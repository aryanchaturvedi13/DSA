#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node* parent;

    node(int k){
        data=k;
        left=nullptr;
        right=nullptr;
        parent=nullptr;
    }

    node(int k,node* l,node* r,node* p){
        data=k;
        left=l;
        right=r;
        parent=p;
    }
};

void preorder(node* root,vector<int> &pre){
    if(!root) return;
    pre.push_back(root->data);
    preorder(root->left,pre);
    preorder(root->right,pre);
}

void inorder(node* root, vector<int> &in){
    if(!root) return;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

void postorder(node* root, vector<int> &post){
    if(!root) return;
    postorder(root->left,post);
    postorder(root->right,post);
    post.push_back(root->data);
}

void levelOrder(node* root, vector<int> &level){
    if(!root) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        level.push_back(temp->data);
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int height(node* root){
    if(!root) return 0;
    return 1+max(height(root->left),height(root->right));
}

void Depth(node* root, unordered_map<node*, int> depthdata,int depth=0){
    if(!root) return;
    depthdata[root]=depth;
    Depth(root->left,depthdata,depth+1);
    Depth(root->right,depthdata,depth+1);
}

node* insert(node* root, int data){
    if(!root) return nullptr;
    node* temp= new node(data);
    if(data<root->data){
        node* l=insert(root->left,data);
        root->left=l;
        // l->parent=root;
    }
    else{
        node* r=insert(root->right,data);
        root->right=r;
        // r->parent=root;
    }
    return root;
}

node* findMin(node*root){
    if(!root) return nullptr;
    while(root->left) root=root->left;
    return root;
}

node* findMax(node* root){
    if(!root) return  nullptr;
    while(root && root->right!=nullptr) root=root->right;
    return root;
}

node* del(node* root, int data){
    if(data<root->data){
        root->left=del(root->left,data);
        if(root->left) root->left->parent=root;
    }
    else if(data>root->data){
        root->right=del(root->right,data);
        if(root->right) root->right->parent=root;
    }
    else{
        if(!root->right && !root->left){
            delete root;
            return nullptr;
        }
        else if(!root->left){
            node* r=root->right;
            r->parent=root->parent;
            delete root;
            return r;
        }
        else if(!root->right){
            node* l=root->left;
            l->parent=root->parent;
            delete root;
            return l;
        }
        else{
            node* nxt=findMin(root->right);
            root->data=nxt->data;
            root->right=del(root->right,nxt->data);
        }
    return root;
    }
}   

int maxInBST(node* root){
    if(!root) return -1;
    node* temp=root;
    while(temp->right){
        temp=temp->right;
    }
    return temp->data;
}

int minInBST(node* root){
    if(!root) return -1;
    node* temp=root;
    while(temp->left){
        temp=temp->left;
    }
    return temp->data;
}

vector<vector<int>> levelOrder(node* root) {
        if(!root) return {};
        queue<node*> q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size=q.size();
            for(int i=0;i<size;i++){
                node* temp=q.front();
                q.pop();
                level.push_back(temp->data);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(level);
        }
        return ans;
    }

bool isBST(node* root){
    vector<int>in;
    inorder(root,in);
    for(int i=0;i<in.size()-1;i++){
        if(in[i]>in[i+1]) return false;
    }
    return true;
}

node* inOrderPredecessor(node* root, node* x){
    node* pred=new node (-1);
    while(root){
        if(x->data<=root->data){
            root=root->left;
        }
        else{
            pred=root;
            root=root->right;
        }
    }    
    return pred;
}

node* inOrderSuccessor(node* root, node* x){
    node* suc=new node(-1);
    while(root){
        if(x->data>=root->data){
            root=root->right;
        }
        else{
            suc=root;
            root=root->left;
        }
    }
    return suc;

}

int noOfBSTs(int n){
    int x=1;
    int y=1;
    for(int i=0;i<2*n;i++) x*=(i+1);
    for(int i=0;i<n;i++) y*=(i+1);
    return x/pow(y,2);
}

vector<node*> allTreesFromInorder3(int a, int b, int c){
    vector<node*> res;

    node* t1 = new node(b);
    t1->left = new node(a);
    t1->left->parent = t1;
    t1->right = new node(c);
    t1->right->parent = t1;
    res.push_back(t1);

    node* t2 = new node(a);
    t2->right = new node(b);
    t2->right->parent = t2;
    t2->right->right = new node(c);
    t2->right->right->parent = t2->right;
    res.push_back(t2);

    node* t3 = new node(c);
    t3->left = new node(b);
    t3->left->parent = t3;
    t3->left->left = new node(a);
    t3->left->left->parent = t3->left;
    res.push_back(t3);

    node* t4 = new node(a);
    t4->right = new node(c);
    t4->right->parent = t4;
    t4->right->left = new node(b);
    t4->right->left->parent = t4->right;
    res.push_back(t4);

    node* t5 = new node(c);
    t5->left = new node(a);
    t5->left->parent = t5;
    t5->left->right = new node(b);
    t5->left->right->parent = t5->left;
    res.push_back(t5);

    return res;
}


bool isBalanced(node* root){
    if(!root || (!root->right && !root->left)) return true;
    if(abs(height(root->left)-height(root->right))>1) return false;
    else{
        return isBalanced(root->left) && isBalanced(root->right);
    }
}

node* leastCommonAncestor(node* root, node* p, node* q){
    if(!root) return nullptr;
    if(p->data<root->data && q->data<root->data) leastCommonAncestor(root->left,p,q);
    else if(p->data>root->data && q->data>root->data) leastCommonAncestor(root->right,p,q);
    return root;
}

int noOfLeaves(node* root){
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    if(!root->left) return noOfLeaves(root->right);
    else if(!root->right) return noOfLeaves(root->left);
    else return noOfLeaves(root->right)+noOfLeaves(root->left);
}

int maxi=0;
int diameter(node* root){
    if(!root) return 0;
    maxi=max(maxi,height(root->left)+height(root->right));
    diameter(root->left);
    diameter(root->right);
    return maxi;
}

// using level order traversal
string serialize(node* root) {
        if(!root) return "";
        string s="";
        queue<node*> q;
        q.push(root);
        while(!q.empty()){
            node* curr=q.front();
            q.pop();

            if(curr==nullptr) s+="#,";
            else s+=to_string(curr->data)+",";

            if(curr){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

node* deserialize(string data) {
    if(data.size()==0) return nullptr;
    queue<node*> q;
    stringstream s(data);
    string str;
    getline(s,str,',');
    node* root= new node (stoi(str));
    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
        q.pop();

        getline(s,str,',');
        if(str=="#") curr->left=nullptr;
        else{
            node* leftnode= new node(stoi(str));
            curr->left=leftnode;
            q.push(leftnode);
        }

        getline(s,str,',');
        if(str=="#") curr->right=nullptr;
        else{
            node* rightnode=new node(stoi(str));
            curr->right=rightnode;
            q.push(rightnode);
        }
    }
    return root;
}




int main(){
    node* n1=new node(10);
    n1=insert(n1,15);
    n1=insert(n1,3);
    n1=insert(n1,1);
    n1=insert(n1,5);
    n1=insert(n1,19);
    n1=insert(n1,23);
    string k=serialize(n1);
    for(auto i:k) cout<<i<<" ";
}