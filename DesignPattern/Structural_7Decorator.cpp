/*
 * Structural_7Decorator.cpp
 *
 *  Created on: 2018年3月2日
 *  href: http://blog.csdn.net/wuzhekai1985/article/details/6672614
 *      Author: liu_z
 */
#include <iostream>
using namespace std;

//公共抽象类
class Phone
{
	public:
		Phone() {}
		virtual ~Phone() {}
		virtual void ShowDecorate() {}
};

//具体的手机类
class iPhone : public Phone
{
	private:
		string m_name; //手机名称
	public:
		iPhone(string name): m_name(name){}
		~iPhone() {}
		void ShowDecorate() { cout<<m_name<<"的装饰"<<endl;}
};

//具体的手机类
class NokiaPhone : public Phone
{
	private:
		string m_name;
	public:
		NokiaPhone(string name): m_name(name){}
		~NokiaPhone() {}
		void ShowDecorate() { cout<<m_name<<"的装饰"<<endl;}
};

//装饰类
class DecoratorPhone : public Phone
{
	private:
		Phone *m_phone;  //要装饰的手机
	public:
		DecoratorPhone(Phone *phone): m_phone(phone) {}
		virtual void ShowDecorate() { m_phone->ShowDecorate(); }
};

//具体的装饰类
class DecoratorPhoneA : public DecoratorPhone
{
	public:
		DecoratorPhoneA(Phone *phone) : DecoratorPhone(phone) {}
		void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
	private:
		void AddDecorate() { cout<<"增加挂件"<<endl; } //增加的装饰
};

//具体的装饰类
class DecoratorPhoneB : public DecoratorPhone
{
	public:
		DecoratorPhoneB(Phone *phone) : DecoratorPhone(phone) {}
		void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
	private:
		void AddDecorate() { cout<<"屏幕贴膜"<<endl; } //增加的装饰
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
    Phone *dpa = new DecoratorPhoneA(iphone); //装饰，增加挂件
    Phone *dpb = new DecoratorPhoneB(dpa);    //装饰，屏幕贴膜
    dpb->ShowDecorate();
    delete dpa;
    delete dpb;
    delete iphone;
}
