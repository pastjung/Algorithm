#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 노드 클래스
class Node{
public:
    int idx, x, y;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int idx, int x, int y) : idx(idx), x(x), y(y){}
};

// BST 클래스
class BST{
private:
    Node* root = nullptr;
    static bool cmp(Node* a, Node* b);
    Node* insertNode(Node* node, Node* newNode);
    void preorderTraverse(Node* node, vector<int>& result);
    void postorderTraverse(Node* node, vector<int>& result);
public:
    // 생성자
    BST(vector<vector<int>> nodeinfo);
    
    // 노드 추가 멤버 함수
    void insert(int idx, int x, int y);
    
    // 전위 순회 멤버 함수
    vector<int> preorder();
    
    // 후위 순회 멤버 함수
    vector<int> postorder();
};

bool BST::cmp(Node* a, Node* b){
    if(a->y != b-> y){
        return a->y > b->y;
    }
    return a->x < b->x;
}

BST::BST(vector<vector<int>> nodeinfo){
    vector<Node*> nodes;
    
    // 각 노드의 (인덱스, x좌표, y좌표) 정보를 nodes에 저장
    for(int i = 0; i < nodeinfo.size(); i++){
        nodes.push_back(new Node(i+1, nodeinfo[i][0], nodeinfo[i][1]));
    }
    
    // 이진 트리를 구축하기 위해 노드를 정렬
    sort(nodes.begin(), nodes.end(), cmp);
    
    // 이진 트리 구축
    for(Node* node : nodes){
        root = insertNode(root, node);
    }
}

Node* BST::insertNode(Node* currentNode, Node* newNode){
    if(currentNode == nullptr){
        return newNode;
    }
    
    // 추가하려는 노드의 좌표를 기준으로 현재 노드의 좌, 우 여부 판단 후 추가
    if(newNode-> x < currentNode->x){
        currentNode->left = insertNode(currentNode->left, newNode);
    } else{
        currentNode->right = insertNode(currentNode->right, newNode);
    }
    
    return currentNode;
}

void BST::preorderTraverse(Node* node, vector<int>& result) {
    if (node == nullptr){
        return;  
    }
    result.push_back(node->idx);
    preorderTraverse(node->left, result);
    preorderTraverse(node->right, result);
}

void BST::postorderTraverse(Node* node, vector<int>& result) {
    if (node == nullptr){
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
    
    // BST 생성
    BST bst(nodeinfo);
    
    // 전위, 후위 순회 결과 저장
    answer.push_back(bst.preorder());
    answer.push_back(bst.postorder());
    
    return answer;
}