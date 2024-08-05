#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <array>
#include <set>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("03")
#pragma GCC target("avx")

#define PI (3.141592);

typedef long long ll;
typedef long l;

template <typename T>
using vt = vector<T>;

template <typename J, typename A>
using hm = unordered_map<J, A>;

template <typename R>
using st = stack<R>;

static vector<int> nums = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution
{
private:
    string evaluateExpression(stack<string> &tokens, string op)
    {
        int numberOne = stoi(tokens.top());
        tokens.pop();
        int numberTwo = stoi(tokens.top());
        tokens.pop();

        if(op == "+") return to_string(numberTwo + numberOne);
        if(op == "-") return to_string(numberTwo - numberOne);
        if(op == "*") return to_string(numberTwo * numberOne);
        if(op == "/") return to_string((int)floor(numberTwo / numberOne));
        return 0;
    }
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<string> numbers;

        for (size_t i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "+") numbers.push(evaluateExpression(numbers, "+"));
            else if(tokens[i] == "-") numbers.push(evaluateExpression(numbers, "-"));
            else if(tokens[i] == "*") numbers.push(evaluateExpression(numbers, "*"));
            else if(tokens[i] == "/") numbers.push(evaluateExpression(numbers, "/"));
            else numbers.push(tokens[i]);
        }
        return stoi(numbers.top());
    }
};

int main()
{

    return 0;
}