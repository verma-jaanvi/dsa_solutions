class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int half = n/2;
        string vowel = "aeiouAEIOU";
        int firsthalf = 0;
        for(int i = 0; i<half; ++i){
            if(vowel.find(s[i]) != string::npos)    firsthalf++;
        }

        int secondhalf = 0;
        for(int i = half; i<n; ++i){
            if(vowel.find(s[i]) != string::npos)    secondhalf++;
        }

        return firsthalf == secondhalf;
    }
};