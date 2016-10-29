#include "tconvert.h"
#include <iostream>
#include <conio.h>
#define scanf scanf_s

void main()
{
	int in=2;
	TConvert A("first", 50);
	TConvert B("second", 6);
	printf("\nWrite your letter and I put it into convert\n...\n");
	if (A.CanSent())
	{
		A.WriteLetter();
		A.SentLetter();
	}
	else printf("\nYou cant sent letter/nPlease buy a mark for your convert");
	printf("\nDo you want to create a second letter? \n(1-yes, 0-no\n");
	do
	{
		scanf("%i", &in);
	} while ((in < 0) || (in > 1));
	if (in == 1)
	{
		
		B.WriteLetter();
		B.SentLetter();
	}
	else printf("\nMkay...\n");
	in = 2;
	printf("\nDo you want to view your first letter? \n(1-yes, 0-no\n");
	do
		scanf("%i", &in);
	while ((in < 0) || (in > 1));
	if (in == 1)
	{
		A.ConsoleViewText();
	} else printf("\nMkay...\n");
	in = 2;
	printf("\nDo you want to save in Variable text your first letter? \n(1-yes, 0-no\n");
	do
		scanf("%i", &in);
	while ((in < 0) || (in > 1));
	if (in == 1)
	{
		char *VarText = new char[MAX_TEXT];
		*VarText = A.SaveText();
	}
	else printf("\nMkay...\n");
	//if (A == B) printf("\nYour Converts are equal\n"); 
//	else printf("\nYour Converts are not equal\n");
	system("pause");
	//~A();
	//~B();
}