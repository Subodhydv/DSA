class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (!root)
            return NULL;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }

        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else {

            // Case 1: No child
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            }

            // Case 2: Only right child
            else if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 3: Only left child
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 4: Two children
            else {
                TreeNode* child = root->left;
                TreeNode* parent = root;

                // Find inorder predecessor
                while (child->right) {
                    parent = child;
                    child = child->right;
                }

                if (parent != root) {
                    parent->right = child->left;

                    child->left = root->left;
                    child->right = root->right;

                    delete root;
                    return child;
                }

                else {
                    child->right = root->right;

                    delete root;
                    return child;
                }
            }
        }
    }
};