#include "shell.h"
/**
 * interactive - it should return true if shell is interactive mode
 * @info: struct address
 * Return: 1 if interactive mode or 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - it should check if character is a delimeter
 * @c: char to check
 * @delim: it's a delimeter string
 * Return: 1 if works or 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
/**
 * _isalpha - it checks for alphabetic characters
 * @c: character to input
 * Return: 1 when c is alphabetic or 0 if otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _atoi -  it converts a string to an integer
 * @s: is the string to be converted
 * Return: 0 when no numbers in string or converted number otherwise
 */
int _atoi(char *s)
{
	int q, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (q = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[q] == '-')
			sign *= -1;
		if (s[q] >= '0' && s[q] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[q] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}
