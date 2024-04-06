#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {

        stack<int> stack;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stack.push(i);
            }
            else if (s[i] == ')')
            {
                if (stack.empty())
                {
                    s.erase(i, 1);
                    i--;
                }
                else
                {
                    stack.pop();
                }
            }
        }
        while (!stack.empty())
        {
            s.erase(stack.top(), 1);
            stack.pop();
        }
        return s;
    }
};

int main()
{
    Solution *obj = new Solution();
    string s = "()())))))(";
    string valid = obj->minRemoveToMakeValid(s);
    cout << valid << " ";
    return 0;
}