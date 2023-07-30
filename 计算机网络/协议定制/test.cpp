
#include <iostream>

using namespace std;
#include "protocol.hpp"

void test_protocal()
{
    Request *req = new Request(1, 2, '+');
    string s;
    req->Serialize(s);
    cout << s << endl;

    Request r2;

    r2.Deserialize(s);

    cout << r2.to_string() << endl;

    Response *resp = new Response("exitnormal", 10);

    resp->Serialize(s);
    cout << s << endl;

    Response r3;

    r3.Deserialize(s);

    cout << r3.to_string() << endl;
}

int main()
{
    test_protocal();
}