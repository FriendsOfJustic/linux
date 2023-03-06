#pragma once
#include <utility>
#include <vector>
#include<string>
#include<assert.h>

namespace sht
{
    template <class ValueType>
    class HashNode
    {
    public:
        HashNode(const ValueType & x=ValueType() )
            : val(x)
        {
        }
        HashNode<ValueType>* next;   //下一个节点
        ValueType val;
    };


    template<class T>
    class HashFunc
    {
    public:
        size_t operator()(const T& x)
        {
            return (size_t)x;
        }

    };

    template<>
    class HashFunc<std::string>
    {
    public:
        size_t operator()(const std::string& s)
        {
            size_t ret = 0;
            for (auto& e : s)
            {
                ret += e - '0';
            }
            return ret;
        }
    };

    

    template<class ValueType,class Ref,class Ptr, class Hash, class Get_key>
    class HashTable_iterator
    {
    public:
        typedef HashNode<ValueType> Node;
        typedef HashTable_iterator<ValueType, Ref, Ptr,Hash,Get_key> iterator;

        HashTable_iterator(Node* x,std::vector<Node*> *map)   //构造函数
            :p(x)
            ,_map(map)
        {

        }

        bool operator==(const iterator& x)
        {
            return (p == x.p) && (_map == x._map);
        }


        bool operator!=(const iterator& x)
        {
            return !(*this == x);
        }




        iterator& operator++()
        {
            int sz = (*_map).size();
            if (p->next!=nullptr)
            {
                p = p->next;
            }
            else
            {

                int pos = hashi(Key(p->val)) % sz+1;  //取得 散列地址

                while (pos < sz && (*_map)[pos] == nullptr)
                {
                    pos++;
                }

                if (pos < sz)
                    p = (*_map)[pos];
                else
                    p = nullptr;
            }

            return *this;
        }

        Ref operator*()
        {
            return (*p).val;
        }

        Ptr operator->()
        {
            return &((*p).val);
        }



    private:
        Node* p; 
        std::vector<Node*>* _map; // hash表
        Get_key Key;
        Hash hashi;

    };


    template <class K, class ValueType,class Hash ,class Get_key> // ,class hassi>
    class HashTable
    {
        typedef HashNode<ValueType> Node;
        typedef HashTable_iterator<ValueType,ValueType&,ValueType*,Hash,Get_key> iterator;
       
    public:
        HashTable(int x = 10)
            : _n(0)
        {
            map.resize(x);
            for (auto& e : map)
            {
                e = nullptr;
            }
        }

       

        iterator begin()
        {
            for (const auto &e : map)
            {
                if (e != nullptr)
                    return iterator(e,&map);
            }
        }


        iterator end()
        {
            return iterator(nullptr, &map);
        }


        std::pair<iterator,bool>  insert(const ValueType& x)
        {
            

            if ((double)_n / (double) map.size() >= 1.0)
            {
                std::vector<Node*> newmap;
                newmap.resize(map.size() * 2);

                for (auto& e : map)
                {
                    if (e != nullptr)
                    {
                        Node* cur = e;
                        while (cur)
                        {
                            Node* next = cur->next;

                            int pos = hashi((cur->val).first) % newmap.size();  //取得 散列地址
                            Node* tmp = newmap[pos];
                            newmap[pos] = cur;
                            cur->next = tmp;


                            cur = next;

                        }
                    }
                }
                map.swap(newmap);
            }


            //插入元素
            Node* ret = find(Key(x));
            if (ret)
                return std::make_pair(iterator(ret,&map),false);
            int pos = hashi(Key(x)) % map.size();  //取得 散列地址

            Node* newnode = new Node(x);
            Node* cur = map[pos];
            map[pos] = newnode;
            newnode->next = cur;
            _n++;
            return make_pair(iterator(newnode,&map), true);

        }

        Node* find(const K& x) // 找到返回节点地址，找不到空指针
        {
            int pos = hashi(x) % map.size();  //取得 散列地址


            Node* cur = map[pos];
            while (cur)
            {
                if (Key(cur->val) == x)
                    return cur;
                cur = cur->next;
            }

            return nullptr;
        }



       /* V& operator[](const K& x)
        {
            auto 
        }*/

    private:
        Get_key Key;
        Hash hashi;
        std::vector<Node*> map; // hash表
        int _n;                // 标识有多少个有效元素存入了hash表中
    };
}