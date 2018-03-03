/*
 * Create_AbstractFactory.cpp
 *
 *  Created on: 2018年2月28日
 *      Author: liu_z
 *      例子：这家公司的技术不断进步，不仅可以生产单核处理器，也能生产多核处理器。现在简单工厂模式和工厂方法模式都鞭长莫及。抽象工厂模式登场了。
 *      它的定义为提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。
 *      具体这样应用，这家公司还是开设两个工厂，一个专门用来生产A型号的单核多核处理器，而另一个工厂专门用来生产B型号的单核多核处理器，下面给出实现的代码。
 */
#include <iostream>
using namespace std;

//单核
class SingleCore
{
	public:
		virtual void Show() = 0;
};

class SingleCoreA: public SingleCore
{
	public:
		void Show() { cout<<"Single Core A"<<endl; }
};

class SingleCoreB :public SingleCore
{
	public:
		void Show() { cout<<"Single Core B"<<endl; }
};

//多核
class MultiCore
{
	public:
    	virtual void Show() = 0;
};

class MultiCoreA : public MultiCore
{
public:
    void Show() { cout<<"Multi Core A"<<endl; }

};

class MultiCoreB : public MultiCore
{
	public:
		void Show() { cout<<"Multi Core B"<<endl; }
};

//工厂
class CoreFactory
{
	public:
		virtual SingleCore* CreateSingleCore() = 0;
		virtual MultiCore* CreateMultiCore() = 0;
};

//工厂A，专门用来生产A型号的处理器
class FactoryA :public CoreFactory
{
	public:
		SingleCore* CreateSingleCore() { return new SingleCoreA(); }
		MultiCore* CreateMultiCore() { return new MultiCoreA(); }
};

//工厂B，专门用来生产B型号的处理器
class FactoryB : public CoreFactory
{
	public:
		SingleCore* CreateSingleCore() { return new SingleCoreB(); }
		MultiCore* CreateMultiCore() { return new MultiCoreB(); }
};


void test_create_abstract_factory(void)
{
	SingleCore* pSc = NULL;
	MultiCore*  pMc = NULL;

	FactoryA	fa;
	FactoryB	fb;
	pSc = fa.CreateSingleCore();
	pSc->Show();
	pMc = fa.CreateMultiCore();
	pMc->Show();
	pSc = fb.CreateSingleCore();
	pSc->Show();
	pSc = fa.CreateSingleCore();
	pSc->Show();
	pMc = fa.CreateMultiCore();
	pMc->Show();
	pSc = fa.CreateSingleCore();
	pSc->Show();
	pSc = fb.CreateSingleCore();
	pSc->Show();
	pMc = fb.CreateMultiCore();
	pMc->Show();
}
