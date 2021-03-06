/* Binary search tree
implementation by
@prnjl-g */
#include<bits/stdc++.h>
using namespace std;


typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;
node * creat_node(int value)
{
    node *t=(node*)malloc(sizeof(node));
    t->left=NULL;
    t->right=NULL;
    t->data=value;
    return t;
}
node * inorder_successor(node * root)
{
    if(root->left==NULL)
        return root;
    return inorder_successor(root->left);
}
node * delete_node(node * root,int value)
{
    if(root==NULL)
        return root;
    else if(value<root->data)
        root->left=delete_node(root->left,value);
    else if (value>root->data)
        root->right=delete_node(root->right,value);
    else{
        if(root->left==NULL){
            node *t=root->right;
            free(root);
            return t;
        }
        else if(root->right==NULL)
        {
            node *t=root->left;
            free(root);
            return t;
        }
        else
        {
            node *t=(node*)malloc(sizeof(node));
            t=inorder_successor(root->right);
            root->data=t->data;
            root->right=delete_node(t,t->data);
            return root;
        }

    }
    return 0;
}
node * insert_node(node *root,int value)
{
    if(root==NULL)
    {

        return creat_node(value);
    }
    if(root->data==value)
        return root;
    else if(value<root->data)
    {

        root->left= insert_node(root->left,value);
        return root;
    }
    else
    {

        root->right= insert_node(root->right,value);
        return root;
    }
}
void inorder_trav(node * root)
{
    if(root==NULL)
        return ;
    inorder_trav(root->left);
    cout<<root->data<<"\t";
    inorder_trav(root->right);
}
void preorder_trav(node * root)
{
    if(root==NULL)
        return ;
        cout<<root->data<<"\t";
    inorder_trav(root->left);

    inorder_trav(root->right);
}
void postorder_trav(node * root)
{
    if(root==NULL)
        return ;

    inorder_trav(root->left);

    inorder_trav(root->right);
    cout<<root->data<<"\t";
}
int main()
{
    node *root=NULL;
    root=insert_node(root,1);
    for(int i=10;i>2;i--)
        insert_node(root,i);
        insert_node(root,10);
    inorder_trav(root);
    cout<<endl;
    preorder_trav(root);
    cout<<endl;
    postorder_trav(root);
    cout<<endl;
    delete_node(root,10);
    inorder_trav(root);
    cout<<endl;
    postorder_trav(root);
    return 0;
}








