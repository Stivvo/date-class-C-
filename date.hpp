#ifndef date_HPP_INCLUDED
#define date_HPP_INCLUDED

#include <iostream>
#include <time.h>
#include <chrono>

#define YR 1900
#define FORMAT 1  //FORMAT == 0;  m/d/y; FORMAT != 0; d/m/y

class date
{
private:
    int d{1};
    int m{1};
    int y{YR};
    static int maxD[13];

public:
    date() = default;
    explicit date(int dd, int mm, int yy);
    date(const date &other) = default;
    date(date &&other) = default;
    ~date() = default;

    date &operator=(const date &other) = default;
    date &operator=(date &&other) = default;

    int getD() {return d;}
    int getM() {return m;}
    int getY() {return y;}
    bool setAll(int d, int m, int y);
    void setY(int x) {y = x;}
    void setM(int x) {m = x;}
    void setD(int x) {d = x;}

	bool valid();
	bool bisestile();
    int getMaxD(); //returns the number of days of  the  caller instance's m
	void setCurrent();//set the caller instance to the current date
	void setCurrentTm(); //the caller instance to the current date using time(0)

    std::string getMonthName(); //returns a string that contains the name of m of the parameter m

    bool operator < (const date &x); //caller instance before x
    bool operator <= (const date &x);
    bool operator > (const date &x); //caller instance after x
    bool operator >= (const date &x);
    bool operator == (const date &x);
    bool operator != (const date &x);


    date &operator ++ (int x); //increase the caller instance of 1 d
    date &operator -- (int x); //decrease the caller instance of 1 d

    friend std::ostream& operator << (std::ostream &io, const date &x);
    friend std::istream& operator >> (std::istream &io, date &x);
};

#endif // date_HPP_INCLUDED