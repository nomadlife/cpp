//functin returning the max between two numbers
//calling a function
#include <iostream>
using namespace std;


//function declaration
int max(int num1, int num2);  // or int max(int, int); 

int main()
{
    //local vatiable declaration:
    int a= 100;
    int b= 200;
    int ret;

    //calling a function to get max value.
    ret = max(a,b);

    cout << "Max value is :" << ret << endl;

    return 0;
}

int max(int num1, int num2)
{
    //local vatiable declaration
    int result;

    if (num1 > num2)
    result = num1;
    else
    result = num2;

    return result;

}

