#include<vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return binSearch(nums,0,nums.size()-1);
    }

    int binSearch(vector<int>& nums, int left, int right){
        
        int middle = left + (right - left) / 2;

        if(left == right) {return left;}
        if(nums[middle] > nums[middle+1]){
            return binSearch(nums,left,middle);
        }
        return binSearch(nums,middle+1,right);
    }
};