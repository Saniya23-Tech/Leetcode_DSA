class Solution {
public:
    set<vector<int>> s; 

    void getAllCombinations(vector<int> &arr, int idx, int tar,
                            vector<vector<int>> &ans, vector<int> &combin) {

        if (tar == 0) {
            if (s.find(combin) == s.end()) {
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }

        if (idx >= arr.size() || tar < 0)
            return;

        combin.push_back(arr[idx]);
        getAllCombinations(arr, idx, tar - arr[idx], ans, combin);
        combin.pop_back();

        getAllCombinations(arr, idx + 1, tar, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> combin;
        getAllCombinations(arr, 0, tar, ans, combin);
        return ans;
    }
};
