#pragma once
#include "main.h"

class EntryTable
{
private:
	vector<EntryNode*> entryList; //Chua cac EntryNode cua cac Entry thuoc thu muc goc
public:
	EntryTable();
	~EntryTable();
	vector<EntryNode*> getEntryList();
};