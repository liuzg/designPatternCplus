/*
 * Behavior_5State.cpp
 *
 *  Created on: 2018��3��4��
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

//ս��
class War
{
private:
    State *m_state;  //Ŀǰ״̬
    int m_days;      //ս������ʱ��
public:
    War(State *state): m_state(state), m_days(0) {}
    ~War() { delete m_state; }
    int GetDays() { return m_days; }
    void SetDays(int days) { m_days = days; }
    void SetState(State *state) { delete m_state; m_state = state; }
    void GetState() { m_state->CurrentState(this); }
};

//ս������
class EndState: public State
{
public:
    void End(War *war) //�����׶εľ�����Ϊ
    {
        cout<<"ս������"<<endl;
    }
    void CurrentState(War *war) { End(war); }
};

//����
class AnaphaseState: public State
{
public:
    void Anaphase(War *war) //���ڵľ�����Ϊ
    {
        if(war->GetDays() < 30)
            cout<<"��"<<war->GetDays()<<"�죺ս�����ڣ�˫��ƴ��һ��"<<endl;
        else
        {
            war->SetState(new EndState());
            war->GetState();
        }
    }
    void CurrentState(War *war) { Anaphase(war); }
};

//����
class MetaphaseState: public State
{
public:
    void Metaphase(War *war) //���ڵľ�����Ϊ
    {
        if(war->GetDays() < 20)
            cout<<"��"<<war->GetDays()<<"�죺ս�����ڣ�������ֽ׶Σ�˫���������"<<endl;
        else
        {
            war->SetState(new AnaphaseState());
            war->GetState();
        }
    }
    void CurrentState(War *war) { Metaphase(war); }
};

//ǰ��
class ProphaseState: public State
{
public:
    void Prophase(War *war)  //ǰ�ڵľ�����Ϊ
    {
        if(war->GetDays() < 10)
            cout<<"��"<<war->GetDays()<<"�죺ս�����ڣ�˫������������������̽�Է�"<<endl;
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
