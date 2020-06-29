*/


Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:
Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.


*/


class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i = 1; i * i<=n; i++){ // O(sqrt(n))
            squares.push_back(i * i);
        }
        vector<int> dp(n + 1,INT_MAX); // 0(n)
        dp[0] = 0;
        for(int amount = 1; amount<=n; amount++){ //O(n)
            int current_best = INT_MAX;
            for(int j = 0; j<squares.size(); j++){//O(sqrt(n))
                int square = squares[j];
                if(amount - square >= 0 && current_best > dp[amount - square] + 1){
                    current_best = dp[amount-square]  + 1; 
                }
            }
            dp[amount] = current_best;
        }
        return dp[n];
    }
};
