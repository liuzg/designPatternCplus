/*
 * Structural_5Flyweight.cpp
 *
 *  Created on: 2018��3��2��
 *  Href: http://blog.csdn.net/wuzhekai1985/article/details/6670298
 *      Author: liu_z
 *      ���Ľ�����Ԫģʽ��ʵ�֡�
 *      �ٸ�Χ������ӣ�Χ������̹���361�񣬼��ɷ�361�����ӡ�����Ҫʵ��һ��Χ����򣬸���ô���أ�
 *      ����Ҫ���ǵ����������̵�ʵ�֣����Զ���һ�����ӵ��࣬��Ա�����������ӵ���ɫ����״��λ�õ���Ϣ��
 *      �����ٶ���һ�����̵��࣬��Ա�������и����������ڴ�����ӵĶ���
 *      ���Է��֣����̵������д�������µ����ӣ���ÿ�����Ӱ������ӵ��������ԡ�
 *      һ����������Ҫ���ϰٿ����ӣ�������������ʵ�֣�ռ�õĿռ�̫���ˡ�
 *      ��θĽ��أ�����Ԫģʽ���䶨��Ϊ�����ù�������Ч��֧�ִ���ϸ���ȵĶ���
 */
#include <iostream>
#include <vector>
using namespace std;


//������ɫ
enum PieceColor {BLACK, WHITE};
//����λ��
struct PiecePos
{
		int x;
		int y;
		PiecePos(int a, int b): x(a), y(b) {}
};

//���Ӷ���
class Piece
{
	protected:
		PieceColor m_color; //��ɫ
		// PiecePos m_pos;     //λ��
	public:
		//Piece(PieceColor color, PiecePos pos): m_color(color), m_pos(pos) {}
		Piece(PieceColor color): m_color(color) {}
		virtual ~Piece() {}
		virtual void Draw() {}
};

class BlackPiece: public Piece
{
	public:
		//BlackPiece(PieceColor color, PiecePos pos): Piece(color, pos) {}
		BlackPiece(PieceColor color): Piece(color) {}
		~BlackPiece() {}
		void Draw() { cout<<"����һ�ź���"<<endl;}
};

class WhitePiece: public Piece
{
	public:
		//WhitePiece(PieceColor color, PiecePos pos): Piece(color, pos) {}
		WhitePiece(PieceColor color): Piece(color) {}
		~WhitePiece() {}
		void Draw() { cout<<"����һ�Ű���"<<endl;}
};

class PieceBoard
{
	private:
		//vector<Piece*> m_vecPiece; //���������е�����
		vector<PiecePos> m_vecPos; 	 //���������е����ӵ�λ��
	    Piece *m_blackPiece;       //��������
	    Piece *m_whitePiece;       //��������
		string m_blackName; //�ڷ�����
		string m_whiteName; //�׷�����

	public:
		PieceBoard(string black, string white): m_blackName(black), m_whiteName(white){
			m_blackPiece = NULL;
			m_whitePiece = NULL;
		}
		//~PieceBoard() { Clear(); }
		~PieceBoard() { delete m_blackPiece; delete m_whitePiece; }

		void SetPiece(PieceColor color, PiecePos pos) //һ���壬�������Ϸ�һ������
		{
			//Piece * piece = NULL;
			if(color == BLACK) //�ڷ��µ�
			{
				//piece = new BlackPiece(color, pos); //��ȡһ�ź���
				if ( !m_blackPiece )
					m_blackPiece = new BlackPiece(color); //��ȡһ�ź���
				cout<<m_blackName<<"��λ��("<<pos.x<<','<<pos.y<<")";
				m_blackPiece->Draw(); //�������ϻ��Ƴ�����
			}
			else
			{
				//piece = new WhitePiece(color, pos);
				if ( !m_whitePiece )
					m_whitePiece = new WhitePiece(color); //��ȡһ�ź���
				cout<<m_whiteName<<"��λ��("<<pos.x<<','<<pos.y<<")";
				m_whitePiece->Draw();
			}
			//m_vecPiece.push_back(pos);  //����������
			m_vecPos.push_back(pos);  //����������
		}

//		void Clear() //�ͷ��ڴ�
//		{
//			int size = m_vecPiece.size();
//			for(int i = 0; i < size; i++)
//				delete m_vecPiece[i];
//		}
};

void test_structural_flyweight(void)
{
	PieceBoard	oPB("��", "��");

	oPB.SetPiece(WHITE, PiecePos(5, 5));
	oPB.SetPiece(BLACK, PiecePos(3, 5));

}
