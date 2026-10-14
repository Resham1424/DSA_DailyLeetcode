class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());   //sorting to get the largest 3rd value
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                count++;
            }
            if(count==3){
                return nums[i];
            }
        }
        return nums[0];
    }
};