/*
 * Behavior_Strategy.cpp
 *
 *  Created on: 2018��2��28��
 *  href: http://blog.csdn.net/wuzhekai1985/article/details/6665197
 *      Author: liu_z
 */

#include <iostream>
using namespace std;


//����ӿ�
class ReplaceAlgorithm
{
	public:
		virtual void Replace() = 0;
		virtual ~ReplaceAlgorithm(){};
};

//���־�����滻�㷨
class LRU_ReplaceAlgorithm : public ReplaceAlgorithm
{
	public:
		void Replace() { cout<<"Least Recently Used replace algorithm"<<endl; }
};

class FIFO_ReplaceAlgorithm : public ReplaceAlgorithm
{
	public:
		void Replace() { cout<<"First in First out replace algorithm"<<endl; }
};

class Random_ReplaceAlgorithm: public ReplaceAlgorithm
{
	public:
		void Replace() { cout<<"Random replace algorithm"<<endl; }
};

/*
 *  ��������ַ�ʽ���ͻ�����Ҫ֪����Щ�㷨�ľ��嶨�塣ֻ�����������ַ�ʽʹ�ã����Կ�����¶��̫���ϸ�ڡ�
 */
//Cache��Ҫ�õ��滻�㷨
class Cache
{
	private:
		ReplaceAlgorithm *m_ra;

	public:
		Cache(ReplaceAlgorithm *ra) { m_ra = ra; }
		~Cache() { delete m_ra; }

		void Replace() { m_ra->Replace(); }
};

void test_behavior_strategy(void)
{
	LRU_ReplaceAlgorithm	lra;
	Cache		oCa(&lra);
	oCa.Replace();

	FIFO_ReplaceAlgorithm	fra;
	Cache		oCa1(&fra);
	oCa1.Replace();

	Random_ReplaceAlgorithm	rra;
	Cache		oCa2(&rra);
	oCa2.Replace();

}


/*
 * ��ʽ����Ҳ��ֱ��ͨ������ָ����ֻ�������Ǵ���ָ�룬����һ����ǩ�������ͻ�ֻҪ֪���㷨����Ӧ��ǩ���ɣ�������Ҫ֪���㷨�ľ��嶨�塣
 */
//Cache��Ҫ�õ��滻�㷨
enum RA {LRU, FIFO, RANDOM}; //��ǩ
class Cache2
{
	private:
		ReplaceAlgorithm *m_ra;

	public:
		Cache2(enum RA ra)
		{
			if(ra == LRU)
				m_ra = new LRU_ReplaceAlgorithm();
			else if(ra == FIFO)
				m_ra = new FIFO_ReplaceAlgorithm();
			else if(ra == RANDOM)
				m_ra = new Random_ReplaceAlgorithm();
			else
				m_ra = NULL;
		}
		~Cache2() { delete m_ra; }
		void Replace() { m_ra->Replace(); }
};

void test_behavior_strategy2(void)
{
	Cache2		oCa(LRU);
	oCa.Replace();

	Cache2		oCa1(FIFO);
	oCa1.Replace();

	Cache2		oCa2(RANDOM);
	oCa2.Replace();

}


/*
 *��ʽ��������ģ��ʵ�֡��㷨ͨ��ģ���ʵ��ָ������Ȼ�ˣ�����ʹ���˲�����ֻ�������ǹ��캯���Ĳ������ڲ���ģʽ�У������Ĵ������Ա��⣬�ͻ�����ָ��ĳ���㷨��
 */
//Cache��Ҫ�õ��滻�㷨
template <class RA>
class Cache3
{
	private:
		RA m_ra;

	public:
		Cache3() { }
		~Cache3() { }
		void Replace() { m_ra.Replace(); }
};

void test_behavior_strategy3(void)
{
	Cache3<LRU_ReplaceAlgorithm> oCa;
	oCa.Replace();

	Cache3<FIFO_ReplaceAlgorithm> oCa1;
	oCa1.Replace();

	Cache3<Random_ReplaceAlgorithm>	oCa2;
	oCa2.Replace();

}

