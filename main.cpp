#include "date.hpp"
#include "test.hpp"
using namespace std;

int main()
{
	cout<<endl<<"--- test ---";
	if ( tstEqOperator() && tstSetAll() && tstBisestile()
		&& tstGreaterOperator() && tstPlusPlusOperator() 
		&& tstMinusMinusOperator() )
		cout<<endl<<"Every test passed!"<<endl;

	date d;
	cout<<endl<<"print default date: "<<endl<<d;

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
		cout<<endl<<d2<<endl<<"is a copy";

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

	cout<<endl<<"fist date with one day more: "<<endl<<++d1;
	cout<<endl<<"fist with one day less: "<<endl<<--d1;

	cout<<endl;

	return 0;
}
