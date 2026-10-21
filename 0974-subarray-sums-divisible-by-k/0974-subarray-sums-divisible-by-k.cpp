class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //  Unorderd Map 
        unordered_map<int ,int >m ;  // reminder with their count 

        m[0]=1 ;

        int PrefixSum = 0 , rem , total= 0 ;

        for (int i=0 ;i<nums.size() ;i++){
            PrefixSum+= nums[i];
            rem= PrefixSum % k;

            if (rem<0) // if our reminder is negative  , make it positive 
            rem = k+rem ;

            if(m.count(rem)){
                total+=m[rem];
                m[rem]++;
            }
            else 
            m[rem]=1 ;
        }

        return total ;
    }
};