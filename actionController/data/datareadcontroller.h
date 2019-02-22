#ifndef DATAREAD_H_INCLUDED
#define DATAREAD_H_INCLUDED

#include <bits/stdc++.h>
#include <windows.h>
#include "../dsutil/dsutilcontroller.h"
#include "../../parkingconmanage/car/carcontroller.h"
#include "InterfaceDAO.h"
#define null NULL
#define PI acos(-1)
#define eps 1e-9
#define debug(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
// 无穷大
#define INF 32767

using namespace std;
typedef int ll;

class dataReadController: public InterfaceDAO{
public:
    ifstream in;
    ofstream logger;
    ofstream out;
public:
    ~dataReadController(){};

    void clearData(noticeController &noticeController1,carModel &carModel1){
        cnt=0;
        cnt_site=0;
        carModel1.max_order=0;
        sites.clear();
        number.clear();
        banned.clear();
        bannedRoad.clear();
        head.clear();
        edge.clear();
        attractionIntroduction.clear();
        noticeController1.clear();
        while(!carModel1.parkingSpot.empty()){
            carModel1.parkingSpot.pop();
        }
        while(!carModel1.shortcut.empty()){
            carModel1.shortcut.pop();
        }
        carModel1.record_of_parking.clear();
        carModel1.car_fetched.clear();
    }

    void readData(noticeController &noticeController1,dataProcessController &dataProcessController1,dsutilController &dsutilController1,carModel &carModel1){
        clearData(noticeController1,carModel1);
        //read in data
        string str;
        vector<string>vec;
        logger.open("log.txt");

        //读取景点信息
        in.open("attractions.txt");
        while(in>>str){                         //读取一个景点名称
            Intro tmp;
            tmp.name = str;
            in>>tmp.brief>>tmp.popularity>>tmp.rest>>tmp.toilet;
            dsutilController1.addAttraction(tmp);
//        logger<<cnt_site<<' '<<str<<endl;
        }
        in.close();

        //读取边
        in.open("roads.txt");
        while(in>>str){                         //读取一条边
            build tmp;
            dataProcessController1.Split(vec,str,"——");
            dsutilController1.add_edge(tmp,vec,dataProcessController1);                  //加入两条有向边
        }
        in.close();

        //读取通知
        in.open("notice.txt");
        do{
            getline(in,str);
//        logger<<"notice:"<<str<<endl;
            if(str.length()<1){
                break;
            }
            noticeController1.push_back(str);
        }while(true);
        in.close();

        //获取停车场出入信息
        in.open("record_of_parking.txt");
        do{
            getline(in,str);
            if(str.length()<1){
                break;
            }
            carModel1.record_of_parking.push_back(str);
        }while(true);
        in.close();
//    cout<<"end load"<<endl;
    }

    void saveData(noticeController &noticeController1,carModel &carModel1){
        logger<<endl;
        logger<<"景点数据:"<<endl;
        out.open("attractions.txt");
        //保存景点数据
        for(auto x:attractionIntroduction){
            if(banned[sites[x.name]])
                continue;
            out<<x.name<<' '<<x.brief<<' '<<x.popularity<<' '<<x.rest<<' '<<x.toilet<<endl;
            logger<<x.name<<' '<<x.brief<<' '<<x.popularity<<' '<<x.rest<<' '<<x.toilet<<endl;
        }
        out.close();
        logger<<endl;

        logger<<"路径数据:"<<endl;
        //保存路径数据
        out.open("roads.txt");
        for(int i=0,j=edge.size();i<j;i+=2){
            if(bannedRoad[i]||banned[edge[i].from]||banned[edge[i].to])
                continue;
            //路径与景点都未被删除，则将该路写入文件
            out<<number[edge[i].from]<<"——"<<number[edge[i].to]<<"——"<<edge[i].w<<endl;
            logger<<number[edge[i].from]<<"——"<<number[edge[i].to]<<"——"<<edge[i].w<<endl;

        }
        out.close();
        logger<<endl;

        logger<<"通知内容:"<<endl;
        //保存通知
        out.open("notice.txt");
        for(auto x:noticeController1.getNotices()){
            out<<x<<endl;
            logger<<x<<endl;
        }
        out.close();

        logger<<"停车场信息:"<<endl;
        out.open("record_of_parking.txt");
        for(auto x:carModel1.record_of_parking){
            out<<x<<endl;
            logger<<x<<endl;
        }
        out.close();
        logger<<endl;
//    cout<<"done"<<endl;
//    cout<<"end save"<<endl;
    }

    void close(){
        logger.close();
    }
};

#endif // DATAREAD_H_INCLUDED
