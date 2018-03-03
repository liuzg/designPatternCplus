/*
 * Structural_6Bridge.cpp
 *
 *  Created on: 2018��3��2��
 *      Author: liu_z
 */
#include <iostream>
using namespace std;

//����ϵͳ
class OS
{
	public:
		virtual void InstallOS_Imp() {}
		virtual ~OS(){};
};

class WindowOS: public OS
{
	public:
		void InstallOS_Imp() { cout<<"��װWindow����ϵͳ"<<endl; }
};

class LinuxOS: public OS
{
	public:
		void InstallOS_Imp() { cout<<"��װLinux����ϵͳ"<<endl; }
};

class UnixOS: public OS
{
	public:
		void InstallOS_Imp() { cout<<"��װUnix����ϵͳ"<<endl; }
};

//�����
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
