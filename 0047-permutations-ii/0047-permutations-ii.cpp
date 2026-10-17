class Solution {
public:
vector<vector<int>> ans;
vector<int> temp;
vector<bool> used;

void solve(vector<int> &nums) {
    if(temp.size() == nums.size()) {
        ans.push_back(temp);
        return;
    }

    for(int i=0; i< nums.size(); i++) {
        if(used[i])
        continue;

        //skip duplicate branch 
        if( i >0 && nums[i] == nums[i-1] && !used[i-1])
        continue;
    
    used[i] = true;
    temp.push_back(nums[i]);

    solve(nums);
    temp.pop_back();
    used[i] = false;
}
}


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        used.resize(nums.size() , false);
        solve(nums);
    return ans;

    
    }
};