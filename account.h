#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "transaction.h"
#include "user.h"
#include <iostream>
#include <QObject>
#include <QString>
using namespace std;

class Account{
    User::Depositor depositor_;
    double balance;
    int accountNumber;
    QString accountType;
    int status;

    int total;
    int transactionCount;
    Transaction* transactions;
public:
    Account(void);
    Account(const User& person,double balance_, int accountNumber_,QString accountType_,int status);
    Account(const Account& account);
    ~Account(void);


void addTransaction(Transaction transaction);
int getTransactionCount();
Transaction getTransaction(int current);

void open();
void close();
bool isClosed();

double getBalance();
User::Depositor getPerson();
int getAccountNumber();
QString getAccountType();
void makeDeposit(double amount);
bool makeWithDrawal(double amount);

};

#endif // ACCOUNT_H
