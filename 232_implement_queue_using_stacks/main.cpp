#include <iostream>
using namespace std;

class Node{
    public:
    int value;
    Node *next;

    Node() : next(nullptr){};
    Node(int value) : value(value), next(nullptr){};
};

class MyQueue {
private:
    Node *front;
    Node *rear;
public:
    MyQueue() {
        front = nullptr;
        rear = nullptr;
    }
    
    void push(int x) {
        Node *newNode = new Node(x);
        if(!front){
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = rear->next;
        }
    }
    
    int pop() {
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    
    int peek() {
        return front->value;
    }
    
    bool empty() {
        return front == nullptr;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    


    return 0;
}