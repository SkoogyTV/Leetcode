//Author: Sean Skaugen
// find-first-and-last-position-of-element-in-sorted-array
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        if(nums.size() < 2){
            if(nums[0] == target) return {0,0};
            return {-1,-1};
        }
        vector<int>res;
        res.push_back(binSearch(nums,0,nums.size()-1,target,true));
        res.push_back(binSearch(nums,0,nums.size()-1,target,false));
        return res;
    }

        int binSearch(vector<int>& nums,int left, int right,int target, bool first){

        int middle = left + (right - left) / 2;
        
        if(left > right){return -1;}
        if(first){ //first ends either when first = end or when nums[mid] != nums[mid + 1]
            if((middle == 0 || nums[middle-1] != target) && nums[middle] == target){
                return middle;
            }else{
                if(nums[middle] >= target){
                    return binSearch(nums,left,middle-1,target,true);
                }
                return binSearch(nums,middle+1,right,target,true);
            }
        }else{
            if((middle == nums.size()-1 || nums[middle] != nums[middle+1]) && nums[middle] == target){
            return middle;
        }else{
            if(nums[middle] > target){
                return binSearch(nums,left,middle-1,target,false);
            }
            return binSearch(nums,middle+1,right,target,false);
        }
        }
        
    }
};