/*
 * Structural_6Bridge.cpp
 *
 *  Created on: 2018年3月2日
 *      Author: liu_z
 */
#include <iostream>
using namespace std;

//操作系统
class OS
{
	public:
		virtual void InstallOS_Imp() {}
		virtual ~OS(){};
};

class WindowOS: public OS
{
	public:
		void InstallOS_Imp() { cout<<"安装Window操作系统"<<endl; }
};

class LinuxOS: public OS
{
	public:
		void InstallOS_Imp() { cout<<"安装Linux操作系统"<<endl; }
};

class UnixOS: public OS
{
	public:
		void InstallOS_Imp() { cout<<"安装Unix操作系统"<<endl; }
};

//计算机
class Computer
{
	public:
		virtual void InstallOS(OS *os) {}
};

class DellComputer: public Computer
{
	public:
		void InstallOS(OS *os) { os->InstallOS_Imp(); }
};

class AppleComputer: public Computer
{
	public:
		void InstallOS(OS *os) { os->InstallOS_Imp(); }
};

class HPComputer: public Computer
{
	public:
		void InstallOS(OS *os) { os->InstallOS_Imp(); }
};


void test_structural_bridge(void)
{
	OS			*pOs = NULL;
	Computer	*pC = NULL;

	DellComputer	pCDell;

	pOs = new WindowOS();
	pC = &pCDell;
	pC->InstallOS(pOs);
	delete pOs;

	pOs = new LinuxOS();
	pC->InstallOS(pOs);
	delete pOs;

	HPComputer	pcHP;
	pC = &pcHP;
	pOs = new UnixOS();
	pC->InstallOS(pOs);
	delete pOs;
}
