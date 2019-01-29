// Current Date and Time

#include <iostream>
#include <ctime>

using namespace std;

// main function to call above defined function
int main()
{
    //current data/time based on current system
    time_t now = time(0);

    //convert now to string form
    char *dt = ctime(&now);

    cout << "The local date and time is:" << dt << endl;

    // convert now to tm strunt for UTC
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);

    cout << "The UTC date and time is:" << dt << endl;
}
