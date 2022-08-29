class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,max = 0;
        while(i < j){
            int smaller = (height[i] > height[j])?j:i;
            int diff = (i - j < 0)?j-i:i-j;
            int area = height[smaller] * diff;
            max = (area > max)?area:max;
            //printf("smaller: %d , diff: %d , area: %d , max:%d \n",height[smaller],diff,area,max);
            if(smaller == i){
                ++i;
            }
            else{
                --j;
            }
        }
        return max;
    }
};