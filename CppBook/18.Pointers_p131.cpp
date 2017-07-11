// function which can accept a pointer, can also accept an array as shown in
// the following example:
// p131

#include <iostream>
//#include <ctime>

using namespace std;

//function declaration:
void getAverage(int *arr, int size);

int main ()
{
    //an int array with 5 elements.
    int balance[5] = {1000,2,3,17,50};
    double avg;
    
    return 0;
}

void getSeconds(unsigned long *par)
{
    //get the current number of seconds
    *par = time (NULL);
    return;
}