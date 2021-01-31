#include <iostream>

class Date
{
    int year;
    int month; // 1부터 12 까지
    int day;   // 1부터 31 까지

public:
    void SetDate(int year_, int month_, int date_)
    {
        this->year = year_;
        this->month = month_;
        this->day = date_;
    }

    void AddDay(int inc)
    {

    tryAgain:
        switch (this->month)
        {
        // 31일 까지 있는 달 : 1,3,5,7,8,10,12
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if (this->day + inc > 31)
            {
                this->month++;
                inc = inc - (31 - this->day);
                this->day = 0;
                goto tryAgain;
            }
            else
            {
                this->day = this->day + inc;
                break;
            }
        case 12:
            if (this->day + inc > 31)
            {
                this->month = 1;
                this->year++;
                inc = inc - (31 - this->day);
                this->day = 0;
                goto tryAgain;
            }
            else
            {
                this->day = this->day + inc;
                break;
            }
        // 30일 까지만 있는 달 : 4,6,9,11
        case 4:
        case 6:
        case 9:
        case 11:
            if (this->day + inc > 30)
            {
                this->month++;
                inc = inc - (30 - this->day);
                this->day = 0;
                goto tryAgain;
            }
            else
            {
                this->day = this->day + inc;
                break;
            }
        // 28일까지만 있는 달 : 2
        case 2:
            if (this->day + inc > 28)
            {
                this->month++;
                inc = inc - (this->day + inc) % 28;

                this->day = 0;
                goto tryAgain;
            }
            else
            {
                this->day = this->day + inc;
                break;
            }
        }
    }

    void AddMonth(int inc)
    {
        // 12를 초과하면 year 올리기
        if (this->month + inc > 12)
        {
            this->year = this->year + (this->month + inc) / 12;
            this->month = (this->month + inc) % 12;
        }
        else
        {
            this->month += inc;
        }
    }
    void AddYear(int inc)
    {
        this->year += inc;
    }
    void ShowDate()
    {
        std::cout << this->year << "년" << this->month << "월" << this->day << "일" << std::endl;
    }
};

int main()
{
    Date date;
    date.SetDate(2021, 01, 30);
    std::cout << "현재 날짜는 ";
    date.ShowDate();
    // 3년 더하기
    date.AddYear(3);
    std::cout << "3년 더한 후 : ";
    date.ShowDate();
    // 4개월 더하기
    date.AddMonth(4);
    std::cout << "4개월 더한 후 : ";
    date.ShowDate();
    // 14개월 더하기
    date.AddMonth(14);
    std::cout << "14개월 더한 후 : ";
    date.ShowDate();
    // 1일 더하기
    date.AddDay(1);
    std::cout << "1일 더한 후 : ";
    date.ShowDate();
    // 30일 더하기
    date.AddDay(30);
    std::cout << "30일 더한 후 : ";
    date.ShowDate();
    // 100일 더하기
    date.AddDay(200);
    std::cout << "200일 더한 후 : ";
    date.ShowDate();
}
