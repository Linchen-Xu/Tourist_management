#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <bits/stdc++.h>
#include "carmodel.h"
#define null NULL
#define PI acos(-1)
#define eps 1e-9
#define debug(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
// �����
#define INF 32767

using namespace std;

class carController {
private:
    carModel carModel1;
public:
    void parkCar(dataProcessController &dataProcessController1) {
        park tmp;
        cout << "�����복�ƺţ�";
        cin >> tmp.license;
        cout << "������ͣ��ʱ�䣨��ʽΪHH��MM����";
        cin >> tmp.arrival;
        tmp.order = carModel1.max_order;
        carModel1.car_fetched.push_back(false);
        if (carModel1.parkingSpot.size() >= carModel1.max_parking_car) {
            cout << "��������ʱͣ������ϣ����Ϊ " << carModel1.max_order << endl;
            carModel1.shortcut.push(tmp);
            carModel1.record_of_parking.push_back(
                    tmp.license + " �� " + tmp.arrival + " ͣ���������Ϊ " + dataProcessController1.intToString(carModel1.max_order));
        } else {
            cout << "������ͣ��ͣ���������Ϊ " << carModel1.max_order << endl;
            carModel1.parkingSpot.push(tmp);
            carModel1.record_of_parking.push_back(
                    tmp.license + " �� " + tmp.arrival + " ͣ��ͣ���������Ϊ " + dataProcessController1.intToString(carModel1.max_order));
        }
        ++carModel1.max_order;
    }

    void getCar(dataProcessController &dataProcessController1) {
        if (carModel1.parkingSpot.empty()) {
            cout << "ͣ����Ϊ�գ�" << endl;
            system("pause");
            return;
        }
        cout << "�����복����ţ�";
        int num = dataProcessController1.getNumberBetween(0, carModel1.max_order - 1);
        if (carModel1.car_fetched[num]) {    //�����Ѿ�������
            cout << "�ó��ѱ����ߣ�" << endl;
            system("pause");
            return;
        }
        carModel1.car_fetched[num] = true;
        cout << "�����뵱ǰʱ�䣺";
        string str;
        cin >> str;
        if (num > carModel1.parkingSpot.top().order) {
//           cout<<"biandao"<<endl;
            queue<park> tmp;
//           cout<<"queue"<<endl;
            while (carModel1.shortcut.front().order != num) {
//               cout<<"top ";
//               cout<<num<<" "<<carModel1.shortcut.front().order<<endl;
                tmp.push(carModel1.shortcut.front());
                carModel1.shortcut.pop();
            }
//           cout<<"test11"<<endl;
            park leave = carModel1.shortcut.front();
            carModel1.shortcut.pop();
//           cout<<"test empty"<<endl;
            if (!tmp.empty()) {
//               cout<<"not empty"<<endl;
                int second_order = tmp.front().order;
//               cout<<"test1"<<endl;
                while (!tmp.empty()) {
                    carModel1.shortcut.push(tmp.front());
                    tmp.pop();
//                   cout<<"pop"<<endl;
                }
//               cout<<"test2"<<endl;
                while (second_order != carModel1.shortcut.front().order) {
                    Car tmp1 = carModel1.shortcut.front();
                    carModel1.shortcut.pop();
                    carModel1.shortcut.push(tmp1);
                }
//               cout<<"test3"<<endl;
            }
            carModel1.record_of_parking.push_back(
                    leave.license + " �� " + str + " �뿪��������Ϊ " + dataProcessController1.intToString(leave.order));
            cout << "ȡ���ɹ���" << endl;
            return;
        }
        stack<park> st;
        while (carModel1.parkingSpot.top().order != num) {
            st.push(carModel1.parkingSpot.top());
            carModel1.parkingSpot.pop();
        }
        //����ͣ��ʱ�䣬����һСʱ��һСʱ��
        int fee = ((dataProcessController1.stringToInt(str.substr(0, 2)) -
                    dataProcessController1.stringToInt(carModel1.parkingSpot.top().arrival.substr(0, 2))) * 60 +
                   (dataProcessController1.stringToInt(str.substr(str.length() - 2, 2)) - dataProcessController1.stringToInt(
                           carModel1.parkingSpot.top().arrival.substr(carModel1.parkingSpot.top().arrival.length() - 2, 2))) + 59) / 60 *
                  10;
        cout << "����Ϊ " << fee << " Ԫ" << endl;
        carModel1.record_of_parking.push_back(carModel1.parkingSpot.top().license + " �� " + str + " �뿪ͣ���������Ϊ " +
                                    dataProcessController1.intToString(carModel1.parkingSpot.top().order) + " ,����Ϊ " +
                                    dataProcessController1.intToString(fee) + " Ԫ");
        carModel1.parkingSpot.pop();
        while (!st.empty()){
            carModel1.parkingSpot.push(st.top());
            st.pop();
        }
        park tmp;
        while (!carModel1.shortcut.empty() && carModel1.parkingSpot.size() <= carModel1.max_parking_car) {
            tmp = carModel1.shortcut.front();
            tmp.arrival = str;
            carModel1.shortcut.pop();
            carModel1.parkingSpot.push(tmp);
            carModel1.record_of_parking.push_back(
                    tmp.license + " �� " + tmp.arrival + " ͣ��ͣ���������Ϊ " + dataProcessController1.intToString(tmp.order));
        }
    }
};
#endif // CAR_H_INCLUDED
