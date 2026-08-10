class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> t(n+1, false);

        //Base case . n== 0, return false
        //i == 0
        t[0] = false; //base case

        for(int i = 1; i < n+1; i++) {

            for(int k = 1; k*k <= i; k++) {
                if(t[i - (k*k)] == false) {
                    t[i] = true;
                    break;
                }
            }
        }

        return t[n]; 
    }
};