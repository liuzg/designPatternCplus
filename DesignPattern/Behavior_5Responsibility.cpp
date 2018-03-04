/*
 * Behavior_5Responsibility.cpp
 *
 *  Created on: 2018��3��3��
 *  href: http://blog.csdn.net/wuzhekai1985/article/details/6673892
 *      Author: liu_z
 *      ְ����ģʽ��ʹ��������л��ᴦ�����󣬴Ӷ���������ķ����ߺͽ�����֮�����Ϲ�ϵ��
 *      ����Щ��������һ���������������������ݸ�����ֱ����һ����������Ϊֹ����˼��ܼ򵥣�����Ա��Ҫ���н��
 *      ��˾�Ĺ�����һ�����������ܾ����ܼࡢ�������һ��Ա��Ҫ���н��Ӧ�������ܵľ������룬�����н�������ھ����ְȨ�ڣ�
 *      ��ô�������ֱ����׼�����������Ͻ����ܼࡣ�ܼ�Ĵ���ʽҲһ�����ܾ�����Դ�����������
 *      ����ǵ��͵�ְ����ģʽ������Ĵ����γ���һ������ֱ����һ������������
 */
#include <iostream>
using namespace std;


//���������
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

//����
class CommonManager: public Manager
{
	public:
		CommonManager(Manager *manager, string name):Manager(manager,name) {}
		void DealWithRequest(string name, int num)
		{
			if(num < 500) //����ְȨ֮��
			{
				cout<<"����"<<m_name<<"��׼"<<name<<"��н"<<num<<"Ԫ"<<endl<<endl;
			}
			else
			{
				cout<<"����"<<m_name<<"�޷����������ܼദ��"<<endl;
				m_manager->DealWithRequest(name, num);
			}
		}
};

//�ܼ�
class Majordomo: public Manager
{
	public:
		Majordomo(Manager *manager, string name):Manager(manager,name) {}
		void DealWithRequest(string name, int num)
		{
			if(num < 1000) //�ܼ�ְȨ֮��
			{
				cout<<"�ܼ�"<<m_name<<"��׼"<<name<<"��н"<<num<<"Ԫ"<<endl<<endl;
			}
			else
			{
				cout<<"�ܼ�"<<m_name<<"�޷����������ܾ�����"<<endl;
				m_manager->DealWithRequest(name, num);
			}
		}
};

//�ܾ���
class GeneralManager: public Manager
{
	public:
		GeneralManager(Manager *manager, string name):Manager(manager,name) {}
		void DealWithRequest(string name, int num)  //�ܾ�����Դ�����������
		{
			cout<<"�ܾ���"<<m_name<<"��׼"<<name<<"��н"<<num<<"Ԫ"<<endl<<endl;
		}
};

void test_behavior_Reponsibility(void)
{
	Manager		*pG = new GeneralManager(NULL, "����");
	Manager		*pT = new Majordomo(pG, "�Ƹ���");
	Manager		*pC = new CommonManager(pT, "�⾭��");

	pC->DealWithRequest("С��", 2500);
	pC->DealWithRequest("С��", 500);
	pC->DealWithRequest("С��", 300);

	delete pG; delete pT; delete pC;
}



