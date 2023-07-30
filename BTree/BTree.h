#pragma once
#include<vector>
#include<iostream>
#include<queue>
namespace sht
{
	template<class K, size_t M>
	class BTreeNode
	{
	public:
		//如果下标相同  array_node[i] 是 array_k[i] 的左节点
		BTreeNode()
		{
			//把数组初始化一下
			for (int i = 0; i < M; i++)
			{
				array_k[i] = K();
			}


			for (int i = 0; i < M + 1; i++)
			{
				array_node[i] = nullptr;
			}
		}
		//BTreeNode<K, M>* parent;  //记录一下父亲节点
		int cur_sz=0;   //记录当前key的数量
		K array_k[M];   //Key的数组
		BTreeNode<K, M>* array_node[M+1]; // 存储子节点的数组

	};

	template<class K, size_t  M>
	class BTree
	{
		//树中关键字的数量 要满足 小于M-1 大于less_key_number
		typedef BTreeNode<K, M> Node;
		Node* _root;
		int less_key_number = 0;
		//判断当前root是否满足B树规则
		static bool is_BTree(Node* _root)
		{
			if (_root == nullptr)
				return true;

			bool cur = true;
			for (int i = 0; i < _root->cur_sz - 1; i++)
			{
				//节点关键字序列是否是有序的
				if (_root->array_k[i] > _root->array_k[i + 1])
				{
					cur = false;
					break;
				}
				//如果不是叶子节点就要判断 是否满足 关键字数量==子节点数量-1  关键字大于左节点的最大值 关键字小于右节点的最小值
				if (_root->array_node[0] != nullptr && (_root->array_node[i + 1] == nullptr || _root->array_k[i] < (_root->array_node[i])->array_k[(_root->array_node[i])->cur_sz - 1]))
				{
					cur = false;
					break;
				}

				if (_root->array_node[0] != nullptr && (_root->array_node[i + 1] == nullptr || _root->array_k[i] > (_root->array_node[i + 1])->array_k[0]))
				{
					cur = false;
					break;
				}

			}

			for (int i = 0; i <= _root->cur_sz; i++)
				cur = cur && is_BTree(_root->array_node[i]);
			return cur;


		}

		void insert_into_node(const K& key, Node* key_node, Node* target_node)
		{
			//需要找到插入元素的位置并移动周围的元素——两个数组都需要移动

			//首先找到插入位置
			int pos = 0;
			for (; pos < target_node->cur_sz; pos++)
			{
				if (target_node->array_k[pos] > key)
					break;
			}


			//key数组插入
			int j = 0;
			for (j = target_node->cur_sz; j > pos; j--)
			{
				target_node->array_k[j] = target_node->array_k[j - 1];
			}
			target_node->array_k[j] = key;


			//node数组插入
			for (j = target_node->cur_sz + 1; j > pos + 1; j--)
			{
				target_node->array_node[j] = target_node->array_node[j - 1];
			}
			target_node->array_node[j] = key_node;
			//cur_sz记住修改
			target_node->cur_sz++;
		}

		void merge(Node* cur, Node* father)
		{
			//判断是否是叶子节点   如果不是叶子节点array_node节点也需要调整
			bool is_leaf_node = cur->array_node[0] == nullptr ? true : false;
			//我们要搞清楚一点就是删除前的Btree一定是符合B树要求的即——所有节点关键字的数量>=less_key_number
			//先看看叶节点删除后是否 富足
			if (cur->cur_sz >= less_key_number)
			{
				//富足
				return;
			}
			else
			{
				//不富足		
				bool flag = false;
				int bro_pos = 0;   //bro在array_node中的下标 
				int cur_pos = 0;     //cur在array_node中的下标
				for (int i = 0; i <= father->cur_sz; i++)
				{
					if ((father->array_node[i])->cur_sz > less_key_number)
					{
						flag = true;
						bro_pos = i;
					}

					if ((father->array_node[i])->cur_sz < less_key_number)
						cur_pos = i;
				}

				if (flag == true)
				{
					//自己不富足 ——先找兄弟借

					if (bro_pos < cur_pos)
					{
						//bro在cur 的左边

						//将元素移动

						int i = cur_pos;
						(father->array_node[i])->cur_sz++;
						while (i != bro_pos)
						{
							for (int j = (father->array_node[i])->cur_sz - 1; j > 0; j--)
							{
								(father->array_node[i])->array_k[j] = (father->array_node[i])->array_k[j - 1];
							}


							for (int j = (father->array_node[i])->cur_sz; j > 0; j--)
							{
								(father->array_node[i])->array_node[j] = (father->array_node[i])->array_node[j - 1];
							}
							(father->array_node[i])->array_k[0] = father->array_k[i - 1];
							father->array_k[i - 1] = (father->array_node[i - 1])->array_k[(father->array_node[i - 1])->cur_sz - 1];
							(father->array_node[i])->array_node[0] = (father->array_node[i - 1])->array_node[(father->array_node[i - 1])->cur_sz];
							i--;
						}
						(father->array_node[i])->cur_sz--;

					}
					else
					{
						//bro在cur的右边
						int i = cur_pos;
						(father->array_node[i])->cur_sz++;
						while (i != bro_pos)
						{
							(father->array_node[i])->array_k[(father->array_node[i])->cur_sz - 1] = father->array_k[i];
							(father->array_node[i])->array_node[(father->array_node[i])->cur_sz] = (father->array_node[i + 1])->array_node[0];
							father->array_k[i] = (father->array_node[i + 1])->array_k[0];
							i++;
							int j = 0;
							for (j = 0; j < (father->array_node[i])->cur_sz - 1; j++)
							{
								(father->array_node[i])->array_k[j] = (father->array_node[i])->array_k[j + 1];
								(father->array_node[i])->array_node[j] = (father->array_node[i])->array_node[j + 1];
							}
							(father->array_node[i])->array_node[j] = (father->array_node[i])->array_node[j + 1];

						}
						(father->array_node[i])->cur_sz--;
					}
				}
				else
				{
					//兄弟不富足找父亲借 
					//注意这时候所有父节点的所有子节点（除去要删除的那个节点,该节点的关键字数量是less_key_number-1）的关键字的数量全部都是less_key_number 
					//实际上就是插入的逆过程 less_key_number-1(要删除的那个子节点) + 1（父节点的一个关键字） +  less_key_number(任意一个与要删除的子节点挨着的子节点）= 正好是M-1（正好是一个全新符合要求的节点！！！！！）


					//我们始终与右边的字点融合 ——但是最右边的那个字节点需要单独讨论



					if (cur_pos == father->cur_sz)
					{
						//如果删除的是最右边的那个节点，但是我们始终保留左边的节点、
						(father->array_node[cur_pos - 1])->cur_sz = M - 1;
						
						int i = (father->array_node[cur_pos - 1])->cur_sz;
						(father->array_node[cur_pos - 1])->array_k[i++] = father->array_k[cur_pos - 1];
				
						int j = 0;
						for (j = 0; j < (father->array_node[cur_pos])->cur_sz; j++)
						{
							(father->array_node[cur_pos - 1])->array_k[i] = (father->array_node[cur_pos])->array_k[j];
							(father->array_node[cur_pos - 1])->array_node[i] = (father->array_node[cur_pos])->array_node[j];
							i++;
						}
						(father->array_node[cur_pos - 1])->array_node[i] = (father->array_node[cur_pos])->array_node[j];
						
						Node* tmp = father->array_node[cur_pos];
						father->array_node[cur_pos] = nullptr;
						delete tmp;
						
						if (father == _root && father->cur_sz == 1)   //如果跟节点减到0，直接delete
						{
							Node* tmp = _root;
							_root = father->array_node[cur_pos - 1];
							delete tmp;
						}
						else
						{
							//father数组不需要调整
						}
					}
					else
					{
						(father->array_node[cur_pos])->cur_sz = M - 1;
						//如果删除的节点不是最右边的节点，删除节点与右边相邻的节点融合
						int i = less_key_number - 1;
						(father->array_node[cur_pos])->array_k[i++] = father->array_k[cur_pos];
						//合并数组   ——不管是array_k还是array_node都需要合并
						int j = 0;
						for (j = 0; j < (father->array_node[cur_pos + 1])->cur_sz; j++)
						{
							(father->array_node[cur_pos])->array_k[i] = (father->array_node[cur_pos + 1])->array_k[j];
							(father->array_node[cur_pos])->array_node[i] = (father->array_node[cur_pos + 1])->array_node[j];
							i++;
						}
						(father->array_node[cur_pos])->array_node[i] = (father->array_node[cur_pos + 1])->array_node[j];
						

						Node* tmp = father->array_node[cur_pos + 1];
						father->array_node[cur_pos + 1] = nullptr;
						delete tmp;
						
						if (father == _root && father->cur_sz == 1)   //如果跟节点减到0，直接delete
						{
							//带完善............
							Node* tmp = _root;
							_root = father->array_node[cur_pos];
							delete tmp;
						}
						else
						{
							//调整father的array_key数组
							for (int j = cur_pos; j + 1 < father->cur_sz; j++)
								father->array_k[j] = father->array_k[j + 1];
							//调整father的array_node数组
							for (int j = cur_pos + 1; j + 1 <= father->cur_sz; j++)
								father->array_node[j] = father->array_node[j + 1];
						}


					}

					father->cur_sz--;

				}
			}

		}
	public:
		BTree()
			:_root(nullptr)
		{
			if (M < 2)
				throw "M必须设置成大于1的";

			//计算出每一个节点的最少的关键字数目
			if (M % 2 == 0)
			{
				less_key_number = M / 2-1;
			}
			else
			{
				less_key_number = M / 2 ;
			}
		}


		int find(const K& x,std::vector<Node*>& trace)
		{
			//记住这个find的前提条件是 —— 该root已经是一个BTree结构的树
			Node* cur = _root;
			while (cur)
			{
				trace.push_back(cur);
				int flag = 0;
				int i = 0;
				for (i = 0; i < cur->cur_sz; i++)
				{
					if (x < cur->array_k[i])
					{
						//直接找对应的字节点去查找
						flag = 1;
						cur = cur->array_node[i];
						break;
					}
					else if (x > cur->array_k[i])
					{
						//继续向下查找
						continue;
					}
					else {
						//找到直接返回下标
						return i;
					}
				}

				//进入最右边的那个子节点进行查找
				if(cur!=nullptr && x> cur->array_k[i-1] && flag==0)
				cur = cur->array_node[i];
			}
			return -1;
		}


		


		//插入的逻辑
		bool insert(const K& x)
		{
			//头插需要单独讨论
			if (_root == nullptr)
			{
				_root = new Node();

				_root->array_k[0] = x;
				_root->cur_sz++;
				//_root->parent = nullptr;
				return true;
			}
			//首先先找到节点
			std::vector<Node*> trace;  // 用来记录B树节点的路径
			int ret = find(x, trace);


			//不插入重复节点
			if (ret != -1)
				return false;


			//向找到的节点中插入数值
			insert_into_node(x, nullptr,trace[trace.size() - 1]);

			//向上调整B树
			Node* cur = trace[trace.size() - 1];
			trace.pop_back();
			while (cur->cur_sz==M)
			{
				if (trace.size() != 0)
				{
					Node* parent = trace[trace.size() - 1];
					//如果不满足条件则需要调整
					int mid = cur->array_k[M / 2];
					Node* newnode = new Node();
					int j = 0;
					//初始化newnode的array_k数组
					for (int i = less_key_number+1; i < M; i++)
					{
						newnode->array_k[j++] = cur->array_k[i];
					}
					
					//初始化newnode的array_node数组
					j = 0;
					for (int i = less_key_number+1; i < M+1; i++)
					{
						newnode->array_node[j++] = cur->array_node[i];
					}
					newnode->cur_sz = M - M / 2 - 1;
					cur->cur_sz = M / 2;
					insert_into_node(mid, newnode, parent);
					cur = parent;
					trace.pop_back();
					//print();
				}
				else
				{

					//如果是根节点需要分裂，则需要单独讨论
					int mid = cur->array_k[M / 2];
					Node* newnode = new Node();
					int j = 0;
					for (int i = M/2 + 1; i < M; i++)
					{
						newnode->array_k[j++] = cur->array_k[i];
					}
					newnode->cur_sz = M-M/2-1;
					cur->cur_sz = M / 2;

					//newnode的array_node需要初始化
					j = 0;
					for (int i = M / 2 + 1; i < M+1; i++)
					{
						newnode->array_node[j++] = cur->array_node[i];
					}

					//直接插入——root
					_root = new Node();
					_root->array_k[0] = mid;
					_root->array_node[0] = cur;
					_root->array_node[1] = newnode;
					_root->cur_sz = 1;
					cur = _root;
					


					//print();
				}

			}
		}


		

		//不管删除哪个节点最终都是转换成删除叶子节点
		//删除成功 返回true 反之 返回false
		bool erase(const K& key)
		{
			//首先得找到要删除的节点
			std::vector<Node*> trace;

			int pos=find(key, trace);

			if (pos == -1)
				return false; //没找到直接返回


			Node* cur = trace[trace.size() - 1];
			//trace.pop_back();
			
			//判断是否是叶子节点  不是叶子节点要转换成删除叶子节点

			if (cur->array_node[0] != nullptr)
			{
				//如果cur是叶子节点，那么最左边的子节点一定是空的！！！！！！！！！！

				//我们这里使用左子树的最大值，如果是中间节点关键字两边的子节点一定是非空的！！！！！！！！！
				Node* find_cur = cur->array_node[pos];
				while (find_cur->array_node[find_cur->cur_sz] != nullptr)
				{

					trace.push_back(find_cur);
					find_cur = find_cur->array_node[find_cur->cur_sz];
				}

				//交换节点的key值
				std::swap(cur->array_k[pos], find_cur->array_k[find_cur->cur_sz - 1]);
				cur = find_cur;
				pos = find_cur->cur_sz - 1;
			}
			else
				trace.pop_back();

			//到这里 cur里面是要处理的节点 pos是要处理的Key的下标 trace是B树到cur节点的路径


			//先把叶子节点上的删除了——为什么只调整array_k数组？因为删除操作只在叶子节点，后面向上遍历是删除叶子节点之后的连锁效应
			for (int i = pos; i < cur->cur_sz - 1; i++)
				cur->array_k[i] = cur->array_k[i + 1];
			cur->cur_sz--;

			Node* parent = nullptr;
			while (cur->cur_sz < less_key_number)
			{
				if (trace.size())
				{
					parent = trace[trace.size() - 1];
					
				}

				if (trace.size() == 0)
				{

					//捏马，根节点的删除还要单独写，真操蛋啊
					//根节点的关键字数量最小可以是1 ，所以只要判断一下根节点是否为0！！！！！

					if (cur->cur_sz == 0)
						_root = cur->array_node[0];
					return true;
				}
				else
				{
					merge(cur, parent);
					trace.pop_back();
				}
				cur = parent;
			}
			return true;
		}



		bool is_Btree()
		{
			return is_BTree(_root);
		}


		//打印B树的层序结构
		//并判断是否满足B树的规则
		bool print()
		{
			std::cout << "---------------------------------------------------------------" << std::endl;
			std::queue<Node*> q;

			q.push(_root);
			int cur_sz = 1;
			int next_sz = 0;


			while (!q.empty())
			{
				if (cur_sz != 0)
				{
					Node* top = q.front();
					for (int i = 0; i <= top->cur_sz; i++)
					{
						if (top->array_node[i] != nullptr)
						{
							next_sz++;
							q.push(top->array_node[i]);
						}
					}
					std::cout << "    |";
					for (int i = 0; i < top->cur_sz; i++)
					{
						std::cout << top->array_k[i] << " ";
					}
					std::cout << "|    ";

					q.pop();
					cur_sz--;

				}
				else
				{
					std::cout << std::endl;
					cur_sz = next_sz;
					next_sz = 0;   //没有清零出现显示bug
				}
			}
			std::cout<<std::endl<<std::endl;
			bool ret = true;
			ret = is_BTree(_root);
			if (is_BTree(_root) == false)
				std::cout  << "          不是BTree               " << std::endl;
			else
				std::cout  << "            是BTree               " << std::endl;
			std::cout << std::endl ;
			return ret;
		}
	};
}