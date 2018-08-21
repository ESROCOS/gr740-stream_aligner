#include "Time.hpp"

#include <sys/time.h>
#include <math.h>
#include <iomanip>
#include <stdexcept>
#include <stdio.h>
#include <time.h>
#include <limits>

namespace base {

Time::Time(int64_t _microseconds) : microseconds(_microseconds)
{

}

Time::Time() : microseconds(0)
{

}

Time Time::now()
{
    timeval t;
    gettimeofday(&t, 0);
    return Time(static_cast<int64_t>(t.tv_sec) * UsecPerSec + t.tv_usec);
}

bool Time::operator<(const Time& ts) const
{
    return microseconds < ts.microseconds;
}

bool Time::operator>(const Time& ts) const
{
    return microseconds > ts.microseconds;
}

bool Time::operator==(const Time& ts) const
{
    return microseconds == ts.microseconds;
}

bool Time::operator!=(const Time& ts) const
{
    return !(*this == ts);
}

bool Time::operator>=(const Time& ts) const
{
    return !(*this < ts);
}

bool Time::operator<=(const Time& ts) const
{
    return !(*this > ts); 
}

Time Time::operator-(const Time& ts) const
{
    return Time(microseconds - ts.microseconds);
}

Time Time::operator+(const Time& ts) const
{
    return Time(microseconds + ts.microseconds);
}

Time Time::operator/(int divider) const
{
    return Time(microseconds / divider);
}

Time Time::operator*(double factor) const
{
    return Time(microseconds * factor);
}

bool Time::isNull() const
{
    return microseconds == 0;
}

timeval Time::toTimeval() const
{
    timeval tv = { static_cast<time_t>(microseconds / UsecPerSec), static_cast<suseconds_t>(microseconds % UsecPerSec) };
    return tv;
}

std::string Time::toString(Time::Resolution resolution, const std::string& mainFormat) const
{
    struct timeval tv = toTimeval();
    int uSecs = tv.tv_usec;

    time_t when = tv.tv_sec;
    struct tm *tm = localtime(&when); 

    char time[50];
    strftime(time,50, mainFormat.c_str(), tm);

    char buffer[57];
    switch(resolution)
    {
        case Seconds:
            return std::string(time);
        case Milliseconds:
            sprintf(buffer,"%s:%03d", time, (int) (uSecs/1000.0));
            break;
        case Microseconds:
            sprintf(buffer,"%s:%06d", time, uSecs);
            break;
        default:
            throw std::invalid_argument(
                "Time::toString(): invalid "
                "value in switch-statement");
    }

    return std::string(buffer);
}

double Time::toSeconds() const
{
    return static_cast<double>(microseconds) / UsecPerSec;
}

int64_t Time::toMilliseconds() const
{
    return microseconds / 1000;
}

int64_t Time::toMicroseconds() const
{
    return microseconds;
}

Time Time::fromMicroseconds(int64_t value)
{
    return Time(value);
}

Time Time::fromMilliseconds(int64_t value)
{
    return Time(value * 1000);
}

Time Time::fromSeconds(int64_t value)
{
    return Time(value * UsecPerSec); 
}

Time Time::fromSeconds(int value)
{
    return Time(static_cast<int64_t>(value) * UsecPerSec);
}

Time Time::fromSeconds(int64_t value, int microseconds)
{
    return Time(value * UsecPerSec + static_cast<int64_t>(microseconds));
}

Time Time::fromSeconds(double value)
{
    int64_t seconds = value;
    return Time(seconds * UsecPerSec + static_cast<int64_t>(round((value - seconds) * UsecPerSec)));
}

Time Time::max()
{
    return Time(std::numeric_limits<int64_t>::max());
} 

Time Time::fromTimeValues(int year, int month, int day, int hour, int minute, int seconds, int millis, int micros)
{
    struct tm timeobj;
    timeobj.tm_year = year - 1900;
    timeobj.tm_mon = month - 1;
    timeobj.tm_mday = day;
    timeobj.tm_hour = hour;
    timeobj.tm_min = minute;
    timeobj.tm_sec = seconds;
    timeobj.tm_isdst = -1;

    time_t tTime;
    tTime = mktime(&timeobj);

    int64_t timeVal =  static_cast<int64_t>(tTime);

    timeVal = timeVal * UsecPerSec;
    timeVal += millis * 1000 + micros;


    return Time(timeVal); 
}

Time Time::fromString(const std::string& stringTime, Time::Resolution resolution, const std::string& mainFormat)
{
    // On the GR740 board, there exists no strptime, therefore this function should not be used!
    // For now, we just return some defined base::Time value, e.g. max()
    return max();
}


std::ostream& operator<<(std::ostream& io, const Time& time)
{
    const int64_t microsecs = time.toMicroseconds();

    io << (microsecs / 1000000)
        << std::setfill('0')
        << "." << std::setw(3) << (std::llabs(microsecs) / 1000) % 1000
        << "." << std::setw(3) << (std::llabs(microsecs) % 1000)
        << std::setfill(' ');

    return io;
}


} //end namespace base
