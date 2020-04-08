#ifndef _CA_H_
#define _CA_H_


/*
*
*		接收数字
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

	CAStack();//初始化栈

	~CAStack();//销毁栈

	void Traverse();

	bool clear();//清空栈

	int Length();//检测栈长度

	bool push(ElemType& e);//入栈

	bool pop(ElemType& e);//出栈

	ElemType getTop();



};


#endif
