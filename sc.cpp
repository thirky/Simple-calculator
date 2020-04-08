#include"sc.h"
#include<iostream>



LinkStack::LinkStack()
{
	head = new StackNode;
	head->data = 0;
	head->next = nullptr;
	length = 0;
}
LinkStack::~LinkStack()
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
bool LinkStack::clear()
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
bool LinkStack::isEmpty()
{
	if (length == 0)
	{
		return true;
	}
	return false;
}
int LinkStack::Length()
{
	return length;
}
bool LinkStack::push(ElemType& e)
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

bool LinkStack::pop(ElemType& e)
{
	if (isEmpty())
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

void LinkStack::Traverse()
{
	StackNode* p = head;
	while (p->next != nullptr)
	{
		p = p->next;
		std::cout << p->data << std::endl;
	}
}
LinkStack::ElemType LinkStack::getTop()
{
	if (length!=0)
	{
		StackNode* p = head->next;
		return p->data;
	}
	return 0;
}




