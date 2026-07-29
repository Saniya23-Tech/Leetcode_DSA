class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int bitcount = 0;

            for (int val : nums) {
                if ((val >> i) & 1) {
                    bitcount++;
                }
            }

            if ((bitcount % 3) != 0) {
                result |= (1 << i);
            }
        }
        return result;
    }
};
