
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
        typedef std::pair<const Key, Value> ValueType;    //注意这里定义的ValueType是实际树节点里面存的内容
        typedef typename sht::RBTree<Key, ValueType, Get_Key_From_ValueType>::iterator iterator;
        typedef typename sht::RBTree<Key, ValueType, Get_Key_From_ValueType>::const_iterator const_iterator;
        
        
        
        std::pair<iterator,bool> insert(const std::pair<Key, Value> x)
        {
            return tree.insert(x);
        }


        Value&  operator [](const Key& x)
        {
            auto ret = tree.insert(std::make_pair(x, Value()));
            return (ret.first)->second;
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