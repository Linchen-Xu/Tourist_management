#ifndef DATAPROCESS_H_INCLUDED
#define DATAPROCESS_H_INCLUDED

#include <bits/stdc++.h>
#include <windows.h>
#include "../dsutil/dsutilcontroller.h"
#define null NULL
#define PI acos(-1)
#define eps 1e-9
#define debug(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
// 无穷大
#define INF 32767

using namespace std;

/*
字符串与整数处理
*/

class dataProcessController{
public:
//切分字符串
    void Split(vector<string> &vec, string str, string ch) {
        int i = 0, len = str.length(), j = 0, len1 = ch.length();
        vec.clear();
        while (i < len) {
            if (str.substr(i, len1) == ch) {
                if (i > j) {
                    vec.push_back(str.substr(j, i - j));
                }
                j = i + len1;
                i += len1 - 1;
            }
            ++i;
        }
        if (j < len && str.substr(j, len - j) != ch) {
            vec.push_back(str.substr(j, len - j));
        }
    }

//将字符串转换为整数
    int stringToInt(const string &a) {
        double ans = 0, sign = 1;
        int len = a.length(), i = 0;
        if (a[0] == '-') {
            sign = -1;
            ++i;
        }
//    cout<<"len="<<len<<endl;
        for (; i < len; ++i) {
            ans = ans * 10 + (a[i] - '0');
        }
        return ans * sign;
    }

//将整数转换为字符串
    string intToString(const int &a) {
        if (a == 0) {
            return "0";
        }
        string ans = "";
        int x = a;
        if (x < 0) {
            ans = "-";
            x *= -1;
        }
        while (x) {
            char ch = '0' + x % 10;
            ans = ch + ans;
            x /= 10;
        }
        return ans;
    }

//获取一个[a,b]之间的整数
    int getNumberBetween(const int &a, const int &b) {
        string str;
        bool flag = true;
        int ans;
        while (flag) {
            cout << "请输入一个在 " << a << " 到 " << b << " 之间的数:";
            cin >> str;
            flag = false;
            for (auto x:str) {
                if (x < '0' || x > '9') {
                    cout << "请输入一个在 " << a << " 到 " << b << " 之间的数！" << endl;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                ans = stringToInt(str);
                if (ans < a || ans > b) {
                    cout << "请输入一个在 " << a << " 到 " << b << " 之间的数！" << endl;
                    flag = true;
                }
            }
        }
        return ans;
    }
};
#endif // DATAPROCESS_H_INCLUDED
