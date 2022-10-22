// Coding Assignment 5
// Fawaz Asif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "GameLib.h"

int main(void)
{
	char Phrase[MAX_INPUT] = {};
	char DashedPhrase[MAX_INPUT] = {};
	char UpperPhrase[MAX_INPUT] = {};
	int Strikes = 0;
	int i;
	
	StartGame(Phrase);
	DashIt(Phrase, DashedPhrase);
	/* uppercase Phrase */
	for (i = 0; i < strlen(Phrase); i++)
	{
	    UpperPhrase[i] = toupper(Phrase[i]);
	}
	
	
	printf("\nHere's the phrase you need to guess\n");
    
	do
	{
		if (!(GuessALetter(Phrase, DashedPhrase, UpperPhrase)))
		{
			Strikes++;
			printf("\nStrike %d", Strikes);
		}
	}
	while ((strchr(DashedPhrase, '-') != NULL) && (Strikes < STRIKES));
	
    if (Strikes < STRIKES)
    {
        printf("\n\nYou figured it out!!\n\nThe phrase was \n\n%s", Phrase);
        printf("\n\nYOU WIN!!!!\n");
    }
    else
    {
        printf("\n\n");
        printf("%d STRIKES - YOU'RE OUT!!\n\n", STRIKES);
        printf("Game over\n\n");
    }
	return 0;
}
