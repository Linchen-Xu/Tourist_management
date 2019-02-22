//
// Created by xlc on 2018/7/12.
//

#ifndef DATA_STDUCTURE_MAINVIEW_H
#define DATA_STDUCTURE_MAINVIEW_H

#include <bits/stdc++.h>

using namespace std;

class mainView{
public:
    void showMenu(){
        system("cls");
        cout << "=========================" << endl;
        cout << "欢迎使用景区信息管理系统" << endl;
        cout << "***    请选择菜单     ***" << endl;
        cout << "=========================" << endl;
        cout << "1.管理员登录" << endl;
        cout << "2.游客登录" << endl;
        cout << "3.阅读通知" << endl;
        cout << "0.退出系统" << endl;
    }
};

#endif //DATA_STDUCTURE_MAINVIEW_H
