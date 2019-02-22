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
// 无穷大
#define INF 32767

using namespace std;
typedef int ll;

map<string, int> sites;                  //景点名称-编号的映射
map<int, string> number;                 //编号-景点名称的映射
vector<bool> banned;                    //景点是否被删除
vector<bool> bannedRoad;                //路径是否被删除
//结点信息
int cnt = 0;                              //边的数量
int cnt_site = 0;                         //景点数量
vector<int> head;                       //用于记录结点的下一个next值
vector<build> edge;                     //用于存储边
vector<Intro> attractionIntroduction;   //景点介绍

class dsutilController{
public:
/*
点和边的增加
*/
    //增加景点
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

//增加路径
    void add_edge(build tmp, vector<string> vec, dataProcessController &dataProcessController1) {   //向系统中加入两条有向边
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

    void add_edge(build tmp) {   //向系统中加入两条有向边
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
        cout << "序号  景点名称 景点描述 受欢迎度 休息区 公厕" << endl;
        for (int i = 0; i < tmp.size(); ++i) {
            cout << i + 1 << ' ' << tmp[i].name << ' ' << tmp[i].brief << ' ' << tmp[i].popularity << ' '
                 << (tmp[i].rest == 1 ? "有" : "无") << ' ' << (tmp[i].toilet == 1 ? "有" : "无") << endl;
        }
    }
};

#endif // DSUTIL_H_INCLUDED
