//
// Created by 郭岩 on 25-5-19.
//

#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

#endif //ACCUMULATOR_H
#include "date.h"
class Accumulator {
private:
    Date lastDate;//上次的日期
    double value;//数值当前值
    double sum;//按日累加之和
public:
    Accumulator(Date date,double value):lastDate(date),value(value),sum(0) {

    };
    //date 累加结果
    const double getSum (Date date) {
     return sum+value*date.distance(lastDate);
    }
    void change(Date date,double value){
        sum=getSum(date);
        lastDate=date;
        this->value=value;//用 this->value 能清楚地告诉编译器，我们操作的是当前对象的成员变量 value
        }//变更新的Value
    void reset(Date date,double value) {
        lastDate=date;
        this->value=value;
        sum=0;
    }//初始化

};