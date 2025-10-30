#include <bits/stdc++.h>
#define int long long int
using namespace std;


struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent; // for Q10
    Node(int k): key(k), left(nullptr), right(nullptr), parent(nullptr) {}
};

void inorder(Node* root, vector<int>& out){
    if(!root) return;
    inorder(root->left, out);
    out.push_back(root->key);
    inorder(root->right, out);
}
void preorder(Node* root, vector<int>& out){
    if(!root) return;
    out.push_back(root->key);
    preorder(root->left, out);
    preorder(root->right, out);
}
void postorder(Node* root, vector<int>& out){
    if(!root) return;
    postorder(root->left, out);
    postorder(root->right, out);
    out.push_back(root->key);
}

int computeHeight(Node* root){
    if(!root) return 0;
    return 1 + max(computeHeight(root->left), computeHeight(root->right));
}
void computeDepths(Node* root, unordered_map<Node*, int>& depthMap, int depth=0){
    if(!root) return;
    depthMap[root] = depth;
    computeDepths(root->left, depthMap, depth+1);
    computeDepths(root->right, depthMap, depth+1);
}

Node* bstSearch(Node* root, int key){
    if(!root) return nullptr;
    if(root->key == key) return root;
    if(key < root->key) return bstSearch(root->left, key);
    return bstSearch(root->right, key);
}

Node* bstInsert(Node* root, int key){
    if(!root) return new Node(key);
    if(key < root->key){
        Node* l = bstInsert(root->left, key);
        root->left = l;
        if(l) l->parent = root;
    } else if(key > root->key){
        Node* r = bstInsert(root->right, key);
        root->right = r;
        if(r) r->parent = root;
    }
    return root;
}

Node* findMin(Node* root){
    if(!root) return nullptr;
    while(root->left) root = root->left;
    return root;
}
Node* findMax(Node* root){
    if(!root) return nullptr;
    while(root->right) root = root->right;
    return root;
}

Node* bstDelete(Node* root, int key){
    if(!root) return nullptr;
    if(key < root->key){
        root->left = bstDelete(root->left, key);
        if(root->left) root->left->parent = root;
    } 
    else if(key > root->key){
        root->right = bstDelete(root->right, key);
        if(root->right) root->right->parent = root;
    } 
    else {
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        } 
        else if(!root->left){
            Node* r = root->right;
            r->parent = root->parent;
            delete root;
            return r;
        } 
        else if(!root->right){
            Node* l = root->left;
            l->parent = root->parent;
            delete root;
            return l;
        } 
        else {
            Node* succ = findMin(root->right);
            root->key = succ->key;
            root->right = bstDelete(root->right, succ->key);
            if(root->right) root->right->parent = root;
        }
    }
    return root;
}

vector<int> levelOrder(Node* root){
    vector<int> res;
    if(!root) return res;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* u = q.front(); q.pop();
        res.push_back(u->key);
        if(u->left) q.push(u->left);
        if(u->right) q.push(u->right);
    }
    return res;
}

bool isBST(Node* root){
    vector<int> arr;
    inorder(root, arr);
    for(size_t i=1;i<arr.size();++i) if(arr[i] <= arr[i-1]) return false;
    return true;
}

Node* inorderSuccessor(Node* node){
    if(!node) return nullptr;
    if(node->right) return findMin(node->right);
    Node* p = node->parent;
    while(p && node == p->right){
        node = p;
        p = p->parent;
    }
    return p;
}

int catalan(int n){
    vector<long long> C(n+1, 0);
    C[0] = 1;
    for(int i=1;i<=n;i++){
        long long sum = 0;
        for(int j=0;j<i;j++){
            sum += C[j] * C[i-1-j];
        }
        C[i] = sum;
    }
    return (int)C[n];
}

Node* buildFromPreInHelper(const vector<int>& pre, int preL, int preR,const vector<int>& in, int inL, int inR,unordered_map<int,int>& inIndex, Node* parent=nullptr){
    if(preL > preR || inL > inR) return nullptr;
    int rootVal = pre[preL];
    Node* root = new Node(rootVal);
    root->parent = parent;
    int idx = inIndex[rootVal];
    int leftSize = idx - inL;
    root->left = buildFromPreInHelper(pre, preL+1, preL+leftSize, in, inL, idx-1, inIndex, root);
    root->right = buildFromPreInHelper(pre, preL+leftSize+1, preR, in, idx+1, inR, inIndex, root);
    return root;
}
Node* buildFromPreIn(const vector<int>& pre, const vector<int>& in){
    unordered_map<int,int> inIndex;
    for(size_t i=0;i<in.size();++i) inIndex[in[i]] = i;
    return buildFromPreInHelper(pre, 0, (int)pre.size()-1, in, 0, (int)in.size()-1, inIndex);
}

Node* buildFromInPostHelper(const vector<int>& post, int postL, int postR,const vector<int>& in, int inL, int inR,unordered_map<int,int>& inIndex, Node* parent=nullptr){
    if(postL > postR || inL > inR) return nullptr;
    int rootVal = post[postR];
    Node* root = new Node(rootVal);
    root->parent = parent;
    int idx = inIndex[rootVal];
    int leftSize = idx - inL;
    root->left = buildFromInPostHelper(post, postL, postL+leftSize-1, in, inL, idx-1, inIndex, root);
    root->right = buildFromInPostHelper(post, postL+leftSize, postR-1, in, idx+1, inR, inIndex, root);
    return root;
}
Node* buildFromInPost(const vector<int>& in, const vector<int>& post){
    unordered_map<int,int> inIndex;
    for(size_t i=0;i<in.size();++i) inIndex[in[i]] = i;
    return buildFromInPostHelper(post, 0, (int)post.size()-1, in, 0, (int)in.size()-1, inIndex);
}

vector<Node*> allTreesFromInorder3(int a, int b, int c){
    vector<Node*> res;

    Node* t1 = new Node(b);
    t1->left = new Node(a);
    t1->left->parent = t1;
    t1->right = new Node(c);
    t1->right->parent = t1;
    res.push_back(t1);

    Node* t2 = new Node(a);
    t2->right = new Node(b);
    t2->right->parent = t2;
    t2->right->right = new Node(c);
    t2->right->right->parent = t2->right;
    res.push_back(t2);

    Node* t3 = new Node(c);
    t3->left = new Node(b);
    t3->left->parent = t3;
    t3->left->left = new Node(a);
    t3->left->left->parent = t3->left;
    res.push_back(t3);

    Node* t4 = new Node(a);
    t4->right = new Node(c);
    t4->right->parent = t4;
    t4->right->left = new Node(b);
    t4->right->left->parent = t4->right;
    res.push_back(t4);

    Node* t5 = new Node(c);
    t5->left = new Node(a);
    t5->left->parent = t5;
    t5->left->right = new Node(b);
    t5->left->right->parent = t5->left;
    res.push_back(t5);

    return res;
}

pair<Node*, Node*> ambiguousTreesExample(){
    Node* A = new Node(1);
    A->left = new Node(2); A->left->parent = A;
    A->left->right = new Node(3); A->left->right->parent = A->left;

    Node* B = new Node(1);
    B->right = new Node(2); B->right->parent = B;
    B->right->left = new Node(3); B->right->left->parent = B->right;

    return {A,B};
}

Node* buildBalancedBSTFromSorted(const vector<int>& arr, int l, int r, Node* parent=nullptr){
    if(l>r) return nullptr;
    int mid = (l+r)/2;
    Node* root = new Node(arr[mid]);
    root->parent = parent;
    root->left = buildBalancedBSTFromSorted(arr, l, mid-1, root);
    root->right = buildBalancedBSTFromSorted(arr, mid+1, r, root);
    return root;
}
Node* buildDegenerateBST(const vector<int>& arr){
    //degenerate ante skewed 
    Node* root = nullptr;
    for(int v : arr) root = bstInsert(root, v);
    return root;
}

pair<bool,int> isBalancedHelper(Node* root){
    if(!root) return {true,0};
    auto L = isBalancedHelper(root->left);
    auto R = isBalancedHelper(root->right);
    bool ok = L.first && R.first && (llabs(L.second - R.second) <= 1);
    int h = 1 + max(L.second, R.second);
    return {ok, h};
}
bool isBalanced(Node* root){
    return isBalancedHelper(root).first;
}

Node* lcaBST(Node* root, int a, int b){
    if(!root) return nullptr;
    if(root->key > a && root->key > b) return lcaBST(root->left, a, b);
    if(root->key < a && root->key < b) return lcaBST(root->right, a, b);
    return root;
}

int countLeaves(Node* root){
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

pair<int,int> diameterHelper(Node* root){
    if(!root) return {0,0};
    auto L = diameterHelper(root->left);
    auto R = diameterHelper(root->right);
    int height = 1 + max(L.second, R.second);
    int dia = max({L.first, R.first, L.second + R.second + 1});
    return {dia, height};
}
int diameter(Node* root){
    return diameterHelper(root).first;
}

void serialize(Node* root, string& s){
    if(!root){
        s+="# ";
        return;
    }
    s+= to_string(root->key)+ " ";
    serialize(root->left, s);
    serialize(root->right, s);
}
Node* deserializeHelper(vector<string>&tokens , int &idx){
    if(idx>=tokens.size() || tokens[idx]=="#"){
        idx++;
        return nullptr;
    }
    Node* root=new Node(stoi(tokens[idx++]));
    root->left=deserializeHelper(tokens,idx);
    root->right=deserializeHelper(tokens,idx);
    return root;
}
Node* deserialize(const string& s){
    string token;
    vector<string>tokens;
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            token+=s[i];
        }
        else{
            tokens.push_back(token);
            token="";
        }
    }
    int idx=0;
    return deserializeHelper(tokens,idx);
}

void printVec(const vector<int>& v){
    for(size_t i=0;i<v.size();++i){
        if(i) cout << " ";
        cout << v[i];
    }
    cout << "\n";
}

int32_t main(){
    cout << "Q1: Node struct created (with parent pointer available)\n";

    Node* root = nullptr;
    vector<int> vals = {5,3,7,2,4,6,8};
    for(int v: vals) root = bstInsert(root, v);
    cout << "Traversals on BST constructed from {5,3,7,2,4,6,8}:\n";
    vector<int> out;
    out.clear(); preorder(root, out); cout << "Preorder: "; printVec(out);
    out.clear(); inorder(root, out);  cout << "Inorder:  "; printVec(out);
    out.clear(); postorder(root, out); cout << "Postorder:"; printVec(out);

    cout << "Q2 (b): Height of tree: " << computeHeight(root) << "\n";
    unordered_map<Node*,int> depthMap;
    computeDepths(root, depthMap);
    cout << "Depths (node:value):\n";
    out.clear(); inorder(root, out);
    for(int k: out){
        Node* n = bstSearch(root, k);
        cout << k << ":" << depthMap[n] << " ";
    }
    cout << "\n";

    cout << "Q3 (c): Search 4 -> " << (bstSearch(root,4) ? "Found" : "Not Found") << "\n";

    root = bstInsert(root, 10);
    cout << "Q4 (d): After inserting 10, LevelOrder: ";
    printVec(levelOrder(root));

    root = bstDelete(root, 3);
    cout << "Q5 (e): After deleting 3, LevelOrder: ";
    printVec(levelOrder(root));

    Node* mn = findMin(root);
    Node* mx = findMax(root);
    cout << "Q6 (f): Min = " << (mn?mn->key:-1) << " Max = " << (mx?mx->key:-1) << "\n";

    cout << "Q7 (g): Level Order printed above.\n";

    cout << "Q2 (verify BST): isBST -> " << (isBST(root) ? "Yes" : "No") << "\n";

    Node* node6 = bstSearch(root, 6);
    Node* succ = inorderSuccessor(node6);
    cout << "Q3 (inorder successor of 6): " << (succ ? to_string(succ->key) : string("None")) << "\n";

    cout << "Q4 (Catalan): C(0..10): ";
    for(int i=0;i<=10;i++) cout << catalan(i) << (i==10? "\n":" ");
    
    vector<int> pre = {1,2,4,5,3,6};
    vector<int> inr = {4,2,5,1,3,6};
    Node* treePI = buildFromPreIn(pre, inr);
    out.clear(); postorder(treePI, out);
    cout << "Q5 (reconstruct Pre+In -> Post): postorder: "; printVec(out);

    vector<int> in2 = {4,2,5,1,3,6};
    vector<int> post = {4,5,2,6,3,1};
    Node* treeIP = buildFromInPost(in2, post);
    out.clear(); preorder(treeIP, out);
    cout << "Q6 (reconstruct In+Post -> Pre): preorder: "; printVec(out);

    cout << "Q7: Different trees producing same inorder [10,20,30] and their inorder check:\n";
    auto mult = allTreesFromInorder3(10,20,30);
    for(size_t i=0;i<mult.size();++i){
        vector<int> tmp; inorder(mult[i], tmp);
        cout << "Tree " << i+1 << " inorder: "; printVec(tmp);
    }

    auto amb = ambiguousTreesExample();
    vector<int> pA, rA;
    preorder(amb.first, pA); postorder(amb.first, rA);
    vector<int> pB, rB;
    preorder(amb.second, pB); postorder(amb.second, rB);
    cout << "Q8: Tree A Preorder: "; printVec(pA);
    cout << "Q8: Tree A Postorder: "; printVec(rA);
    cout << "Q8: Tree B Preorder: "; printVec(pB);
    cout << "Q8: Tree B Postorder: "; printVec(rB);
    cout << "They match but structures differ.\n";

    int n = 15;
    vector<int> arr(n);
    for(int i=0;i<n;i++) arr[i] = i+1;
    Node* best = buildBalancedBSTFromSorted(arr, 0, n-1);
    Node* worst = buildDegenerateBST(arr);
    cout << "Q9: Height of best (balanced) for n=" << n << " : " << computeHeight(best) << "\n";
    cout << "Q9: Height of worst (degenerate chain) for n=" << n << " : " << computeHeight(worst) << "\n";
    cout << "Q9: Worst-case time complexity of search/insert/delete in BST: O(n). Average/balanced: O(log n)\n";

    cout << "Q10: Parent pointer included in Node and maintained during insert/delete above (where applicable).\n";

    cout << "Q11: isBalanced(best) -> " << (isBalanced(best) ? "Yes":"No") << "\n";
    cout << "Q11: isBalanced(worst) -> " << (isBalanced(worst) ? "Yes":"No") << "\n";

    Node* bstForLCA = nullptr;
    vector<int> v2 = {20,10,5,15,30,25,35};
    for(int x:v2) bstForLCA = bstInsert(bstForLCA, x);
    Node* lca = lcaBST(bstForLCA, 5, 15);
    cout << "Q12: LCA of 5 and 15 in BST: " << (lca? to_string(lca->key) : string("None")) << "\n";

    cout << "Q13: leaf count of bstForLCA: " << countLeaves(bstForLCA) << "\n";

    cout << "Q14: diameter (in nodes) of bstForLCA: " << diameter(bstForLCA) << "\n";

    cout << "Q15: serialize tree bstForLCA: ";
    {
        string oss;
        serialize(bstForLCA, oss);
        cout << oss << "\n";
        Node* restored = deserialize(oss);
        cout << "Q15: deserialize -> inorder of restored: ";
        vector<int> tmp; inorder(restored, tmp); printVec(tmp);
    }

    cout << "--- End of demonstrations for all questions ---\n";
}
