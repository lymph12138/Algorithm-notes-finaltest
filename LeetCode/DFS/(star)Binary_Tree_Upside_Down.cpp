/*
156
TreeNode* UpsideDownBinaryTree(TreeNode* root){
    if(!root || !root->left)    return root;
    TreeNode* newNode=UpsideDownBinaryTree(root->left);
    root->left->left=root->right;
    root->left->right=root;
    root->left=NULL;
    root->right=NULL;
    return newNode;
}
*/