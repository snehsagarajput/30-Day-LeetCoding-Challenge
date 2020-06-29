*/


Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.

Example 1:
Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]

Example 2:
Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.


*/



class Solution {
    stack<string> st;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> um;
    
public:
    void buildGraph(string str){
        while(!um[str].empty()){
            string temp = um[str].top();
            um[str].pop();
            buildGraph(temp); // make it point to the next iternary
        }
        st.push(str);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // hash the iteranary
        int l = tickets.size();
        for(int i = 0; i < l; i++){
            um[tickets[i][0]].push(tickets[i][1]);
        }
        
        buildGraph("JFK");
        
        vector <string> itinerary; 
        while(!st.empty()){
            itinerary.push_back(st.top());
            st.pop();
        }
        return itinerary;
    }
};
