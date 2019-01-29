// Format Time using struct tm

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    //current data/time based on current system
    time_t now = time(0);

    printf("test %ld \n", now);
    cout << now << endl;

    cout << "Number of sec since January 1,1970:" << now << endl;

    tm *ltm = localtime(&now);
    cout << "test :" << ltm << endl;

    //print various components of tm structure.
    cout << "Year: " << 1900 + ltm->tm_year << endl;
    cout << "Month: " << 1 + ltm->tm_mon << endl;
    cout << "Day: " << ltm->tm_mday << endl;
    cout << "Time: " << 1 + ltm->tm_hour << endl;
    cout << 1 + ltm->tm_min << ":";
    cout << 1 + ltm->tm_sec << endl;

    //tm *t=localtime();
    //cout << "localtime :" << t << endl;
}
