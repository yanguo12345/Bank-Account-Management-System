//
// Created by 郭岩 on 25-4-5.
//
#include <string>
#include "date.h"
using namespace std;


#ifndef ACCOUNT_H
#define ACCOUNT_H

#endif //ACCOUNT_H
class SavingsAccount {
private:
    string id;
    double balance;//余额
    double rate;
    Date lastDate;
    double accumulation;//余额按日累加之和
    static double total;

    void record(Date date, double amount,const string desc);
    double accumulate(Date date) const {
        return accumulation + balance * date.distance(lastDate);
    }

public:
    //构造
    SavingsAccount(Date date,string id,double rate);
    //返回值

    std::string getId(){return id;}
    double getBalance()const{return balance;}
    double getRate()const{return rate;}
    static double getTotal() {return total;}
    //功能函数

    void show()const;

    //存入现金
    void deposit(Date date, double amount, const string desc);
    //取出现金
    void withdraw(Date date, double amount, const string desc);
    //结算利息，每年1月1日调用一次该函数
    void settle(Date date);





};
