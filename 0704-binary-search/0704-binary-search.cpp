class Solution {
public:
    int search(vector<int>& nums, int target) {
        return Recursive(nums, target, 0, nums.size() - 1);
    }

    int Recursive(vector<int>& nums, int target, int st, int end) {
        if (st > end)
            return -1;

        int mid = st + (end - st) / 2;

        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            return Recursive(nums, target, mid + 1, end);
        else
            return Recursive(nums, target, st, mid - 1);
    }
};
