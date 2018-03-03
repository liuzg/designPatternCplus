/*
 * Create_4-2Singleton.cpp
 *
 *  Created on: 2018年3月1日
 *      Author: liu_z
 *      注意：单例中又有子类的方式，当前写法，生成一个子类后，不会生成另一个。
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
	protected: //必须为保护，如果是私有属性，子类无法访问父类的构造函数
		Singleton2() {}
		virtual ~Singleton2(){ if (!singleton) { delete singleton; singleton = NULL;}}
	private:
		static Singleton2 *singleton; //唯一实例的指针
};


//SingletonA.h
//#pragma once
//#include "Singleton.h"
class SingletonA: public Singleton2
{
    friend class Singleton2; //必须为友元类，否则父类无法访问子类的构造函数
	public:
		void Show() { cout<<"SingletonA"<<endl; }
	private:   //为保护属性，这样外界无法通过构造函数进行实例化
		SingletonA() {}
};

//SingletonB.h
//#pragma once
//#include "Singleton.h"
class SingletonB: public Singleton2
{
    friend class Singleton2; //必须为友元类，否则父类无法访问子类的构造函数
public:
    void Show(){ cout<<"SingletonB"<<endl; }
private:  //为保护属性，这样外界无法通过构造函数进行实例化
    SingletonB() {}
};

pthread_mutex_t mutex2;//互斥锁

Singleton2* Singleton2::singleton = NULL;
Singleton2* Singleton2::GetInstance(const char* name)
{
    if(singleton == NULL)
    {
    	pthread_mutex_lock(&mutex2);         //加锁
        if(strcmp(name, "SingletonA") == 0)
            singleton = new SingletonA();
        else if(strcmp(name,"SingletonB") == 0)
            singleton = new SingletonB();
        else
            singleton = new Singleton2();
        pthread_mutex_unlock(&mutex2);//解锁.
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



