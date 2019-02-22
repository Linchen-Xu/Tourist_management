#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <bits/stdc++.h>
#include "carmodel.h"
#define null NULL
#define PI acos(-1)
#define eps 1e-9
#define debug(...) fprintf(stderr,__VA_ARGS__),fflush(stderr)
// 无穷大
#define INF 32767

using namespace std;

class carController {
private:
    carModel carModel1;
public:
    void parkCar(dataProcessController &dataProcessController1) {
        park tmp;
        cout << "请输入车牌号：";
        cin >> tmp.license;
        cout << "请输入停车时间（格式为HH：MM）：";
        cin >> tmp.arrival;
        tmp.order = carModel1.max_order;
        carModel1.car_fetched.push_back(false);
        if (carModel1.parkingSpot.size() >= carModel1.max_parking_car) {
            cout << "车辆被暂时停到便道上，编号为 " << carModel1.max_order << endl;
            carModel1.shortcut.push(tmp);
            carModel1.record_of_parking.push_back(
                    tmp.license + " 在 " + tmp.arrival + " 停入便道，编号为 " + dataProcessController1.intToString(carModel1.max_order));
        } else {
            cout << "车辆已停入停车场，编号为 " << carModel1.max_order << endl;
            carModel1.parkingSpot.push(tmp);
            carModel1.record_of_parking.push_back(
                    tmp.license + " 在 " + tmp.arrival + " 停入停车场，编号为 " + dataProcessController1.intToString(carModel1.max_order));
        }
        ++carModel1.max_order;
    }

    void getCar(dataProcessController &dataProcessController1) {
        if (carModel1.parkingSpot.empty()) {
            cout << "停车场为空！" << endl;
            system("pause");
            return;
        }
        cout << "请输入车辆编号：";
        int num = dataProcessController1.getNumberBetween(0, carModel1.max_order - 1);
        if (carModel1.car_fetched[num]) {    //车辆已经被开走
            cout << "该车已被开走！" << endl;
            system("pause");
            return;
        }
        carModel1.car_fetched[num] = true;
        cout << "请输入当前时间：";
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
                    leave.license + " 在 " + str + " 离开便道，编号为 " + dataProcessController1.intToString(leave.order));
            cout << "取车成功！" << endl;
            return;
        }
        stack<park> st;
        while (carModel1.parkingSpot.top().order != num) {
            st.push(carModel1.parkingSpot.top());
            carModel1.parkingSpot.pop();
        }
        //计算停车时间，不满一小时按一小时计
        int fee = ((dataProcessController1.stringToInt(str.substr(0, 2)) -
                    dataProcessController1.stringToInt(carModel1.parkingSpot.top().arrival.substr(0, 2))) * 60 +
                   (dataProcessController1.stringToInt(str.substr(str.length() - 2, 2)) - dataProcessController1.stringToInt(
                           carModel1.parkingSpot.top().arrival.substr(carModel1.parkingSpot.top().arrival.length() - 2, 2))) + 59) / 60 *
                  10;
        cout << "车费为 " << fee << " 元" << endl;
        carModel1.record_of_parking.push_back(carModel1.parkingSpot.top().license + " 在 " + str + " 离开停车场，编号为 " +
                                    dataProcessController1.intToString(carModel1.parkingSpot.top().order) + " ,费用为 " +
                                    dataProcessController1.intToString(fee) + " 元");
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
                    tmp.license + " 在 " + tmp.arrival + " 停入停车场，编号为 " + dataProcessController1.intToString(tmp.order));
        }
    }
};
#endif // CAR_H_INCLUDED
