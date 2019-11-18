#include <iostream>
using namespace std;


struct SNode {
    int value;
    SNode *prev;
};


class Stack {

public:

    Stack() : top(nullptr) {}

    int pop() {
        if(top == nullptr) {
            return -1;
        }

        SNode *temp = top;
        top = top->prev;

        int val = temp->value;
        delete temp;
        return val;
    }


    void push(int newVal) {
        SNode *temp = new SNode;
        temp->value = newVal;
        temp->prev = top;

        top = temp;
    }


    int peek() {
        if(isEmpty()) {
            return -1;
        }
        return top->value;
    }


    bool isEmpty() {
        return (top == nullptr);
    }


private:
    SNode *top;
};


int main() {
    ios_base::sync_with_stdio(false);
    setbuf(stdout, NULL);

    Stack s;
    s.push(1);
    s.push(3);
    s.push(2);

    cout << "popped: " << s.pop() << endl;
    cout << "popped: " << s.pop() << endl;
    cout << "peek: " << s.peek() << endl;
    cout << "isEmpty: " << s.isEmpty() << endl;
    cout << "popped: " << s.pop() << endl;
    cout << "popped: " << s.pop() << endl;
    cout << "isEmpty: " << s.isEmpty() << endl;
}