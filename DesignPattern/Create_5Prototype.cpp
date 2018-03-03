/*
 * Create_5Prototype.cpp
 *
 *  Created on: 2018年3月2日
 *  Href:	http://blog.csdn.net/wuzhekai1985/article/details/6667020
 *      Author: liu_z
 *      用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。其中有一个词很重要，那就是拷贝。可以说，拷贝是原型模式的精髓所在。
 *      原型模式实现的关键就是实现Clone函数，对于C++来说，其实就是拷贝构造函数，需实现深拷贝，
 *
 */
#include <iostream>
#include <mem.h>
using namespace std;


//父类
class Resume
{
	protected:
		char *name;

	public:
		Resume() {}
		virtual ~Resume() {}
		virtual Resume* Clone() { return NULL; }
		virtual void Set(char *n) {}
		virtual void Show() {}
};


class ResumeA : public Resume
{
	public:
		ResumeA(const char *str);  //构造函数
		ResumeA(const ResumeA &r); //拷贝构造函数
		~ResumeA();                //析构函数
		ResumeA* Clone();          //克隆，关键所在
		void Show();               //显示内容
};

ResumeA::ResumeA(const char *str)
{
    if(str == NULL) {
        name = new char[1];
        name[0] = '\0';
    }
    else {
        name = new char[strlen(str)+1];
        strcpy(name, str);
    }
}

ResumeA::~ResumeA() { delete [] name;}

ResumeA::ResumeA(const ResumeA &r) {
    name = new char[strlen(r.name)+1];
    strcpy(name, r.name);
}

ResumeA* ResumeA::Clone() {
    return new ResumeA(*this);
}

void ResumeA::Show() {
    cout<<"ResumeA name : "<<name<<endl;
}

class ResumeB : public Resume
{
	protected:
		int m_i;

	public:
		ResumeB(const char *str);  //构造函数
		ResumeB(const ResumeB &r); //拷贝构造函数
		~ResumeB();                //析构函数
		ResumeB* Clone();          //克隆，关键所在
		void Show();               //显示内容
};

ResumeB::ResumeB(const char *str)
{
    if(str == NULL) {
        name = new char[1];
        name[0] = '\0';
    }
    else {
        name = new char[strlen(str)+1];
        strcpy(name, str);
    }
    m_i = 0;
}

ResumeB::~ResumeB() { delete [] name;}

ResumeB::ResumeB(const ResumeB &r) {
    name = new char[strlen(r.name)+1];
    strcpy(name, r.name);
    m_i = r.m_i;
}

ResumeB* ResumeB::Clone() {
    return new ResumeB(*this);
}

void ResumeB::Show() {
    cout<<"ResumeB name : "<<name<< " and m_i = " << m_i << endl;
}



void test_create_prototype(void)
{
    Resume *r1 = new ResumeA("A");
    Resume *r2 = new ResumeB("B");
    Resume *r3 = r1->Clone();
    Resume *r4 = r2->Clone();
    r1->Show(); r2->Show();

    //删除r1,r2
    delete r1; delete r2;
    r1 = r2 = NULL;

    //深拷贝所以对r3,r4无影响
    r3->Show(); r4->Show();
    delete r3; delete r4;

    r3 = r4 = NULL;
}

