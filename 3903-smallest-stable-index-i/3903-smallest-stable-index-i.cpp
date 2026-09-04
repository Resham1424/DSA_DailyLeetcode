class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int maxEle = nums[0];
            int minEle = nums[i];

            for (int j = 0; j <= i; j++) {
                maxEle = max(maxEle, nums[j]);
            }
            
            for (int j = i; j < n; j++) {
                minEle = min(minEle, nums[j]);
            }

            if (maxEle - minEle <= k) {
                return i;
            }
        }

        return -1;
    }
};