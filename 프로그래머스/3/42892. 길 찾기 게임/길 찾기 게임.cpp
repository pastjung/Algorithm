#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Node{
public:
    int x, y, idx;
    Node *left, *right;
    Node(int x, int y, int idx) : x(x), y(y), idx(idx), left(nullptr), right(nullptr){}
};

class BST{
private:
    Node* root;
    static bool cmp(Node* a, Node* b);
    Node* insertNode(Node* currentNode, Node* newNode);
    void preorderTraverse(Node* node, vector<int>& result);
    void postorderTraverse(Node* node, vector<int>& result);
public:   
    BST(vector<vector<int>> nodeinfo);
    vector<int> preorder();
    vector<int> postorder();
};

bool BST::cmp(Node* a, Node* b){
    if(a->y != b->y){
        return a->y > b->y;
    }
    return a->x < b->x;
}

Node* BST::insertNode(Node* currentNode, Node* newNode){
    if(currentNode == nullptr){
        return newNode;
    }
    
    if(newNode->x < currentNode->x){
        currentNode->left = insertNode(currentNode->left, newNode);
    } else{
        currentNode->right = insertNode(currentNode->right, newNode);
    }
    
    return currentNode;
}

BST::BST(vector<vector<int>> nodeinfo) : root(nullptr){
    vector<Node*> nodes;
    
    for(int idx = 0; idx < nodeinfo.size(); idx++){
        int x = nodeinfo[idx][0];
        int y = nodeinfo[idx][1];
     
        nodes.push_back(new Node(x, y, idx + 1));
    }
    
    sort(nodes.begin(), nodes.end(), cmp);
    
    for(Node* node : nodes){
        root = insertNode(root, node);
    }
}

void BST::preorderTraverse(Node* node, vector<int>& result){
    if(node == nullptr){
        return;
    }
    
    result.push_back(node->idx);
    preorderTraverse(node->left, result);
    preorderTraverse(node->right, result);
}

void BST::postorderTraverse(Node* node, vector<int>& result){
    if(node == nullptr){
        return;
    }
    
    postorderTraverse(node->left, result);
    postorderTraverse(node->right, result);
    result.push_back(node->idx);
}

vector<int> BST::preorder(){
    vector<int> result;
    preorderTraverse(root, result);
    return result;
}

vector<int> BST::postorder(){
    vector<int> result;
    postorderTraverse(root, result);
    return result;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    BST bst(nodeinfo);                  // BST 생성
    answer.push_back(bst.preorder());   // 전위 순회 결과 삽입
    answer.push_back(bst.postorder());  // 후위 순회 결과 삽입
    
    return answer;
}