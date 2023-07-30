#pragma once
#include <utility>
#include <vector>

namespace sht
{
    enum STATE
    {
        EMPTY,
        DELETE,
        FULL
    };

    template <class K, class V>
    class HashNode
    {
    public:
        HashNode(const K &k = K(), const V &v = V(), const STATE s = EMPTY)
            : val(std::make_pair(k, v)), _state(s)
        {
        }
        std::pair<K, V> val;
        STATE _state = EMPTY;
    };

    template <class K, class V> // ,class hassi>
    class unordered_map
    {
        typedef HashNode<K, V> Node;
        typedef std::pair<K, V> ValueType;

    public:
        unordered_map(int x = 10)
            : _n(0)
        {
            map.resize(x);
        }

        Node *insert(const ValueType &x)
        {
            if (_n + 1 == map.size())
            {
                sht::unordered_map<K, V> tmp(2 * map.size());
                for (const auto &e : map)
                {
                    tmp.insert(e.val);
                }
                _n = 2 * map.size();
                tmp.map.swap(map);
                insert(x);
            }
            else
            {
                int key = x.first;
                int i = key % map.size();
                while (map[i]._state == FULL)
                {
                    if (i == map.size() - 1)
                    {
                        i = 0;
                        continue;
                    }
                    i++;
                }

                map[i].val = x;
                map[i]._state = FULL;
                _n++;
            }
        }

        Node *find(const K &x) // 找到返回节点地址，找不到空指针
        {
            int i = x % map.size();

            while (map[i]._state == FULL)
            {
                if (map[i].val.first == x) //.first == x.first && map[i].val.second == x.second)
                {
                    return &map[i];
                }
                if (i == map.size() - 1)
                {
                    i = 0;
                    continue;
                }
                i++;
            }

            return nullptr;
        }

    private:
        std::vector<Node> map; // hash表
        int _n;                // 标识有多少个有效元素存入了hash表中
    };
}