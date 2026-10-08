class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;  
        
        // store {value, original_index}
        for(int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }
        
        // sort by value
        sort(arr.begin(), arr.end());
        
        int start = 0, end = arr.size() - 1;
        
        while(start < end) {
            int sum = arr[start].first + arr[end].first;
            
            if(sum == target) {
                return {arr[start].second, arr[end].second};
            }
            else if(sum < target) {
                start++;
            }
            else {
                end--;
            }
        }
        
        return {};
    }
};

