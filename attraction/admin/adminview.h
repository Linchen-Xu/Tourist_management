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
        cout << "        ***��ѡ��˵�***        " << endl;
        cout << "  1.��Ӿ���      2.ɾ������    " << endl;
        cout << "  3.�޸ľ�������  4.�޸ľ�������" << endl;
        cout << "  0.�ص��ϼ�                    " << endl;
        cout << "================================" << endl;
    }

    void showAdminMain(){
        system("cls");
        cout << "================================" << endl;
        cout << "    ��ӭʹ�þ�����Ϣ����ϵͳ    " << endl;
        cout << "        ***��ѡ��˵�***        " << endl;
        cout << "================================" << endl;
        cout << "1.ͣ��������������¼" << endl;
        cout << "2.�������" << endl;
        cout << "3.·������" << endl;
        cout << "4.����֪ͨ" << endl;
        cout << "0.�ص��ϼ�" << endl;
        cout << "�������Ӧ�ı�ţ�";
    }

    void showRoadManage(){
        system("cls");
        cout << "================================" << endl;
        cout << "        ***��ѡ��˵�***        " << endl;
        cout << "1.���·�� 2.ɾ����· 0.�ص��ϼ�" << endl;
        cout << "================================" << endl;
    }
};



#endif //DATA_STDUCTURE_ADMINVIEW_H
