#pragma once
#include "Header.h"
#include "EntryTable.h"

class Volume
{
private:
	string path;
	Header header;
	EntryTable entryTable;
public:
	Volume();
	~Volume();
	int create();
	int fullFormat();
	int quickFormat();
	int format();
};