//author: Sean Skaugen
//Question: Car Fleet
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed) {
            //we need to create a vector of pairs so we can sort the vehicles descending

            vector<pair<int,int>> fleet_holder;
            stack<double> times;

            for(int i = 0; i < position.size(); i++){
                fleet_holder.push_back(make_pair(position[i], speed[i]));
            }

            sort(fleet_holder.begin(), fleet_holder.end(), [](const pair<int,int>& a, const pair<int,int>&b){
                return a.first > b.first;
            });

            for(int i = 0; i < fleet_holder.size(); i++){
                //get the time = (target - position) / speed!
                double time = (double)(target - fleet_holder[i].first) / fleet_holder[i].second;

                if(!times.empty() && time <= times.top()){
                    continue;
                }else{
                    times.push(time);
                }
            }
            return times.size();
        }
    };