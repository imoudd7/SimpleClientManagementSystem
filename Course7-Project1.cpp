#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Lib.h"
using namespace Functions;
using namespace std;


void GoBackToMainMenue();

void ShowClientList()
{
    system("cls");
    PrintAllClientsData(LoadClientsDataFromFile(ClientsFileName));

    GoBackToMainMenue();
}

void AddNewClientScreen()
{
    char Answer = 'n';
    do
    {
        system("cls");
        cout << "------------------------------------------" << endl;
        cout << "         Add New Clients Screen           " << endl;
        cout << "------------------------------------------" << endl;
        cout << "Adding New Client: \n\n";
        AddNewClient();

        cout << "\n Client Added Succussfuly, do you want to add more clients? (Y/N) ";
        cin >> Answer;

    } while(Answer == 'y' || Answer == 'Y');


    GoBackToMainMenue();

}

void DeleteClientScreen(vector<sClient> &vClients)
{
    string AcNo = "";
    system("cls");
    cout << "------------------------------------------" << endl;
    cout << "          Delete Client Screen            " << endl;
    cout << "------------------------------------------" << endl;

    AcNo = ReadAccountNumber();

    DeleteClientByAccountNumber(AcNo,vClients);

    GoBackToMainMenue();

}

void UpdateClientScreen(vector<sClient> &vClients)
{
    string AcNo = "";
    system("cls");
    cout << "------------------------------------------" << endl;
    cout << "          Update Client Screen            " << endl;
    cout << "------------------------------------------" << endl;

    AcNo = ReadAccountNumber();

    UpdateClientByAccountNumber(AcNo, vClients);

    GoBackToMainMenue();

}

void FindClientScreen(vector<sClient> &vClients)
{
    string AcNo = "";
    system("cls");
    cout << "------------------------------------------" << endl;
    cout << "          Find Client Screen            " << endl;
    cout << "------------------------------------------" << endl;

    AcNo = ReadAccountNumber();

    sClient Client;

    if (FindClientByAccountNumber(Client,AcNo,vClients))
         PrintClientCard(Client);
    else
    {
        cout << "Account with (" << AcNo << ") Not Found." << endl;
    }

   
    GoBackToMainMenue();

}

void ExitScreen()
{
    system("cls");
    cout << "------------------------------------------" << endl;
    cout << "               Program Ends               " << endl;
    cout << "------------------------------------------" << endl;
    system("pause>0");
}

void MainMenueScreen()
{
    cout << "=========================================" << endl;
    cout << "            Main Menue Screen            " << endl;
    cout << "=========================================" << endl;
    cout << "       [1] Show Client List.             " << endl;
    cout << "       [2] Add New Client.               " << endl;
    cout << "       [3] Delete Client.                " << endl;
    cout << "       [4] Update Client Info.           " << endl;
    cout << "       [5] Find Client.                  " << endl;
    cout << "       [6] Exit.                         " << endl;
    cout << "=========================================" << endl;
}

void Choosing()
{
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    short choose = 0;
    cout << "Choose what do you want to do? [1 to 6]? ";
    cin >> choose;

    switch (choose)
    {
    case 1:
        ShowClientList();
        break;
    case 2:
        AddNewClientScreen(); 
        break;
    case 3:
        DeleteClientScreen(vClients);
        break;
    case 4:
        UpdateClientScreen(vClients);
        break;
    case 5:
        FindClientScreen(vClients);
        break;
    case 6:
        ExitScreen();
        exit(0); 
    default:
        cout << "Invalid choice. Please choose a number between 1 and 6." << endl;
        break;
    }
}

void Start()
{
    system("cls");
    MainMenueScreen();
    Choosing();
}

void GoBackToMainMenue()
{
    cout << "Press any key to go back to the Main Menu...";
    system("pause>0");
    Start();
}




int main()
{
    Start();
    return 0;
}
