#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsAddNewClientScreen : protected clsScreen
{
private :
	static void _ReadClientInfo(clsBankClient& Client) {
		cout << "\n Enter first name :";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\n Enter last  name :";
		Client.LastName = clsInputValidate::ReadString();
		cout << "\n Enter email :";
		Client.Email = clsInputValidate::ReadString();
		cout << "\n Enter phone :";
		Client.Phone = clsInputValidate::ReadString();
		cout << "\n Enter Pin Code :";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "\n Enter account balance:";
		Client.AccountBalance = clsInputValidate::ReadNumber<float>();





	}
	static void _PrintClient(clsBankClient& Client) {
		_DrawScreenHeader("Add New Client Screen ");
		cout << "\n Client Card";
		cout << "\n-----------------------------------------";
		cout << "\n First Name :" << Client.FirstName;
		cout << "\n Last Name :" << Client.LastName;
		cout << "\n Full Name :" << Client.FullName();
		cout << "\n Email     :" << Client.Email;
		cout << "\n Phone     :" << Client.Phone;
		cout << "\n Account Number    :" << Client.GetAccountNumber();
		cout << "\n Pin Code    :" << Client.PinCode;
		cout << "\n AccountBalance    :" << Client.AccountBalance;
		cout << "\n-----------------------------------------";
	}

public:
	static void _ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}

		string AccountNumber = "";
		cout << "\n Please enter account number !";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Account number is already used , please choose another one !";
			AccountNumber = clsInputValidate::ReadString();

		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\n Account is added successfully !";
			_PrintClient(NewClient);

			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\n Error account is not saved because it is empty  !";
			break;
		}


		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{

			cout << "\nError account is used ,please choose another one!\n";
			break;
		}

		}
	}


};

