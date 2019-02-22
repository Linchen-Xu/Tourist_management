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
    int max_order = 0;                  //��ÿ�������
    stack<park> parkingSpot;            //ģ��ͣ����
    queue<park> shortcut;               //ģ����
    vector<string> record_of_parking;   //��¼ͣ�������
    vector<bool> car_fetched;           //��¼ȡ�����
    const int fee_per_hour = 10;        //ÿСʱͣ����
};

#endif //DATA_STDUCTURE_CARMODEL_H
