/*
 * Behavior_6Observer.cpp
 *
 *  Created on: 2018��3��3��
 *  href: http://blog.csdn.net/wuzhekai1985/article/details/6674984
 *      Author: liu_z
 */
#include <iostream>
#include <list>
using namespace std;

//�۲���
class Observer
{
	public:
		Observer() {}
		virtual ~Observer() {}
		virtual void Update() {}
};

//����
class Blog
{
	public:
		Blog() {}
		virtual ~Blog() {}
		void Attach(Observer *observer) { m_observers.push_back(observer); }     //��ӹ۲���
		void Remove(Observer *observer) { m_observers.remove(observer); }        //�Ƴ��۲���
		void Notify() //֪ͨ�۲���
		{
			list<Observer*>::iterator iter = m_observers.begin();
			for(; iter != m_observers.end(); iter++)
				(*iter)->Update();
		}
		virtual void SetStatus(string s) { m_status = s; } //����״̬
		virtual string GetStatus() { return m_status; }    //���״̬
	private:
		list<Observer* > m_observers; //�۲�������
	protected:
		string m_status; //״̬
};

//���岩����
class BlogCSDN : public Blog
{
	private:
		string m_name; //��������
	public:
		BlogCSDN(string name): m_name(name) {}
		~BlogCSDN() {}
		void SetStatus(string s) { m_status = "CSDN֪ͨ : " + m_name + s; } //��������״̬��Ϣ
		string GetStatus() { return m_status; }
};

	//����۲���
class ObserverBlog : public Observer
{
	private:
		string m_name;  //�۲�������
		Blog *m_blog;   //�۲�Ĳ��ͣ���Ȼ��������ʽ���ã��Ϳ��Թ۲�������
	public:
		ObserverBlog(string name,Blog *blog): m_name(name), m_blog(blog) {}
		~ObserverBlog() {}
		void Update()  //��ø���״̬
		{
			if( m_blog ) {
				string status = m_blog->GetStatus();
				cout<<m_name<<"-------"<<status<<endl;
			}
		}
};


void test_behavior_observer(void)
{

	BlogCSDN	*pB = new BlogCSDN("����");
	Observer 	*pO	= new ObserverBlog("�۲���",pB);
	Observer 	*pO1	= new ObserverBlog("�۲���1",pB);

	pB->Attach(pO);

	pB->SetStatus("������ʵ���");
	pB->Notify();

	pO->Update();
	pO1->Update();

	delete pB;
	delete pO;
	delete pO1;

}
