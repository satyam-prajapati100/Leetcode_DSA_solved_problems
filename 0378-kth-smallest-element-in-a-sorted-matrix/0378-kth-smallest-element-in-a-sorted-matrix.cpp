class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<pair<int , pair<int , int >>> temp ;

        for (int i=0 ;i<n ;i++){
            temp.push_back(make_pair(matrix[i][0] , make_pair(i,0)));
        }
        
        // create min heap 
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());

        // data(value) , row , col 

        int ans ; 
        pair<int , pair<int , int >>Element;
        int i , j ; 

        while(k--){
            Element = p.top();
            p.pop();
            ans = Element.first ; // value 
            i= Element.second.first ; //row 
            j= Element.second.second; //col 

            if(j+1<n)
            p.push(make_pair(matrix[i][j+1] , make_pair(i , j+1))) ;
        }

        return ans ; 


    }
};