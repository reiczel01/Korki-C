#include <stdio.h>
#include <time.h>
int sort_dates(int day[], int month[], int year[], int size) {
    return 0;
}
int main(void)
{
    time_t     now;
    struct tm  ts;
    struct tm t;
    time_t t_of_day;
    t.tm_year = 1800 - 1900;  // Year - 1900
    t.tm_mon = 7;           // Month, where 0 = jan
    t.tm_mday = 8;   // Day of the month
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = -1;
    char       buf[80];
    t_of_day = mktime(&t);

    printf("seconds since the Epoch: %ld\n", (long)t_of_day);

    // Get current time
    time(&now);

    // Format time, "ddd yyyy-mm-dd hh:mm:ss zzz"
    time_t ourDate = 1613140000;
    ts = *localtime(&ourDate);
    strftime(buf, sizeof(buf), "%d-%m-%Y", &ts);
    printf("%s\n", buf);
    return 0;
}