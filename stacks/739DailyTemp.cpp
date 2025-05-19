//Author: Sean Skaugen
//Question 739: Daily Tempss
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            
            vector<int> result(temperatures.size(),0);
            stack<int> index_holder;

            index_holder.push(0);
            for(int i = 1; i < temperatures.size(); i++){
                while(!index_holder.empty() && temperatures[i] > temperatures[index_holder.top()]){
                    result[index_holder.top()] = i - index_holder.top();
                    index_holder.pop();   
                }
                    index_holder.push(i);

            }
            return result;
        }
    };