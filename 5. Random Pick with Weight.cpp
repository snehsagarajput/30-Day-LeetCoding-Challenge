/*

Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:
1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.

Example 1:
Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]

Example 2:
Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]

Explanation of Input Syntax:
The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.


*/

class Solution {
    vector<int> w_sum;
    int sum;
public:
    Solution(vector<int>& w) {
        sum = 0;
        for (int i : w)
        {
            sum += i;
            w_sum.push_back(sum);
        }
    }
    
    int pickIndex() {
        int idx = rand() % sum;
        return binarySearch(idx + 1);
    }
    int binarySearch(int val)
    {
        int l = 0;
        int r = w_sum.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (w_sum[mid] < val)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
