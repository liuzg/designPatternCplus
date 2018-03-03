/*
 * Behavior_4Mediator.cpp
 *
 *  Created on: 2018��3��2��
 *      Author: liu_z
 */
#include <iostream>
using namespace std;


class Mediator;

//������
class Person
{
	protected:
		Mediator *m_mediator; //�н�
	public:
		virtual void SetMediator(Mediator *mediator){} //�����н�
		virtual void SendMessage(string message) {}    //���н鷢����Ϣ
		virtual void GetMessage(string message) {}     //���н��ȡ��Ϣ
};

//�����н����
class Mediator
{
	public:
		virtual void Send(string message, Person *person) {}
		virtual void SetA(Person *A) {}  //��������һ��
		virtual void SetB(Person *B) {}
};
//�ⷿ��
class Renter: public Person
{
	public:
		void SetMediator(Mediator *mediator) { m_mediator = mediator; }
		void SendMessage(string message) { m_mediator->Send(message, this); }
		void GetMessage(string message) { cout<<"�ⷿ���յ���Ϣ:"<<message << endl; }
};
//����
class Landlord: public Person
{
	public:
		void SetMediator(Mediator *mediator) { m_mediator = mediator; }
		void SendMessage(string message) { m_mediator->Send(message, this); }
		void GetMessage(string message) { cout<<"�����յ���Ϣ��"<<message << endl; }
};
//�����н�
class HouseMediator : public Mediator
{
	private:
		Person *m_A; //�ⷿ��
		Person *m_B; //����
	public:
		HouseMediator(): m_A(0), m_B(0) {}
		void SetA(Person *A) { m_A = A; m_A->SetMediator(this);}
		void SetB(Person *B) { m_B = B; m_B->SetMediator(this);}
		void Send(string message, Person *person)
		{
			if(person == m_A) //�ⷿ�߸���������Ϣ
				m_B->GetMessage(message); //�����յ���Ϣ
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
	pL->SendMessage("���⣺1000Ԫ/�졣");
	pR->SendMessage("̫���ˡ�");

}

