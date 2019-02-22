//
// Created by xlc on 2018/7/12.
//

#ifndef DATA_STDUCTURE_DAO_H
#define DATA_STDUCTURE_DAO_H

#include <bits/stdc++.h>

using namespace std;

class InterfaceDAO{
public:
    virtual void clearData(noticeController &noticeController1,carModel &carModel1) = 0;
    virtual void readData(noticeController &noticeController1,dataProcessController &dataProcessController1,dsutilController &dsutilController1,carModel &carModel1) = 0;
    virtual void saveData(noticeController &noticeController1,carModel &carModel1) = 0;
    virtual void close() = 0;
    ~InterfaceDAO(){};
};

#endif //DATA_STDUCTURE_DAO_H
