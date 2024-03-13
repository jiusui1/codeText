class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty() || st.top() != s[i])
                st.push(s[i]);
            else
                st.pop();
        }
        string result = "";
        while (!st.empty())
        { // 将栈中元素放到result字符串汇总
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end()); // 此时字符串需要反转一下
        return result;
    }
};