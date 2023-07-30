#define _CRT_SECURE_NO_WARNINGS 1

#include<string.h>
#include<stdio.h>

#define MAX 20
#define MAX_data 10

struct peopleinfo
{
	char name[MAX];
	char gender[MAX];
	int age;
	char tele[MAX];
	char address[MAX];
}data[MAX_data];

struct contact
{
	struct peopleinfo data[MAX_data];
	int sz;
}con;

void initcontact(struct contact* p);
int addcontact(struct contact* p);
void printcon(struct contact* p);
void delecon(struct contact* p);
void searchcon(struct contact* p);
void sortcon(struct contact* p);
void subcon(struct peopleinfo* p1,struct peopleinfo* p2);
void exitcon(struct contact* p);
