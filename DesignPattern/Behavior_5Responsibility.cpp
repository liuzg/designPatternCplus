/*
 * Behavior_5Responsibility.cpp
 *
 *  Created on: 2018年3月3日
 *  href: http://blog.csdn.net/wuzhekai1985/article/details/6673892
 *      Author: liu_z
 *      职责链模式：使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。
 *      将这些对象连成一条链，并沿着这条链传递该请求，直到有一个对象处理它为止。其思想很简单，考虑员工要求加薪。
 *      公司的管理者一共有三级，总经理、总监、经理，如果一个员工要求加薪，应该向主管的经理申请，如果加薪的数量在经理的职权内，
 *      那么经理可以直接批准，否则将申请上交给总监。总监的处理方式也一样，总经理可以处理所有请求。
 *      这就是典型的职责链模式，请求的处理形成了一条链，直到有一个对象处理请求。
 */
#include <iostream>
using namespace std;


//抽象管理者
class Manager
{
	protected:
		Manager *m_manager;
		string m_name;
	public:
		Manager(Manager *manager, string name):m_manager(manager), m_name(name){}
		virtual void DealWithRequest(string name, int num)  {}
		virtual ~Manager(){}
};

//经理
class CommonManager: public Manager
{
	public:
		CommonManager(Manager *manager, string name):Manager(manager,name) {}
		void DealWithRequest(string name, int num)
		{
			if(num < 500) //经理职权之内
			{
				cout<<"经理"<<m_name<<"批准"<<name<<"加薪"<<num<<"元"<<endl<<endl;
			}
			else
			{
				cout<<"经理"<<m_name<<"无法处理，交由总监处理"<<endl;
				m_manager->DealWithRequest(name, num);
			}
		}
};

//总监
class Majordomo: public Manager
{
	public:
		Majordomo(Manager *manager, string name):Manager(manager,name) {}
		void DealWithRequest(string name, int num)
		{
			if(num < 1000) //总监职权之内
			{
				cout<<"总监"<<m_name<<"批准"<<name<<"加薪"<<num<<"元"<<endl<<endl;
			}
			else
			{
				cout<<"总监"<<m_name<<"无法处理，交由总经理处理"<<endl;
				m_manager->DealWithRequest(name, num);
			}
		}
};

//总经理
class GeneralManager: public Manager
{
	public:
		GeneralManager(Manager *manager, string name):Manager(manager,name) {}
		void DealWithRequest(string name, int num)  //总经理可以处理所有请求
		{
			cout<<"总经理"<<m_name<<"批准"<<name<<"加薪"<<num<<"元"<<endl<<endl;
		}
};

void test_behavior_Reponsibility(void)
{
	Manager		*pG = new GeneralManager(NULL, "刘总");
	Manager		*pT = new Majordomo(pG, "黄副总");
	Manager		*pC = new CommonManager(pT, "吴经理");

	pC->DealWithRequest("小王", 2500);
	pC->DealWithRequest("小章", 500);
	pC->DealWithRequest("小午", 300);

	delete pG; delete pT; delete pC;
}



