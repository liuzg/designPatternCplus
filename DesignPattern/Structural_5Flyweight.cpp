/*
 * Structural_5Flyweight.cpp
 *
 *  Created on: 2018年3月2日
 *  Href: http://blog.csdn.net/wuzhekai1985/article/details/6670298
 *      Author: liu_z
 *      本文介绍享元模式的实现。
 *      举个围棋的例子，围棋的棋盘共有361格，即可放361个棋子。现在要实现一个围棋程序，该怎么办呢？
 *      首先要考虑的是棋子棋盘的实现，可以定义一个棋子的类，成员变量包括棋子的颜色、形状、位置等信息，
 *      另外再定义一个棋盘的类，成员变量中有个容器，用于存放棋子的对象。
 *      可以发现，棋盘的容器中存放了已下的棋子，而每个棋子包含棋子的所有属性。
 *      一盘棋往往需要含上百颗棋子，采用上面这种实现，占用的空间太大了。
 *      如何改进呢？用享元模式。其定义为：运用共享技术有效地支持大量细粒度的对象。
 */
#include <iostream>
#include <vector>
using namespace std;


//棋子颜色
enum PieceColor {BLACK, WHITE};
//棋子位置
struct PiecePos
{
		int x;
		int y;
		PiecePos(int a, int b): x(a), y(b) {}
};

//棋子定义
class Piece
{
	protected:
		PieceColor m_color; //颜色
		// PiecePos m_pos;     //位置
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
		void Draw() { cout<<"绘制一颗黑棋"<<endl;}
};

class WhitePiece: public Piece
{
	public:
		//WhitePiece(PieceColor color, PiecePos pos): Piece(color, pos) {}
		WhitePiece(PieceColor color): Piece(color) {}
		~WhitePiece() {}
		void Draw() { cout<<"绘制一颗白棋"<<endl;}
};

class PieceBoard
{
	private:
		//vector<Piece*> m_vecPiece; //棋盘上已有的棋子
		vector<PiecePos> m_vecPos; 	 //棋盘上已有的棋子的位置
	    Piece *m_blackPiece;       //黑棋棋子
	    Piece *m_whitePiece;       //白棋棋子
		string m_blackName; //黑方名称
		string m_whiteName; //白方名称

	public:
		PieceBoard(string black, string white): m_blackName(black), m_whiteName(white){
			m_blackPiece = NULL;
			m_whitePiece = NULL;
		}
		//~PieceBoard() { Clear(); }
		~PieceBoard() { delete m_blackPiece; delete m_whitePiece; }

		void SetPiece(PieceColor color, PiecePos pos) //一步棋，在棋盘上放一颗棋子
		{
			//Piece * piece = NULL;
			if(color == BLACK) //黑方下的
			{
				//piece = new BlackPiece(color, pos); //获取一颗黑棋
				if ( !m_blackPiece )
					m_blackPiece = new BlackPiece(color); //获取一颗黑棋
				cout<<m_blackName<<"在位置("<<pos.x<<','<<pos.y<<")";
				m_blackPiece->Draw(); //在棋盘上绘制出棋子
			}
			else
			{
				//piece = new WhitePiece(color, pos);
				if ( !m_whitePiece )
					m_whitePiece = new WhitePiece(color); //获取一颗黑棋
				cout<<m_whiteName<<"在位置("<<pos.x<<','<<pos.y<<")";
				m_whitePiece->Draw();
			}
			//m_vecPiece.push_back(pos);  //加入容器中
			m_vecPos.push_back(pos);  //加入容器中
		}

//		void Clear() //释放内存
//		{
//			int size = m_vecPiece.size();
//			for(int i = 0; i < size; i++)
//				delete m_vecPiece[i];
//		}
};

void test_structural_flyweight(void)
{
	PieceBoard	oPB("刘", "孙");

	oPB.SetPiece(WHITE, PiecePos(5, 5));
	oPB.SetPiece(BLACK, PiecePos(3, 5));

}
