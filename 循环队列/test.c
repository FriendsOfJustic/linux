#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

typedef struct {
    int* a;
    int Front;
    int Rear;
    int k;
} MyCircularQueue;
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* p = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    p->a = (int*)malloc((k + 1) * sizeof(int));
    p->Front = 0;
    p->Rear = 0;
    p->k = k;
    return p;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;
    else
    {
        obj->a[obj->Rear] = value;
        obj->Rear += 1;
        obj->Rear = obj->Rear % (obj->k + 1);
        return true;

    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;
    else
    {
        obj->Front++;
        obj->Front = obj->Front % (obj->k + 1);
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;
    return obj->a[obj->Front];


}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;
    if (obj->Rear == 0)
        return obj->a[obj->k];
    else
        return obj->a[obj->Rear-1];

}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->Front == obj->Rear;

}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->Rear + 1) % (obj->k + 1) == obj->Front;

}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}


int main()
{
    MyCircularQueue* ps=NULL;
    ps = myCircularQueueCreate(3);
   /* myCircularQueueEnQueue(ps, 1);
    myCircularQueueEnQueue(ps, 2);
    int ret=myCircularQueueRear(ps);*/
    int ret1 = myCircularQueueFront(ps);
}