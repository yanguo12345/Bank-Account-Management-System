
// Created by 郭岩 on 25-4-5.
//
#include <cmath>
#include <iostream>
#include <utility>
using namespace std;
#include "account.h"

double SavingsAccount::total=0;

SavingsAccount::SavingsAccount(Date date,string id,double rate)
:lastDate(date),id(id),rate(rate),balance(0),accumulation(0){

    date.show();
    cout << "\t#" << id << " is created" << endl;   //  制表符\t
}
void SavingsAccount::record(Date date, double amount,const string desc) {
    accumulation=accumulate(date);
    lastDate=date;
    amount = floor(amount * 100 + 0.5) / 100;
    balance+=amount;
    total+=amount;
    date.show();

    cout << "\t#" << id << "\t" << amount << "\t" << balance <<"\t"<<desc<< endl;
}
void SavingsAccount::deposit(Date date, double amount, const string desc) {
    record(date,amount,desc);
}
void SavingsAccount::withdraw(Date date, double amount, const string desc) {
    if (amount > getBalance())
        cout << "Error: not enough money" << endl;
    else
        record(date, -amount,desc);
}

void SavingsAccount::settle(Date date) {
    double interest = accumulate(date) * rate /date.distance(Date(date.getYear()-1,1,1));
    if (interest != 0)
        record(date, interest,"interest");
    accumulation = 0;
}
void SavingsAccount::show()const {
    cout << "#" << id << "\tBalance: " << balance;
}
