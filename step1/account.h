//
// Created by 郭岩 on 25-4-5.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H

#endif //ACCOUNT_H

class SavingsAccount {
private:
    int id;
    double balance;//余额
    double rate;
    int lastDate;
    double accumulation;//余额按日累加之和
    void record(int date,double amount);
    double accumulate(int date) const {
        return accumulation + balance * (date - lastDate);
    }

public:
    //构造
    SavingsAccount(int date,int id,double rate);
    //返回值

    int getId(){return id;}
    double getBalance()const{return balance;}
    double getRate()const{return rate;}
    //功能函数

    void show()const;


    //存入现金
    void deposit(int date, double amount);
    //取出现金
    void withdraw(int date, double amount);
    //结算利息，每年1月1日调用一次该函数
    void settle(int date);





};
