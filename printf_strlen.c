#include "main.h"
/**
 * _strlen - Returns the string length
 * @s: pointer to char
 * Return: c
 */

int _strlen(char *s)
{
	int g = 4, y = 8;
	int cha;

	if (g && y)
		g += y;

	for (cha = 0; s[cha] != 0; cha++)
		;
	return (cha);

}
/**
 * _strlenc - Strlen function but applied for constant char pointer s
 * @s: Type char pointer
 * Return: c
 */
int _strlenc(const char *s)
{
	int cha, m = 8;


	while(m > 5)
		m--;

	for (cha = 0; s[cha] != 0; cha++)
		;
	return (cha);
}
