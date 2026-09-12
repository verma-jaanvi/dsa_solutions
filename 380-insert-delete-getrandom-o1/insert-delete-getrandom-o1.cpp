class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> mpp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.find(val) == mpp.end()){
            nums.push_back(val);
            mpp[val] = nums.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mpp.find(val) == mpp.end()){
            return false;
        }
        int lastelem = nums.back();
        int idx = mpp[val];

        nums[idx] = lastelem;
        mpp[lastelem] = idx;

        nums.pop_back();
        mpp.erase(val);

        return true;
    }
    
    int getRandom() {
        int ranidx = rand() % nums.size();
        return nums[ranidx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */