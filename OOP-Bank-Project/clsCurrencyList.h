#pragma once
#include<iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"

class clsCurrencyList :protected clsScreen
{
private:
    static void PrintCurrenciesList(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.GetCountry();
        cout << "| " << setw(8) << left << Currency.GetCurrencyCode();
        cout << "| " << setw(45) << left << Currency.GetCurrencyName();
        cout << "| " << setw(10) << left << Currency.GetRate();

    }
public:
    static void ShowCurrenciesList()
    {

        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currencies(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Currency Code";
        cout << "| " << left << setw(45) << "Currency Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency Currency: vCurrencies)
            {

                PrintCurrenciesList( Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }


};

