//
// Created by xlc on 2018/7/12.
//

#ifndef DATA_STDUCTURE_TOURISTVIEW_H
#define DATA_STDUCTURE_TOURISTVIEW_H

#include <bits/stdc++.h>

using namespace std;

class touristView{
public:
    void showMenu(){
        system("cls");
        cout << "================================" << endl;
        cout << "    欢迎使用景区信息管理系统    " << endl;
        cout << "        ***请选择菜单***        " << endl;
        cout << "================================" << endl;
        cout << "1.查看景区景点分布图" << endl;
        cout << "2.查找景点" << endl;
        cout << "3.景点排序" << endl;
        cout << "4.输出导游线路图" << endl;
        cout << "5.查看两个景点间的最短路径与距离" << endl;
        cout << "6.停车场车辆管理" << endl;
        cout << "0.回到上级" << endl;
    }

    void showSort(){
        system("cls");
        cout << "请输入数字以进行对应排序：" << endl;
        cout << "1.按景点受欢迎度进行排序" << endl;
        cout << "2.按景点有无休息区进行排序" << endl;
        cout << "3.按景点有无公厕进行排序" << endl;
    }

    void showPark(){
        system("cls");
        cout << "================================" << endl;
        cout << "    欢迎使用景区车辆管理系统    " << endl;
        cout << "        ***请选择菜单***        " << endl;
        cout << "1.停车     2.取车     0.回到上级" << endl;
        cout << "================================" << endl;
    }
};

#endif //DATA_STDUCTURE_TOURISTVIEW_H
