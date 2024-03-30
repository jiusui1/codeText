class Solution {
   public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        string temp(str);
        reverse(temp.begin(), temp.end());
        return temp == str;
    }
};