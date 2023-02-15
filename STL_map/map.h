
#include "RedBlackTree.h"
#include <utility>

namespace sht
{
    template <class Key, class Value>
    class map
    {
        struct Get_Key_From_ValueType
        {
            Key &operator()(std::pair<Key, Value> &v)
            {
                return v.first;
            }
        };

        sht::RBTree<Key, std::pair<Key, Value>> tree;
    };
}
