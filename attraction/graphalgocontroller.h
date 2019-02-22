#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <bits/stdc++.h>
#include <windows.h>
#include "../actionController/dsutil/dsutilcontroller.h"
#define null NULL
#define PI acos(-1)
#define eps 1e-9
#define debug(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
// 无穷大
#define INF 32767

using namespace std;
typedef int ll;

class graphAlgoController{
public:
    int dij(int s, int n, int destination, stack<int> &route) {
        vector<bool> vis(n);    //结点是否访问过
        vector<ll> d(n);    //源结点到各结点的距离
        vector<int> vec(n);
        vector<vector<int> > mp(n);
        while (!route.empty()) {
            route.pop();
        }
        for (int i = 0; i < n; i++) {
            d[i] = INF;
            vis[i] = 0;
            vec[i] = i;
            mp[i].resize(n);
        }
        for (auto &x:mp) {
            for (auto &a:x) {
                a = INF;
            }
        }
        for (int i = 0; i < cnt; i += 2) {
            if (bannedRoad[i] || banned[edge[i].from] || banned[edge[i].to]) {
                continue;
            }
            mp[edge[i].from][edge[i].to] = edge[i].w;
            mp[edge[i].to][edge[i].from] = edge[i].w;
//        cout<<number[edge[i].from]<<' '<<number[edge[i].to]<<' '<<edge[i].w<<' '<<mp[edge[i].from][edge[i].to]<<endl;
        }
        d[s] = 0;
        for (int i = 0; i < n; i++) {
            ll cur = INF;
            int x;
            for (int j = 0; j < n; j++) {
                if (!vis[j] && d[j] <= cur) {
                    cur = d[j];
                    x = j;
                }
            }
            vis[x] = 1;
            for (int j = 0; j < n; j++) {
                if (d[x] + mp[x][j] < d[j]) {
                    d[j] = d[x] + mp[x][j];
                    vec[j] = x;
//                cout<<number[x]<<' '<<number[j]<<endl;
                }
            }
        }
        for (int i = destination; i != vec[i]; i = vec[i]) {
            if (i == s) {
                break;
            }
            route.push(i);
        }
        return d[destination];
    }


    void printPath(const int &i, const int &j, const vector<vector<int> > &path) {
        if (path[i][j] == -1)
            return;
        printPath(i, path[i][j], path);
        cout << "---" << number[path[i][j]];
        printPath(path[i][j], j, path);
    }


    int floyd(int s, int n, int destination, vector<vector<int> > &path) {
        vector<vector<int> > mp(n);
        path.resize(n);
        for (int i = 0; i < n; ++i) {
            mp[i].resize(n);
            path[i].resize(n);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                mp[i][j] = INF;
                path[i][j] = -1;
            }
        }
        for (int i = 0; i < cnt; i += 2) {
            if (bannedRoad[i] || banned[edge[i].from] || banned[edge[i].to]) {
                continue;
            }
            mp[edge[i].from][edge[i].to] = edge[i].w;
            mp[edge[i].to][edge[i].from] = edge[i].w;
//        cout<<number[edge[i].from]<<' '<<number[edge[i].to]<<' '<<edge[i].w<<' '<<mp[edge[i].from][edge[i].to]<<endl;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mp[i][k] + mp[k][j] < mp[i][j]) {
                        mp[i][j] = mp[i][k] + mp[k][j];
                        path[i][j] = k;
                    }
                }
            }
        }
        return mp[s][destination];
    }
};

#endif // GRAPH_H_INCLUDED
