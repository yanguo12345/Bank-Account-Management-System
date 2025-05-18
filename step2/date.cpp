//
// Created by 郭岩 on 25-5-14.
//
#include "date.h"
#include <iostream>
#include <cstdlib> //exit函数，该函数的原型声明在cstdlib中
using namespace std;

namespace {	//namespace使下面的定义只在当前文件中有效
    //存储平年中某个月1日之前有多少天，为便于getMaxDay函数的实现，该数组多出一项
    const int DAYS_BEFORE_MONTH[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
}
//在类的外部定义函数要用类名::函数名
Date::Date(int year,int month,int day):year(year),month(month),day(day) {
    int years=year-1;
    totalDays = years * 365 + years / 4 - years / 100 + years / 400
        + DAYS_BEFORE_MONTH[month - 1] + day;
    //这种计算方式通过 容斥原理 避免了重复计数：
    //先包含：计算所有能被 4 整除的年份（可能包含过多）。
    //再排除：减去能被 100 整除的年份（排除错误包含的）。
    //后包含：加上能被 400 整除的年份（补回被错误排除的）。
    //用集合论表示：
    //闰年数量 = |被4整除的年份| - |被100整除的年份| + |被400整除的年份|
    if (isLeapYear() && month > 2) totalDays++;

}
int Date::getMaxDay() {
    if(isLeapYear()&&month==2)
        return 29;
    else
        return DAYS_BEFORE_MONTH[month]-DAYS_BEFORE_MONTH[month-1];
}


void Date::show() {
    cout<<getYear()<<"-"<<getMonth()<<'-'<<getDay();

}
