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
    int val;
    QNode *next;

    QNode(int val) : val(val), next(nullptr){};
};

class MyCircularQueue {
private:
    int k, ctr = 0;
    QNode *front = nullptr, *rear = nullptr;
public:
    MyCircularQueue(int k) {
        this->k = k;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;

        QNode *node = new QNode(value);
        if(!front){
            front = node;
            rear = node;
        } else {
            rear->next = node;
            rear = node;
        }

        ++ctr;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;

        QNode *temp = front;
        front = front->next;
        delete temp;

        if(!front)
            rear = nullptr;

        --ctr;
        return true;
    }
    
    int Front() {
        return front ? front->val : -1;
    }
    
    int Rear() {
        return rear ? rear->val : -1;
    }
    
    bool isEmpty() {
        return !ctr;
    }
    
    bool isFull() {
        return k == ctr;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main()
{

    return 0;
}