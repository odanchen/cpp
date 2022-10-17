
#include<iostream>

using namespace::std;

struct tree
{
    tree *left = NULL;
    tree *right = NULL;
    int value = 0;
};

void traverse(tree *node, int &cnt)
{
    if (node == NULL) return;
    
    traverse(node->left, cnt);
    cnt++;
    traverse(node->right, cnt);
}

int countTreeElements(tree *node)
{
    int cnt = 0;
    
    traverse(node, cnt);
    
    return cnt;
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
    cout << countTreeElements(root);
}
