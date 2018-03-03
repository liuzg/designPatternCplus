/*
 * Structural_Facade.cpp
 *
 *  Created on: 2018��3��2��
 *  href: http://blog.csdn.net/wuzhekai1985/article/details/6667564
 *      Author: liu_z
 *      �����ص�:��1�����Կͻ�������ϵͳ�������������˿ͻ�����Ķ������Ŀ��ʹ����ϵͳʹ���������ӷ��㡣
 *      ��2����ʵ������ϵͳ��ͻ�֮�������Ϲ�ϵ������ϵͳ�ڲ��Ĺ�����������ǽ���ϵġ�
 *      ��3�����Ӧ����Ҫ����������������ʹ����ϵͳ�ࡣ
 *
 */
#include <iostream>
using namespace std;


class Scanner
{
	public:
		void Scan() { cout<<"�ʷ�����"<<endl; }
};

class Parser
{
	public:
		void Parse() { cout<<"�﷨����"<<endl; }
};

class GenMidCode
{
	public:
		void GenCode() { cout<<"�����м����"<<endl; }
};

class GenMachineCode
{
	public:
		void GenCode() { cout<<"����������"<<endl;}
};

//�߲�ӿ�
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
