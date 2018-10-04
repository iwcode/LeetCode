class Solution {
public:
    string longestPalindrome(string s) {
        int arr[300][1005];
        string ret = s.substr(0,1);
        memset(arr, 0, sizeof(arr));
        int len = s.length(), ans = 1;
        for (int i = 0; i < len; i++) {
            arr[s[i]][++arr[s[i]][0]] = i;
            if (arr[s[i]][0] == 1) continue;
            for (int j = 1; j < arr[s[i]][0]; j++) {
                if (arr[s[i]][arr[s[i]][0]] - arr[s[i]][j] < ans) break;
                int count = (arr[s[i]][arr[s[i]][0]] - arr[s[i]][j]) / 2;
                for (int k = 0; k <= count; k++) {
                    if (s[arr[s[i]][j] + k] != s[arr[s[i]][arr[s[i]][0]] - k]) {
                        count = -1;
                        break;
                    }
                }
                if (count != -1) {
                    ans = arr[s[i]][arr[s[i]][0]] - arr[s[i]][j] + 1;
                    ret = s.substr(arr[s[i]][j], ans);
                    break;
                }
            }
        }
        return ret;
    }
};