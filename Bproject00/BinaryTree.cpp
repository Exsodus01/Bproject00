#include "BinaryTree.h"
#include <iostream>

#include <sstream>

#include <deque>

#include <cmath>


BinaryTree::BinaryTree()
	:Tree(nullptr),Depth(0)
{
	std::cout << "Tree ����" << std::endl;

}

BinaryTree::~BinaryTree()
{
	std::cout << "Tree ����" << std::endl;
}



void BinaryTree::DeleteNode(BinaryNode* Del)
{
	delete Del;

}

void BinaryTree::DeleteTree(BinaryNode* DelTree)
{


	if (DelTree == nullptr)
		return;




	DeleteTree(DelTree->GetLeft());




	DeleteTree(DelTree->GetRight());


	delete DelTree;



}

void BinaryTree::PreorderPrint(BinaryNode* Root)
{
	if (Root == nullptr)
		return;

//	std::cout << Root->GetData() << std::endl;
	if(Root->GetStr()!="")
	std::cout << Root->GetStr() << std::endl;


	PreorderPrint(Root->GetLeft());


	PreorderPrint(Root->GetRight());



}

void BinaryTree::InorderPrint(BinaryNode* Root)
{
	if (Root == nullptr)
		return;




	InorderPrint(Root->GetLeft());

//	std::cout << Root->GetData() << std::endl;
	if (Root->GetStr() != "")
	std::cout << Root->GetStr() << std::endl;

	InorderPrint(Root->GetRight());

}

void BinaryTree::PostorderPrint(BinaryNode* Root)
{
	if (Root == nullptr)
		return;




	PostorderPrint(Root->GetLeft());




	PostorderPrint(Root->GetRight());


	//std::cout << Root->GetData() << std::endl;
	if (Root->GetStr() != "")
	std::cout << Root->GetStr() << std::endl;


}

void BinaryTree::CreateRoot(int Dep)
{
	this->Tree = new BinaryNode;
	this->Depth = Dep;

	std::cout << "Ʈ���� ��Ʈ�� �����Ǿ����ϴ�." << std::endl;
}

void BinaryTree::CreateTree(BinaryNode*& Root,int Dep)
{
	if (this->Tree == nullptr)
		CreateRoot(Dep);
	
	if (Dep == 0)
		return;


	if (Root == nullptr) {
		Root = new BinaryNode;
	}
	CreateTree(Root->Left,Dep-1);

	CreateTree(Root->Right, Dep - 1);




}

void BinaryTree::CharArray(std::string NewStr, int NewDepth)
{
	//�̸� ���� ���ؼ� ��ȭ ���� Ʈ�� �غ��ϱ�
	int NewLenth = NewStr.length();


	
	if (NewLenth == pow(2, NewDepth) - 1) {
		std::cout << "��ȭ ���� Ʈ���� �����˴ϴ�." << std::endl;
	}
	else if (NewLenth < pow(2, NewDepth) - 1)
		std::cout << "���� ���� Ʈ���� �����˴ϴ�." << std::endl;
	else {
		std::cout << "Depth �ʰ�. Ʈ���� ���� ���� �ʽ��ϴ�" << std::endl;
		return;
	}

	std::istringstream iss(NewStr);
	char ch;
	std::deque<std::string>* Deque=new std::deque<std::string>;

	//�Ľ̵� char�� string ���Ϳ� ����
	while (iss >> ch) {

		Deque->push_back(std::string(1, ch));

	}


	


	this->deque = Deque;

	
}

void BinaryTree::PreOrderInsert(BinaryNode* Root,std::deque<std::string>* Deq)
{
	if (Root == nullptr)
		return;

	if (Deq->empty())
		return;


	if (Root != nullptr) {
		std::string sTmp = Deq->front();
		Deq->pop_front();
		Root->SetStr(sTmp);
	}

	PreOrderInsert(Root->Left, Deq);

	PreOrderInsert(Root->Right, Deq);




}


