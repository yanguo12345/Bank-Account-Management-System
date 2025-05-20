//
// Created by 郭岩 on 25-5-19.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H

#endif //ACCOUNT_H
using namespace std;
#include "date.h"
#include "accumulator.h"
#include<string>
class Account {
private:
    string id;
    double balance;
    static double total;
protected:

    Account(Date date, string id);


    void record(Date date,double amount,string desc);



    void error(string msg);
public:
    const string getId(){return id;}
    double getBalance(){return balance;}
    void show()const;
    static double getTotal(){return total;}
};

class SavingsAccount:public Account {
private:
    Accumulator acc;
    double rate;
public:
    SavingsAccount(Date date,string id,double rate);
    double getRate(){return rate;}
    void deposit(Date date,double amount,string desc);
    void withdraw(Date date,double amount,string desc);
    void settle(Date date);
};

class CreditAccount :public Account{
private:
private:
    Accumulator acc;	//辅助计算利息的累加器
    double credit;		//信用额度
    double rate;		//欠款的日利率
    double fee;			//信用卡年费

    double getDebt()  {	//获得欠款额
        double balance = getBalance();
        return (balance < 0 ? balance : 0);
    }
public:
    //构造函数
    CreditAccount( Date date, string id, double credit, double rate, double fee);
    double getCredit()  { return credit; }
    double getRate()  { return rate; }
    double getFee() { return fee; }
    double getAvailableCredit()  {	//获得可用信用
        if (getBalance() < 0)
            return credit + getBalance();
        else
            return credit;
    }
    //存入现金
    void deposit( Date date, double amount, string desc);
    //取出现金
    void withdraw( Date date, double amount,string desc);
    //结算利息和年费，每月1日调用一次该函数
    void settle(Date date);

    void show() ;



};