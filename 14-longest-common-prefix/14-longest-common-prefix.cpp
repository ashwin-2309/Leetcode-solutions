class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string mn = strs[0],mx= strs[0];
        for(auto i : strs)
        {
            if(i > mx)
            {
                mx = i;
            }
            else if(i<mn){
                mn = i;
            }
        }
        
//         now find the common elements in these two
        string ans = "";
        int i = 0;
        while(i<mn.size())
        {
            if(mn[i] == mx[i])
            {
                ans+=mn[i];i++; 
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};