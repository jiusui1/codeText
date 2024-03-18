class Solution {
   public:
    int maxSubArray(vector<int> &nums) {
        int result = INT_MIN;
        int num = 0;
        for (int i : nums) {
            num += i;
            result = max(result, num);
            if (num < 0)
                num = 0;
        }
        return result;
    }
};