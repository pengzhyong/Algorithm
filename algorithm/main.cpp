#include <iostream>
#include "tree.h"
using namespace std;
int main()
{
	double nodes[10] = { 5,4,5,1,3,10,1,0,2,6 };
	BaseTree<double> searchTree(nodes, 10);

	return 0;
}
