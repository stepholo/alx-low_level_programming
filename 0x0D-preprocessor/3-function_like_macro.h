#ifndef FUNCTION_LIKE_MACRO
#define FUNTION_LIKE_MACRO

/**
 * File: Macro named ABS
 * Desc: A function like macro that prints the absolute number of x
 * @x: value to find its absolute value
 */

#define ABS(x) ((x) < (0) ? ((x) * (-1) : (x))

#endif
