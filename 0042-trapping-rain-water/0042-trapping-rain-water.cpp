class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        //Two pointers
        int left = 0;
        int right = n-1; 
        
        int maxleft = 0;
        int maxright=0;
        int trapwater=0;

        while(left < right) {
            if(height[left] <= height[right]) {
                if(height[left] >= maxleft) {
                    maxleft = height[left];
                } else {
                    trapwater +=maxleft-height[left];
                }
                left++;
            } else {
                if(height[right] >= maxright) {
                    maxright = height[right];
                } else {
                    trapwater+=maxright-height[right];
                }
                right--;
            }
          
        }
        return trapwater;

        
    }
};