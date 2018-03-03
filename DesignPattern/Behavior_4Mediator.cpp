/*
 * Behavior_4Mediator.cpp
 *
 *  Created on: 2018年3月2日
 *      Author: liu_z
 */
#include <iostream>
using namespace std;


class Mediator;

//抽象人
class Person
{
	protected:
		Mediator *m_mediator; //中介
	public:
		virtual void SetMediator(Mediator *mediator){} //设置中介
		virtual void SendMessage(string message) {}    //向中介发送信息
		virtual void GetMessage(string message) {}     //从中介获取信息
};

//抽象中介机构
class Mediator
{
	public:
		virtual void Send(string message, Person *person) {}
		virtual void SetA(Person *A) {}  //设置其中一方
		virtual void SetB(Person *B) {}
};
//租房者
class Renter: public Person
{
	public:
		void SetMediator(Mediator *mediator) { m_mediator = mediator; }
		void SendMessage(string message) { m_mediator->Send(message, this); }
		void GetMessage(string message) { cout<<"租房者收到信息:"<<message << endl; }
};
//房东
class Landlord: public Person
{
	public:
		void SetMediator(Mediator *mediator) { m_mediator = mediator; }
		void SendMessage(string message) { m_mediator->Send(message, this); }
		void GetMessage(string message) { cout<<"房东收到信息："<<message << endl; }
};
//房屋中介
class HouseMediator : public Mediator
{
	private:
		Person *m_A; //租房者
		Person *m_B; //房东
	public:
		HouseMediator(): m_A(0), m_B(0) {}
		void SetA(Person *A) { m_A = A; m_A->SetMediator(this);}
		void SetB(Person *B) { m_B = B; m_B->SetMediator(this);}
		void Send(string message, Person *person)
		{
			if(person == m_A) //租房者给房东发信息
				m_B->GetMessage(message); //房东收到信息
			else
				m_A->GetMessage(message);
		}
};


void test_behavior_Mediator(void)
{
	HouseMediator	HM;
	Landlord	*pL = NULL;
	Renter		*pR = NULL;

	pL = new Landlord();
	pR = new Renter();
	HM.SetA(pR);
	HM.SetB(pL);
	//pL->SetMediator(&HM);
	//pR->SetMediator(&HM);

	HM.Send("Hello!", pL);
	HM.Send("I don't rent.", pR);

	pL->GetMessage("Who");
	pL->SendMessage("房租：1000元/天。");
	pR->SendMessage("太贵了。");

}

