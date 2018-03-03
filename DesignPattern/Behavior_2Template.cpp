/*
 * Behavior_Template.cpp
 *
 *  Created on: 2018年3月2日
 *  href: http://blog.csdn.net/wuzhekai1985/article/details/6667020
 *      Author: liu_z
 *      其中，A、B可以有不同的模板输出方式或格式，从而谓之模板。
 */
#include <iostream>
#include <mem.h>
using namespace std;


//简历
class ResumeT
{
	protected: //保护成员 （使得对外部不可见，方便进行调整）
		virtual void SetPersonalInfo() {}
		virtual void SetEducation() {}
		virtual void SetWorkExp() {}

	public:
		void FillResume()
		{
			SetPersonalInfo();
			SetEducation();
			SetWorkExp();
		}
		virtual ~ResumeT(){};
};

class ResumeTA: public ResumeT
{
	protected:
		void SetPersonalInfo() { cout<<"A's PersonalInfo"<<endl; }
		void SetEducation() { cout<<"A's Education"<<endl; }
		void SetWorkExp() { cout<<"A's Work Experience"<<endl; }
};

class ResumeTB: public ResumeT
{
	protected:
		void SetPersonalInfo() { cout<<"B's PersonalInfo"<<endl; }
		void SetEducation() { cout<<"B's Education"<<endl; }
		void SetWorkExp() { cout<<"B's Work Experience"<<endl; }
};


void test_behavior_template(void)
{
    ResumeT *r1;
    r1 = new ResumeTA();

    r1->FillResume();
    delete r1;

    r1 = new ResumeTB();
    r1->FillResume();
    delete r1;

    r1 = NULL;
}

