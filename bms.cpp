#include "bms.h"
#include <QString>
Bank::Bank(void){
   accountsNumber = 0;
}
Bank::~Bank(void){

}
int Bank::getAccountsNumber(){
    return accountsNumber;
}
bool Bank::openAccount(QString UserName_, QString UserSurname_, int serialNo_, QString ssn_, int accountNumber_, QString accountType_, double balance_){
    if(addAccount(UserName_,UserSurname_,serialNo_,ssn_,accountNumber_,accountType_,balance_,1)){
        int current = findAccount(accountNumber_);
        if(current>=0){
            accounts[current]->open();

        }
        return true;

    }
    return false;
}

bool Bank::addAccount(QString UserName_, QString UserSurname_, int serialNo_, QString ssn_, int accountNumber_, QString accountType_, double balance_, int status_){
    if(accountNumber_<MAX_NUM-1 && findAccount(accountNumber_)==-1){
        User person(UserName_,UserSurname_,serialNo_,ssn_);
        accounts[accountsNumber] = new Account(person,balance_,accountNumber_,accountType_,status_);
        accountsNumber++;
        return true;
    }
    return false;
}

int Bank::findAccount(int accountNumber_){
    for(int i=0;i<<accountsNumber;i++){
        if(accounts[i]->getAccountNumber()==accountNumber_)
            return i;

    }
    return -1;
}

int Bank::findAccountSSN(QString ssn_)
{
    for (int i = 0; i<accountsNumber; i++)
    {
        if (accounts[i]->getPerson().getssn()==ssn_)
            return i;
    }
    return -1;
}

Account* Bank::getAccount(int current){
    return accounts[current];
}


bool Bank::deleteAccount(int current){
    if(current>=0 && current<accountsNumber){
        for (int i = current; i<accountsNumber; i++)
                 accounts[i] = accounts[i + 1];

             accountsNumber--;
             return true;
    }
    else {
        return false;
    }
}
