#include "main.h"
#include "Volume.h"

int readBlock(void*& buffer, FILE*& f)
{
	if (fread(buffer, 512, 1, f) == 1)
		return 1; //Ma 1: doc du lieu thanh cong
	return 0; //Ma 0: doc du lieu that bai
}
int writeBlock(void* buffer, int writen_block_count, FILE*& f)
{
	for (int i = 0; i < writen_block_count; i++)
	{
		if (fwrite(buffer, SECTOR_SIZE, 1, f) != 1) //Moi lan ghi 512 byte giong nhu truy xuat tung cum 512 byte tren sector
			return 0; //Ma 0: ghi du lieu that bai
	}	
	return 1; //Ma 1: ghi du lieu thanh cong
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

void login() {
	Volume volume;
	volume.create(); // Neu volume co san thi doc volume do
	Header header = volume.getHeader();
	string currPass = header.getPassword();
	string pass;
	

	string volPath = volume.getPath();
	FILE* f = fopen(volPath.c_str(), "wb");

	if (header.getPassword() == "") {
		createPassword(f);
	}
	else {
		cout << "Nhap mat khau";
		cin >> pass;
		if (pass == currPass) {
			// Dang nhap thanh cong

			// Option doi mat khau
			changePassword(f, header);
		}
	}
	fclose(f);
}

void launch() {
	do {
		int choice;
		cout << "1. Truy cap volume." << endl;
		cout << "0. Thoat chuong trinh." << endl;
		cin >> choice;
		if (choice == 1) {
			login();
			return;
		}
		else if (choice == 0)
			return;

	} while (1);
}

void createPassword(FILE* f) {
	string password;
	cout << "Tao mat khau: ";
	cin >> password;

	hashFunction(password, 3);

	fseek(f, 0, SEEK_SET);
	fwrite(0, sizeof(password), 1, f);
}

void changePassword(FILE* f, Header header) {
	string password;
	cout << "Dat mat khau moi: ";
	cin >> password;

	hash(password, 3);
	header.setPassword(3); // Tao header moi roi chen vao

	if (f == NULL)
	{
		cout << "Khong the doi mat khau!\n";
		return;
	}

	int writen_block_count = sizeof(header) / SECTOR_SIZE;
	if (sizeof(header) % SECTOR_SIZE != 0)
		writen_block_count++;
	if (writeBlock(&header, writen_block_count, f) != 1)
	{
		cout << "Khong the ghi du lieu thanh cong, doi mat khau that bai!" << endl;
		fclose(f);
		return;
	}
	cout << "Doi mat khau thanh cong." << endl;
}