#include <string>
#include <vector>

using namespace std;

struct Node {
    struct Node* left;
    struct Node* right;
    int x;
    int y;
    int data;
} Node;

void add(struct Node *parent, struct Node *node) {
    if (parent->x > node->x) {
        if (parent->left == nullptr) {
            parent->left = node;
        } else {
            add(parent->left, node);
        }
    } else {
        if (parent->right == nullptr) {
            parent->right = node;
        } else {
            add(parent->right, node);
        }
    }
}

void printInorder(struct Node *parent, vector<int> &vi) {
    if (parent == nullptr)
        return ;
    vi.push_back(parent->data);
    printInorder(parent->left, vi);
    printInorder(parent->right, vi);
}

void printPostorder(struct Node *parent, vector<int> &vi) {
    if (parent == nullptr)
        return ;
    printPostorder(parent->left, vi);
    printPostorder(parent->right, vi);
    vi.push_back(parent->data);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    struct Node *tree = (struct Node*) malloc(sizeof(struct Node));
    
    vector<vector<int>> answer;
    vector<int> vi;
    int x = 0, y = -99, n = 0;
    
    for (decltype(nodeinfo.size()) i = 0; i != nodeinfo.size(); i++) {
        for (decltype(nodeinfo.size()) j = 0; j != nodeinfo.size(); j++) {
            if (y < nodeinfo[j][1]) {
                y = nodeinfo[j][1];
                x = nodeinfo[j][0];
                n = j;
            }
        }
            
        struct Node *node = (struct Node*) malloc(sizeof(struct Node));
        node->left = nullptr;
        node->right = nullptr;
        node->x = x;
        node->y = y;
        node->data = n + 1;
        if (!i) {
            tree = node;
        } else {
            add(tree, node);
        }
        y = -99;
        nodeinfo[n][1] = -99;
    }
    printInorder(tree, vi);
    answer.push_back(vi);
    
    vi.clear();
    printPostorder(tree, vi);
    answer.push_back(vi);
    
    return answer;
}
