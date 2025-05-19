#include <vector>
#include <algorithm>
class Solution {
    public:
        int trap(std::vector<int>& height) {
            
            if(height.size() < 2){return 0;} 

            std::vector<int>prefix(height.size());
            std::vector<int>suffix(height.size());
            int rslt = 0;

            //prefix
            prefix[0] = height[0];
            for(int i = 1; i < height.size(); i++){
                if(prefix[i-1] > height[i]){
                    prefix[i] = prefix[i-1];
                }else{
                prefix[i] = height[i];
                }
            }
            suffix[height.size()-1] = height[height.size()-1];
            for(int i = height.size()-2; i >= 0; i--){
                if(suffix[i+1] > height[i]){
                    suffix[i] = suffix[i+1];
                }else{
                suffix[i] = height[i];
                }
            }

            //now we do the calc
            for(int i = 0; i < height.size(); i++){
                rslt += std::min(prefix[i], suffix[i]) - height[i];
            }
            return rslt;
        }
    };