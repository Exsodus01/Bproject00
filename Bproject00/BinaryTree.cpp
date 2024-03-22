#include "BinaryTree.h"
#include <iostream>

#include <sstream>

#include <vector>

#include <cmath>
BinaryTree::BinaryTree()
	:Tree(nullptr)
{
	std::cout << "Tree 생성" << std::endl;

}

BinaryTree::~BinaryTree()
{
	std::cout << "Tree 삭제" << std::endl;
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
	//미리 길이 구해서 포화 이진 트리 준비하기
	int NewLenth = NewStr.length();


	BinaryNode* Tmp = new BinaryNode[NewLenth];
	if (NewLenth == pow(2, NewDepth) - 1) {
		std::cout << "포화 이진 트리가 생성됩니다." << std::endl;
	}
	else if(NewLenth < pow(2, NewDepth) - 1)
		std::cout << "완전 이진 트리가 생성됩니다." << std::endl;
	else {
		std::cout << "Depth 초과. 트리가 생성 되지 않습니다" << std::endl;
		return;
	}

	std::istringstream iss(NewStr);
	char ch;
	std::vector<std::string> TmpVec;


	


	//재할당 방지를 위해 미리 공간 확보
	TmpVec.reserve(NewLenth);


	//파싱된 char을 string 벡터에 저장
	while (iss >> ch) {
		
		TmpVec.push_back(std::string(1, ch));

	}
	//노드 초기화
	for (int n = 0; n < NewLenth; n++) {
		Tmp[n].SetStr(TmpVec.at(n));
	}

	Tree = Tmp[0].Getme();
	
	PreorderInsert(Tree, Tmp, NewDepth);
}

void BinaryTree::PreorderInsert(BinaryNode* Root,BinaryNode* Insert,int NewDepth,int Depth,int Cnt)
{
	//일정 깊이의 트리를 만들기 위한 조건
	
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
