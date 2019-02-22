//
// Created by xlc on 2018/7/12.
//

#ifndef DATA_STDUCTURE_ADMINVIEW_H
#define DATA_STDUCTURE_ADMINVIEW_H

#include <bits/stdc++.h>

using namespace std;

class adminView{
public:
    void showAttractionManage(){
        system("cls");
        cout << "================================" << endl;
        cout << "        ***请选择菜单***        " << endl;
        cout << "  1.添加景点      2.删除景点    " << endl;
        cout << "  3.修改景点描述  4.修改景点属性" << endl;
        cout << "  0.回到上级                    " << endl;
        cout << "================================" << endl;
    }

    void showAdminMain(){
        system("cls");
        cout << "================================" << endl;
        cout << "    欢迎使用景区信息管理系统    " << endl;
        cout << "        ***请选择菜单***        " << endl;
        cout << "================================" << endl;
        cout << "1.停车场车辆进出记录" << endl;
        cout << "2.景点管理" << endl;
        cout << "3.路径管理" << endl;
        cout << "4.发布通知" << endl;
        cout << "0.回到上级" << endl;
        cout << "请输入对应的编号：";
    }

    void showRoadManage(){
        system("cls");
        cout << "================================" << endl;
        cout << "        ***请选择菜单***        " << endl;
        cout << "1.添加路径 2.删除道路 0.回到上级" << endl;
        cout << "================================" << endl;
    }
};



#endif //DATA_STDUCTURE_ADMINVIEW_H
