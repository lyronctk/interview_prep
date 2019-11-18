#include <iostream>
#include <vector>
#include <string>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

/*
LEETCODE: Design Linked List (707)
https://leetcode.com/problems/design-linked-list/
*/


class MyLinkedList {

friend ostream& operator<<(ostream& os, const MyLinkedList &ll);

private:
    struct Node {
        int val;
        Node *next, *prev;
    };

    Node *head, *tail;
    int length;


public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head   = NULL;
        tail   = NULL;
        length = 0;
    }


    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(!head)
            return -1;

        Node *it = head;
        for(int i = 0; it; i++) {
            if(i == index)
                return it->val;
            it = it->next;
        }
        return -1;
    }

    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *temp = new Node;

        temp->val  = val;
        temp->next = head;
        temp->prev = NULL;

        if(!head)
            tail = temp;
        else
            head->prev = temp;
        head = temp;

        length++;
    }


    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *temp = new Node;

        temp->val = val;
        temp->prev = tail;
        temp->next = NULL;

        if(!tail)
            head = temp;
        else
            tail->next = temp;
        tail = temp;

        length++;
    }


    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == -1) { // ACCOUNT FOR FAULTY LEATCODE TEST CASE
            addAtHead(val);
            return;
        }

        if(index == length) {
            addAtTail(val);
            return;
        }
        else if(index == 0) {
            addAtHead(val);
            return;
        }

        Node *temp = new Node;
        temp->val = val;

        Node *current = head;
        for(int i=0; current; i++) {
            if(i == index) {
                temp->prev = current->prev;
                temp->next = current;

                current->prev->next = temp;
                current->prev = temp;

                length++;
                break;
            }
            current = current->next;
        }
    }


    void deleteHead() {
        if(length <= 1) {
            delete head;

            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;
            delete head->prev;
            head->prev = NULL;
        }

        if(length != 0)
            length--;
    }


    void deleteTail() {
        if(length <= 1) {
            delete tail;

            head = NULL;
            tail = NULL;
        }
        else {
            tail = tail->prev;
            delete tail->next;
            tail->next = NULL;
        }

        if(length != 0)
            length--;
    }
    

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index == 0) {
            deleteHead();
            return;
        }
        else if(index == length-1) {
            deleteTail();
            return;
        }


        Node *it = head;
        for(int i=0; it; i++) {
            if(i == index) {
                it->prev->next = it->next;
                it->next->prev = it->prev;
                delete it;

                length--;
                break;
            }
            it = it->next;
        }
    }
};


ostream& operator<<(ostream &os, const MyLinkedList &ll) {
    os << "linked list (" << ll.length << "): ";

    MyLinkedList::Node *temp = ll.head;
    while(temp != NULL) {
        os << temp->val << " ";
        temp = temp->next;
    }
    return os;
}


int main() {
    ios_base::sync_with_stdio(false);
    setbuf(stdout, NULL);

    MyLinkedList nums;

    nums.addAtHead(38);
    cout << nums << endl;

    nums.addAtHead(45);
    cout << nums << endl;

    nums.deleteAtIndex(2);
    cout << nums << endl;

    nums.addAtIndex(1, 24);
    cout << nums << endl;
}