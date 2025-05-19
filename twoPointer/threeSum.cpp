#include <vector>
#include <algorithm>
class Solution {
    public:
        std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
            //three sum problem

            std::sort(nums.begin(), nums.end());
            std::vector<std::vector<int>> result;

            for(int i = 0; i < nums.size()-2; i++){
                
                //do not need to look at duplicates
                if(i > 0 && nums[i] == nums[i-1]){continue;}

                int left = i+1;
                int right = nums.size()-1;

                //now it is just the two sum problem with a duplicate problem
                while(left < right){
                    int sum = nums[i] + nums[left] + nums[right];
                    //case 1: > 0
                    if(sum > 0){
                        right--;
                    }
                    //case 2: < 0
                    else if(sum < 0){
                        left++;
                    }
                    else{
                        result.push_back({nums[i],nums[left],nums[right]});
                        
                        left++;
                        right--;

                        while(left < right && nums[left] == nums[left-1]){
                            left++;
                        }
                        while(left < right && nums[right] == nums[right+1]){
                            right--;
                        }
                    }
                
                }
            }

            return result;
        }
    };