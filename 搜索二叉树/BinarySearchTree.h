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

    bool _Insert_R(Node *&root, const T &key) // 递归写法
    {
        if (root == nullptr)
        {
            root = new Node(key);
            return true;
        }
        if (key < root->val)
            return _Insert_R(root->left, key);
        else if (key > root->val)
            return _Insert_R(root->right, key);
        else
            return false;
    }

    Node *_find_R(Node *root, const T &key)
    {

        if (root == nullptr)
        {
            return nullptr;
        }

        if (key < root->val)
            return _find_R(root->left, key);
        else if (key > root->val)
            return _find_R(root->right, key);
        else
            return root;
    }

    bool _Erase_R(Node *&root, const T &key)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (key < root->val)
            return _Erase_R(root->left, key);
        else if (key > root->val)
            return _Erase_R(root->right, key);
        else
        {
            if (root->left == nullptr)
            {
                Node *tmp = root;
                root = root->right;
                delete tmp;
            }
            else if (root->right == nullptr)
            {
                Node *tmp = root;
                root = root->left;
                delete tmp;
            }
            else
            {
                Node *minright = root->right;
                while (minright->left)
                {
                    minright = minright->left;
                }

                std::swap(root->val, minright->val);

                _Erase_R(root->right, key);
            }
            return true;
        }
    }

public:
    BinarySearchTree()
        : root(nullptr)
    {
    }

    Node *find_R(const T &x)
    {
        return _find_R(root, x);
    }

    Node *find(const T &x) // 循环写法
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

    bool insert_R(const T &x) // 递归写法的插入
    {
        return _Insert_R(root, x);
    }

    bool insert(const T &x) // 循环写法的插入
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

    bool Erase_R(const T &x)
    {
        return _Erase_R(root, x);
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
                delete son;
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
