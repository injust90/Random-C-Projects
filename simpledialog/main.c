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
int hiraganaA();
void introDialog();

int main()
{
	int STATE = OUT;
	int choice;
	wchar_t c = ' ';
	wchar_t n;
	int katakana;
	int len;
	wchar_t line[MAXLINE];

	introDialog();
	setlocale(LC_ALL, "en_US.utf8");
	const char* mbstr = "あ";
	wchar_t test[1];
	mbstowcs(test, mbstr, 1);
	if (test[0] == hiraganaA())
		printf("Test Correct! \n");
	else
		printf("Test Incorrect! \n");
	printf("test[0]: %lc", test[0]);

	/*
	// Main program
	len = my_getline(line, MAXLINE);
	if (len == 1) {


		printf("line[0] %lc\n", line[0]);
		if (test[0] == hiraganaA())
			printf("Correct! \n");
		else 
			printf("Incorrect \n");
	}
	else
		printf("Incorrect! Too many characters.");
	*/

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

int hiraganaA()
{
	const char* mbstr = "あ";
	wchar_t wstr[1];
	mbstowcs(wstr, mbstr, 1);

	return wstr[0];
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

void introDialog()
{

	printf("You find yourself in an old library.\n\nThe books are entombed with dust and there is a musky odor in the air.\n\n");
	printf("A kind voice begins to speak \"I've been waiting a longgg time for you!\"\n\n");
	printf("\"We need to learn an ancient language known as Japanese\"\n\n");
	printf("\"This is going to be fun!\n\n\"");
	printf("First thing is first, we need to teach you the basics.\n\n");
	printf("There are 46 letters of hiragana (ひらがな) and 46 katakana (カタカナ)\n\n");
	printf("The first letters of the alphabet are あいうえお corresponding to AIUEO.\n\n");
	printf("Each character represents a vowel, for example あ represents the sound 'a'\n\n");
}
