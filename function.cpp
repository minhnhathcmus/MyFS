#include "main.h"

int readBlock(void*& buffer, FILE*& f)
{
	if (fread(buffer, 512, 1, f) == 1)
		return 1; //Ma 1: doc du lieu thanh cong
	return 0; //Ma 0: doc du lieu that bai
}
int writeBlock(void* buffer, FILE*& f)
{
	if (fwrite(buffer, 512, 1, f) == 1)
		return 1; //Ma 1: ghi du lieu thanh cong
	return 0; //Ma 0: ghi du lieu that bai
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
	for (int i = 0; i < content.length(); i++)
		content[i] = content[i] + n;
}
string getFileNameFromPath(string path)
{
	int pos = path.find_last_of('\\');
	string fileName = path.substr(pos + 1);
	return fileName;
}
void printTab(int number_of_tab)
{
	for (int i = 0; i < number_of_tab; i++)
		cout << '\t';
}
unsigned long long calculateDataSize(EntryNode* node)
{//Tra ve dataSize neu node la tap tin, tra ve tong kich thuoc cac tap tin/thu muc con neu node la thu muc
	if (node->item.getDataSize() != 0)
		return node->item.getDataSize();
	unsigned long long totalDataSize = 0;
	vector<EntryNode*> childrenList = node->childrenList;
	for (int i = 0; i < childrenList.size(); i++)
		totalDataSize += calculateDataSize(childrenList[i]);
	return totalDataSize;
}
void traverse(EntryNode* node/*, int number_of_tab*/)
{
	string fileName = getFileNameFromPath(node->item.getFileName());
	cout << fileName << '\t';

	unsigned long long dataSize = calculateDataSize(node);
	cout << dataSize << '\t';

	Date last_modified_date = node->item.getDate();
	cout << last_modified_date.day << '/' << last_modified_date.month << '/' << last_modified_date.year << '\t';

	Time last_modified_time = node->item.getTime();
	cout << last_modified_time.hour << '/' << last_modified_time.minute << '/' << last_modified_time.second << '\n';

	//for (int i = 0; i < node->childrenList.size(); i++)
	//{
	//	printTab(number_of_tab + 1);
	//	cout << i + 1 << '.\t';
	//	traverse(node->childrenList[i], number_of_tab + 1);
	//}
}