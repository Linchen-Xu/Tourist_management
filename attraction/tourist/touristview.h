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
        cout << "    ��ӭʹ�þ�����Ϣ����ϵͳ    " << endl;
        cout << "        ***��ѡ��˵�***        " << endl;
        cout << "================================" << endl;
        cout << "1.�鿴��������ֲ�ͼ" << endl;
        cout << "2.���Ҿ���" << endl;
        cout << "3.��������" << endl;
        cout << "4.���������·ͼ" << endl;
        cout << "5.�鿴�������������·�������" << endl;
        cout << "6.ͣ������������" << endl;
        cout << "0.�ص��ϼ�" << endl;
    }

    void showSort(){
        system("cls");
        cout << "�����������Խ��ж�Ӧ����" << endl;
        cout << "1.�������ܻ�ӭ�Ƚ�������" << endl;
        cout << "2.������������Ϣ����������" << endl;
        cout << "3.���������޹��޽�������" << endl;
    }

    void showPark(){
        system("cls");
        cout << "================================" << endl;
        cout << "    ��ӭʹ�þ�����������ϵͳ    " << endl;
        cout << "        ***��ѡ��˵�***        " << endl;
        cout << "1.ͣ��     2.ȡ��     0.�ص��ϼ�" << endl;
        cout << "================================" << endl;
    }
};

#endif //DATA_STDUCTURE_TOURISTVIEW_H
