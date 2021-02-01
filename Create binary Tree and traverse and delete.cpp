#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *newNode(int val)
{
    Node *temp=new Node;
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
Node *insertValue(Node *root,int val,queue<Node*>&q)
{
    Node *temp=newNode(val);
    if(root==NULL)
        root=temp;
    else if(q.front()->left==NULL)
        q.front()->left=temp;
    else
    {
        q.front()->right=temp;
        q.pop();
    }
    q.push(temp);
    return root;
}
Node *createTree(int arr[],int n)
{
    Node *root=NULL;
    queue<Node*>q;
    for(int i=0;i<n;i++)
        root=insertValue(root,arr[i],q);
    return root;
}
void Inorder(Node *temp)
{
    if(temp!=NULL)
    {
        Inorder(temp->left);
        printf("%d\t",temp->data);
        Inorder(temp->right);
    }
}
void Preorder(Node *temp)
{
    if(temp!=NULL)
    {
        printf("%d\t",temp->data);
        Preorder(temp->left);
        Preorder(temp->right);
    }
}
void Postorder(Node *temp)
{
    if(temp!=NULL)
    {
        Postorder(temp->left);
        Postorder(temp->right);
        printf("%d\t",temp->data);
    }
}
void levelOrder(struct Node* root)
{
	if (root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		printf("%d\t",q.front()->data);
		if (q.front()->left != NULL)
			q.push(q.front()->left);
		if (q.front()->right != NULL)
			q.push(q.front()->right);
		q.pop();
	}
}
void deleteFullTree(Node* node)
{
    if (node == NULL) return;

    /* first delete both subtrees */
    deleteFullTree(node->left);
    deleteFullTree(node->right);

    /* then delete the node */
    cout << "Deleting node: " << node->data << endl;
    delete node;
}

void deleteTree(Node** node_ref)
{
    deleteFullTree(*node_ref);
    *node_ref = NULL;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node *root=createTree(arr,n);
    printf("Pre Order   : ");
    Preorder(root);
    printf("\nIn Order    : ");
    Inorder(root);
    printf("\nPost Order  : ");
    Postorder(root);
    printf("\nLevel Order : ");
    levelOrder(root);
    printf("\n");
    deleteTree(&root);
    Inorder(root);
}
