class Solution {
public:
    void getAllCombinations(vector<int>& candidates, int idx, int target, vector<vector<int>>& ans, vector<int>& combin) {
        if (target == 0) {
            ans.push_back(combin);
            return;
        }

        if (idx >= candidates.size() || target < 0) return;

        // Include
        combin.push_back(candidates[idx]);
        getAllCombinations(candidates, idx + 1, target - candidates[idx], ans, combin);
        combin.pop_back();

        // Exclude
        int next = idx + 1;
        while (next < candidates.size() && candidates[next] == candidates[idx]) next++;

        getAllCombinations(candidates, next, target, ans, combin);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combin;
        getAllCombinations(candidates, 0, target, ans, combin);
        return ans;
    }
};