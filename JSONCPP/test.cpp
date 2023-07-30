

#include <iostream>
#include <jsoncpp/json/json.h>
#include <string>

using namespace std;

class PeopleInfo
{
    string name;
    int age;
};
std::string writeAsArray()
{

    // 写入一个json 字符串
    Json::FastWriter w;
    Json::Value RRoot; // 根节点
    Json::Value root;  // 数组节点节点
    Json::Value a;     // 根节点
    a["name"] = "石海涛";
    a["age"] = 23;
    root.append(a);
    a.clear();
    a["name"] = "魏子涵";
    a["age"] = 32;
    root.append(a);
    a.clear();
    a["name"] = "王一鸣";
    a["age"] = 45;
    root.append(a);

    RRoot["状态码"] = "正常";
    RRoot["数组"] = root;
    cout << RRoot.toStyledString() << endl;
    cout << w.write(RRoot) << endl;
    return w.write(RRoot);

    // Json::Value root;
    // Json::Value itemFaceArray;
    // Json::Value itemFace;
    // root["errorCode"] = 0;
    // root["faces"].resize(0);
    // // face1
    // itemFace["x"] = 1;
    // itemFace["y"] = 1;
    // itemFace["width"] = 100;
    // itemFace["height"] = 100;
    // itemFace["score"] = 95;
    // itemFaceArray.append(itemFace);
    // // face2
    // itemFace.clear();
    // itemFace["x"] = 200;
    // itemFace["y"] = 200;
    // itemFace["width"] = 100;
    // itemFace["height"] = 100;
    // itemFace["score"] = 98;
    // itemFaceArray.append(itemFace);
    // root["faces"] = itemFaceArray;
    // std::string strJson = root.toStyledString();
    // cout << strJson << endl;
}

void readAsAraay(const string &s)
{

    // 读取json字符串
    Json::Value root;
    Json::Reader r;
    r.parse(s, root);
    cout << root["状态码"] << endl;

    Json::Value array = root["数组"];

    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i]["name"] << "   " << array[i]["age"] << endl;
    }
    return;
}

int main()
{
    readAsAraay(writeAsArray());
}