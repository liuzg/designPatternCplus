/*
 * Create_AbstractFactory.cpp
 *
 *  Created on: 2018��2��28��
 *      Author: liu_z
 *      ���ӣ���ҹ�˾�ļ������Ͻ��������������������˴�������Ҳ��������˴����������ڼ򵥹���ģʽ�͹�������ģʽ���޳�Ī�������󹤳�ģʽ�ǳ��ˡ�
 *      ���Ķ���Ϊ�ṩһ������һϵ����ػ��໥��������Ľӿڣ�������ָ�����Ǿ�����ࡣ
 *      ��������Ӧ�ã���ҹ�˾���ǿ�������������һ��ר����������A�ͺŵĵ��˶�˴�����������һ������ר����������B�ͺŵĵ��˶�˴��������������ʵ�ֵĴ��롣
 */
#include <iostream>
using namespace std;

//����
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

//���
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

//����
class CoreFactory
{
	public:
		virtual SingleCore* CreateSingleCore() = 0;
		virtual MultiCore* CreateMultiCore() = 0;
};

//����A��ר����������A�ͺŵĴ�����
class FactoryA :public CoreFactory
{
	public:
		SingleCore* CreateSingleCore() { return new SingleCoreA(); }
		MultiCore* CreateMultiCore() { return new MultiCoreA(); }
};

//����B��ר����������B�ͺŵĴ�����
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
