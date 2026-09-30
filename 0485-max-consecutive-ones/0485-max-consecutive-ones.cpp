class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int total=0 ;
        int count =0 ;

        for(int i=0 ;i<nums.size() ;i++){
            if(nums[i] == 1){
                count ++ ;
                total = max(count , total);
            }else {
                count=0 ;
            }
        }

        return total ;
    }
};