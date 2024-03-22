#pragma once

#include <string>

class BinaryNode
{
	int Data;
	std::string Str;

	BinaryNode* Left;
	BinaryNode* Right;



public:

	BinaryNode();
	~BinaryNode();

	void SetData(int NewData);
	void SetStr(std::string NewStr);
	void SetLeft(BinaryNode* NewNode);
	void SetRight(BinaryNode* NewNode);


	int GetData();
	std::string GetStr();
	BinaryNode* GetLeft();
	BinaryNode* GetRight();
	BinaryNode* Getme();

	


};

