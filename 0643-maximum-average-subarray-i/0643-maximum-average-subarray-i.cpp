class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long windowSum=0;
        for(int i=0;i<k;i++){
            windowSum+=nums[i];
        }
        long long maxSum=windowSum;
        for(int i=k;i<nums.size();i++){
            windowSum+=nums[i];
            windowSum-=nums[i-k];

            maxSum=max(maxSum,windowSum);
        }
        return (double)maxSum/k;
    }
};