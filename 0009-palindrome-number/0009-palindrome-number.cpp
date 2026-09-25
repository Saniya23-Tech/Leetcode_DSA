class Solution {
public:
    bool isPalindrome(int x) {
        if(x <0) return false;

        int original =x;
        long long reversednum =0;

        while(x > 0) {
            int digit = x%10;
            reversednum = (reversednum * 10) + digit;
            x /= 10;
        }
        return original == reversednum;
    }
};