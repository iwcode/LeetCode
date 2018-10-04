class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int vi[300], len = s.length();
        memset(vi, -1, sizeof(vi));
        int ans = 0, tmp = -1;
        for (int i = 0; i < len; i++) {
            if(vi[s[i]] != -1) {
                tmp = max(tmp, vi[s[i]]);
            }
            vi[s[i]] = i;
            ans = max(ans, i - tmp);
        }
        return ans;
    }
};