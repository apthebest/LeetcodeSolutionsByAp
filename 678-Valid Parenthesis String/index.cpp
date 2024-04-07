#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {

        stack<int> stack1;
        stack<int> stack2;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                stack1.push(i);
            else if (s[i] == '*')
                stack2.push(i);
            else
            {
                if (stack1.empty())
                {
                    if (stack2.empty())
                        return false;
                    else
                        stack2.pop();
                }
                else
                    stack1.pop();
            }
        }
        while (!stack1.empty() && !stack2.empty())
        {
            if (stack2.top() < stack1.top())
                return false;
            stack1.pop();
            stack2.pop();
        }
        return stack1.empty();
    }
};

int main()
{
    Solution *sol = new Solution();
    string s = "()";
    cout << sol->checkValidString(s);
    return 0;
}