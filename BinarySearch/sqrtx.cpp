//Author: Sean Skaugen
class Solution {
public:
    int mySqrt(int x) {

            if(x == 0) return 0;

            int front = 1, back = x, res = 1;
            int middle = 0;

            while(front <= back)
            {
                middle = front + (back - front) / 2;
                if(middle <= x / middle){
                    res = middle;
                    front = middle + 1;
                }
                else{
                    back = middle - 1;
                }
            }
            return res;
    }
};