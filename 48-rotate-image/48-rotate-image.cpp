class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
//         reverse the matrix and take transpose
        reverse(matrix.begin(),matrix.end());
        
//         take transpose
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<i;j++){
                 swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};