#pragma once
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include <vector>
#include<iomanip>
#include "clsUtil.h"
#include "clsUser.h"
class clsLoginRegister :protected clsScreen
{
private:
	static void _PrintRegisterRecordLine(clsUser::stLoginRegisterRecord   LoginRegisterRecord) {
		cout << "| " << setw(15) << left << clsDate::GetSystemDateTimeString();

		cout << "| " << setw(15) << left << LoginRegisterRecord.UserName;

		cout << "| " << setw(20) << left << LoginRegisterRecord.Password;

		cout << "| " << setw(12) << left << LoginRegisterRecord.Permissions;

	}
public:
	static void ShowUserRegisterMenu()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}
		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

		string Title = "\t Register List Screen";
		string SubTitle = "\t    (" + to_string(vLoginRegisterRecord.size()) + ") User(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t\t\t\t\tUsers List (" << vLoginRegisterRecord.size() << ") User(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "| " << left << setw(15) << "Date";
		cout << "| " << left << setw(20) << "Username";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(12) << "Permission";

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (vLoginRegisterRecord.size() == 0)
		{
			cout << "\t\t\t\t No users available in the system !";
		}
		else {
			for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
			{

				_PrintRegisterRecordLine(Record);
				cout << endl;
			}
			cout << "\n_______________________________________________________";
			cout << "_________________________________________\n" << endl;

		}





	}

};

