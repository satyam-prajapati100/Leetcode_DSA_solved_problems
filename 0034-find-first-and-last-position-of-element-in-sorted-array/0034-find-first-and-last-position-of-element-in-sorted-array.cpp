class Solution {
public:

    int firstOccurrence(vector<int> &arr , int n , int k){
        int start=0 , end=n-1;
        int first =-1 ;
        while(start<=end){
            int mid = start+(end-start)/2 ;
            if(arr[mid] == k){
                first = mid ;
                end = mid-1 ;
            }
            else if (arr[mid] < k ){
                start = mid+1 ;

            }
            else {
                end=mid-1 ;
            }

            
        }
        return first ;
    }

    int lastOccurrence(vector<int>&arr , int n , int k){
        int start=0 , end = n-1  , last = - 1 ;
        while(start<= end){
            int mid= start+(end-start)/2 ;
            if(arr[mid] == k){
                last = mid ;
                start = mid+1 ;
            }
            else if (arr[mid] <k ){
                start=mid+1 ;
            }
            else {
                end=mid-1 ;
            }
            
        }
        return last ;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n= nums.size() ;
        vector<int> ans ;

        int first = firstOccurrence(nums , n , target) ;
        int last = lastOccurrence(nums, n , target);

        ans.push_back(first) ;
        ans.push_back(last);

        return ans ;
        
    }
};