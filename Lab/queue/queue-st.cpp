#include <bits/stdc++.h>
using namespace std;

class qImptl{
    stack<int> s1,s2;
public:
    void enqueue(int k){
        while(s1.size()>=0){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(k);
        while(s2.size()>=0){
            s1.push(s2.top());
            s2.pop();
        }
    }
    void dequeue(){
        s1.pop();
    }
    void peek(){
        s1.top();
    }
    bool isempty(){
        if(s1.size()==0) return true;
        else return false;
    }
};

int main(){

}