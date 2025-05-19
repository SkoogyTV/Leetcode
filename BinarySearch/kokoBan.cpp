#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int max_ban = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            max_ban = max(piles[i], max_ban);
        }
        int left = 1, right = max_ban;
        while (left < right)
        {
            int sum = 0;
            int k = left + (right - left) / 2;
            for (int pile : piles){
                sum += ceil(pile + k - 1);
            }
                if (sum <= h)
                {
                    right = k;
                }
                else
                {
                    left = k + 1;
                }
        }
        return left;
    }
};