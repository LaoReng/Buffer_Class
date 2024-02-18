// CBuffer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Buffer.h"

int test()
{
	Buffer str;
	Buffer str1;
	str = "hello ";
	str = str + "你好";
	str1 = str;
	std::cout << str << std::endl;
	std::cout << str1 << std::endl;
	return 0;
}

int main()
{
	test();
	return 0;
}
