#pragma once

#include <string>

class BinaryNode
{
	int Data;
	std::string Str;



public:
	BinaryNode* Left;
	BinaryNode* Right;

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
	

	


};

