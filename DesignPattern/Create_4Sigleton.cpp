/*
 * Create_4Sigleton.cpp
 *
 *  Created on: 2018年3月1日
 *  href:	http://blog.csdn.net/wuzhekai1985/article/details/6665869
 *      Author: liu_z
 *      增加了线程锁的测试。
 */
#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;


//Singleton.h
class Singleton
{
	public:
		static Singleton* GetInstance();
		void show(void) { cout << "This is singleton test." << endl; }
	private:
		Singleton() {}
		static Singleton *singleton;
};

pthread_mutex_t mutex;//互斥锁
//Singleton.cpp
Singleton* Singleton::singleton = NULL;
Singleton* Singleton::GetInstance()
{
	//pthread_mutex_lock(&mutex);

	if(singleton == NULL)
        singleton = new Singleton();

	//pthread_mutex_unlock(&mutex);

    return singleton;
}

void* fuc1(void *arg)
{
	cout << "In thread 1:======\n";
	Singleton *pSgl = Singleton::GetInstance();
	pSgl->show();
	//sleep(10);
	cout << "Out thread 1:======\n";

	return (void*)0;
}

void* fuc2(void *arg)
{
	cout << "In thread 2:======\n";
	Singleton *pSgl = Singleton::GetInstance();
	pSgl->show();
	cout << "Out thread 2:======\n";
	pthread_exit((void*)("fuc2 over.\n")); //使用了该函数，下面的返回值就无效了。

	return (void*)5;
}

void test_create_singleton(void)
{
	//void*	pStr = NULL;
	int		ret = 3;
	pthread_t tid1, tid2;
	pthread_mutex_init(&mutex, NULL);

	pthread_create(&tid1, NULL, fuc1, NULL);
	pthread_create(&tid2, NULL, fuc2, NULL);
	pthread_join(tid2, (void**)&ret);

	cout << (char*)ret << "\n";

	pthread_mutex_destroy(&mutex);

	system("pause");
	cout << "out main.\n";
}

