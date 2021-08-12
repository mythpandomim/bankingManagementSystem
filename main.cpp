#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <QObject>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include "transaction.h"
#include "bms.h"
using namespace std;
#include "user.h"


void menu()
{

    qDebug()<<"                  -------------HELLO! WELCOME TO C.A.B.-------------"<<endl<<"        Select one of the following:"<<endl;
    qDebug()<<" W - Withdrawal transactions"<<endl;
    qDebug()<<" D - Deposit transactions"<<endl;
    qDebug()<<" N - New Account transactions"<<endl;
    qDebug()<<" B - Balance queries"<<endl;
    qDebug()<<" C - Close Account"<<endl;
    qDebug()<<" R - Reopen Account"<<endl;
    qDebug()<<" X - Delete Account"<<endl;
    qDebug()<<" Q - QUIT"<<endl;

}

void withdrawal(Bank& bank)
{
    int current, req_acc;

    qDebug()<<"Enter the account number: "<<endl;
    cin>>req_acc;

    if(req_acc != 0)
    {
        current = bank.findAccount(req_acc);
        if(current>=0)
        {
            double amount;

            qDebug()<<"Enter amount to withdraw transaction: "<<endl;
            cin>>amount;

            if(amount>0)
            {
                if(bank.getAccount(current)->makeWithDrawal(amount))
                {
                    qDebug()<<"Withdraw is completed..."<<endl;
                }
                else
                {
                    qDebug()<<"Withdraw is not completed..."<<endl;
                }

            }
            else
            {
                qDebug()<<"Invalid amount. You need enter the positive amount "<<endl;
            }

        }
        else
        {
            qDebug()<<"Error.Account number : "<<req_acc<<"is not found in our system"<<endl;
        }

    }
    else
    {
        qDebug()<<"Invalid account number..."<<endl;
    }
}


void deposit(Bank& bank)
{
    int current, req_acc;

    qDebug()<<"Enter the account number : "<<endl;
    cin>>req_acc;

    if(req_acc != 0)
    {
        current = bank.findAccount(req_acc);


        if(current>=0)
        {
            double amount;

            qDebug()<<"Enter amount to deposit transaction : "<<endl;
            cin>>amount;

            if(amount>0)
            {
                bank.getAccount(current)->makeDeposit(amount);
                qDebug()<<"Deposit is completed..."<<endl;
            }
            else
            {
                qDebug()<<"Deposit is not completed..."<<endl;
            }

        }
        else
        {
            qDebug()<<"Error... Account number is : "<<req_acc<<"did'nt find."<<endl;
        }
    }
    else
    {
        qDebug()<<"Error! Invalid account number... "<<endl;
    }

}

void newAcc(Bank& bank)
{
    int current,req_acc;

    qDebug()<<"Enter the account number : ";
    cin>>req_acc;

    if(req_acc != 0)
    {
        current = bank.findAccount(req_acc);
        if(current == -1)
        {
            QTextStream qtin(stdin);
            QString line = qtin.readLine();
            double amount;
            QString userName;
            QString userSurname;
            int serialNo;
            QString ssn;
            QString accountType;

            qDebug()<<"Please enter your name : ";
            qtin>>userName;
            qDebug()<<"Please enter your surname : ";
            qtin>>userSurname;
            qDebug()<<"Enter your serial number : ";
            cin>>serialNo;
//            do
//            {


//                if(std::to_string(serialNo).length()>=12)
//                {
//                    break;
//                }
//                else
//                {
//                    qDebug()<<"Error. Invalid serialNo. You must use 11 digits of number... Please try again."<<endl;
//                }

//            } while(true);

            do
            {
                qDebug()<<"Enter your social security number : ";
                qtin>>ssn;


                if(ssn.length()==9)
                {
                    break;
                }
                else
                {
                    qDebug()<<"Error... Invalid social security number... Try again please."<<endl;
                }

            } while(true);


            do
            {
                qDebug()<<"Enter account type = C: Checking     S: Saving   D: CD";
                qtin>>accountType;

                if(accountType == "C" || accountType == "S" || accountType == "D")
                {
                    break ;
                }
                else
                {
                    qDebug()<<"Error... Invalid account type..."<<endl;
                }

            }while(true);


            do
            {
                qDebug()<<"Enter amount to deposit : "<<endl;
                cin>>amount;

                if(amount>0)
                {
                    break;
                }
                else
                {
                    qDebug()<<"Invalid amount. Please enter positive amount"<<endl;
                }
            }while(true);

                if(bank.openAccount(userName,userSurname,serialNo,ssn,req_acc,accountType,amount))
                {
                    qDebug()<<"Account is opened..."<<endl;
                }
                else
                {
                    qDebug()<<"Account can not opened."<<endl;
                }
        }
        else
        {
            qDebug()<<"Account can not created."<<req_acc<<"is already exists..."<<endl;
        }

    }
    else
    {
        qDebug()<<"Invalid account number... Please try again."<<endl;
    }
}

void closeAcc(Bank& bank)
{
    int current,req_acc;

    qDebug()<<"Enter your account number : "<<endl;
    cin>>req_acc;

    if(req_acc != 0)
    {
        current = bank.findAccount(req_acc);
        Account* acc = bank.getAccount(current);

        if(current>=0)
        {
            if(!acc->isClosed())
            {
                acc->close();
                qDebug()<<"Account : "<<req_acc<<"has been closed. "<<endl;
            }
            else
            {
                qDebug()<<"This account can not closed..."<<endl;
            }
        }
        else
        {
            qDebug()<<"Account number : "<<req_acc<<"is not found."<<endl;
        }
    }
    else
    {
        qDebug()<<"Invalid account number. Please try again!"<<endl;
    }
}

void reopen_acct(Bank& bank)
{
    int current, req_acc;

    //prompt for account number
    cout << endl << "Enter the account number: ";
    cin >> req_acc;

    // account #0 is not valid
    if (req_acc != 0)
    {
        current = bank.findAccount(req_acc);
        Account* acc = bank.getAccount(current);

        if (current >= 0)
        {
            if (acc->isClosed())
            {
                acc->open();
                cout << "Account number \"" << req_acc << "\" has been reopened. "<< endl;
            } else {
                cout << "Error. Account number \"" << req_acc << "\" is already opened." << endl;
            }
        }
        else {
            cout << "Error. Account number \"" << req_acc << "\" is not found." << endl;
        }
    }
    else {
        cout << "Error. Invalid account number." << endl;
    }
}

void delete_acct(Bank& bank)
{
    int current, req_acc;

    //prompt for account number
    cout << endl << "Enter the account number: ";
    cin >> req_acc;

    // account #0 is not valid
    if (req_acc != 0)
    {
        current = bank.findAccount(req_acc);
        if (current >= 0)
        {
            if (bank.deleteAccount(current))
                cout << "Account is closed." << endl;
            else
                cout << "Error. Cannot close account." << endl;
        }
        else {
            cout << "Error. Account number \"" << req_acc << "\" is not found." << endl;
        }
    }
    else {
        cout << "Error. Invalid account number." << endl;
    }
}

void balance(Bank& bank)
{
    int current, req_acc;


    cout << endl << "Enter the account number: ";
    cin >> req_acc;


if (req_acc != 0)
{
        current = bank.findAccount(req_acc);
        Account* acc = bank.getAccount(current);
        if (current >= 0)
        {
           acc->addTransaction(Transaction("balance"));
           cout<<"Balance is: "<<fixed<<setprecision(2)<<acc->getBalance()<<endl;
        }
        else
        {
            cout << "Error. Account number \"" << req_acc << "\" is not found." << endl;
        }
    }
    else {
        cout << "Error. Invalid account number." << endl;
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Bank bank;
    string choice;
    bool stop = false;


    do
    {
        menu();
        cin>>choice;

        if(choice == "Q" || choice == "q")
        {
            stop = true;
        }

        if(choice == "W" || choice == "w")
        {
            withdrawal(bank);
        }

        if(choice == "D" || choice == "d")
        {
            deposit(bank);
        }

        if(choice == "N" || choice == "n")
        {
            newAcc(bank);
        }

        if(choice == "B" || choice == "b")
        {
            balance(bank);
        }

        if(choice == "C" || choice == "c")
        {
            closeAcc(bank);
        }

        if(choice == "R" || choice == "r")
        {
            reopen_acct(bank);
        }

        if(choice == "X" || choice == "x")
        {
            delete_acct(bank);
        }


    }while(!stop);







    return a.exec();
}
