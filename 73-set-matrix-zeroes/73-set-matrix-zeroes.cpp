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
    
    void setZeroesOptimal( vector<vector<int>> &a)
    {
//         here we use the first row as row matrix and first col as column matrix but 
//         a bool col0 must be used as 0,0 is intersecting(common in both)
        
        bool col0 = false;
        int n = a.size();
        int m = a[0].size(); 
        
        for(int i=0;i<n;i++){
            
//             checking for first column only
            
            if(a[i][0] == 0)
            {
                col0 = true;
            }
            
               for(int j=1;j<m;j++){
                   
//                
                   if(a[i][j] == 0)
                   {
                       a[i][0] = 0,a[0][j] = 0;
                   }
                   
               }
        }
//         iterate over the array once again and using the first row and column update the elements
//         iteration will start from i=1 and j=1
        
        for(int i=1;i<n;i++){
               for(int j=1;j<m;j++){
                   if(a[i][0] == 0 or a[0][j] == 0)
                   {
                       a[i][j] = 0;
                   }
               }
        }
        
//         see if the first row needs to be set zero
//         this step will be done after the previous state
        if(a[0][0] == 0)
        {
            for(int j=0;j<m;j++){
                 a[0][j] = 0;
            }
        }
        
//         check this for first column as well
        if(col0){
            for(int i=0;i<n;i++){
                 a[i][0] = 0;
            }
        }
        
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        // setZeroesBetter(matrix);
        setZeroesOptimal(matrix);
        return;
    }
};