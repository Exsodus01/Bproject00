#include "BinaryTree.h"
#include <iostream>

#include <sstream>

#include <vector>

#include <cmath>
BinaryTree::BinaryTree()
	:Tree(nullptr)
{
	std::cout << "Tree ����" << std::endl;

}

BinaryTree::~BinaryTree()
{
	std::cout << "Tree ����" << std::endl;
}

BinaryNode* BinaryTree::CreateNode(int NewData, std::string NewStr)
{
	BinaryNode* Tmp = new BinaryNode;
	Tmp->SetData(NewData);
	Tmp->SetStr(NewStr);


	return Tmp;
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
	std::cout << Root->GetStr() << std::endl;


	PreorderPrint(Root->GetLeft());


	PreorderPrint(Root->GetRight());



}

void BinaryTree::InorderPrint(BinaryNode* Root)
{
	if (Root == nullptr)
		return;




	PreorderPrint(Root->GetLeft());

	std::cout << Root->GetData() << std::endl;
	std::cout << Root->GetStr() << std::endl;

	PreorderPrint(Root->GetRight());

}

void BinaryTree::PostorderPrint(BinaryNode* Root)
{
	if (Root == nullptr)
		return;




	PreorderPrint(Root->GetLeft());




	PreorderPrint(Root->GetRight());


	//std::cout << Root->GetData() << std::endl;
	std::cout << Root->GetStr() << std::endl;


}

void BinaryTree::CreateTree(std::string NewStr,int NewDepth)
{
	//�̸� ���� ���ؼ� ��ȭ ���� Ʈ�� �غ��ϱ�
	int NewLenth = NewStr.length();


	BinaryNode* Tmp = new BinaryNode[NewLenth];
	if (NewLenth == pow(2, NewDepth) - 1) {
		std::cout << "��ȭ ���� Ʈ���� �����˴ϴ�." << std::endl;
	}
	else if(NewLenth < pow(2, NewDepth) - 1)
		std::cout << "���� ���� Ʈ���� �����˴ϴ�." << std::endl;
	else {
		std::cout << "Depth �ʰ�. Ʈ���� ���� ���� �ʽ��ϴ�" << std::endl;
		return;
	}

	std::istringstream iss(NewStr);
	char ch;
	std::vector<std::string> TmpVec;


	


	//���Ҵ� ������ ���� �̸� ���� Ȯ��
	TmpVec.reserve(NewLenth);


	//�Ľ̵� char�� string ���Ϳ� ����
	while (iss >> ch) {
		
		TmpVec.push_back(std::string(1, ch));

	}
	//��� �ʱ�ȭ
	for (int n = 0; n < NewLenth; n++) {
		Tmp[n].SetStr(TmpVec.at(n));
	}

	Tree = Tmp[0].Getme();
	
	PreorderInsert(Tree, Tmp, NewDepth);
}

void BinaryTree::PreorderInsert(BinaryNode* Root,BinaryNode* Insert,int NewDepth,int Depth,int Cnt)
{
	//���� ������ Ʈ���� ����� ���� ����
	
	if (Depth > NewDepth-1) {
		return;
	}

	if (Root->GetLeft() == nullptr) {
		Root->SetLeft(Insert[Cnt++].Getme());
		PreorderInsert(Root->GetLeft(), Insert, NewDepth, ++Depth, Cnt);
	}
	

	if (Root->GetRight() == nullptr) {
		Root->SetRight(Insert[Cnt++].Getme());
		PreorderInsert(Root->GetRight(), Insert, NewDepth, ++Depth, Cnt);
	}


}
