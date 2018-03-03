/*
 * Structural_Facade.cpp
 *
 *  Created on: 2018年3月2日
 *  href: http://blog.csdn.net/wuzhekai1985/article/details/6667564
 *      Author: liu_z
 *      几个特点:（1）它对客户屏蔽子系统组件，因而减少了客户处理的对象的数目并使得子系统使用起来更加方便。
 *      （2）它实现了子系统与客户之间的松耦合关系，而子系统内部的功能组件往往是紧耦合的。
 *      （3）如果应用需要，它并不限制它们使用子系统类。
 *
 */
#include <iostream>
using namespace std;


class Scanner
{
	public:
		void Scan() { cout<<"词法分析"<<endl; }
};

class Parser
{
	public:
		void Parse() { cout<<"语法分析"<<endl; }
};

class GenMidCode
{
	public:
		void GenCode() { cout<<"产生中间代码"<<endl; }
};

class GenMachineCode
{
	public:
		void GenCode() { cout<<"产生机器码"<<endl;}
};

//高层接口
class Compiler
{
	public:
		void Run()
		{
			Scanner scanner;
			Parser parser;
			GenMidCode genMidCode;
			GenMachineCode genMacCode;
			scanner.Scan();
			parser.Parse();
			genMidCode.GenCode();
			genMacCode.GenCode();
		}
};

void test_structural_facade(void)
{
	Compiler	oC;

	oC.Run();
}
