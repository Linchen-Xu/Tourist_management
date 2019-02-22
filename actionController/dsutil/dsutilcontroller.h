#ifndef DSUTIL_H_INCLUDED
#define DSUTIL_H_INCLUDED

#include <bits/stdc++.h>
#include <windows.h>
#include "../data/dataprocesscontroller.h"
#include "../notice/noticecontroller.h"
#include "dsutilmodel.h"
#define null NULL
#define PI acos(-1)
#define eps 1e-9
#define debug(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
// �����
#define INF 32767

using namespace std;
typedef int ll;

map<string, int> sites;                  //��������-��ŵ�ӳ��
map<int, string> number;                 //���-�������Ƶ�ӳ��
vector<bool> banned;                    //�����Ƿ�ɾ��
vector<bool> bannedRoad;                //·���Ƿ�ɾ��
//�����Ϣ
int cnt = 0;                              //�ߵ�����
int cnt_site = 0;                         //��������
vector<int> head;                       //���ڼ�¼������һ��nextֵ
vector<build> edge;                     //���ڴ洢��
vector<Intro> attractionIntroduction;   //�������

class dsutilController{
public:
/*
��ͱߵ�����
*/
    //���Ӿ���
    void addAttraction(const string &str) {
        Intro tmp1;
        tmp1.name = str;
        attractionIntroduction.push_back(tmp1);
        sites[str] = cnt_site;
        number[cnt_site] = str;
        banned.push_back(false);
        head.push_back(-1);
        ++cnt_site;
    }

    void addAttraction(const Intro &tmp) {
        attractionIntroduction.push_back(tmp);
        sites[tmp.name] = cnt_site;
        number[cnt_site] = tmp.name;
        banned.push_back(false);
        head.push_back(-1);
        ++cnt_site;
    }

//����·��
    void add_edge(build tmp, vector<string> vec, dataProcessController &dataProcessController1) {   //��ϵͳ�м������������
        tmp.from = sites[vec[0]];
        tmp.to = sites[vec[1]];
        tmp.next = head[tmp.from];
        head[tmp.to] = cnt;
        tmp.w = dataProcessController1.stringToInt(vec[2]);
        edge.push_back(tmp);
        bannedRoad.push_back(false);
        ++cnt;
        tmp.from = sites[vec[1]];
        tmp.to = sites[vec[0]];
        tmp.next = head[tmp.from];
        head[tmp.to] = cnt;
        tmp.w = dataProcessController1.stringToInt(vec[2]);
        edge.push_back(tmp);
        bannedRoad.push_back(false);
        ++cnt;
    }

    void add_edge(build tmp) {   //��ϵͳ�м������������
        tmp.next = head[tmp.from];
        head[tmp.to] = cnt;
        edge.push_back(tmp);
        bannedRoad.push_back(false);
        ++cnt;
        int a = tmp.from;
        tmp.from = tmp.to;
        tmp.to = a;
        tmp.next = head[tmp.from];
        head[tmp.to] = cnt;
        edge.push_back(tmp);
        bannedRoad.push_back(false);
        ++cnt;
    }

    void showAttractionInfo(vector<Intro> tmp) {
        cout << "���  �������� �������� �ܻ�ӭ�� ��Ϣ�� ����" << endl;
        for (int i = 0; i < tmp.size(); ++i) {
            cout << i + 1 << ' ' << tmp[i].name << ' ' << tmp[i].brief << ' ' << tmp[i].popularity << ' '
                 << (tmp[i].rest == 1 ? "��" : "��") << ' ' << (tmp[i].toilet == 1 ? "��" : "��") << endl;
        }
    }
};

#endif // DSUTIL_H_INCLUDED
