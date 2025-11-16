#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <time.h>

#define IN 1
#define OUT 0
#define MAXLINE 1000

int randomChar();
int getline1(char line[], int maxline);

int main()
{
	int STATE = OUT;
	int choice;
	wchar_t c = ' ';
	wchar_t n;
	int katakana;

	do {
		katakana = randomChar();

		printf("Input the Correct Character\n");
		printf("katakana: %lc\n", katakana);

		c = getwchar();
		// Reads in the \n
		n = getwchar();

		if (n == '\n')
			STATE = OUT;
		else
			STATE = IN;

		if (c == katakana) {
			printf("Correct!\n");
		}
		else 
			printf("Incorrect!\n");
	}
	while (c != WEOF && STATE == IN);

   return 0;
}

// read a line into s, return length
int getline1(char s[], int lim) 
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

int randomChar()
{
	unsigned int seed = time(0);
	int rd_num = 0;

	rd_num = rand_r(&seed) % (46 - 0 + 1) + 0;

	setlocale(LC_ALL, "en_US.utf8");
	const char* mbstr = "アイウエオカキクケコサシスセソタチツテトナニヌネノハヒフヘホマミムメモヤユヨラリルレロワヲン";
	wchar_t wstr[46];
	mbstowcs(wstr, mbstr, 46);

	return wstr[rd_num];	
}
