class Solution {
public:
    vector<int> partitionLabels(string str) {
        unordered_set<char> s;
        for(char ch : str){
            s.insert(ch);
        }
        vector<pair<int, int>> vec;
        for(char ch : s){
            size_t ft = str.find(ch);
            size_t en = str.rfind(ch);
            vec.push_back({ft, en});
        }
        sort(vec.begin(), vec.end());
        vector<pair<int, int>> par;
        for(auto [st, en] : vec){
            if(!par.empty() && par.back().second > st){
                par.back().second = max(par.back().second, en);
            }else{
                par.push_back({st, en});
            }
        }
        vector<int> res;
        for(auto [st, en] : par){
            res.push_back(en-st+1);
        }
        return res;
    }
};