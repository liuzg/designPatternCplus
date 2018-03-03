/*
 * Create_4-2Singleton.cpp
 *
 *  Created on: 2018��3��1��
 *      Author: liu_z
 *      ע�⣺��������������ķ�ʽ����ǰд��������һ������󣬲���������һ����
 */
//#pragma once
#include <iostream>
#include <mem.h>
#include <pthread.h>
using namespace std;

class Singleton2
{
	public:
		static Singleton2* GetInstance(const char* name);
		virtual void Show() {}
	protected: //����Ϊ�����������˽�����ԣ������޷����ʸ���Ĺ��캯��
		Singleton2() {}
		virtual ~Singleton2(){ if (!singleton) { delete singleton; singleton = NULL;}}
	private:
		static Singleton2 *singleton; //Ψһʵ����ָ��
};


//SingletonA.h
//#pragma once
//#include "Singleton.h"
class SingletonA: public Singleton2
{
    friend class Singleton2; //����Ϊ��Ԫ�࣬�������޷���������Ĺ��캯��
	public:
		void Show() { cout<<"SingletonA"<<endl; }
	private:   //Ϊ�������ԣ���������޷�ͨ�����캯������ʵ����
		SingletonA() {}
};

//SingletonB.h
//#pragma once
//#include "Singleton.h"
class SingletonB: public Singleton2
{
    friend class Singleton2; //����Ϊ��Ԫ�࣬�������޷���������Ĺ��캯��
public:
    void Show(){ cout<<"SingletonB"<<endl; }
private:  //Ϊ�������ԣ���������޷�ͨ�����캯������ʵ����
    SingletonB() {}
};

pthread_mutex_t mutex2;//������

Singleton2* Singleton2::singleton = NULL;
Singleton2* Singleton2::GetInstance(const char* name)
{
    if(singleton == NULL)
    {
    	pthread_mutex_lock(&mutex2);         //����
        if(strcmp(name, "SingletonA") == 0)
            singleton = new SingletonA();
        else if(strcmp(name,"SingletonB") == 0)
            singleton = new SingletonB();
        else
            singleton = new Singleton2();
        pthread_mutex_unlock(&mutex2);//����.
    }
    return singleton;
}


void test_create_singleton_subclass(void)
{
	pthread_mutex_init(&mutex2, NULL);
	if (1){
		Singleton2 *st = Singleton2::GetInstance("SingletonA");
		st->Show();
	}

	Singleton2 *st = Singleton2::GetInstance("SingletonA");
	st->Show();

    Singleton2 *st2 =  Singleton2::GetInstance("SingletonB");
    st2->Show();
}



