#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"



class clsLoginScreen : protected clsScreen
{
	static bool _Login()
	{
		bool LoginFailed = false;
		short FailedLoginCounts = 0;
		string UserName, Password;
		do
		{
			if(LoginFailed)
				{
				FailedLoginCounts++;
					cout<<"\n Invalid Username/ Password\n";
					cout << "You have " << 3 - FailedLoginCounts << " trial(s) to login";
				}
			if (FailedLoginCounts == 3) {
				cout << "You are locked after "<<FailedLoginCounts<<"trial(s)";
				return false;
			}
			cout << "Enter UserName ";
			cin >> UserName;
			cout << "Enter Password ";
			cin >> Password;
			CurrentUser = clsUser::Find(UserName, Password);
			LoginFailed = CurrentUser.IsEmpty();
		} while (LoginFailed);
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenu();
		return true;

	}
public:
	static bool ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return _Login();
	}
};

