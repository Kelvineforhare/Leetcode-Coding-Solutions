class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = 0;
        int max = nums.size()-1;
        while(max-1 > min){
            printf("min: %d , max: %d\n",nums[min],nums[max]);
            if(nums[min] > nums[max]){
                //min = (min+max)/2;
                min++;
            }
            else{
                max=(min+max)/2;
                //max++;
            }
        }
        return (nums[min] < nums[max])?nums[min]:nums[max];
    }
};