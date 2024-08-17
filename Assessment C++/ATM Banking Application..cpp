#include <iostream>
#include <string>
// ATM Banking Application

#include <ctime>
using namespace std;

class ATM 
{
public:
    int pin;
    double balance, deposit;
    string name, address, location;

    ATM(int n, double m) 
	{
        pin = n;
        balance = m;
    }

    void displayWelcomeScreen() 
	{
        time_t now = time(0);
        char* date = ctime(&now);

        cout << "\n\n\t =============== WELCOME TO ATM =============== \n\n";
        cout << "\t\t     ----------------------- \n\n";
        cout << "\t\tCurrent date : " << date << "\n";
        cout << "\t\t     ----------------------- \n";
    }

    void display() 
	{
        cout << "\n\n\t =============== ATM ACCOUNT DEPOSIT SYSTEM =============== \n\n";
    }

    void displaymain() 
	{
        cout << "\n\n -->Account holder name : " << name << "\n";
        cout << "\n\n -->Account holder address : " << address << "\n";
        cout << "\n\n -->The branch location : " << location << "\n";
        cout << "\n\n -->Account balance : " << balance << "\n";
    }

    void displaydeposit() 
	{
        cout << "\n\n -- Available balance : Rs. " << balance << "\n";
        cout << "\n\n -- Enter amount to deposited : ";
        cin >> deposit;
        balance += deposit;
        cout << "\n\n\t -- Your total available balance : " << balance << "\n";
    }
};

class Withdraw : public ATM 
{
public:
    Withdraw(int n, double m, string a, string b, string c) : ATM(n, m) 
	{
        name = a;
        address = b;
        location = c;
    }


    void withdrawAmount() 
	{
        double withdraw;
        cout << "\n\n -- Enter amount to withdraw : ";
        cin >> withdraw;

        if (balance < withdraw) 
		{
            cout << "\n\n\t ---------- ATM ACCOUNT WITHDRAW SYSTEM ---------- \n\n";
            displaymain();
            cout << "\n\n Insufficient balance in your account.\n";
            cout << "\n\n Sorry!!";
        }
        else 
		{
            cout << "\n\n\t ---------- ATM ACCOUNT WITHDRAW SYSTEM ---------- \n\n";
            balance -= withdraw;
            displaymain();
            cout << "\n\n -- After withdrawal, your total balance : " << balance << "\n";
        }
    }

    void displayBalance() 
	{
        cout << "\n\n\t =============== ATM ACCOUNT BALANCE DISPLAY SYSTEM =============== \n\n";
        displaymain();
        cout << "\n\n -- Your balance in account : " << balance << "\n";
    }
};

int main() 
{
    Withdraw withdraw(12345, 50000, "Nik ", "Ahemdabad", "I dont know please dont ask me!! ");
    withdraw.displayWelcomeScreen();

    cout << "\n\n -> Press 1 and press enter to account pin number\n\n";
    cout << "                             or                                   ";
    cout << "\n\n -> Press 0 and press enter to get help.\n";
    cout << "\n\n ----- Enter your choice : ";
    int select;
    cin >> select;

    if (select == 1) 
	{
        cout << "\n\n\t =============== ATM ACCOUNT ACCESS =============== \n\n";
        cout << "\n\n -- Enter your pin access number! : ";
        int atm_pin;
        cin >> atm_pin;

        if (withdraw.pin == atm_pin) 
		{
            cout << " \n\n\t =============== ATM MAIN MENU SCREEN =============== \n\n";
            cout << "\n\n --->Enter 1 to deposit cash\n";
            cout << "\n\n --->Enter 2 to withdraw cash\n";
            cout << "\n\n --->Enter 3 to balance inquiry\n";
            cout << "\n\n --->Enter 0 to exit ATM\n";

            while (true) 
			{
                cout << "\n\n ----- Select any option from the menu : ";
                cin >> select;

                if (select == 0) 
				{
                    cout << "\n\n =============== You have been successfully logged out =============== \n";
                    break;
                }

                switch (select) 
				{
                case 1:
                    withdraw.display();
                    withdraw.displaymain();
                    withdraw.displaydeposit();
                    break;

                case 2:
                    withdraw.withdrawAmount();
                    break;

                case 3:
                    withdraw.displayBalance();
                    break;

                default:
                    break;
                }
            }
        }
        else 
		{
            cout << "\n\n\t  =============== THANK YOU =============== \n\n";
            cout << "\n\n --- You had made your attempt which failed!!! No more attempts allowed! Sorry!\n";
        }
    }
    else if (select == 0) 
	{
        cout << " \n\t =============== ATM ACCOUNT STATUS =============== \n\n";
        cout << "\n\n ---You must have the correct pin number to access this account. See your\n";
        cout << "\n\n ---bank representative for assistance during bank opening hours.\n";
        cout << "\n\n ---Thanks for your choice \n" ;
    }

}

