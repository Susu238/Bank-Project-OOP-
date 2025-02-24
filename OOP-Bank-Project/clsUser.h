#pragma once
#include<iostream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"
#include <vector>
#include <fstream>

class clsUser :public clsPerson
{
private :

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password ;
	int _Permissions;
	bool _MarkedForDelete = false;
	struct stLoginRegisterRecord;

	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Separator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;
		vector <string> LoginRegisterDataLine = clsString::Split(Line, Separator);
			LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
		LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		LoginRegisterRecord.Password = clsUtil::DecryptText( LoginRegisterDataLine[2]);
		LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

		return LoginRegisterRecord;

	}

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector<string> vUserData;
		vUserData = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));

	}
	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{

		string stUserRecord = "";
		stUserRecord +=User.FirstName + Seperator;
		stUserRecord +=User.LastName + Seperator;
		stUserRecord +=User.Email + Seperator;
		stUserRecord +=User.Phone + Seperator;
		stUserRecord +=User.GetUserName() + Seperator;
		stUserRecord +=clsUtil::EncryptText(User.Password)+ Seperator;
		stUserRecord += to_string(User.Permissions);

		return stUserRecord;

	}
	static  vector <clsUser> _LoadUsersDataFromFile()
	{

		vector <clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsUser User = _ConvertLineToUserObject(Line);

				vUsers.push_back(User);
			}

			MyFile.close();

		}

		return vUsers;

	}

	static void _SaveUsersDataToFile(vector <clsUser> vUsers)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsUser C : vUsers)
			{
				if (C.MarkedForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConvertUserObjectToLine(C);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& C : _vUsers)
		{
			if (C.GetUserName() == GetUserName())
			{
				C = *this;
				break;
			}

		}

		_SaveUsersDataToFile(_vUsers);

	}

	void _AddNew()
	{

		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	  string _PrepareLoginRecord(string Separator ="#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() +Separator;
		LoginRecord += UserName + Separator;
		LoginRecord += clsUtil::EncryptText(Password) + Separator;
		LoginRecord += to_string(Permissions) ;
		return LoginRecord;



	}


public:
	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;

	};

	enum enPermissions {eAll = -1,pListClients = 1,pAddNewClient = 2 ,pDeleteClient = 4, pUpdateClients = 8, pFindClient =16
		,pTransactions=16, pManageUsers = 64,pLoginRegister =128
	};
	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName
		, string Password , int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;
	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;
	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int  GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	static clsUser Find(string UserName)
	{


		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser Client = _ConvertLineToUserObject(Line);
				if (Client.UserName == UserName)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password)
	{



		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser  User = _ConvertLineToUserObject(Line);
				if (User.UserName ==UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}

			}

			MyFile.close();

		}
		return _GetEmptyUserObject();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{

				return enSaveResults::svFaildEmptyObject;

			}

		}

		case enMode::UpdateMode:
		{


			_Update();

			return enSaveResults::svSucceeded;

			break;
		}

		case enMode::AddNewMode:
		{
			//This will add new record to file or database
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}



	}

	static bool IsUserExist(string UserName)
	{

		clsUser User1 = clsUser::Find(UserName);
		return (!User1.IsEmpty());
	}

	bool Delete()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& C : _vUsers)
		{
			if (C.UserName == _UserName)
			{
				C._MarkedForDelete = true;
				break;
			}

		}

		_SaveUsersDataToFile(_vUsers);

		*this = _GetEmptyUserObject();

		return true;

	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool CheckPermissionAccess(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;
		if ((Permission & this->Permissions) == Permission)
			return true;
		else
			return false;
}
	 void  RegisterLogin()
	{
		string DataLine = _PrepareLoginRecord();
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
		}
		MyFile.close();
	}

	 static  vector <stLoginRegisterRecord> GetLoginRegisterList()
	 {

		 vector <stLoginRegisterRecord> vLoginRegisterRecord;

		 fstream MyFile;
		 MyFile.open("LoginRegister.txt", ios::in);//read Mode

		 if (MyFile.is_open())
		 {

			 string Line;

			 stLoginRegisterRecord LoginRegisterRecord;
			 while (getline(MyFile, Line))
			 {

				 LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

				 vLoginRegisterRecord.push_back(LoginRegisterRecord);
			 }

			 MyFile.close();

		 }

		 return vLoginRegisterRecord;

	 }



};

