#pragma once
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"


class clsTransferScreen :protected clsScreen
{
private:
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}
	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;
		cout << "\n Enter transfer amount ";
		Amount = clsInputValidate::ReadNumber<float>();
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\n Amount exceeds the available  balance, enter another amount !";
			Amount = clsInputValidate::ReadNumber<float>();

		}
		return Amount;
	}
	static void _PrintClient(clsBankClient& Client) {
		cout << "\n Client Card";
		cout << "\n-----------------------------------------";
		cout << "\n First Name :" << Client.FirstName;
		cout << "\n Last Name :" << Client.LastName;
		cout << "\n Full Name :" << Client.FullName();
		cout << "\n Account Number    :" << Client.GetAccountNumber();
		cout << "\n AccountBalance    :" << Client.AccountBalance;
		cout << "\n-----------------------------------------";
	}

public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\tTransfer Screen");
		cout << "\nPlease Enter Account Number to Transfer From: ";
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(SourceClient);
		cout << "\nPlease Enter Account Number to Transfer To : ";
		clsBankClient DestinationClient= clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(DestinationClient);
		float Amount = ReadAmount(SourceClient);
		cout << "\n Are you sure you want to perform this transaction ? y/n";
		char answer = ' y';
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\n Transfer is done successfully !";
			}
			else
			{
				cout << "\n Transfer is failed !";
			}
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);



	}
};

