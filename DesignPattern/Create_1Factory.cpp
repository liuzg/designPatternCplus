/*
 * Factory.cpp
 *
 *  Created on: 2018��2��28��
 *      Author: liu_z
 *      ���ӣ���һ�������������˵ĳ��ң���ֻ��һ���������ܹ����������ͺŵĴ������ˡ��ͻ���Ҫʲô���Ĵ������ˣ�һ��Ҫ��ʾ�ظ��������������������һ��ʵ�ַ�����
 *      ����ģʽ: ��Ҫȱ�㡪��Ҫ�����µĺ�����ʱ������Ҫ�޸Ĺ����ࡣ���Υ���˿��ŷ��ԭ�����ʵ�壨�ࡢģ�顢������������չ�����ǲ����޸ġ�
 *      ���ǣ���������ģʽ�����ˡ���ν��������ģʽ����ָ����һ�����ڴ�������Ľӿڣ����������ʵ������һ���ࡣFactory Methodʹһ�����ʵ�����ӳٵ������ࡣ
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

//Ψһ�Ĺ������������������ͺŵĴ������ˣ����ڲ��ж�
class Factory
{
	public:
		SingleCore* CreateSingleCore(enum CTYPE ctype)
		{
			if(ctype == COREA) //�����ڲ��ж�
				return new SingleCoreA(); //������A
			else if(ctype == COREB)
				return new SingleCoreB(); //������B
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

