/* Recursion */

void Inorder(struct Node* node)
{
    if (node == NULL) return;
    Inorder(node->left);
    cout << node->data << " ";
    Inorder(node->right);
}

/* Iterative */

void inOrder(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL and s.empty() == false)
    {
        while (curr !=  NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    } 
}