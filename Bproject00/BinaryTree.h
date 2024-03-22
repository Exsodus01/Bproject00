#pragma once
#include "BinaryNode.h"
class BinaryTree : public BinaryNode
{


public:
	BinaryNode* Tree;


	BinaryTree();
	~BinaryTree();


	BinaryNode* CreateNode(int NewData, std::string NewStr);
	void DeleteNode(BinaryNode* Del);
	void DeleteTree(BinaryNode* DelTree);

	void PreorderPrint(BinaryNode* Root);
	void InorderPrint(BinaryNode* Root);
	void PostorderPrint(BinaryNode* Root);


	
	void CreateTree(std::string NewStr, int NewDepth);
	void PreorderInsert(BinaryNode* Root,BinaryNode* Insert,int NewDepth,int Depth=0,int Cnt=1);


};

