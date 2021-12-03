#pragma once
#include "Entry.h"

class EntryTable
{
private:
	Entry* root;
	vector<Entry*> entryTable;
public:
	EntryTable();
	~EntryTable();
};