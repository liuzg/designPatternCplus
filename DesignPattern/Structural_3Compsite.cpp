/*
 * Structural_3Compsite.cpp
 *
 *  Created on: 2018��3��2��
 *  href: http://blog.csdn.net/wuzhekai1985/article/details/6667564
 *      Author: liu_z
 *      ��������ϳ����νṹ�Ա�ʾ������-���塱�Ĳ�νṹ�����ʹ���û��Ե����������϶����ʹ�þ���һ���ԡ�
 *      ���ڴ�й©����Ҫ�����ӵ�Del�У�����erase��delete��
 */
#include <iostream>
#include <list>
#include <typeinfo>
using namespace std;

class Company
{
	public:
		Company(string name) { m_name = name; }
		virtual ~Company(){}
		virtual void Add(Company *pCom){}
		virtual void Del(string name){}
		virtual void Show(int depth) {}
		virtual Company* GetClassType(void) { return this; }
		string	GetName(void) { return m_name; }
	protected:
		string m_name;
};

//���幫˾
class ConcreteCompany : public Company
{
	public:
		ConcreteCompany(string name): Company(name) {}
		virtual ~ConcreteCompany() {}
		virtual ConcreteCompany* GetClassType(void) { return this; }
		void Add(Company *pCom) { m_listCompany.push_back(pCom); } //λ�������м䣬������������
		virtual void Del(string name){
			list<Company *>::iterator iter = m_listCompany.begin();
			if( 0 == name.compare(GetName()) )
					cout << "It's me! " << GetName() << endl;
			for(; iter != m_listCompany.end(); iter++) {//��ʾ�²���
//				if( 0 == name.compare((*iter)->m_name) ){
					Company *pCom = *iter;
					if( typeid(*pCom->GetClassType()) == typeid(ConcreteCompany)) {
//						pCom->Del()
						cout << "This is ConcreteCompany class." << endl;
						cout << "class name = " << pCom->GetName() << endl;
						pCom->Del(name);
					}
					else{
						cout << "This isn't ConcreteCompany class." << endl;
						cout << "class name = " << pCom->GetName() << endl;
					}
//					m_listCompany.erase(iter);
//					delete pCom;
//				}
			}
		}

		void Show(int depth)
		{
			for(int i = 0;i < depth; i++)
				cout<<"-";
			cout<<m_name<<endl;
			list<Company *>::iterator iter=m_listCompany.begin();
			for(; iter != m_listCompany.end(); iter++) //��ʾ�²���
				(*iter)->Show(depth + 2);
		}
	private:
		list<Company *> m_listCompany;
};

//����Ĳ��ţ�����
class FinanceDepartment : public Company
{
	public:
		FinanceDepartment(string name):Company(name){}
		virtual ~FinanceDepartment() {}
		virtual FinanceDepartment* GetClassType(void) { return this; }
		virtual void Show(int depth) //ֻ����ʾ��������Ӻ�������Ϊ����Ҷ���
		{
			for(int i = 0; i < depth; i++)
				cout<<"-";
			cout<<m_name<<endl;
		}
};

//����Ĳ��ţ�������Դ��
class HRDepartment :public Company
{
	public:
		HRDepartment(string name):Company(name){}
		virtual ~HRDepartment() {}
		virtual HRDepartment* GetClassType(void) { return this; }
		virtual void Show(int depth) //ֻ����ʾ��������Ӻ�������Ϊ����Ҷ���
		{
			for(int i = 0; i < depth; i++)
				cout<<"-";
			cout<<m_name<<endl;
		}
};

void test_structural_composite(void)
{
	ConcreteCompany	oCorp("֪ѧ��");
	oCorp.Add(new FinanceDepartment("֪ѧ�� ����"));
	oCorp.Add(new HRDepartment("֪ѧ�� ����"));

	ConcreteCompany	oCorp1("֪ѧ�� �Ϻ��ֹ�˾");
	oCorp1.Add(new FinanceDepartment("֪ѧ�� �Ϻ�����"));
	oCorp1.Add(new HRDepartment("֪ѧ�� �Ϻ�����"));

	oCorp.Add(&oCorp1);

	oCorp.Show(3);

	oCorp.Del("֪ѧ�� �Ϻ��ֹ�˾");
}

