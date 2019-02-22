//
// Created by xlc on 2018/7/12.
//

#ifndef DATA_STDUCTURE_DSUTILMODEL_H
#define DATA_STDUCTURE_DSUTILMODEL_H

#include <bits/stdc++.h>

using namespace std;

typedef int ll;

struct node{
    int next,to,from;                   //next:下一个结点的位置；to:有向边的终点；from:有向边的起点
    ll w;                               //边权
    bool operator < (const struct node &b){
        return w < b.w;
    }
};
typedef struct node build;

//景点介绍
struct Info{
    string name;           //景点名称
    string brief = "无";     //景点简介
    int popularity = 0;    //景点欢迎度，数值越大越受欢迎
    int rest = 0;          //有无休息区，0代表没有，1代表有
    int toilet = 0;        //有无公厕，0代表没有，1代表有
};
typedef struct Info Intro;

//景点排序函数
bool cmpPopularity(const Intro &a,const Intro &b){
    return a.popularity > b.popularity;
}

bool cmpRest(const Intro &a,const Intro &b){
    return a.rest > b.rest;
}

bool cmpToilet(const Intro &a,const Intro &b){
    return a.toilet > b.toilet;
}
//！--景点排序函数

#endif //DATA_STDUCTURE_DSUTILMODEL_H
