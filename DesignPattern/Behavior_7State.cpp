/*
 * Behavior_5State.cpp
 *
 *  Created on: 2018年3月4日
 *  href:http://blog.csdn.net/wuzhekai1985/article/details/6675799
 *      Author: liu_z
 */
#include <iostream>
#include <list>
using namespace std;


class War;
class State
{
public:
    virtual void Prophase() {}
    virtual void Metaphase() {}
    virtual void Anaphase() {}
    virtual void End() {}
    virtual void CurrentState(War *war) {}
    virtual ~State(){}
};

//战争
class War
{
private:
    State *m_state;  //目前状态
    int m_days;      //战争持续时间
public:
    War(State *state): m_state(state), m_days(0) {}
    ~War() { delete m_state; }
    int GetDays() { return m_days; }
    void SetDays(int days) { m_days = days; }
    void SetState(State *state) { delete m_state; m_state = state; }
    void GetState() { m_state->CurrentState(this); }
};

//战争结束
class EndState: public State
{
public:
    void End(War *war) //结束阶段的具体行为
    {
        cout<<"战争结束"<<endl;
    }
    void CurrentState(War *war) { End(war); }
};

//后期
class AnaphaseState: public State
{
public:
    void Anaphase(War *war) //后期的具体行为
    {
        if(war->GetDays() < 30)
            cout<<"第"<<war->GetDays()<<"天：战争后期，双方拼死一搏"<<endl;
        else
        {
            war->SetState(new EndState());
            war->GetState();
        }
    }
    void CurrentState(War *war) { Anaphase(war); }
};

//中期
class MetaphaseState: public State
{
public:
    void Metaphase(War *war) //中期的具体行为
    {
        if(war->GetDays() < 20)
            cout<<"第"<<war->GetDays()<<"天：战争中期，进入相持阶段，双发各有损耗"<<endl;
        else
        {
            war->SetState(new AnaphaseState());
            war->GetState();
        }
    }
    void CurrentState(War *war) { Metaphase(war); }
};

//前期
class ProphaseState: public State
{
public:
    void Prophase(War *war)  //前期的具体行为
    {
        if(war->GetDays() < 10)
            cout<<"第"<<war->GetDays()<<"天：战争初期，双方你来我往，互相试探对方"<<endl;
        else
        {
            war->SetState(new MetaphaseState());
            war->GetState();
        }
    }
    void CurrentState(War *war) { Prophase(war); }
};


void test_behavior_state(void)
{
	State	*pS = new ProphaseState();
	War	*pW = new War(pS);

	for(int iDay = 1; iDay < 40; iDay+=5){
		pW->SetDays(iDay);
		pW->GetState();
	}
//	pW->GetState();
//	pS->CurrentState(pW);
//
//	pS = new MetaphaseState();
//	pW->SetDays(11);
//	pW->SetState(pS);
//	pW->GetState();
//	pS->CurrentState(pW);
//
//	pS = new AnaphaseState();
//	pW->SetDays(21);
//	pW->SetState(pS);
//	pW->GetState();
//	pS->CurrentState(pW);
//
//	pS = new EndState();
//	pW->SetDays(31);
//	pW->SetState(pS);
//	pW->GetState();
//	pS->CurrentState(pW);

	delete pW;
}
