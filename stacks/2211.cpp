//author: Sean Skaugen
// Question: 2211 Count Colllisions on a road

#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        int countCollisions(string directions) {
            int result = 0;
            stack<char> dir_stack;

            dir_stack.push(directions[0]);
            
            for(int i = 1; i < directions.size(); i++){
                char curr = directions[i];
                //case1:
                if(dir_stack.top() == 'R' && curr == 'L'){
                    //right -> <- Left
                    result += 2;
                    dir_stack.pop();
                    curr = 'S';
                }
                else if(dir_stack.top() == 'S' && curr == 'L'){
                    result += 1;
                    dir_stack.pop();
                    curr = 'S';
                }
                while(!dir_stack.empty() && dir_stack.top() == 'R' && curr == 'S'){
                    result += 1;
                    dir_stack.pop();
                }
                dir_stack.push(curr);
                }
                return result;
         }
    }; 

    //this is an o(n) solution with o(n) space complexity as well.