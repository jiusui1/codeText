class Solution {
   public:
    string longestCommonPrefix(vector<string> &strs) {  // strs = ["flower","flow","flight"]
        if (strs.empty())
            return "";
        string ans = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string t = "";
            for (int j = 0; j < ans.size() && j < strs[i].size(); j++) {
                if (ans[j] == strs[i][j])
                    t += ans[j];
                else
                    break;
            }
            ans = t;
        }
        return ans;
    }
};