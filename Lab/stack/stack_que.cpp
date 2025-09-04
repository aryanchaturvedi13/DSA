#include <bits/stdc++.h>
using namespace std;

class sImptl{
    queue <int> q;
public:
    void push_1(int k){
        q.push(k);
        int s=q.size();
        for(int i=1;i<=s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    void peek(){
        cout<<q.back()<<endl;
    }
    bool isempty(){
        if(q.empty()) return true;
        else return false;
    }
    void pop_1(){
        q.pop();
    }
};




int main(){
    int arr[]={2,5,7,9,6,4,1,3};
    sImptl q;
    for(auto i:arr) q.push_1(i);
    q.peek();
    q.pop_1();

}