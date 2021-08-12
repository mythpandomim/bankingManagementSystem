#ifndef BMS_H
#define BMS_H
#include "account.h"
#include <iostream>
#include <QString>
using namespace std;

#define MAX_NUM 100

class Bank{
    Account* accounts[MAX_NUM];
    int accountsNumber;

public:
    Bank(void);
    ~Bank(void);
    bool openAccount(QString UserName_,QString UserSurname_, int serialNo_, QString ssn_,int accountNumber_, QString accountType_, double balance_);
    bool addAccount(QString UserName_,QString UserSurname_, int serialNo_, QString ssn_,int accountNumber_, QString accountType_, double balance_, int status_);

    int findAccount(int accountNumber_);
    int findAccountSSN(QString ssn_);
    Account* getAccount(int current);
    bool deleteAccount(int current);

    int getAccountsNumber();

};

#endif // BMS_H
