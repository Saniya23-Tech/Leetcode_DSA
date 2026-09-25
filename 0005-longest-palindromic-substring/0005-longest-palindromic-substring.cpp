class Solution {
public:
    string expandAroundCenter(string s , int left, int right) {
        while( left >=0 && right <s.length() && s[left] == s[right]) { //until the character matches stay in the boundary
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }

    string longestPalindrome(string s) {
        if(s.empty()) return "";

        string longest = "";
        for(int i=0; i<s.length(); i++) {
            //case1: ODD Palindrome
            string odd_P = expandAroundCenter(s,i,i);
            if(odd_P.length() > longest.length()) {
                longest = odd_P;
            }

            //case 2 : Even length palindrome 
            string even_P = expandAroundCenter(s,i,i+1);
            if(even_P.length() > longest.length()) {
                longest = even_P;
            }
        }
        return longest;
    }
};