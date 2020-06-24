/*


The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
_____________________
-2(K)	| -3	 |  3
_____________________
 -5	  | -10	 |  1
_____________________
 10	  |  30	 | -5(P)
_____________________

Note:
The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.


*/


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector minInitHealth(m, vector<int>(n,0));
        for(int i=m-1; i>=0; i--)
        {
            for (int j=n-1; j>=0; j--)
            {
                if (i == m-1 && j == n-1)
                {
                    minInitHealth[i][j]=max(1, 1 - dungeon[i][j]);
                }  
                else if (i == m-1)
                {
                    minInitHealth[i][j]=max(1, minInitHealth[i][j+1]-dungeon[i][j]);
                }  
                else if (j == n-1)
                {
                    minInitHealth[i][j]=max(1, minInitHealth[i+1][j]-dungeon[i][j]);
                }  
                else
                {
                    minInitHealth[i][j]=max(1, min(minInitHealth[i+1][j],minInitHealth[i][j+1])-dungeon[i][j]);
                }  
            }
        }
        
        return  minInitHealth[0][0];
    }
};
