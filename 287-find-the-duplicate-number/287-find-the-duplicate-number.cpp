class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> set;
        for(int i = 0; i < nums.size();++i){
            auto test = set.insert(nums[i]);
            if (!test.second){
                return nums[i];
            }
            
        }
        return nums[0];
    }
};