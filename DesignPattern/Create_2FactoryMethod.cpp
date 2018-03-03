/*
 * Create_FactoryMethod.cpp
 *
 *  Created on: 2018��2��28��
 *      Author: liu_z
 *      ���ӣ� ��������������˵Ĳ���׬�˲���Ǯ�����Ǿ����ٿ���һ������ר����������B�ͺŵĵ��ˣ���ԭ���Ĺ���ר����������A�ͺŵĵ��ˡ�
 *      ��ʱ���ͻ�Ҫ�������Һù���������ҪA�ͺŵĺˣ�����A����Ҫ��������B����Ҫ��������Ҫ���߹�������Ҫʲô�ͺŵĴ��������ˡ�
 *      ��ν��������ģʽ����ָ����һ�����ڴ�������Ľӿڣ����������ʵ������һ���ࡣFactory Methodʹһ�����ʵ�����ӳٵ������ࡣ
 *      ȱ�㣺ÿ����һ�ֲ�Ʒ������Ҫ����һ������Ĺ����������ҹ�˾��չѸ�٣��Ƴ��˺ܶ��µĴ������ˣ���ô��Ҫ������Ӧ���¹�����
 *          ��C++ʵ���У�����Ҫ����һ�����Ĺ����ࡣ��Ȼ����ȼ򵥹���ģʽ����������ģʽ��Ҫ������ඨ�塣
 */
#include <iostream>
using namespace std;


class SingleCore
{
public:
    virtual void Show() = 0;
};

//����A
class SingleCoreA: public SingleCore
{
public:
    void Show() { cout<<"SingleCore A"<<endl; }
};

//����B
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

//����A�˵Ĺ���
class FactoryA: public Factory
{
	public:
		SingleCoreA* CreateSingleCore() { return new SingleCoreA; }
};

//����B�˵Ĺ���
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
