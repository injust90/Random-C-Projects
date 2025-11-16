#include <stdio.h> 
#include <wchar.h> 
#include <locale.h> 
int main() { setlocale(LC_CTYPE, ""); int choice = 0; wchar_t katakana = 0x30A2; printf("Welcome the Library.\nA place of lost information\n"); wprintf(L"katakana: %lc\n", katakana); }
