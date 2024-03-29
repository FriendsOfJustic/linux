
#include <vector>
#include <iostream>
#include <queue>
namespace sht
{
    enum color
    {
        BLACK,
        RED
    };
    template <class K, class V>
    struct TreeNode
    {
        TreeNode(const std::pair<K, V> &x, color col = RED)
            : _parent(nullptr), _left(nullptr), _right(nullptr), val(x), _col(col)
        {
        }

        TreeNode<K, V> *_parent;
        TreeNode<K, V> *_left;
        TreeNode<K, V> *_right; // 三叉链
        color _col;             // 记录颜色
        std::pair<K, V> val;    // 值
    };

    template <class K, class V>
    class RBTree
    {
        typedef TreeNode<K, V> Node;

    public:
        RBTree()
            : _root(nullptr)
        {
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
                cur->_col = BLACK; // 第一个根节点一定是黑

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

            // 对树进行调整
            while (parent && cur->_col == RED && parent->_col == RED) // 只有这种情况需要对红黑树进行调整
            {
                Node *pparent = parent->_parent;
                Node *uncle = nullptr;
                if (parent == pparent->_left) // 第一大类
                {
                    uncle = pparent->_right;
                    if (uncle && uncle->_col == RED)
                    {

                        // case 1
                        if (pparent->_parent) // pparent为根节点时不需要改变颜色
                            pparent->_col = RED;

                        parent->_col = BLACK;
                        uncle->_col = BLACK;

                        // 继续向上调整，因为pparent被置成了红色，可能会与上面的产生冲突
                        cur = pparent;
                        parent = pparent->_parent;
                    }
                    else // uncle不存在  或   uncle存在且为黑
                    {
                        if (cur == parent->_left)
                        {
                            // case 2
                            Right_Rotate(pparent);
                            parent->_col = BLACK;
                            pparent->_col = RED;
                            break; // 情况二调整完之后就已经结束了
                        }
                        else
                        {
                            // case 3
                            Left_Rotate(parent);

                            // 情况三调整完之后会变成情况二
                            std::swap(cur, parent);
                        }
                    }
                }
                else // 第二大类
                {
                    uncle = pparent->_left;
                    if (uncle && uncle->_col == RED)
                    {
                        // case 1
                        parent->_col = BLACK;
                        uncle->_col = BLACK;
                        if (pparent != _root) // pparent 为根节点时不用调整颜色，因为根节点一定为黑色
                            pparent->_col = RED;

                        cur = pparent;
                        parent = pparent->_parent;
                    }
                    else
                    {
                        if (cur == parent->_right)
                        {
                            // case 2
                            Left_Rotate(pparent);
                            parent->_col = BLACK;
                            pparent->_col = RED;
                        }
                        else
                        {
                            // case 3
                            Right_Rotate(parent);

                            std::swap(cur, parent);
                        }
                    }
                }
            }
            return true;
        }

        void IsBalnace() // 检查红黑树是否平衡
        {
            bool is = parent_isRed(_root);

            std::vector<int> num;

            black_num_is_same(_root, num);

            bool it = true;
            int first = num[0];
            for (const auto &e : num)
            {
                if (e != first)
                {
                    it = false;
                    break;
                }
            }

            if (it && is)
            {
                std::cout << "it is a redblackTree" << std::endl;
            }
            else
            {
                std::cout << "it is not a redblackTree" << std::endl;
            }
        }

        void BFS() // 层序遍历树的所有节点
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
                    {
                        if (tmp->_col == BLACK)
                        {
                            std::cout << (tmp->val).first << "B"
                                      << " ";
                        }
                        else
                            std::cout << (tmp->val).first << "R ";
                    }
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
        }

        bool parent_isRed(Node *root) // 判断红色节点的父节点是不是黑色节点
        {
            if (root == nullptr)
            {
                return true;
            }

            if (root->_col == RED && root->_parent->_col == RED)
            {
                return false;
            }

            return parent_isRed(root->_left) && parent_isRed(root->_right);
        }

        void black_num_is_same(Node *root, std::vector<int> &num, int k = 0) // num存储了每条路径黑色节点的数量
        {
            if (root == nullptr)
            {
                num.push_back(k);
                return;
            }

            if (root->_col == BLACK)
            {
                k++;
            }

            black_num_is_same(root->_left, num, k);
            black_num_is_same(root->_right, num, k);
        }

        Node *_root;
    };
}