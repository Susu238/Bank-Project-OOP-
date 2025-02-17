#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindClientScreen : protected clsScreen
{
private :
	static void _PrintClient(clsBankClient& Client) {
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
    static void ShowFindClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }

        _DrawScreenHeader("\tFind Client Screen");

        string AccountNumber;
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintClient(Client1);

    }

};

