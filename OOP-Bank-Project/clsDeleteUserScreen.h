#pragma once
#include<iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
{
private:
	static void _PrintUser(clsUser& User) {
		_DrawScreenHeader("Delete User  Screen ");
		cout << "\n User Card";
		cout << "\n-----------------------------------------";
		cout << "\n First Name :" << User.FirstName;
		cout << "\n Last Name :" << User.LastName;
		cout << "\n Full Name :" << User.FullName();
		cout << "\n Email     :" << User.Email;
		cout << "\n Phone     :" << User.Phone;
		cout << "\n User Name    :" << User.UserName;
		cout << "\n Password   :" << User.Password;
		cout << "\n Permission    :" << User.Permissions;
		cout << "\n-----------------------------------------";
	}
public:
	static void ShowDeleteUserScreen() {
		_DrawScreenHeader("\tDelete User Screen");
		string UserName = "";
		cout << "\n Please enter user name  !";
		UserName= clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\n user name is not found , please choose another one !";
			UserName = clsInputValidate::ReadString();

		}
		clsUser User1 = clsUser::Find(UserName);
		_PrintUser(User1);

		cout << "\n Are you sure you want to delete this user  y/n ?";
		char answer = 'n';
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {

			if (User1.Delete())
			{
				cout << "\nUser is deleted successfully :)";
				_PrintUser(User1);
			}
			else
			{
				cout << "\nUser was not deleted ";
			}
		}




	}


};

