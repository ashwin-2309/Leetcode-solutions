class Solution {
public:
    void setZeroesBetter( vector<vector<int>> &a)
    {
//         we are using a col array and a row array
        int n = a.size(); int m = a[0].size(); 
        vector<int> col(m,0),row(n,0);
        
//         now fill these positions
        for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                   
                   if(a[i][j] == 0)
                   {
                       col[j] = 1;
                       row[i] = 1;
                   }
                   
               }
        }
        
//         now lookup the vectors and change the matrix
        for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                   
//                    for a[i][j]
                   if(col[j] == 1 or row[i] == 1)
                   {
                       a[i][j] = 0;
                   }
                   
               }
        }
        return ;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        setZeroesBetter(matrix);
        return;
    }
};