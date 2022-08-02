class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size()),post(nums.size()),answer(nums.size());
        
        int total = 1;
        for(int i = 0; i < pre.size();++i){
            pre[i]= nums[i]*total;
            total = pre[i];
        }
        // for(int i = 0; i < pre.size();++i){
        //    printf("%d\n",pre[i]);
        // }
        total = 1;
        for(int i = post.size()-1; i < post.size();--i){
            post[i]= nums[i]*total;
            total = post[i];
        }
        // for(int i = 0; i < post.size();++i){
        //    printf("%d\n",post[i]);
        // }
        answer[0] = post[1];
        answer[answer.size() - 1] = pre[pre.size()-2];
        for(int i = 1; i <= answer.size()-2;++i){
            answer[i] = pre[i-1] * post[i+1];
        }
        // for(int i = 0; i < answer.size();++i){
        //    printf("%d\n",answer[i]);
        // }
        return answer;
    }
};