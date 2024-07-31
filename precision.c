#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current index in the format string
 * @list: List of arguments
 *
 * This function calculates the precision for printing based on the format
 * string and the list of arguments. The precision is used to determine
 * the number of digits to be printed for numeric values or the maximum
 * number of characters to be printed for strings.
 *
 * Return: The calculated precision. If no precision is specified, it
 * returns -1.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1; /* Initialize current index */
    int precision = -1;  /* Default precision value */

    if (format[curr_i] != '.')
        return (precision); /* Return default if no precision specifier */

    precision = 0; /* Initialize precision to 0 */

    /* Iterate through format string to calculate precision */
    for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i])) /* Check if character is a digit */
        {
            precision *= 10;
            precision += format[curr_i] - '0'; /* Convert char to int */
        }
        else if (format[curr_i] == '*') /* Check for '*' specifier */
        {
            curr_i++;
            precision = va_arg(list, int); /* Get precision from arguments */
            break;
        }
        else
            break; /* Break if no more precision specifier */
    }

    *i = curr_i - 1; /* Update index pointer */

    return (precision); /* Return calculated precision */
}
