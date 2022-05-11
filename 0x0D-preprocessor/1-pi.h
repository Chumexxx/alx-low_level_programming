#ifndef _PI_
#define _PI_

#define PI 3.14159265359

#endif


2-main.c:

#include <stdio.h>

/**
 * main - prints the name of the file.
 *
 * Return: Always 0.
 */
int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}
