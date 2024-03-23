#include <iostream>

#include "BinaryTree.h"


int main() {
	BinaryTree start;
	std::string str = "ABCDEFG";
	start.CreateTree(start.Tree,3);
	start.CharArray(str,3);
	start.PreOrderInsert(start.Tree, start.deque);


	
	start.PostorderPrint(start.Tree);
	return 0;
}