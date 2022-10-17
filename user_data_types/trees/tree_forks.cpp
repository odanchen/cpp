#include<iostream>

using namespace::std;

struct tree
{
    tree *left = NULL;
    tree *right = NULL;
    int value = 0;
};

bool isFork(tree *node)
{
    return (node->left != NULL && node->right != NULL);
}

void traverse(tree *node)
{
    if (node == NULL) return;
    
    traverse(node->left);
    if (isFork(node)) cout << node->value << ' ';
    traverse(node->right);
}

void buildTree(tree *&root)
{
    int curValue = -1;
    tree *curNode = root;
    tree *prevNode = root;
    cin >> curValue;
    root->value = curValue;
    
    while(curValue != 0)
    {
        cin >> curValue;
        curNode = root;
        
        if (curValue != 0)
        {
            while(curNode != NULL && curNode->value != curValue)
            {
                if (curValue > curNode->value)
                {
                    prevNode = curNode;
                    curNode = curNode->right;
                }
                else
                {
                    prevNode = curNode;
                    curNode = curNode->left;
                }
            }
        
            if (curNode == NULL)
            {
                if (curValue > prevNode->value)
                {
                    tree *addNode = new tree;
                    addNode->value = curValue;
                    prevNode->right = addNode;
                }
                else if (curValue < prevNode->value)
                {
                    tree *addNode = new tree;
                    addNode->value = curValue;
                    prevNode->left = addNode;
                }
            }
        }
    }
}



int main()
{
    tree *root = new tree;
    buildTree(root);
    if (root->value != 0) traverse(root);
}
