#pragma once
#include<iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsFindCurrencyScreen : protected clsScreen
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
	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);

		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}

	}
public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");
		cout << "\nFind by : [1] Code or [2] Country ?";
		short Answer = 1;
		cin >> Answer;
		string CurrencyCode = "";
		if (Answer == 1)
		{
			cout << "\n Please enter Currency code !";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency1);
		}
		else
		{
			string CountryName = "";
			cout << "\n Please enter country name !";
			CountryName = clsInputValidate::ReadString();
			clsCurrency Currency1 = clsCurrency::FindByCountry(CountryName);
			_ShowResults(Currency1);

		}
	}
};

