#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include <vector>
#include <fstream>
class clsCurrency
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;
	string _Country;
	string	_CurrencyName;
	string _CurrencyCode;
	float  _Rate;
	static clsCurrency _ConvertCurrencyLineToRecord(string Line, string Separator = "#//#")
	{
		vector <string> vCurrencyData = clsString::Split(Line, Separator);
		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));

	}
	static string _ConvertCurrencyRecordToLine(clsCurrency Currency, string Separator = "#//#")
	{
		string CurrencyRecord = "";
		CurrencyRecord += Currency.GetCountry() + Separator;
		CurrencyRecord += Currency.GetCurrencyCode() + Separator;
		CurrencyRecord += Currency.GetCurrencyName() + Separator;
		CurrencyRecord += to_string(Currency.GetRate())+ Separator;

		return CurrencyRecord;

	}
	static  vector <clsCurrency> _LoadCurrencyDataFromFile()
	{

		vector <clsCurrency> vCurrencies;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsCurrency Currency = _ConvertCurrencyLineToRecord(Line);

				vCurrencies.push_back(Currency);
			}

			MyFile.close();

		}

		return vCurrencies;

	}
	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencies)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency Currency : vCurrencies)
			{				{
					DataLine = _ConvertCurrencyRecordToLine(Currency);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsCurrency> _vCurrencies;
		_vCurrencies = _LoadCurrencyDataFromFile();

		for (clsCurrency& Currency : _vCurrencies)
		{
			if (Currency.GetCurrencyCode() == GetCurrencyCode())
			{
				Currency = *this;
				break;
			}

		}

		_SaveCurrencyDataToFile(_vCurrencies);

	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode ,string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyName = CurrencyName;
		_CurrencyCode = CurrencyCode;
		_Rate = Rate;
	}
	static vector <clsCurrency> GetAllUSDRates()
	{

		return _LoadCurrencyDataFromFile();

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string GetCountry()
	{
		return _Country;
	}
	string GetCurrencyName()
	{
		return _CurrencyName;
	}
	string GetCurrencyCode()
	{
		return _CurrencyCode;
	}


	void SetRate(float Rate)
	{
		_Rate =Rate;
		_Update();
	}

	float GetRate()
	{
		return _Rate;
	}
	__declspec(property(get = GetRate, put = SetRate)) float Rate;

	static clsCurrency FindByCode(string CurrencyCode)
	{

		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertCurrencyLineToRecord(Line);
				if (Currency.GetCurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCountry(string Country)
	{

		Country = clsString::UpperAllString(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertCurrencyLineToRecord(Line);
				if (clsString::UpperAllString(Currency.GetCountry()) == Country)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();
	}
	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());

	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}
	float ConvertToUSD(float Amount)
	{
		return (float)( Amount/ GetRate());
	}
	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);
		if (Currency2.GetCurrencyCode() == "USD")
		{
			return AmountInUSD;
		}
		return (float)(AmountInUSD * Currency2.GetRate());
	}
};

