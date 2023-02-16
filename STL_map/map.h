
#include "RedBlackTree.h"
#include <utility>

namespace sht
{
    template <class Key, class Value>
    class map
    {
        typedef std::pair<Key, Value> ValueType;
        typedef RBTreeiterator<ValueType, ValueType *, ValueType &> iterator;

        struct Get_Key_From_ValueType
        {
            Key operator()(const std::pair<Key, Value> &v)
            {
                return v.first;
            }
        };

    public:
        bool insert(const std::pair<Key, Value> x)
        {
            return tree.insert(x);
        }

        iterator begin()
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
