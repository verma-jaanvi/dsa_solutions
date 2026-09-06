class Solution {
public:
    string decodeString(string s) {
        stack<pair<string ,int>> st;
        int val = 0;
        string curr = "";
        for(int i = 0; i<s.length(); ++i){
            char ch = s[i];
            if(ch == '['){   
                st.push({curr,val});
                curr ="";

                val = 0;
            }else if(isdigit(ch)){
                val = val * 10 + (ch- '0');
            }else if(ch == ']'){
                string al =  st.top().first;
                int rep = st.top().second;
                st.pop();

                string temp = "";
                for(int j = 0; j<rep; ++j){
                    temp += curr;
                }
                curr = al + temp;
            }else{
                curr += ch;
            }

        }
        return curr;
    }
};