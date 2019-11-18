#include <iostream>
using namespace std;


struct QNode {
    int value;
    QNode *prev;
    QNode *next;
};


class Queue {

public:

    Queue() : head(nullptr), tail(nullptr) {}

    int pop() {
        if(isEmpty()) {
            return -1;
        }

        int val = head->value;
        QNode *temp = head;
        head = head->prev;
        delete temp;
        return val;
    }


    void push(int newVal) {
        QNode *temp = new QNode;
        temp->value = newVal;
        temp->prev = nullptr;

        if(isEmpty()) {
            temp->next = nullptr;
            head = tail = temp;
        }
        else {
            temp->next = tail;
            tail->prev = temp;
            tail = temp;
        }
    }


    int peek() {
        if(isEmpty()) {
            return -1;
        }
        return head->value;
    }


    bool isEmpty() {
        return (head == nullptr);
    }


private:
    QNode *head, *tail;
};


int main() {
    ios_base::sync_with_stdio(false);
    setbuf(stdout, NULL);

    Queue q;
    q.push(1);
    q.push(3);
    q.push(2);

    cout << "popped: " << q.pop() << endl;

    q.push(5);
    cout << "pushed 5 " << endl;

    cout << "popped: " << q.pop() << endl;
    cout << "peek: " << q.peek() << endl;
    cout << "isEmpty: " << q.isEmpty() << endl;
    cout << "popped: " << q.pop() << endl;
    cout << "popped: " << q.pop() << endl;
    cout << "isEmpty: " << q.isEmpty() << endl;
}