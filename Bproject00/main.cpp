#include <iostream>

#include "BinaryTree.h"


int main() {
	BinaryTree start;
	std::string str = "ABCDEF";
	start.CreateTree(start.Tree,3);
	start.CharArray(str,3);
	start.PreOrderInsert(start.Tree, start.deque);


	//start.PreorderPrint(start.Tree);
	//start.InorderPrint(start.Tree);
	start.PostorderPrint(start.Tree);
	return 0;
}