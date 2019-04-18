#include "date.hpp"
#include "test.hpp"
using namespace std;
//this file has only been made to test the date class and show how to use it
//if you want to run this test, run cmake in this folder

bool tstEqOperator()
{
	date x1;
	date x(18, 4, 2019);

	x1 = x;

	if (x1 == x)
		return true;

	std::cout<<endl<<"tstOperatorEq FAILED";
	return false;
}

bool tstSetAll()
{
	date x(18, 4, 2019);
	date x1;
	x1.setAll(18, 4, 2019);

	if (x1 == x)
		return true;

	std::cout<<endl<<"tstSetAll FAILED";
	return false;
}

bool tstBisestile()
{
	date yBis1(20, 5, 2000);
	date yBis2(12, 9, 2016);
	date yNoBis(16, 9, 2002);

	if (yBis1.bisestile() && yBis2.bisestile() && (!yNoBis.bisestile()))
		return true;

	std::cout<<endl<<"tstBisestile FAILED";
	return false;
}

bool tstGreaterOperator()
{
	date x(30, 12, 2018);
	date x1(15, 12, 2018);
	date x2(15, 11, 2018);
	date x3(12, 7, 2017);

	if (x > x1 && x > x2 && x > x3)
		return true;

	std::cout<<endl<<"tstGreaterOperator FAILED";
	return false;
}

bool tstPlusPlusOperator()
{
	date x1(12, 10, 2007);
	date x1pp(13, 10, 2007);

	date x2(31, 10, 2007);
	date x2pp(1, 11, 2007);

	date x3(31, 12, 2007);
	date x3pp(1, 1, 2008);

	if (x1++ == x1pp && x2++ == x2pp && x3++ == x3pp)
		return true;

	std::cout<<endl<<"tstPlusPlusOperator FAILED";
	return false;
}

bool tstMinusMinusOperator()
{
	date x1(13, 10, 2007);
	date x1pp(12, 10, 2007);

	date x2(1, 11, 2007);
	date x2pp(31, 10, 2007);

	date x3(1, 1, 2008);
	date x3pp(31, 12, 2007);

	if (x1-- == x1pp && x2-- == x2-- && x3-- == x3pp)
		return true;

	std::cout<<endl<<"tstMinusMinusOperator FAILED";
	return false;
}


int main()
{
	cout<<endl<<"--- test ---";
	if ( tstEqOperator() && tstSetAll() && tstBisestile()
		&& tstGreaterOperator() && tstPlusPlusOperator() 
		&& tstMinusMinusOperator() )
		cout<<endl<<"Every test passed!";

	date d;
	cout<<"print default date: "<<endl<<d;

	d.setCurrent();
	cout<<endl<<"current date: "<<d;

	if (d.bisestile())
		cout<<endl<<"current year is bisestile";
	else
		cout<<endl<<"current year isnt' bisestile";

	cout<<endl<<"month "<<d.getMonthName();
	cout<<" has "<<d.getMaxD()<<" days"<<endl;

	date d1(15, 12, 2001);
	date d2(d1);

	if (d1 == d2)
		cout<<endl<<"== = setAll copy constructor work";

	cout<<endl<<"Input first date: "<<endl;
	cin>>d1;
	cout<<endl<<"Input second date: "<<endl;
	cin>>d2;

	cout<<endl<<"fist date"<<endl<<d1;
	cout<<endl<<"second date"<<endl<<d2;
	#include "test.hpp"

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
