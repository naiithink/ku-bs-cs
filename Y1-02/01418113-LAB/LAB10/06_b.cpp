#include <iostream>
#include <cmath>
#include <string>
#include <time.h>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;
    //     int duration;

public:
    explicit Time(int hour, int minute, int second)
    {
        int duration = 0;

        duration = second + (minute * 60) + (hour * 3600);
        if (duration > 86400)
            duration %= 86400;
        else if (duration < 0)
        {
            duration *= -1;
            if (duration > 86400)
                duration %= 86400;
        }

        this->hour = (int)duration / 3600;
        duration -= this->hour * 3600;
        this->minute = (int)duration / 60;
        duration -= this->minute * 60;
        this->second = duration;
    }

    explicit Time(int duration)
    {
        if (duration > 86400)
            duration %= 86400;
        else if (duration < 0)
        {
            duration *= -1;
            if (duration > 86400)
                duration %= 86400;
        }

        this->hour = (int)duration / 3600;
        duration -= this->hour * 3600;
        this->minute = (int)duration / 60;
        duration -= this->minute * 60;
        this->second = duration;
    }

    int getDuration(void)
    {
        int duration = 0;

        duration += this->hour * 3600;
        duration += this->minute * 60;
        duration += this->second;

        return duration;
    }

    int getHour(void)
    {
        return this->hour;
    }

    int getMinute(void)
    {
        return this->minute;
    }

    int getSecond(void)
    {
        return this->second;
    }

    void setHour(const int in_hour)
    {
        hour = in_hour;
    }

    void setMinute(const int in_minute)
    {
        minute = in_minute;
    }

    void setSecond(const int in_second)
    {
        second = in_second;
    }

    Time add(Time other)
    {
        Time day(24, 0, 0);
        int sum_duration = 0;

        sum_duration = getDuration() + other.getDuration();

        if (sum_duration > day.getDuration())
            sum_duration %= day.getDuration();

        Time res(sum_duration);

        return res;
    }

    int subtract(Time other)
    {
        int res = 0;
        Time day(24, 0, 0);

        if (getDuration() >= other.getDuration())
            res = getDuration() - other.getDuration();
        else
            res = day.getDuration() - other.getDuration() + getDuration();

        return res;
    }

    int equals(Time other)
    {
        int res = -1;
        int this_duration = 0;
        int other_duration = 0;

        this_duration = getDuration();
        other_duration = other.getDuration();

        if (this_duration == other_duration)
            res = 1;
        else
            res = 0;

        return res;
    }

    string toString(void)
    {
        string res;
        string hour, minute, second;

        hour = to_string(this->hour);
        minute = to_string(this->minute);
        second = to_string(this->second);

        hour.insert(hour.begin(), 2 - hour.length(), '0');
        minute.insert(minute.begin(), 2 - minute.length(), '0');
        second.insert(second.begin(), 2 - second.length(), '0');

        res = hour + ":" + minute + ":" + second;

        return res;
    }
};

int main()
{
    clock_t start, end;
    start = clock();
    /* From the example */
    // Time a(2, 2, 2);
    // Time b(1, 1, 1);
    // Time c(82739);
    // Time d(9, 8, 4);
    // Time day(24, 0, 0);

    // cout << a.subtract(b) << endl;
    // cout << b.subtract(a) << endl;

    // cout << a.getDuration() << endl;
    // cout << b.getDuration() << endl;

    // cout << c.toString() << endl;
    // cout << d.toString() << endl;
    // cout << d.getDuration() << endl;

    // cout << day.getDuration() << endl;
    // cout << day.subtract(b) << endl;

    /* ELAB */
    Time t1(0, 0, 0);
    Time t2(12, 13, 14);
    Time t3(13, 57, 59);
    Time t4(7, 58, 25);
    Time t5(4, 7, 9);

    Time a(2, 2, 2);
    Time b(1, 1, 1);

    cout << a.toString() << endl;
    cout << b.toString() << endl;
    cout << a.getDuration() << endl;
    cout << b.getDuration() << endl;
    cout << a.subtract(b) << endl;
    cout << b.subtract(a) << endl;
    cout << endl;

    cout << "1   " << t1.getDuration() << endl;
    cout << "2   " << t2.getDuration() << endl;
    cout << "3   " << t3.getHour() << endl;
    cout << "4   " << t3.getMinute() << endl;
    cout << "5   " << t3.getSecond() << endl;
    cout << endl;

    t5 = t1.add(t2);
    cout << "6   " << t5.getDuration() << endl;
    cout << endl;

    t5 = t2.add(t3);
    cout << "7   " << t5.getHour() << " " << t5.getMinute() << " " << t5.getSecond() << endl;
    cout << endl;

    t5 = t2.add(t4);
    cout << "8   " << t5.getHour() << " " << t5.getMinute() << " " << t5.getSecond() << endl;
    cout << endl;

    cout << "9   " << t1.toString() << endl;
    cout << "10  " << t2.toString() << endl;
    cout << "11  " << t3.toString() << endl;
    cout << "12  " << t4.toString() << endl;
    cout << "13  " << t5.toString() << endl;
    cout << endl;

    cout << "t1  " << t1.getDuration() << endl;
    cout << "t2  " << t2.getDuration() << endl;
    cout << "t3  " << t3.getDuration() << endl;
    cout << "t4  " << t4.getDuration() << endl;
    cout << "t5  " << t5.getDuration() << endl;
    cout << endl;

    cout << "14  " << t1.subtract(t5) << endl;
    cout << "15  " << t5.subtract(t1) << endl;
    cout << "16  " << t3.subtract(t2) << endl;
    cout << "17  " << t2.subtract(t3) << endl;
    cout << endl;

    cout << "18  " << t5.equals(t3) << endl;
    cout << endl;

    t5 = Time(t3.subtract(t1));

    cout << "t1  " << t1.getDuration() << endl;
    cout << "t2  " << t2.getDuration() << endl;
    cout << "t2  " << t2.toString() << endl;
    cout << "t3  " << t3.getDuration() << endl;
    cout << "t4  " << t4.getDuration() << endl;
    cout << "t5  " << t5.getDuration() << endl;
    cout << endl;


    cout << "19  " << t5.equals(t3) << endl;
    cout << "20  " << t2.equals(Time(12, 13, 14)) << endl;
    cout << "21  " << t2.equals(Time(12, 13, 14)) << endl;
    cout << endl;

    cout << "22  " << t4.equals(Time(t4.getDuration())) << endl;
    cout << "23  " << t4.equals(Time(t4.getDuration())) << endl;

    end = clock();
    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f\n", elapsed);
    
    return 0;
}