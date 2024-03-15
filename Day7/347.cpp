#include <iostream>
#include <set>
#include <vector>
using namespace std;

// 1,1,1,2,2,3
class Solution {
   public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        set<int> s;
        for (int i : nums) {
            s.insert(i);
        }
        // while (k--) {
        // }
        return nums;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(1);
    s.topKFrequent(v, 2);
    return 0;
}
