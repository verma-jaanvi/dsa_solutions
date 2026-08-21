class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i = 0, j = tokens.size()-1;
        int score = 0;
        sort(tokens.begin(), tokens.end());
        
        // Fix 1: Loop should continue as long as i <= j to process the final token
        while(i <= j) {
            if(power >= tokens[i]){
                power -= tokens[i++];
                score++;
            } 
            // Fix 2: Only sacrifice score for power if there are still other tokens to buy (i < j)
            else if(score >= 1 && i < j){
                power += tokens[j--];
                score--;
            } 
            // Fix 3: If you can neither buy nor sell, the game ends. Don't skip tokens.
            else {
                break;
            }
        }
        return score;
    }
};