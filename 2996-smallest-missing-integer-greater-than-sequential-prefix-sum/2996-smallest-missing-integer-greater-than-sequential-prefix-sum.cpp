class Solution {
public:
    int missingInteger(vector<int>& nums) {
         int n = nums.size();

        int sequential = nums[0];
        for(int j = 1; j < n; j++) {
            if(nums[j] == nums[j-1] + 1) {
                sequential += nums[j];
            } else {
                break;
            }
        }

        sort(begin(nums), end(nums));
        for(int i = 0; i < n; i++) {
            if(nums[i] == sequential)
                sequential++;
        }

        return sequential;
    }
};