//
// Created by xlc on 2018/7/12.
//

#ifndef DATA_STDUCTURE_CARMODEL_H
#define DATA_STDUCTURE_CARMODEL_H

#include <bits/stdc++.h>

using namespace std;

struct Car{
    string license;
    string arrival;
    int order;
};
typedef struct Car park;

class carModel {
public:
    const int max_parking_car = 1;
    int max_order = 0;                  //给每辆车编号
    stack<park> parkingSpot;            //模拟停车场
    queue<park> shortcut;               //模拟便道
    vector<string> record_of_parking;   //记录停车场情况
    vector<bool> car_fetched;           //记录取车情况
    const int fee_per_hour = 10;        //每小时停车费
};

#endif //DATA_STDUCTURE_CARMODEL_H
