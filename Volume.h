#pragma once
#include "Header.h"
#include "EntryTable.h"

class Volume
{
private:
	Header header;
	EntryTable entryTable;
public:
	Volume();
	~Volume();
	int create();
};