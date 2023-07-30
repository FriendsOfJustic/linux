#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include<string.h>
#include<stdio.h>
#include<malloc.h>

#define MAX 20
#define initial 3
#define ADDCA 2

struct peopleinfo
{
	char name[MAX];
	char gender[MAX];
	int age;
	char tele[MAX];
	char address[MAX];
};

struct contact
{
	struct peopleinfo* data;
	int sz;
	int capacity;
}con;

void initcontact(struct contact* p);
int addcontact(struct contact* p);
void printcon(struct contact* p);
void delecon(struct contact* p);
void searchcon(struct contact* p);
void sortcon(struct contact* p);
void subcon(struct peopleinfo* p1, struct peopleinfo* p2);
void exitcon(struct contact* p);
