#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0, cnt = 0;
        while (index < s.size() && cnt < g.size())
        {
            if (s[index] >= g[cnt])
                cnt++;
            index++;
        }
        return cnt;
    }
};

int main()
{

    return 0;
}