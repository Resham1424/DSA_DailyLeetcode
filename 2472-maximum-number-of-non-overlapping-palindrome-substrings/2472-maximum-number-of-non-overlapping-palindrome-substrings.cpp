class Solution {
public:
   bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    //max non-overlapping palindromic pieces (length >= k) from s[i..j]
    int solve(const string& s, int k, int i, int j, vector<vector<int>>& t) {
        int n = s.size();
        if (i >= n || j >= n) 
            return 0;
            
        if (t[i][j] != -1) 
            return t[i][j];

        if (isPalindrome(s, i, j)) {
            int growWindow  = solve(s, k, i, j + 1, t);
            int takeIt      = 1 + solve(s, k, j + 1, j + k, t);
            int slideWindow = solve(s, k, i + 1, j + 1, t);

            return t[i][j] = max({growWindow, takeIt, slideWindow});
        }

        int slideWindow = solve(s, k, i + 1, j + 1, t);
        int growWindow  = solve(s, k, i, j + 1, t);

        return t[i][j] = max(slideWindow, growWindow);
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1)
            return n; //each character can be a substring

        vector<vector<int>> t(n, vector<int>(n, -1));

        return solve(s, k, 0, k - 1, t);
    }
};