#include <iostream>
#include <string>
#include "./entity/contact.pb.h"
#include <fstream>
using namespace std;

int main()
{
    Contact2::Contact con;
    fstream in_file("contact.bin", ios::in | ios::binary);

    if (!con.ParseFromIstream(&in_file))
    {
        cerr << "读取出错" << endl;
        return false;
    }

    for (int i = 0; i < con.contact_size(); i++)
    {
        Contact2::PeopleInfo cur = con.contact(i);
        cout << "联系人姓名：" << cur.name() << endl;
        cout << "联系人年龄：" << cur.age() << endl;
        for (int j = 0; j < cur.phone_size(); j++)
        {
            cout << "电话号码" << j + 1 << ": " << cur.phone(j).number() << endl;
        }
    }
    in_file.close();

    return 0;
}