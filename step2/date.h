//
// Created by 郭岩 on 25-5-14.
//
//实现计算出两个日期之间的差值
#ifndef DATE_H
#define DATE_H

#endif //DATE_H
using namespace std;
class Date {
private:
    int year;
    int month;
    int day;
    int totalDays;//一共多少天
public:
    Date(int year,int month,int day);
    int getYear() {return year;}
    int getMonth() {return month;}
    int getDay() {return day;}
    int getMaxDay();//获得当月有多少天
    bool isLeapYear() {
        return year%4==0&&year%100!=0||year%400==0;
    }//是否为闰年
    void show();
    int distance(Date date) {
        return totalDays-date.totalDays;
    }
};