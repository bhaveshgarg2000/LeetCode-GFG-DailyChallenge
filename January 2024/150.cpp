class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> ans;
        for (string x : tokens)
        {
            if (x == "+")
            {
                // first element in stack insert
                int a = ans.top();
                ans.pop();
                // second element in stack insert
                int b = ans.top();
                ans.pop();
                ans.push(a + b);
            }
            else if (x == "-")
            {
                // first element in stack insert
                int a = ans.top();
                ans.pop();
                // second element in stack insert
                int b = ans.top();
                ans.pop();
                ans.push(b - a);
            }
            else if (x == "*")
            {
                // first element in stack insert
                int a = ans.top();
                ans.pop();
                // second element in stack insert
                int b = ans.top();
                ans.pop();
                ans.push(a * b);
            }
            else if (x == "/")
            {
                // first element in stack insert
                int a = ans.top();
                ans.pop();
                // second element in stack insert
                int b = ans.top();
                ans.pop();
                ans.push(b / a);
            }
            else
            {
                ans.push(stoi(x));
            }
        }
        return ans.top();
    }
};