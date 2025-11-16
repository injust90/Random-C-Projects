#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

char randomChar();

int main()
{
	int choice;

	// printf("Welcome the Library.\nA place of lost information\n");
	// printf("図書館へようこそ。\n");

	// printf("randomChar: %c", randomChar());

	const char katakana[] = "アイウエオ";

	setlocale(LC_ALL, "en_US.utf8");
	const char* mbstr = "アリガトウ";
	wchar_t wstr[5];
	mbstowcs(wstr, mbstr, 5);
	printf("Wide String: %ls\n", wstr); 

	printf("wstr[0]: %lc", wstr[0]);
	
   return 0;

}

char randomChar()
{
	const char katakana[] = "アイウエオ";
	// printf("%s", c);
	return katakana[0];	
}
