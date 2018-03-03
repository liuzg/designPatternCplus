/*
 * Create_6Builder.cpp
 *
 *  Created on: 2018年3月2日
 *  href: http://blog.csdn.net/wuzhekai1985/article/details/6667467
 *      Author: liu_z
 *      建造者模式的定义将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示（DP）。
 *      《大话设计模式》举了一个很好的例子——建造小人，一共需建造6个部分，头部、身体、左右手、左右脚。
 *      与工厂模式不同，建造者模式是在导向者的控制下一步一步构造产品的。建造小人就是在控制下一步步构造出来的。
 *      创建者模式可以能更精细的控制构建过程，从而能更精细的控制所得产品的内部结构。
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

//构造瘦人
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

//构造胖人
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

//构造的指挥官
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
