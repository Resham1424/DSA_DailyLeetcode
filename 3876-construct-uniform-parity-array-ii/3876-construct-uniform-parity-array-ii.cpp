class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       int minEl = *min_element(begin(nums1), end(nums1));

        if(minEl % 2 == 1) { 
            return true; 
        }

        for(int &num : nums1) {
            if(num % 2 == 1) {
                return false;
            }
        }

        return true;
    }
};