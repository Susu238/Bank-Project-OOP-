
#include <iostream>
#include "clsLoginScreen.h"
using namespace std;
int main()
{

        while (true) {
            if (!clsLoginScreen::ShowMainMenu()) {
                break;
            }
        }
        return 0;
    
}
//#include <iostream>
//#include "clsCurrency.h"
//
//
//static void _PrintCurrency(clsCurrency Currency)
//{
//    cout << "\nCurrency Card:\n";
//    cout << "_____________________________\n";
//    cout << "\nCountry    : " << Currency.GetCountry();
//    cout << "\nCode       : " << Currency.GetCurrencyCode();
//    cout << "\nName       : " << Currency.GetCurrencyName();
//    cout << "\nRate(1$) = : " << Currency.GetRate();
//
//    cout << "\n_____________________________\n";
//
//}
//
//int main()
//
//{
//    clsCurrency Currency1 = Currency1.FindByCode("jod");
//
//    if (Currency1.IsEmpty())
//    {
//        cout << "\nCurrency Is Not Found!\n";
//    }
//    else
//    {
//        _PrintCurrency(Currency1);
//    }
//
//    clsCurrency Currency2 = Currency2.FindByCountry("Egypt");
//
//    if (Currency2.IsEmpty())
//    {
//        cout << "\nCurrency Is Not Found!\n";
//    }
//    else
//    {
//        _PrintCurrency(Currency2);
//    }
//
//    cout << "Currency1 after updating Rate:\n";
//    Currency1.SetRate(0.71);
//    _PrintCurrency(Currency1);
//
//
//    return 0;
//}
//
