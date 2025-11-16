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
int my_getline(wchar_t line[], int maxline);

int main()
{
	int STATE = OUT;
	int choice;
	wchar_t c = ' ';
	wchar_t n;
	int katakana;
	int len;
	wchar_t line[MAXLINE];

	do {
		katakana = randomChar();
		printf("Input the correct katakana: %lc\n", katakana);

		len = my_getline(line, MAXLINE);
		if (len == 1) {
			if (line[0] == katakana)
				printf("Correct! \n");
			else 
				printf("Incorrect \n");
		}
		else 
			printf("Incorrect! Too many characters.\n");
	}
	while (len > 0);

   return 0;
}

// read a line into s, return length
int my_getline(wchar_t s[], int lim) 
{
	wchar_t c;
	int i;
	for (i = 0; i < lim - 1 && (c = getwchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
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
