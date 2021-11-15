#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<string.h>
#include"contact.h"

void menu()
{
	printf("********************************\n");
	printf("*******0.exit    1.add    ******\n");
	printf("*******2.del     3.search ******\n");
	printf("*******4.modify  5.show   ******\n");
	printf("*******6.sort             ******\n");
	printf("********************************\n");
	printf("********************************\n");
	printf("请输入你的选择：");
}
enum function
{
	exit,
	add,
	del,
	search,
	modify,
	show,
	sort
};


int main()
{
	int input = 0;
	do
	{
		struct contact c;
		initcontact(&c);
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case exit:
			return 0;
			break;
		case add:
			add_personinfo(&c);
			break;
		case del:
			break;
		case search:
			break;
		case modify:
			break;
		case show:
			show_personinfo(&c);
			break;
		case sort:
			break;
		default:
			printf("没有该种功能");
		}
	} while (input);
}