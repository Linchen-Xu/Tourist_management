#ifndef MST_H_INCLUDED
#define MST_H_INCLUDED

#include <bits/stdc++.h>
#include <windows.h>
#include "../../actionController/data/datareadcontroller.h"
#define null NULL
#define PI acos(-1)
#define eps 1e-9
#define debug(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
// 无穷大
#define INF 32767

using namespace std;

vector<int> par;
vector<int> ran;
vector<int> pre;
vector<vector<int> > son;

class PQNode{
public:
    int a,b,w;
    PQNode(int w,int a,int b):w(w),a(a),b(b){}
};

//图的信息
struct E {
    int u;
    int v;
    ll w;
    bool operator < (const E &_) const {
        return w > _.w;
    }
};

class cmp{
public:
    bool operator()(PQNode *a,PQNode *b){
        if(a->w==b->w)
            if(a->a==b->a)
                return a->b >= b->b;
            else
                return a->a >= b->a;
        return a->w >= b->w;
    }
};

class mstController {
public:
    int fnd(int x) {
        if (par[x] == x) return x;
        else return par[x] = fnd(par[x]);
    }

    void unite(int a, int b) {
        a = fnd(a);
        b = fnd(b);
        if (a == b) return;
        if (ran[a] < ran[b]) {
            par[a] = b;
            pre[a] = b;
            son[b].push_back(a);
//        cout<<number[b]<<' '<<number[a]<<endl;
        } else {
            son[a].push_back(b);
            par[b] = a;
            pre[b] = a;
//        cout<<number[a]<<' '<<number[b]<<endl;
            if (ran[a] == ran[b])
                ++ran[a];
        }
    }

    bool same(int x, int y) {
        return fnd(x) == fnd(y);
    }


    void preorder(const int a) {
        cout << number[a];
        for (int i = 0; i < son[a].size(); ++i) {
            if (son[a][i] == -1)
                continue;
            cout << "---";
            preorder(son[a][i]);
        }
    }

    void generateTourGraph(const int &s, const int &n) {
        par.resize(n);
        ran.resize(n);
        son.resize(n);
        pre.resize(n);
        priority_queue<PQNode *, vector<PQNode *>, cmp> q;
        PQNode *tmp;
        int ans;
        //初始化
        for (int i = 0; i < n; ++i) {
            par[i] = pre[i] = i;
            ran[i] = 0;
            son[i].clear();
        }
//    ans=0;
        for (int i = 0; i < edge.size(); ++i) {
            if (bannedRoad[i])
                continue;
            q.push(new PQNode(edge[i].w, edge[i].from, edge[i].to));
        }
        //生成MST
        while (!q.empty()) {
            tmp = q.top();
            q.pop();
            //printf("%d %d %d\n",tmp->a,tmp->b,tmp->w);
            if (!same(tmp->a, tmp->b)) {
                unite(tmp->a, tmp->b);
//            ans+=tmp->w;
            }
        }
//    printf("%d\n",ans);
        //将起点变成树根
        int start = s, _end = fnd(s);
        do {
            int a = pre[start];
            son[start].push_back(a);
            for (auto &x:son[a]) {
                if (x == start) {
                    x = -1;
                }
            }
            start = a;
        } while (start != _end);
        cout << "推荐路线为：" << endl;
        preorder(s);
        cout << endl;
//    cout<<number[s]<<endl;
    }
};
#endif // MST_H_INCLUDED
