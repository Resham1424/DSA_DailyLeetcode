class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         int i = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for (int j = 0; j < nums.size(); j++) {

            if (nums[j] == 0)
                zeroCount++;

            while (zeroCount > k) {
                if (nums[i] == 0)
                    zeroCount--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};