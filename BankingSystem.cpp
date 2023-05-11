#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <fstream>

int accNum();

using namespace std;

int acc_num;

int accNum()
{
    ifstream ptr;
    ptr.open("Accounts.txt");
    if (!ptr)
    {
        return 1;
    }
    int i = 0;
    string str;
    int y = 0;
    while (!ptr.eof())
    {
        ptr >> y;
        getline(ptr, str);
        i++;
    }
    return y + 1;
    ptr.close();
}

class Bank
{
private:
    static int AccountNumber;
    string fname;
    string lname;
    float AccountBalance;

public:
    Bank()
    {
        fname = "";
        lname = "";
        AccountBalance = 0.0f;
    }
    void AddAccount()
    {
        cout << "Enter Your First Name : ";
        cin >> fname;
        cout << "Enter Your Second Name: ";
        cin >> lname;
        cout << "Enter Your Initial Bank Balance : ";
        cin >> AccountBalance;
        ofstream ptr("Accounts.txt", ios::app);
        if (AccountNumber == 1)
        {
            ptr << AccountNumber << "\t" << fname << "\t" << lname << "\t" << AccountBalance;
        }
        else
        {
            ptr << endl
                << AccountNumber << "\t" << fname << "\t" << lname << "\t" << AccountBalance;
        }
        AccountNumber++;
        ptr.close();
    }
    void showAllAccounts()
    {
        int accnum;
        float bal;
        string fname;
        string lname;
        cout << "All the Accounts registered in this Bank are" << endl
             << endl;
        ifstream ptr;
        ptr.open("Accounts.txt");
        if (!ptr)
        {
            cout << "No accounts are registered in this yet" << endl
                 << endl;
        }
        else
        {
            while (!ptr.eof())
            {
                ptr >> accnum >> fname >> lname >> bal;
                cout << "Account Number : " << accnum << endl;
                cout << "First Name : " << fname << endl;
                cout << "Last Name : " << lname << endl;
                cout << "Balance : " << bal << endl;
                cout << "\n";
            }
        }
        cout << "\n";
        ptr.close();
    }
    void showNewAccountDetails()
    {
        cout << endl
             << endl
             << "Congratulations! Your Account has been created" << endl;
        cout << "Account Number : " << AccountNumber - 1 << endl;
        cout << "First Name : " << fname << endl;
        cout << "Last Name : " << lname << endl;
        cout << "Initial Account Balance : " << AccountBalance << endl
             << endl;
    }
};
int Bank ::AccountNumber = accNum();

class Account
{
private:
    int AccNum;
    float balance;
    string fname;
    string lname;

public:
    Account()
    {
        AccNum = 0;
        balance = 0.0f;
        fname = "";
        lname = "";
    }
    void EnquireBalance()
    {
        int a;
        cout << "Enter your Account Number : ";
        cin >> a;
        cout << "\n";
        ifstream ptr;
        ptr.open("Accounts.txt");
        if (!ptr)
        {
            cout << "No Accounts Found in the Database" << endl;
        }
        else
        {
            int flag = 0;
            while (!ptr.eof())
            {
                ptr >> AccNum >> fname >> lname >> balance;
                if (AccNum == a)
                {
                    flag = 1;
                    cout << "Your Account Details Are" << endl
                         << endl;
                    cout << "Account Number : " << AccNum << endl;
                    cout << "First Name : " << fname << endl;
                    cout << "Last Name : " << lname << endl;
                    cout << "Account Balance : " << balance << endl
                         << endl;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "Account with the specified Account Number not found" << endl
                     << endl;
            }
        }
        ptr.close();
    }
    void DepositMoney()
    {
        int a;
        float amt;
        cout << "Enter your Account Number : ";
        cin >> a;
        cout << "Enter the amount to be deposited : ";
        cin >> amt;
        ifstream ptr;
        ptr.open("Accounts.txt");
        ofstream ptr1("AccountsMoneyDeposit.txt");
        ptr1.close();
        ofstream ptr_out("AccountsMoneyDeposit.txt");
        if (!ptr)
        {
            cout << "No Accounts Found in the Database" << endl;
        }
        else
        {
            int flag = 0;
            while (!ptr.eof())
            {
                ptr >> AccNum >> fname >> lname >> balance;
                if (AccNum == a)
                {
                    flag = 1;
                    balance = balance + amt;
                    cout << "Money Deposited Successfully" << endl
                         << endl;
                    cout << "The current Account Details are" << endl;
                    cout << "Account Number : " << AccNum << endl;
                    cout << "First Name : " << fname << endl;
                    cout << "Last Name : " << lname << endl;
                    cout << "Account Balance : " << balance << endl
                         << endl;
                }
                if (AccNum == 1)
                {
                    ptr_out << AccNum << "\t" << fname << "\t" << lname << "\t" << balance;
                }
                else
                {
                    ptr_out << endl
                            << AccNum << "\t" << fname << "\t" << lname << "\t" << balance;
                }
            }
            ptr.close();
            ptr_out.close();
            if (flag == 0)
            {
                cout << "Account with the specified Account Number not found" << endl
                     << endl;
            }
            else
            {
                ifstream ptr;
                ptr.open("AccountsMoneyDeposit.txt");
                ofstream ptr2("Accounts.txt");
                ptr2.close();
                ofstream ptr_in("Accounts.txt", ios::app);
                while (!ptr.eof())
                {
                    ptr >> AccNum >> fname >> lname >> balance;
                    if (AccNum == 1)
                    {
                        ptr_in << AccNum << "\t" << fname << "\t" << lname << "\t" << balance;
                    }
                    else
                    {
                        ptr_in << endl
                               << AccNum << "\t" << fname << "\t" << lname << "\t" << balance;
                    }
                }
                ptr.close();
                ptr_in.close();
            }
        }
    }
    void WithdrawMoney()
    {
        int a;
        float amt;
        cout << "Enter your Account Number : ";
        cin >> a;
        cout << "Enter the amount to be withdrawn : ";
        cin >> amt;
        ifstream ptr;
        ptr.open("Accounts.txt");
        ofstream ptr1("AccountsMoneyWithdrawal.txt");
        ptr1.close();
        ofstream ptr_out("AccountsMoneyWithdrawal.txt");
        if (!ptr)
        {
            cout << "No Accounts Found in the Database" << endl;
        }
        else
        {
            int flag = 0;
            while (!ptr.eof())
            {
                ptr >> AccNum >> fname >> lname >> balance;
                if (AccNum == a)
                {
                    flag = 1;
                    if (balance >= amt)
                    {
                        balance = balance - amt;
                        cout << "Money Withdrawn Successfully" << endl
                             << endl;
                    }
                    else
                    {
                        cout << "Your Account has insufficient funds" << endl
                             << endl;
                    }
                    cout << "The current Account Details are" << endl;
                    cout << "Account Number : " << AccNum << endl;
                    cout << "First Name : " << fname << endl;
                    cout << "Last Name : " << lname << endl;
                    cout << "Account Balance : " << balance << endl
                         << endl;
                }
                if (AccNum == 1)
                {
                    ptr_out << AccNum << "\t" << fname << "\t" << lname << "\t" << balance;
                }
                else
                {
                    ptr_out << endl
                            << AccNum << "\t" << fname << "\t" << lname << "\t" << balance;
                }
            }
            ptr.close();
            ptr_out.close();
            if (flag == 0)
            {
                cout << "Account with the specified Account Number not found" << endl
                     << endl;
            }
            else
            {
                ifstream ptr;
                ptr.open("AccountsMoneyWithdrawal.txt");
                ofstream ptr2("Accounts.txt");
                ptr2.close();
                ofstream ptr_in("Accounts.txt", ios::app);
                while (!ptr.eof())
                {
                    ptr >> AccNum >> fname >> lname >> balance;
                    if (AccNum == 1)
                    {
                        ptr_in << AccNum << "\t" << fname << "\t" << lname << "\t" << balance;
                    }
                    else
                    {
                        ptr_in << endl
                               << AccNum << "\t" << fname << "\t" << lname << "\t" << balance;
                    }
                }
                ptr.close();
                ptr_in.close();
            }
        }
    }
    void DeleteAccount()
    {
        int a;
        cout << "Enter the Account Number you want to close : ";
        cin >> a;
        cout << "\n";
        ifstream ptr;
        ptr.open("Accounts.txt");
        ofstream ptr1("AccountsDeletion.txt");
        ptr1.close();
        ofstream ptr_out("AccountsDeletion.txt");
        if (!ptr)
        {
            cout << "No Accounts Found in the Database" << endl;
        }
        else
        {
            int flag = 0;
            while (!ptr.eof())
            {
                ptr >> AccNum >> fname >> lname >> balance;
                if (AccNum == a)
                {
                    flag = 1;
                    cout << "Your Account has been deleted" << endl
                         << endl;
                    cout << "The current Account Details are" << endl;
                    cout << "Account Number : " << AccNum << endl;
                    cout << "First Name : " << fname << endl;
                    cout << "Last Name : " << lname << endl;
                    cout << "Account Balance : " << balance << endl
                         << endl;
                    cout << "Money will be given in out Accounts Office! Thank you for doing business with us." << endl
                         << endl;
                }
                else
                {
                    if (AccNum == 1)
                    {
                        ptr_out << AccNum << "\t" << fname << "\t" << lname << "\t" << balance;
                    }
                    else
                    {
                        ptr_out << endl
                                << AccNum << "\t" << fname << "\t" << lname << "\t" << balance;
                    }
                }
            }
            ptr.close();
            ptr_out.close();
            if (flag == 0)
            {
                cout << "Account with the specified Account Number not found" << endl
                     << endl;
            }
            else
            {
                ifstream ptr;
                ptr.open("AccountsDeletion.txt");
                ofstream ptr2("Accounts.txt");
                ptr2.close();
                ofstream ptr_in("Accounts.txt", ios::app);
                while (!ptr.eof())
                {
                    ptr >> AccNum >> fname >> lname >> balance;
                    if (AccNum == 1)
                    {
                        ptr_in << AccNum << "\t" << fname << "\t" << lname << "\t" << balance;
                    }
                    else
                    {
                        ptr_in << endl
                               << AccNum << "\t" << fname << "\t" << lname << "\t" << balance;
                    }
                }
                ptr.close();
                ptr_in.close();
            }
        }
    }
};

int main()
{
    int flag = 0;
    while (flag == 0)
    {
        int choice;
        cout << "\tSelect an Option from below:" << endl;
        cout << "\t1. Open an Account" << endl;
        cout << "\t2. Balance Enquiry" << endl;
        cout << "\t3. Deposit Money to your Account" << endl;
        cout << "\t4. Withdraw Money from your Account" << endl;
        cout << "\t5. Close an Account" << endl;
        cout << "\t6. Show all Accounts" << endl;
        cout << "\t7. Quit" << endl;
        cout << "Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Bank b;
            b.AddAccount();
            b.showNewAccountDetails();
            break;
        }
        case 2:
        {
            Account acc;
            acc.EnquireBalance();
            break;
        }
        case 3:
        {
            Account acc;
            acc.DepositMoney();
            break;
        }
        case 4:
        {
            Account acc;
            acc.WithdrawMoney();
            break;
        }
        case 5:
        {
            Account acc;
            acc.DeleteAccount();
            break;
        }
        case 6:
        {
            Bank b;
            b.showAllAccounts();
            break;
        }
        case 7:
        {
            flag = 1;
            break;
        }
        default:
        {
            cout << "Wrong Choice. Please Enter a Correct Choice" << endl;
        }
        }
    }
    return 0;
}