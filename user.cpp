#include "user.h"
#include <iostream>
#include <QObject>
using namespace std;



User::User(void){
}
User::~User(void){

}
User::User(QString UserName_,QString UserSurname_,int serialNo_,QString ssn_){
    UserName=UserName_;
    UserSurname=UserSurname_;
    serialNo = serialNo_;
    ssn = ssn_;
}
User::User(const User& person){
    UserName = person.UserName;
    UserSurname = person.UserSurname;
}

QString User::getUserName(){
    return UserName;
}
QString User::getUserSurname(){
    return UserSurname;
}
int User::getserialNo(){

    return serialNo;
}
QString User::Depositor::getssn(){
    return ssn;
}
