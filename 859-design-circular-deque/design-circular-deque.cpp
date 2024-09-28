class MyCircularDeque {
public:
int size;
vector<int> dq;
int front;
int rear;
int currsize;
    MyCircularDeque(int k) {
        size=k;
        dq=vector<int>(size,0);
        front=0; rear=size-1;
        currsize=0;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        front=(front+size-1)%size;
        dq[front]=value;
        currsize++; return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        rear=(rear+1)%size;
        dq[rear]=value;
        currsize++; return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        front=(front+1)%size;
        currsize--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        rear=(rear+size-1)%size;
        currsize--; return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return dq[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return dq[rear];
    }
    
    bool isEmpty() {
        if(currsize==0) return true;
        return false;
    }
    
    bool isFull() {
        if(currsize==size) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */