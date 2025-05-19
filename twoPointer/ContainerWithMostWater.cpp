//Author: Sean Skaugen
//https://leetcode.com/problems/container-with-most-water/description/

#include <vector>
#include <cmath>
class Solution {
    public:
        int maxArea(std::vector<int>& height) {
            
            int left = 0;
            int right = height.size()-1;
            int max_area = 0;
            
            while (left < right)
            {
                //we need to calulate the area
                int curr_area = (right - left) * std::min(height[left],height[right]);
                max_area = std::max(curr_area,max_area);
                
                //case 1: left is larger
                if(height[left] > height[right]){
                    right--;
                }else{
                    left++;
                }
            }
            
            return max_area;
        }
    };

    //Done