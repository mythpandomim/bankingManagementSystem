#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <QObject>
#include <QTime>
#include <QString>
using namespace std;

class Transaction{
    QString transactionType;
    double amount;
public:
    Transaction(void);
    ~Transaction(void);
    Transaction(QString transactionType_,double amount_);
    Transaction(string transactionType_);
    Transaction(const Transaction& transaction);



    QString getTransactionType();
    double getamount();


};
#endif // TRANSACTION_H
