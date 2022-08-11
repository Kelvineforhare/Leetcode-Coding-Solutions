class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = 0;
        int max = nums.size()-1;
        int mid = (max-min)/2;
        while(max-1 > min){
            printf("min %d , mid %d , max %d\n",nums[min],nums[mid],nums[max]);
            if(nums[mid] < nums[max]){
                max = mid;
            }
            else if(nums[mid] > nums[min]){
                min = mid+1;
            }
            mid = (max+min)/2;
    
        }
        return (nums[min] < nums[max])?nums[min]:nums[max];
    }
};