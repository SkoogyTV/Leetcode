/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        int front = 1, back = n, res = 0;
        int middle = 0;
        
        while(front <= back){
            middle = front + (back - front) / 2;
            res = guess(middle);
            if(res == 0){
                break;
            }else if(res == -1){
                back = middle - 1;
            }else{
                front = middle + 1;
            }
        }
        return middle;
    }
};