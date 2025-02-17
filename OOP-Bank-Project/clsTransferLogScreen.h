#pragma once
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{
private:
	static void _PrintTransferLogRecordLine(clsBankClient:: stTransferLogRecord  TransferLogRecord)
		 {
		cout << "| " << setw(15) << left << clsDate::GetSystemDateTimeString();
		cout << "| " << setw(15) << left << TransferLogRecord.SourceAccountNumber;
		cout << "| " << setw(15) << left << TransferLogRecord.DestinationAccountNumber;
		cout << "| " << setw(15) << left << TransferLogRecord.Amount;
		cout << "| " << setw(15) << left << TransferLogRecord.srcBalanceAfter;

		cout << "| " << setw(15) << left << TransferLogRecord.DestinationBalance;

		cout << "| " << setw(15) << left << CurrentUser.UserName;


	}
public :
	static void ShowTransferLogScreen()
	{
		vector < clsBankClient::stTransferLogRecord>  vTransferLogRecord = clsBankClient::GetTransferLogList();
		_DrawScreenHeader("\t Transfer Log");
		cout << "\n\t\t\t\t\tUsers List (" << vTransferLogRecord.size() << ") Record(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "| " << left << setw(15) << "Date";
		cout << "| " << left << setw(21) << "S.Client";
		cout << "| " << left << setw(12) << "D.Client";
		cout << "| " << left << setw(12) << "Amount";
		cout << "| " << left << setw(12) << " S.Balance";
		cout << "| " << left << setw(12) << " D.Balance";
		cout << "| " << left << setw(12) << " User";

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (vTransferLogRecord.size() == 0)
		{
			cout << "\t\t\t\t No Transfer available in the system !";
		}
		else {
			for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
			{
				_PrintTransferLogRecordLine(Record);
				

				cout << endl;
			}
			cout << "\n_______________________________________________________";
			cout << "_________________________________________\n" << endl;

		}



	}
};

