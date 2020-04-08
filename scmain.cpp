#include"sc.h"
#include"ca.h"
#include<iostream>
#include<string>

int main()
{

    LinkStack* p = new LinkStack;
	CAStack* s = new CAStack;
	std::cout << "请输入中缀表达式：";
    std::string str;
	std::cin >> str;
	int i = 0,a,b,c;
	char j;
	while (str[i] != '\0')
	{
		while (str[i]>='0'&&str[i]<='9')
		{
			int k;
			k = str[i] - 48;
			s->push(k);
			i++;
		}
		if (str[i] == '+' || str[i] == '-')
		{
			if (p->Length()==0)
			{
				p->push(str[i]);
			}
			else
			{
				do
				{
					p->pop(j);
					if (j == '(')
					{
						p->push(j);
					}
					else
					{
						s->pop(c);
						s->pop(b);
						if (j == '+')
						{
							a = b + c;
						}
						else if (j == '-')
						{
							a = b - c;
						}
						else if (j == '*')
						{
							a = b * c;
						}
						else if (j == '/')
						{
							a = b / c;
						}
						s->push(a);
					}
				} while (p->Length()!=0 && j != '(');

				p->push(str[i]);
			}
		}
		else if (str[i] == ')')
		{
			p->pop(j);
			while (j != '(')
			{
				s->pop(c);
				s->pop(b);
				if (j == '+')
				{
					a = b + c;
				}
				else if (j == '-')
				{
					a = b - c;
				}
				else if (j == '*')
				{
					a = b * c;
				}
				else if (j == '/')
				{
					a = b / c;
				}
				s->push(a);
				p->pop(j);
			}
		}
		else if (str[i] == '*' || str[i] == '/' || str[i] == '(')
		{
			p->push(str[i]);
		}

		else if (str[i] == '\0')
		{
			break;
		}

		else
		{
			printf("\n输入格式错误！\n");
			return 0;
		}
		i++;
	}
	while (p->Length()!=0)
	{
		p->pop(j);
		s->pop(c);
		s->pop(b);
		if (j == '+')
		{
			a = b + c;
		}
		else if (j == '-')
		{
			a = b - c;
		}
		else if (j == '*')
		{
			a = b * c;
		}
		else if (j == '/')
		{
			a = b / c;
		}
		s->push(a);
	}
	std::cout << s->getTop() << std::endl;
	return 0;
}