#pragma once
#include "Header.h"
#include "main.h"

class Volume
{
private:
	string path;
	Header header;
	vector<Entry> entryTable;
public:
	Volume();
	~Volume();
	string getPath();
	Header getHeader();
	vector<Entry> getEntryTable();
	int create();
	int fullFormat();
	int quickFormat();
	int format();
	void list(vector<Entry> listOfEntryInRoot);
	int importFile();
	int createPassword();
	int changePassword();
};