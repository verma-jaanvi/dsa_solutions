class MyCircularQueue {
    vector<int> arr;
    int ft = -1;
    int rr = -1;
    int size = 0;
    int cap = 0;
public:
    MyCircularQueue(int k) {
        arr.resize(k);
        cap = k;
        ft = rr = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()){
           return false; 
        }
        arr[rr] = value;
        rr = (rr + 1)% cap;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        ft = (ft+1)%cap;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : arr[ft];
    }
    
    int Rear() {
        int idx = (rr-1 + cap)%cap;
        return isEmpty() ? -1 : arr[idx];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */