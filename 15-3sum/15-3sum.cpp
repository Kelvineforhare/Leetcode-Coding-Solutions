class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<int> used;
        sort(nums.begin(),nums.end());
        //  for(int i = 0; i < nums.size();++i){
        //      printf("%d,",nums[i]);
        //  }
        // printf("\n");
        for(int i = 0; i < nums.size();++i){
            auto ins = used.insert(nums[i]);
            if(!ins.second){
                continue;
            }
            if(nums[i] >= 0){
                if(i < nums.size()-2){
                    if(nums[i] + nums[i+1] + nums[i+2] == 0){
                        ans.push_back({nums[i],nums[i+1],nums[i+2]});
                    }
                    
                }
                return ans;
            }
            int low=i+1,high=nums.size()-1;
            while(low < high){
                //printf("i: %d , low: %d , high: %d \n",nums[i],nums[low],nums[high]);
                if(low == i){
                    ++low;
                    //printf("skip\n");
                    continue;
                }
                if(high == i){
                    --high;
                    //printf("skip\n");
                    continue;
                }
                if(low > 0 && nums[low] == nums[low-1] && low-1!=i){
                    ++low;
                    continue;
                }
                if(high < nums.size()-1 && nums[high] == nums[high+1] && high+1!=i){
                    --high;
                    continue;
                }
                int add = nums[i] + nums[low] + nums[high];
                if(add > 0){
                    --high;
                }
                else if(add < 0){
                    ++low;
                }
                else{
                    ans.push_back({nums[i],nums[low],nums[high]});
                    ++low;
                    --high;
                }
            }
        }
        
        
        

        
        
        return ans;
    }
};