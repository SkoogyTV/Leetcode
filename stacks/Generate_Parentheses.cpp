#include <vector>
#include <string>
using namespace std;

void backtrack(vector<string>& result, string current, int open, int closed, int n){
    //base case
    if(current.length() == n * 2){
        result.push_back(current);
        return;
    }
    //case open > closed
    if(open < n){
        backtrack(result, current + "(", open + 1, closed, n);
    }
    
    if(closed < open){
        backtrack(result, current + ")", open, closed + 1, n);
    }

}

class Solution {
    public:
        vector<string> generateParenthesis(int n){
            vector<string> rslt;
            
            backtrack(rslt, "", 0, 0, n);
            return rslt;
                
        }
    };