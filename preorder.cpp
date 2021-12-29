/* Recursion */

void Preorder(struct Node* node)
{
    if (node == NULL) return;
    cout << node->data << " ";
    Preorder(node->left);
    Preorder(node->right);
}

/* Iterative */

void Preorder(node* root)
{
    if (root == NULL) return;
    stack<node*> nodeStack;
    nodeStack.push(root);
    while (nodeStack.empty() == false) {
        struct node* node = nodeStack.top();
        cout << node->data << " ";
        nodeStack.pop();
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}
