#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsInputValidate.h"

class clsWithdrawScreen :protected clsScreen
{
private:
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
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}
public:
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t Withdraw Screen");
		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);
		double Amount = 0;
		cout << "\n Please enter deposit amount ";
		Amount = clsInputValidate::ReadNumber<double>();
		cout << "\n Are you sure you want to perform this transaction ? y/n";
		char answer = ' y';
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			if (Client1.Withdraw(Amount)) {

				cout << "\n Deposit is withdrawn successfully ";
				cout << "\n New Balance is : " << Client1.AccountBalance;

			}
		else
		{
			cout << "\n Can not withdraw , insufficient  balance ";
			cout << "\n Amount to withdraw  is :"<<Amount;
			cout << "\n Your balance is : " <<Client1.AccountBalance;


		}
		}
		else
		{
			cout << "\nOperation was canceled ";

			}
		}

	

};

