#pragma once
#include<iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyScreen: protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency& Currency) {
		cout << "\n Currency Card";
		cout << "\n-----------------------------------------";
		cout << "\n Country :" << Currency.GetCountry();
		cout << "\n Currency Code:" << Currency.GetCurrencyCode();
		cout << "\nCurrency Name :" << Currency.GetCurrencyName();
		cout << "\n Rate ($1)   :" << Currency.GetRate();
		cout << "\n-----------------------------------------";
	}
	static float _ReadRate()
	{
		cout << "\n Enter new rate for  " ;
		float Rate = 0;
			Rate = clsInputValidate::ReadNumber<float>();
		return Rate;
	}

public :
	static void ShowUpdateCurrencyScreen()
	{

		string CurrencyCode = "";

		cout << "\n Please enter Currency code !";
		CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\n Currency code is not found please choose another one !";
			CurrencyCode= clsInputValidate::ReadString();

		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);
		cout << "\n Are you sure you want to update this currency y/n ?";
		char answer = 'n';
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			cout << "\n\nUpdate currency:";
			cout << "\n____________________\n";

			Currency.SetRate(_ReadRate());
				cout << "\nCurrency is updated successfully :)";
				_PrintCurrency(Currency);
			}
			else
			{
				cout << "\nCurrency is not updated  ";
			}

	}
};

