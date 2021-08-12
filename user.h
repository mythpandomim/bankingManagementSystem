#ifndef USER_H
#define USER_H

#include <iostream>
#include <QString>
using namespace std;

class Depositor{
public:
    QString ssn;
    QString getssn();
    QString getPerson();
};


class User: public Depositor{
    QString UserName;
    QString UserSurname;
    int serialNo;
public:

    User(void);
    User(QString UserName,QString UserSurname,int serialNo,QString ssn_);
    User(const User& person);
    ~User(void);

    QString getUserName();
    QString getUserSurname();

    int getserialNo();

};

#endif // USER_H
