#include <iostream>
//The extern Storage Class
int count;
extern void write_extern();
main()
{
    count = 5;
    write_extern();
}
