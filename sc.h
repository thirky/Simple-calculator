
#ifndef _SC_H_
#define _SC_H_


/*
*
*		��ջ
*
*/


class LinkStack
{
public:
	typedef char ElemType;


protected:
	struct StackNode {
		ElemType data;
		struct StackNode* next;
	};


	StackNode* head;
	int length;
public:

	LinkStack();//��ʼ��ջ

	~LinkStack();//����ջ

	bool isEmpty();//�ж�ջ�Ƿ�Ϊ��

	void Traverse();

	bool clear();//���ջ

	int Length();//���ջ����

	bool push(ElemType& e);//��ջ

	bool pop(ElemType& e);//��ջ

	ElemType getTop();



};


#endif

