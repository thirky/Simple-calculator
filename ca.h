#ifndef _CA_H_
#define _CA_H_


/*
*
*		��������
*
*/


class CAStack
{
public:
	typedef int ElemType;


protected:
	struct StackNode {
		ElemType data;
		struct StackNode* next;
	};


	StackNode* head;
	int length;
public:

	CAStack();//��ʼ��ջ

	~CAStack();//����ջ

	void Traverse();

	bool clear();//���ջ

	int Length();//���ջ����

	bool push(ElemType& e);//��ջ

	bool pop(ElemType& e);//��ջ

	ElemType getTop();



};


#endif
