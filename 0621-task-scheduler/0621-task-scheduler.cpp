class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        //calculate the frequrncy each char 
        vector<int>freq(26,0);
        int Size = tasks.size();

        //  count is the highest freq of charector 
        int count = 0;

        for(int i=0 ; i<tasks.size() ;i++){
            freq[tasks[i]-'A']++;
            count = max(count , freq[tasks[i]-'A']);
        }

        int ans = (count-1)*(n+1) ;

        for(int i=0 ; i<26 ;i++){
            if(freq[i] == count){
                ans++ ;
            }
        }

        ans = max(ans ,Size);

        return ans ;
    }
};