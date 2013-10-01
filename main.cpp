#include <windows.h>
#include <iostream>
#include <conio.h>
#include "myStack.h"
#include "myQueue.h"
#include "student.h"
using namespace std ;

template<class T>
void Data_input(stack<T> &S,queue<T> &Q,student &stu,int num=0);


int Start()
{
	int num=0;
	cout<< "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	cout<<"		Enter the number of students of you want to enter : ";
						// if user will try to enter more data then the mystack or queue will be resized original + 1/3 of orinal size;
	cin>> num; 
	return num;
}

int menu()
{
	system("cls");
	int option=0;
	cout<< "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	cout<<"		Enter your choice to perform operation:\n";
			//stack operations;;
	cout<<" 1> To Push data in Stack \n";
	cout<<" 2> To POP data from Stack\n";
			//Queue Operations;;
	cout<<" 3> To Push data in Queue using Enque \n";
	cout<<" 4> To Push the data in Queue via Enhanced operation\n";
	cout<<" 5> To Pop data from QUeue using simple operation\n";
	cout<<" 6> To Pop data from Queue using Enhanced Operation\n";
			//multipurpose
	cout<<" 7> To Enter data in both [Stack and Queue]....(simple operations)\n";
	cout<<" 8> To Enter data in both [Stack and Queue]....(Enhanced operations)\n";
	cout<<" 9> To pop data in both [Stack and Queue]....(simple operations)\n";
	cout<<" 10> To pop data in both [Stack and Queue]....(Enhaced operations)\n";
	
	cout<<" 11> To display the Stack and Queue\n";
	cout<<" 12> Exit\n"; 
	cin>>option;
	return option;
}

int main()
{
	/*HANDLE hOut;
	COORD NewSBSize;
	SMALL_RECT Area = {0, 0, 0, 0};

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	NewSBSize = GetLargestConsoleWindowSize(hOut);

	SetConsoleScreenBufferSize(hOut, NewSBSize);

	Area.Right = NewSBSize.X - 1;
	Area.Bottom = NewSBSize.Y - 1;

	SetConsoleWindowInfo(hOut, TRUE,  &Area);*/



	int num = Start();
	bool E_chk = false;//

	student S1;
	stack<student> S_abr(num);
	queue<student> Q_abr(num);
	
	for(int i=0; i<num; i++)
	{
		cout<<"enter the data for student "<<i+1<<" : ";
		S1.get_data();
		Q_abr.enque(S1);
		S_abr.push(S1);
	}

	int option = menu();

	while(1){
		//Can also be implmented as a function
	if (option == 1)
	{
		S1.get_data();
		S_abr.push(S1);
		//Data_input(S_abr,Q_abr,S1,num);
	}
	else if(option == 2)
	{
		//S1.get_data();
		E_chk = S_abr.pop(S1);
		if (!E_chk)
		{
			cout<<" Now the Stack is Empty\n";
			system("pause");
		}
		else
		{
			cout<<" The Student popped from stack is: ";S1.Student_Display();
			system("pause");
		}
	}
	else if(option == 3)
	{
		S1.get_data();
		Q_abr.enque(S1);
	}
	else if(option == 4)
	{
		S1.get_data();
		Q_abr.e_enque(S1);
	}
	else if(option == 5)
	{
		E_chk = Q_abr.deque(S1);
		if (!E_chk)
		{
			//cout<<" Now the Queue is Empty\n";
			system("pause");
		}
		else
		{
			cout<<" The Student popped from Queue is: ";S1.Student_Display();
			system("pause");
		}
	}
	else if(option == 6)
	{
		E_chk = Q_abr.e_deque(S1);
		if (!E_chk)
		{
			cout<<"Queue is now empty\n";
			system("pause");
		}
		else
		{
			cout<<" The Student popped from Queue is: ";S1.Student_Display();
			system("pause");
		}
	}
	else if(option == 7)
	{
		S1.get_data();
		S_abr.push(S1);
		Q_abr.enque(S1);
	}
	else if(option == 8)
	{
		S1.get_data();
		S_abr.push(S1);
		Q_abr.e_enque(S1);	
	}
	else if(option == 9)
	{
		E_chk = S_abr.pop(S1);
		if (!E_chk)
		{
			cout<<" Now the Stack is Empty\n";
			system("pause");
		}
		else
		{
			cout<<" The Student popped from Stack is: ";S1.Student_Display();
			system("pause");

		}
		E_chk = Q_abr.deque(S1);
		if (!E_chk)
		{
			cout<<" Now the Queue is Empty\n";
			system("pause");
		}
		else
		{
			cout<<" The Student popped from Queue is: ";S1.Student_Display();
			system("pause");

		}
	}
	else if(option == 10)
	{
		E_chk = S_abr.pop(S1);
		if (!E_chk)
		{
			cout<<" Now the Stack is Empty\n";
			system("pause");
		}
		else
		{
			cout<<" The Student popped from Stack is: ";S1.Student_Display();
			system("pause");		
		}
		E_chk = Q_abr.e_deque(S1);
		if (!E_chk)
		{
			cout<<" Now the Queue is Empty\n";
			system("pause");
		}
		else
		{
			cout<<" The Student popped from Queue is: ";S1.Student_Display();
			system("pause");
	
		}	
	}
	else if(option == 11)
	{
		system("cls");
		cout<<"The members of Stack Are : \n";
		S_abr.display();
		cout<<"\n\nThe members of Queue Are : \n";
		Q_abr.Qdisplay();
		system("pause");
	}
	else if(option == 12)
	{
		cout<<"\nThe Program has been terminated.....";
		return 0;
	}
	system("cls");
	option = menu();
	}
	
}

template<class T>
void Data_input(stack<T> &S,queue<T> &Q,student &stu,int num)
{
	for(int i=0; i<num; i++)
	{
		cout<<"Enter the data for student "<<i+1<<" : ";
		stu.get_data();
		Q.enque(stu);
		S.push(stu);
	}

}


//int main()
//{
//	// stack chk  working oka
//
//	int num = Start();
//	student S1;
//	stack<student> S_abr(num);
//	for(int i=0; i<num; i++)
//	{
//		cout<<"enter the data for student "<<i+1<<" : ";
//		S1.get_data();
//		S_abr.push(S1);
//	}
//	S_abr.display();
//	cout<<"-----------------------"<< endl ;
//	S1.get_data();
//	S_abr.push(S1) ;
//	cout<<"\n\n\n\n";
//	S_abr.display();
//	S_abr.pop(S1) ;
//	S_abr.pop(S1) ;
//	
//	cout<<"S"<<S_abr.size<<"     L"<<S_abr.len;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	//queue chk working oka
//
//	int num = Start();
//	bool chk=0;
//	student S1;
//	queue<student> Q_abr(num);
//	for(int i=0; i<num; i++)
//	{
//		cout<<"enter the data for student "<<i+1<<" : ";
//		S1.get_data();
//		Q_abr.enque(S1);
//	}
//	Q_abr.Qdisplay();
//	cout<<"-----------------------"<< endl ;
//	S1.get_data();
//	Q_abr.e_enque(S1) ;
//	cout<<"\n\n\n\n";
//	Q_abr.e_deque(S1);
//	Q_abr.deque(S1);
//	Q_abr.Qdisplay();
//	cout<<Q_abr.lenght<<"l       S"<<Q_abr.size<<endl;
//	system("pause");
//	return 0;
//}
//
