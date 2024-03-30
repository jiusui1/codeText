class Solution {
   public:
    vector<int> plusOne(vector<int> &digits) {
        string str(digits.begin(), digits.end());
        int num = ++auto(str);
        string temp = to_string(num);
        return vector<int>(temp.begin(), temp.end());
    }
};