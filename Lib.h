#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
const string ClientsFileName = "Clients.txt";




namespace Functions
{


	string ReadString()
	{
		string S1;
		cout << "PLEASE ENTER YOUR STRING?" << endl;
		getline(cin, S1);
		return S1;
	}



	void PrintFirstLetterOfEachWord(string S)
	{
		bool isFirstLetter = true;

		cout << endl << "FIRST LETTERS OF THIS STRING: " << endl;

		for (short i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ' && isFirstLetter)
			{
				cout << S[i] << endl;
			}

			isFirstLetter = (S[i] == ' ' ? true : false);
		}
	}
	void UpperFirstLetterOfEachWord(string S)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ' && isFirstLetter)
			{
				S[i] = toupper(S[i]);
			}
			isFirstLetter = (S[i] == ' ' ? true : false);
		}
		cout << S << endl;
	}

	string UpperAllString(string S)
	{
		for (short i = 0; i < S.length(); i++)
		{
			S[i] = toupper(S[i]);
		}
		return S;
	}
	string LowerAllString(string S)
	{
		for (short i = 0; i < S.length(); i++)
		{
			S[i] = tolower(S[i]);
		}
		return S;
	}

	char ReadChar()
	{
		char Ch1;
		cout << "PLEASE ENTER A CHAR?" << endl;
		cin >> Ch1;
		return Ch1;
	}
	char InvertLetterCase(char Char)
	{
		return isupper(Char) ? tolower(Char) : toupper(Char);
	}


	string InvertAllStringLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}


	short StringLength(string S)
	{
		return S.length();
	}
	short CapitalLettersCount(string S)
	{
		short counter = 0;
		for (short i = 0; i < S.length(); i++)
		{
			if (isupper(S[i]))
				counter++;
		}
		return counter;
	}
	short SmalllLettersCount(string S)
	{
		short counter = 0;
		for (short i = 0; i < S.length(); i++)
		{
			if (islower(S[i]))
				counter++;
		}
		return counter;
	}



	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1 };
	short CountLetters(string S, enWhatToCount WhatToCount)
	{
		short Counter = 0;

		for (short i = 0; i < S.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S[i]))
				Counter++;

			if (WhatToCount == enWhatToCount::SmallLetters && islower(S[i]))
				Counter++;
		}
		return Counter;
	}


	short CountLetter(char Letter, string S)
	{
		short Counter = 0;

		for (short i = 0; i < S.length(); i++)
		{
			if (S[i] == Letter)
				Counter++;
		}

		return Counter;
	}


	bool isVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);

		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
	}

	short VowelsLettersCount(string Str)
	{
		short counter = 0;
		for (short i = 0; i < Str.length(); i++)
		{
			if (isVowel(Str[i]))
				counter++;
		}
		return counter;
	}





	void PrintEachWordInString(string S1)
	{

		string delim = " ";

		cout << "\nYour string wrords are: \n\n";

		short pos = 0; string sWord;


		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);

			if (sWord != "")
			{
				cout << sWord << endl;
			}

			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			cout << S1 << endl;
		}
	}


	vector<string> SplitString(string S1, string Delim)
	{

		vector<string> vString;
		short pos = 0;
		string sWord;



		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);

			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			S1.erase(0, pos + Delim.length());
		}

		if (S1 != "")
		{
			vString.push_back(S1);
		}

		return vString;
	}



	string ReverseWordsInString(string S1)
	{
		vector<string> vString;
		string S2 = "";

		vString = SplitString(S1, " ");

		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}

		return S2;
	}




	string ReplaceWordInString(string S1, string StringToReplace, string StringReplaceTo)
	{
		short pos = S1.find(StringToReplace);

		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), StringReplaceTo);
			pos = S1.find(StringToReplace);
		}

		return S1;
	}






	//-----------------------------------------------------------------------------------------
	struct sClient
	{
		string AccountNumber;
		string PinCode;
		string Name;
		string Phone;
		double AccountBalance;
		bool MarkForDelete = false;
		bool MarkForUpdate = false;
	};

	

	


	sClient ReadNewClient()
	{
		sClient Client;

		cout << "Enter Account Number? ";
		getline(cin >> ws, Client.AccountNumber);

		cout << "Enter PinCode? ";
		getline(cin, Client.PinCode);

		cout << "Enter Name? ";
		getline(cin, Client.Name);

		cout << "Enter Phone? ";
		getline(cin, Client.Phone);

		cout << "Enter Account Balance? ";
		cin >> Client.AccountBalance;

		return Client;
	}

	string ConvertRecordToLine(sClient Client, string Seperator)
	{
		string Line = "";

		Line += Client.AccountNumber + Seperator;
		Line += Client.PinCode + Seperator;
		Line += Client.Name + Seperator;
		Line += Client.Phone + Seperator;
		Line += to_string(Client.AccountBalance);

		return Line;
	}

	sClient ConvertLineToRecord(string Line, string Seperator)
	{
		sClient Client;
		vector<string> vString;
		vString = SplitString(Line, Seperator);

		Client.AccountNumber = vString[0];
		Client.PinCode = vString[1];
		Client.Name = vString[2];
		Client.Phone = vString[3];
		Client.AccountBalance = stod(vString[4]);

		return Client;
	}

	void PrintClientRecord(sClient Client)
	{
		cout << "\n Account Number : " << Client.AccountNumber << endl;
		cout << "\n Pin Code : " << Client.PinCode << endl;
		cout << "\n Name : " << Client.Name << endl;
		cout << "\n Phone : " << Client.Phone << endl;
		cout << "\n Account Balance : " << Client.AccountBalance << endl;
	}

	void AddLineToFile(string FileName, string Line)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}

	

	void AddNewClient()
	{
		sClient newClient;
		newClient = ReadNewClient();
		string Line = ConvertRecordToLine(newClient, "---");
		AddLineToFile(ClientsFileName, Line);
	}

	void AddClients()
	{
		char AddMore = 'Y';

		do
		{
			system("cls");
			cout << "Adding New Client:\n\n";

			AddNewClient();

			cout << "Client Added Successfully, do you want to add more clients? (Y,N) :";
			cin >> AddMore;

		} while (toupper(AddMore) != 'N');
		system("cls");

	}

	vector <sClient> LoadClientsDataFromFile(string FileName)
	{
		vector <sClient> vClients;

		fstream MyFile;
		MyFile.open(FileName, ios::in);

		if (MyFile.is_open())
		{
			string Line;
			sClient newClient;
			while (getline(MyFile, Line))
			{
				newClient = ConvertLineToRecord(Line, "---");
				vClients.push_back(newClient);
			}

			MyFile.close();
		}

		return vClients;
	}

	void PrintFormattedClientRecord(sClient Client) {
		cout << "| " << setw(15) << left << Client.AccountNumber;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(40) << left << Client.Name;
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(12) << left << fixed << setprecision(2) << Client.AccountBalance;
	}

	void PrintAllClientsData(vector<sClient> vClients)
	{

		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).\n";
		cout << "________________________________________________________";
		cout << "_________________________________________\n";

		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n";

		for (sClient Client : vClients) {
			PrintFormattedClientRecord(Client);
			cout << endl;
		}

		cout << "________________________________________________________";
		cout << "_________________________________________\n";
	}

	bool FindClientByAccountNumber(sClient& Client, string AccountNumber, vector<sClient> vClients)
	{
		for (sClient C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				Client = C;
				return true;
			}
		}
		return false;
	}



	string ReadAccountNumber()
	{
		string AccountNumber;
		cout << "Please Enter Account Number? ";
		cin >> AccountNumber;
		return  AccountNumber;
	}


	void PrintClientCard(sClient Client)
	{
		cout << "--------------------------------------------";
		cout << "\nThe following are the client details:\n";
		cout << "\nAccount Number: " << Client.AccountNumber;
		cout << "\nPin Code     : " << Client.PinCode;
		cout << "\nName         : " << Client.Name;
		cout << "\nPhone        : " << Client.Phone;
		cout << "\nAccount Balance: " << Client.AccountBalance << endl;
		cout << "--------------------------------------------";
	}


	//--------------------------------------------------------------------------



	bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients)
	{
		for (sClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.MarkForDelete = true;
				return true;
			}
		}
		return false;
	}

	void SaveClientsDataToFile(string FileName, vector<sClient> vClients)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out);

		string Line;
		if (MyFile.is_open())
		{
			for (sClient C : vClients)
			{
				if (C.MarkForDelete == false && C.MarkForUpdate == false)
				{
					Line = ConvertRecordToLine(C, "---");
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
		else
		{
			cout << "Error: Could not open file for writing." << endl;
		}
	}

	bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
	{
		sClient Client;
		char Answer = 'n';

		if (FindClientByAccountNumber(Client, AccountNumber, vClients))
		{
			PrintClientCard(Client);

			cout << "\n Are U Sure You You Want Delete This Client? (y/n) ";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
				MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
				SaveClientsDataToFile(ClientsFileName, vClients);

				vClients = LoadClientsDataFromFile(ClientsFileName);

				cout << "\n\n Client Deleted Successfully.";
				return true;
			}
		}
		else
		{
			cout << "\n Client with Account Number(" << AccountNumber << ") is Not Found.";
			return false;
		}


	}

	sClient ChangeClientRecord(string AccountNumber)
	{
		sClient Client;
		Client.AccountNumber = AccountNumber;

		cout << "\n\n Enter PinCode? ";
		getline(cin >> ws, Client.PinCode);
		cout << "Enter Name? ";
		getline(cin, Client.Name);
		cout << "Enter Phone? ";
		getline(cin, Client.Phone);
		cout << "Enter Account Balance? ";
		cin >> Client.AccountBalance;

		return Client;
	}


	bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
	{
		sClient Client;
		char Answer = 'n';

		if (FindClientByAccountNumber(Client, AccountNumber, vClients))
		{
			PrintClientCard(Client);

			cout << "\n Are U Sure You You Want Update This Client? (y/n) ";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
				for (sClient& C : vClients)
				{
					if (C.AccountNumber == AccountNumber)
					{
						C = ChangeClientRecord(AccountNumber);
						break;
					}
				}

				SaveClientsDataToFile(ClientsFileName, vClients);
				vClients = LoadClientsDataFromFile(ClientsFileName);

				cout << "\n\n Client Updated Successfuly.";
				return true;
			}
		}
		else
		{
			cout << "\n Client with Account Number(" << AccountNumber << ") is Not Found.";
			return false;
		}
	}


}