#define _CRT_SECURE_NO_WARNINGS 1
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

#include<stdio.h>
int fun(int x, int y,int z)  //153 3 100
{
	int count = 0;
	for (int i = 0; i < y; i++)
	{
		int b = 1;
		int m = x / z;
		for (int j = 0; j < y; j++)
		{
			b = b * m;
		}
		count += b; //1 6
		x = x - m * z; //53 
		z = z /10;  //10

	}
	return count;

}
int main()
{
	int i,a,j;
	for (i = 100000; i >0; i--)
	{
		int p = 100000;
		for (j = 0; j <= 6; j++)
		{
			if(i/p!=0)
			{
				a = 6 - j;
				break;     //几位数
			}
			if(i/p==0)
			{
				p = p / 10;
			}
		}
		int ret = fun(i, a, p);
		if (fun(i, a, p) == i)
		{
			printf("%d ", i);
		}
	}
	
}