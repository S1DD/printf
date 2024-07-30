#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define INIT(x) (void)(x)
#define BUFSIZE 1024

/*--------------------FLAGS----------------------*/
#define FLAG_LEFT_ALIGN 1
#define FLAG_FORCE_SIGN 2
#define FLAG_LEADING_ZERO 4
#define FLAG_ALTERNATE 8
#define FLAG_SPACE_IF_NO_SIGN 16

/*-------------------SIZES----------------------*/
#define SHORT 1
#define LONG 2


/*------------------FUNCTIONS------------------*/
/*For printing strings and characters*/
int render_char(va_list args, char output_buffer[],
		int options, int min_width, int max_length, int data_size);

int render_string(va_list args, char output_buffer[],
		int options, int min_width, int max_length, int data_size);

int render_percent(va_list args, char output_buffer[],
		int options, int min_width, int max_length, int data_size);

/**
 * struct FormatEntry - Associate a format specifier with a formatting function
 *
 * @specifier: The format specifier character.
 * @handler: The function associated with the format specifier.
 */
typedef struct FormatEntry
{
	char specifier;
	int (*handler)(va_list, char[], int, int, int, int);
} FormatEntry_t;

int _printf(const char *format, ...);

int process_format_specifier(const char *format_str, int *index,
		va_list args, char output_buffer[],
		int format_flags, int min_width, int precision, int data_size);

/*For printing numbers*/
int convertToInt(va_list args, char output_buffer[],
		int format_flags, int min_width, int precision, int type_size);

int convertToBin(va_list args, char output_buffer[],
		int format_flags, int min_width, int precision, int type_size);

int convertToUnsigned(va_list args, char output_buffer[],
		int format_flags, int min_width, int precision, int type_size);

int convertToOct(va_list args, char output_buffer[],
		int format_flags, int min_width, int precision, int type_size);

int convertToHex(va_list args, char output_buffer[],
		int format_flags, int min_width, int precision, int type_size);

int convertToHexUpper(va_list args, char output_buffer[],
		int format_flags, int min_width, int precision, int type_size);

int convertToHexCustom(va_list args, char hex_map[],
		char output_buffer[], int format_flags,
		char hex_flag, int min_width, int precision, int type_size);

/*For printinng non printable characters*/
int format_non_printable_chars(va_list args, char output_buffer[],
		int format_flags, int min_width, int max_length, int data_size);

/*For printing memory address*/
int format_pointer_address(va_list args, char output_buffer[],
		int format_flags, int min_width, int max_length, int data_size);

/* Handling specifiers*/
int parse_format_flags(const char *format_str, int *idx);
int extract_width(const char *format_str, int *idx, va_list args);
int extract_precision(const char *format_str, int *idx, va_list args);
int determine_size(const char *format_str, int *idx);

/*Reversing a string*/
int revString(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Print string in ROT13*/
int rot13String(va_list args, char output_buffer[],
		int format_flags, int min_width, int max_length, int data_size);

/*Width handler*/
int format_and_write_char(char character, char output_buffer[],
		int format_flags, int min_width, int precision, int data_size);

int format_and_write_number(int is_positive, int index, char output_buffer[],
		int format_flags, int min_width, int precision, int data_size);

int format_and_write_number_with_padding(int idx, char output_buffer[],
		int format_flags, int min_width, int precision,
		int length, char padding_char, char extra_char);

int format_and_write_pointer(char output_buffer[], int index, int length,
		int min_width, int format_flags, char padding_char,
		char extra_char, int padding_start);

int format_and_write_unsigned(int is_negative, int index, char output_buffer[],
		int format_flags, int min_width, int precision, int data_size);

/*************************HELPER FUNCTIONS***********************/
int is_character_printable(char character);
int append_hexadecimal_code(char character, char buffer[], int buffer_idx);
int is_character_digit(char character);
long int convertNumberSz(long int number, int size_specifier);
unsigned long int convertUnsignedSz(unsigned long int n, int size_specifier);

#endif
