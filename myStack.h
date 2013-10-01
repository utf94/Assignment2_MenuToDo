#pragma once
#include <iostream>
#include "student.h"
#include <string>
using namespace std ;

template <typename T>

class stack
{
public:

	T *obj ;
	int len ;
	int size ;

	stack(int num){  //ctor if only size is passed
 		obj =  new T[num] ;
		len = 0 ;
		size =  num ;
	} 

	stack()
	{
		obj =  NULL ;
		len = 0 ;
		size =  0 ;
	} // default ctor

	stack(T arr[],int num){ //ctor if array and sized are passed ,to be used for enhanced Enque and Deque
		obj =  new T[num] ;
		len = num ;
		size =  num ;
		for(int i=0; i<size; i++)
		{
			obj[i] = arr[i];
		}
	}

	void push(T dat){
		if (IsFull())
		{
			resize() ;
		}
		obj[len] = dat;
		len++;
	}
	
	void resize(){
		//if(IsFull())
		//{
			T *temp = new T[len+1] ;
			size = len+1  ;
			for (int i = 0; i < len; i++)
			{
				temp[i] =  obj[i] ;
			}
			delete []obj ;
			obj = temp ;
		//}
	}

	bool IsFull()
	{
		if(len == size)
		{
			return true;
		}
		return false;

	}

	void movedown(){
	
		for (int i = len; i != 0 ; i--)
		{
			obj[i] = obj[i - 1] ;
		}
	}
	
	void moveup(){
		for (int i = 0; i <= len; i++)
		{
			obj[i] =  obj[i+1] ;
		}
	}
	
	 bool pop(T&S) {
		// good for enhanced operation

		/*T *tem = new T ;
	 *tem = obj[0] ;
	 moveup();
	 len-- ;
	return *tem ;*/	  

		if(!IsEmpty())
		{
			S = obj[--len];
			//return S;
			return true;
		}
		return 0;
	}

	bool IsEmpty()
	{
		if(len == 0)
			return true;
		return false;
	}

	void display()
	{
		for(int i=(len-1); i>=0; i--)
		{
			cout<< obj[i]<<endl;
		}
	}

	~ stack()
	{
		delete []obj;
		obj = nullptr;
	}

};
	
