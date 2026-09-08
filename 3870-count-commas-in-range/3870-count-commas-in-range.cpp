class Solution {
public:
    int countCommas(int n) {
       int result = 0;

        int lower  = 1000;
        int commas = 1;

        while(lower <= n) {
            int upper = lower*1000 - 1;
            if(upper > n) upper = n;

            int countNumbers = upper - lower + 1;
            result += (countNumbers * commas);

            lower *= 1000;
            commas++;
        }

        return result; 
    }
};