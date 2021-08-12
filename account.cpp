#include "account.h"
#include "transaction.h"
#include "user.h"
#include <QObject>
#include <iostream>
#include <QString>
using namespace std;


Account::Account(void){
    transactionCount=0;
    total = 101;
    transactions = new Transaction[total];
}
Account::~Account(void){
    delete[] transactions;
}
Account::Account(const User& person_,double balance_, int accountNumber_,QString accountType_,int status_){
    depositor_ = person_;
    balance = balance_;
    accountNumber = accountNumber_;
    accountType = accountType_;
    status = status_;
    transactionCount=0;
    total = 101;
    transactions = new Transaction[total];
}
Account::Account(const Account& account){
    depositor_ = account.depositor_;
    balance = account.balance;
    accountNumber = account.accountNumber;
    accountType = account.accountType;
    status = account.status;

    total = account.total;
    transactionCount = account.transactionCount;

    transactions = new Transaction[total];

    for(int j = 0; j<transactionCount;j++){

        transactions[j]=account.transactions[j];
    }
}

void Account::addTransaction(Transaction transaction)
{
    if (transactionCount>=total-1)
    {
        total = total * 2;
        Transaction* newTransaction = new Transaction[total];
        for(int i=0; i<transactionCount; i++)
            newTransaction[i] = transactions[i];

        delete[] transactions;
        transactions = newTransaction;
    }
    transactions[transactionCount] = transaction;
    transactionCount++;
}

int Account::getTransactionCount(){
    return transactionCount;
}

Transaction Account::getTransaction(int current){
    return transactions[current];
}
double Account::getBalance(){
    return balance;
}

User::Depositor Account::getPerson(){
    return depositor_;
}

int Account::getAccountNumber(){
    return accountNumber;
}

QString Account::getAccountType(){
    return accountType;
}

void Account::makeDeposit(double amount_)
{
    Transaction* test = new Transaction("deposit",amount_);

     addTransaction(*test);
     balance+=amount_;
}
bool Account::makeWithDrawal(double amount_){
    Transaction* test = new Transaction("makedraw",amount_);
    if(amount_>balance){
        return false;
    }
    else{
        addTransaction(*test);
        balance-=amount_;
        return true;
    }

}

void Account::open(){
    Transaction* test = new Transaction("open", 0.0);
    addTransaction(*test);
    status = 1;
}

void Account::close(){
    Transaction* test = new Transaction("close",0.0);
    addTransaction(*test);
    status = 0;

}

bool Account::isClosed(){
    return status == 0;
}
