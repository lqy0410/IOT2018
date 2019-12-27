#include"head.h"

int main()
{
	Stack  s;
	int option;
	int sign = 1;
	int i = 0;
	while (sign)
	{
		cout << "=======================请选择功能===========================" << endl;
		cout << " 1.创建一个空栈        2.入栈         3.出栈              4.输出栈顶元素 " << "\n";
		cout << " 5.遍历栈中元素        6.加法运算                      7.退出   " << "\n";


		cout << "请输入功能（1-7）" ;
		cin >> option;
		switch (option)
		{
		case 1:
			initStack(s);
			cout << "初始化成功"<<endl;
			break;
		case 2:
			elem e;
			cout << "请输入入栈元素    " ;
			cin >> e;
			Push(s, e);
			cout << "入栈成功" << endl;
			break;
		case 3:
			Pop(s);
			cout << "出栈成功" << endl;
			break;
		case 4:
			elem q;
			q = Get(s);
			cout << " " << q << endl;
			break;
		case 5:
			showStack(s);
			break;
		case 6:
			Stack s;
			char save[20];
			char m[20];
			initStack(s);
			getExp(save);
			houzui(save, s, m);
			iStack t;
			initStack_int(t);
			
			Evalu(m, t);
			

			break;

		case 7:
			sign = 0;
			break;
		}
	}
}