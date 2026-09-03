class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char ch : tasks){
            freq[ch - 'A']++;
        }
        int maxF = *max_element(freq.begin(), freq.end());
        int cnt = count(freq.begin(), freq.end(), maxF);
        return max( (int)tasks.size(), (maxF - 1) * (n + 1) + cnt);
        
    }
};