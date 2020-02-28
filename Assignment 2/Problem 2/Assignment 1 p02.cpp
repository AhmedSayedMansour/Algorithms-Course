/*
Problem 2
You have a binary tree t. Your task is to find the largest value in each row of this tree. In a
tree, a row is a set of Nodes that have equal depth. For example, a row with depth 0 is a tree
root, a row with depth 1 is composed of the root's children, etc.
Return an array in which the first element is the largest value in the row with depth 0, the
second element is the largest value in the row with depth 1, the third element is the largest
element in the row with depth 2, etc.
 -1 the output should be: [-1, 7, 1]
 / \
 5 7
 \
 1
In the row with depth 0, there is only one vertex - the root with value -1;
In the row with depth 1, there are two vertices with values 5 and 7, so the largest value here
is 7;
In the row with depth 2, there is only one vertex with value 1.
[input] tree.integer t
A binary tree of integers.
Guaranteed constraints: 0 ≤ tree size ≤ 5 · 104, -1000 ≤ Node value ≤ 1000.
[output] array.integer
An array of the largest values in each row of t.
Function Signature is => int[] largestValues (Tree<Integer> t)
*/

#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int val;
    Node* left;
    Node* right;
};
Node* newNode(int key)
{
    struct Node* temp = new Node;
    temp->val = key;
    temp->left = temp->right = NULL;
    return temp;
};
class Tree
{
public:
     Node* root;
    int i=0;
    Tree()
    {
        root=NULL;
    }
    void insert(int key)
    {
        if(root!=NULL)
            insert(root, key);
        else
        {
            root=new Node;
            root->val=key;
            root->left=NULL;
            root->right=NULL;
        }
        i++;
    }

    void insert(Node* temp, int key)
{
    queue<struct Node*> q;
    q.push(temp);

    // Do level order traversal until we find
    // an empty place.
    while (!q.empty()) {
        struct Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newNode(key);
            break;
        } else
            q.push(temp->left);

        if (!temp->right) {
            temp->right = newNode(key);
            break;
        } else
            q.push(temp->right);
    }
}

int* largestValues(Node* root)
{
    int l=log2(i)+1;
    int* ret= new int[l];
    queue<Node*> q;
    queue<Node*> q1;
    if (root == NULL)  return ret;
    int counter=0;
    q.push(root);
    int large;
    while (1+1==2)
    {
         large=q.front()->val;
         while (!q.empty()){
            Node* node = q.front();
            if (node->val>large)
                large=node->val;
             q.pop();
            if (node->left != NULL)
                q1.push(node->left);
            if (node->right != NULL)
                q1.push(node->right);

         }

          ret[counter++]=large;


        if (q1.empty())
            break;
        else
        {
            while(!q1.empty()){
                q.push(q1.front());
                q1.pop();
            }
        }
    }
    return ret;
}
int* largestValues()
{
    return  largestValues(root);
}
int getLevels(){
    return log2(i)+1;
}
};

int main()
{
    Tree a;
    a.insert(-1);
    a.insert(5);
    a.insert(7);
    a.insert(1);
    int* large=a.largestValues();
    for (int i=0;i<a.getLevels();i++){
        cout<<large[i]<<endl;
    }
  return 0;

}
