class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start =0 , end = 0 , n= nums.size() ;
        int sum = 0 , total = INT_MAX;

        while(end<n){
            sum+=nums[end];

            while(sum>= target){
                total = min(total , end-start+1);
                sum-=nums[start++];
            }
          
            end++ ;
        }
    //    if (total == INT_MAX){
    //     return 0 ;
    //    }

    //    return total ;

    return total == INT_MAX ? 0 : total ;
    }
};