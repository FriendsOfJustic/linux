
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include"contact.h"

void menu()
{
	printf("******************************\n");
	printf("***** 1.add        2.delete***\n");
	printf("***** 3.search     4.sub   ***\n");
	printf("***** 5.sort       6.print ***\n");
	printf("***** 0.exite              ***\n");
	printf("******************************\n");
	printf("******************************\n");
}


enum function
{
	excite,
	add,
	delete,
	search,
	sub,
	sort,
	print
};

int main()
{
	int input = 0;
	initcontact(&con);
	do
	{
		menu();
		scanf_s("%d", &input);
		switch (input)
		{
		case add:
			addcontact(&con);
			break;
		case excite:
			exitcon(&con);
			break;
		case delete:
			delecon(&con);
			break;
		case search:
			searchcon(&con);
			break;
		case sub:
			break;
		case sort:
			sortcon(&con);
			break;
		case print:
			printcon(&con);
			break;
		default:
			printf("重新输入正确选项");
		}

	} while (input);
}