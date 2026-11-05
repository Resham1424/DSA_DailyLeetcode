class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
       ranges::sort(arr2);
        arr2.push_back(INT_MAX);
        int cnt = 0;
        for(int a : arr1){
            if(*ranges::lower_bound(arr2, a - d) > a + d){
                cnt++;
            }
        }
        return cnt; 
    }
};