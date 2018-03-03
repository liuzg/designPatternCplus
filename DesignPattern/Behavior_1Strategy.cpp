/*
 * Behavior_Strategy.cpp
 *
 *  Created on: 2018年2月28日
 *  href: http://blog.csdn.net/wuzhekai1985/article/details/6665197
 *      Author: liu_z
 */

#include <iostream>
using namespace std;


//抽象接口
class ReplaceAlgorithm
{
	public:
		virtual void Replace() = 0;
		virtual ~ReplaceAlgorithm(){};
};

//三种具体的替换算法
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
 *  如果用这种方式，客户就需要知道这些算法的具体定义。只能以下面这种方式使用，可以看到暴露了太多的细节。
 */
//Cache需要用到替换算法
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
 * 方式二：也是直接通过参数指定，只不过不是传入指针，而是一个标签。这样客户只要知道算法的相应标签即可，而不需要知道算法的具体定义。
 */
//Cache需要用到替换算法
enum RA {LRU, FIFO, RANDOM}; //标签
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
 *方式三：利用模板实现。算法通过模板的实参指定。当然了，还是使用了参数，只不过不是构造函数的参数。在策略模式中，参数的传递难以避免，客户必须指定某种算法。
 */
//Cache需要用到替换算法
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

