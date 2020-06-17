/*


Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.
IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;
Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.
IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).
However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.
Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"
Output: "IPv4"
Explanation: This is a valid IPv4 address, return "IPv4".

Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output: "IPv6"
Explanation: This is a valid IPv6 address, return "IPv6".

Example 3:
Input: "256.256.256.256"
Output: "Neither"
Explanation: This is neither a IPv4 address nor a IPv6 address.


*/



class Solution {
public:
    string validIPAddress(string IP) {
       
        int dotcnt = 0;
        int coloncnt = 0;
        for(int i = 0 ; i < IP.length() ; i++)
        {
            if(IP[i] == '.')
                dotcnt++ ;
            else if(IP[i] == ':')
                coloncnt++ ;
        }
        
        if(dotcnt == 3 && coloncnt == 0) 
            return valid4(IP);
        
        if(dotcnt == 0 && coloncnt == 7)
            return valid6(IP) ;
        
        return "Neither" ;
    }
    
    string valid4(string IP)
    {
        int i = 0;
        int len = IP.length() ;
        
        int curr = 0;
        int num = 0;
        while( i < len )
        {
            if(IP[i] >= '0' && IP[i] <= '9')
            {
                if(num == 0 && curr == 1)
                    return "Neither" ;
                num = num*10 + (IP[i] - '0') ;
                if(num > 255)
                    return "Neither" ;  
                curr++;
            }
            else if(IP[i] == '.')
            {
                if(curr > 3 || curr == 0 || i == len-1)
                    return "Neither" ;
                curr = 0;
                num = 0;
            }
            else
                return "Neither" ;
            
            i++ ;
        }
        
        return "IPv4";
     }

    
    string valid6(string ip)
    {
        int i = 0;
        int size = ip.length() ;
        int len = 0;
        while(i < size)
        {
            if((ip[i] >= 'a' && ip[i] <= 'f') ||(ip[i] >= 'A' && ip[i] <= 'F') || (ip[i] >= '0' && ip[i] <= '9'))
            {
                if(++len > 4)
                    return "Neither" ;
            }
            else if(ip[i] == ':')
            {
                if(len == 0 || len > 4)
                    return "Neither" ;
                len = 0;
            }
            else
                return "Neither" ;
            i++;
        }
        
        return "IPv6" ;
    }
};
