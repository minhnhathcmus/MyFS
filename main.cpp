#include "Volume.h"

int main()
{
	Volume volume;
	int option;
	do
	{
		option = showMainMenu();
		switch (option)
		{
		case 0:
			break;
		case 1:
		{
			volume.create();
			system("pause");
			break;
		}
		case 2:
		{
			volume.format();
			system("pause");
			break;
		}
		case 3:
		{
			volume.createPassword();
			system("pause");
			break;
		}
		case 4:
		{
			volume.changePassword();
			system("pause");
			break;
		}
		case 5:
		{
			volume.list(volume.getEntryTable());
			system("pause");
			break;
		}
		default:
		{
			cout << "Loi khong xac dinh!\n";
			system("pause");
			break;
		}
		}
	} while (option != 0);
	cout << "Da thoat chuong trinh.";
	return 0;
}