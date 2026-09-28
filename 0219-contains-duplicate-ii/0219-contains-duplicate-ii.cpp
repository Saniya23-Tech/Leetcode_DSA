class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;

        for (int i = 0; i < nums.size(); i++) {
            // if present in set 
            if (st.count(nums[i])) {
                return true;
            }
            
            // Add current element
            st.insert(nums[i]);
            
            // Window size is greater than the k 
            if (st.size() > k) {
                st.erase(nums[i - k]);
            }
        }
        return false;
    }
};