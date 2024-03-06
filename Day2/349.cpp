
/**
 * @brief      This class describes a solution.
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    	unordered_set<int> result_set;
    	int hashtable[1005] = {0};
    	for (int num: nums1)
    	{
    		hashtable[num] = 1;
    	}
    	for (int num : nums2)
    	{
    		if(hashtable[num] == 1)
    		{
    			unordered_set.insert(num);
    		}
    	}
    	return vector<int>(result_set.begin(),result_set.end());
    }
};
