#include "date.hpp"

int date::maxD[] =
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

date::date(int dd, int mm, int yy) :
    d{dd},
    m{mm},
    y{yy}
{}

bool date::setAll(int d, int m, int y)
{
    this->d = d;
    this->m = m;
    this->y = y;

    if (!this->valid())
	{
        this->d = 1;
        this->m = 1;
        this->y = YR;
		return false;
	}
	return true;
}

bool date::valid()
{
    if (y < YR)
        return false;
    else
    {
        if (m < 1 || m > 12)
            return false;
        else
        {
            if (d < 1 || d > this->getMaxD())
                return false;
        }
    }
    return true;
}

bool date::bisestile()
{
    if (y % 400 == 0)
		return true;
	else
	{
        if ((y % 4 == 0) && (y % 100 != 0))
			return true;
	}
	return false;
}

int date::getMaxD()
{
    if (m < 1 || m > 12 || y < YR)
        return -1;

    if (m == 2)
    {
        if (this->bisestile())
            return 29;
    }

    return maxD[m]; //static array
}

bool date::operator > (const date &x)
{
    if ((*this).y > x.y)
	{
        return true;
	}
    else if ((*this).y == x.y)
	{
        if ((*this).m > x.m)
			return true;
        else if ((*this).m == x.m)
		{
            if ((*this).d > x.d)
				return true;
		}
	}
	return false;
}

bool date::operator>=(const date& x)
{
    if ((*this) > x || (*this) == x)
        return true;

    return false;
}

bool date::operator < (const date &x)
{
	if ((*this) > x)
		return false;

    return true;
}

bool date::operator<=(const date& x)
{
    if ((*this) < x || (*this) == x)
        return true;

    return false;
}

bool date::operator == (const date &x)
{
    if ((*this).y == x.y && (*this).m == x.m && (*this).d == x.d)
		return true;

    return false;
}

bool date::operator != (const date &x)
{
    if (! ((*this) == x))
        return true;

    return false;
}

date& date::operator ++ (int x)
{
    if (m ==12 && d == 31)
        y++;

    d++;

    if (d > this->getMaxD())
	{
        d = 1;
        m++;
	}
	return (*this);
}

date& date::operator -- (int x)
{
    if (m == 1 && d == 1)
        y--;

    d--;

    if (d <= 0)
	{
        d = this->getMaxD();
        m--;
	}
	return (*this);
}

void date::setCurrent()
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    time_t tt = std::chrono::system_clock::to_time_t(now);
    tm *todayTm = localtime(&tt);

	this->setAll(
               todayTm->tm_mday,
               todayTm->tm_mon + 1,
               todayTm->tm_year + YR);
}

void date::setCurrentTm()
{
	time_t a = time(0);
    struct tm *todayTm = localtime(&a);

    this->setAll(
                todayTm->tm_mday,
               	todayTm->tm_mon + 1,
               	todayTm->tm_year + YR);
}

std::ostream& operator << (std::ostream &io, const date &x)
{
    if (FORMAT == 0)
        io<<x.m<<"/"<<x.d<<"/"<<x.y;
    else
        io<<x.d<<"/"<<x.m<<"/"<<x.y;

	return io;
}

std::istream& operator >> (std::istream &io, date &x)
{
	bool first = true;

	do
    {
        if (first)
            first = false;
        else
            std::cout<<std::endl<<"unvalid date, please retry!";

        std::cout<<std::endl<<"y: ";
        io>>x.y;

        std::cout<<"m: ";
        io>>x.m;

        std::cout<<"d: ";
        io>>x.d;
    }
    while (!x.valid());

	return io;
}

std::string date::getMonthName()
{
    switch(this->m)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "Septenber";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        return "ERROR";
    }
}