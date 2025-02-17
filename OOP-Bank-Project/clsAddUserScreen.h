#pragma once
#include<iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsAddUserScreen :protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser& User) {
		cout << "\n Enter first name :";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\n Enter last  name :";
		User.LastName = clsInputValidate::ReadString();
		cout << "\n Enter email :";
		User.Email = clsInputValidate::ReadString();
		cout << "\n Enter password:";
		User.Password = clsInputValidate::ReadString();
		cout << "\nEnter Permission: ";
		User.Permissions = _ReadPermissionsToSet();




	}
	static void _PrintUser(clsUser& User) {
		_DrawScreenHeader("Add New User  Screen ");
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
    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }
		cout << "\n Users Register? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pLoginRegister;
		}


        return Permissions;

    }

    public:
		static void ShowAddNewUserScreen()
		{
			string UserName = "";
			cout << "\n Please enter user name !";
			UserName= clsInputValidate::ReadString();
			while (clsUser::IsUserExist(UserName))
			{
				cout << "\n User name  is already used , please choose another one !";
				UserName = clsInputValidate::ReadString();

			}
			clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
			_ReadUserInfo(NewUser);

			clsUser::enSaveResults SaveResult;
			SaveResult = NewUser.Save();

			switch (SaveResult)
			{
			case clsUser::enSaveResults::svSucceeded:
			{
				cout << "\nUser is added successfully !";
				_PrintUser(NewUser);

				break;
			}
			case clsUser::enSaveResults::svFaildEmptyObject:
			{
				cout << "\n Error user is not saved because it is empty  !";
				break;
			}


			case clsUser::enSaveResults::svFaildAccountNumberExists:
			{

				cout << "\nError user is used ,please choose another one!\n";
				break;
			}

			}
		}



};

