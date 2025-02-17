#pragma once
#include <iostream>
#include "Global.h"
#include"clsDate.h"
#include "clsUser.h"
using namespace std;

class clsScreen
{
protected:
	static void  _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\n\t\t\t\t\t----------------------------------------------------------------";
		string UserName;
		
		cout << "\n\n \t\t\t\t" << Title;
		if (SubTitle != "")
		{
			
			cout << "\n\n \t\t\t\t" << SubTitle;

		}



		cout << "\n\t\t\t\t\t-----------------------------------------------------------------\n\n";
		cout << "\n\n \t\t\t\t\t\t\t User :" << CurrentUser.UserName;
		cout << "\n\n \t\t\t\t\t\t\t Date  :" << clsDate::DateToString(clsDate());
		cout << "\n\n";



	}
	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckPermissionAccess(Permission))
		{
			cout << "\n\t\t\t---------------------------------------------------------------------\n";
			cout << "\n\n\t\t\t\t\t  Access Denied\n";
			cout << "\n\t\t\t---------------------------------------------------------------------\n";
			return false;

		}
		else {
			return true;
		}
	}

};

