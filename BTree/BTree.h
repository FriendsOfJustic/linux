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
		//����±���ͬ  array_node[i] �� array_k[i] ����ڵ�
		BTreeNode()
		{
			//�������ʼ��һ��
			for (int i = 0; i < M; i++)
			{
				array_k[i] = K();
			}


			for (int i = 0; i < M + 1; i++)
			{
				array_node[i] = nullptr;
			}
		}
		//BTreeNode<K, M>* parent;  //��¼һ�¸��׽ڵ�
		int cur_sz=0;   //��¼��ǰkey������
		K array_k[M];   //Key������
		BTreeNode<K, M>* array_node[M+1]; // �洢�ӽڵ������

	};

	template<class K, size_t  M>
	class BTree
	{
		//���йؼ��ֵ����� Ҫ���� С��M-1 ����less_key_number
		typedef BTreeNode<K, M> Node;
		Node* _root;
		int less_key_number = 0;
		//�жϵ�ǰroot�Ƿ�����B������
		static bool is_BTree(Node* _root)
		{
			if (_root == nullptr)
				return true;

			bool cur = true;
			for (int i = 0; i < _root->cur_sz - 1; i++)
			{
				//�ڵ�ؼ��������Ƿ��������
				if (_root->array_k[i] > _root->array_k[i + 1])
				{
					cur = false;
					break;
				}
				//�������Ҷ�ӽڵ��Ҫ�ж� �Ƿ����� �ؼ�������==�ӽڵ�����-1  �ؼ��ִ�����ڵ�����ֵ �ؼ���С���ҽڵ����Сֵ
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
			//��Ҫ�ҵ�����Ԫ�ص�λ�ò��ƶ���Χ��Ԫ�ء����������鶼��Ҫ�ƶ�

			//�����ҵ�����λ��
			int pos = 0;
			for (; pos < target_node->cur_sz; pos++)
			{
				if (target_node->array_k[pos] > key)
					break;
			}


			//key�������
			int j = 0;
			for (j = target_node->cur_sz; j > pos; j--)
			{
				target_node->array_k[j] = target_node->array_k[j - 1];
			}
			target_node->array_k[j] = key;


			//node�������
			for (j = target_node->cur_sz + 1; j > pos + 1; j--)
			{
				target_node->array_node[j] = target_node->array_node[j - 1];
			}
			target_node->array_node[j] = key_node;
			//cur_sz��ס�޸�
			target_node->cur_sz++;
		}

		void merge(Node* cur, Node* father)
		{
			//�ж��Ƿ���Ҷ�ӽڵ�   �������Ҷ�ӽڵ�array_node�ڵ�Ҳ��Ҫ����
			bool is_leaf_node = cur->array_node[0] == nullptr ? true : false;
			//����Ҫ�����һ�����ɾ��ǰ��Btreeһ���Ƿ���B��Ҫ��ļ��������нڵ�ؼ��ֵ�����>=less_key_number
			//�ȿ���Ҷ�ڵ�ɾ�����Ƿ� ����
			if (cur->cur_sz >= less_key_number)
			{
				//����
				return;
			}
			else
			{
				//������		
				bool flag = false;
				int bro_pos = 0;   //bro��array_node�е��±� 
				int cur_pos = 0;     //cur��array_node�е��±�
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
					//�Լ������� ���������ֵܽ�

					if (bro_pos < cur_pos)
					{
						//bro��cur �����

						//��Ԫ���ƶ�

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
						//bro��cur���ұ�
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
					//�ֵܲ������Ҹ��׽� 
					//ע����ʱ�����и��ڵ�������ӽڵ㣨��ȥҪɾ�����Ǹ��ڵ�,�ýڵ�Ĺؼ���������less_key_number-1���Ĺؼ��ֵ�����ȫ������less_key_number 
					//ʵ���Ͼ��ǲ��������� less_key_number-1(Ҫɾ�����Ǹ��ӽڵ�) + 1�����ڵ��һ���ؼ��֣� +  less_key_number(����һ����Ҫɾ�����ӽڵ㰤�ŵ��ӽڵ㣩= ������M-1��������һ��ȫ�·���Ҫ��Ľڵ㣡����������


					//����ʼ�����ұߵ��ֵ��ں� �����������ұߵ��Ǹ��ֽڵ���Ҫ��������



					if (cur_pos == father->cur_sz)
					{
						//���ɾ���������ұߵ��Ǹ��ڵ㣬��������ʼ�ձ�����ߵĽڵ㡢
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
						
						if (father == _root && father->cur_sz == 1)   //������ڵ����0��ֱ��delete
						{
							Node* tmp = _root;
							_root = father->array_node[cur_pos - 1];
							delete tmp;
						}
						else
						{
							//father���鲻��Ҫ����
						}
					}
					else
					{
						(father->array_node[cur_pos])->cur_sz = M - 1;
						//���ɾ���Ľڵ㲻�����ұߵĽڵ㣬ɾ���ڵ����ұ����ڵĽڵ��ں�
						int i = less_key_number - 1;
						(father->array_node[cur_pos])->array_k[i++] = father->array_k[cur_pos];
						//�ϲ�����   ����������array_k����array_node����Ҫ�ϲ�
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
						
						if (father == _root && father->cur_sz == 1)   //������ڵ����0��ֱ��delete
						{
							//������............
							Node* tmp = _root;
							_root = father->array_node[cur_pos];
							delete tmp;
						}
						else
						{
							//����father��array_key����
							for (int j = cur_pos; j + 1 < father->cur_sz; j++)
								father->array_k[j] = father->array_k[j + 1];
							//����father��array_node����
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
				throw "M�������óɴ���1��";

			//�����ÿһ���ڵ�����ٵĹؼ�����Ŀ
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
			//��ס���find��ǰ�������� ���� ��root�Ѿ���һ��BTree�ṹ����
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
						//ֱ���Ҷ�Ӧ���ֽڵ�ȥ����
						flag = 1;
						cur = cur->array_node[i];
						break;
					}
					else if (x > cur->array_k[i])
					{
						//�������²���
						continue;
					}
					else {
						//�ҵ�ֱ�ӷ����±�
						return i;
					}
				}

				//�������ұߵ��Ǹ��ӽڵ���в���
				if(cur!=nullptr && x> cur->array_k[i-1] && flag==0)
				cur = cur->array_node[i];
			}
			return -1;
		}


		


		//������߼�
		bool insert(const K& x)
		{
			//ͷ����Ҫ��������
			if (_root == nullptr)
			{
				_root = new Node();

				_root->array_k[0] = x;
				_root->cur_sz++;
				//_root->parent = nullptr;
				return true;
			}
			//�������ҵ��ڵ�
			std::vector<Node*> trace;  // ������¼B���ڵ��·��
			int ret = find(x, trace);


			//�������ظ��ڵ�
			if (ret != -1)
				return false;


			//���ҵ��Ľڵ��в�����ֵ
			insert_into_node(x, nullptr,trace[trace.size() - 1]);

			//���ϵ���B��
			Node* cur = trace[trace.size() - 1];
			trace.pop_back();
			while (cur->cur_sz==M)
			{
				if (trace.size() != 0)
				{
					Node* parent = trace[trace.size() - 1];
					//�����������������Ҫ����
					int mid = cur->array_k[M / 2];
					Node* newnode = new Node();
					int j = 0;
					//��ʼ��newnode��array_k����
					for (int i = less_key_number+1; i < M; i++)
					{
						newnode->array_k[j++] = cur->array_k[i];
					}
					
					//��ʼ��newnode��array_node����
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

					//����Ǹ��ڵ���Ҫ���ѣ�����Ҫ��������
					int mid = cur->array_k[M / 2];
					Node* newnode = new Node();
					int j = 0;
					for (int i = M/2 + 1; i < M; i++)
					{
						newnode->array_k[j++] = cur->array_k[i];
					}
					newnode->cur_sz = M-M/2-1;
					cur->cur_sz = M / 2;

					//newnode��array_node��Ҫ��ʼ��
					j = 0;
					for (int i = M / 2 + 1; i < M+1; i++)
					{
						newnode->array_node[j++] = cur->array_node[i];
					}

					//ֱ�Ӳ��롪��root
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


		

		//����ɾ���ĸ��ڵ����ն���ת����ɾ��Ҷ�ӽڵ�
		//ɾ���ɹ� ����true ��֮ ����false
		bool erase(const K& key)
		{
			//���ȵ��ҵ�Ҫɾ���Ľڵ�
			std::vector<Node*> trace;

			int pos=find(key, trace);

			if (pos == -1)
				return false; //û�ҵ�ֱ�ӷ���


			Node* cur = trace[trace.size() - 1];
			//trace.pop_back();
			
			//�ж��Ƿ���Ҷ�ӽڵ�  ����Ҷ�ӽڵ�Ҫת����ɾ��Ҷ�ӽڵ�

			if (cur->array_node[0] != nullptr)
			{
				//���cur��Ҷ�ӽڵ㣬��ô����ߵ��ӽڵ�һ���ǿյģ�������������������

				//��������ʹ�������������ֵ��������м�ڵ�ؼ������ߵ��ӽڵ�һ���Ƿǿյģ�����������������
				Node* find_cur = cur->array_node[pos];
				while (find_cur->array_node[find_cur->cur_sz] != nullptr)
				{

					trace.push_back(find_cur);
					find_cur = find_cur->array_node[find_cur->cur_sz];
				}

				//�����ڵ��keyֵ
				std::swap(cur->array_k[pos], find_cur->array_k[find_cur->cur_sz - 1]);
				cur = find_cur;
				pos = find_cur->cur_sz - 1;
			}
			else
				trace.pop_back();

			//������ cur������Ҫ����Ľڵ� pos��Ҫ�����Key���±� trace��B����cur�ڵ��·��


			//�Ȱ�Ҷ�ӽڵ��ϵ�ɾ���ˡ���Ϊʲôֻ����array_k���飿��Ϊɾ������ֻ��Ҷ�ӽڵ㣬�������ϱ�����ɾ��Ҷ�ӽڵ�֮�������ЧӦ
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

					//�������ڵ��ɾ����Ҫ����д����ٵ���
					//���ڵ�Ĺؼ���������С������1 ������ֻҪ�ж�һ�¸��ڵ��Ƿ�Ϊ0����������

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


		//��ӡB���Ĳ���ṹ
		//���ж��Ƿ�����B���Ĺ���
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
					next_sz = 0;   //û�����������ʾbug
				}
			}
			std::cout<<std::endl<<std::endl;
			bool ret = true;
			ret = is_BTree(_root);
			if (is_BTree(_root) == false)
				std::cout  << "          ����BTree               " << std::endl;
			else
				std::cout  << "            ��BTree               " << std::endl;
			std::cout << std::endl ;
			return ret;
		}
	};
}