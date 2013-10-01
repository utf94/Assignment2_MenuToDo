#pragma once
#include <iostream>
using namespace std;

void name_adjuster() ;

class student
{
private:
	long int id ;
	char *name ;

public:
	//student();
	student(int id1=0, char*N=nullptr)
	{
		id = id1;
		name = N;
	}
	~student();
	void sort_id();
	void sort_name();
	void get_data() ;
	void Student_Display();
	void operator= ( const char obj2[]);
	friend ostream& operator <<(ostream& o, const student& S);
	friend int name_adjuster(char obj[]) ;
	friend void sort (student *[] , int ) ;
};