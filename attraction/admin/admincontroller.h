#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <bits/stdc++.h>
#include <windows.h>
#include "adminview.h"
#include "../../actionController/dsutil/dsutilcontroller.h"
#include "../graphalgocontroller.h"
#define null NULL
#define PI acos(-1)
#define eps 1e-9
#define debug(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
// 无穷大
#define INF 32767

using namespace std;
typedef int ll;

class adminController {
private:
    adminView adminView1;
public:
    void parkingRecord(carModel &carModel1) {   //停车场车辆进出记录
        system("cls");
//    cout<<"parkingRecord"<<endl;
        cout << "停车场车辆进出记录" << endl;
        for (auto x:carModel1.record_of_parking) {
            cout << x << endl;
        }
    }

    void adminAddAttraction(dsutilController &dsutilController1) {
        string str;
        cout << "请输入需要添加的景点名称：";
        cin >> str;
        if (sites.find(str) != sites.end()) {
            cout << "该景点已存在！" << endl;
        } else {
            dsutilController1.addAttraction(str);
            cout << "添加成功！" << endl;
        }
    }

    void adminDeleteAttraction(dataReadController &dataReadController1, noticeController &noticeController1,dataProcessController &dataProcessController1,dsutilController &dsutilController1,carModel &carModel1) {
        for (auto x:number) {
            cout << x.first + 1 << ' ' << x.second << endl;
        }
        cout << "请选择需要删除的结点：";
        int num;
        cin >> num;
        --num;
        banned[num] = true;
        for (num = head[num]; num + 1; num = edge[num].next) {
            bannedRoad[num] = true;
        }
        cout << "删除成功！" << endl;
        dataReadController1.saveData(noticeController1,carModel1);
//        cout<<"test"<<endl;
        dataReadController1.readData(noticeController1,dataProcessController1,dsutilController1,carModel1);
    }

    void adminModifydescription(const int &seq) {
        cout << "请输入景点描述（不要包含空格）：" << endl;
        string str;
        cin >> str;
        attractionIntroduction[seq].brief = str;
    }

    void adminModifyProperty(const int &seq,dataProcessController &dataProcessController1) {
        cout << "请依次输入0（代表否）或1（代表是）以对属性进行修改：" << endl;
        int yes;
        cout << "景点是否有公厕：";
        yes = dataProcessController1.getNumberBetween(0, 1);
        attractionIntroduction[seq].toilet = yes;
        cout << "景点是否有休息区：";
        yes = dataProcessController1.getNumberBetween(0, 1);
        attractionIntroduction[seq].rest = yes;
    }

    void attractionManage(dataReadController &dataReadController1, noticeController &noticeController1,dataProcessController &dataProcessController1,dsutilController &dsutilController1,carModel &carModel1) {//景点管理
//    cout<<"attractionManage"<<endl;
        int num;
        while (true) {
            adminView1.showAttractionManage();
            num = dataProcessController1.getNumberBetween(0, 4);
            if (num == 0) {
                return;
            }
            if (num == 1) {                                     //添加景点
                adminAddAttraction(dsutilController1);
            } else if (num == 2) {                               //删除景点
                adminDeleteAttraction(dataReadController1, noticeController1,dataProcessController1,dsutilController1,carModel1);
            } else {
                //输出景点信息
                cout << "景点信息如下：" << endl;
                dsutilController1.showAttractionInfo(attractionIntroduction);
                int seq;
                while (true) {
                    cout << "请输入要修改的景点的序号:" << endl;
                    seq = dataProcessController1.getNumberBetween(1, (int) attractionIntroduction.size());
                    --seq;
                    break;
                }
                if (num == 3) {                 //修改景点描述
                    adminModifydescription(seq);
                } else {                      //修改景点属性
                    adminModifyProperty(seq,dataProcessController1);
                }
                cout << "修改成功！" << endl;
            }
            system("pause");
        }
    }

    void adminAddRoad(dsutilController &dsutilController1) {
        build tmp;
        string str1, str2;
        cout << "请输入起点：";
        cin >> str1;
        cout << "请输入终点：";
        cin >> str2;
        if (sites.find(str1) == sites.end() || sites.find(str2) == sites.end()) {
            cout << "景点不存在！" << endl;
            system("pause");
            return;
        }
        tmp.from = sites[str1];
        tmp.to = sites[str2];
        cout << "请输入路径长度：";
        cin >> tmp.w;
        dsutilController1.add_edge(tmp);
        cout << "添加成功！" << endl;
    }

    void adminDeleteRoad(dataReadController &dataReadController1, noticeController &noticeController1,dataProcessController &dataProcessController1,dsutilController &dsutilController1,carModel &carModel1) {
        cout << "序号  起点   终点   路径长度" << endl;
        for (int i = 0; i < edge.size(); i += 2) {
            cout << i / 2 + 1 << ' ' << number[edge[i].from] << ' ' << number[edge[i].to] << ' ' << edge[i].w << endl;
        }
        cout << "请输入需要删除的路径编号：";
        int num = dataProcessController1.getNumberBetween(1, (int) edge.size() / 2);
        num = num * 2 - 1;
        bannedRoad[num] = true;
        --num;
        bannedRoad[num] = true;
        cout << "路径删除成功！" << endl;
        dataReadController1.saveData(noticeController1,carModel1);
        dataReadController1.readData(noticeController1,dataProcessController1,dsutilController1,carModel1);
    }

    void roadManage(dataReadController &dataReadController1, noticeController &noticeController1,dataProcessController &dataProcessController1,dsutilController &dsutilController1,carModel &carModel1) {      //路径管理
//    cout<<"roadManage"<<endl;
        int num;
        while (true) {
            adminView1.showRoadManage();
            num = dataProcessController1.getNumberBetween(0, 2);
            if (num == 0) {
                return;
            }
            if (num != 1 && num != 2) {
                cout << "编号输入错误，请重新输入！" << endl;
                system("pause");
                continue;
            }
            if (num == 1) {
                adminAddRoad(dsutilController1);
            } else {
                adminDeleteRoad(dataReadController1, noticeController1,dataProcessController1,dsutilController1,carModel1);
            }
            system("pause");
        }
    }

    bool checkLogin() {
        string usr, passwd;
        cout << "请输入账号：";
        cin >> usr;
        cout << "请输入密码：";
        cin >> passwd;
        if (passwd == usr && usr == "admin") {
            return true;
        } else {
            return false;
        }
    }

    void admin(dataReadController &dataReadController1, noticeController &noticeController1,dataProcessController &dataProcessController1,dsutilController &dsutilController1,carModel &carModel1) {
        while (true) {
            adminView1.showAdminMain();
            int num;
            num = dataProcessController1.getNumberBetween(0, 4);
            switch (num) {
                case 1:
                    parkingRecord(carModel1);
                    break;
                case 2:
                    attractionManage(dataReadController1, noticeController1,dataProcessController1,dsutilController1,carModel1);
                    break;
                case 3:
                    roadManage(dataReadController1, noticeController1,dataProcessController1,dsutilController1,carModel1);
                    break;
                case 4:
                    noticeController1.sendNotice();
                    break;
                case 0:
                    cout << "谢谢您的使用" << endl;
                    return;
                default:
                    cout << "请输入正确的编号！" << endl;
                    break;
            }
            system("pause");
        }
    }
};
#endif // ADMIN_H_INCLUDED
