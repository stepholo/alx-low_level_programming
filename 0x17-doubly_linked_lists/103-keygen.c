#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* f_4 - finds the biggest number
* @usrn: username
* @len: length of username
* Return: the biggest number
*/
int f_4(char *usrn, int len)
{
	int ch;
	int vch;
	unsigned int rand_num;

	ch = *usrn;
	vch = 0;

	while (vch < len)
	{
		if (ch < usrn[vch])
			ch = usrn[vch];
		vch += 1;
	}

	srand(ch ^ 14);
	rand_num = rand();

	return (rand_num & 63);
}

/**
* f_5 - Multiplies each character of username
* @usrn: username
* @len: length of username
* Return: Multiplies char
*/
int f_5(char *usrn, int len)
{
	int ch;
	int vch;

	ch = vch = 0;

	while (vch < len)
	{
		ch = ch + usrn[vch] * usrn[vch];
		vch += 1;
	}

	return (((unsigned int)ch ^ 239) & 63);
}

/**
* f_6 - generates a random char
* @usrn: username
* Return: a random char
*/
int f_6(char *usrn)
{
	int ch;
	int vch;

	ch = vch = 0;

	while (vch < *usrn)
	{
		ch = rand();
		vch += 1;
	}

	return (((unsigned int)ch ^ 229) & 63);
}

/**
* main - Entry point
* @argc: arguments count
* @argv: arguments vector
* Return: Always 0
*/
int main(int argc, char **argv)
{
	char key_gen[7];
	int len, ch, vch;
	long alph[] = {
		0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
		0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850};
	(void) argc;

	for (len = 0; argv[1][len]; len++)
		;
	key_gen[0] = ((char *)alph)[(len ^ 59) & 63];

	ch = vch = 0;
	while (vch < len)
	{
		ch = ch + argv[1][vch];
		vch = vch + 1;
	}
	key_gen[1] = ((char *)alph)[(ch ^ 79) & 63];

	ch = 1;
	vch = 0;
	while (vch < len)
	{
		ch = argv[1][vch] * ch;
		vch = vch + 1;
	}

	key_gen[2] = ((char *)alph)[(ch ^ 85) & 63];
	key_gen[3] = ((char *)alph)[f_4(argv[1], len)];
	key_gen[4] = ((char *)alph)[f_5(argv[1], len)];
	key_gen[5] = ((char *)alph)[f_6(argv[1])];
	key_gen[6] = '\0';

	for (ch = 0; key_gen[ch]; ch++)
	{
		printf("%c", key_gen[ch]);
	}
	printf("\n");
	return (0);
}
