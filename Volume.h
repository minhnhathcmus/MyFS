#pragma once
#include "Header.h"
#include "EntryTable.h"
#include "main.h"

class Volume
{
private:
	string path;
	Header header;
	EntryTable entryTable;
public:
	Volume();
	~Volume();
	string getPath();
	EntryTable getEntryTable();
	int create();
	int fullFormat();
	int quickFormat();
	int format();
	int list(vector<EntryNode*> listOfEntryInRoot, EntryNode* parent, string folderName/*, int number_of_tab*/);
};