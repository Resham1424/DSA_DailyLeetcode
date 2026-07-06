class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long windowSum=0;
        long long maxSum=0;

        for(int i=0;i<k;i++){
            windowSum+=nums[i];
            freq[nums[i]]++;
        }
        if (freq.size() == k)
            maxSum = windowSum;
            
        for(int i=k;i<nums.size();i++){
            windowSum+=nums[i];
            freq[nums[i]]++;

            windowSum-=nums[i-k];
            freq[nums[i - k]]--;
            
             if (freq[nums[i - k]] == 0)
                freq.erase(nums[i - k]);

            // Check if all elements are distinct
            if (freq.size() == k)
                maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }
};