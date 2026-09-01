class Solution {
public:
    bool isPerfectSquare(int n) {
       long long low=1,high=n;
       while(low<=high){
        long long mid=low+(high-low)/2;
        long long square=mid*mid;
        if(square==n){
            return true;
        }else if(square<n){
           low=mid+1;
       }else{
           high=mid-1;
       }
       }
       return false;
    }
};