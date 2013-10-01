#pragma once
#include <iostream>
#include "student.h"
#include "myStack.h"
#include <string>
using namespace std ;

template <typename T >

class queue
{
public:

	int lenght;				// no. of elements in the Queue
	int front, rear;
	int size;      // max Queue size
	T *Qobj ;


		//default ctor intializes --> 0
	queue(){
		Qobj =  nullptr;
		lenght = 0 ;
		size =  0 ;
	}
		//overloaded ctor 
	queue(int num)
	{
		//if (num <= 0) size = 10; else size = num;
		size = num; 
		Qobj = new T[size];
		lenght = 0;
		rear = -1;			// points to the last element
		front = 0;			// points to first element to be popoed/dequed

	}
		//overloaded ctor takes input of size and array
	queue(T arr[], int num)
	{
		Qobj =  new T[num] ;
		lenght = num ;
		size =  num ;
		for(int i=0; i<num; i++)
		{
			Qobj[i] = arr[i];
		}
	}

	void enque(T dat){

		if (size == lenght) // (front == rear) can also be used but with some exceptions
		{
			resize() ;
		}

		//rear++;
		rear = (rear + 1) % size; 
		Qobj[rear] = dat;  
		lenght++; 
}
	
	void resize(){

		/*T *temp = new T[2*lenght] ;
		size = 2 * lenght  ;*/

		T *temp = new T[lenght + 1] ;
		size = lenght + 1;
		front = 0;
		rear = -1;
		for (int i = 0; i < lenght; i++)
		{
			rear = (rear + 1) % size; 
			temp[rear] =  Qobj[i] ;
		}
		delete []Qobj ;
		Qobj = temp ;
	}

	void movedown(){

		for (int i = lenght; i != 0 ; i--)
		{
			Qobj[i] = Qobj[i - 1] ;
		}
	}

	void moveup(){
		for (int i = 0; i < lenght; i++)
		{
			Qobj[i] =  Qobj[i+1] ;
		}
	}

	bool deque(T& S){
		if (! IsEmpty()) { 
			S= Qobj[front];
			//moveup();
			//rear -- ;
			front = (front+1)%size;
			lenght--;
			return 1;
		}
		else 
		{
			cout<<"Queue is now empty\n";
			return 0;
		}
	}

	bool IsEmpty(){
		if(lenght == 0)
			return 1;
		return false;
	}

	void Qdisplay()
	{
		for(int i=0; i<lenght; i++)
		{
			cout<< Qobj[i]<<endl;
		}
	}

	void e_enque(T dat) //enhanced enque
	{
		stack<T> s1(Qobj,lenght);
		s1.push(dat);
		size = s1.size;
		lenght = s1.len;
		delete []Qobj;
		Qobj = new T[size];
		front =0;
		rear = -1;
		int temp = (lenght-1); // to calculate where at the queue the element should be placed
							// to avoid the confusion of front and rear of queue
		for(int i=lenght; i>0; i--)
		{
			rear = (temp % size);
			//Qobj[rear] = s1.pop(); // placing the element at the calculated index
			s1.pop(Qobj[rear]); // placing the element at the calculated index
			temp --;
		}
		rear = lenght-1;
	}

	bool e_deque(T&S)
	{
		if(!IsEmpty())
		{
			stack<T> s1(Qobj,lenght);
			stack<T> s2(lenght);
			int count=0;
			//T ret;
			bool chk=0;
			while(count<lenght)
			{
				chk = s1.pop(S);//ret);
				if (!chk)
					break;
				s2.push(S);//ret);
				count++;
			}
			//T ret = s2.pop();
		
			s2.pop(S);//ret);
			lenght = s2.len;
			size = s2.len;
			delete []Qobj;
			Qobj = new T[size];
			front =0;
			rear = -1;
			for(int i=0; i<size; i++)
			{
				rear = (rear+1) % size;
				s2.pop(Qobj[rear]);
				//Qobj[rear] = s2.pop(); // placing the element at the calculated index 
			}
			return 1;
		}
		return 0;
	}

	~ queue()
	{
		delete []Qobj;
		Qobj = nullptr;
	}

};

