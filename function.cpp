#include "main.h"
#include <ctime>

int readBlock(void* buffer, FILE*& f)
{
	return fread(buffer, 1, SECTOR_SIZE, f);//Tra ve so byte doc duoc
}
int writeBlock(void* buffer, int block_count, FILE*& f)
{
	return fwrite(buffer, 1, block_count, f);
}
int showFormatMenu() //Ham xuat menu khi chon chuc nang dinh dang volume
{
	cout << "1. Dinh dang cho volume (full format)\n";
	cout << "2. Dinh dang nhanh (quick format)\n";
	cout << "0. Quay lai\n";
	int option;
	do
	{
		cout << "Nhap vao lua chon cua ban: ";
		cin >> option;
	} while (!(option == 1 || option == 2 || option == 0));
	return option;
}
void hashFunction(string& content, int n) //Ham bam 1 chuoi
{
	for (int i = 0; i < (int)content.length(); i++)
		content[i] = content[i] + n;
}
string getFileNameFromPath(string path)
{
	int pos = path.find_last_of('\\');
	string fileName = path.substr(pos + 1);
	return fileName;
}
void traverse(Entry entry)
{
	string fileName = getFileNameFromPath(entry.getFileName());
	cout << fileName << '\t';
	cout << entry.getDataSize() << '\t';
	Date last_modified_date = entry.getDate();
	cout << last_modified_date.day << '/' << last_modified_date.month << '/' << last_modified_date.year << '\t';
	Time last_modified_time = entry.getTime();
	cout << last_modified_time.hour << '/' << last_modified_time.minute << '/' << last_modified_time.second << '\n';
}
Date getCurrentDate()
{
	Date currentDate;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	currentDate.day = ltm->tm_mday;
	currentDate.month = ltm->tm_mon + 1;
	currentDate.year = ltm->tm_year + 1900;
	return currentDate;
}
Time getCurrentTime()
{
	Time currentTime;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	currentTime.hour = ltm->tm_hour;
	currentTime.minute = ltm->tm_min;
	currentTime.second = ltm->tm_sec;
	return currentTime;
}
void writeEntryTable(vector<Entry> entryList, FILE*& f)
{
	int writen_block_count;
	for (int i = 0; i < (int)entryList.size(); i++)
	{
		writen_block_count = sizeof(entryList[i]) / SECTOR_SIZE;
		for (int j = 0; j < writen_block_count; j++)
			writeBlock(&entryList[i], SECTOR_SIZE, f);
		writeBlock(&entryList[i], sizeof(entryList[i]) % SECTOR_SIZE, f);
	}
}