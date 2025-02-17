#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsDeleteClientScreen :protected clsScreen
{
	static void _PrintClient(clsBankClient& Client) {
		_DrawScreenHeader("Delete Client Screen ");
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
public :
	static void ShowDeleteClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("\tDelete Client Screen");
		string AccountNumber = "";
		cout << "\n Please enter account number !";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Account number is not found , please choose another one !";
			AccountNumber = clsInputValidate::ReadString();

		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\n Are you sure you want to delete this client   y/n ?";
		char answer = 'n';
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {

			if (Client1.Delete())
			{
				cout << "\n Client is deleted successfully :)";
				_PrintClient(Client1);
			}
			else
			{
				cout << "\n Client was not deleted ";
			}
		}




	}

};

