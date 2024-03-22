#include "BinaryNode.h"
#include <iostream>

BinaryNode::BinaryNode()
	:Data(0),Str(""),Left(nullptr),Right(nullptr)
{
	std::cout << "BNode 생성" << std::endl;

}
BinaryNode::~BinaryNode()
{
	std::cout << "BNode 삭제" << std::endl;
}

void BinaryNode::SetData(int NewData)
{
	this->Data = NewData;
}

void BinaryNode::SetStr(std::string NewStr)
{
	this->Str = NewStr;
}

void BinaryNode::SetLeft(BinaryNode* NewNode)
{
	this->Left = NewNode;
}

void BinaryNode::SetRight(BinaryNode* NewNode)
{
	this->Right = NewNode;
}

int BinaryNode::GetData()
{
	return this->Data;
}

std::string BinaryNode::GetStr()
{
	return this->Str;
}

BinaryNode* BinaryNode::GetLeft()
{
	return this->Left;
}

BinaryNode* BinaryNode::GetRight()
{
	return this->Right;
}

BinaryNode* BinaryNode::Getme()
{
	return this;
}

