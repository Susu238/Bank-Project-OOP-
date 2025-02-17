#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen :protected clsScreen
{
	static void _PrintCurrency(clsCurrency  Currency , string Title = "Currency Card") {
		cout << "\n-----------------------------------------";
		cout << "\n Country :" << Currency.GetCountry();
		cout << "\n Currency Code:" << Currency.GetCurrencyCode();
		cout << "\nCurrency Name :" << Currency.GetCurrencyName();
		cout << "\n Rate ($1)   :" << Currency.GetRate();
		cout << "\n-----------------------------------------";
	}

	static float _ReadAmount()
	{
		cout << "\n Enter amount :  ";
		float Amount = 0;
		Amount = clsInputValidate::ReadNumber<float>();
		return Amount ;
	}
	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode = "";

		cout << Message << endl;
		CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\n Currency code is not found please choose another one !";
			CurrencyCode = clsInputValidate::ReadString();

		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;


	}
	static void _PrintCalculationResults(float Amount ,clsCurrency CurrencyFrom , clsCurrency CurrencyTo)
	{
		_PrintCurrency(CurrencyFrom, "Convert from :");
		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);
		cout << endl;
		cout << Amount << " " << CurrencyFrom.GetCurrencyCode() << "=" << AmountInUSD << "USD\n";
		if (CurrencyTo.GetCurrencyCode() == "USD\n")
		{
			return;
		}
		cout << "\n Converting from USD to :";
		_PrintCurrency(CurrencyTo, "Convert to :");
		float AmountInUSD2 = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);
		cout << endl;
		cout << Amount << " " << CurrencyFrom.GetCurrencyCode() << "=" << AmountInUSD2<<" "<<CurrencyTo.GetCurrencyCode();

	}
public :
	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';

		while (Continue == 'y' || Continue == 'Y')
		{

			cout << "\n Enter Currency1 :";


				system("cls");
				_DrawScreenHeader("\t Update Currency Screen");

				clsCurrency CurrencyFrom = _GetCurrency("Please  enter currency1 code  ");
				clsCurrency CurrencyTo = _GetCurrency("Please  enter currency2 code  ");
				float Amount = _ReadAmount();

				_PrintCalculationResults(Amount, CurrencyFrom, CurrencyTo);
				cout << "\n Do you want to perform another calculation y/n ?";
				cin >> Continue;
			}


		}
	
};

