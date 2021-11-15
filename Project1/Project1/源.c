#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
//#include<stdio.h>
//#include<string.h>
////int main()
////{
////	char arr1[] = "abcd";
////	char arr2[] = { 'a','b','c','d' };
////	printf("1: %s\n", arr1);
////	printf("2: %s\n", arr2);
////	printf("1: %d\n", strlen(arr1));
////	printf("2: %d\n", strlen(arr2));
////	printf("\a\a\a\a");
////	return 0;
////}
//int add(int x, int y)
//{
//	int max;
//	if (x > y)
//	{
//		max = x;
//	}
//	else
//	{
//		max = y;
//	}
//	return max;
//}
//int main()
//{
//	int a, b;
//	int max;
//	scanf("%d %d", &a, &b);
//	max = add(a, b);
//	printf("最大值是 %d", max);
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 0)
//			printf("%d ", i);
//	}
//		return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[3];
//	int i = 0,temp;
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 2 - i; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				temp = arr[j];
//				arr[j] = arr[i + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	return 0;
//}
//
//#include<stdio.h>      //两个数的最大公约数：1 最大公约数不会超过18   2 从大到小
//int main()
//{
//	int a, b,i;
//	scanf("%d %d", &a, &b);
//	for (i =( a > b ? b : a); i >0; i--)
//	{
//		int max = a < b ? b : a;
//		if ((max % i == 0)&&( (a > b ? b : a)%i==0))
//		{
//			printf("%d", i);
//			break;
//		}
//	}
//	return 0;
//}
//#include<stdio.h> //辗转相除法
//int main()
//{
//	int m = 0, n = 0;
//	scanf("%d%d", &m, &n);
//	int t = 0;
//	while (t = m % n)
//	{
//		m = m;
//		n = t;
//	}
//	printf("最大公约数：%d", n);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if ((i % 4 == 0) && (i % 100 != 0)) //if ((i % 4 == 0) && (i % 100 != 0)||(i%400==0))
//			printf("%d ", i);
//		else if(i%400==0)
//			printf("%d ", i);
//	}
//	return 0;
//
//}
//#include<stdio.h>
//int main()
//{
//	int i,j;
//	for (i = 100; i <= 200; i++)
//	{
//		for (j = 2; j < i; j++)   //sqrt(i)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (i == j)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	int s = 1, n, sum=0;
//	scanf("%d", &n);
//	for (i = 1; i < n; i++)
//	{
//		if (n == 1)
//			printf("%d ", n);
//		else
//			s = s * (i + 1);
//		sum = sum + s;
//	}
//	printf("%d", sum);
//	return 0;
//}
//#include<stdio.h>//二分法
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 12;
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//	while (left<=right)
//	{
//		int mid = (right + left) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了 %d", mid+1);
//			break;
//		}
//	}
//	if (left > right)
//		printf("找不到芜湖！！！！！！！");
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr1[] = "welcome to bit!!!!!!!!";
//	char arr2[] = "######################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码：》");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)//不能是password=="123456",这样只是比较字符串首地址
//		{
//			printf("登陆成功\n");
//			break;
//		}
//		else
//		{
//			if (i == 2)
//			{
//				printf("三次输入军错误 退出");
//			}
//			printf("重新输入：");
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a, b,i,m=0;
//	for (i = 1; i < 101; i++)
//	{
//		a = i / 10;
//		b = i - 10 * a;
//		if (a == 9)
//			m++;
//		if (b == 9)
//			m++;
//	}
//	printf("%d", m);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	double i;
//	double sum=0;
//	int x = 1;
//	for (i = 1; i <=100; i++)
//	{
//		float s;
//		s = x*(1 / (double)i);
//		sum += s;
//		x = x * (-1);
//		
//	}
//	printf("%f", sum);
//}
//#include<stdio.h>
//int main()
//{
//	int arr[10];
//	int i,j;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 9 - i; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int temp;
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//	printf("%d ", arr[0]);
//}
//#include<stdio.h>
//int main()
//{
//	int i, j;
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %d\t", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	int k;
//	printf("请输入查找的数");
//	scanf("%d", &k);
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//			left = mid + 1;
//		else if (arr[mid] > k)
//			right = mid - 1;
//		else
//		{
//			printf("序列号为 %d ", mid);
//			break;
//		}
//	}
//	if (left > right)
//		printf("不存在这个数字");
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void manu()
//{
//	printf("*******************************************\n");
//	printf("************ 1.play   *********************\n");
//	printf("************ 2.exit   *********************\n");
//	printf("*******************************************\n");
//	printf("*******************************************\n");
//	printf("*******************************************\n");
//}
//void game()
//{
//	int random = rand() % 100 + 1;
//	int input;
//	while (1)
//	{
//		printf("请输入一个数字： ");
//		scanf("%d", &input);
//		if (input < random)
//			printf("数字小了");
//		else if (input > random)
//			printf("数字大了");
//		else
//		{
//			printf("输入正确 游戏结束");
//			break;
//		}
//
//	}
//}
//int main()
//{
//	int m=0;
//	srand((unsigned)time(NULL));
//	while (1)
//	{
//		manu();
//		printf("输入数字：");
//		scanf("%d", &m);
//		if (m == 1)
//		{
//			game();
//		}
//		else if (m == 0)
//		{
//			break;
//		}
//		else
//			printf("重新输入");
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		;
//	}
//	printf("%d", i);
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	char arr[20];
//	while (1)
//	{
//		printf("请在20s秒内输入输入“石海涛是我爹”否则后果自负\n");
//		system("shutdown -s -t 20");
//		scanf("%s", arr);
//		if (strcmp(arr, "石海涛是我爹") == 0)
//		{
//			system("shutdown -a");
//			printf("自毁已经关闭");
//			break;
//		}
//	}
//	return 0;
//
//}
//
//#include<stdio.h>
//void fun(int a)
//{
//	int i;
//	for (i = a - 1; i > 1; i--)
//	{
//		if (a % i == 0)
//		{
//			break;
//		}
//	}
//	if (i == 1)
//	{
//		printf("%d ", a);
//	}
//}
//int main()
//{
//	int i = 100;
//	for (; i <= 200; i++)
//	{
//		fun(i);
//	}
//	return 0;
//}
//#include<stdio.h>
//void swap(int* x, int* y)
//{
//	int z = 0;
//	z = *x;
//	*x = *y;
//	*y = z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//交换两个整形变量的值
//
//	swap(&a, &b);
//	printf("a=%d b=%d", a, b);
//	return 0;
//
//}
//#include<stdio.h>
//int is_leap_year(int x)
//{
//	if ((x % 4 == 0) && (x % 100 != 0) || (x % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int y = 0;
//	for (y = 1000; y <= 2000; y++)
//	{
//		if (is_leap_year(y) == 1)
//		{
//			printf("%d ", y);
//		}
//	}
//
//	return 0;
//}
//int binary_search(int arr[], int k, int s)
//{
//	int left = 0;
//	int right = s - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if(a[mid>k])
//
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int key = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//找到了就返回找到位置的坐标
//	//找不到返回-1
//	int ret=binary_search();
//	if (-1 == ret)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了，下标是：%d\n", ret);
//	}
//}
//#include<stdio.h>
//int add(int p)
//{
//	p++;
//	return p;
//}
//int main()
//{
//	static int num = 0;
//	printf("%d",add(num));
//	return 0;
//}

//void print(unsigned int n)
//{
//	if (n / 10 != 0)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//
//}

//不创建临时变量求字符串长度
//int my_strlen(char *str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//		return 0;
//
//}
//int main()
//{
//	char arr[] = "bit";
//	printf("%d", my_strlen(arr));
//	return 0;
//
//}

//斐波那契数列
//int fib1(int n)//递归
//{
//	if (n > 2)
//		return fib1(n - 1) + fib1(n - 2);
//	else
//		return 1;
//}
//int fib2(int n)
//{
//	int a = 1, b = 1, c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("递归法求解：%d", fib1(n));
//	printf("迭代法求解：%d", fib2(n));
//	return 0;
//}
//

//#include<stdio.h>
//void fun(int* a, int* b)
//{
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int main()
//{
//	int x, y;
//	scanf("%d %d",&x,&y);
//	fun(&x, &y);
//	printf("%d %d", x, y);
//	return 0;
//}

//#include<stdio.h>
//void fun(int x)
//{
//	int i, j;
//	for (i = 1; i <= x; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf(" %d * %d = %d\t", j, i, j * i);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int x;
//	scanf("%d", &x);
//	fun(x);
//	return 0;
//}

//#include<stdio.h>
//void fun(int x)
//{
//	if (x / 10 != 0)
//		fun(x / 10);
//	printf(" %d ", x%10);
//}
//int main()
//{
//	int n = 123456;
//	fun(n);
//	return 0;
//}

//#include<stdio.h>
//int fun(int n)
//{
//	if (n > 1)
//		return n * fun(n - 1);
//	else
//		return 1;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d", fun(n));
//	return 0;
//}

//#include<stdio.h>
//int fun1(char *p)
//{
//	if (*p != '\0')
//		return 1 + fun1(p + 1);
//	else
//		return 0;
//}
//int fun2(char* p)
//{
//	int count=0;
//	while (*p != '\0')
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
//int main()
//{
//	char ar[] = "woshizhu";
//	printf("递归方法实现 ： %d\n", fun1(ar));
//	printf("非递归方法实现 ：%d\n", fun2(ar));
//
//}

//#include<stdio.h> //递归使字符串逆序
//int my_strlen(char *p)
//{
//	int n = 0;
//	if (*p != '\0')
//	{
//		return 1+my_strlen(p + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//void reverse(char* p)
//{
//	int left = 0;
//	int right = my_strlen(p)-1;
//	char temp;
//	temp = p[left];
//	p[left] = p[right];
//	p[right] = '\0';
//	if (right>0)
//	{
//		reverse(p + 1);
//	}
//	p[right] = temp;
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	reverse(arr);
//	printf("%s", arr);
//	return 0;
//}
//
//#include<stdio.h>
//int fun(int i)
//{
//	if (i / 10 == 0)
//	{
//		return i % 10;
//	}
//	return fun(i / 10) + fun(i % 10);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", fun(n));
//	return 0;
//}



//#include<stdio.h>
//int fun(int k,int n)
//{ 
//	if (k > 0)
//	{
//		return n * fun(k-1, n);
//	}
//	else
//		return 1;
//}
//int main()
//{
//	int n, k;
//	printf("请输入n和k：");
//	scanf("%d %d", &n, &k);
//	printf("%d", fun(k, n));
//	return 0;
//}

//#include<stdio.h>
//int fun1(int n)
//{
//	if (n > 2)
//	{
//		return fun1(n - 1) + fun1(n - 2);
//	}
//	else
//		return 1;
//
//}
//int fun2(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("递归的方法：\t%d\n",fun1(n));
//	printf("非递归的方法：\t%d",fun2(n));
//	return 0;
//}


//#include<stdio.h>                                                                          //汉诺塔问题
//void move(char x,char y)
//{
//	printf("%c->%c ", x, y);
//}
//int fun(int n)
//{
//	if (n > 2)
//		return fun(n - 1) + 1 + fun(n - 1);
//	else
//		return 3;
//}
//void fun1(int n, char a, char b, char c)
//{
//	if (n == 1)
//	{
//		move(a, c);
//	}
//	else
//	{
//		fun1(n - 1, a, c, b);
//		move(a, c);
//		fun1(n - 1, b, a, c);
//	}
//}
//int main()
//{
//	int n;
//	char a = 'A';
//	char b = 'B';
//	char c = 'C';
//	scanf("%d", &n);
//	printf("%d", fun(n));
//	fun1(n, a, b, c);
//
//}
//
//#include<stdio.h>     //一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//int fun(int n)
//{
//	if (n > 1)
//		return fun(n - 1) + fun(n - 2);
//	else
//		return 1;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d",fun(n));
//	return 0;
//}




//冒泡排序
//#include<stdio.h>
//void bubble_sort(int arr[],int t)
//{
//	int i = 0;
//	int temp;
//	for (i = 0; i < t - 1; i++)
//	{
//		int n = 0;
//		for (int j = 0; j < t - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//				n = 1;
//			}
//		}
//		if (0==n)
//		{
//			break;
//		}
//	}
//}
//int main()
//{
//	int t = 0;
//	int arr[] = { 9,8,7,6,13,4,3,2,1,0 };
//	t = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr,t);
//	for (int i = 0; i < t; i++)
//	{
//		printf(" %d ", arr[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
//void init(int arr[],int sz)
//{
//	for (int i = 0; i < sz; i++)
//		arr[i] = 0;
//}
//void prints(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//}
//void reverse(int arr[], int sz)
//{
//	int temp;
//	for (int i = 0; i < sz / 2; i++)
//	{
//		temp = arr[i];
//		arr[i] = arr[sz - i - 1];
//		arr[sz - i - 1] = temp;
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	reverse(arr, sz);
//	prints(arr, sz);
//	init(arr,sz);
//	prints(arr, sz);
//}

//#include<stdio.h>
//void trade(int a1[],int a2[],int sz)
//{
//	int temp;
//	for (int i = 0; i < sz; i++)
//	{
//		temp=a1[i];
//		a1[i] = a2[i];
//		a2[i] = temp;
//	}
//}
//int main()
//{
//
//	int a1[] = { 12,13,14123,141,5,32,3131 };
//	int a2[] = { 12,314,2,1,52,12,3123 };
//	int sz = sizeof(a1) / sizeof(a1[0]);
//	trade(a1, a2,sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", a1[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", a2[i]);
//	}
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    int n;
//    int a = 1,count=0;
//    scanf("%d", &n);
//    for (int i = 0; i < 32; i++)
//    {
//        
//        if ((a&n) == 1)
//        {
//            count++;
//        }
//        n=n >> 1;
//    }
//   
//    printf("%d", count);
//}




//#include<stdio.h>
//int main()
//{
//	int a = 5;
//	int b = 3;
//	int c = a & b;
//
//	printf("%d", a);
//	printf("%d", b);
//	printf("%d", c);
//	printf("%d", a & b);
//	if ((a & b)==1)
//	{
//		printf("kkkkk");
//	}
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	printf("%p\n", &a);
//	printf("%d\n", &a);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3,d = 4;
//	i = a++ && ++b && d++;
//	printf("%d %d %d %d",a, b, c, d);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	float a = 5 / 4;
//	printf("%f", a);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	int count = 0;
//	printf("输入两个数：\n");
//	scanf("%d %d", &a, &b);
//	c = a ^ b;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((c & 1) == 1)
//		{
//			count++;
//		}
//		c=c >> 1;
//	}
//	printf("%d", count);
//	return 0;
//}



//#include<stdio.h >
//int main()
//{
//	int a = 5;
//	int b=0, c=1;
//	for (int i = 0; i < 16; i++)//奇数
//	{
//		b = (~b) & a;
//		a = a >> i+1;
//	}
//	//for (int i = 0; i < 16; i++)//偶数
//	//{
//	//	a = a >> i+1;
//	//	c = c | a;
//	//}
//	//printf("%d",b);
//	//printf("%d", c);
//
//}




//#include<stdio.h>
//int main()
//{
//	int a;
//	int count = 0;
//	scanf("%d", &a);
//	for (int i = 0; i < 32; i++)
//	{
//		if ((a & 1) == 1)
//			count++;
//		a = a >> 1;
//	}
//	printf("%d", count);
//	return 0;
//}



//#include<stdio.h>
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d", a, b);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 13;
//	int b = a>>1;
//	int arr2[16] = { 0 };
//	int arr[16] = { 0 };
//	for (int i = 0; i <16; i++)
//	{
//		
//		if ((a & 1) == 1)
//			arr[i]=1;
//		a = a >> 2;
//	}
//	for (int i = 0; i < 16; i++)
//	{
//		printf("%d", arr[15 - i]);
//		
//	}
//	printf("\n");
//	for (int i = 0; i < 16; i++)
//	{
//		if ((b & 1) == 1)
//			arr2[i] = 1;
//		b = b >> 2;
//	}
//	for (int i = 0; i < 16; i++)
//	{
//		printf("%d", arr2[15 - i]);
//
//	}
//}


//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	int ret = (++i) + (++i) + (++i);
//	printf("%d", ret);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int ar = 5;
//	int aa = 0x1666;     //0x00DAFA1C
//	int b = 166;
//}

//#include<stdio.h>
//int i;
//int main()
//{
//	i--;
//	if (i > sizeof(i))
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a;
//	int count = 0;
//	int p=1;
//	scanf("%d", &a);
//	for (int i = 0; i < 5; i++)
//	{
//		count += a * p * (5-i);
//		p = 10 * p;
//	}
//	printf("%d", count);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i <sz;i++ )
//	{
//		printf("%d ", *(p + i));
//	}
//	return 0;
//}

//#include<stdio.h>
//int fun(int x, int y,int z)  //153 3 100
//{
//	int count = 0;
//	for (int i = 0; i < y; i++)
//	{
//		int b = 1;
//		int m = x / z;
//		for (int j = 0; j < y; j++)
//		{
//			b = b * m;
//		}
//		count += b; //1 6
//		x = x - m * z; //53 
//		z = z /10;  //10
//
//	}
//	return count;
//
//}
//int main()
//{
//	int i,a,j;
//	for (i = 100000; i >0; i--)
//	{
//		int p = 100000;
//		for (j = 0; j <= 6; j++)
//		{
//			if(i/p!=0)
//			{
//				a = 6 - j;
//				break;     //几位数
//			}
//			if(i/p==0)
//			{
//				p = p / 10;
//			}
//		}
//		int ret = fun(i, a, p);
//		if (fun(i, a, p) == i)
//		{
//			printf("%d ", i);
//		};
//	}
//	
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char a[100] = {};
//	gets_s(a);
//	int sz = strlen(a);
//	int right = sz - 1;
//	int left = 0;
//	while (right > left)
//	{
//		int temp = a[left];
//		a[left] = a[right];
//		a[right] = temp;
//		left++;
//		right--;
//	}
//	printf("%s", a);
//	return 0;
//}

//#define x 13
//
//#include<stdio.h>
//void fun(char (*p)[x], int left, int right)
//{
//	for (int i = left; i <= right; i++)
//	{
//		*(*p + i) = '*';
//	}
//	if (left<(x+1)/2)
//	{
//		fun(--p, ++left, --right);
//	}
//	
//}
//void fun1(char(*p)[x], int left, int right)
//{
//	for (int i = left; i <= right; i++)
//	{
//		*(*p + i) = '*';
//	}
//	if (left < (x+1)/2)
//	{
//		p++;
//		left++;
//		right--;
//		fun1(p, left, right);
//	}
//	
//}
//int main()
//{
//	char a[x][x] = { {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} };
//	fun(&a[(x-1)/2], 0, x-1);
//	fun1(&a[(x - 1) / 2], 0, x-1);
//	for (int i = 0; i < x; i++)
//	{
//		for (int j = 0; j < x; j++)
//		{
//			printf("%c", a[i][j]);
//		}
//		printf("\n");
//	}
//
//}


//#include<stdio.h>
//void fun(int* p)
//{
//
//}
//int main()
//{
//	int a[2][2] = { {1,2},{3,4} };
//	int (*p)[2];
//	p = &a[0];
//	printf("%d", **(p+1));
//	return 0;
//
//}



//#include<stdio.h>
//int fun(int x)
//{
//	if (x > 1)
//	{
//		return x  + fun((x  + x % 2)/2);
//
//	}
//	return 0;
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int ret=fun(a);
//	printf("%d", ret);
//}

//#include<stdio.h>
//int main()
//{
//	int a = 5;
//	a = ~a + 1;
//	printf("%d", a);
//	return 0;
//}
 
//#include<stdio.h>
//void fun1(int arr[])
//{
//	printf("%d\n", sizeof(arr));
//}
//void fun2(char ch[])
//{
//	printf("%d\n", sizeof(ch));
//}
//int main()
//{
//	int arr[10] = {};
//	char ch[10] = {};
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", sizeof(ch));
//	fun1(arr);
//	fun2(ch);
//	return 0;
//}


//#include<stdio.h>
//struct student
//{
//	int age;
//}stu;
//void fun1(struct student* p)
//{
//	printf("%d", p->age);
//}
//void fun2(struct student p)
//{
//	printf("%d", p.age);
//}
//int main()
//{
//	struct student atu = { 12 };
//	fun1(&atu);
//	fun2(atu);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe");
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[10] = {};
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", arr+i);
//	}
//	int k = 0;
//	for (int j = 0; j < 10; j++)
//	{
//		if ((arr[j] % 2 == 1)&&(k<10))
//		{
//			int temp = arr[j];
//			arr[j] = arr[k];
//			arr[k] = temp;
//			k++;
//		}
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}




//#include<stdio.h>
//void fun(int arr[],int sz)
//{
//	int k = 0;
//	for (int j = 0; j < sz; j++)
//	{
//		if (arr[j] % 2 == 1)
//		{
//			int temp = arr[j];
//			arr[j] = arr[k];
//			arr[k] = temp;
//			k++;
//		}
//	}
//}
//int main()
//{
//	int arr[10] = {};
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", arr + i);
//	}
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	fun(arr,sz);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char c = 1;
//	printf("%u\n", sizeof(c));
//	printf("%u\n", sizeof(+c));
//	printf("%u\n", sizeof(-c));
//	return 0;
//}

//#include<stdio.h>
//#include<assert.h>
//int my_strlen(const char * p)
//{
//	int count=0;
//	assert(p != nullptr);
//	while (*p++)
//	{
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char a[] = "abcd";
//	printf("%d", my_strlen(a));
//	return 0;
//}

//#include<stdio.h>
//#include<assert.h>
//char* my_strcpy(char* dest, const char* str)
//{
//	//asset(str != NULL); 
//	char* ret = dest;
//	while (*dest++ = *str++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr[] = "xxxxxxxxxxxxxxxxxxxxxx";
//	char arr1[] = "abcdef";
//	printf("%s", my_strcpy(arr, arr1));
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int count = 0;
//	while (n)
//	{
//		count++;
//		n = n & (n - 1);
//	}
//	printf("%d", count);
//	return 0;
//}

//int main()
//{
//	int count=0;
//	int n;
//	scanf("%d", &n);
//	while (n)
//	{
//		if (n % 2 == 1)
//			count++;
//		n = n / 2;
//	}
//	printf("%d", count);
//	return 0;
//}
//
//int main()
//{
//	int count=0;
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < 32; i++)
//	{
//		if (((n >> i) & 1) == 1)
//			count++;
//	}
//	printf("%d", count);
//	return 0;
//}












//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 32; i > 0; i-=2)
//	{
//		if (((n >> i-1) & 1) == 1)
//		{
//			printf("%d", 1);
//		}
//		else
//		{
//			printf("%d", 0);
//		}
//	}
//	printf("\n");
//	for (int i = 31; i >= 1; i-=2)
//	{
//		if (((n >> i-1) & 1 )== 1)
//		{
//			printf("%d", 1);
//		}
//		else
//		{
//			printf("%d", 0);
//		}
//	}
//}
//printf("%p\n", p);
//printf("%p\n", p + 1);
//printf("%p\n", pc);
//printf("%p\n", pc + 1);




//#include<stdio.h>
//int main()
//{
//    char arr[100];
//    gets_s(arr);
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    for (int i = sz - 1; i >= 0; i--)
//    {
//        if (arr[i] == ' ')
//        {
//            for (int j = i + 1;; j++)
//            {
//                if (arr[j] == ' ' || arr[j] == '\0')
//                    break;
//                printf("%c", arr[j]);
//
//            }
//            printf("%c", ' ');
//        }
//        if (i == 0)
//        {
//            for (int j = i;; j++)
//            {
//                if (arr[j] == ' ')
//                    break;
//                    printf("%c", arr[j]);
//
//            }
//        }
//    }
//    return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j <= n - i; j++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//        printf("*");
//        for (int i = 0; i < n; i++)
//        {
//            printf("\n");
//            for (int j = 0; j <= i + 1; j++)
//            {
//                printf("* ");
//            }
//
//
//        }
//    }
//}


//#include<stdio.h>
//#include<math.h>
//int fun(int x)
//{
//    int count=0;
//    while (x)
//    {
//        count++;
//        x = x / 10;
//    }
//    return count;
//}
//
//int main()
//
//{
//    int n = 1;
//   scanf("%d", &n);
//    int i = n;
//    while (i++)
//    {
//
//            int count = fun(i);
//            int s, t;
//            int sz = 1;
//            int add = 0;
//            for (int j = 1; j < count; j++)
//            {
//                sz = sz * 10;
//            }
//            s = i / sz;
//            t = i % 10;
//            
//
//            if (s == t)
//                continue;
//            s = s > t ? s : t;
//            sz = 1;
//            for (int m = 0; m <count; m++)
//            {
//                add = add + sz * s;
//                sz = sz * 10;
//            }
//            int ret = add > i ? add - i : i - add;
//            int flag = 0;
//            int z = ret % 10;
//            while (ret/10)
//            {
//                if (ret % 10 != s)
//                {
//                    flag = 1;
//                    break;
//                }
//            }
//            if (flag==0 || ret <10)
//            {
//                if (i % n == 0)
//                {
//                    printf("%d", i);
//                    break;
//                }
//                    
//            }
//            else
//                continue;
//    }
//}
//



//#include<stdio.h>
//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("%d %d ", a + b, c);
//	return 0;
//}

//
//#include<stdio.h>
//int main()
//{
//	int n = 2;
//	int arr[20][20] = { {1},{1,1} };
//	printf("%d\n%d %d\n",1, 1, 1);
//	while (n<20)
//	{
//		arr[n][0] = 1;
//		arr[n][n] = 1;
//		for (int i = 1; i < n; i++)
//		{
//			arr[n][i] = arr[n - 1][i - 1] + arr[n - 1][i];
//		}
//		for (int i = 0; i <= n; i++)
//		{
//			printf("%d ", arr[n][i]);
//		}
//		printf("\n");
//		n++;
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	for (int i = 'a'; i <= 'd';i++)
//	{
//		if ((i != 'a') + (i == 'c') + (i == 'd') + (i != 'd')==3)
//			printf("%c", i);
//	}
//	return 0;
//}


//#include<stdio.h>
//#include<time.h>
//#include<stdlib.h>
//int main()
//{
//	while (1)
//	{
//		srand((unsigned)time(NULL));
//		int a = rand() % 4 + 1;
//		int b = rand() % 4 + 1;
//		int c = rand() % 4 + 1;
//		int d = rand() % 4 + 1;
//		int e = rand() % 4 + 1;
//		while (a + b + c + d != 10)
//		{
//			int a = rand() % 4 + 1;
//			int b = rand() % 4 + 1;
//			int c = rand() % 4 + 1;
//			int d = rand() % 4 + 1;
//			int e = rand() % 4 + 1;
//		}
//		int ret1 = (b == 2) + (a == 3);
//		int ret2 = (b == 2) + (e == 4);
//		int ret3 = (c == 1) + (d == 2);
//		int ret4 = (c == 5) + (d == 3);
//		int ret5 = (e == 4) + (a == 1);
//		if (ret1 == 1 && ret2 == 1 && ret3 == 1 && ret4 == 1 && ret5 == 1)
//		{
//			printf("A:%d B:%d C:%d  D:%d  E:%d", a, b, c, d, e);
//			break;
//		}
//		return 0;
//
//	}
//	
//}


//#include<stdio.h>
//int main()
//{
//	int arr[3] = { 1,2,3 };
//	int* p = arr;  //接收首元素的地址   右边类型 ：int 类型   指针类型 ：指向int类型的指针
//	int(*p)[3] = &arr;   //接收数组的地址  右边的类型：整个数组的地址    指针类型：指向数组的指针
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//
//}


//#include<stdio.h>
//int main()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	if (*p == 1)
//		printf("小端存储");
//	if (*p == 0)
//		printf("大端存储");
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char a[1000];
//	int i;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//
//	}
//	printf("%d", strlen(a));
//	return 0;
//
//}

//#include<stdio.h>
//int main()
//{
//	int a = 9;
//	float* p = (float*)&a;
//	printf("%d\n", a);
//	printf("%f\n", *p);
//
//	*p = 9.0;
//	printf("%d\n", a);
//	printf("%f\n", *p);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int buy;
//	scanf("%d", &buy);
//	int empty=buy;
//	int total = buy;
//	while (empty>1)
//	{
//		
//		buy = empty / 2;
//		empty = empty / 2 + empty % 2;
//		total += buy;
//	}
//	printf("%d", total);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	int n;
//	int m;
//	scanf("%d", &n);
//	int i = 0;
//	int ret = 1;
//	for (i = 0; i < 3; i++)
//	{
//		if (arr[0][i] < n)
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				if (arr[2][i] < n)
//					break;
//				if (arr[j][i] == n)
//				{
//					printf("找到了 %d行 %d列", j+1, i + 1);
//					ret = 0;
//					break;
//				}
//			}
//		}
//		else
//		{
//			if (ret == 1)
//				printf("找不到！");
//		}
//		
//	}
//	
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int* p = (int*)(&arr + 1);
//	printf("%d %d", *(arr + 1), *(p - 1));
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	for (int a = 1; a <= 5; a++)
//	{
//		for (int b = 1; b <= 5; b++)
//		{
//			for (int c = 1; c <= 5; c++)
//			{
//				for (int d = 1; d <= 5; d++)
//				{
//					for (int e = 1; e <= 5; e++)
//					{
//						if ((b == 2) + (a == 3) == 1 && (b == 2) + (e == 4) == 1 && (c == 1) + (d == 2) == 1 && (c == 5) + (d == 3) == 1 && (e == 4) + (a == 1) == 1)
//						{
//							if (a * b * c * d * e == 120)
//							{
//								printf("ABCDE的名次分别为：%d %d %d %d %d",a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}

//#include<stdio.h>
//#include<string>
//void fun(char* p, int sz,int k)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left<right)
//	{
//		char temp = *(p + left);
//		*(p + left) = *(p + right);
//		*(p + right) = temp;
//		left++;
//		right--;
//	}
//	if (k > 0)
//	{
//		fun(p + sz - k, k, -1);
//		fun(p, sz - k, -1);
//	}
//
//
//}
//int main()
//{
//	char str[] = "abcdefg";
//	int sz = strlen(str);
//	int k;
//	scanf("%d", &k);
//	fun(str, sz,k);
//	printf("%s", str);
//	return 0;
//}

//#include<stdio.h>
//#include<string>
//int strmp(char* p1, char* p2, int sz)
//{
//	int ret = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		if (*(p1 + i) != *(p2 + i))
//			ret = 1;
//	}
//	return ret;//相等返回的是0 不相等返回的是1
//}
//void reverse(char* p1, int sz1)
//{
//	int left = 0;
//	int right = sz1 - 1;
//	while (left < right)
//	{
//		char temp = *(p1 + left);
//		*(p1 + left) = *(p1 + right);
//		*(p1 + right) = temp;
//		left++;
//		right--;
//	}
//}
//int fun(char* p1,char *p2, int sz1,int k)  //是 返回1 不是 返回0
//{
//	reverse(p1, sz1);
//	reverse(p1 + sz1 - k, k);
//	reverse(p1, sz1 - k);
//	return strmp(p1, p2, sz1);
//}
//
//int main()
//{
//	char s1[] = "abcdefz";
//	char s2[] = "bcedfzs";
//	int sz = strlen(s1);
//	int ret = 0;
//	for (int k = 1; k <= 5; k++)
//	{
//		if (fun(s1, s2, sz, k) == 0)
//		{
//			ret = 1;
//			break;
//		}
//	}
//	printf("%d", ret);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char a = -1;
//	unsigned int b = 1;
//	unsigned char c = -1;
//	int d = -1;
//	unsigned int e = 1;
//	printf("%d\n", a > b);
//	printf("%d\n", c > d);
//	printf("%d\n", c > e);
//	return 0;
//
//}

//#include<stdio.h>
//void test(char* arr[5])
//{
//	;
//}
//int main()
//{
//	int arr[3] = { 1,2,3 };
//	printf("%d", &arr);
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int sort(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//void print(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//}
//int main()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	qsort(arr, 10, 4, sort);
//	print(arr, 10);
//	return 0;
//}

//#include<stdio.h>
//#include<string>
//void bubble_qsort(void* p, int sz, int width, int (*pf)(const void*, const void*))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (pf((char*)p+width*j,(char *)p+width*(j+1) ) >= 0)     //a[j]   a[j+1]
//			{
//				for (int m = 0; m < width; m++)
//				{
//					char temp = *((char*)p + width * j + m);
//					*((char*)p + width * j + m) = *((char*)p + width * (j + 1) + m);
//					*((char*)p + width * (j + 1) + m) = temp;
//				}
//			}
//		}
//	}
//}
//struct stu {
//	int age;
//	char name[20];
//};
//int compare_int(const void* e1, const void*e2)
//{
//	return *((int*)e1) - *((int*)e2);
//}
//int my_strcmp(const void* e1, const void* e2)
//{
//	return strcmp(((struct stu *)e1)->name, ((struct stu*)e2)->name);
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	struct stu s[2] = { {30,"shabisssssssssss"},{20,"choushabi"} };
//	bubble_qsort(arr, 10, 4, compare_int);
//	bubble_qsort(s, sizeof(s) / sizeof(s[0]), sizeof(s[0]), my_strcmp);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 1;
//    int count = 0;
//    int L, R;
//    int ret = 1;
//    while (n / i != 0)
//    {
//        i = i * 10;
//        count++;
//    }
//    i = i / 10;
//    int left = 1;
//    int right = count;
//    while (left < right)
//    {
//        L = n / i;
//        R = n % 10;
//        if (L != R)
//        {
//            ret = 0;
//            break;
//        }
//        n = (n - L * i) / 10;
//        i /= 100;
//        left++;
//        right--;
//    }
//    printf("%d", ret);
//    return 0;
//
//}

//#include<stdio.h>
//int main()
//{
//    int m, n;
//    
//    while (scanf("%d %d", &m, &n) != EOF)
//    {
//        int ret = 1;
//        for (int i = m; i <= n; i++)
//        {
//            int j = i;
//            int count = 0;
//            for (int x = 0; x < 3; x++)
//            {
//                int c = 1;
//                for (int z = 0; z < 3; z++)
//                {
//                    c = (j % 10) * c;
//                }
//                count += c;
//                j = j / 10;
//            }
//            if (count == i)
//            {
//                printf("%d ", i);
//                ret = 0;
//            }
//        }
//        if (ret == 1)
//            printf("no");
//        printf("\n");
//    }
//    return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%p ----------- %p\n", &arr[i], p + i);
//	}
//	return 0;
//}
//


//#include<stdio.h>
//int main()
//{
//	int i = 0, j = 0;
//	for (i = 0; i < 6; i++)
//	{
//		for (j = 0; j < 6-i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		for (j = 0; j < 6 - i; j++)
//		{
//			printf(" ");
//		}
//		printf("\n");
//	}
//	printf("*************\n");
//	for (i = 0; i < 6; i++)
//	{
//		for (j = 0; j < i+1; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j <11-2*i ; j++)
//		{
//			printf("*");
//		}
//		for (j = 0; j < i+1; j++)
//		{
//			printf(" ");
//		}
//		printf("\n");
//	}
//
//}

//#include<stdio.h>
//#include<string>
//struct stu
//{
//	char name[20];
//	int age;
//};
//void bubble_sort(int* arr, int sz)
//{
//	int i, j;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//
//}
//void qsort_(void *p,int width,int sz,int (*pf)(void *e1,void *e2))
//{
//	int i, j;
//	for (i = 0; i < sz - 1 ; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (pf((char*)p + j * width, (char*)p + (j + 1) * width) > 0)
//			{
//				for (int m = 0; m< width; m++)
//				{
//					char temp = *((char*)p + j * width+m);
//					*((char*)p + j * width+m) = *((char*)p + (j + 1) * width+m);
//					*((char*)p + (j + 1) * width+m) = temp;
//				}
//			}
//		}
//	}
//
//}
//int sort_by_name(void *s1 ,void *s2)
//{
//	return strcmp(((struct stu*)s1)->name, ((struct stu*)s2)->name);
//	
//}
//int sort_by_age(void* s1, void* s2)
//{
//	return (((struct stu*)s1)->age) - (((struct stu*)s2)->age);
//}
//int main()
//{
//	struct stu s[2] = { {"wzngyiming",40},{"weizihan",22} };
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	bubble_sort(arr,sizeof(arr)/sizeof(arr[0]) );
//	qsort_(s, sizeof(s[0]), sizeof(s) / sizeof(s[0]), sort_by_name);
//	//qsort_(s, sizeof(s[0]), sizeof(s) / sizeof(s[0]), sort_by_age);
//}

//#include<stdio.h>
//void fun1(char *p,int k,int sz)
//{
//	for (int i = 0; i < k; i++)
//	{
//		char temp = p[0];
//		for (int j = 0; j < sz - 1; j++)
//		{
//			p[j] = p[j + 1];
//		}
//		p[sz - 1] = temp;
//	}
//
//}
//void reverse(char* p, int sz)
//{
//	int right = 0;
//	int left = sz - 1;
//	while (right < left)
//	{
//		char temp = p[right];
//		p[right] = p[left];
//		p[left] = temp;
//		left--;
//		right++;
//	}
//}
//void fun2(char arr[], int k,int sz)
//{
//	reverse(arr,k);
//	reverse(arr+k,sz-k);
//	reverse(arr,sz);
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int k = 3;
//	int sz = strlen(arr);
//	fun2(arr, k, sz);
//	return 0;
//}

//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
//
//#include<stdio.h>
//int match(char* p1, char* p2, int sz1)
//{
//	int ret = 1;
//	for (int i = 0; i < sz1; i++)
//	{
//		if (p1[i] != p2[i])
//		{
//			ret = 0;
//			break;
//		}
//	}
//	return ret;
//
//}
//int  fun1(char *p1,char *p2,int sz1,int sz2) //是 返回1  不是返回0
//{
//	int ret = 0;
//	if (sz1 != sz2)
//	{
//		return 0;
//	}
//	for (int k = 0; k <= sz1; k++)
//	{
//		for (int i = 0; i < k; i++)
//		{
//			char temp = p1[0];
//			for (int j = 0; j < sz1 - 1; j++)
//			{
//				p1[j] = p1[j + 1];
//			}
//			p1[sz1 - 1] = temp;
//		}
//		ret=match(p1, p2, sz1);  //相等返回1 
//		if (ret == 1)
//		{
//			return ret;
//			break;
//		}
//	}
//	return ret;
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	char brr[] = "bcdefgs";
//	int sz1 = strlen(arr);
//	int sz2 = strlen(brr);
//	printf("%d",fun1(arr, brr, sz1, sz2));
//
//}


//#include<stdio.h>
//int main()
//{
//    int k = 0;
//	while (scanf("%d", &k) != EOF)
//	{
//        int left = 1;
//        int right = k;
//        while (left <= right)
//        {
//            int count = 1;
//            for (int i = 0; i < k; i++)
//            {
//                if ((count == left) || (count == right))
//                {
//                    printf("*");
//                }
//                else
//                {
//                    printf(" ");
//                }
//                count++;
//            }
//            printf("\n");
//            left++;
//            right--;
//        }
//        //int count = 1;
//        if (k % 2 == 1)
//        {
//            int temp = left;
//            left = right;
//            right = temp;
//            while (left > 0)
//            {
//                int count = 1;
//
//                for (int i = 0; i < k; i++)
//                {
//                    if ((count == left) || (count == right))
//                    {
//                        printf("*");
//                    }
//                    else
//                    {
//                        printf(" ");
//                    }
//                    count++;
//                }
//                left--;
//                right++;
//                printf("\n");
//            }
//        }
//        else
//        {
//            left = k / 2;
//            right = k / 2 + 1;
//            while (left > 0)
//            {
//                int count = 1;
//                for (int i = 0; i < k; i++)
//                {
//                    if ((count == left) || (count == right))
//                    {
//                        printf("*");
//                    }
//                    else
//                    {
//                        printf(" ");
//                    }
//                    count++;
//                }
//                printf("\n");
//                left--;
//                right++;
//            }
//        }
//	}
//   
//
//}
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    int arr[50] = { 0 };
//    scanf("%d", &n);
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    scanf("%d", &arr[i]);
//    int x = 0;
//    int y = 0;
//    for (x = 0; x < n; x++)
//    {
//        for (y = 0; y < n - x; y++)
//        {
//            if (arr[y] > arr[y + 1])
//            {
//                int temp = arr[y];
//                arr[y] = arr[y + 1];
//                arr[y + 1] = temp;
//            }
//        }
//    }
//    for (int i = 0; i < n + 1; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//    int year;
//    int month;
//    scanf("%d%d", &year, &month);
//    switch (month)
//    {
//    case 1:
//        printf("31");
//        break;
//    case 2:
//        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//        {
//            printf("29");
//        }
//        else
//        {
//            printf("28");
//        }
//        break;
//    case 3:
//        printf("31");
//        break;
//    case 4:
//        printf("30");
//        break;
//    case 5:
//        printf("31");
//        break;
//    case 6:
//        printf("30");
//        break;
//    case 7:
//        printf("31");
//        break;
//    case 8:
//        printf("31");
//    case 9:
//        printf("30");
//        break;
//    case 10:
//        printf("31");
//        break;
//    case 11:
//        printf("30");
//        break;
//    case 12:
//        printf("31");
//        break;
//    }
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n, m;
//    scanf("%d%d", &n, &m);
//    int arr[10][10] = { 0 };
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            int temp = arr[i][j];
//            arr[i][j] = arr[j][i];
//            arr[j][i] = temp;
//        }
//    }
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char str1[] = "abcdef";
//	char str2[] = "abcdef";
//	const char* str3 = "abcdef";
//	const char* str4 = "abcdef";
//	if (str1 == str2)
//	{
//		printf("str1 str2地址相同\n");
//	}
//	else
//	{
//		printf("str1 str2地址不相同\n");
//	}
//	if (str3 == str4)
//	{
//		printf("str3 str4地址相同\n");
//	}
//	else
//	{
//		printf("str3 str4地址不相同\n");
//	}
//}

//
//#include<stdio.h>
//int main()
//{
//	int arr[2][3] = { 1,2,3,4,5,6 };
//	for (int i = 0; i <2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%p-----------%d\n", &arr[i][j],arr[i][j]);
//		}
//	}
//	printf("-----------------------\n");
//	int* p[2] = { arr[0],arr[1] };
//	for (int i = 0; i <2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%p-----------%d\n", &p[i][j],p[i][j]);
//		}
//	}
//	return 0;
//}


//#include<stdio.h>
//#include<string>
//int main()
//{
//
//	char s1[] = "abcdef\0sssssss";
//	char s2[] = "ef";
//	strncat(s1, s2, 5);
//	return 0;
//
//}
//
//#include<stdio.h>
//int my_strlen1(char* p)                 //正常的方法
//{
//	int count = 0;
//	while (*p++)
//	{
//		count++;
//	}
//	return count;
//}
//int my_strlen2(char* p)             //递归的方法
//{
//	if (*p)
//	{
//		return my_strlen2(p + 1) + 1;
//	}
//	return 0;
//}
//int my_strlen3(char* p)                //指针减指针的方法
//{
//	char* cp = p;
//	while (*cp++)
//	{
//		;
//	}
//	return cp - p - 1;
//}
//
//char* my_strcpy(char* p1,const char* p2)
//{
//	char* p = p1;
//	while (*p1++ = *p2++)
//	{
//		;
//	}
//	return p;
//}
//char* my_strncpy(char* p1, const char* p2,int n)
//{
//	char* p = p1;
//	for (int i = 0; i < n; i++)
//	{
//		if (*p2)
//		{
//			*p++ = *p2++;
//		}
//		else
//		{
//			*p++ = '\0';
//		}
//	}
//	return p1;
//}
//int main()
//
//{
//	char arr[] = "fuck you wzh";
//	char arr1[] = "wym";
//	//printf("%s", my_strcpy(arr, arr1));
//	///*my_strncpy(arr + 9, arr1, 3);
//	//printf("%s", arr);*/
//	printf("%d", my_strlen1(arr));
//	return 0;
//
//}

//#include<stdio.h>
//int strcmp(char *p1,char*p2)
//{
//	while ((*p1 == *p2)&&*p1)
//	{
//		p1++;
//		p2++;
//	}
//	if (*p1 > * p2)
//		return 1;
//	else if (*p1 < *p2)
//		return -1;
//	else
//		return 0;
//}
//int main()
//{
//	char a1[] = "abcdefg";
//	char a2[] = "abcdefzz";
//	printf("%d", strcmp(a1, a2));
//	return 0;
//}
//
//#include<stdio.h>
//char* my_strcat(char *p1,char *p2)
//{
//	char* p = p1;  //记住起始地址
//	while (*p1)
//	{
//		*p1++;
//	}
//	while (*p1++ = *p2++)
//	{
//		;
//	}
//	return p;
//}
//int main()
//{
//	char arr[20] = "fuck";
//	char arr2[] = " *you";
//	printf("%s", my_strcat(arr, arr2));
//	return 0;
//}


//Each of these functions returns a pointer to the first occurrence of strCha//rSet in string, or NULL if strCharSet does not appear in string. 
//If strCharSet points to a string of zero length, the function returns string.
//#include<stdio.h>
//#include<assert.h>
//char* my_strstr(char* p1, const char* p2)
//{
//	if (p2 == NULL)
//	{
//		return p1;
//	}
//	char* a = p1;
//	while (1)
//	{
//		const char* b = p2;
//		while (*a != *b)
//		{
//			a++;
//		}
//		char* c = a;
//		while (*c++ == *b++)
//		{
//			if (*c=='\0')
//			{
//				return NULL;
//			}
//			if (*b=='\0')
//				return a;
//		}
//	}
//
//
//}
//int main()
//{
//	char ar11[] = "acbcccbcccbcbbcb";
//	char ar22[] = "cbc";
//	printf("%s", my_strstr(ar11, ar22));
//	return 0;
//
//}



//void test1(int* arr)
//{
//
//}
//void test2(int* arr[5])
//{
//
//}
//void test3(int(*arr)[5])
//{
//
//}
//void test4(int** arr)
//{
//
//}
//
//int main()
//{
//	int arr[3][5] = { 0 };
//	test1(arr[1]+1);
//	test2(arr);         //错误
//	test3(arr);
//	test4(arr);        //错误
//}


//
//#include<stdio.h>
//#include<string>
//
//int main()
//{
//    int a[5][5];
//    int(*p)[4];
//    p =(int (*)[4]) a;
//    printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//    return 0;
//}

//#include<stdio.h>
//void* my_memcpy(void* dest, const void* sour, int num)
//{
//	void* pc = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)sour;
//		dest = (char*)dest + 1;
//		sour = (char*)sour + 1;
//	}
//	return pc;
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	char brr[] = "ssssss";
//	int a[] = { 1,2,3,4,5,6,7,7 };
//	int b[] = { 9,9,9,9,9,9 };
//	printf("%s", (char *)my_memcpy(arr, brr, 3));
//	void* c = my_memcpy(a, b, 20);
//	return 0;
//}

//#include<stdio.h>
//void* my_memmove(void* dest, void* sour, int num)
//{
//	void* pc = dest;
//	if (dest < sour)   //从前向后赋值
//	{
//	    while (num--)
//		{
//			*(char*)dest = *(char*)sour;
//			dest = (char*)dest + 1;
//			sour = (char*)sour + 1;
//		}
//	}
//	else                       //从后向前赋值
//	{
//		for (int i = num-1; i >= 0; i--)
//		{
//			*((char*)dest+i) = *((char*)sour+i);
//		}
//
//	}
//	return pc;
//}
//int main()
//{
//	char arr[] ="abcdefghssssssss";
//	my_memmove(arr + 3, arr + 1, 5);
//	printf("%s", arr);
//	scanf("%d");
//	return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//	const char* a[] = { "work","at","alibaba" };
//	const char** pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	return 0;
//}


//
//#include<stdio.h>
//int my_strlen1(char* p)                 //正常的方法
//{
//	int count = 0;
//	while (*p++)
//	{
//		count++;
//	}
//	return count;
//}
//int my_strlen2(char* p)             //递归的方法
//{
//	if (*p)
//	{
//		return my_strlen2(p + 1) + 1;
//	}
//	return 0;
//}
//int my_strlen3(char* p)                //指针减指针的方法
//{
//	char* cp = p;
//	while (*cp++)
//	{
//		;
//	}
//	return cp - p - 1;
//}
//
//char* my_strcpy(char* p1, const char* p2)
//{
//	char* p = p1;
//	while (*p1++ = *p2++)
//	{
//		;
//	}
//	return p;
//}
//char* my_strncpy(char* p1, const char* p2, int n)
//{
//	char* p = p1;
//	for (int i = 0; i < n; i++)
//	{
//		if (*p2)
//		{
//			*p++ = *p2++;
//		}
//		else
//		{
//			*p++ = '\0';
//		}
//	}
//	return p1;
//}
//int main()
//
//{
//	char arr[] = "fuck you wzh";
//	char arr1[] = "wym";
//	printf("%s\n", my_strcpy(arr, arr1));
//	//my_strncpy(arr + 9, arr1, 3);
//	printf("%s", arr);
//	/*printf("%d", my_strlen1(arr));*/
//	return 0;
//
//}
//
//#include<stdio.h>
//#include<string>
//int main()
//{
//	const char* str1 = "abcdef";
//	const char* str2 = "bbb";
//	if (strlen(str2) - strlen(str1)>0)
//	{
//		printf("str2>str1\n");
//	}
//	else
//	{
//		printf("str2<str1\n");
//	}
//	return 0;
//}
//
//#include<stdio.h>
//#include<assert.h>
//#include<string.h>
//char* my_strcpy(char* p1, const char* p2)
//{
//	char* p = p1;
//	while (*p1++ = *p2++)
//	{
//		;
//	}
//	return p;
//}
//char* my_strcat(char *p1,char *p2)
//{
//	char* p = p1;  //记住起始地址
//	while (*p1)
//	{
//		*p1++;
//	}
//	while (*p1++ = *p2++)
//	{
//		;
//	}
//	return p;
//}
//int my_strcmp(const char* str1, const char* str2)
//{
//	while ((*str1++ == *str2++)&&*str1&&*str2)
//	{
//		;
//	}
//	if (*str1 > * str2)
//	{
//		return 1;
//	}
//	else if (*str1 < * str2)
//	{
//		return -1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//char* my_strncpy(char* p1, const char* p2, int n)
//{
//	char* p = p1;
//	for (int i = 0; i < n; i++)
//	{
//		if (*p2)
//		{
//			*p++ = *p2++;
//		}
//		else
//		{
//			*p++ = '\0';
//		}
//	}
//	return p1;
//}
//char* my_strncat(char* p1, const char* p2, int num)
//{
//	assert(p2 && p1);
//	char* pc = p1;
//	while (*p1)
//	{
//		p1++;
//	}
//	for (int i = 0; i < num; i++)
//	{
//		if (*p1 = *p2)
//		{
//			p1++;
//			p2++;
//		}
//		else
//			return pc;
//	}
//	*p1 = '\0';
//	return pc;
//}
//int my_strncmp(char* p1, const char* p2, int num)
//{
//	assert(p1 && p2);
//	for (int i = 0; i < num; i++)
//	{
//		if (*p1 && *p2 && (*p1++ == *p2++));
//		else
//		{
//			if (*p1 > * p2)
//				return 1;
//			else if (*p1 < *p2)
//				return -1;
//			return 0;
//		}
//	}return 0;
//}
//const char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1!=NULL);
//	assert(p2 != NULL);
//	while (*p1 && *p2)
//	{
//		if (*p1 == *p2)
//		{
//			const char* a = p1;
//			const char* b = p2;
//			while (*a++ && *b++)
//			{
//				if (*a != *b)
//					break;
//				if (*a == *b && *(b+1) == 0)
//					return p1;
//			
//			}
//		}
//		p1++;
//	}
//	return NULL;
//}
//char* strtok1(char* str, const char* sep)
//{
//	static int ret = 0;//这个静态变量也十分重要！当指针指向最后一个 字符串str 出现的 sep字符分隔符，
//	//因为最后一段字符串并不会再出现sep中任何一个分隔符，所以字符串就不会打印，
//	//那我们如何区分这种情况和str中就从来没有出现过sep字符的情况，我们设置一个静态变量，如果静态变量被修改过，就输出字符串，如果没修改过就返回空指针。
//	static char* a = NULL;       //这里要用到静态变量，这样函数结束变量就不会销毁，a会记住上一次的地址
//	if (str != NULL)               // 判断是否为NULL
//
//	{
//		a = str;
//		ret = 0;
//	}
//	else
//	{
//		if (ret == 2)
//			return NULL;
//		a++;
//	}
//	char* first = a;
//	while (*a)
//	{
//		const char* p = sep;
//		while (*p)
//		{
//			if (*p == *a)
//			{
//				*a = '\0';
//				ret = 1;
//				return first;
//			}
//			p++;
//		}
//		a++;
//		if (*a == '\0')
//		{
//			ret = 2;
//			break;
//		}
//
//	}
//	if (ret == 0)
//		return NULL;
//	else if(ret == 2)
//		return first;
//}
//void* my_memcpy(void* destination, const void* source, size_t num)
//{
//	void* p = destination;
//	for (unsigned int i = 0; i < num; i++)
//	{
//		*(char*)destination = *(char*)source;
//		destination = (char*)destination + 1;
//		source = (char*)source + 1;
//	}
//	return p;
//}
//void* my_memmove(void* destination, const void* source, size_t num)
//{
//	void* p = destination;
//	if (destination > source) //从后向前拷贝
//	{
//		while (num--)
//		{
//			*((char*)destination + num) = *((char*)source + num);
//		}
//	}
//	else
//	{
//		for (int i = 0; i < num; i++)  //从前向后拷贝
//		{
//			*(char*)destination = *(char*)source;
//			destination = (char*)destination + 1;
//			source = (char*)source + 1;
//		}
//	}
//	return p;
//}
//int  my_memcmp(const void* ptr1, const void* ptr2, size_t num)
//{
//	int i = 0;
//	while (i++<num&&ptr1 && ptr2 && (*((char*)ptr1 + i) == *((char*)ptr2 + i)));
//	if (*((char*)ptr1 + i) > * ((char*)ptr2 + i))
//		return 1;
//	else if (*((char*)ptr1 + i) < *((char*)ptr2 + i))
//		return -1;
//	else
//		return 0;
//}
//int main()
//{
//	char a[] = "everything is simple";
//	char b[] = " ";
//	char c[] = "1345424480@qq.com";
//	char d[] = "@.";
//	char e[] = "aaaaaaaaaaaaaaa";
//	char f[] = " ";
//	
//	
//	
//	printf("%s\n", strtok(a, b));
//	printf("%s\n", strtok(NULL, b));
//	printf("%s\n", strtok(NULL, b));
//	printf("%s\n", strtok(NULL, b));
//	printf("%s\n", strtok(c, d));
//	printf("%s\n", strtok(NULL, d));
//	printf("%s\n", strtok(NULL, d));
//	printf("%s\n", strtok(NULL, d));
//	printf("%s\n", strtok(NULL, d));
//	printf("%s\n", strtok(e, f));
//	printf("%s\n", strtok(NULL, f));
//	printf("%s\n", strtok(NULL, f));
//	printf("%s\n", strtok(NULL, f));
//	
//	printf("__________________________\n");
//
//	/*printf("%s\n", strtok1(a, b));
//	printf("%s\n", strtok1(NULL, b));
//	printf("%s\n", strtok1(NULL, b));
//	printf("%s\n", strtok1(NULL, b));
//	printf("%s\n", strtok1(c, d));
//	printf("%s\n", strtok1(NULL, d));
//	printf("%s\n", strtok1(NULL, d));
//	printf("%s\n", strtok1(NULL, d));
//	printf("%s\n", strtok1(NULL, d));
//	printf("%s\n", strtok1(e, f));
//	printf("%s\n", strtok1(NULL, f));
//	printf("%s\n", strtok1(NULL, f));
//	printf("%s\n", strtok1(NULL, f));
//	
//	*/
//	
//	
//	
//	
//	
//	
//	
//	
//	
//	
//	
//	/*char a[] = "abc";
//	char b[] = "ab";
//	char* p = NULL;
//	char* c = NULL;
//	my_strncat(p, c, 1);*/
//	return 0;
//	
//	
//	
//	
//	
//	
//	
//	return 0;
//
//
//}

//#include<stdio.h>
//#include<string.h>
//#include<errno.h>
//int main()
//{
//	FILE* pFILE;
//	pFILE = fopen("unexist.ent", "r");
//	if (pFILE == NULL)
//		printf("Error opening file unexist.ent: %s\n", strerror(errno));
//	return 0;
//}

//
//#include<stdio.h>
//#include<ctype.h>
//int main()
//{
//	char arr[] = "abBBsjJSBHdlDLKDjdef";
//	char c;
//	int i = 0;
//	while (arr[i])
//	{
//		c = arr[i];
//		if (isupper(arr[i]))
//			c = tolower(arr[i]);
//		putchar(c);
//		i++;
//	}
//	return 0;
//}

//
//#include<stdio.h>
//#include<string>
//int main()
//{
//	printf("%s\n", strerror(0));
//	printf("%s\n", strerror(1));
//	printf("%s\n", strerror(2));
//	printf("%s\n", strerror(3));
//	printf("%s\n", strerror(4));
//	printf("%s\n", strerror(5));
//	printf("%s\n", strerror(6));
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//    int i = 0;
//    printf("Hello world!");
//    printf("\n");
//    printf("%d", i);
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    printf("The size of short is %d bytes.", sizeof((short)1));
//    printf("The size of int is %d bytes.", sizeof((int)1));
//    printf("The size of long is %d bytes.", sizeof((long)1));
//    printf("The size of long long is %d bytes.", sizeof((long long)1));
//    return 0;
//}
//#include<stdio.h>
//int judg(long long  x)
//{
//    int s, t;
//    t = x % 10;
//    while (t == x % 10)
//    {
//        x = x / 10;
//    }
//    if (x == 0)
//        return 0;
//    s = x % 10;
//    while (s == x % 10)
//    {
//        x = x / 10;
//    }
//    if (s == t)
//        return 0;
//    if (x == 0)
//        return 1;
//    else
//        return 0;
//}
//int main()
//{
//    long long  n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        long long i = n;
//        while (i++)
//        {
//            int ret = judg(i);  //是二段数返回1
//            if (ret == 1)
//            {
//                if (i % n == 0)
//                {
//                    printf("%lld: %lld\n", n, i);
//                    break;
//                }
//            }
//        }
//    }
//    return 0;
//}
//#include<stdio.h>
//struct s1
//{
//	char c1;
//	int i;
//	char c2;
//};
//struct s2
//{
//	char c1;
//	char c2;
//	int i;
//};
//int main()
//{
//	printf("s1的大小位：%d\n",sizeof(s1));
//	printf("s2的大小位：%d\n", sizeof(s2));
//	return 0;
//}


//
//#include<stdio.h>
//struct s1
//{
//	char c1;
//	int i;
//	char c2;
//};
//struct s3
//{
//	char a;
//	struct s1 s;
//	int b;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct s1));
//	printf("%d\n", sizeof(struct s3));
//	return 0;
//}


//
//
//struct s
//{
//	int data[1000];
//	int num;
//};
//struct s b = { {0},100 };
//void print1(struct s b);
//void print2(struct s* ps);
//int main()
//{
//	print1(b);  //传结构体
//	print2(&b); //传地址
//	return 0;
//}

//
//#include<stdio.h>
//int main()
//{
//    int n;
//    while (scanf("%d", &n) != EOF)
//    {
//        int left = 1;
//        int right = n;
//        while (left <= n)
//        {
//            for (int i = 1; i <= n; i++)
//            {
//                if (i == left || i == right)
//                    printf("*");
//                else
//                    printf(" ");
//            }
//            printf("\n");
//            left++;
//            right--;
//        }
//        printf("\n");
//    }
//    return 0;
//}

//

//
//#include<stdio.h>
//struct student
//{
//	int c1;
//	char c2;
//};
//
//int check(void)
//{
//	union u 
//	{
//		char a;
//		int i;
//	};
//	union u x;
//	x.i = 1;
//	return x.a;
//}
//int main()
//{
//	struct student a = { 5,'c' };
//	struct student b = a;
//	//printf("%d", b.c1);
//	int ret = check();
//	if (ret == 1)
//		printf("小段存储");
//	else
//		printf("大端存储");
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 5;
//	printf("%5d\n", a);
//	printf("%.5d\n", a);
//	printf("%05d\n", a);
//	printf("%-5d\n", a);
//	printf("%-05d\n", a);
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//#define pages 336
//#define words 65618
//{
//	short num = pages;        //0000 0001 0101 0000
//	short mnum = -pages;      //1111 1110 1011 0000
//	printf("num as short and unsigned short:%hd %hu\n",num,num);  //0000 0001 0101 0000
//	printf("mnum as short and unsigned short:%hd %hu\n",mnum,mnum);  //1111 1110 1011 0000  
//	printf("num as int and char %d %c\n", num, num);  //1111 1111 1111 1111 1111 1110 1011 0000 和 0101 0000=80 查ASCII码对照表可知结果
//	printf("words as int ,short ,char:%d,%hd,%c", words, words, words);
//	return 0;
//
//}
////如果要用%d打印就要发生整型提升,二进制位会提升为32位，规则为有符号补符号位，无符号补零
////1111 1111 1111 1111 1111 1110 1011 0000
////1000 0000 0000 0000 0000 0001 0101 0000
//
////words
////%d 0000 0000 0000 0001 0000 0000 0101 0010
////%hd  0000 0000 0101 0010

//#include<stdio.h>
//int main()
//{
//	float n1 = 3.0;
//	double n2=3.0;
//	long n3 = 2000000000;
//	long n4 = 1234567890;
//	printf("%.le %.le %.le %.le\n", n1, n2, n3, n4);
//	printf("%ld %ld \n", n3, n4);
//	printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);
//	return 0;
//}
//
//#include<stdio.h>
//struct A
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//struct A a = { 0 };
//int main()
//{
//	a.a = 10;
//	a.b = 12;
//	a.c = 5;
//	a.d = 4;
//	return 0;
//}
//
//#include<stdio.h>
//
//
//
//
//
//
//int main()
//{
//	char a = '9';
//	int b = a;
//	printf("%d", b);
//	return 0;
//
//}
//
//#include<stdio.h>
//int atoi(const char* str)
//{
//	long long int sum = 0;   //数字总和
//	int b = 0; //接收每一个数字
//	int MIN = -2147483648;
//	int MAX = 2147483647;
//	const char* p = str;
//	int ret = 0;
//	while (*p == ' ')
//	{
//		p++;
//	}
//	if (*p == '+')
//	{
//		p++;
//	}
//	else if (*p == '-')
//	{
//		ret = 1;
//		p++;
//	}
//	else if (*p < '0' && *p > '9')
//	{
//		return 0;
//	}
//	while (*p >= '0' && *p <= '9')
//	{
//		b = *p - '0';
//		if (ret == 0)
//			sum = sum * 10 + b;
//		else
//			sum = sum * 10 - b;
//		
//		if (sum < MAX && sum >MIN )
//		{
//			p++;
//		}
//		else
//		{
//			if (sum > 0)
//				return MAX;
//			else
//				return MIN;
//		}
//	}
//	return sum;
//
//}
//int main()
//{
//	char a[20];
//	scanf("%s", a);
//	printf("%d",atoi(a));
//	return 0;
//}

//
//#include<stdio.h>
//char* my_strncpy(char* p1, const char* p2, int n)
//{
//	char* p = p1;
//	for (int i = 0; i < n; i++)
//	{
//		if (*p2)
//		{
//			*p++ = *p2++;
//		}
//		else
//		{
//			*p++ = '\0';
//		}
//	}
//	return p1;
//}
//char* my_strncat(char* p, const char* p2, int num)
//{
//	char* p1 = p;
//	while (*p1++ != '\0');
//	p1--;
//	for (int i = 0; i < num; i++)
//	{
//		*p1++ = *p2++;
//		if (*p2 == '\0')
//		{
//			*p1 = '\0';
//			return p;
//		}
//	}
//	return p;
//}
//int main()
//{
//	char a[20] = { 0 };
//	const char* b = "akskkfk";
//	printf("%s",my_strncat(a, b, 3));
//	return 0;
//}

//
//#include<stdio.h>
//void find(int* p,int sz)
//{
//
//	for (int i = 0; i < sz; i++)
//	{
//		int ret = 0;
//		for (int j = 0; j < sz; j++)
//		{
//			if (i == j)
//				continue;
//			if (p[i] == p[j])
//			{
//				ret = 1;
//				break;
//			}
//
//		}
//		if (ret == 0)
//			printf("%d\n ", p[i]);
//	}
//
//
//}
//int main()
//{
//	int arr[12] = { 1,1,3,5,0,4,6,2,4,3,6,5 };
//	find(arr, sizeof(arr) / sizeof(arr[0]) );
//
//	return 0;
//}

enum DAY
{
	MON,
	TUES,
	WED,
	THUR,
	FRI,
};
//
//enum color
//{
//	BLUE=1,
//	YELLOW=2,
//	GREEN
//};
//int main()
//{
//	enum color b = BLUE;
//	b = 5;
//}

//
////联合体类型的声明
//union un
//{
//	char c;
//	int i;
//};
////联合变量的定义
//union un n;
////计算联合体变量的大小
//printf("%d", sizeof(un));
//

//#include<stdio.h>
//union un
//{
//	int i;
//	char c;
//};
//union un n;
//int main()
//{
//	printf("%p\n", &(n.c));
//	printf("%p\n", &(n.i));
//
//	n.i = 0x10223344;
//	n.c = 0x20;
//	printf("%x\n", n.i);
//}

//
//#include<stdio.h>
//union un
//{
//	int i;
//	char c;
//};
//union un n;
//int main()
//{
//	n.i = 1;
//	if (n.c == 0)
//		printf("大端存储");
//	else
//		printf("小段存储");
//}
//
//#include<stdio.h>
//union i
//{
//	char b[5];
//	int i;
//};
//
//int main()
//{
//	printf("%d", sizeof(union i));
//}
//
////向文件中输入数字
//#include<stdio.h>
//int main()
//{
//	FILE* p = fopen("D:\\学习资料\\比特教育\\源代码\\Project1\\test.txt", "w");
//	if (p == NULL)
//	{
//		printf("读入失败");
//		return 0;
//	}
//	fputs("abcdef\n", p);
//	fputs("ejejejjej\n", p);
//	fclose(p);
//}
//
//
//#include<stdio.h>
//int main()
//{
//	FILE* p = fopen("D:\\学习资料\\比特教育\\源代码\\Project1\\test.txt", "r");
//	if (p == NULL)
//	{
//		printf("读入失败");
//		return 0;
//	}
//	char a[20];
//	fgets(a, 4, p);
//	printf(a);
//
//	fgets(a, 4, p);
//	printf(a);
//
//	fclose(p);
//
//}
//
//#include<stdio.h>
//int main()
//{
//	int a = 3;
//	char b[5] = { 1,2,3 };
//}

//
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int* ptr = (int*)malloc(num * sizeof(int));
//	if (ptr == NULL)
//		printf("开辟失败");
//	else
//	{
//		for (int i = 0; i < num; i++)
//		{
//			ptr[i] = i;
//		}
//	}
//	free(ptr);
//	ptr = NULL;
//}

//
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		printf("开辟内存失败");
//	}
//	else
//	{
//		//使用空间
//	}
//	free(p);
//	p = NULL;
//	return 0;
//	void* realloc(void* ptr, size_t size);
//}


//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int* ptr = (int *)realloc(NULL, 100);
//	if (ptr == NULL)
//		printf("开辟失败");
//	else
//	{
//		//扩容方法一
//		ptr = (int *)realloc(ptr, 100);
//		//扩容方法二
//		int* p = NULL;
//		p = (int*)realloc(ptr, 100);
//		if (p != NULL)
//			ptr = p;
//		free(ptr);
//		ptr = NULL;
//	}
//}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//
//void main()
//{
//	int* p = (int*)malloc(100);
//	*p = 4;
//	free(p);
//	p = NULL;
//}
//
//void main()
//{
//	int* p = (int*)malloc(10*sizeof(int));
//	if (p != NULL)
//	{
//		for (int i = 0; i < 10; i++)
//		{
//			*p++ = i;
//		}
//	}
//	free(p);
//	p = NULL;
//}



//void main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	free(p);//p=NULL;
//	free(p);
//}

//void test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL != p)
//		*p = 20;
//}
//void main()
//{
//	while (1)
//	{
//		test();
//	}
//}
//
//void Getmemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void main()
//{
//	char* str = NULL;
//	Getmemory(&str);
//	strcpy(str, "helloworld");
//	printf(str);
//}
//
//char* Getmemory(void)
//{
//	char *p = (char*)malloc(100);
//	strcpy(p, "kksk");
//	return p;
//}
//void main()
//{
//	char* str = NULL;
//	str = Getmemory();
//	printf(str);
//}

//
//void main()
//{
//	char* p = (char*)malloc(100);
//	strcpy(p, "kksk");
//	free(p);
//	if (p != NULL)
//	{
//		strcpy(p, "kksk");
//		printf(p);
//	}
//
//}

//typedef struct s
//{
//	int i;
//	int a[0];//柔性数组成员
//}s;

//
//typedef struct st_type
//{
//	int i;
//	int a[];//柔性数组成员
//}type_a;
//
//struct s
//{
//	int i;
//	int* arr;
//};
//
//int main()
//{
//	struct s* p = (struct s*)malloc(sizeof(struct s));
//	if (p == NULL)
//		printf("开辟失败");
//	else
//	{
//		p->i = 10;
//		int* pc = (int*)malloc(10 * sizeof(int));
//		if (pc != NULL)
//		{
//			p->arr = pc;
//			for (int i = 0; i < 10; i++)
//			{
//				*(p->arr + i) = i;
//			}
//		}
//		free(pc);
//		pc = NULL;
//	}
//
//	free(p);
//	p = NULL;
//}
//
//int main()
//{
//	FILE* pf;
//	pf = fopen("D:\\学习资料\\比特教育\\源代码\\Project1\\Project1\\kksk.txt", "r");
//	if (pf != NULL)
//	{
//		
//		printf("打开文件成功\n");
//
//		int ret = 0;
//
//
//		printf("%d\n", fputc(50, pf));
//
//		/*ret = fgetc(pf);
//		printf("%c\n", ret);
//
//		ret = fgetc(pf);
//		printf("%c\n", ret);
//
//		ret = fgetc(pf);
//		printf("%c\n", ret);
//
//		ret = fgetc(pf);
//		printf("%c\n", ret);
//
//		ret = fgetc(pf);
//		printf("%c\n", ret);*/
//
//
//		fclose(pf);
//	}
//	return 0;
//}


//
//struct s
//{
//	int i;
//	char b;
//	char d[20];
//};
//int main()
//{
//	struct s a = { 10,'c',"sfdfqwdqd"};
//	struct s c = { 0 };
//	FILE* pf;
//	pf = fopen("D:\\学习资料\\比特教育\\源代码\\Project1\\Project1\\kksk.txt", "r");
//	if (pf != NULL)
//	{
//
//		printf("打开文件成功\n");
//		/*fwrite(&a, sizeof(struct s), 1, pf);*/
//		fread(&c, sizeof(struct s), 1, pf);
//		printf("%d %c %s", c.i, c.b, c.d);
//		fclose(pf);
//	}
//	return 0;
//}

//
//struct S
//{
//	int a;
//	char b;
//	char c[20];
//};
//int main()
//{
//	struct S m = { 10,'c',"ssssssssssss" };
//	struct S n = { 0 };
//	char buffer[100];
//	sprintf(buffer, "%d %c %s", m.a, m.b, m.c);
//	printf("%s\n",buffer);
//	sscanf(buffer, "%d %c %s", &(n.a), &(n.b), n.c);
//	printf("%d %c %s", n.a, n.b, n.c);
//
//}

//
//
//struct s
//{
//	int i;
//	char b;
//	char d[20];
//};
//int main()
//{
//	struct s a = { 10,'c',"sfdfqwdqd"};
//	struct s c = { 0 };
//	FILE* pf;
//	pf = fopen("D:\\学习资料\\比特教育\\源代码\\Project1\\Project1\\kksk.txt", "r");
//	if (pf != NULL)
//	{
//
//		printf("打开文件成功\n");
//		/*fwrite(&a, sizeof(struct s), 1, pf);*/
//		while(fread(&c, sizeof(struct s), 1, pf));
//		printf("%d %c %s", c.i, c.b, c.d);
//		fclose(pf);
//	}
//	return 0;
////}
//int* singleNumbers(int* nums, int numsSize, int* returnSize) {
//    int x = 0;
//    int pos = 0;
//    int a = 0;
//    int b = 0;
//    int* arr = (int*)malloc(2 * sizeof(int));
//    for (int i = 0; i < numsSize; i++)
//    {
//        x = x ^ nums[i];
//    }
//    for (int i = 1;; i++)
//    {
//        if (((x >> i) & 1) == 1)
//        {
//            pos = i;
//            break;
//        }
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (((nums[i] >> pos) & 1) == 1)
//        {
//            a = a ^ nums[i];
//        }
//        else
//        {
//            b = b ^ nums[i];
//        }
//    }
//    arr[0] = a;
//    arr[1] = b;
//    *returnSize = 2;
//    return arr;
//}
//int main()
//{
//    int arr[8] = { 7,1,7,2,6,6,3,1 };
//    int returnSize = 0;
//    int* p = singleNumbers(arr, 8,&returnSize );
//    for (int i = 0; i < returnSize; i++)
//    {
//        printf("%d,", p[i]);
//    }
//    return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//#define N 100;
//int main()
//{
//	int b = N    //等价于
//	int b = 100;
//
//
//	int c = N + 1;// 这就是错误的了
//	//等价于 int c = 100; +1;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#define N 100;
//#define offsetof(a,b) (char*)a-(char*)b
//struct s
//{
//	int a;
//	char b;
//};
//int main()
//{
//	struct s m = { 0 };
//	printf("%d", offsetof(&m, &(m.b)));
//	return 0;
//}


//
//#define fun(a,b) ((a)>(b)?(a):(b))
//
//int main()
//{
//	int x = 5;
//	int y = 8;
//	int z = fun(x++, y++);
//	printf("%d %d %d",x,y, z);
//	return 0;
//}

#include<stdio.h>
#pragma once
//#define Malloc(p,type) malloc(2*sizeof(type))
//int main()
//{
//	int* pf = (int*)Malloc(pf,int);
//	if (pf == NULL)
//	{
//		perror("malloc");
//		return 0;
//	}
//	for (int i = 0; i < 2; i++)
//	{
//		pf[i] = i;
//	}
//	free(pf);
//	pf = NULL;
//	return 0;
//}
//
//void rotate(int* nums, int numsSize, int k) {
//    k = k % numsSize;
//    int* left = nums;
//    int* right = nums + numsSize - 1;
//    while (left < right)
//    {
//        int temp;
//        temp = *left;
//        *left = *right;
//        *right = temp;
//        left++;
//        right--;
//
//    }
//    left = nums;
//    right = nums + k - 1;
//    while (left < right)
//    {
//        int temp;
//        temp = *left;
//        *left = *right;
//        *right = temp;
//        left++;
//        right--;
//
//    }
//    left = nums + k;
//    right = nums + numsSize - 1;
//    while (left < right)
//    {
//        int temp;
//        temp = *left;
//        *left = *right;
//        *right = temp;
//        left++;
//        right--;
//    }
//
//}
//int main()
//{
//    int arr[4] = { -1,-100,3,99 };
//    rotate(arr, 4, 2);
//    return 0;
//}
//int removeElement(int* nums, int numsSize, int val) {
//    int* sear = nums;
//    int k = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (sear[i] != val)
//        {
//            *nums = *sear;
//            nums++;
//            k++;
//        }
//    }
//    return k;
//}
//int removeDuplicates(int* nums, int numsSize) {
//    int* pc = nums;
//    int* sear = nums;
//    int k = 1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (*pc != sear[i])
//        {
//            pc++;
//            *pc = sear[i];
//            k++;
//
//        }
//    }
//    return k;
//
//}
//int main()
//{
//    int arr[8] = { 0,0,1,2,2,3,3,4};
//    int ret = removeDuplicates(arr, 8);
//    for (int i = 0; i < ret; i++) {
//        printf("%d", arr[i]);
//    }
//}
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//    int* pc = (int*)malloc(nums1Size * sizeof(int));
//    int* p1 = nums1;
//    int* p2 = nums2;
//    int j = 0;
//    while ((p1 - nums1 < m) && (p2 - nums2 < n))
//    {
//        if (*p1 >= * p2)
//        {
//            *(pc+j) = *p2;
//            p2++;
//            j++;
//        }
//        else
//        {
//            *(pc+j) = *p1;
//            p1++;
//            j++;
//        }
//    }
//    while ((p2 - nums2 < n))
//    {
//        *(pc + j) = *p2;
//        p2++;
//        j++;
//    }
//    while (p1 - nums1 < m)
//    {
//        *(pc + j) = *p1;
//        p1++;
//        j++;
//    }
//    for (int i = 0; i < nums1Size; i++)
//    {
//        nums1[i] = pc[i];
//    }
//    free(pc);
//}
//int main()
//{
//    int nums1[2] = { 2,0 };
//    int nums2[1] = { 1 };
//    merge(nums1, 2, 1, nums2, 1, 1);
//    return 0;
//}

//void SListPushFront(SLTNode** pphead, SLRDataType x)
//{
//	SLTNode* p = (SLTNode *)malloc(sizeof(SLTNode));
//	p->x = x;
//	p->next = *pphead;
//	*pphead = p;
//}

//
//
//#include"Seqlist.h"
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//
//
//
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* tail = head;
//    while (tail != NULL)
//    {
//        if (tail->next->val == val)
//        {
//            tail->next = tail->next->next;
//            free(tail->next);
//            tail->next = NULL;
//
//        }
//        tail = tail->next;
//    }
//
//    return head;
//
//}
//int main()
//{
//
//}



//long long Fib(int N)
//{
//	if (N < 3)
//		return 1;
//	return Fib(N - 1) + Fib(N - 2);
//}
//
//void fun(int N)
//{
//	int count = 0;
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			++count;
//		}
//	}
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d", count);
//}

//
//void fun(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < M; ++k)
//	{
//		++count;
//	}
//	for (int k = 0; k < N; ++k)
//	{
//		++count;
//	}
//}


//
//void fun(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < 1000; ++k)
//	{
//		++count;
//	}
//}
//
//#include<assert.h>
//
//void fun(int *a, int n)
//{
//	for (int i = 0; i < n ; i++)
//	{
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (a[j] < a[j + 1])
//			{
//				int temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//		}
//	}
//
//}
//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//	int left = 0;
//	int right = n - 1;
//	while (left != right)
//	{
//		int mid = (left + right) / 2;
//		if (x > a[mid])
//		{
//			left = mid + 1;
//		}
//		else if (x < a[mid])
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid+1;
//		}
//		return -1;
//	}
//
//}

//
//long long fun(size_t N)
//{
//	if (0 == N)
//		return 1;
//	return fun(N - 1) * N;
//}
//
//long long Fib(size_t N)
//{
//	if (N < 3)
//	{
//		return 1;
//	}
//	return Fib(N - 1) + Fib(N - 2);
//}
//
//long long Fac(size_t N)
//{
//	if (N == 0)
//		return 1;
//	return Fac(N - 1) * N;
//}
//
//
//int main()
//{
//	int a[5] = { 1,2,4,5,8 };
//	fun(a, 5);
//	BinarySearch(a, 5, 4);
//	return 0;
//}

//
//#include<stdio.h>
//#define N 15
//void fun(int b[], int n, int m)
//{
//	int i, j;
//	for (i = m; i >= n; i--)
//		b[i + 1] = b[i];
//}
//int main()
//{
//	/*int a[3] = { 1,2,3 };
//	int* p = a;
//	a = a + 1;
//	printf("%d", *a);*/
//	int i, a[N] = { 1,2,3,4,5,6,7,8,9,10 };
//	fun(a, 1, 9);
//	for (i = 0; i < 5; i++)
//		printf("%d", a[i]);
//	return 0;
//
//}

//
//#include<stdio.h>
//void fun(int a[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		int k = i;
//		for (int j = i + 1; j < n; j++)
//		{
//			if (a[k] > a[j])
//				k = j;
//		}
//		if (k != i)
//		{
//			int t = a[i];
//			a[i] = a[k];
//			a[k] = t;
//
//		}
//	}
//}
//int main()
//{
//	int a[5] = { 9,0,1,5,6 };
//	fun(a, 5);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	/*int i = 5;
//	while (i = 0)
//		i--;
//	printf("%d", i);
//	return 0;*/
//	int x, y;
//	int a = 0, b = 1, c = 2;
//	float f;
//	scanf("%.2f", &f);
//	printf("%d", a || (b + b) && (c - a));
//	printf("%d", a && b);
//	printf("%d", !a);
//}
//
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int a = 1, b = 4, c = 2;
//	float x = 10.5, y = 4.0, z;
//	z = (a + b) / c + sqrt((double)y) * 1.2 / c + x;
//	int a = 5;
//	float b = 2.00, c;
//	c = a / b;
//
//}


//
//#include<stdio.h>
//int main()
//{
//	int a = 100, x = 10, y = 20, ok1 = 5, ok2 = 0;
//	if (x < y)
//		if (y != 10)
//			if (!ok1)
//				a = 1;
//			else
//				if (ok2)
//					a = 10;
//	a = -1;
//	printf("%d", a);
//	return 0;
//}

//
//
//
//#include<stdio.h>
//int main()
//{
//	for (int i = 100; i <= 200; i++)
//	{
//		int k = 0;
//		for (int j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				k = 1;
//				break;
//			}
//
//		}
//		if (k == 0)
//			printf(" %d ", i);
//	}
//	return 0;
//}

//
//#include<stdio.h>
//int main()
//{
//    int k = 0;
//    scanf("%d", &k);
//    int a[30][30] = { 0 };
//    for (int i = 0; i < k; i++)
//    {
//        for (int j = 0; j < i + 1; j++)
//        {
//            if (j == 0 || j == i)
//            {
//                a[i][j] = 1;
//            }
//            else
//            {
//                a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
//            }
//        }
//    }
//    for (int i = 0; i < k; i++)
//    {
//        for (int j = 0; i < i + 1; j++)
//        {
//            printf("%5d", a[i][j]);
//        }
//        printf("\n");
//    }
//}


//
//
//#include<stdio.h>
//int main()
//{
//	/*int i = 0;
//	while (i++ <= 10);
//	printf("%d", i);
//	return 0;*/
//	int x = 0, s = 0;
//	while (!x != 0)
//		s += ++x;
//	printf("%d", s);
//}

//
//typedef struct ListNode
//{
//    int x;
//    struct ListNode* next;
//}ListNode;
//
//typedef struct Queue
//{
//    ListNode* head;
//    ListNode* tail;
//}Queue;
//
//typedef struct {
//    Queue *q1;
//    Queue *q2;
//
//} MyStack;
//
///** Initialize your data structure here. */
//void CheckEmpty(Queue** x, Queue** y)
//{
//    if ((*x)->head == NULL)
//    {
//        Queue* temp = *x;
//        *x = *y;
//        *y = temp;
//    }
//    return;
//
//}
//
//MyStack* myStackCreate() {
//    MyStack* p = (MyStack*)malloc(sizeof(MyStack));
//
//    p->q1 = (Queue*)malloc(sizeof(Queue));
//    p->q1->head = p->q1->tail = (ListNode*)malloc(sizeof(ListNode));
//    p->q1->tail->next = NULL;
//
//    p->q2 = (Queue*)malloc(sizeof(Queue));
//    p->q2->head = p->q2->tail = (ListNode*)malloc(sizeof(ListNode));
//    p->q2->tail->next = NULL;
//    return p;
//}
//
///** Push element x onto stack. */
//void myStackPush(MyStack* obj, int x) {
//
//    CheckEmpty(&(obj->q1), &(obj->q2));
//
//    obj->q1->tail->x = x;
//
//    obj->q1->tail->next = (ListNode*)malloc(sizeof(ListNode));
//    obj->q1->tail = obj->q1->tail->next;
//    obj->q1->tail->next = NULL;
//
//    //obj->q2->tail->next=(ListNode*)malloc(sizeof(ListNode));
//    //obj->q2->tail=obj->q2->tail->next;
//    //obj->q2->tail->next=NULL;
//
//}
//
///** Removes the element on top of the stack and returns that element. */
//int myStackPop(MyStack* obj) {
//
//    while (obj->q1->head->next->next)
//    {
//        if(obj->q2->head==NULL)
//            obj->q2->head =obj->q2->tail= (ListNode*)malloc(sizeof(ListNode));
//        obj->q2->tail->x = obj->q1->head->x;
//        ListNode* temp = obj->q1->head->next;
//        free(obj->q1->head);
//        obj->q1->head = temp;
//        obj->q2->tail->next = (ListNode*)malloc(sizeof(ListNode));
//        obj->q2->tail = obj->q2->tail->next;
//        obj->q2->tail->next = NULL;
//    }
//    int k = obj->q1->head->x;
//    free(obj->q1->head);
//    obj->q1->head = obj->q1->tail = NULL;
//    CheckEmpty(&(obj->q1), &(obj->q2));
//    return k;
//}
//
///** Get the top element. */
//int myStackTop(MyStack* obj) {
//
//    CheckEmpty(&(obj->q1), &(obj->q2));
//    return obj->q1->tail->x;
//}
//
///** Returns whether the stack is empty. */
//bool myStackEmpty(MyStack* obj) {
//    CheckEmpty(&(obj->q1), &(obj->q2));
//    if ((obj->q1->tail->next == NULL) && (obj->q2->tail->next == NULL))
//    {
//        return true;
//    }
//    return (obj->q1->tail == NULL);
//}
//
//void myStackFree(MyStack* obj) {
//    CheckEmpty(&(obj->q1), &(obj->q2));
//    while (obj->q1->head)
//    {
//        ListNode* temp = obj->q1->head->next;
//        free(obj->q1->head);
//        obj->q1->head = temp;
//    }
//
//}
//
//int main()
//{
//    MyStack *ps;
//    ps=myStackCreate();
//    int ret=myStackEmpty(ps);
//   /* myStackPush(ps, 1);
//    myStackPush(ps, 2);
//    int ret=myStackTop(ps);*/
//
//   /* myStackPop(ps);
//    myStackPush(ps, 2);
//    myStackPush(ps, 3);
//    myStackPush(ps, 4);
//    myStackPop(ps);
//    myStackPop(ps);
//    myStackPop(ps);
//    myStackPop(ps);
//    int ret = myStackEmpty(ps);
//    myStackFree(ps);*/
//}
//
///**
// * Your MyStack struct will be instantiated and called as such:
// * MyStack* obj = myStackCreate();
// * myStackPush(obj, x);
//
// * int param_2 = myStackPop(obj);
//
// * int param_3 = myStackTop(obj);
//
// * bool param_4 = myStackEmpty(obj);
//
// * myStackFree(obj);
//*/

//
//
//#include<stdio.h>
//void fun(int arr[], int parents,int size)//排小堆
//{
//	int child = parents * 2 + 1;
//	while (child<size)
//	{
//		if (child+1 < size && arr[child] > arr[child + 1])
//		{
//			child++;
//		}
//		if (arr[child] < arr[parents])
//		{
//			int temp = arr[child];
//			arr[child] = arr[parents];
//			arr[parents] = temp;
//			parents = child;
//			child = parents * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//}
//
//int main()
//{
//	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
//	for ( int i=  4; i >= 0; i--)
//	{
//		fun(arr, i,10);
//	}
//	for (int i = 1; i < 10; i++)
//	{
//		int temp = arr[10 - i];
//		arr[10-i] = arr[0];
//		arr[0] = temp;
//		for (int j = 10-i; j >= 0; j--)
//		{
//			fun(arr, j,10-i);
//		}
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf(" %d ", arr[i]);
//	}
//}


//void adjustup(int* a, int n, int child)
//{
//	int parents;
//	while ((parents = (child - 1) / 2)>=0)
//	{
//		if (a[child] > a[parents])
//		{
//			int temp = a[child];
//			a[child] = a[parents];
//			a[parents] = temp;
//		}
//		else
//		{
//			break;
//		}
//		child = parents;
//
//	}
//}


//
//#include<stdio.h>
//
//void swap(int *a,int *b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void fun1(int a[], int n, int parents)
//{
//	int child = parents * 2 + 1;
//	while (child < n)
//	{
//		if (child+1<n && a[child] > a[child + 1])
//		{
//			child++;
//		}
//		if (a[parents] > a[child])
//		{
//			swap(&a[parents], &a[child]);
//			parents = child;
//			child = parents * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//}
//
//void sort(int a[], int n)
//{
//	for (int i = (n - 2) / 2; i >= 0; i--)
//	{
//		fun1(a, n, i);
//	}
//	
//	for (int j = 1; j < n; j++)
//	{
//		swap(&a[0], &a[n - j ]);
//		fun1(a, n-j, 0);
//	}
//
//}
//
//int main()
//{
//	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
//	sort(arr, 10);
//
//}



#include<stdio.h>

//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void adjustdown(int a[], int n, int parents)
//{
//	int child = parents * 2 + 1;
//	while (child < n)
//	{
//		if (child + 1 < n && a[child] > a[child + 1])
//		{
//			child++;
//		}
//		if (a[parents] > a[child])
//		{
//			swap(&a[parents], &a[child]);
//			parents = child;
//			child = parents * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//}
//
//void adjustup(int* a, int n, int child)
//{
//	int parents = (child - 1) / 2;
//	while (child > 0)
//	{
//		if (a[child] < a[parents])
//		{
//			int temp = a[child];
//			a[child] = a[parents];
//			a[parents] = temp;
//			child = parents;
//			parents = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//void sort(int a[], int n)
//{
//	/*for (int i = (n - 2) / 2; i >= 0; i--)
//	{
//		adjustdown(a, n, i);
//	}*/
//	for (int i = 1; i < n; i++)
//	{
//		adjustup(a, n,i);
//	}
//
//	for (int j = 1; j < n; j++)
//	{
//		swap(&a[0], &a[n - j]);
//		adjustdown(a, n - j, 0);
//	}
//}
//	
//
//
//
//int main()
//{
//	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
//	sort(arr, 10);
//}

//
//int removeElement(int* nums, int numsSize, int val) {
//	int sear = 0;
//	int cur = 0;
//	while (sear < numsSize)
//	{
//		if (nums[sear] != val)
//		{
//			cur++;
//			sear++;
//		}
//		else
//		{
//			while (nums[sear] == val)
//			{
//				sear++;
//			}
//			nums[cur] = nums[sear];
//			cur++;
//			sear++;
//		}
//	}
//	return cur;
//
//}
//int main()
//{
//	int a[] = { 3,2,2,3 };
//	int ret = removeElement(a, 4, 3);
//}

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
//class PalindromeList {
//public:
//    void reverseList(ListNode** phead)
//    {
//        struct ListNode* newhead = NULL;
//        struct ListNode* cur = *phead;
//        while (cur)
//        {
//            struct ListNode* temp = cur->next;
//            cur->next = newhead;
//            newhead = cur;
//            cur = temp;
//        }
//        *phead = newhead;
//    }
//    struct ListNode* FindHead(ListNode* p)
//    {
//        struct ListNode* fast = p;
//        struct ListNode* slow = p;
//        while (fast && fast->next)
//        {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        return slow;
//    }
//    bool chkPalindrome(ListNode* A) {
//        ListNode* mid = FindHead(A);
//        reverseList(&mid);
//        while (A && mid)
//        {
//            if (A->val != mid->val)
//                return 0;
//            else
//            {
//                A = A->next;
//                mid = mid->next;
//            }
//
//        }
//        return 1;
//
//    }
//};

//
//int BinaryTreeLeafSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	if (root->right == NULL && root->left == NULL)
//	{
//		return 1;
//	}
//	else
//	{
//		return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
//	}
//}
//
//
//int BinaryTreeLevelKSize(BTNode* root, int k)
//{
//	if (root == NULL)
//		return 0;
//	if (k == 0)
//	{
//		return 1;
//	}
//	else if (root->left == NULL && root->right == NULL && k > 0)
//	{
//		return 0;
//	}
//	else
//	{
//		return BinaryTreeLevelKSize(root->left,k--) + BinaryTreeLevelKSize(root->right,k--);
//	}
//
//}

//
//BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
//{
//	if (root == NULL)
//	{
//		return NULL;
//	}
//	if (root->val == x)
//	{
//		return root;
//	}
//	BTNode *p=BinaryTreeFind(root->left,x);
//	if (p)
//		return p;
//	BTNode *x= BinaryTreeFind(root->right, x);
//	if (x)
//		return x;
//}

//
//typedef char DataType;
//typedef struct BinaryTree
//{
//    DataType x;
//    struct BinaryTree* _left;
//    struct BinaryTree* _right;
//}BT;
//
//BT* CreatBT(BT* ps, char** s)
//{
//    if (**s != '#')
//    {
//        ps = (BT*)malloc(sizeof(BT));
//        ps->x = **s;
//        ps->_left = CreatBT(ps->_left, &(++(*s)));
//    }
//    else {
//        return NULL;
//    }
//    ps->_right = CreatBT(ps->_right, &(++(*s)));
//    return ps;
//}
//
//void Inorder(BT* ps)
//{
//    if (ps != NULL)
//    {
//        Inorder(ps->_left);
//        printf("%c ", ps->x);
//        Inorder(ps->_right);
//    }
//}
//int  main()
//{
//    char s[1000] = {};
//    scanf("%s", s);
//    BT* p = NULL;
//    char* t = s;
//    p = CreatBT(p, &t);
//    Inorder(p);
//}


//
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
//
//typedef int Datatype;
//typedef struct Stack
//{
//	Datatype* a;
//	int top;
//	int Capacity;
//}Stack;
//void StackInit(Stack* p)
//{
//	assert(p);
//	p->a = (Datatype*)malloc(4 * sizeof(Datatype));
//	p->top = 0;
//	p->Capacity = 4;
//}
//void StackPush(Stack* p, Datatype x)
//{
//	assert(p);
//	if (p->top == p->Capacity)  //检查是否要增容
//	{
//		p->a = (Datatype*)realloc(p->a, 2 * p->Capacity * sizeof(Datatype));
//		p->Capacity = p->Capacity * 2;
//	}
//	p->a[p->top] = x;
//	p->top++;
//}
//void StackPop(Stack* p)
//{
//	assert(p);
//	if (p->top)
//		p->top = p->top - 1;
//}
//void StackPrint(Stack* p)
//{
//	assert(p);
//	for (int i = 0; i < p->top; i++)
//	{
//		printf(" %d ", p->a[i]);
//	}
//	printf("\n");
//}
//Datatype StackTop(Stack* p)
//{
//	return p->a[p->top - 1];
//}
//int StackEmpty(Stack* p)
//{
//	return p->top == 0;
//}
//void StackDestroy(Stack* p)
//{
//	free(p->a);
//	p->a = NULL;
//	p->top = 0;
//	p->Capacity = 0;
//}
//
//typedef struct {
//	Stack s1;
//	Stack s2;
//
//} MyQueue;
//
///** Initialize your data structure here. */
//
//MyQueue* myQueueCreate() {
//	MyQueue q;
//	StackInit(&(q.s1));
//	StackInit(&(q.s2));
//	return &q;
//}
//
///** Push element x to the back of queue. */
//void myQueuePush(MyQueue* obj, int x) {
//	int a = 0;
//	StackPush(&(obj->s1), x);
//}
//
///** Removes the element from in front of queue and returns that element. */
//int myQueuePop(MyQueue* obj) {
//	while (StackEmpty(&(obj->s1))==0)
//	{
//		StackPush(&(obj->s2), StackTop(&(obj->s1)));
//		StackPop(&(obj->s1));
//	}
//	Datatype a = StackTop(&(obj->s2));
//	StackPop(&(obj->s2));
//	while (StackEmpty(&(obj->s2))==0)
//	{
//		StackPush(&(obj->s1), StackTop(&(obj->s2)));
//		StackPop(&(obj->s2));
//	}
//	return a;
//
//}
//
///** Get the front element. */
//int myQueuePeek(MyQueue* obj) {
//	while (StackEmpty(&(obj->s1)) == 0)
//	{
//		StackPush(&(obj->s2), StackTop(&(obj->s1)));
//		StackPop(&(obj->s1));
//	}
//	Datatype a = StackTop(&(obj->s2));
//	while (StackEmpty(&(obj->s2)) == 0)
//	{
//		StackPush(&(obj->s1), StackTop(&(obj->s2)));
//		StackPop(&(obj->s2));
//	}
//	return a;
//
//
//}
//
///** Returns whether the queue is empty. */
//bool myQueueEmpty(MyQueue* obj) {
//	return StackEmpty(&(obj->s1));
//
//}
//
//void myQueueFree(MyQueue* obj) {
//	StackDestroy(&(obj->s1));
//	StackDestroy(&(obj->s2));
//	obj = NULL;
//}
//int main()
//{
//	MyQueue* ps;
//	ps = myQueueCreate();
//
//	myQueuePush(ps, 1);
//
//
//
//
//
//
//
//	/*myQueuePush(&ps, 2);
//	myQueuePush(&ps, 3);
//	myQueuePush(&ps, 4);
//
//	myQueuePop(&ps);
//	int ret=myQueuePeek(&ps);*/
//
//
//
//
//}
//
//#include<stdbool.h>
//typedef struct {
//    int* a;
//    int Front;
//    int Rear;
//    int capacity;
//} MyCircularQueue;
//
//
//MyCircularQueue* myCircularQueueCreate(int k) {
//    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//    q->a = (int*)malloc((k + 1) * sizeof(int));
//    q->Front = 0;
//    q->Rear = 0;
//    q->capacity = k + 1;
//    return q;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//    if (((obj->Rear + 1) % (obj->capacity)) == obj->Front)  //检查队列是否满了
//        return false;
//    obj->a[obj->Rear] = value;
//    obj->Rear++;
//    obj->Rear %= obj->capacity;
//    return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//    if (((obj->Front) % (obj->capacity)) == obj->Rear)
//        return false;
//    obj->Front++;
//    obj->Front %= obj->capacity;
//    return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj))
//        return -1;
//    return obj->a[obj->Front];
//
//}
//
//int myCircularQueueRear(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj))
//        return -1;
//    return obj->a[(obj->Rear - 1+obj->capacity)%obj->capacity];
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//    return ((obj->Front) % (obj->capacity)) == obj->Rear;
//
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj) {
//    return ((obj->Rear + 1) % (obj->capacity)) == obj->Front;
//}
//
//void myCircularQueueFree(MyCircularQueue* obj) {
//    free(obj->a);
//    free(obj);
//    obj = NULL;
//
//}
//
//int main()
//{
//    MyCircularQueue* q = myCircularQueueCreate(3);
//   /* int a1=myCircularQueueEnQueue(q, 1);
//    int a2 = myCircularQueueEnQueue(q, 2);
//    int a3 = myCircularQueueEnQueue(q, 3);
//    int a4 = myCircularQueueEnQueue(q, 4);*/
//    int a5 = myCircularQueueRear(q);
//    /*int a6 = myCircularQueueIsFull(q);
//    int a7 = myCircularQueueDeQueue(q);
//    int a8 = myCircularQueueEnQueue(q, 4);
//    int a9 = myCircularQueueRear(q);*/
//}
///**
// * Your MyCircularQueue struct will be instantiated and called as such:
// * MyCircularQueue* obj = myCircularQueueCreate(k);
// * bool param_1 = myCircularQueueEnQueue(obj, value);
//
// * bool param_2 = myCircularQueueDeQueue(obj);
//
// * int param_3 = myCircularQueueFront(obj);
//
// * int param_4 = myCircularQueueRear(obj);
//
// * bool param_5 = myCircularQueueIsEmpty(obj);
//
// * bool param_6 = myCircularQueueIsFull(obj);
//
// * myCircularQueueFree(obj);
//*/


//
//
//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//
//
//
//typedef int Datatype;
//typedef struct listNode
//{
//	Datatype x;
//	struct listNode* next;
//}ListNode;
//
//typedef struct
//{
//	ListNode* head;
//	ListNode* tail;
//}Queue;
//
//void QueueInit(Queue* q)
//{
//	ListNode* First = (ListNode*)malloc(sizeof(ListNode));
//	First->next = NULL;
//	q->head = q->tail = First;
//	q->tail->next = NULL;
//}
//int QueueEmpty(Queue* q)
//{
//	return q->head == q->tail;
//}
//void QueuePush(Queue* q, Datatype x)
//{
//	assert(q);
//	q->tail->x = x;
//	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
//	q->tail->next = NewNode;
//	q->tail = NewNode;
//	q->tail->next = NULL;
//}
//
//void QueuePop(Queue* q)
//{
//	assert(q);
//	assert(!QueueEmpty(q));
//	if (!QueueEmpty(q))
//	{
//		ListNode* temp = q->head->next;
//		free(q->head);
//		q->head = temp;
//	}
//
//}
//
//Datatype QueueFront(Queue* q)
//{
//	assert(q);
//	assert(!QueueEmpty(q));
//	return q->head->x;
//}
//
//Datatype QueueBack(Queue* q)
//{
//	assert(q);
//	assert(!QueueEmpty(q));
//	ListNode* cur = q->head;
//	while (cur->next != q->tail)
//	{
//		cur = cur->next;
//	}
//	return cur->x;
//}
//
//int QueueSize(Queue* q)
//{
//	if (QueueEmpty(q))
//	{
//		return 0;
//	}
//	ListNode* cur = q->head;
//	int k = 0;
//	while (cur != q->tail)
//	{
//		cur = cur->next;
//		k++;
//	}
//	return k;
//}
//
//
//
//void QueueDestroy(Queue* q)
//{
//	ListNode* cur = q->head;
//	while (cur != q->tail)
//	{
//		ListNode* temp = cur->next;
//		free(cur);
//		cur = temp;
//	}
//	free(cur);
//	cur = NULL;
//	q->head = NULL;
//	q->tail = NULL;
//
//}
//void check(Queue* q1, Queue* q2)
//{
//	if (QueueEmpty(q1)) {
//		Queue temp = *q1;
//		*q1 = *q2;
//		*q2 = temp;
//	}
//}
//
//typedef struct {
//	Queue q1;
//	Queue q2;
//} MyStack;
//
///** Initialize your data structure here. */
//
//MyStack* myStackCreate() {
//	MyStack* p = (MyStack*)malloc(sizeof(MyStack));
//	QueueInit(&(p->q1));
//	QueueInit(&(p->q2));
//	return p;
//
//}
//
///** Push element x onto stack. */
//void myStackPush(MyStack* obj, int x) {
//	check(&(obj->q1), &(obj->q2));
//	QueuePush(&(obj->q1), x);
//}
//
///** Removes the element on top of the stack and returns that element. */
//int myStackPop(MyStack* obj) {
//	check(&(obj->q1), &(obj->q2));
//	int b = 0;
//	while (!QueueEmpty(&(obj->q1)))
//	{
//		if (QueueSize(&(obj->q1)) == 1)
//		{
//			b = QueueFront(&(obj->q1));
//			QueuePop(&(obj->q1));
//			continue;
//		}
//		int a = QueueFront(&(obj->q1));
//		QueuePop(&(obj->q1));
//		QueuePush(&(obj->q2), a);
//
//	}
//
//	return b;
//}
//
///** Get the top element. */
//int myStackTop(MyStack* obj) {
//	check(&(obj->q1), &(obj->q2));
//	return QueueBack(&(obj->q1));
//
//}
//
///** Returns whether the stack is empty. */
//bool myStackEmpty(MyStack* obj) {
//	check(&(obj->q1), &(obj->q2));
//	return QueueEmpty(&(obj->q1));
//
//}
//
//void myStackFree(MyStack* obj) {
//	QueueDestroy(&(obj->q1));
//	QueueDestroy(&(obj->q2));
//	free(obj);
//}
//
//
//int main()
//{
//	MyStack* ps = myStackCreate();
//	myStackPush(ps, 1);
//	myStackPush(ps, 2);
//	int ret = myStackPop(ps);
//	int a = myStackEmpty(ps);
//}
//
//
//#include<stdio.h>
//
//typedef char DataType;
//typedef struct BinaryTree
//{
//    DataType x;
//    struct BinaryTree* _left;
//    struct BinaryTree* _right;
//}BT;
//
//
//BT* CreatTree(char* s, int* i)
//{
//    if (s[*i] != '\0')
//    {
//        if (s[*i] != '#')
//        {
//            BT* ps = (BT*)malloc(sizeof(BT));
//            ps->x = s[*i];
//            *i = *i + 1;
//            ps->_left=CreatTree(s, i);
//            *i = *i + 1;
//            ps->_right = CreatTree(s, i);
//            return ps;
//        }
//        else {
//            return NULL;
//        }
//    }
//}
//
//void Inorder(BT* root)
//{
//    if (root != NULL)
//    {
//        Inorder(root->_left);
//    }
//    else
//    {
//        return;
//    }
//    printf("%c ", root->x);
//    Inorder(root->_right);
//}
//int main()
//{
//    char s[100];
//    scanf("%s", s);
//    BT *ps;
//    int i = 0;
//    ps=CreatTree(s,&i );
//    Inorder(ps);
//    return 0;
//}


//
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef char DataType;
//typedef struct BinaryTree
//{
//    DataType x;
//    struct BinaryTree* _left;
//    struct BinaryTree* _right;
//}BT;
//
//
//BT* CreatTree(char* s, int* i)
//{
//    if (s[*i] != '\0')
//    {
//        if (s[*i] != '#')
//        {
//            BT* p = (BT*)malloc(sizeof(BT));
//            p->x = s[*i];
//            *i += 1;
//            p->_left = CreatTree(s, i);
//            *i += 1;
//            p->_right = CreatTree(s, i);
//        }
//        else {
//            return NULL;
//        }
//    }
//    return NULL;
//}
//
//void Inorder(BT* root)
//{
//    if (root != NULL)
//    {
//        Inorder(root->_left);
//    }
//    else
//    {
//        return;
//    }
//    printf("%c ", root->x);
//    Inorder(root->_right);
//}
//int main()
//{
//    char s[100];
//    scanf("%s", s);
//    BT* ps;
//    int i = 0;
//    ps = CreatTree(s, &i);
//    Inorder(ps);
//    return 0;
//}
//
//int PartSort2(int* a, int left, int right)
//{
//	int key = right;
//	int temp = a[key];
//	while (left < right)
//	{
//		while (left<right && a[right] >= temp)
//		{
//			right--;
//		}
//		swap(&a[right], &a[left]);
//
//		while (left<right&&a[left] <= temp)
//		{
//			right--;
//		}
//		swap(&a[right], &a[left]);
//	}
//	a[left] = temp;
//	return left;
//
//}
//
//
//#include<assert.h>
// struct TreeNode {
//      int val;
//     struct TreeNode *left;
//      struct TreeNode *right;
//  };
// 
//typedef struct TreeNode* Datatype;
//typedef struct listNode
//{
//	Datatype x;
//	struct listNode* next;
//}ListNode;
//
//typedef struct Queue
//{
//	ListNode* head;
//	ListNode* tail;
//}Queue;
//
//struct TreeNode* CreatBT()
//{
//	struct TreeNode* n1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	struct TreeNode* n2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	struct TreeNode* n3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	struct TreeNode* n4 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	struct TreeNode* n5 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//
//	n1->val = 3;
//	n2->val = 9;
//	n3->val = 20;
//	n4->val = 15;
//	n5->val = 7;
//
//	n1->left = n2;
//	n1->right = n3;
//	n2->left = n2->right = NULL;
//	n4->left = n4->right = NULL;
//	n5->left = n5->right = NULL;
//	n3->left = n4;
//	n3->right = n5;
//
//	return n1;
//
//}
//void QueueInit(Queue* q)
//{
//	ListNode* First = (ListNode*)malloc(sizeof(ListNode));
//	q->head = q->tail = First;
//	q->tail->next = NULL;
//}
//int QueueEmpty(Queue* q)
//{
//	return q->head == q->tail;
//}
//void QueuePush(Queue* q, Datatype x)
//{
//	assert(q);
//	q->tail->x = x;
//	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
//	q->tail->next = NewNode;
//	q->tail = NewNode;
//	q->tail->next = NULL;
//}
//
//void QueuePop(Queue* q)
//{
//	assert(q);
//	assert(!QueueEmpty(q));
//	if (!QueueEmpty(q))
//	{
//		ListNode* temp = q->head->next;
//		free(q->head);
//		q->head = temp;
//	}
//
//}
//
//Datatype QueueFront(Queue* q)
//{
//	assert(q);
//	assert(!QueueEmpty(q));
//	return q->head->x;
//}
//
//
//
//void QueueDestroy(Queue* q)
//{
//	ListNode* cur = q->head;
//	while (cur != q->tail)
//	{
//		ListNode* temp = cur->next;
//		free(cur);
//		cur = temp;
//	}
//	free(cur);
//	cur = NULL;
//	q->head = NULL;
//	q->tail = NULL;
//
//}
//
//int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
//	if (root == NULL)
//		return NULL;
//	int** p = (int**)malloc(sizeof(int*));
//	*p = NULL;
//	int* q = (int*)malloc(sizeof(int*));
//	Queue Q1;
//	QueueInit(&Q1);
//	QueuePush(&Q1, root);
//	int colsize = 0;          //数组的个数，也就是行数
//	int index = 1;   //每次数组的理论大小
//	while (!QueueEmpty(&Q1))
//	{
//		int m = 0; //每一个数组实际上存了几个数，因为是NULL是不会进入数组的
//
//
//		for (int i = 0; i < index; i++)
//		{
//			if (!QueueEmpty(&Q1)&&QueueFront(&Q1))
//			{
//				if(p[colsize]==NULL)
//					p[colsize] = (int*)malloc((m + 1) * sizeof(int));
//				else
//					p[colsize] = (int*)realloc(p[colsize], (m + 1) * sizeof(int));
//				p[colsize][m] = QueueFront(&Q1)->val;
//				m++;
//				struct TreeNode* temp = QueueFront(&Q1);
//				QueuePush(&Q1, temp->left);
//				QueuePush(&Q1, temp->right);
//			}
//
//			if (!QueueEmpty(&Q1))
//				QueuePop(&Q1);
//			else
//				break;
//		}
//		q = (int*)realloc(q, (colsize + 1) * sizeof(int));
//		q[colsize] = m;
//		if(sizeof(q[colsize]))
//		colsize++;
//		index *= 2;
//		p = (int**)realloc(p,(colsize+1)*sizeof(int*));
//		p[colsize] = NULL;
//	}
//	QueueDestroy(&Q1);
//	*returnSize = colsize;
//	*returnColumnSizes = q;
//	return p;
//}
//

////
////int main()
////{
////	int* t = (int*)realloc(t, sizeof(int));
////}


//
//int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
//	if (root == NULL)
//	{
//		*returnSize = 0;
//		*returnColumnSizes = NULL;
//		return NULL;
//	}
//	int** p = (int**)malloc(sizeof(int*));
//	*p = NULL;
//	int* q = (int*)malloc(sizeof(int*));
//	Queue Q1;
//	QueueInit(&Q1);
//	QueuePush(&Q1, root);
//	int colsize = 0;          //数组的个数，也就是行数
//	int index = 1;   //每次数组的理论大小
//	while (!QueueEmpty(&Q1))
//	{
//		int m = 0; //每一个数组实际上存了几个数，因为是NULL是不会进入数组的
//		int k = 0;
//
//		for (int i = 0; i < index; i++)
//		{
//			if (!QueueEmpty(&Q1) && QueueFront(&Q1))
//			{
//				if (p[colsize] == NULL)
//					p[colsize] = (int*)malloc((m + 1) * sizeof(int));
//				else
//					p[colsize] = (int*)realloc(p[colsize], (m + 1) * sizeof(int));
//				p[colsize][m] = QueueFront(&Q1)->val;
//				m++;
//				struct TreeNode* temp = QueueFront(&Q1);
//				if (temp->left)
//					QueuePush(&Q1, temp->left);
//				if (temp->right)
//					QueuePush(&Q1, temp->right);
//				if (temp->left == NULL)
//					k++;
//				if (temp->right == NULL)
//					k++;
//			}
//
//			if (!QueueEmpty(&Q1))
//				QueuePop(&Q1);
//			else
//				break;
//		}
//		q = (int*)realloc(q, (colsize + 1) * sizeof(int));
//		q[colsize] = m;
//		index = index * 2 - k;
//		colsize++;
//		p = (int**)realloc(p, (colsize + 1) * sizeof(int*));
//		p[colsize] = NULL;
//	}
//	QueueDestroy(&Q1);
//	*returnSize = colsize;
//	*returnColumnSizes = q;
//	return p;
//}
//void postOrder(struct TreeNode* root, int* returnSize, int* a)
//{
//	if (root != NULL)
//	{
//		postOrder(root->left, returnSize, a);
//	}
//	else
//	{
//		return;
//	}
//	postOrder(root->right, returnSize, a);
//	a[*returnSize] = root->val;
//	*returnSize++;
//}
//
//int* postorderTraversal(struct TreeNode* root, int* returnSize) {
//	int* p = (int*)malloc(2000 * sizeof(int));
//	int k = 0;
//	postOrder(root, &k, p);
//	*returnSize = k;
//	return p;
//
//
//
//}
//
//int main()
//{
//	TreeNode* root;
//	root = CreatBT();
//	int* returnColumnSizes;
//	int returnSize;
//	int** b;
//	//a = postorderTraversal(root, &size);
//	b = levelOrder(root, &returnSize, &returnColumnSizes);
//	for (int i = 0; i < returnSize; i++)
//	{
//		for (int j = 0; j < returnColumnSizes[i]; j++)
//		{
//			printf("%d ", b[i][j]);
//		}
//		printf("\n");
//	}
//}

//
//
//void PartSort3(int* a, int left, int right)
//{
//	int keyi = left;
//	int prev = left;
//	int cur = prev + 1;
//
//	while (cur <= right)
//	{
//		if (a[cur] > a[keyi])
//			cur++;
//		else
//		{
//			swap(&a[++prev], &a[cur];
//			cur++;
//		}
//
//
//
//	}
//	swap(&a[keyi], &a[prev]);
//}
//

//
//typedef int DataType;
//struct Node
//{
//	struct Node* _fistchild1;   //第一个孩子的节点
//	struct Node* _NextBrother;   //指向其下一个兄弟的节点
//	DataType _data;               //节点中的数据域
//};

//
//typedef int DataType;
//struct BinaryTreeNode               //二叉链
//{
//	struct BinaryTreeNode* left;
//	struct BinaryTreeNode* right;
//	DataType data;
//};
//
//typedef BinaryTreeNode            //三叉链
//{
//	struct BinaryTreeNode* left;
//	struct BinaryTreeNode* right;
//	struct BinaryTreeNode* parents;
//	DataType data;
//}

//
//int* sortArray(int* nums, int numsSize, int* returnSize) {
//    for (int i = 0; i < numsSize - 1; i++)
//    {
//        int end = i;
//        int temp = nums[end + 1];
//        while (end>=0&&nums[end] > temp)
//        {
//            nums[end + 1] = nums[end];
//            end--;
//        }
//        nums[end + 1] = temp;
//    }
//    *returnSize = numsSize;
//    return nums;
//
//}
//int main()
//{
//    int a[] = {5,2,3,1 };
//    int sz = 0;
//    int *arry=sortArray(a, 4, &sz);
//}



//
//int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
//    *returnSize = 0;
//    int** p = (int**)malloc(sizeof(int*));
//    for (int x = 0; x < numsSize; x++)
//    {
//        for (int y = x + 1; y < numsSize; y++)
//        {
//            for (int z = y + 1; z < numsSize; z++)
//            {
//                if (nums[x] + nums[y] + nums[z] == 0)
//                {
//                    int temp = nums[x] ^ nums[y] ^ nums[z];
//                    int a = -1;
//                    int b = -1;
//                    int c = -1;
//                    for (int i = 0; i < *returnSize; i++)
//                    {
//                        for (int j = 1; j < 4; j++)
//                        {
//                            if (p[i][j - 1] == nums[x])
//                            {
//                                a = j;
//                                break;
//                            }
//                        }
//                        if (a >= 0)
//                        {
//                            for (int j = 1; j < 4; j++)
//                            {
//                                if (p[i][j - 1] == nums[y] && j != a)
//                                {
//                                    b = j;
//                                    break;
//                                }
//                            }
//                            if (b >= 0)
//                            {
//                                for (int j = 1; j < 4; j++)
//                                {
//                                    if (p[i][j - 1] == nums[z] && j != a && j != b)
//                                    {
//                                        c = j;
//                                        break;
//                                    }
//                                }
//
//                            }
//
//                        }
//                    }
//                    if (a>0&&b>0&&c>0)
//                        continue;
//                   /* int ret = 1;
//                    for (int i = 0; i < *returnSize; i++)
//                    {
//                        if ((temp == p[i][3]))
//                        {
//                            ret = 0;
//                            break;
//                        }
//                    }
//                    if (ret == 0)
//                        continue;*/
//                    p = (int**)realloc(p, (*returnSize + 1) * sizeof(int*));
//                    p[*returnSize] = NULL;
//                    p[*returnSize] = (int*)realloc(p[*returnSize], (*returnSize + 1) * 4 * sizeof(int));
//                    p[*returnSize][0] = nums[x];
//                    p[*returnSize][1] = nums[y];
//                    p[*returnSize][2] = nums[z];
//                    p[*returnSize][3] = temp;
//                    (*returnSize)++;
//
//                }
//            }
//        }
//    }
//    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
//    for (int i = 0; i < *returnSize; i++)
//    {
//        (*returnColumnSizes)[i] = 3;
//    }
//
//    return p;
//
//}



//
//
//
//int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
//
//    int** p = (int**)malloc(sizeof(int*));
//
//    *returnSize = 0;
//    *returnColumnSizes = (int*)malloc(sizeof(int));
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = 0; j < numsSize - 1 - i; j++)
//        {
//            if (nums[j] > nums[j + 1])
//            {
//                int temp = nums[j];
//                nums[j] = nums[j + 1];
//                nums[j + 1] = temp;
//            }
//
//        }
//    }
//    for (int i = 0; nums[i] < 0; i++)
//    {
//        int L = i + 1;
//        int R = numsSize - 1;
//        while (L < R)
//        {
//            if (nums[i] + nums[L] + nums[R] > 0)
//                R--;
//            if (nums[i] + nums[L] + nums[R] < 0)
//                L++;
//            if (L < R && nums[i] + nums[L] + nums[R] == 0)
//            {
//                (*returnSize)++;
//
//                p = (int **)realloc(p, *returnSize * sizeof(int*));  //重新开辟指针数组大小
//                p[*returnSize - 1] = (int*)malloc(3 * sizeof(int));  //开辟数组指针指向的数组大小
//
//                p[*returnSize - 1][0] = nums[i];
//                p[*returnSize - 1][1] = nums[L];
//                p[*returnSize - 1][2] = nums[R];
//
//                *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*returnSize) * sizeof(int));
//                (*returnColumnSizes)[*returnSize - 1] = 3;
//
//
//                while (L < R && nums[L] == nums[L + 1])
//                    L++;
//                while (L < R && nums[R] == nums[R + 1])
//                    R--;
//
//                L++;
//                R--;
//            }
//        }
//        while (nums[i] == nums[i + 1])
//            i++;
//
//    }
//    return p;
//
//}


//
//int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
//    if (nums == NULL || numsSize < 3)
//        return NULL;
//    int** p = (int**)malloc(5000 * sizeof(int*));
//
//    *returnSize = 0;
//    *returnColumnSizes = (int*)malloc(5000 * sizeof(int));
//    for (int i = 0; i < numsSize; i++)
//    {
//        for (int j = 0; j < numsSize - 1 - i; j++)
//        {
//            if (nums[j] > nums[j + 1])
//            {
//                int temp = nums[j];
//                nums[j] = nums[j + 1];
//                nums[j + 1] = temp;
//            }
//
//        }
//    }
//    if (nums[0] > 0)
//        return NULL;
//    for (int i = 0; nums[i] < 0 && i < numsSize; i++)
//    {
//        while (i < numsSize && nums[i - 1] == nums[i])
//            i++;
//        int L = i + 1;
//        int R = numsSize - 1;
//        while (L < R)
//        {
//            if (nums[i] + nums[L] + nums[R] > 0)
//                R--;
//            if (nums[i] + nums[L] + nums[R] < 0)
//                L++;
//            if (L < R && nums[i] + nums[L] + nums[R] == 0)
//            {
//                (*returnSize)++;
//
//                //p = (int**)realloc(p, *returnSize * sizeof(int*));  //重新开辟指针数组大小
//                p[*returnSize - 1] = (int*)malloc(3 * sizeof(int));  //开辟数组指针指向的数组大小
//
//                p[*returnSize - 1][0] = nums[i];
//                p[*returnSize - 1][1] = nums[L];
//                p[*returnSize - 1][2] = nums[R];
//
//                //*returnColumnSizes = (int *)realloc(*returnColumnSizes, (*returnSize )* sizeof(int));
//                (*returnColumnSizes)[*returnSize - 1] = 3;
//
//
//                while (nums[L] == nums[L + 1])
//                    L++;
//                while (nums[R] == nums[R + 1])
//                    R--;
//                L++;
//            }
//        }
//
//    }
//    return p;
//
//}
//int main()
//{
//    int a[] = { -1,0,1,2,-1,-4,-2,-3,3,0,4};
//    int sz = sizeof(a) / sizeof(a[0]);
//    int c;   //存放有几行  --------returnSize
//    int* b;  //存放每一行有几列   ————returnColumnSize
//    int** d;
//    d = threeSum(a, sz, &c, &b);
//
//    for (int i = 0; i < c; i++)
//    {
//        for (int j = 0; j < b[i]; j++)
//        {
//            printf(" %d ", d[i][j]);
//        }
//        printf("\n");
//    }
//
//    for (int i = 0; i < c; i++)
//    {
//        free(d[i]);
//    }
//
//    free(d);
//
//}
//
//
//
////int main()
////{
////	int** p = (int**)malloc(sizeof(int*));
////
////	p[0] = (int*)malloc(3 * sizeof(int));
////	for (int i = 0; i < 3; i++)
////	{
////		p[0][i] = i;
////	}
////
////	p = (int**)realloc(p, 2 * sizeof(int*));
////	p[1] = (int*)malloc(3 * sizeof(int));
////	for (int i = 0; i < 3; i++)
////	{
////		p[1][i] = i*2;
////	}
////
////	for (int i = 0; i < 2; i++)
////	{
////		free(p[i]);
////	}
////	free(p);
////}
//
//
//#define add(x,y) x+y;


//
//int main()
//{
//	printf("hello world");
//	return 0;
//}
//
//typedef struct Q {
//    int x;
//    struct Q* next;
//
//}Queue;
//
//typedef struct {
//    Queue* head;
//    Queue* tail;
//} MaxQueue;
//
//
//MaxQueue* maxQueueCreate() {
//    MaxQueue* p = (MaxQueue*)malloc(sizeof(MaxQueue));
//    Queue* q = (Queue*)malloc(sizeof(Queue));
//    p->head = q;
//    p->tail = q;
//    p->tail->next = NULL;
//    return p;
//
//}
//
//int maxQueueMax_value(MaxQueue* obj) {
//    if (obj->tail == obj->head)
//        return -1;
//    Queue* cur = obj->head;
//    int max = obj->head->x;
//    while (cur != obj->tail)
//    {
//        if (cur->x > max)
//            max = cur->x;
//    }
//    return max;
//
//}
//
//void maxQueuePush_back(MaxQueue* obj, int value) {
//    obj->tail->x = value;
//    obj->tail->next = (Queue*)malloc(sizeof(Queue));
//    obj->tail = obj->tail->next;
//    obj->tail->next = NULL;
//
//}
//
//int maxQueuePop_front(MaxQueue* obj) {
//    if (obj->tail == obj->head)
//        return -1;
//    Queue* temp = obj->head->next;
//    free(obj->head);
//    obj->head = temp;
//    return 0;
//
//}
//
//void maxQueueFree(MaxQueue* obj) {
//    while (obj->head != obj->tail)
//    {
//        Queue* temp = obj->head->next;
//        free(obj->head);
//        obj->head = temp;
//    }
//    free(obj->tail);
//    free(obj);
//
//
//
//}
//int main()
//{
//    MaxQueue* ps = maxQueueCreate();
//    maxQueuePush_back(ps, 1);
//    maxQueuePush_back(ps, 2);
//    int ret=maxQueueMax_value(ps);
//
//}
//
//void fun1(int x)
//{
//	printf("fun(int x)");
//}
//
//void fun2(int* x)
//{
//	printf("fun(int* x)");
//}
//
//
//
//int main()
//{
//	fun1(0);
//	fun2(0);
//	fun2(NULL);
//	fun1(NULL);
//
//}


//
//char* replaceSpace(char* s) {
//    int num = 0;
//    int sum = 0;
//    while (s[sum] != '\0')
//    {
//        if (*s == ' ')
//            num++;
//        sum++;
//    }
//    char* new = (char*)malloc((sum + num * 2 + 1) * sizeof(char));
//    int i = 0, j = 0;
//    for (i = 0, j = 0; i < sum; j++, i++)
//    {
//        if (s[i] == ' ')
//        {
//            new[j] = '%';
//            new[++j] = '2';
//            new[++j] = '0';
//        }
//        else {
//            new[j] = s[i];
//        }
//    }
//    new[j] = '\0';
//    return new;
//    // write code here
//}
//int main()
//{
//    char s[] = "we are happy";
//    char* p = replaceSpace(s);
//    printf("%s", p);
//    return 0;
//}


//
//
//int main()
//{
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(short));
//	return 0;
//}


//
//
//int  onesort(int* a, int left, int right)  //单趟排序
//{
//    int key = left;
//
//    while (left < right)
//    {
//        while (left<right && a[right]>a[key])
//            right--;
//
//        while (left < right && a[left] <= a[key])
//            left++;
//
//        int temp = a[right];
//        a[right] = a[left];
//        a[left] = temp;
//   }
//
//
//    int temp = a[key];
//    a[key] = a[left];
//    a[left] = temp;
//
//    return left;
//}
//
//
//void quicksort(int* a, int left, int right)
//{
//    if (right <= left)
//        return;
//
//    int k = onesort(a, left, right);
//
//    quicksort(a, left, k - 1);
//
//    quicksort(a, k + 1, right);
//}
//
//int main()
//{
//    int a[] = { -4,0,7,4,9,-5,-1,0,-7,-1 };
//   quicksort(a, 0, 9);
//
//}


//
//int* plusOne(int* digits, int digitsSize, int* returnSize) {
//
//    digits[digitsSize - 1] += 1;
//
//    for (int i = digitsSize - 1; i >= 1; i--)
//    {
//        if (digits[i] > 9)
//        {
//            if(i-1>0)
//            digits[i - 1]++;
//            digits[i] -= 10;
//        }
//    }
//    if (digits[0] >= 10)
//    {
//        int* p = (int*)malloc((digitsSize + 1) * sizeof(int));
//        for (int i = 0; i < digitsSize; i++)
//        {
//            p[i + 1] = digits[i];
//        }
//        p[0] = 1;
//        *returnSize = digitsSize + 1;
//        return p;
//    }
//    else
//    {
//        int* p = (int*)malloc((digitsSize) * sizeof(int));
//        for (int i = 0; i < digitsSize; i++)
//        {
//            p[i] = digits[i];
//        }
//        *returnSize = digitsSize;
//        return p;
//    }
//
//
//
//
//
//}
//int main()
//{
//    int a[] = { 9 };
//    int sz = 0;
//    int* p = plusOne(a, 1 ,&sz);
//
//    return 0;
//}



//
//
//void sort(int* a, int n)
//{
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n - 1 - i; j++)
//        {
//            if (a[j] > a[j + 1])
//            {
//                int temp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = temp;
//            }
//        }
//    }
//}
//int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//    sort(nums, numsSize);
//    int mid = target / 2;
//    if (nums[0] > mid || nums[numsSize - 1] < mid)
//    {
//        return NULL;
//    }
//    int l=0;
//
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > mid)
//        {
//            l = i;
//            break;
//        }
//    }
//    int* new = NULL;
//    int capacity = 0;
//    for (int i = 0; i < l; i++)
//    {
//        for (int j = l; j < numsSize; j++)
//        {
//            if (nums[j] == mid)
//            {
//                capacity += 1;
//                new = (int*)realloc(new, capacity * sizeof(int));
//                new[capacity - 1] = i;
//            }
//            else if (nums[i] + nums[j] == target)
//            {
//                capacity += 1;
//                new = (int *)realloc(new, 2*capacity * sizeof(int));
//                new[2 * capacity - 2] = i;
//                new[2 * capacity - 1] = j;
//            }
//        }
//    }
//
//    *returnSize = 2*capacity;
//
//    return new;
//
//
//}
//
//int main()
//{
//    int a[] = { 3,2,4 };
//    int b = 6;
//    int* p = twoSum(a, 3, 6, &b);
//
//
//
//
//}

//
//int reverse(int x) {
//
//    unsigned long M = -1;
//    M /= 2;
//
//    long min = -(signed long)M;
//    long max = (signed long)M - 1;
//
//    long long y = 0;
//    while (x != 0)
//    {
//        y = y * 10 + x % 10;
//        x /= 10;
//        if (y < min || y > max)
//            return 0;
//
//    }
//
//    
//        return y;
//    
//
//
//}
//int main()
//{
//    int ret=reverse(1534236469);
//}

//int firstUniqChar(char* s) {
//    int i = 0;
//
//    while (s[i] != '\0')
//    {
//        i++;
//    }
//
//    char* p = (char*)malloc((i + 1) * sizeof(char));
//
//    for (int j = 0; j < i + 1; j++)
//    {
//        p[j] = s[j];
//    }
//
//    int cur = 0;
//    while (p[cur] != '\0')
//    {
//        int find = cur + 1;
//        int ret = 1;
//        while (p[find] != '\0')
//        {
//            if (p[find] == p[cur])
//            {
//                ret = 0;
//                int x = find;
//                while (p[x] != '\0')
//                {
//                    if(p[x+1]!=p[find])
//                    p[x] = p[x + 1];
//                    x++;
//                }
//                break;
//
//            }
//            find++;
//        }
//        if (ret)
//            return cur;
//        cur++;
//    }
//
//    return -1;
//
//}
//int main()
//{
//    char* a = "lleetcode";
//    int ret = firstUniqChar(a);
//
//
//
//}
//
//
//#include<stdbool.h>
//bool isPalindrome(char* s) {
//    int size = 0;
//    while (s[size] != '\0')
//    {
//        size++;
//    }
//
//    int left = 0;
//    int right = size - 1;
//
//    int ret = 1;
//
//    while (right > left)
//    {
//        while (!(s[right] >= 'a' && s[right] <= 'z' || s[right] >= 'A' && s[right] <= 'Z' || s[right] >= '0' && s[right] <= '9'))
//        {
//            right--;
//        }
//        while (!(s[left] >= 'a' && s[left] <= 'z' || s[left] >= 'A' && s[left] <= 'Z' || s[left] >= '0' && s[left] <= '9'))
//        {
//            left++;
//        }
//
//
//        if (isupper(s[right]))
//        {
//            s[right] = tolower(s[right]);
//        }
//
//        if (isupper(s[left]))
//        {
//            s[left] = tolower(s[left]);
//        }
//
//
//        if (s[left] != s[right])
//            ret = 0;
//
//        left++;
//        right--;
//    }
//
//    if (ret)
//        return true;
//    else
//        return false;
//
//}
//
//
//int main()
//{
//    char s[] = ".,";
//
//    int ret = isPalindrome(s);
//
//}
//
//int myAtoi(char* s) {
//    unsigned long long count = 0;
//    int ret = 1;
//    int i = 0;
//    while (s[i] != '\0')
//    {
//        while (s[i] != '\0' && !(s[i] >= '0' && s[i] <= '9'))
//        {
//            if (s[i] == '-')
//                ret = -1;
//            i++;
//        }
//        if (s[i] != '\0')
//        {
//            count = count * 10 + s[i] - '0';
//
//            i++;
//        }
//        else
//            break;
//    }
//    if (count > 4294967295 && ret == 1 || count > 4294967295 && ret == -1)
//        return ret * count;
//    else
//        return ret * (int)count;
//}
//
//int main()
//{
//    char s[] = "words and 987";
//    int ret = myAtoi(s);
//}



//
//
//int* fun(char* s)
//{
//	int* p = NULL;
//	int size = 0;
//
//	while (s[size] != '\0')
//	{
//		int left = 1;
//		int right = size-1;
//		if (!(right >= 0 && left <= size))
//		{
//			p = (int*)realloc(p, (size + 1) * sizeof(int));
//			p[size] = -1;
//		}
//		else
//		{
//			while (right >= 0 && left <= size)
//			{
//				int i, j;
//				int ret = 1;
//				for (i = 0, j = left; i <= right, j <= size; i++, j++)
//				{
//					if (s[i] != s[j])
//					{
//						ret = 0;
//						break;
//					}
//				}
//				if (ret)
//					break;
//				left++;
//				right--;
//
//			}
//			p = (int*)realloc(p, (size + 1) * sizeof(int));
//			p[size] = right;
//		}
//
//
//
//
//		size++;
//	}
//	return p;
//
//}


//next[j]就是待匹配串从t[0]开始到t[j-1]结尾的这个子串中，前缀和后缀相等时对应前缀/后缀的最大长度，请看下图，j=10（下标从0开始）：


//void get_next_arr(char* t, int* next)
//{
//	// next[i]的求解方法是，找到从t[0]~t[i-1]的公共最长匹配前缀和后缀的长度
//	next[0] = -1;  // next[0]定义为-1
//	next[1] = 0;	 // next[1]肯定是0
//	// 只要待匹配串还没到底，都要求相应位的next[i]值
//	for (int i = 2; t[i] != '\0'; i++)
//	{
//		int max_len = i - 1;		// 最长长度为i-1
//		int len, j;
//		for (len = max_len; len >= 1; len--)  // 从最长的情况开始搜索
//		{
//			for (j = 0; j < len; j++)
//			{
//				if (t[j] != t[j + i - len])  // 只要有任何一位不对应相等，那么当前len就不成立，试探下一个len 
//					break;
//			}
//			// 如果上一个循环是正常退出，即都对应相等了，那就把当前的len赋给next[i],并不再往下试探了
//			if (j == len)
//			{
//				next[i] = len;
//				break;
//			}
//		}
//		if (len < 1)  // 如果len=1的情况都不成立，那next[i]肯定是0了
//		{
//			next[i] = 0;
//		}
//
//	}
//}

//
//void buildchar(char* s, int* p)
//{
//	int size = strlen(s);
//
//	p[0] = -1;
//
//	for (int i = 1; i < size; i++)   //从1 开始 到最后一个数进行遍历 ,里面的循环是寻找 前后缀的最大长度
//	{
//		p[i] = 0;
//		for (int j = 1; j < i; j++)//里面数组下表要小于i
//		{
//
//			if (s[j] == s[0])
//			{
//				int ret = 1;
//				int x;
//				for (x = j; x < i; x++)
//				{
//					if (s[x] != s[x - j])
//					{
//						ret = 0;
//						break;
//					}
//				}
//
//				if (ret)
//				{
//					p[i] = x - j;
//					break;
//				}
//			}
//		}
//	}
//}
//
//int kmp(char* s,char* p)
//{
//	int size = strlen(s);
//	int* next = (int*)malloc(size * sizeof(int));
//	buildchar(p, next);
//
//
//	int i = 0, j = 0;
//	while (s[i] != '\0' && p[j] != '\0')
//	{
//		if (s[i] == p[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = next[j];
//
//			if (j <=0)
//			{
//				i++;
//				j = 0;
//			}
//		}
//	}
//
//	if (p[j])
//		return -1;
//	else
//		return i - strlen(p);
//}
//
//int main()
//{
//	char s[] = "aabaaabaaac";
//	char p[] = "aabaaac";
//
//
//	//buildchar(s,p);
//	//get_next_arr(s, p);
//
//	int ret = kmp(s, p);
//}
//
//



//char* compare(char* s, char* t)
//{
//    int i = 0;
//    while (s[i] != '\0' && t[i] != '\0')
//    {
//        if (s[i] == t[i])
//        {
//            i++;
//        }
//    }
//
//    t[i] = '\0';
//
//    return t;
//}
//
//char* longestCommonPrefix(char** p, int strsSize) {
//    for (int i = 0; i < strsSize - 1; i++)
//    {
//        if (compare(p[i], p[i + 1]) == '\0')
//            return p[i + 1];
//    }
//    return p[strsSize - 1];
//}
//
//
//int main()
//{
//    char a1[] = "flower";
//    char a2[] = "flow";
//    char a3[] = "flight";
//
//    char* p[3] = {a1,a2,a3};
//
//
//    char* ps = longestCommonPrefix(p, 3);
//
//
//
//}





//
//
//void buildchar(char* s, int* next)
//{
//	int size = strlen(s);
//	next[0] = 0;
//	for (int i = 1; i < size; i++)
//	{
//		if (s[next[i - 1]] == s[i - 1])
//		{
//			if (i == 1)
//				next[i] = 0;
//			else
//			next[i] = next[i - 1] + 1;
//			continue;
//		}
//		else
//		{
//			int k = next[i - 1];
//			while (k > 0)
//			{
//				if (s[k] == s[i - 1])
//				{
//					next[i] = k + 1;
//					break;
//				}
//				k = next[k];
//			}
//			if (s[k] == s[i - 1])
//				next[i] = 1;
//			else
//				next[i] = 0;
//		}
//	}
//
//
//}
//
//int kmp(char* s,char* p)
//{
//	int size = strlen(p);
//	int* next = (int*)malloc(size * sizeof(int));
//	buildchar(p, next);
//
//
//	int i = 0, j = 0;
//	while (s[i] != '\0' && p[j] != '\0')
//	{
//		if (s[i] == p[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			j = next[j];
//
//			if (j == 0)
//			{
//				i++;
//				j = 0;
//			}
//		}
//	}
//	free(next);
//
//	if (p[j])
//		return -1;
//	else
//		return i - strlen(p);
//}
//
//int strStr(char* haystack, char* needle) {
//    if (needle == '\0')
//        return 0;
//    if (haystack == '\0')
//        return -1;
//    int size1 = strlen(haystack);
//    int size2 = strlen(needle);
//
//    for (int i = 0; i <= size1 - size2; i++)
//    {
//        if (haystack[i] == needle[0])
//        {
//            int x = i, y = 0;
//            for (y = 0; y < size2; x++,y++)
//            {
//                if (haystack[x] != needle[y])
//                    break;
//            }
//            if (y == size2)
//                return i;
//        }
//        /*else
//        {
//            i++;
//        }*/
//    }
//    return -1;
//}
//
//int main()
//{
//	char s[] = "mississippi";
//	char p[] = "";
//
//    //"ababcaababcaabc"
//    //"ababcaabc"
//
//
//	//buildchar(s,p);
//	//get_next_arr(s, p);
//
//	int ret = strStr(s, p);
//}

//
//
//void print(unsigned int n)
//{
//	if (n > 9)
//	{
//		print(n/10);
//	}
//	printf("%u", n);
//}
//
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);
//	print(num);
//	return 0;
//}


int minNumberInRotateArray(int* rotateArray, int rotateArrayLen) {
    int  left = 0;
    int right = rotateArrayLen - 1;
    int mid = 0;

    while (left <= right)
    {
        if (rotateArray[left] == rotateArray[mid] && rotateArray[right] == rotateArray[mid])
        {
            int min = rotateArray[left];
            for (int i = left; i <= right; i++)
            {
                if (rotateArray[i] < min)
                {
                    min = rotateArray[i];
                }
            }
            return min;
        }
        if (left + 1 == right)
            return rotateArray[right];
        mid = (left + right) / 2;
        if (rotateArray[left] > rotateArray[mid])
        {
            right = mid;
        }

        if (rotateArray[left] <= rotateArray[mid])
        {
            left = mid;
        }
        
    }
    return rotateArray[left];
    // write code here
}

int main()
{
    int arr[] = { 1,0,1,1,1 };
    int ret = minNumberInRotateArray(arr, 5);
}