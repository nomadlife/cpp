/* 
 using1.cpp
*/
	
#include <iostream>

namespace A_COM
{
	void function(void)
	{
		std::cout<<"A.com���� ������ �Լ�"<<std::endl;
	}
}

using A_COM::function;
int main(void)
{
	function();
	return 0;
}
