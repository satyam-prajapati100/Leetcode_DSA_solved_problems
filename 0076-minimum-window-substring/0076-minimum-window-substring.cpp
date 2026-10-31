class Solution {
public:
    string minWindow(string s, string t) {
        int total= t.size() ;
        unordered_map<char , int > m ;

        for(int i=0 ;i<t.size();i++){
            m[t[i]]++ ;
        }

        int start=0 , end=0 , ans= INT_MAX , index=-1  , n= s.size() ; 
        // min lenght of substring 
        while(end<n){
            m[s[end]]--; // decrease the count of char 
            if(m[s[end]] >=0) // if count is not negative 
            total--; // decrease he total 
            
            // can we decrease the size of the window 
            while(!total && start <=end){
                // update the length of substring 
                if(ans> end-start+1){
                    ans = end-start+1 ; 
                    index = start ;
                }

                m[s[start]]++ ; // increse the count of char 
                if(m[s[start]]>0) // if count is positive 
                total++;// increase the total ;

                start++ ; // move the start . decrese the size 
            }
             

            // increase the size of window 
            end++;
        }

        if(index ==-1 ){
            return "";
        }

        string str = "" ;

        for(int i= index ; i<index+ans ; i++){
            str+=s[i];
        }
        return str ;

    }
};