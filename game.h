#ifndef GAME_H
#define GAME_H
class Game{
	private:
		unsigned short int Direction;
		unsigned short int Length;
		unsigned short int X_head, Y_head, X_tail, Y_tail;
		unsigned short int Difficuly;		
		short int Data[52][32];
	public:
		Game();
		void Set_Difficulty(int a);
		int Return_Score();
		void Start();
		void Change_Direction();
		bool Lose_Check();
		void Food_Generator(int i);
		void Move();		
};
#endif
