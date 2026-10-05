class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        vector<int> vec;

        int score = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(') {
                vec.push_back(score);
                score = 0;
            } else {
                if (s[i-1] == '(') { 
                    score = vec.back() + 1;
                } else {
                   
                    score = vec.back() + (2 * score);
                }
                vec.pop_back();
            }
        }
        return score;
    }
};