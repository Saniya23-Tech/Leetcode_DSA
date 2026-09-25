class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int count = 1;
        int maxFreq = 0;
        int answer = 0;

        for (int i = 1; i <= nums.size(); i++) {

            if (i < nums.size() && nums[i] == nums[i - 1]) {
                count++;
            }
            else {
                if (count > maxFreq) {
                    maxFreq = count;
                    answer = count;
                }
                else if (count == maxFreq) {
                    answer += count;
                }

                count = 1;  //reset count back again to check another numbers 
            }
        }

        return answer;
    }
};