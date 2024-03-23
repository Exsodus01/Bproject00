#pragma once
#include "BinaryNode.h"
#include <deque>

class BinaryTree : public BinaryNode
{


public:
	int Depth;
	BinaryNode* Tree;
	std::deque<std::string>* deque;

	BinaryTree();
	~BinaryTree();


	
	void DeleteNode(BinaryNode* Del);
	void DeleteTree(BinaryNode* DelTree);

	void PreorderPrint(BinaryNode* Root);
	void InorderPrint(BinaryNode* Root);
	void PostorderPrint(BinaryNode* Root);



	void CreateRoot(int Dep);
	void CreateTree(BinaryNode*& Root,int Dep);
	void CharArray(std::string NewStr, int NewDepth);

	void PreOrderInsert(BinaryNode* Root,std::deque<std::string>* Deq);

};

