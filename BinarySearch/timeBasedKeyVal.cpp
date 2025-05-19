//Author: Sean Skaugen
// Question: 

#include <unordered_map>
#include <string>
using namespace std;

class TimeMap {

private:

    unordered_map<string,vector<pair<string,int>>> parser;         
public:
    TimeMap() {
        //I can create a dictionary of dictonaries!
    }
    
    void set(string key, string value, int timestamp) {
        parser[key].push_back(make_pair(value,timestamp));
    }
    
    string get(string key, int timestamp) {
        //this is the class with all the logic of this function!
        string res = "";
        //we need to check and see if the key exits
        if(parser.find(key) != parser.end()){
            //now we do binary search!
            vector<pair<string,int>>& curr_vec = parser[key];
            int left = 0;
            int right = curr_vec.size()-1;

            while(left <= right){
                int mid = left + (right - left) / 2;

                if(curr_vec[mid].second <=timestamp){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            if(right >= 0){
                res = curr_vec[right].first;
            }
        }
        return res;
}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestam
 * p);
 */