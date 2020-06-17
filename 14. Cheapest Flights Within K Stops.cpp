/*


There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.
Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200

Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500

Constraints:
The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.


*/


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        
        for(int i = 0; i <= K; i++) {
            vector<int> tmp = distance;
            for (auto& flight : flights) {
                int u = flight[0], v = flight[1], w = flight[2];
                if (distance[u] != INT_MAX && tmp[v] > distance[u] + w) {
                    tmp[v] = distance[u] + w;
                }
            }
            distance = tmp;
        }
        
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
