#include <iostream>
#include <utility>
#include <queue>
namespace sht
{
    template <class K, class V>
    struct TreeNode
    {
        TreeNode(const std::pair<K, V> &x)
            : _parent(nullptr), _left(nullptr), _right(nullptr), val(x), bf(0)
        {
        }

        TreeNode<K, V> *_parent;
        TreeNode<K, V> *_left;
        TreeNode<K, V> *_right; // 三叉链
        int bf;                 // 平衡因子
        std::pair<K, V> val;    // 值
    };

    template <class K, class V>
    class AVLTree
    {
        typedef TreeNode<K, V> Node;

    public:
        AVLTree()
            : _root(nullptr)
        {
        }

        bool find(const std::pair<K, V> &x)
        {
            Node *cur = _root;

            while (cur)
            {
                if (x.first > (cur->val).first)
                {
                    cur = cur->_right;
                }
                else if (x.first < (cur->val).first)
                {
                    cur = cur->_left;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }

        bool insert(const std::pair<K, V> &x)
        {

            // 找节点
            Node *cur = _root;
            Node *parent = nullptr;
            while (cur)
            {
                if (x.first > (cur->val).first)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else if (x.first < (cur->val).first)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else
                {
                    return false;
                }
            }

            // 插入
            cur = new Node(x);
            if (parent == nullptr) // 如果是第一个插入直接结束
            {
                _root = cur;
                return true;
            }

            cur->_parent = parent;
            if (x.first > (parent->val).first)
            {
                parent->_right = cur;
            }
            else if (x.first < (parent->val).first)
            {
                parent->_left = cur;
            }

            // 向上调节平衡因子

            while (parent) // 当parent为null时也就向上到头了
            {
                if (cur == parent->_left)
                    parent->bf--;
                else if (cur == parent->_right)
                    parent->bf++;

                if (parent->bf == 0) // 当bf为0时就不用继续向上调整了
                    break;
                else if (parent->bf == 2 || parent->bf == -2) // 需要旋转
                {
                    if (parent->bf == 2 && parent->_right->bf == 1)
                    {
                        Left_Rotate(parent);
                        break;
                    }
                    else if (parent->bf == -2 && parent->_left->bf == -1)
                    {
                        Right_Rotate(parent);
                        break;
                    }
                    else if (parent->bf == 2 && parent->_right->bf == -1)
                    {
                        Right_Left_Rotate(parent);
                        break;
                    }
                    else if (parent->bf == -2 && parent->_left->bf == 1)
                    {
                        Left_Right_Rotate(parent);
                        break;
                    }
                }
                else
                {
                    cur = parent;
                    parent = parent->_parent;
                }
            }
            return true;
        }

        void InOrder()
        {
            Inorder(_root);
            std::cout << std::endl;
        }

        void BFS()
        {
            std::queue<Node *> q;
            q.push(_root);

            while (!q.empty())
            {
                int sz = q.size();

                for (int i = 0; i < sz; i++)
                {
                    Node *tmp = q.front();
                    if (tmp)
                        std::cout << (tmp->val).first << " ";
                    else
                        std::cout << "NULL"
                                  << " ";
                    q.pop();
                    if (tmp)
                        q.push(tmp->_left);
                    if (tmp)
                        q.push(tmp->_right);
                }
                std::cout << std::endl;
            }
        }

    private:
        void Left_Rotate(Node *parent) // 左单旋
        {
            Node *pparent = parent->_parent;
            Node *subR = parent->_right;
            Node *subRL = subR->_left;

            subR->_left = parent;
            parent->_parent = subR;

            parent->_right = subRL;
            if (subRL)
                subRL->_parent = parent;

            if (pparent)
            {
                if (pparent->_left == parent)
                {
                    pparent->_left = subR;
                    subR->_parent = pparent;
                }
                else
                {
                    pparent->_right = subR;
                    subR->_parent = pparent;
                }
            }
            else
            {
                subR->_parent = nullptr;
                _root = subR;
            }
            parent->bf = 0;
            subR->bf = 0;
        }
        void Right_Rotate(Node *parent) // 右单旋
        {
            Node *pparent = parent->_parent;
            Node *subL = parent->_left;
            Node *subLR = subL->_right;

            subL->_right = parent;
            parent->_parent = subL;

            parent->_left = subLR;
            if (subLR)
                subLR->_parent = parent;

            if (pparent)
            {
                if (pparent->_left == parent)
                {
                    pparent->_left = subL;
                    subL->_parent = pparent;
                }
                else
                {
                    pparent->_right = subL;
                    subL->_parent = pparent;
                }
            }
            else
            {
                subL->_parent = nullptr;
                _root = subL;
            }
            parent->bf = 0;
            subL->bf = 0;
        }

        // parent->bf == -2 && parent->_left->bf == 1
        void Left_Right_Rotate(Node *parent) // 左右双旋
        {
            Node *subL = parent->_left;
            Node *subLR = subL->_right;
            int _bf = subLR->bf; // 记录旋转前的subLR的bf

            Left_Rotate(subL);
            Right_Rotate(parent);

            // 对于平衡因子的更新要根据subLR的bf分成三种情况
            if (_bf == 1)
            {
                subLR->bf = 0;
                subL->bf = -1;
                parent->bf = 0;
            }
            else if (_bf == -1)
            {
                subLR->bf = 0;
                subL->bf = 0;
                parent->bf = 1;
            }
            else
            {
                subLR->bf = 0;
                subL->bf = 0;
                parent->bf = 0;
            }
        }

        //  parent->bf == 2 && parent->_right->bf == -1
        void Right_Left_Rotate(Node *parent) // 右左双旋
        {
            Node *subR = parent->_right;
            Node *subRL = subR->_left;
            int _bf = subRL->bf; // 记录旋转前的subLR的bf

            Right_Rotate(subR);
            Left_Rotate(parent);

            if (_bf == 1)
            {
                subRL->bf = 0;
                subR->bf = 0;
                parent->bf = -1;
            }
            else if (_bf == -1)
            {
                subRL->bf = 0;
                subR->bf = 1;
                parent->bf = 0;
            }
            else
            {
                subRL->bf = 0;
                subR->bf = 0;
                parent->bf = 0;
            }
        }

        void Inorder(Node *cur)
        {
            if (cur == nullptr)
                return;

            Inorder(cur->_left);
            std::cout << (cur->val).first << " ";
            Inorder(cur->_right);
        }

        Node *_root;
    };
}