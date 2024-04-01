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
using namespace std;

#define PI (3.141592);
#define e (2.7182);

typedef long long ll;
typedef long l;

template <typename T>
using vt = vector<T>;

template <typename J, typename A>
using hm = unordered_map<J, A>;

template <typename R>
using st = stack<R>;

static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *ptrTwoStart = list2, *ptrTwoEnd = nullptr, *temp = list2;
        
        while (temp)
        {
            ptrTwoEnd = temp;
            temp = temp->next;
        }
        
        int ctr = 0;
        temp = list1;
        ListNode *aOne = nullptr, *aTwo = nullptr;

        while (temp)
        {
            if(ctr + 1 == a){
                aOne = temp;
            } else if(ctr - 1  == b){
                aTwo = temp;
            } 
            temp = temp->next;
            ctr++;
        }
        aOne->next = ptrTwoStart;
        ptrTwoEnd->next = aTwo;
        return list1;
    }
};

int main()
{

    return 0;
}