/**
 * @brief ´æÔÚÖØ¸´ÔªËØ II
 *
 */
class Solution {
   public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        int len = nums.size();
        unordered_map<int, int> Indexmap;
        for (int i = 0; i < len; i++) {
            if (Indexmap.find(nums[i]) != Indexmap.end() and i - Indexmap[nums[i]] <= k)
                return true;
            Indexmap[nums[i]] = i;
        }
        return false;
    }
};