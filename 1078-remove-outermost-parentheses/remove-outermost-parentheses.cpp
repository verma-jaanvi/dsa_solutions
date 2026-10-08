class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int count=0;
        int i=0;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]=='(')
            {
                count++;
            }
            else
            {
                count--;
            }
            if(count==0)
            {
                ans+=s.substr(i+1,j-i-1);
                i=j+1;
            }
        }
        return ans;
    }
};