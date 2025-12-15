#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

TreeNode* AddNode(TreeNode* root, int val)
{
    if (!root) return new TreeNode(val);

    if (val < root->data)
        root->left = AddNode(root->left, val);
    else if (val > root->data)
        root->right = AddNode(root->right, val);

    return root;
}
void Inorder(TreeNode* root)
{
    if (!root) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(TreeNode* root)
{
    if (!root) return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(TreeNode* root)
{
    if (!root) return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}
int totalNodes(TreeNode* root)
{
    if (!root) return 0;
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}

int leafNodes(TreeNode* root)
{
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return leafNodes(root->left) + leafNodes(root->right);
}

int internalNodes(TreeNode* root)
{
    if (!root || (!root->left && !root->right))
        return 0;
    return 1 + internalNodes(root->left) + internalNodes(root->right);
}
TreeNode* mirror(TreeNode* root)
{
    if (!root) return nullptr;

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);

    return root;
}
int main()
{
    TreeNode* root = nullptr;
    int choice, val;

    while (true)
    {
        cout << "\n=== RECURSIVE TREE OPERATIONS ===\n";
        cout << "1. Insert Node\n";
        cout << "2. Inorder\n";
        cout << "3. Preorder\n";
        cout << "4. Postorder\n";
        cout << "5. Count Total Nodes\n";
        cout << "6. Count Leaf Nodes\n";
        cout << "7. Count Internal Nodes\n";
        cout << "8. Mirror Tree\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                root = AddNode(root, val);
                break;

            case 2:
                cout << "Inorder: ";
                Inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Preorder: ";
                Preorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder: ";
                Postorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Total Nodes = " << totalNodes(root) << endl;
                break;

            case 6:
                cout << "Leaf Nodes = " << leafNodes(root) << endl;
                break;

            case 7:
                cout << "Internal Nodes = " << internalNodes(root) << endl;
                break;

            case 8:
                mirror(root);
                cout << "Tree mirrored.\n";
                break;

            case 9:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
