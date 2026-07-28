class Solution {
public:
     int funct(vector<int>& nums, int L, int M) {
        int n = nums.size();

        int lBlockSum = 0;
        int mBlockSum = 0;

        //starting window from index 0 to L+M-1
        for(int i = 0; i <= L+M-1; i++) {
            if(i < L) {
                lBlockSum += nums[i];
            } else {
                mBlockSum += nums[i];
            }
        }

        int maxLeftSubSum = lBlockSum;
        int result = maxLeftSubSum + mBlockSum;

        for(int mEnd = L + M; mEnd < n; mEnd++) {
            lBlockSum += nums[mEnd-M] - nums[mEnd - M - L];
            mBlockSum += nums[mEnd] - nums[mEnd - M];

            maxLeftSubSum = max(maxLeftSubSum, lBlockSum);

            result = max(result, maxLeftSubSum + mBlockSum);
        }

        return result;

    }

    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        int n = nums.size();

        return max(funct(nums, L, M), funct(nums, M, L));
    }
};