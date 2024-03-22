#include <iostream>

#include "BinaryTree.h"


int main() {
	BinaryTree start;

	start.CreateTree("ABCDEFG",3);
	start.PreorderPrint(start.Tree);


	return 0;
}