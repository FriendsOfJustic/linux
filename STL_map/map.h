
#include "RedBlackTree.h"
#include <utility>

namespace sht
{
    template <class Key, class Value>
    class map
    {

        struct Get_Key_From_ValueType
        {
            Key operator()(const std::pair<Key, Value> &v)
            {
                return v.first;
            }
        };

    public:
        typedef std::pair<const Key, Value> ValueType;
        typedef sht::RBTreeiterator<ValueType, ValueType *, ValueType &> iterator;
        typedef sht::RBTreeiterator<ValueType, ValueType *, ValueType &> const_iterator;
        std::pair<iterator, bool> insert(const std::pair<Key, Value> x)
        {
            return tree.insert(x);
        }

        const_iterator begin() const // 常量迭代器
        {
            return tree.begin();
        }

        const_iterator end() const
        {
            return tree.end();
        }

        iterator begin() // 普通迭代器 ： 注意普通迭代器的key也是无法修改的
        {
            return tree.begin();
        }

        iterator end()
        {
            return tree.end();
        }

        void BFS()
        {
            tree.BFS();
        }

    private:
        sht::RBTree<Key, ValueType, Get_Key_From_ValueType> tree;
    };
}
