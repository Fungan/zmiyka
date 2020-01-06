#include"game.h"
#include"interface.h"
#include"window.h"
#include<iostream>
#include<windows.h>


Game::Game(){
	for(int x=0; x<52; x++){
		for(int y=0; y<32; y++){
			if(x==0 || y==0 || x==51 || y==31){
				Game::Data[x][y]=-1;
			} else Game::Data[x][y]=0;
		}
	}	
	Game::Difficuly=3;
	Game::Direction=3;
	Game::X_head=26;
	Game::Y_head=15;
	Game::X_tail=24;
	Game::Y_tail=15;
	Data[X_head][Y_head]=3;
	Data[X_head-1][Y_head]=3;
	Data[X_tail][Y_tail]=3;
	Game::Food_Generator();
	Game::Length=3;
}

void Game::Set_Difficulty(int a){
	Game::Difficuly=a;
}

void Game::Start(){
	system("cls");
	gotoxy(0,0);
	for(int y=0; y<32; y++){
		for(int x=0; x<52; x++){
			if(Game::Data[x][y]==-1){
				gotoxy(x,y);
				std::cout << '#' << std::endl;
			}
			if(Game::Data[x][y]==-2){
				gotoxy(x,y);
				std::cout << '+' << std::endl;
			}
			if(Game::Data[x][y]>0){
				gotoxy(x,y);
				std::cout << '@' << std::endl;
			}
		}
	}
	gotoxy(59,7);
	std::cout << "_________" << std::endl;
	gotoxy(59,8);
	std::cout << "| SCORE |" <<std::endl;
	gotoxy(59,9);
	std::cout << "|       |" <<std::endl;
	gotoxy(59,10);
	std::cout << "|   0   |" << std::endl;
	gotoxy(59,11);
	std::cout << "|_______|" << std::endl;
	while (true){
		Game::Change_Direction();
		
		if(Game::Lose_Check()){
			Lose(Game::Return_Score());
			break;
			
		}	else{
			Game::Move();
		}
	}
	
}

void Game::Change_Direction(){
	bool flag=true;
	for (int i=0; i<50*Game::Difficuly; i++){
		Sleep(1);
		if (GetAsyncKeyState(VK_LEFT)==-32767 && Game::Direction!=3 && flag){
			flag=false;
			Game::Direction=1;
		}
		if (GetAsyncKeyState(VK_UP)==-32767 && Game::Direction!=4 && flag){
			flag=false;
			Game::Direction=2;
		}
		if (GetAsyncKeyState(VK_RIGHT)==-32767 && Game::Direction!=1 && flag){
			flag=false;
			Game::Direction=3;
		}
		if (GetAsyncKeyState(VK_DOWN)==-32767 && Game::Direction!=2 && flag){
			flag=false;
			Game::Direction=4;
		}
		if (GetAsyncKeyState(VK_SPACE)==-32767){
			i+=200;
		}			
	}
}

bool Game::Lose_Check(){
	if (Game::Direction==1 && (Game::Data[Game::X_head-1][Game::Y_head]>0 || Game::Data[Game::X_head-1][Game::Y_head]==-1)) return true;
	if (Game::Direction==2 && (Game::Data[Game::X_head][Game::Y_head-1]>0 || Game::Data[Game::X_head][Game::Y_head-1]==-1)) return true;
	if (Game::Direction==3 && (Game::Data[Game::X_head+1][Game::Y_head]>0 || Game::Data[Game::X_head+1][Game::Y_head]==-1)) return true;
	if (Game::Direction==4 && (Game::Data[Game::X_head][Game::Y_head+1]>0 || Game::Data[Game::X_head][Game::Y_head+1]==-1)) return true;
	return false;
}

int Game::Return_Score(){
	return (Game::Length-3)*(5-Game::Difficuly)*30;
}

void Game::Food_Generator(){
	srand(Game::Return_Score()+Game::Length*Game::Data[Game::X_tail][Game::Y_head]);
	int x=rand()%50+1, y=rand()%30+1;
	if (Game::Data[x][y]==0){
		Game::Data[x][y]=-2;
		gotoxy(x,y);
		std::cout << '+' << std::endl;
	} else Game::Food_Generator();
}

void Game::Move(){
	Game::Data[Game::X_head][Game::Y_head]=Game::Direction;
	switch (Game::Direction){
		case 1:
			gotoxy(Game::X_head-1,Game::Y_head);
			std::cout << '@' << std::endl;
			Game::X_head--;
			break;
		case 2:
			gotoxy(Game::X_head,Game::Y_head-1);
			std::cout << '@' << std::endl;
			Game::Y_head--;
			break;
		case 3:
			gotoxy(Game::X_head+1,Game::Y_head);
			std::cout << '@' << std::endl;
			Game::X_head++;
			break;
		case 4:
			gotoxy(Game::X_head,Game::Y_head+1);
			std::cout << '@' << std::endl;
			Game::Y_head++;
			break;
	}
	
	if(Game::Data[Game::X_head][Game::Y_head]!=-2){
		gotoxy(Game::X_tail,Game::Y_tail);
		std::cout << ' ' << std::endl;
		switch (Game::Data[Game::X_tail][Game::Y_tail]){
			case 1:
				Game::Data[Game::X_tail][Game::Y_tail]=0;
				Game::X_tail--;
				break;
			case 2:
				Game::Data[Game::X_tail][Game::Y_tail]=0;
				Game::Y_tail--;
				break;
			case 3:
				Game::Data[Game::X_tail][Game::Y_tail]=0;
				Game::X_tail++;
				break;
			case 4:
				Game::Data[Game::X_tail][Game::Y_tail]=0;
				Game::Y_tail++;
				break;
		}
	} else{
		Game::Food_Generator();
		Game::Length++;
		gotoxy(63,10);
		if (Game::Return_Score()>99)gotoxy(62,10);
		if (Game::Return_Score()>999)gotoxy(61,10);
		if (Game::Return_Score()>9999)gotoxy(60,10);
		std::cout << Game::Return_Score() << std::endl;
	}
}




























