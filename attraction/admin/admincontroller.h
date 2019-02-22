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
// �����
#define INF 32767

using namespace std;
typedef int ll;

class adminController {
private:
    adminView adminView1;
public:
    void parkingRecord(carModel &carModel1) {   //ͣ��������������¼
        system("cls");
//    cout<<"parkingRecord"<<endl;
        cout << "ͣ��������������¼" << endl;
        for (auto x:carModel1.record_of_parking) {
            cout << x << endl;
        }
    }

    void adminAddAttraction(dsutilController &dsutilController1) {
        string str;
        cout << "��������Ҫ��ӵľ������ƣ�";
        cin >> str;
        if (sites.find(str) != sites.end()) {
            cout << "�þ����Ѵ��ڣ�" << endl;
        } else {
            dsutilController1.addAttraction(str);
            cout << "��ӳɹ���" << endl;
        }
    }

    void adminDeleteAttraction(dataReadController &dataReadController1, noticeController &noticeController1,dataProcessController &dataProcessController1,dsutilController &dsutilController1,carModel &carModel1) {
        for (auto x:number) {
            cout << x.first + 1 << ' ' << x.second << endl;
        }
        cout << "��ѡ����Ҫɾ���Ľ�㣺";
        int num;
        cin >> num;
        --num;
        banned[num] = true;
        for (num = head[num]; num + 1; num = edge[num].next) {
            bannedRoad[num] = true;
        }
        cout << "ɾ���ɹ���" << endl;
        dataReadController1.saveData(noticeController1,carModel1);
//        cout<<"test"<<endl;
        dataReadController1.readData(noticeController1,dataProcessController1,dsutilController1,carModel1);
    }

    void adminModifydescription(const int &seq) {
        cout << "�����뾰����������Ҫ�����ո񣩣�" << endl;
        string str;
        cin >> str;
        attractionIntroduction[seq].brief = str;
    }

    void adminModifyProperty(const int &seq,dataProcessController &dataProcessController1) {
        cout << "����������0������񣩻�1�������ǣ��Զ����Խ����޸ģ�" << endl;
        int yes;
        cout << "�����Ƿ��й��ޣ�";
        yes = dataProcessController1.getNumberBetween(0, 1);
        attractionIntroduction[seq].toilet = yes;
        cout << "�����Ƿ�����Ϣ����";
        yes = dataProcessController1.getNumberBetween(0, 1);
        attractionIntroduction[seq].rest = yes;
    }

    void attractionManage(dataReadController &dataReadController1, noticeController &noticeController1,dataProcessController &dataProcessController1,dsutilController &dsutilController1,carModel &carModel1) {//�������
//    cout<<"attractionManage"<<endl;
        int num;
        while (true) {
            adminView1.showAttractionManage();
            num = dataProcessController1.getNumberBetween(0, 4);
            if (num == 0) {
                return;
            }
            if (num == 1) {                                     //��Ӿ���
                adminAddAttraction(dsutilController1);
            } else if (num == 2) {                               //ɾ������
                adminDeleteAttraction(dataReadController1, noticeController1,dataProcessController1,dsutilController1,carModel1);
            } else {
                //���������Ϣ
                cout << "������Ϣ���£�" << endl;
                dsutilController1.showAttractionInfo(attractionIntroduction);
                int seq;
                while (true) {
                    cout << "������Ҫ�޸ĵľ�������:" << endl;
                    seq = dataProcessController1.getNumberBetween(1, (int) attractionIntroduction.size());
                    --seq;
                    break;
                }
                if (num == 3) {                 //�޸ľ�������
                    adminModifydescription(seq);
                } else {                      //�޸ľ�������
                    adminModifyProperty(seq,dataProcessController1);
                }
                cout << "�޸ĳɹ���" << endl;
            }
            system("pause");
        }
    }

    void adminAddRoad(dsutilController &dsutilController1) {
        build tmp;
        string str1, str2;
        cout << "��������㣺";
        cin >> str1;
        cout << "�������յ㣺";
        cin >> str2;
        if (sites.find(str1) == sites.end() || sites.find(str2) == sites.end()) {
            cout << "���㲻���ڣ�" << endl;
            system("pause");
            return;
        }
        tmp.from = sites[str1];
        tmp.to = sites[str2];
        cout << "������·�����ȣ�";
        cin >> tmp.w;
        dsutilController1.add_edge(tmp);
        cout << "��ӳɹ���" << endl;
    }

    void adminDeleteRoad(dataReadController &dataReadController1, noticeController &noticeController1,dataProcessController &dataProcessController1,dsutilController &dsutilController1,carModel &carModel1) {
        cout << "���  ���   �յ�   ·������" << endl;
        for (int i = 0; i < edge.size(); i += 2) {
            cout << i / 2 + 1 << ' ' << number[edge[i].from] << ' ' << number[edge[i].to] << ' ' << edge[i].w << endl;
        }
        cout << "��������Ҫɾ����·����ţ�";
        int num = dataProcessController1.getNumberBetween(1, (int) edge.size() / 2);
        num = num * 2 - 1;
        bannedRoad[num] = true;
        --num;
        bannedRoad[num] = true;
        cout << "·��ɾ���ɹ���" << endl;
        dataReadController1.saveData(noticeController1,carModel1);
        dataReadController1.readData(noticeController1,dataProcessController1,dsutilController1,carModel1);
    }

    void roadManage(dataReadController &dataReadController1, noticeController &noticeController1,dataProcessController &dataProcessController1,dsutilController &dsutilController1,carModel &carModel1) {      //·������
//    cout<<"roadManage"<<endl;
        int num;
        while (true) {
            adminView1.showRoadManage();
            num = dataProcessController1.getNumberBetween(0, 2);
            if (num == 0) {
                return;
            }
            if (num != 1 && num != 2) {
                cout << "�������������������룡" << endl;
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
        cout << "�������˺ţ�";
        cin >> usr;
        cout << "���������룺";
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
                    cout << "лл����ʹ��" << endl;
                    return;
                default:
                    cout << "��������ȷ�ı�ţ�" << endl;
                    break;
            }
            system("pause");
        }
    }
};
#endif // ADMIN_H_INCLUDED
