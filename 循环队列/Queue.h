#define _CRT_SECURE_NO_WARNINGS 1


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
    if (myCircularQueueIsEmpty)
        return false;
    return obj->Front;


}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty)
        return false;
    if (obj->Rear == 0)
        return obj->a[obj->k];
    else
        return obj->a[obj->Rear];

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
