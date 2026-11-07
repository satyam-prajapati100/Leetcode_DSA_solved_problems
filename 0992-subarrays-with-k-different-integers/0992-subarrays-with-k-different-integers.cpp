class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int , int>freq;

        int start=0 , end=0 , n=nums.size() , total=0 , count=0 ;

        while(end<n){
            freq[nums[end]]++ ;
            if(freq[nums[end]]==1)
            count++;

            while(count >k){
                freq[nums[start]]--; 
                if(freq[nums[start]]==0)
                count--;
                start++;
            }

            total+= end-start+1 ;
            end++ ;
        }
        start=0 , end=0 , count= 0 ;
        freq.clear() ;
        k-- ;
        
        while(end<n){
            freq[nums[end]]++;
            if(freq[nums[end]]==1)
            count++;

            while(count >k){
                freq[nums[start]]--; 
                if(freq[nums[start]]==0)
                count--;
                start++;
            }

            total-= end-start+1 ;
            end++ ;
        }
        return total ;

    }
};