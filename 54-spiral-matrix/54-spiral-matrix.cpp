class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector <int> v;
        int r = a.size();int c = a[0].size();
        int top =0,down = r-1,left = 0,right=c-1;
        while(top<=down and left <=right){
            for(int i=left;i<=right;i++){
                //row fixed
                v.push_back(a[top][i]);
            }
            top++;
            for(int i = top;i<=down;i++){
                //column fixed
                v.push_back(a[i][right]);
            }
            right--;
            if(top<=down){
            for(int i=right;i>=left;i--){
                //row fixed
                v.push_back(a[down][i]);
            }
            }
            down--;
            if(left <= right){
            for(int i=down;i>=top;i--){
                //col fixed
                v.push_back(a[i][left]);
            }
            }
            left++;
        }
        return v;
    }
};