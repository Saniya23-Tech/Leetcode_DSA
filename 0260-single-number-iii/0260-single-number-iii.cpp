class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int result = 0;
        for (int val : nums) {
            result ^= val;
        }

        
        unsigned int positionBit = result & -((unsigned int)result);

        int num1 = 0, num2 = 0;
        for (int val : nums) {
            if (val & positionBit) {
                num1 ^= val;
            } else {
                num2 ^= val;
            }
        }

        return {num1, num2};
    }
};
