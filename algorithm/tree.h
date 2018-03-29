#pragma once
template <typename T>
struct TNode
{
	T value;
	TNode<T>* pLeft;
	TNode<T>* pRight;
	TNode<T>* pParent;
};

template <typename T> 
class BaseTree
{
public:
	BaseTree() = default;
	BaseTree(T input[], int sz);
private:
	TNode<T>* pRoot;
	void insertEle(TNode<T>* node, TNode<T>* ele);
};

template <typename T>
BaseTree<T>::BaseTree(T input[], int sz)
{
	if (sz <= 0 || input == nullptr)
		return;
	pRoot = new TNode<T>;
	pRoot->pLeft = nullptr;
	pRoot->pRight = nullptr;
	pRoot->pParent = nullptr;
	pRoot->value = input[0];
	if (sz <= 1)
		return;
	for (int i = 1; i < sz; ++i)
	{
		TNode<T>* node = new TNode<T>;
		node->pLeft = nullptr;
		node->pRight = nullptr;
		node->pParent = nullptr;
		node->value = input[i];
		insertEle(pRoot, node);
	}
}

template <typename T>
void BaseTree<T>::insertEle(TNode<T>* node, TNode<T>* ele)
{
	if (ele->value < node->value)
	{
		if (node->pLeft == nullptr)
		{
			node->pLeft = ele;
			return;
		}
		else
			insertEle(node->pLeft, ele);
		
	}
	else
	{
		if (node->pRight == nullptr)
		{
			node->pRight = ele;
			return;
		}
		else
			insertEle(node->pRight, ele);
	}
}
