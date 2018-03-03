/*
 * Structural_3Compsite.cpp
 *
 *  Created on: 2018年3月2日
 *  href: http://blog.csdn.net/wuzhekai1985/article/details/6667564
 *      Author: liu_z
 *      将对象组合成树形结构以表示“部分-整体”的层次结构。组合使得用户对单个对象和组合对象的使用具有一致性。
 *      有内存泄漏。需要在增加的Del中，进行erase及delete。
 */
#include <iostream>
#include <list>
#include <typeinfo>
using namespace std;

class Company
{
	public:
		Company(string name) { m_name = name; }
		virtual ~Company(){}
		virtual void Add(Company *pCom){}
		virtual void Del(string name){}
		virtual void Show(int depth) {}
		virtual Company* GetClassType(void) { return this; }
		string	GetName(void) { return m_name; }
	protected:
		string m_name;
};

//具体公司
class ConcreteCompany : public Company
{
	public:
		ConcreteCompany(string name): Company(name) {}
		virtual ~ConcreteCompany() {}
		virtual ConcreteCompany* GetClassType(void) { return this; }
		void Add(Company *pCom) { m_listCompany.push_back(pCom); } //位于树的中间，可以增加子树
		virtual void Del(string name){
			list<Company *>::iterator iter = m_listCompany.begin();
			if( 0 == name.compare(GetName()) )
					cout << "It's me! " << GetName() << endl;
			for(; iter != m_listCompany.end(); iter++) {//显示下层结点
//				if( 0 == name.compare((*iter)->m_name) ){
					Company *pCom = *iter;
					if( typeid(*pCom->GetClassType()) == typeid(ConcreteCompany)) {
//						pCom->Del()
						cout << "This is ConcreteCompany class." << endl;
						cout << "class name = " << pCom->GetName() << endl;
						pCom->Del(name);
					}
					else{
						cout << "This isn't ConcreteCompany class." << endl;
						cout << "class name = " << pCom->GetName() << endl;
					}
//					m_listCompany.erase(iter);
//					delete pCom;
//				}
			}
		}

		void Show(int depth)
		{
			for(int i = 0;i < depth; i++)
				cout<<"-";
			cout<<m_name<<endl;
			list<Company *>::iterator iter=m_listCompany.begin();
			for(; iter != m_listCompany.end(); iter++) //显示下层结点
				(*iter)->Show(depth + 2);
		}
	private:
		list<Company *> m_listCompany;
};

//具体的部门，财务部
class FinanceDepartment : public Company
{
	public:
		FinanceDepartment(string name):Company(name){}
		virtual ~FinanceDepartment() {}
		virtual FinanceDepartment* GetClassType(void) { return this; }
		virtual void Show(int depth) //只需显示，无限添加函数，因为已是叶结点
		{
			for(int i = 0; i < depth; i++)
				cout<<"-";
			cout<<m_name<<endl;
		}
};

//具体的部门，人力资源部
class HRDepartment :public Company
{
	public:
		HRDepartment(string name):Company(name){}
		virtual ~HRDepartment() {}
		virtual HRDepartment* GetClassType(void) { return this; }
		virtual void Show(int depth) //只需显示，无限添加函数，因为已是叶结点
		{
			for(int i = 0; i < depth; i++)
				cout<<"-";
			cout<<m_name<<endl;
		}
};

void test_structural_composite(void)
{
	ConcreteCompany	oCorp("知学馆");
	oCorp.Add(new FinanceDepartment("知学馆 财务"));
	oCorp.Add(new HRDepartment("知学馆 人力"));

	ConcreteCompany	oCorp1("知学馆 上海分公司");
	oCorp1.Add(new FinanceDepartment("知学馆 上海财务"));
	oCorp1.Add(new HRDepartment("知学馆 上海人力"));

	oCorp.Add(&oCorp1);

	oCorp.Show(3);

	oCorp.Del("知学馆 上海分公司");
}

