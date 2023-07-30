#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include"contact.h"
void checkcapcity(struct contact* p)
{
	if (p->sz == p->capacity)
	{
		struct peopleinfo* ptr = (struct peopleinfo*)realloc(p->data, (p->capacity + ADDCA) * sizeof(struct peopleinfo));
		if (ptr == NULL)
		{
			printf("初始化失败");
			return;
		}
		else
		{
			p->data = ptr;
			printf("初始化成功");
			p->capacity = p->capacity + ADDCA;
		}
	}
}
void file_read(struct contact* p)
{
	FILE* pf = fopen("contact.txt", "r");
	if (pf == NULL)
		printf("文件读取失败，请重新读取");
	else
	{
		struct peopleinfo temp;
		while(fread(&temp, sizeof(struct peopleinfo), 1, pf))
		{
			checkcapcity(p);
			p->data[p->sz] = temp;
			p->sz++;
		}
	}
}
void initcontact(struct contact* p)
{
	p->data = (struct peopleinfo*)malloc(initial * sizeof(struct peopleinfo));
	if (p->data == NULL)
	{
		printf("初始化失败");
		return;
	}
	else
	{
		
		p->sz = 0;
		p->capacity = initial;
	}
	file_read(p);
}
void exitcon(struct contact* p)
{
	FILE* pf = fopen("contact.txt", "w");
	if (p == NULL)
		printf("保存文件失败");
	else
	{
		for (int i = 0; i < p->sz; i++)
		{
			fwrite(p->data + i, sizeof(struct peopleinfo), 1, pf);
		}
	}
	fclose(pf);
	free(p->data);
	p->data = NULL;

}

int addcontact(struct contact* p)
{
	if (p->sz == p->capacity)
	{
		struct peopleinfo* ptr = (struct peopleinfo*)realloc(p->data, (p->capacity + ADDCA) * sizeof(struct peopleinfo));
		if (ptr == NULL)
		{
			printf("初始化失败");
			return 0;
		}
		else
		{
			p->data = ptr;
			printf("初始化成功");
			p->capacity = p->capacity + ADDCA;
		}
	}

	printf("\n请输入姓名：");
	scanf("%s", p->data[p->sz].name);
	printf("\n请输入性别：");
	scanf("%s", p->data[p->sz].gender);
	printf("\n请输入年龄");
	scanf("%d", &(p->data[p->sz].age));
	printf("\n请输入电话呢号码");
	scanf("%s", p->data[p->sz].tele);
	printf("\n请输入住址:");
	scanf("%s", p->data[p->sz].address);
	p->sz++;
	return 0;
}
void printcon(struct contact* p)
{
	for (int i = 0; i < p->sz; i++)
	{
		printf("%-7s\t%-5s\t%-2s\t%-5s\t%-5s\n", "姓名", "性别", "年龄", "电话", "住址");
		printf("%-7s\t", p->data[i].name);
		printf("%-5s\t", p->data[i].gender);
		printf("%d\t", p->data[i].age);
		printf("%-5s\t", p->data[i].tele);
		printf("%-5s\t", p->data[i].address);
		printf("\n");
	}
}


static int findbyname(char* p1, struct contact* p2)
{
	for (int i = 0; i < p2->sz - 1; i++)
	{
		int ret = strcmp(p1, p2->data[p2->sz - 1].name);
		if (ret == 0)
			return p2->sz - 1;
	}
	return 0;
}


void delecon(struct contact* p)
{
	if (p->sz < 1)
		printf("通讯录为空无法在删除");
	else
	{
		char name1[MAX];
		printf("输入要删除的联系人名字：");
		scanf("%s", name1);
		int ret = findbyname(name1, p);
		if (ret == 0)
			printf("不存在这个人");
		else
		{
			for (int z = ret; z < (p->sz - 1 - ret); z++)
			{
				p->data[z] = p->data[z + 1];
			}
			p->sz--;
		}
	}
}


void searchcon(struct contact* p)
{
	printf("q请输入名字以便查找：");
	char name1[MAX];
	scanf("%s", name1);
	for (int i = 0; i < p->sz - 1; i++)
	{
		int ret = strcmp(name1, p->data[i].name);
		if (ret == 0)
		{
			printf("%-7s\t%-5s\t%-2s\t%-5s\t%-5s\n", "姓名", "性别", "年龄", "电话", "住址");
			printf("%-7s\t", p->data[i].name);
			printf("%-5s\t", p->data[i].gender);
			printf("%d\t", p->data[i].age);
			printf("%-5s\t", p->data[i].tele);
			printf("%-5s\t", p->data[i].address);
			printf("\n");
			break;
		}
	}
}


void sortcon(struct contact* p)
{
	for (int i = 0; i < p->sz - 1; i++)
	{
		for (int j = 0; j < p->sz - i - 1; j++)
		{
			int ret = strcmp(p->data[i].name, p->data[i + 1].name);
			if (ret > 0)
			{
				subcon(&(p->data[i]), &(p->data[i + 1]));
			}
		}
	}

	printcon(p);
}


void subcon(struct peopleinfo* p1, struct peopleinfo* p2)
{
	char a = 0;
	int size = sizeof(struct peopleinfo);
	for (int i = 0; i < size; i++)
	{
		a = ((char*)p1)[i];
		((char*)p1)[i] = ((char*)p2)[i];
		((char*)p2)[i] = a;

	}
}
