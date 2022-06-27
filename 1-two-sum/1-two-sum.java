class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i =0; i < nums.length; i++){
            map.put(target - nums[i] ,i);
        }
        // for (int name: map.keySet()) {
        //     int key = name;
        //     int value = map.get(name);
        //     System.out.println(key + " " + value);
        // }
        //System.out.println(map.keySet());
        for(int i =0; i < nums.length;i++){
            //System.out.println(i + " " + map.get(nums[i]));
            if(map.get(nums[i]) != null && map.get(nums[i]) != i){
                int[] ret = {i,map.get(nums[i])};
                return ret;
            }
            
        }
        int[] ret = {0,0};
        return ret;
    }
}