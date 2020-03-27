#include "data.h"

data::data()
{

}

int data::getAppNumber()
{
    return dataVector.size();
}

void data::loadAppData()
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
    info.appName = "fore";
    dataVector.push_back(info);

    info.picPath = "ded";
    info.appName = "five";
    dataVector.push_back(info);

}
