#pragma once
#include <utility>
#include <vector>
#include<string>

namespace sht
{
    template <class K, class V>
    class HashNode
    {
    public:
        HashNode(const K& k = K(), const V& v = V())
            : val(std::make_pair(k, v))
        {
        }
        HashNode<K, V>* next;   //��һ���ڵ�
        std::pair<K, V> val;
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
    template <class K, class V,class Hash=HashFunc<K> > // ,class hassi>
    class unordered_map
    {
        typedef HashNode<K, V> Node;
        typedef std::pair<K, V> ValueType;

    public:
        unordered_map(int x = 10)
            : _n(0)
        {
            map.resize(x);
            for (auto& e : map)
            {
                e = nullptr;
            }
        }

        Node* insert(const ValueType& x)
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

                            int pos = hashi((cur->val).first) % newmap.size();  //ȡ�� ɢ�е�ַ
                            Node* tmp = newmap[pos];
                            newmap[pos] = cur;
                            cur->next = tmp;


                            cur = next;

                        }
                    }
                }
                map.swap(newmap);
            }


            //����Ԫ��
            Node* ret = find(x.first);
            if (ret)
                return ret;
            int pos = hashi(x.first) % map.size();  //ȡ�� ɢ�е�ַ

            Node* newnode = new Node(x.first, x.second);
            Node* cur = map[pos];
            map[pos] = newnode;
            newnode->next = cur;
            _n++;
            return newnode;
        }

        Node* find(const K& x) // �ҵ����ؽڵ��ַ���Ҳ�����ָ��
        {
            int pos = hashi(x) % map.size();  //ȡ�� ɢ�е�ַ


            Node* cur = map[pos];
            while (cur)
            {
                if (cur->val.first == x)
                    return cur;
                cur = cur->next;
            }

            return nullptr;
        }

    private:
        HashFunc<K> hashi;
        std::vector<Node*> map; // hash��
        int _n;                // ��ʶ�ж��ٸ���ЧԪ�ش�����hash����
    };
}