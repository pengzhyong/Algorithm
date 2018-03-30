#include <iostream>
#include "tree.h"
using namespace std;
int main()
{
	int nodes[10] = { 5,4,5,1,3,10,1,0,2,6 };
	BaseTree<int> searchTree(nodes, 8);
	searchTree.preOrder();
	cout << endl;
	searchTree.inOrder();
	cout << endl;
	searchTree.postOrder();
	cout << endl << endl;
	searchTree.preOrderUseStack();
	cout << endl;
	searchTree.inOrderUseStack();
	cout << endl;
	searchTree.postOrderUseStack();
	cout << endl;
	return 0;
}
