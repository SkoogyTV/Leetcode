//Author: Sean Skaugen
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size()-1;
        if(nums[0] < nums[n]){ // if this is list is not rotated
            return nums[0];
        }
        return searchBin(nums,0,n);
    }

    int searchBin(vector<int>& nums, int left, int right){
        //we are looking for the local min!
        int middle = left + (right - left) / 2;
        if(left == right){ // We are at local min
            return nums[left];
        }
        if(nums[middle] < nums[right]){ //middle is less than the right so min has to be before
            return searchBin(nums, left, middle);
        }
        return searchBin(nums,middle+1,right); // middle > right so min is in the right side
    }
};