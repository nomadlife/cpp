/* 
 using2.cpp
*/
	
#include <iostream>

namespace A_COM
{
	void function(void)
	{
		std::cout<<"A.com���� ������ �Լ�"<<std::endl;
	}
}

using namespace A_COM;

int main(void)
{
	function();
	return 0;
}
