//
// Created by xlc on 2018/7/11.
//

#ifndef DATA_STDUCTURE_MAIN_H
#define DATA_STDUCTURE_MAIN_H

#include <bits/stdc++.h>
#include <windows.h>
#include "mainview.h"
#include "actionController/dsutil/dsutilcontroller.h"
#include "actionController/data/datareadcontroller.h"
#include "attraction/tourist/touristcontroller.h"
#include "actionController/notice/noticecontroller.h"
#include "attraction/admin/admincontroller.h"
#include "attraction/graphalgocontroller.h"
#define null NULL
#define PI acos(-1)
#define eps 1e-9
#define debug(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
// �����
#define INF 32767

using namespace std;
typedef int ll;


class mainController{
private:
    noticeController noticeController1;
    dataReadController dataReadController1;
    adminController adminController1;
    dataProcessController dataProcessController1;
    dsutilController dsutilController1;
    graphAlgoController graphAlgoController1;
    touristController touristController1;
    mstController mstController1;
    carController carController1;
    carModel carModel1;
    mainView mainView1;

    int login() {
        while (true) {
            mainView1.showMenu();
            int num;
            num = dataProcessController1.getNumberBetween(0, 3);
            if (num == 0) {
                return 0;
            } else if (num == 1) {
                if (adminController1.checkLogin()) {
                    return 1;
                } else {
                    cout << "�˺Ż������������!" << endl;
                }
            } else {
                return num;
            }
            system("pause");
        }
    }
public:
    void run() {
        dataReadController1.readData(noticeController1,dataProcessController1,dsutilController1,carModel1);
        //ϵͳ����
        while (true) {    //0:�˳�ϵͳ;1:����Ա:2:�ο�
            int num = login();
            if (num == 0) {
                cout << "Bye." << endl;
                break;
            }
            switch (num) {
                case 1:
                    adminController1.admin(dataReadController1,noticeController1,dataProcessController1,dsutilController1,carModel1);
                    break;
                case 2:
                    touristController1.tourist(dataProcessController1,dsutilController1,graphAlgoController1,mstController1,carController1);
                    break;
                default:    //num=3
                    noticeController1.readNotice();
                    break;
            }
        }
        dataReadController1.saveData(noticeController1,carModel1);
        dataReadController1.close();
    }
};

#endif //DATA_STDUCTURE_MAIN_H
