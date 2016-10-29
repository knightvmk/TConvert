#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX_TEXT 256 //max lenght of text in included file
#define COUNT 5 //count of convert
#define gets gets_s
class TConvert
{
private:
	char *name;
	char *fname;
	int mark;
	FILE *file;
public:
	TConvert(char *_name, int _mark);
	~TConvert();
	bool CanSent();
	void AddMark(int count);
	void WriteLetter();
	void SentLetter();
	void ConsoleViewText();
	char SaveText();
	bool operator==(TConvert &B);
	bool operator!=(TConvert &B);
};