#ifndef NOTICE_H_INCLUDED
#define NOTICE_H_INCLUDED

#include <bits/stdc++.h>
#include <windows.h>
#define null NULL
#define PI acos(-1)
#define eps 1e-9
#define debug(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
// �����
#define INF 32767

using namespace std;

class noticeController {
private:
    vector<string> notice;                  //֪ͨ
public:
    void sendNotice() {      //����֪ͨ
        system("cls");
//    cout<<"sendNotice"<<endl;
        cout << "������֪ͨ���ݣ�" << endl;
        string str;
        getline(cin, str);   //��ջ�����
        getline(cin, str);   //��ȡ�ı�
        notice.push_back(str);
        cout << "�����ɹ���" << endl;
    }

    void readNotice() {          //��ȡ֪ͨ
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
