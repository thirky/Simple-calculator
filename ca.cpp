#include"ca.h"
#include<iostream>



CAStack::CAStack()
{
	head = new StackNode;
	head->data = 0;
	head->next = nullptr;
	length = 0;
}
CAStack::~CAStack()
{
	StackNode* p1 = head;
	while (p1->next != nullptr)
	{
		StackNode* p2 = p1->next;
		delete p1;
		p1 = nullptr;
		p1 = p2;
	}
	delete head;
	head = nullptr;
}
bool CAStack::clear()
{
	StackNode* p1 = head->next;
	if (p1 == nullptr)
	{
		return false;
	}
	while (p1->next != nullptr)
	{
		StackNode* p2 = p1->next;
		delete p1;
		p1 = p2;
	}
	delete p1;
	head->next = nullptr;
	length = 0;
	return true;
}

int CAStack::Length()
{
	return length;
}
bool CAStack::push(ElemType& e)
{
	StackNode* p1 = head->next;
	StackNode* p2 = new StackNode;
	if (p2 == NULL)
	{
		return false;
	}
	p2->data = e;
	head->next = p2;
	p2->next = p1;
	length++;
	return true;
}

bool CAStack::pop(ElemType& e)
{
	if (length==0)
	{
		std::cout << "操作失败：栈中元素为空" << std::endl;
		return false;
	}
	StackNode* p = head->next;
	e = p->data;
	head->next = p->next;
	delete p;
	p = nullptr;
	length--;
	return true;
}

void CAStack::Traverse()
{
	StackNode* p = head;
	while (p->next != nullptr)
	{
		p = p->next;
		std::cout << p->data << std::endl;
	}
}
CAStack::ElemType CAStack::getTop()
{
	if (length != 0)
	{
		StackNode* p = head->next;
		return p->data;
	}
	return 0;
}