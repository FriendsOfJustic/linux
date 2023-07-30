#pragma once




#define NUMBER 1000


struct personinfo
{
	char name[20];
	int tele[10];
	char gender[6];
	char address[30];
};
struct contact
{
	struct personinfo data[NUMBER];
	int size;
};

void initcontact(struct contact*p);

void add_personinfo(struct contact*p);


void show_personinfo(struct contact* p);
