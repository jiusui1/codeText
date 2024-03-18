class Solution {
   public:
    // ÊäÈë£ºnums = [0,1,2,4,5,7]
    // Êä³ö£º["0->2", "4->5", "7"]
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        int i = 0, n = nums.size();
        while (i < n) {
            int j = i;
            while (j + 1 < n && nums[j + 1] == nums[j] + 1)
                j++;
            string t = to_string(nums[i]);
            if (j > i)
                t += "->" + to_string(nums[j]);
            res.push_back(t);
            i = j + 1;
        }
        return res;
    }
};