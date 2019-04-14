#ifndef date_HPP_INCLUDED
#define date_HPP_INCLUDED

#include <iostream>
#include <time.h>

using namespace std;

#define YR 1900
#define FORMAT 1  //FORMAT == 0;  m/d/y; FORMAT != 0; d/m/y

class date
{
private:
	int d, m, y;
    static int maxD[13];

public:

	date();
	date(int d, int m, int y);
	date(const date &x) { (*this) = x; }
	~date() {}

	int getD() {return d;}
	int getM() {return m;}
	int getY() {return y;}
	bool setAll(int d, int m, int y);
	void setY(int x) {y = x;}
	void setM(int x) {m = x;}
	void setD(int x) {d = x;}

	bool valid();
	bool bisestile();
    int getMaxD(); //returns the number of days of  the  caller instance's month
	void setCurrent();//set the caller instance to the current date

	string getMonthName(); //returns a string that contains the name of month of the parameter m

	bool operator < (const date &x); //caller instance before x
	bool operator <= (const date &x);
	bool operator > (const date &x); //caller instance after x
	bool operator >= (const date &x);
	bool operator == (const date &x);
	bool operator != (const date &x);

	date &operator = (const date &x);
	date &operator ++ (int x); //increase the caller instance of 1 day
	date &operator -- (int x); //decrease the caller instance of 1 day

	friend ostream& operator << (ostream &io, const date &x);
	friend istream& operator >> (istream &io, date &x);
};


#endif // date_HPP_INCLUDED