class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> num;
        for(int i = 0; i < nums.size();++i){
            auto newInsert = num.insert(nums[i]);
            if(newInsert.second == false){
                printf("%d",nums[i]);
                return true;
            }
        }
        return false;
    }
};