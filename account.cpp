//
// Created by 郭岩 on 25-4-5.
//
#include <cmath>
#include <iostream>
using namespace std;
#include "account.h"

SavingsAccount::SavingsAccount(int date,int id,double rate)
:lastDate(date),id(id),rate(rate),balance(0),accumulation(0){

    cout << date << "\t#" << id << " is created" << endl;   //  制表符\t
}
void SavingsAccount::record(int date,double amount) {
    accumulation=accumulate(date);
    lastDate=date;
    amount = floor(amount * 100 + 0.5) / 100;

    balance+=amount;
    cout << date << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}
void SavingsAccount::deposit(int date, double amount) {
    record(date,amount);
}
void SavingsAccount::withdraw(int date, double amount) {
    if (amount > getBalance())
        cout << "Error: not enough money" << endl;
    else
        record(date, -amount);
}

void SavingsAccount::settle(int date) {
    double interest = accumulate(date) * rate / 365;
    if (interest != 0)
        record(date, interest);
    accumulation = 0;
}
void SavingsAccount::show()const {
    cout << "#" << id << "\tBalance: " << balance;
}