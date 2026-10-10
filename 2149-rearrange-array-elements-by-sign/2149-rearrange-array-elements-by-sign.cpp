class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>first ;
        vector<int>second ;

        for(int i=0 ;i<nums.size() ;i++){
            if(nums[i] >0){
                first.push_back(nums[i]);
            }
            else {
                second.push_back(nums[i]);
            }
        }

        int k=0 , j=0;

        for(int i=0 ;i<nums.size() ;i+=2){
            nums[i]=first[k];
            k++;
        }

        for(int i=1 ; i<nums.size() ;i+=2){
            nums[i]=second[j];
            j++;
        }

        return nums ;
    }
};