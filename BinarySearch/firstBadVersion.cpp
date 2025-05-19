//Author: Sean Skaugen
//Cool version of Binary search used for tracking last known things!
class Solution {
public:
    int firstBadVersion(int n) {
    
        int left = 1, right = n, mid = 0;
        while(left < right){
            mid = left + (right - left) / 2;
            bool bad = isBadVersion(mid);
            if(bad){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};