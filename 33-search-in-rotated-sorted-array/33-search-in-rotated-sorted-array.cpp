class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min = 0 , max = nums.size()-1 , mid = (max+min)/2;
        while(max-1 > min){
            int numMin = nums[min] ,numMid = nums[mid], numMax = nums[max];
            if(numMin < numMid ){
                if(target >= numMin && target <= numMid){
                    max = mid;
                }
                else{
                    min = mid;
                }
            }
            else if(numMid < numMax){
                if(target >= numMid && target <= numMax){
                    min = mid;
                }
                else{
                    max = mid;
                }
            }
            mid = (max+min)/2;
            //printf("min: %d, mid: %d, max: %d \n",numMin,numMid,numMax);
            
        }
        //printf("min: %d, mid: %d, max: %d \n",nums[min],nums[mid],nums[max]);
        if(nums[min] == target){
            return min;
        }
        if(nums[max] == target){
            return max;
        }
        return -1;
        
    }
};