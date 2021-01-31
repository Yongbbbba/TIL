#include <iostream>

class Date
{
    int year;
    int month; // 1부터 12 까지
    int day;   // 1부터 31 까지

    public:
    void SetDate(int year_, int month_, int date_)
    {
        year = year_;
        month = month_;
        day = date_;
    }

    void AddMonth(int inc);
    void AddDay(int inc);
    void AddYear(int inc);
    void ShowDate();
};

void Date::AddDay(int inc)
{

tryAgain: //Goto 문 활용
    switch (month)
    {
        // 31일 까지 있는 달 : 1,3,5,7,8,10,12
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day + inc > 31)
            {
                // inc를 더했는데 달이 넘어가면, month를 1 올려주고 day를 0으로 만든다. 현재 day와 31일만큼의 차이를 inc에서 차감하고 다시 switch 문을 돌린다.
                AddMonth(1);
                inc -= (31 - day);
                day = 0;
                goto tryAgain;
            }
            else
            {
                // inc를 더했는데 31일이 안넘으면 month에 영향이 없으므로 그냥 더하고 swith 문을 나간다.
                day += inc;
                break;
            }
            // 30일 까지만 있는 달 : 4,6,9,11
        case 4:
        case 6:
        case 9:
        case 11:
            if (day + inc > 30)
            {
                AddMonth(1);
                inc -= (30 - day);
                day = 0;
                goto tryAgain;
            }
            else
            {
                day += inc;
                break;
            }
            // 28일까지만 있는 달 : 2
        case 2:
            // 윤년인 경우
            if (year % 4 == 0 && year % 100 != 0){

                if (day + inc > 29)
                {
                    AddMonth(1);
                    inc -= (29 - day); 

                    day = 0;
                    goto tryAgain;
                } else{
                    day += inc;
                    break;
                } 
            } else {

                // 윤년이 아닌 경우
                if (day + inc > 28)
                {
                    AddMonth(1);
                    inc -= (28-day);

                    day = 0;
                    goto tryAgain;
                }
                else
                {
                    day += inc;
                    break;
                }

            }

    }
}


void Date::AddMonth(int inc)
{
    AddYear( (month + inc - 1) / 12);
    month = month + inc % 12;
    month = (month == 12 ? 12 : month % 12);
}
void Date::AddYear(int inc)
{
    year += inc;
}
void Date::ShowDate()
{
    std::cout << year << "년" << month << "월" << day << "일" << std::endl;
}


int main()
{
    Date day;
    day.SetDate(2011, 3, 1);
    day.ShowDate();
    day.AddDay(30);
    day.ShowDate();
    day.AddDay(2000);
    day.ShowDate();
    day.SetDate(2012, 1, 31); // 윤년
    day.AddDay(29);
    day.ShowDate();
    day.SetDate(2012, 8, 4);
    day.AddDay(2500);
    day.ShowDate();
    return 0;
}
