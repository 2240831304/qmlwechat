#include "data.h"

data::data()
{

}

data::~data()
{
    dataVector.clear();
}

int data::getAppNumber()
{
    return dataVector.size();
}

const AppInfo & data::getData(int number)
{
   return  dataVector[number];
}

void data::loadAppData()
{
    loadData();
}

void data::loadData()
{
    AppInfo info;
    info.picPath = "ded";
    info.appName = "one";
    dataVector.push_back(info);

    info.picPath = "ded";
    info.appName = "two";
    dataVector.push_back(info);

    info.picPath = "ded";
    info.appName = "three";
    dataVector.push_back(info);

    info.picPath = "ded";
    info.appName = "four";
    dataVector.push_back(info);

    info.picPath = "ded";
    info.appName = "five";
    dataVector.push_back(info);

}
