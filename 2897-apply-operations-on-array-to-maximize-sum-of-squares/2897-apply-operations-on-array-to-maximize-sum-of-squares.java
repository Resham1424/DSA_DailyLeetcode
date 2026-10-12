class Solution {
    public int maxSum(List<Integer> nums, int k) {
        final int MOD = 1_000_000_007;
        final int BITS = 30;                 

        // count[b] = number of 1s in bit column b
        int[] count = new int[BITS];

        for (int num : nums) {
            for (int b = 0; b < BITS; b++) {
                if ((num & (1 << b)) != 0) {
                    count[b]++;               // found a '1' in bit position b
                }
            }
        }

        long result = 0;

        while (k-- > 0) {
            long curr = 0;

            for (int b = 0; b < BITS; b++) {
                if (count[b] > 0) {
                    count[b]--;
                    curr |= (1L << b);        // 1L so it is a long, not an int
                }
            }

            result = (result + curr * curr) % MOD;
        }

        return (int) result;
    }
}