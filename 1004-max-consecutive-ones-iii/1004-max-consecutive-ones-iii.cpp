class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0 , end=0 , n = nums.size()  ,  len=0 ;

        while(end<n && start<=end){
            if(nums[end] == 0){
                k-- ;
            }

            while(k<0){
                if(nums[start] == 0){
                    k++;
                }
                start++;
            }


            len = max(len , end-start+1);
            end++;
        }

        return len ;
    }
};