#include <string>
class Solution {
    public:
        bool isPalindrome(std::string s) {
            //two pointer approach!

            int left = 0;
            int right = s.size() -1;

            while(left < right){
                //move the char until we find a alphaNumeric
                while(left < right && !std::isalnum(s[left])){
                    left++;
                }
                while(left < right && !std::isalnum(s[right])){
                    right--;
                }
                if(std::tolower(s[left]) != std::tolower(s[right])){
                    return false;
                }
                left++;
                right--;
            }
            return true;
        }
    };