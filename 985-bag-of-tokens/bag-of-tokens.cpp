class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i = 0, j = tokens.size()-1;
        int score = 0;
        sort(tokens.begin(), tokens.end());
        while(i <= j){
            if(power >= tokens[i]){
                power -= tokens[i++];
                score++;
            }else if(score >= 1 && i < j){
                power += tokens[j--];
                score--;
            }else{
                break;
            }
        }
        return score;
    }
};