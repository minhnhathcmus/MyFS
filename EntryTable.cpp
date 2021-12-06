#include "EntryTable.h"

EntryTable::EntryTable()
{
	
}
EntryTable::~EntryTable()
{
	
}
vector<Entry> EntryTable::getEntryList()
{
	return entryList;
}
void EntryTable::setEntryList(Entry entry)
{
	entryList.push_back(entry);
}