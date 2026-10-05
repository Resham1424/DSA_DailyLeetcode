class Solution {
public:
        bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> t(n + 1, vector<bool>(n + 1, false));
        
        t[n][0] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int open = 0; open <= n; open++) {
                bool isValid = false;

                if (s[i] == '*') {
                    isValid |= t[i + 1][open + 1];
                    if (open > 0) {
                        isValid |= t[i + 1][open - 1];
                    }
                    isValid |= t[i + 1][open];
                } else {
                    if (s[i] == '(') {
                        isValid |= t[i + 1][open + 1];
                    } else if (open > 0) {
                        isValid |= t[i + 1][open - 1]; 
                    }
                }
                t[i][open] = isValid;
            }
        }

        return t[0][0];
    }
};