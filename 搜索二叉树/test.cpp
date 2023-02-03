#include <iostream>
using namespace std;

template <class T>
class TreeNode
{

public:
    TreeNode(const T &x = 0)
        : left(nullptr), right(nullptr), val(x)
    {
    }
    TreeNode *left;
    TreeNode *right;
    T val;
};

template <class T>
class BinarySearchTree
{
    typedef TreeNode<T> Node;

private:
    Node *root;
    void Inorder(Node *cur)
    {
        if (cur == nullptr)
            return;

        Inorder(cur->left);
        cout << cur->val << " ";
        Inorder(cur->right);
    }

public:
    BinarySearchTree()
        : root(nullptr)
    {
    }

    Node *find(const T &x)
    {
        Node *cur = root;

        if (x > cur->val)
        {
            cur = cur->right;
        }
        else if (x < cur->val)
        {
            cur = cur->left;
        }
        else
        {
            return cur;
        }
    }

    bool insert(const T &x)
    {
        Node *father = nullptr;
        Node *cur = root;

        while (cur)
        {
            if (x > cur->val)
            {
                father = cur;
                cur = cur->right;
            }
            else if (x < cur->val)
            {
                father = cur;
                cur = cur->left;
            }
            else
            {
                return false;
            }
        }

        if (cur == father)
        {
            root = new Node(x);
            return true;
        }
        else if (x < father->val)
        {
            cur = new Node(x);
            father->left = cur;
        }
        else if (x > father->val)
        {
            cur = new Node(x);
            father->right = cur;
        }
        return true;
    }

    bool Erase(const T &x)
    {
        // find
        Node *cur = root;
        Node *father = nullptr;

        while (cur)
        {
            if (x > cur->val)
            {
                father = cur;
                cur = cur->right;
            }
            else if (x < cur->val)
            {
                father = cur;
                cur = cur->left;
            }
            else
            {
                break;
            }
        }

        if (cur == nullptr) // 没有与x对应的删除的值
            return false;

        if (cur->left == nullptr)
        {
            if (father)
            {
                if (father->left == cur)
                {
                    father->left = cur->right;
                }
                else
                {
                    father->right = cur->right;
                }
            }
            else
            {
                root = cur->right;
            }
        }
        else if (cur->right == nullptr)
        {
            if (father)
            {
                if (father->left == cur)
                {
                    father->left = cur->left;
                }
                else
                {
                    father->right = cur->left;
                }
            }
            else
            {
                root = cur->left;
            }
        }
        else
        {
            // 找右子树的最小节点
            Node *son = cur->right;
            Node *parent = cur;
            while (son->left)
            {
                parent = son;
                son = son->left;
            }

            if (son == cur->right)
            {
                cur->val = son->val;
                cur->right = son->right;
            }
            else
            {
                cur->val = son->val;
                parent->left = son->right;
            }
        }
        return true;
    }

    void InOrder()
    {
        Inorder(root);
        cout << endl;
    }

    ~BinarySearchTree()
    {
    }
};

int main()
{
    BinarySearchTree<int> s;
    int a[] = {5, 3, 4, 1, 7, 8, 2, 6, 0, 9};

    for (auto &e : a)
    {
        s.insert(e);
    }

    s.InOrder();

    // s.Erase(2);
    s.Erase(5);
    s.InOrder();

    return 0;
}