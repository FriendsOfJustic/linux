
#include<iostream>

#include <stdio.h>
#include <stdarg.h>
#include <libpq-fe.h>
using namespace std;
int main()
{
    const char *conninfo = "host=122.112.250.145 user=geohazard  dbname=geohazard port=15432 password=cumtb_2023_rerssil";
    PGconn *conn = PQconnectdb(conninfo);
    if (PQstatus(conn) == CONNECTION_BAD)
    {
        printf("failed to connect database！");
        PQfinish(conn);
        return 1;
    }
    PGresult *res = PQexec(conn, "select st_astiff(rast) from chain_sus_dem;");
    int i = PQntuples(res);
    int t = PQnfields(res);
    cout<<PQfname(res,0)<<endl;
    int s = 0;
    // 循环取值
    for (; s < i; s++)
    {
        int k = 0;
        for (; k < t; k++)
        {
            //printf("% s % s \n", PQgetvalue(res, s, k));
            
        }
    }
    PQclear(res);
}