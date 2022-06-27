class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lowerBound = 0;
        int upperBound = nums.size();
        int index = (lowerBound+upperBound)/2;
        while(lowerBound <= upperBound)
        {
            index = (lowerBound+upperBound)/2;
            if(index == nums.size() || nums[index] == target)
            {
                return index;
            }
            else if(nums[index] > target)        
            {
                upperBound = upperBound -1 ;
            }
            else
            {
                lowerBound = index+1;
            }
        }
        return index;
    }
};