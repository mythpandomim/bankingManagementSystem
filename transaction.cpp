#include "transaction.h"

Transaction::Transaction(){

}

Transaction::~Transaction(){

}

Transaction::Transaction(QString transactionType_,double amount_){
    transactionType = transactionType_;
    amount = amount_;
}

Transaction::Transaction(string transactionType_)
{
    transactionType = QString::fromStdString(transactionType_);
    amount = 0.00;
}

Transaction::Transaction(const Transaction& transaction){
   transactionType = transaction.transactionType;
   amount = transaction.amount;
}

QString Transaction::getTransactionType(){
    return transactionType;

}

double Transaction::getamount(){
    return amount;
}

