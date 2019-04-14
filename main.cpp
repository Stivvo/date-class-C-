#include "date.hpp"

//this file has only been made to test the date class and show how to use it
//if you want to run this test, run cmake in this folder
//to use this class, copy date.hpp and date.cpp in your project's folder and include date.hpp

//time.h library is required
//developed on linux

using namespace std;

int main()
{
	date d;
	cout<<"print default date: "<<endl<<d;

	d.setCurrent();
	cout<<endl<<"current date: "<<d;

	if (d.bisestile())
		cout<<endl<<"current year is bisestile";
	else
		cout<<endl<<"current year isnt' bisestile";

	cout<<endl<<"month "<<d.getMonthName()<<" has "<<d.getMaxD()<<" days"<<endl;

	date d1(15, 12, 2001);
	date d2(d1);

	if (d1 == d2)
		cout<<endl<<"==, =, setAll, copy constructor, work";

	cout<<endl<<"Input first date: "<<endl;
	cin>>d1;
	cout<<endl<<"Input second date: "<<endl;
	cin>>d2;

	cout<<endl<<"fist date"<<endl<<d1;
	cout<<endl<<"second date"<<endl<<d2;

	if(d1 == d2)
		cout<<endl<<"equal";
	if (d1 > d2)
		cout<<endl<<"> first greater than second / first after second";
	if (d1 < d2)
		cout<<endl<<"< first smaller than second / first before second";
	if (d1 >= d2)
		cout<<endl<<">=";
	if (d1 <= d2)
		cout<<endl<<"<=";
	if (d1 != d2)
		cout<<endl<<"different";

	cout<<endl<<"fist date with one day more: "<<endl<<d1++;
	cout<<endl<<"fist with one day less: "<<endl<<d1--;

	cout<<endl;

	return 0;
}
