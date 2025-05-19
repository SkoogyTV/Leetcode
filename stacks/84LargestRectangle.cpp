//Author: Sean Skaugen
// 84: Largest Histogram

#include <vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            
            int MaxArea = 0;
            stack<int> index_holder;

            index_holder.push(-1);
            for(int i = 0; i < heights.size(); i++){
                //cases
                // height[top of stack] > height[i]
                    while(index_holder.top() != -1 && heights[index_holder.top()] > heights[i]){
                        //compute max area!
                        int height = heights[index_holder.top()];
                        index_holder.pop();
                        int curr_area = (i - index_holder.top() -1) * height; 
                        MaxArea = max(curr_area,MaxArea);
                    }
                     index_holder.push(i);    
                }

            while(index_holder.top() != -1){
                int height = heights[index_holder.top()];
                index_holder.pop();
                int curr_area = (heights.size() - index_holder.top()-1) * height;
                MaxArea = max(curr_area,MaxArea);
            }
                return MaxArea;
                } 
            };



            //Author: Sean Skaugen
// 84: Largest Histogram

#include <vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int MaxArea = 0;
            stack<int> index_holder;
    
            index_holder.push(-1);
            for(int i = 0; i < heights.size(); i++){
                // When current height is less than the previous one
                while(index_holder.top() != -1 && heights[index_holder.top()] > heights[i]){
                    int curr_pos = index_holder.top();
                    index_holder.pop();
                    int curr_area = heights[curr_pos] * (i - index_holder.top() - 1);
                    MaxArea = max(curr_area, MaxArea);
                }
                index_holder.push(i);    
            }
    
            // Process remaining elements in stack
            while(index_holder.top() != -1){
                int curr_pos = index_holder.top();
                index_holder.pop();
                int curr_area = heights[curr_pos] * (heights.size() - index_holder.top() - 1);
                MaxArea = max(curr_area, MaxArea);
            }
            
            return MaxArea;
        }
    };