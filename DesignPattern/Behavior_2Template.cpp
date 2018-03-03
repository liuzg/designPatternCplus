/*
 * Behavior_Template.cpp
 *
 *  Created on: 2018��3��2��
 *  href: http://blog.csdn.net/wuzhekai1985/article/details/6667020
 *      Author: liu_z
 *      ���У�A��B�����в�ͬ��ģ�������ʽ���ʽ���Ӷ�ν֮ģ�塣
 */
#include <iostream>
#include <mem.h>
using namespace std;


//����
class ResumeT
{
	protected: //������Ա ��ʹ�ö��ⲿ���ɼ���������е�����
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

