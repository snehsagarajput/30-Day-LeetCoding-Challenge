/*


A robot is located at the top-left corner of a m x n grid (marked S('Start') in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked F('Finish') in the diagram below).

How many possible unique paths are there?

_____________________________
| S |   |   |   |   |   |   |
|_S_|___|___|___|___|___|___|
|   |   |   |   |   |   |   |
|___|___|___|___|___|___|___|
|   |   |   |   |   |   | F |
|___|___|___|___|___|___|_F_|

Above is a 7 x 3 grid. How many possible unique paths are there?

Example 1:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:
Input: m = 7, n = 3
Output: 28

Constraints:
1 <= m, n <= 100
It's guarantee that the answer will be less than or equal to 2 * 10 ^ 9.

*/


class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <=0 || n <= 0) return 0;
        long long res = 1;
        for(int i = n; i < m+n-1 ; i++){
            res = res * i / (i- n + 1);
        }
        return (int)res;
    }
};
