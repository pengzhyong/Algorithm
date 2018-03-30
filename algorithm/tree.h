#pragma once
#include <iostream>
#include <stack>
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
	~BaseTree();
	void insertEle(TNode<T>* node, TNode<T>* ele);
	void preOrder();
	void inOrder();
	void postOrder();

	void preOrderUseStack();
	void inOrderUseStack();
	void postOrderUseStack();

private:
	TNode<T>* pRoot;
	void preOrderPara(TNode<T>* begNode);//非静态成员不能作为默认实参，不能把pRoot作为默认实参传给preOrder。参数在递归调用时用到
	void inOrderPara(TNode<T>* begNode);
	void postOrderPara(TNode<T>* begNode);
};

template <typename T>
BaseTree<T>::BaseTree(T input[], int sz)
{
	if (sz <= 0 || input == nullptr)
	{
		pRoot = nullptr;
		return;
	}
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

template <typename T>
BaseTree<T>::~BaseTree()
{

}

template <typename T>
void BaseTree<T>::preOrder()
{
	preOrderPara(pRoot);
}

template <typename T>
void BaseTree<T>::inOrder()
{
	inOrderPara(pRoot);
}

template <typename T>
void BaseTree<T>::postOrder()
{
	postOrderPara(pRoot);
}

template <typename T>
void BaseTree<T>::preOrderPara(TNode<T>* begNode)
{
	if (begNode == nullptr)
		return;
	std::cout << begNode->value << " ";
	if (begNode->pLeft != nullptr)
		preOrderPara(begNode->pLeft);
	if (begNode->pRight != nullptr)
		preOrderPara(begNode->pRight);
}

template <typename T>
void BaseTree<T>::inOrderPara(TNode<T>* begNode)
{
	if (begNode == nullptr)
		return;
	if (begNode->pLeft != nullptr)
		inOrderPara(begNode->pLeft);
	std::cout << begNode->value << " ";
	if (begNode->pRight != nullptr)
		inOrderPara(begNode->pRight);
}

template <typename T>
void BaseTree<T>::postOrderPara(TNode<T>* begNode)
{
	if (begNode == nullptr)
		return;
	if (begNode->pLeft != nullptr)
		postOrderPara(begNode->pLeft);
	if (begNode->pRight != nullptr)
		postOrderPara(begNode->pRight);
	std::cout << begNode->value << " ";
}

//====方法1，类似广度优先搜索
template <typename T>
void BaseTree<T>::preOrderUseStack()
{
	stack<TNode<T>*> nodeStack;
	nodeStack.push(pRoot);
	while (!nodeStack.empty())
	{
		TNode<T>* left = nodeStack.top()->pLeft;
		TNode<T>* right = nodeStack.top()->pRight;
		std::cout << nodeStack.top()->value << " ";
		nodeStack.pop();
		if (right != nullptr)
			nodeStack.push(right);
		if (left != nullptr)
			nodeStack.push(left);
	}
}

//====方法2，类似深度优先搜索
//template <typename T>
//void BaseTree<T>::preOrderUseStack()
//{
//	stack<TNode<T>*> nodeStack;
//	TNode<T>* pCur = pRoot;
//	while (true)
//	{
//		while (pCur != nullptr)
//		{
//			std::cout << pCur->value << " ";
//			nodeStack.push(pCur);
//			pCur = pCur->pLeft;
//		}
//		pCur = nodeStack.top()->pRight;
//		nodeStack.pop();
//		if (pCur != nullptr)
//		{
//			nodeStack.push(pCur);
//			std::cout << pCur->value << " ";
//			pCur = pCur->pLeft;
//		}
//		if (nodeStack.empty())
//			break;
//	}
//}

template <typename T>
void BaseTree<T>::inOrderUseStack()
{
	stack<TNode<T>*> nodeStack;
	TNode<T>* pCur = pRoot->pLeft;
	nodeStack.push(pRoot);
	while (!nodeStack.empty())
	{
		while (pCur != nullptr)
		{
			nodeStack.push(pCur);
			pCur = pCur->pLeft;
		}
		pCur = nodeStack.top();
		std::cout << pCur->value << " ";
		nodeStack.pop();//已经访问过的节点一定要弹出，以免形成死循环
		pCur = pCur->pRight;
		if (pCur != nullptr)
		{
			nodeStack.push(pCur);
			pCur = pCur->pLeft;
		}
	}
}

template <typename T>
void BaseTree<T>::postOrderUseStack()
{
	stack<TNode<T>*> nodeStack;
	TNode<T>* pCur = pRoot->pLeft;
	TNode<T>* pPre = nullptr;

	nodeStack.push(pRoot);
	while (!nodeStack.empty())
	{
		pCur = nodeStack.top();
		if ((pCur->pLeft == nullptr && pCur->pRight == nullptr) || 
			(pPre != nullptr && (pPre == pCur->pLeft || pPre == pCur->pRight)))
		{
			std::cout << pCur->value << " ";
			pPre = pCur;
			nodeStack.pop();
		}
		else
		{
			if (pCur->pRight != nullptr)
				nodeStack.push(pCur->pRight);
			if (pCur->pLeft != nullptr)
				nodeStack.push(pCur->pLeft);
		}
	}
}
