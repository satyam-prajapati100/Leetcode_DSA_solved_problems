class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int ,int > m ;

        int total = 0 ;
        int Prefixsum=0 ;
        m[0]=1 ;

        for(int i=0 ; i< nums.size() ;i++){
            Prefixsum+=nums[i];
            if(m.count(Prefixsum-k)){
                total+=m[Prefixsum-k];
                m[Prefixsum]++;
            }
            else {
                m[Prefixsum]++ ;
            }
          
        }

        return total ;
    }
};