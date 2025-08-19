#ifndef LL_H
#define LL_H

#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;

    node(int data1, node* next1) {
        data = data1;
        next = next1;
    }

    node(int data1) {
        data = data1;
        next = nullptr;
    }
};

inline node* convert(vector<int> &arr) { 
    node* head = new node(arr[0]);
    node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head; 
}

inline int length(node* head) { 
    node* temp = head;
    int cnt = 0;
    while (temp != nullptr) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

inline bool isempty(node* head) { 
    return head == nullptr;
}

inline int max_el(node* head) { 
    node* temp = head;
    int el = INT_MIN;
    while (temp) {
        el = max(el, temp->data);
        temp = temp->next;
    }
    return el;
}

inline node* insert_beg(node* head, int k) { 
    node* add = new node(k);
    add->next = head;
    return add;
}

inline node* insert_end(node* head, int k) { 
    node* add = new node(k);
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = add;
    return head;
}

inline node* insert_pos(node* head, int k, int n) { 
    int len = length(head);
    if (n > len) return nullptr;
    node* add = new node(k);
    int i = 1;
    node* temp = head;
    while (i < n - 1) {
        temp = temp->next;
        i++;
    }
    add->next = temp->next;
    temp->next = add;
    return head;
}

inline void print(node* head) { 
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

inline node* del_beg(node* head) { 
    if (head == nullptr) return nullptr; 
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

inline node* del_end(node* head) { 
    if (head == nullptr) return nullptr;
    node* temp = head;
    while ((temp->next)->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

inline node* del_mid(node* head, int n) { 
    int len = length(head);
    if (n > len) return head;
    node* temp = head;
    node* mover = temp->next;
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

inline node* del_val(node* head, int n) { 
    node* temp = head;
    node* mover = temp->next;
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

inline node* search(node* head, int n) { 
    node* temp = head;
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

inline node* merge(node* head1, node* head2) { 
    node* temp = head1;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

inline node* rev(node* head) { 
    if (head == nullptr || head->next == nullptr) return head;
    node* curr = head;
    node* nxt = nullptr;
    node* prev = nullptr;
    while (curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

inline node* sort(node* head) { 
    node* temp = head;
    while (temp) {
        node* mover = temp;
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
