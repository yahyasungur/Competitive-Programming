#include <bits/stdc++.h>

using namespace std;
	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/
    
    void recursiveOrder(Node *root, int level, vector<vector<int>>& arr){
        if (!root) {
            return;
        }
        
        if (arr.size() <= level) {
            arr.push_back({});
        }
        
        arr[level].push_back(root->data);
        recursiveOrder(root->left, 1+level, arr);
        recursiveOrder(root->right, 1+level, arr);
    }
    
    void levelOrder(Node * root) {
        vector<vector<int>> arr;
        recursiveOrder(root, 0, arr);
        for (auto level : arr) {
            for (auto data : level) {
                cout<< data << " ";
            }
        }
    }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.levelOrder(root);

    return 0;
}
