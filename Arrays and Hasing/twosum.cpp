//twoSum

#include <vector>
#include <Unordered_map>

class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            
            std::vector<int> result;
            std::unordered_map<int,int> num_holder;
            for(int i = 0; i < nums.size(); i++){
                int comp = target - nums[i];
                if(num_holder.find(comp) != num_holder.end()){
                    result.push_back(num_holder[comp]);
                    result.push_back(i);
                    break;
                }
                else{
                    num_holder.insert({nums[i],i});
                }
            }
            return result;
        }
    };

    //Time complexity is O(n) very fast we like that!