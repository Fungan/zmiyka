#include"window.h"
#include"interface.h"
#include"game.h"
#include<iostream>
#include<unistd.h>

void Menu(){
	system("cls");
	gotoxy(25,10);
	std::cout << "Press \'Enter\' to start" << std::endl;
	gotoxy(31,15);
	std::cout << "CONTROLS:" << std::endl;
	gotoxy(27,18);
	std::cout << "Moving - ARROWS" << std::endl;
	gotoxy(25,20);
	std::cout << "Speed UP - SPACE" << std::endl;
	gotoxy(20,22);
	std::cout << "Difficulty UP - NUM_8" << std::endl;
	gotoxy(18,24);
	std::cout << "Difficulty DOWN - NUM_2" << std::endl;
	gotoxy(28,26);
	std::cout << "Pause - Pause/Break" << std::endl;
}

void Pause(){
	
}

void Lose(int Score){
	system("cls");
	gotoxy(28,12);
	std::cout << "_________________" << std::endl;
	gotoxy(28,13);
	std::cout << "|   GAME OVER   |" << std::endl;
	gotoxy(28,14);
	std::cout << "|               |" << std::endl;
	gotoxy(28,15);
	std::cout << "|Score - " << Score << std::endl;
	gotoxy(44,15);
	std::cout << '|' << std::endl;
	gotoxy (28,16);
	std::cout << "|_______________|" << std::endl;	
	sleep (3);
}

