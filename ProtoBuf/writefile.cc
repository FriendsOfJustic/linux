#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "./entity/contact.pb.h"

void add_people(Contact2::PeopleInfo *newone)
{
  string _name;
  int _age;
  cout << "请输入姓名：";
  cin >> _name;

  cout << "请输入年龄：";
  cin >> _age;

  newone->set_name(_name);
  newone->set_age(_age);
  // cin.clear();
  getchar();
  while (1)
  {
    cout << "请输入电话号码#";
    string phonenumber;
    getline(cin, phonenumber);
    if (phonenumber == "exit")
      break;
    newone->add_phone()->set_number(phonenumber);
  }
}
int main()
{
  // 从二进制文件中读取
  Contact2::Contact con;
  fstream input_file("contact.bin", ios::in | ios::binary);
  if (!con.ParseFromIstream(&input_file))
  {
    cerr << "读取文件出错" << endl;
  }
  input_file.close();

  // 添加联系人
  add_people(con.add_contact());

  // 写入二进制文件
  fstream output_file("contact.bin", ios::out | ios::trunc | ios::binary);
  con.SerializePartialToOstream(&output_file);
  output_file.close();
  cout << "写入成功" << endl;
}
