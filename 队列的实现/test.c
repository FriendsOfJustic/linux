#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

int main()
{
	Queue Q;
	QueueInit(&Q);
	QueuePush(&Q,1);
	QueuePush(&Q, 2);
	QueuePush(&Q, 3);
	QueuePush(&Q, 4);
	QueuePush(&Q, 5);
	QueuePop(&Q);

	printf("%d\n", QueueFront(&Q));
	printf("%d\n", QueueBack(&Q));
	printf("%d\n", QueueSize(&Q));

	QueueDestroy(&Q);


}