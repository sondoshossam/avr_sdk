/**
 * @file keysafe_app.c
 * @author Mohamed Yehia
 * @date Jul 20, 2019
 * @brief File containing the main of the key safe application
 * @see http://www.google.com
 * for more information regards of the project.
 * the program stored the user password and some configuration on the EEPROM as follow
 * EEPROM ADDRESS 0 : contain whether the save has opened before or not(0xe0 mean it's opened before)
 * EEPROM ADDRESS 1 : contain the number of stored password length (8 if the password is 8 digits)
 * EEPROM ADDRESS 2 : the first digit of the stored password
 *
 */
#ifdef KEYSAFE_APP
#include <util/delay.h>
#include "../../utils/custom_types.h"
#include "../../hal/lcd/lcd.h"
#include "../../hal/keypad/keypad.h"
#include "../../mcal/EEPROM/eeprom.h"
#define PASSWORD_EXISTED_EEPROM_ADD (u16_t)0
#define PASSWORD_LENGTH_EEPROM_ADD  (u16_t)1
#define FIRST_DIGIT_EEPROM_ADD      (u16_t)2
#define PASSWORD_INSERTED_BYTE_VALUE (u8_t)0xE0
#define MAX_PASSWORD_LENGTH 10
#define MIN_PASSWORD_LENGTH 4
#define ENTER_KEY 'D'
void init_system(void);
bool_t is_this_new_safe(void);
void enter_new_password_handeller(void);
u8_t load_save_configuration(u8_t *pass_container);
bool_t scan_save_password(u8_t *entered_digits , u8_t *no_of_digits_entered);
bool_t is_passwords_equal(u8_t *entered_digits , u8_t *saved_digits ,  u8_t no_of_digits);
void key_safe_app(void)
{
    /* used to store the save password it shouldn't be exceed MAX_PASSWORD_LENGTH digits*/
	u8_t SAVED_DIGITS[MAX_PASSWORD_LENGTH];
	u8_t NO_SAVED_PASS_DIGITS = 0;
	/* used to store the password that entered by the user*/
	u8_t entered_digits[MAX_PASSWORD_LENGTH];
    u8_t no_of_digits_entered = 0;
	bool_t is_enter_key_pressed = false;
	/* wait for power stabilization*/
    _delay_ms(300);
    /* init the whole system */
    init_system();
    /* check whether the safe is new or not */
    if(is_this_new_safe() == true)
    {
    	enter_new_password_handeller();
    }
    /* load the stored save configuration from eeprom*/
    NO_SAVED_PASS_DIGITS = load_save_configuration(SAVED_DIGITS);
    while(1)
    {
    	is_enter_key_pressed = scan_save_password(entered_digits , &no_of_digits_entered);
    	if(is_enter_key_pressed)
    	{
    		/*let's assume that the passwords is not equal and let the code decide whether
    		 * our assumption is right or not
    		 */
    		bool_t is_equal = false;
    		//compare passwords
    		if(NO_SAVED_PASS_DIGITS == no_of_digits_entered)
    		{
    			/*passwords might be the same because they have the same number of digits
    			 * let's compare the values of each digit
    			 * */
    			is_equal = is_passwords_equal(entered_digits , SAVED_DIGITS , no_of_digits_entered);
    		}
    		if(is_equal == true)
    		{
    			/* we gonna open the save */
    			lcd_clear();
    			lcd_write_text("correct password" , 2 , 1);
    			_delay_ms(1000);
    			lcd_clear();
    		}
    		else
    		{
    			/* we can display error for a certain amount of time then go to the normal mode again*/
    			lcd_clear();
    			lcd_write_text("ERROR" , 2 , 1);
    			_delay_ms(1000);
    			lcd_clear();
    		}
    		// restore the variables
    	}
    }
}
/**
 * @brief this function will initialize the whole system
 * 1-initialize lcd
 * 2-initialize keypad
 * 3-initialize eeprom
 ******************************************************************************/
void init_system(void)
{
	 u8_t i;
     init_keypad();
     init_lcd();
     for(i = 0;i<1 ; i++)
     {
    	 lcd_write_text("Key Safe", 1 , 1);
    	 _delay_ms(500);
    	 lcd_clear();
    	 _delay_ms(500);
     }

}
/**
 * @brief this function will check whether the user have entered the password for the save before or not
 * by reading the eeprom PASSWORD_EXISTED_EEPROM_ADD and check whether it contains PASSWORD_INSERTED_BYTE_VALUE
 * or not
 *@return : true if this a new save or false
 ******************************************************************************/
bool_t is_this_new_safe(void)
{
    bool_t is_new = true;
    if(EEPROM_read(PASSWORD_EXISTED_EEPROM_ADD) != PASSWORD_INSERTED_BYTE_VALUE)
    {
    	is_new = false;
    }
    return is_new;
}
/**
 * @brief it handles the process of entering new password as follow
 * 1- ask user to enter new password
 * 2- wait user to hit enter
 * 3- store the password on EEPROM strartino from addresss FIRST_DIGIT_EEPROM_ADD
 * 4- update both PASSWORD_LENGTH_EEPROM_ADD and PASSWORD_EXISTED_EEPROM_ADD
 * */
void enter_new_password_handeller(void)
{
	u8_t clicked_key=0 , number_of_digits = 0 , i=0;
	u8_t temp_container[MAX_PASSWORD_LENGTH];
	bool_t is_password_entered = false;
	lcd_write_text("Enter New Pass" , 1 , 1);
	lcd_write_char(' ' , 2 , 1);
	while(is_password_entered == false)
	{
		clicked_key = get_key_clicked();
		if(clicked_key !=ENTER_KEY && number_of_digits<MAX_PASSWORD_LENGTH)
		{
			temp_container[number_of_digits] = clicked_key;
			number_of_digits++;
			lcd_write_char_cp('*');
		}
		else if (clicked_key == ENTER_KEY)
		{
			if(number_of_digits < MIN_PASSWORD_LENGTH)
			{
				lcd_write_text("pass too short" , 2 , 1);
				_delay_ms(1000);
				lcd_write_text("               " , 2 , 1);
				lcd_write_char(' ' , 2 , 1);
				number_of_digits = 0; //start again
			}
			else
			{
				is_password_entered = true;
			}
		}
		else if(number_of_digits == MAX_PASSWORD_LENGTH)
		{
			lcd_write_text("pass too long" , 2 , 1);
			lcd_write_text("               " , 2 , 1);
			lcd_write_char(' ' , 2 , 1);
			number_of_digits = 0; //start again
		}
	}
	//copy password to eeprom from FIRST_DIGIT_EEPROM_ADD
	for(i=0 ; i<number_of_digits ; i++)
	{
		EEPROM_write(FIRST_DIGIT_EEPROM_ADD + i , temp_container[i]);
	}
	// there's a password now
	EEPROM_write(PASSWORD_EXISTED_EEPROM_ADD , PASSWORD_INSERTED_BYTE_VALUE);
	// store the password length
	EEPROM_write(PASSWORD_LENGTH_EEPROM_ADD , number_of_digits);
	lcd_clear();
}
/**
 * it loads the stored password from EEPROM starting from FIRST_DIGIT_EEPROM_ADD in pass_container and read the
 * length of stored password
 * @pram pass_container: the address of a container to load the stored password from eeprom into it
 * @return the length of stored password
 * */
u8_t load_save_configuration(u8_t *pass_container)
{
	u8_t saved_password_length = 0 , i = 0;
	saved_password_length = EEPROM_read(PASSWORD_LENGTH_EEPROM_ADD);
	for(i=0 ; i<saved_password_length ; i++ )
	{
		pass_container[i] = EEPROM_read(FIRST_DIGIT_EEPROM_ADD+i);
	}
	return saved_password_length;
}
/**
 * @brief it handles the process of entering password as follow
 * 1- ask user to enter  password
 * 2- scan the user input and store it in entered_digits at no_of_digits_entered
 * 3- update the screen
 * @pram entered_digits:the address of a container to load the pressed key into it
 * @pram no_of_digits_entered : reference to a variable that stores how many digits are enter so far
 * @return true if enter key has pressed else false
 * */
bool_t scan_save_password(u8_t *entered_digits , u8_t *no_of_digits_entered)
{
	bool_t is_password_entered = false;
	u8_t clicked_key=0;
	*no_of_digits_entered = 0;
	lcd_write_text("Enter your Pass" , 1 , 1);
	lcd_write_char(' ' , 2 , 1);
	while(is_password_entered == false)
	{
		clicked_key = get_key_clicked();
		if(clicked_key !=ENTER_KEY && (*no_of_digits_entered)<MAX_PASSWORD_LENGTH)
		{
			entered_digits[*no_of_digits_entered] = clicked_key;
			(*no_of_digits_entered)++;
			lcd_write_char_cp('*');
		}
		else if (clicked_key == ENTER_KEY)
		{
			if(*no_of_digits_entered < MIN_PASSWORD_LENGTH)
			{
				lcd_write_text("pass too short" , 2 , 1);
				_delay_ms(1000);
				lcd_write_text("               " , 2 , 1);
				lcd_write_char(' ' , 2 , 1);
				*no_of_digits_entered = 0; //start again
			}
			else
			{
				is_password_entered = true;
				lcd_clear();
			}
		}
		else if((*no_of_digits_entered) == MAX_PASSWORD_LENGTH)
		{
			lcd_write_text("pass too long" , 2 , 1);
			lcd_write_text("               " , 2 , 1);
			lcd_write_char(' ' , 2 , 1);
			_delay_ms(1000);
			*no_of_digits_entered = 0; //start again
		}
	}
	lcd_clear();
	return is_password_entered;
}
/**
 *@brief it campares two arrays
 * @pram entered_digits:first array
 * @pram saved_digits : second array
 * @pram no_of_digits : no of digits on each array
 * @return true if they are equal (each digit of the first array is the same as the corresponding digit on the second array)
 * */
bool_t is_passwords_equal(u8_t *entered_digits , u8_t *saved_digits , u8_t no_of_digits)
{
    bool_t is_equal = true;
    u8_t i =0;
    for(i=0 ; i<no_of_digits ;i++)
    {
    	if(entered_digits[i] != saved_digits[i])
    	{
    		is_equal = false;
    		break;
    	}
    }
    return is_equal;
}
#endif
