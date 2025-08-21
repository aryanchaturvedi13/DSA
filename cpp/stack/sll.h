#ifndef LL_H
#define LL_H

#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct node {
    T data;
    node* next;

    node(T data1, node* next1) {
        data = data1;
        next = next1;
    }

    node(T data1) {
        data = data1;
        next = nullptr;
    }
};

template<typename T>
inline node<T>* convert(vector<T> &arr) { 
    node<T>* head = new node<T>(arr[0]);
    node<T>* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        node<T>* temp = new node<T>(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head; 
}

template<typename T>
inline int length(node<T>* head) { 
    node<T>* temp = head;
    int cnt = 0;
    while (temp != nullptr) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

template<typename T>
inline bool isempty(node<T>* head) { 
    return head == nullptr;
}

template<typename T>
inline T max_el(node<T>* head) { 
    node<T>* temp = head;
    T el = temp->data; // assume head exists
    while (temp) {
        el = max(el, temp->data);
        temp = temp->next;
    }
    return el;
}

template<typename T>
inline node<T>* insert_beg(node<T>* head, T k) { 
    node<T>* add = new node<T>(k);
    add->next = head;
    return add;
}

template<typename T>
inline node<T>* insert_end(node<T>* head, T k) { 
    node<T>* add = new node<T>(k);
    node<T>* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = add;
    return head;
}

template<typename T>
inline node<T>* insert_pos(node<T>* head, T k, int n) { 
    int len = length(head);
    if (n > len) return nullptr;
    node<T>* add = new node<T>(k);
    int i = 1;
    node<T>* temp = head;
    while (i < n - 1) {
        temp = temp->next;
        i++;
    }
    add->next = temp->next;
    temp->next = add;
    return head;
}

template<typename T>
inline void print(node<T>* head) { 
    node<T>* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template<typename T>
inline node<T>* del_beg(node<T>* head) { 
    if (head == nullptr) return nullptr; 
    node<T>* temp = head;
    head = head->next;
    delete temp;
    return head;
}

template<typename T>
inline node<T>* del_end(node<T>* head) { 
    if (head == nullptr) return nullptr;
    node<T>* temp = head;
    while ((temp->next)->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

template<typename T>
inline node<T>* del_mid(node<T>* head, int n) { 
    int len = length(head);
    if (n > len) return head;
    node<T>* temp = head;
    node<T>* mover = temp->next;
    int i = 1;
    while (i < n - 1) {
        temp = temp->next;
        mover = mover->next;
        i++;
    }
    temp->next = mover->next;
    delete mover;
    return head;
}

template<typename T>
inline node<T>* del_val(node<T>* head, T n) { 
    node<T>* temp = head;
    node<T>* mover = temp->next;
    while (temp->next != nullptr) {
        if ((temp->next)->data == n) {
            temp->next = (temp->next)->next;
            delete mover;
            return head;
        }
        temp = temp->next;
        mover = mover->next;
    }
    return head;
}

template<typename T>
inline node<T>* search(node<T>* head, T n) { 
    node<T>* temp = head;
    int i = 1;
    while (temp != nullptr) {
        if (temp->data == n) {
            cout << i << " ";
        }
        temp = temp->next;
        i++;
    }
    return head;
}

template<typename T>
inline node<T>* merge(node<T>* head1, node<T>* head2) { 
    node<T>* temp = head1;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

template<typename T>
inline node<T>* rev(node<T>* head) { 
    if (head == nullptr || head->next == nullptr) return head;
    node<T>* curr = head;
    node<T>* nxt = nullptr;
    node<T>* prev = nullptr;
    while (curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

template<typename T>
inline node<T>* sort(node<T>* head) { 
    node<T>* temp = head;
    while (temp) {
        node<T>* mover = temp;
        while (mover) {
            if (mover->data < temp->data) {
                swap(mover->data, temp->data);
            }
            mover = mover->next;
        }
        temp = temp->next;
    }
    return head;
}

#endif // LL_H
