class MyCircularDeque {
    vector<int> arr;
    int ft = 0, rr = 0, size = 0, cap = 0;
public:
    MyCircularDeque(int k) {
        arr.resize(k);
        cap = k;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        if(isEmpty()){
            arr[rr] = value;
            rr = ft;
        }
        else{
            ft = (ft-1 + cap) % cap;
            arr[ft] = value;
            
        }
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        if(isEmpty()){
            arr[ft] = value;
            ft = rr;
        }
        else{
            rr = (rr + 1)%cap;
            arr[rr] = value;
            
        }    
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        if (size == 1) {
            size = 0;
            return true;
        }
        ft = (ft + 1)%cap;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        if (size == 1) {
            size = 0;
            return true;
        }
        rr = (rr - 1 + cap)%cap;
        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return arr[ft];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return arr[rr];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return cap == size;
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