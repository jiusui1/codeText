#include <algorithm>  // ?? std::max_element ??
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void get(int a, int b) {
    a += 1;
}

int main() {
    // string s = "IVXLC";
    // unordered_map<char, int> hash = {//"IVX"
    //                                  {'I', 1},
    //                                  {'V', 5},
    //                                  {'X', 10},
    //                                  {'L', 50},
    //                                  {'C', 100},
    //                                  {'D', 500},
    //                                  {'M', 1000}};
    // int ans = 0;
    // for (int i = 0; i < s.size(); i++) {
    //     cout << hash[s[i]] << " ";
    //     cout << hash[s[i + 1]] << " ";
    //     if (hash[s[i]] < hash[s[i + 1]])
    //         ans -= hash[s[i]];
    //     else
    //         ans += hash[s[i]];
    // }
    // cout << ans << endl;  // 1990
    // vector<int> nums = {-1};
    // int k = 2;
    // int n = nums.size() - k;
    // int size = nums.size();
    // vector<int> vec;
    // for (int i = n; i < size; i++) {
    //     vec.push_back(nums[i]);
    //     nums.pop_back();
    // }
    // vec.insert(vec.end(), nums.begin(), nums.end());
    // nums = vec;
    // for (int i : nums) {
    //     cout << i << " ";
    // }
    std::cout << "Hello, World!" << std::endl;
    int a, b, c;
    cin >> a >> b >> c;
    return 0;
}
