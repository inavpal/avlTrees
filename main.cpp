#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        height = 1;
    }
};


int height(Node *root)
{
    if(!root) return 0;
    return root->height;
}


int getBalance(Node *root)
{
return (height(root->left)-height(root->right));
}

void levelOrder(Node *root)
{
   if(!root) return;
   queue<Node*> q;
   q.push(root);
   q.push(NULL);
   while(q.size()>1)
   {
       Node *temp = q.front();
       q.pop();
       if(temp == NULL){
            cout<<endl;
        q.push(NULL);
       }
       else{
        cout<<temp->data<<" ";//<<"|"<<temp->height<<"----";
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
       }


   }



}

int maxm(int t1,int t2)
{
    return (t1>t2)?t1:t2;
}

Node* leftRotate(Node* root)
{
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->height = maxm(height(root->left),height(root->right))+1;
    temp->height = maxm(height(temp->left),height(temp->right))+1;
    return temp;
}

Node* rightRotate(Node* root)
{
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root->height = maxm(height(root->left),height(root->right))+1;
    temp->height = maxm(height(temp->left),height(temp->right))+1;
    return temp;
}
Node* insertt(Node *root,int x)
{
    if(!root) return (new Node(x));
    if(x < root->data)
        root->left = insertt(root->left,x);
    else if(x > root->data)
        root->right = insertt(root->right,x);

    //cout<<"fa";
    root->height = 1+maxm(height(root->left),height(root->right));
    //cout<<root->height<<" ";
    int balance = getBalance(root);
    //  cout<<"\n B"<<balance<<" ";
    if(balance > 1 && ( x < root->left->data))
     return rightRotate(root);
    if(balance > 1 && ( x > root->left->data ))
       {
           root->left = leftRotate(root->left);
           return (rightRotate(root));
       }
     if(balance < -1 && (x > root->right->data) )
        return leftRotate(root);
     if(balance < -1 && (x < root->right->data))
     {
         root->right = rightRotate(root->right);
         return (leftRotate(root));
     }

    return root;
}/*
void preOrder(Node *root)
{
    if(!root) return;
    cout<<root->data<<"|"<<root->height<<"  ";
    preOrder(root->left);
    preOrder(root->right);

}*/
int main()
{
    Node *root = NULL;
    root = insertt(root,5);
    //cout<<root->left->height;
    root = insertt(root,8);
    root = insertt(root,12);
    root = insertt(root,10);
    root = insertt(root,11);
    root = insertt(root,20);
    root = insertt(root,25);
    root = insertt(root,50);
    //preOrder(root);

    levelOrde r(root);
    return 0;
}
