// C++ program to find largest rectangle area in histogram using stack
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> nsl(n), psl(n);

    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        nsl[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    while (!s.empty())
    {
        s.pop();
    }

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        psl[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (nsl[i] - psl[i] - 1) * (heights[i]));
    }

    return ans;
}

int main()
{
    vector<int> heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);
    cout << largestRectangleArea(heights) << endl;
    return 0;
}

/*
Output:
10
*/