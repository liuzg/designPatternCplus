/*
 * Create_FactoryMethod.cpp
 *
 *  Created on: 2018年2月28日
 *      Author: liu_z
 *      例子： 这家生产处理器核的产家赚了不少钱，于是决定再开设一个工厂专门用来生产B型号的单核，而原来的工厂专门用来生产A型号的单核。
 *      这时，客户要做的是找好工厂，比如要A型号的核，就找A工厂要；否则找B工厂要，不再需要告诉工厂具体要什么型号的处理器核了。
 *      所谓工厂方法模式，是指定义一个用于创建对象的接口，让子类决定实例化哪一个类。Factory Method使一个类的实例化延迟到其子类。
 *      缺点：每增加一种产品，就需要增加一个对象的工厂。如果这家公司发展迅速，推出了很多新的处理器核，那么就要开设相应的新工厂。
 *          在C++实现中，就是要定义一个个的工厂类。显然，相比简单工厂模式，工厂方法模式需要更多的类定义。
 */
#include <iostream>
using namespace std;


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

class Factory
{
	public:
		virtual SingleCore* CreateSingleCore() = 0;
};

//生产A核的工厂
class FactoryA: public Factory
{
	public:
		SingleCoreA* CreateSingleCore() { return new SingleCoreA; }
};

//生产B核的工厂
class FactoryB: public Factory
{
	public:
		SingleCoreB* CreateSingleCore() { return new SingleCoreB; }
};


void test_create_factory_method(void)
{
	SingleCore* pSc = NULL;

	// enum CTYPE ct[] = {COREA, COREB, COREA, COREA, COREB};

	FactoryA	fa;
	FactoryB	fb;
	pSc = fa.CreateSingleCore();
	pSc->Show();
	pSc = fb.CreateSingleCore();
	pSc->Show();
	pSc = fa.CreateSingleCore();
	pSc->Show();
	pSc = fa.CreateSingleCore();
	pSc->Show();
	pSc = fb.CreateSingleCore();
	pSc->Show();
}
