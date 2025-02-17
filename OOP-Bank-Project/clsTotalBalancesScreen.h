#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include<iomanip>
#include "clsUtil.h"
class clsTotalBalancesScreen : protected clsScreen
{
private:
	static void _PrintClientRecordLineBalance(clsBankClient Client) {
		cout << "| " << setw(15) << left << Client.GetAccountNumber();

		cout << "| " << setw(20) << left << Client.FullName();

		cout << "| " << setw(12) << left << Client.AccountBalance;

	}
public :
	static  void ShowTotalBalances()
	{
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "\t  Balances List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		double TotalBalance = clsBankClient::GetTotalBalances();
		if (vClients.size() == 0)
		{
			cout << "\t\t\t\t No clients available in the system !";
		}
		else {
			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordLineBalance(Client);
				cout << endl;
			}
			cout << "\n_______________________________________________________";
			cout << "_________________________________________\n" << endl;
			cout << "\n Total balances  :" << TotalBalance << endl;
			cout << "\t\t  (" << clsUtil::NumberToText(TotalBalance) << ")";

		}






	}

};

