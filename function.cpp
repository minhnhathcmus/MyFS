#include "main.h"

int showFormatMenu() //Ham xuat menu khi chon chuc nang dinh dang volume
{
	cout << "1 - Dinh dang cho volume (full format)\n";
	cout << "2 - Dinh dang nhanh (quick format)\n";
	cout << "0 - Quay lai\n";
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