/*
 * Structural_4Proxy.cpp
 *
 *  Created on: 2018��3��2��
 *  href: http://blog.csdn.net/wuzhekai1985/article/details/6669219
 *      Author: liu_z
 *      Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ��ʡ� �����ֳ��õ������
 *      ��1��Զ�̴���
 *      ��2�������
 *      ��3����������
 *      ��4���������á�������Ҫ���������������������������
 */
#include <iostream>
using namespace std;

class Image
{
	public:
		Image(string name): m_imageName(name) {}
		virtual ~Image() {}
		virtual void Show() {}
	protected:
		string m_imageName;
};

class BigImage: public Image
{
	public:
		BigImage(string name):Image(name) {}
		~BigImage() {}
		void Show() { cout<<"Show big image : "<<m_imageName<<endl; }
};

class BigImageProxy: public Image
{
	private:
		BigImage *m_bigImage;
	public:
		BigImageProxy(string name):Image(name),m_bigImage(0) {}
		~BigImageProxy() { delete m_bigImage; }
		void Show()
		{
			if(m_bigImage == NULL)
				m_bigImage = new BigImage(m_imageName);
			m_bigImage->Show();
		}
};

void test_structural_proxy(void)
{
    Image *image = new BigImageProxy("proxy.jpg"); //����
    image->Show(); //��Ҫʱ�ɴ������
    delete image;
}

//============�����������õ����ӡ�һ����C++�е�auto_ptr����һ����smart_ptr���Լ�ʵ����һ�¡��ȸ���auto_ptr�Ĵ���ʵ�֣�
template<class T>
class auto_ptr {
	public:
		explicit auto_ptr(T *p = 0): pointee(p) {} //explicit(��ʽ)���캯��
		auto_ptr(auto_ptr<T>& rhs): pointee(rhs.release()) {}
		~auto_ptr() { delete pointee; }

		auto_ptr<T>& operator=(auto_ptr<T>& rhs)
		{
			if (this != &rhs) reset(rhs.release());
			return *this;
		}
		T& operator*() const { return *pointee; }
		T* operator->() const { return pointee; }
		T* get() const { return pointee; }
		T* release()
		{
			T *oldPointee = pointee;
			pointee = 0;
			return oldPointee;
		}
		void reset(T *p = 0)
		{
			if (pointee != p) {
				   delete pointee;
				   pointee = p;
				}
			}
	private:
		T *pointee;
};


//========����֪��C++��û���������ջ��ƣ�����ͨ������ָ�����ֲ��������������ָ���һ��ʵ�֣����������ü����Ĳ��ԡ�
template <typename T>
class smart_ptr
{
	public:
		smart_ptr(T *p = 0): pointee(p), count(new size_t(1)) { }  //��ʼ�ļ���ֵΪ1
		smart_ptr(const smart_ptr &rhs): pointee(rhs.pointee), count(rhs.count) { ++*count; } //�������캯����������1
		~smart_ptr() { decr_count(); }              //������������1������0ʱ�����������գ����ͷſռ�
		smart_ptr& operator= (const smart_ptr& rhs) //���ظ�ֵ������
		{
			//������ֵҲ�ԣ���Ϊ�������ֵ���������ȼ�1���ټ�1����δ�����ı�
			++*rhs.count;
			decr_count();
			pointee = rhs.pointee;
			count = rhs.count;
			return *this;
		}
		//���ؼ�ͷ�������ͽ����ò�������δ�ṩָ��ļ��
		T *operator->() { return pointee; }
		const T *operator->() const { return pointee; }
		T &operator*() { return *pointee; }
		const T &operator*() const { return *pointee; }
		size_t get_refcount() { return *count; } //������ü�����ֵ
	private:
		T *pointee;       //ʵ��ָ�룬������
		size_t *count;    //���ü�����
		void decr_count() //��������1
		{
			if(--*count == 0)
			{
				delete pointee;
				delete count;
			}
		}
};


