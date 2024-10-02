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

static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class QNode{
public:
    QNode *prev, *next;
    int val;

    QNode(int val) : val(val), prev(nullptr), next(nullptr){};
};

class MyCircularDeque {
private:
    QNode *head = nullptr, *last = nullptr;
    int k, ctr = 0;
public:
    MyCircularDeque(int k) {
        this->k = k;
    }
    
    bool insertFront(int value) {
        if(isFull())
            return false;

        QNode *node = new QNode(value);
        if(!head){
            head = node;
            last = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        }
        ctr++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
            return false;

        QNode *node = new QNode(value);
        if(!head){
            head = node;
            last = node;
        } else {
            last->next = node;
            node->prev = last;
            last = node;
        }
        
        ctr++;
        return true;
    }
    
    bool deleteFront() {
        if(!head)
            return false;

        QNode *temp = head;
        head = head->next;
        
        if(head)
            head->prev = nullptr;
        delete temp;

        ctr--;
        if(!ctr)
            last = nullptr;

        return true;
    }
    
    bool deleteLast() {
        if(!head)
            return false;

        QNode *temp = last;
        last = last->prev;
        delete temp;

        if(last)
            last->next = nullptr;
        ctr--;

        if(!ctr)
            head = nullptr;
        return true;
    }
    
    int getFront() {
        return head ? head->val : -1;
    }
    
    int getRear() {
        return last ? last->val : -1;
    }
    
    bool isEmpty() {
        return ctr == 0;
    }
    
    bool isFull() {
        return ctr == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main()
{

    return 0;
}