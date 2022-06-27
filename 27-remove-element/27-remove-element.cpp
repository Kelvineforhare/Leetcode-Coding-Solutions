class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; 
        for(int i = nums.size() - 1; i >= 0;--i){
            if(nums[i] != val){
                k++;
            }
            else if(k!=0){
                int temp = nums[i + k];
                nums[i + k] = val;
                nums[i] = temp;
            }
        }
        return k;
    }
};