class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        int minL=INT_MAX;
        int sum=0;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                minL=min(minL,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return minL==INT_MAX?0:minL;
    }
};