class Solution {
public:
    string breakPalindrome(string s) {
//         thought process
//         if element is single then only it cant be replaced so handle this edge case

        int n = s.length();

        if(n<2)return "";
        for(int i = 0;i<n/2;i++){
            if(s[i] != 'a')
            {
//                 this is the crucial step so we want to do it as early as possible
                s[i] = 'a';
                return s;
            }
        }
//         if all are a's then replace the last character
        s[n-1] = 'b';
        return s;
    }
};