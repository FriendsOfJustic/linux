#define _CRT_SECURE_NO_WARNINGS 1




#include<stdio.h>
#include<string.h>
#include"contact.h"



void initcontact(struct contact* p)
{
	memset(&p, 0, sizeof(struct contact));
}


void add_personinfo(struct contact* p)
{
	if (p->size <= NUMBER)
		return 0;
	else
	{
		pritnf("����������֣�\n");
		scanf("%s", p->data[p->size].name);
		pritnf("������ĵ绰��\n");
		scanf("%d", p->data[p->size].tele);
		pritnf("��������Ա�\n");
		scanf("%s", p->data[p->size].gender);
		pritnf("�������סַ��\n");
		scanf("%s", p->data[p->size].address);

	}
	p->size++;
}


void show_personinfo(struct contact* p)
{
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		printf("%s", p->data[i].name);
		printf("%d", p->data[i].tele);
		printf("%s", p->data[i].gender);
		printf("%s", p->data[i].address);
	}
}