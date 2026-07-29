class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {

        int left = n - 1;
        int right = 0;

        while (left >= 0 && right < m) {
            if (nums1[left] > nums2[right]) {
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            } else {
                break;
            }
        }

        sort(nums1.begin(), nums1.begin() + n);
        sort(nums2.begin(), nums2.end());

        for (int i = 0; i < m; i++) {
            nums1[n + i] = nums2[i];
        }
    }
};