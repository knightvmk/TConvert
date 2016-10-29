#include "tconvert.h"

TConvert::TConvert(char *_name, int _mark)
{
	mark = _mark;
	int size = strlen(_name);
	name = new char[size];
	name = _name;
	fname = new char[size];
	fname = _name;
//	strcat(fname,".txt");
}

TConvert::~TConvert()
{
	delete[] name;
	delete[] fname;
	fclose(file);
	name = fname = 0;
}

bool TConvert::CanSent()
{
	if (mark >= COUNT) return true;
	else return false;
}

void TConvert::AddMark(int count)
{
	mark+=count;
}


void TConvert::WriteLetter()
{
	file = fopen(fname, "a");
	char text[MAX_TEXT];
	gets(text);
	fputs(text, file);
	fclose(file);
}

void TConvert::SentLetter()
{
	if (CanSent()) printf("\nLetter sent\n");
	else printf("\nLetter cant sent\n");
}

void TConvert::ConsoleViewText()
{
	file = fopen(fname, "r");
	char text[MAX_TEXT];
	if (fgets(text, MAX_TEXT, file) != 0)
	fclose(file);
	printf("\n\nYour Letter:\n %s", text);
}
char TConvert::SaveText()
{
	file = fopen(fname, "r");
	char *text;
	text = new char[MAX_TEXT];
	if (fgets(text, MAX_TEXT, file) != 0)
		printf("\nText received\n");
	fclose(file);
	return *text;
}

bool TConvert::operator==(TConvert &B)
{
	//char text1[MAX_TEXT], text2[MAX_TEXT];
	if ((mark == B.mark) & (name == B.name))
	{ 
		char *text1, *text2;
		text1 = new char[MAX_TEXT];
		text2 = new char[MAX_TEXT];
		file = fopen(fname, "r");
		B.file = fopen(B.fname, "r");
		fgets(text1, MAX_TEXT, file);
		fgets(text2, MAX_TEXT, B.file);
		for (int i = 0; i < MAX_TEXT; i++)
		{
			if (text1[i] != text2[i]) return  false;
		}
		return true;
	}
	return false;
}

bool TConvert::operator!=(TConvert &B)
{
	if (*this == B) return false;
	else return true;
}

