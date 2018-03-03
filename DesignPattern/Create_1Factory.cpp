/*
 * Factory.cpp
 *
 *  Created on: 2018年2月28日
 *      Author: liu_z
 *      例子：有一家生产处理器核的厂家，它只有一个工厂，能够生产两种型号的处理器核。客户需要什么样的处理器核，一定要显示地告诉生产工厂。下面给出一种实现方案。
 *      工厂模式: 主要缺点——要增加新的核类型时，就需要修改工厂类。这就违反了开放封闭原则：软件实体（类、模块、函数）可以扩展，但是不可修改。
 *      于是，工厂方法模式出现了。所谓工厂方法模式，是指定义一个用于创建对象的接口，让子类决定实例化哪一个类。Factory Method使一个类的实例化延迟到其子类。
 *
 */
#include <iostream>
using namespace std;


enum CTYPE {COREA, COREB};

class SingleCore
{
public:
    virtual void Show() = 0;
};

//单核A
class SingleCoreA: public SingleCore
{
public:
    void Show() { cout<<"SingleCore A"<<endl; }
};

//单核B
class SingleCoreB: public SingleCore
{
public:
    void Show() { cout<<"SingleCore B"<<endl; }
};

//唯一的工厂，可以生产两种型号的处理器核，在内部判断
class Factory
{
	public:
		SingleCore* CreateSingleCore(enum CTYPE ctype)
		{
			if(ctype == COREA) //工厂内部判断
				return new SingleCoreA(); //生产核A
			else if(ctype == COREB)
				return new SingleCoreB(); //生产核B
			else
				return NULL;
		}
};


void test_create_factory(void)
{
	SingleCore*	pSc = NULL;
	Factory	fc;
	enum CTYPE ct[] = {COREA, COREB, COREA, COREA, COREB};

	for ( int i = 0; i < 5; i++) {
		pSc = fc.CreateSingleCore(ct[i]);
		if (pSc)
			pSc->Show();
		else
			cout << "NULL" << endl;
	}
}

