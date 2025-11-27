#include "raylib.h"
#include <curses.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

void randomChar();
void introDialog();
void* musicStream(void* music);

char array[100] = {0};
int main()
{

	InitAudioDevice();
	Music music = LoadMusicStream("/home/justin/Downloads/Let's Adventure wavs sonatina.itch.io/Let's Adventure wavs sonatina.itch.io/sonatina_letsadventure_1ATaleForTheJourney.wav");
	SetMusicVolume(music, 1.0f);
	PlayMusicStream(music);
	pthread_t thread_info;
	pthread_create(&thread_info, NULL, musicStream, (void*)&music);

	setlocale(LC_ALL, "en_US.utf8");
	char* stringReader = 0; 
	size_t line_len = 0; 

	introDialog();
	while (true) {
		// Get a random character out mbstr and write it into the global variable array
		randomChar();
		printf("Input the character shown %s", array);

		// A return value of -1 for getline indicates that there are no more characters to be read; break out of the loop
		if (getline(&stringReader, &line_len, stdin) == -1) {
			break;
		}

		// If we compare what is read in via getline to array is equal print correct
		if (strcmp(stringReader, array) == 0) {
			printf("Correct!\n\n");
		}
		else {
			printf("Incorrect!\n\n");
		}
	}

	UnloadMusicStream(music);
	CloseAudioDevice();

   return 0;
}

void randomChar()
{
	unsigned int seed = time(0);
	int rd_num = 0;
	wchar_t wstr[46];

	rd_num = rand_r(&seed) % (46 - 0 + 1) + 0;

	const char* mbstr = "アイウエオカキクケコサシスセソタチツテトナニヌネノハヒフヘホマミムメモヤユヨラリルレロワヲン";
	mbstowcs(wstr, mbstr, 46);

	sprintf(array, "%lc\n", wstr[rd_num]); 
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

void* musicStream(void* music)
{
	while (true) {
		UpdateMusicStream(*(Music*)music);
	}
	return NULL;
}
