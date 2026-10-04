class Solution {
public:
    void heapify(vector<int>& nums , int n , int i) {
        //step- 01:
        int largest = i ;//current index assume take it as zero 
        int left = 2*i+1;
        int right = 2*i+2;

        if(left < n && nums[left] > nums[largest]) {
            largest = left;
        }
        if(right < n && nums[right] > nums[largest]) {
            largest =right;
        }
        if (largest != i ) {
            swap(nums[i], nums[largest]);
            heapify(nums , n, largest);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for( int i= n/2 -1; i>=0; i--) {  // build max heap
            heapify(nums, n, i);
        }
        //Heap sort 
        for(int i = n-1; i>0 ; i--) {
            swap(nums[0] , nums[i]);
            heapify(nums, i, 0);
        }
        return nums;

    }

};