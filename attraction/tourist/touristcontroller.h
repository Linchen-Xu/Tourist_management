#ifndef TOURIST_H_INCLUDED
#define TOURIST_H_INCLUDED

#include <bits/stdc++.h>
#include <windows.h>
#include "../../actionController/dsutil/dsutilcontroller.h"
#include "../graphalgocontroller.h"
#include "../../parkingconmanage/car/carcontroller.h"
#include "../mst/mstcontroller.h"
#include "touristview.h"
#define null NULL
#define PI acos(-1)
#define eps 1e-9
#define debug(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
// 无穷大
#define INF 32767

using namespace std;
typedef int ll;

class touristController{
private:
    touristView touristView1;
public:
    void generateGraph(){   //查看景区景点分布图
        system("cls");
//    cout<<"generateGraph"<<endl;
        map<string, int> attractions;
        int maxlen = 6;                                             //数字最长为5位。考虑到空格，故将最小长度设为6
        int numberOfAttractions = 0;                                //可访问的景点数
        for(auto x:number){
            if (banned[x.first])
                continue;
            attractions[x.second] = numberOfAttractions++;
            maxlen = max(maxlen, (int) x.second.length());
        }
        numberOfAttractions = 0;
        for (auto &x:attractions) {
            x.second = numberOfAttractions++;
        }
        vector<vector<int> > attractionMap(numberOfAttractions);                    //建立景点分布图
        for (auto &x:attractionMap) {
            x.resize(numberOfAttractions);
        }
        for (int i = 0; i < attractionMap.size(); ++i) {
            for (int j = 0; j < attractionMap.size(); ++j) {
                attractionMap[i][j] = INF;
            }
            attractionMap[i][i] = 0;
        }
        map<string, int>::iterator iter;
        for (iter = attractions.begin(); iter != attractions.end(); ++iter) {
            if (banned[sites[iter->first]])                                          //跳过删除的景点
                continue;
            for (int i = head[sites[iter->first]]; i + 1; i = edge[i].next) {
                if (bannedRoad[i])                                                   //跳过删除的路径
                    continue;
                attractionMap[attractions[number[edge[i].from]]][attractions[number[edge[i].to]]] = edge[i].w;
                attractionMap[attractions[number[edge[i].to]]][attractions[number[edge[i].from]]] = edge[i].w;
            }
        }
        cout << "       ";
        for (iter = attractions.begin(); iter != attractions.end(); ++iter) {
            cout << iter->first << " ";
            int len = iter->first.length();
            while (len < maxlen) {
                cout << " ";
                ++len;
            }
        }
        cout << endl;
        iter = attractions.begin();
        for (int i = 0; i < attractionMap.size(); ++i) {
            cout << iter->first << " ";
            int len = iter->first.length();
            while (len < maxlen) {
                cout << " ";
                ++len;
            }
            for (int j = 0; j < attractionMap.size(); ++j) {
                printf("%-5d  ", attractionMap[i][j]);
                int interval = maxlen - 6;
                while (interval > 0) {
                    interval--;
                    cout << " ";
                }
            }
            cout << endl;
            ++iter;
        }
    }

    void findAttraction(){  //查找景点
//    cout<<"findAttraction"<<endl;
        system("cls");
        string str;
        cout << "请输入想要查找的关键词，中间不要有空格：";
        cin >> str;
        cout << "查询结果如下：" << endl;
        for(auto x:sites){
            if (x.first.find(str) != string::npos) {
                cout << x.first << endl;
            }
        }
    }

    void sortAttraction(dataProcessController &dataProcessController1, dsutilController &dsutilController1){  //景点排序
        touristView1.showSort();
//    cout<<"sortAttraction"<<endl;
        int num;
        num = dataProcessController1.getNumberBetween(1, 3);
        vector<Intro> tmp;
        for (auto x:attractionIntroduction) {
            tmp.push_back(x);
        }
        switch (num) {
            case 1:
                sort(tmp.begin(), tmp.end(), cmpPopularity);
                break;
            case 2:
                sort(tmp.begin(), tmp.end(), cmpRest);
                break;
            default:
                sort(tmp.begin(), tmp.end(), cmpToilet);
                break;
        }
        dsutilController1.showAttractionInfo(tmp);
    }

    void tourGraph(mstController &mstController1) {       //输出导游线路图
        system("cls");
//    cout<<"tourGraph"<<endl;
        int num = 0;
//    cout<<"请输入起点：";
//    string str;cin>>str;
//    if(sites.find(str) == sites.end()){
//        cout<<"景点名输入错误！"<<endl;
//    }
//    num = sites[str];
//    num = 0;
        mstController1.generateTourGraph(num, cnt_site);
    }

    void minDistance(graphAlgoController &graphAlgoController1,dataProcessController &dataProcessController1) {     //查看两个景点间的最短路径与距离
//    cout<<"minDistance"<<endl;
        string str1, str2;
        while (true) {
            system("cls");
            cout << "请分别输入两个景点的名称，中间以空格分开：";
            cin >> str1 >> str2;
            if (sites.find(str1) == sites.end() || sites.find(str2) == sites.end() || banned[sites[str1]] ||
                banned[sites[str2]]) {
                //景点不存在
                cout << "景点名输入错误，请重新输入！" << endl;
                system("pause");
            } else {
                break;
            }
        }
        int start = sites[str1], destination = sites[str2];
        attractionIntroduction[start].popularity++;
        attractionIntroduction[destination].popularity++;
//    cout<<attractionIntroduction[start].name<<' '<<attractionIntroduction[destination].name<<endl;
        cout<<"请决定用来搜索最短路径的算法（1为迪杰斯特拉算法，0为弗洛伊德算法）：";
        int type;
        type = dataProcessController1.getNumberBetween(0,1);
        int dis;
        if (type) {
            stack<int> route;
            dis = graphAlgoController1.dij(start, cnt_site, destination, route);    //使用迪杰斯特拉算法求最短路
            cout << "路径为：" << number[start];
            while (!route.empty()) {
                cout << "---" << number[route.top()];
                route.pop();
            }
            cout << endl << "最短距离为 " << dis << endl;
        } else {
            vector<vector<int> > path;
            dis = graphAlgoController1.floyd(start, cnt_site, destination, path);  //使用弗洛伊德算法求最短路
            cout << "路径为：" << number[start];
            graphAlgoController1.printPath(start, destination, path);
            cout << "---" << number[destination];
            cout << endl << "最短距离为 " << dis << endl;
        }
    }

    void parking(dataProcessController &dataProcessController1,carController &carController1) {         //停车场车辆管理
        touristView1.showPark();
//    cout<<"parking"<<endl;
        int num;
        num = dataProcessController1.getNumberBetween(0, 2);
        if (num == 0) {
            return;
        }
        if (num == 1) {
            carController1.parkCar(dataProcessController1);
        } else {
            carController1.getCar(dataProcessController1);
        }
    }

    void tourist(dataProcessController &dataProcessController1, dsutilController &dsutilController1, graphAlgoController &graphAlgoController1,mstController &mstController1,carController &carController1) {
        while (true) {
            touristView1.showMenu();
            int num = dataProcessController1.getNumberBetween(0, 6);
            switch (num) {
                case 1:
                    generateGraph();
                    break;
                case 2:
                    findAttraction();
                    break;
                case 3:
                    sortAttraction(dataProcessController1, dsutilController1);
                    break;
                case 4:
                    tourGraph(mstController1);
                    break;
                case 5:
                    minDistance(graphAlgoController1,dataProcessController1);
                    break;
                case 6:
                    parking(dataProcessController1,carController1);
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

#endif // TOURIST_H_INCLUDED
