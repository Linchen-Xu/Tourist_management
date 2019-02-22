#ifndef NOTICE_H_INCLUDED
#define NOTICE_H_INCLUDED

#include <bits/stdc++.h>
#include <windows.h>
#define null NULL
#define PI acos(-1)
#define eps 1e-9
#define debug(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
// 无穷大
#define INF 32767

using namespace std;

class noticeController {
private:
    vector<string> notice;                  //通知
public:
    void sendNotice() {      //发布通知
        system("cls");
//    cout<<"sendNotice"<<endl;
        cout << "请输入通知内容：" << endl;
        string str;
        getline(cin, str);   //清空缓存区
        getline(cin, str);   //读取文本
        notice.push_back(str);
        cout << "发布成功！" << endl;
    }

    void readNotice() {          //读取通知
        system("cls");
        for (int i = 0; i < notice.size(); ++i) {
            cout << i + 1 << ' ' << notice[i] << endl;
        }
        system("pause");
    }

    void clear(){
        notice.clear();
    }

    void push_back(const string &tmp){
        notice.push_back(tmp);
    }

    vector<string> getNotices(){
        return notice;
    }

};
#endif // NOTICE_H_INCLUDED
