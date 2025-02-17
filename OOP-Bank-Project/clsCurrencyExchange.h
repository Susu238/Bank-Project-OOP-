#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsCurrencyList.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"
class clsCurrencyExchange :protected clsScreen
{
private:
	enum enCurrencyMainMenuOptions {
		eCurrencyList = 1, eFindCurrency = 2, eUpdateCurrency = 3,
		 eCurrencyCalculator = 4, eMainMenu = 5
	};
	static short _ReadCurrencyMainMenuOptions()
	{
		cout << setw(37) << left << " " << "Choose what do you want to do ? [1 to 5] ";
		short Choice = clsInputValidate::ReadNumberBetween(1, 5, "Enter a number between 1 to 5");
		return Choice;


	}
	static  void _GoBackToCurrencyMainMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

		system("pause>0");
		ShowCurrencyExchangeScreen();
	}
	void static _ShowCurrencyListScreen()
	{
		//cout << "\n Currency List will be here ";
		clsCurrencyList::ShowCurrenciesList();

	}
	void static _ShowFindCurrencyScreen()
	{
		//cout << "\nFind  Currency  will be here ";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	void static _ShowUpdateCurrencyScreen()
	{
		//cout << "\n Update Currency  will be here ";
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();

	}
	void static _ShowCurrencyCalculatorScreen()
	{
		//cout << "\n Currency Calculator will be here ";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

	}

	void static _ShowCurrencyMainScreen()
	{
		cout << "\n Currency Main Menu be here ";

	}

	static void _PerformCurrencyMainMenuOptions(enCurrencyMainMenuOptions CurrencyMainMenuOption)
	{
		switch (CurrencyMainMenuOption)
		{
		case clsCurrencyExchange::eCurrencyList:
			system("cls");
			_ShowCurrencyListScreen();
			_GoBackToCurrencyMainMenu();

			break;
		case clsCurrencyExchange::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
				_GoBackToCurrencyMainMenu();
			break;
		case clsCurrencyExchange::eUpdateCurrency:
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoBackToCurrencyMainMenu();
			break;
		case clsCurrencyExchange::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyMainMenu();
			break;

		case clsCurrencyExchange::eMainMenu:
			system("cls");
			_ShowCurrencyMainScreen();
			_GoBackToCurrencyMainMenu();
			break;


		default:
			break;
		}
	}



public :
	static void ShowCurrencyExchangeScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\t Currency Main Menu Screen");
		cout << setw(37) << left << " " << "======================================================================\n";
		cout << setw(37) << left << " " << "\t\t\tCurrency Main Menu \n";
		cout << setw(37) << left << " " << "======================================================================\n";
		cout << setw(37) << left << " " << "\t[1] Currencies  List \n";
		cout << setw(37) << left << " " << "\t[2] Find Currency  \n";

		cout << setw(37) << left << " " << "\t[3] Update Currency  \n";
		cout << setw(37) << left << " " << "\t[4] Currency Calculator \n";

		cout << setw(37) << left << " " << "\t[5]Main Menu \n";
		cout << setw(37) << left << " " << "======================================================================\n";



		_PerformCurrencyMainMenuOptions((enCurrencyMainMenuOptions)_ReadCurrencyMainMenuOptions());





	}
};

