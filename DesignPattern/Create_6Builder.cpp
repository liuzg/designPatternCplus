/*
 * Create_6Builder.cpp
 *
 *  Created on: 2018��3��2��
 *  href: http://blog.csdn.net/wuzhekai1985/article/details/6667467
 *      Author: liu_z
 *      ������ģʽ�Ķ��彫һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ��DP����
 *      �������ģʽ������һ���ܺõ����ӡ�������С�ˣ�һ���轨��6�����֣�ͷ�������塢�����֡����ҽš�
 *      �빤��ģʽ��ͬ��������ģʽ���ڵ����ߵĿ�����һ��һ�������Ʒ�ġ�����С�˾����ڿ�����һ������������ġ�
 *      ������ģʽ�����ܸ���ϸ�Ŀ��ƹ������̣��Ӷ��ܸ���ϸ�Ŀ������ò�Ʒ���ڲ��ṹ��
 */
#include <iostream>
using namespace std;


class Builder
{
	public:
		virtual void BuildHead() {}
		virtual void BuildBody() {}
		virtual void BuildLeftArm(){}
		virtual void BuildRightArm() {}
		virtual void BuildLeftLeg() {}
		virtual void BuildRightLeg() {}
		virtual ~Builder(){}
};

//��������
class ThinBuilder : public Builder
{
	public:
		void BuildHead() { cout<<"build thin body"<<endl; }
		void BuildBody() { cout<<"build thin head"<<endl; }
		void BuildLeftArm() { cout<<"build thin leftarm"<<endl; }
		void BuildRightArm() { cout<<"build thin rightarm"<<endl; }
		void BuildLeftLeg() { cout<<"build thin leftleg"<<endl; }
		void BuildRightLeg() { cout<<"build thin rightleg"<<endl; }
};

//��������
class FatBuilder : public Builder
{
	public:
		void BuildHead() { cout<<"build fat body"<<endl; }
		void BuildBody() { cout<<"build fat head"<<endl; }
		void BuildLeftArm() { cout<<"build fat leftarm"<<endl; }
		void BuildRightArm() { cout<<"build fat rightarm"<<endl; }
		void BuildLeftLeg() { cout<<"build fat leftleg"<<endl; }
		void BuildRightLeg() { cout<<"build fat rightleg"<<endl; }
};

//�����ָ�ӹ�
class Director
{
	private:
		Builder *m_pBuilder;

	public:
		Director(Builder *builder) { m_pBuilder = builder; }
		void Set_Director(Builder *builder) {
			if (m_pBuilder)
				delete m_pBuilder;
			m_pBuilder = builder;
		}
		~Director(){ if (m_pBuilder) delete m_pBuilder; }

		void Create(){
			m_pBuilder->BuildHead();
			m_pBuilder->BuildBody();
			m_pBuilder->BuildLeftArm();
			m_pBuilder->BuildRightArm();
			m_pBuilder->BuildLeftLeg();
			m_pBuilder->BuildRightLeg();
		}
};

void test_create_builder(void)
{
	Director bdr(new FatBuilder);
	bdr.Create();

	bdr.Set_Director(new ThinBuilder);
	bdr.Create();
}
