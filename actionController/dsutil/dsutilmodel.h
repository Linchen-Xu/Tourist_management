//
// Created by xlc on 2018/7/12.
//

#ifndef DATA_STDUCTURE_DSUTILMODEL_H
#define DATA_STDUCTURE_DSUTILMODEL_H

#include <bits/stdc++.h>

using namespace std;

typedef int ll;

struct node{
    int next,to,from;                   //next:��һ������λ�ã�to:����ߵ��յ㣻from:����ߵ����
    ll w;                               //��Ȩ
    bool operator < (const struct node &b){
        return w < b.w;
    }
};
typedef struct node build;

//�������
struct Info{
    string name;           //��������
    string brief = "��";     //������
    int popularity = 0;    //���㻶ӭ�ȣ���ֵԽ��Խ�ܻ�ӭ
    int rest = 0;          //������Ϣ����0����û�У�1������
    int toilet = 0;        //���޹��ޣ�0����û�У�1������
};
typedef struct Info Intro;

//����������
bool cmpPopularity(const Intro &a,const Intro &b){
    return a.popularity > b.popularity;
}

bool cmpRest(const Intro &a,const Intro &b){
    return a.rest > b.rest;
}

bool cmpToilet(const Intro &a,const Intro &b){
    return a.toilet > b.toilet;
}
//��--����������

#endif //DATA_STDUCTURE_DSUTILMODEL_H
