/*


Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:
Input: [2,2,3,2]
Output: 3

Example 2:
Input: [0,1,0,1,0,1,99]
Output: 99


*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        long ans;
        int x, t;
        ans=0;
        int p=0;
        for(int i=0;i<32;i++)
        {
            t=0;
            for(int j=0;j<n;j++)
            {
                x=nums[j]&1;
                t=t+x;
                nums[j]=nums[j]>>1;
            }
            t=t%3;
            ans=ans+t*pow(2,p);
            p++;
        }
        return ans;
    }
};
