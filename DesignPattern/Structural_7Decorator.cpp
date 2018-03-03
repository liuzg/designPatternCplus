/*
 * Structural_7Decorator.cpp
 *
 *  Created on: 2018��3��2��
 *  href: http://blog.csdn.net/wuzhekai1985/article/details/6672614
 *      Author: liu_z
 */
#include <iostream>
using namespace std;

//����������
class Phone
{
	public:
		Phone() {}
		virtual ~Phone() {}
		virtual void ShowDecorate() {}
};

//������ֻ���
class iPhone : public Phone
{
	private:
		string m_name; //�ֻ�����
	public:
		iPhone(string name): m_name(name){}
		~iPhone() {}
		void ShowDecorate() { cout<<m_name<<"��װ��"<<endl;}
};

//������ֻ���
class NokiaPhone : public Phone
{
	private:
		string m_name;
	public:
		NokiaPhone(string name): m_name(name){}
		~NokiaPhone() {}
		void ShowDecorate() { cout<<m_name<<"��װ��"<<endl;}
};

//װ����
class DecoratorPhone : public Phone
{
	private:
		Phone *m_phone;  //Ҫװ�ε��ֻ�
	public:
		DecoratorPhone(Phone *phone): m_phone(phone) {}
		virtual void ShowDecorate() { m_phone->ShowDecorate(); }
};

//�����װ����
class DecoratorPhoneA : public DecoratorPhone
{
	public:
		DecoratorPhoneA(Phone *phone) : DecoratorPhone(phone) {}
		void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
	private:
		void AddDecorate() { cout<<"���ӹҼ�"<<endl; } //���ӵ�װ��
};

//�����װ����
class DecoratorPhoneB : public DecoratorPhone
{
	public:
		DecoratorPhoneB(Phone *phone) : DecoratorPhone(phone) {}
		void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
	private:
		void AddDecorate() { cout<<"��Ļ��Ĥ"<<endl; } //���ӵ�װ��
};

void test_structural_decorator(void)
{
	DecoratorPhone *pDP = NULL;
	DecoratorPhoneA	dpa1(new iPhone("Mi2"));
	pDP = &dpa1;
	pDP->ShowDecorate();
	pDP = new DecoratorPhoneB(pDP);
	pDP->ShowDecorate();

	cout << endl;
    Phone *iphone = new NokiaPhone("6300");
    Phone *dpa = new DecoratorPhoneA(iphone); //װ�Σ����ӹҼ�
    Phone *dpb = new DecoratorPhoneB(dpa);    //װ�Σ���Ļ��Ĥ
    dpb->ShowDecorate();
    delete dpa;
    delete dpb;
    delete iphone;
}
