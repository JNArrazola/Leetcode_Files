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
#include <deque>
#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("03")
#pragma GCC target ("avx")

#define PI (3.141592);

typedef long long ll;
typedef long l;

template <typename T>
using vt = vector<T>;

template <typename J, typename A>
using hm = unordered_map<J, A>;

template <typename R>
using st = stack<R>;

class Solution {
private:
    bool interpret(const char &c){
        return c == 't' ? true : false;
    }
public:
    bool parseBoolExpr(string s) {
        if(s.size() == 1)
            return s[0] == 't' ? true : false;
        
        stack<char> operators, operands;
        char op;
        for(const char &c : s){
            switch (c) {
            case 'f':
            case 't':
            case '(':
                operands.push(c);
                break;
            case '&':
            case '!':
            case '|':
                operators.push(c);
                break;
            case ')':
                op = operators.top();
                if(op == '&'){
                    bool r, flag = false;
                    char ch;
                    while (operands.top() != '(')
                    {
                        ch = operands.top();
                        operands.pop();

                        if(!flag){
                            r = interpret(ch);
                            flag = !flag;
                        }
                        else 
                            r = r && interpret(ch);
                    }
                    operators.pop();
                    operands.pop();
                    operands.push(r ? 't' : 'f');
                    break;
                } else if(op == '|'){
                    bool r, flag = false;
                    char ch;
                    while (operands.top() != '(')
                    {
                        ch = operands.top();
                        operands.pop();

                        if(!flag){
                            r = interpret(ch);
                            flag = !flag;
                        }
                        else 
                            r = r || interpret(ch);

                    }
                    operators.pop();
                    operands.pop();
                    operands.push(r ? 't' : 'f');
                } else if(op == '!') {
                    char ch = operands.top();
                    operands.pop();
                    operands.pop();
                    operators.pop();
                    operands.push((!(interpret(ch)) ? 't' : 'f'));
                }
                break;
            default:
                break;
            }
        }
        
        return operands.top() == 't' ? true : false;
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    Solution s;
    
    vector<string> testcases = {"&(|(f))", "|(f,f,f,t)", "!(&(f,t))"};

    for(const string &str : testcases)
        cout << s.parseBoolExpr(str) << endl;

    return 0;
}