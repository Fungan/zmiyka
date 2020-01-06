#include"window.h"
#include"interface.h"
#include"game.h"
#include<unistd.h>
#include<windows.h>
#include<iostream>



main() {
	setwindow();
	while(true){
		Game *game = new Game();
		int i=0;
		int a=3;
		Menu();
		gotoxy(1,31);
		std::cout << "Current difficulty - Normal" << std::endl;
		while(true){
			Sleep(1);
			i++;
			gotoxy(30,10);
			if (i==500) std::cout << "         " << std::endl;
			if (i==1000) {
				std::cout << " \'Enter\' " << std::endl;
				i=0;
			}
			if (GetAsyncKeyState(VK_RETURN)==-32767){
				game->Start();
				break;
			}
			if (GetAsyncKeyState(VK_NUMPAD8)==-32767){
				if (a>1){
					a--;
					game->Set_Difficulty(a);
					gotoxy(22,31);
					switch (a){
						case 1:
							std::cout << "Insane" << std::endl;
							break;
						case 2: 
							std::cout << "Hard  " << std::endl;
							break;
						case 3: 
							std::cout << "Normal" << std::endl;
							break;
					}
				}
			}
			if (GetAsyncKeyState(VK_NUMPAD2)==-32767){
				if (a<4){
					a++;
					game->Set_Difficulty(a);
					gotoxy(22,31);
					switch (a){
						case 2: 
							std::cout << "Hard  " << std::endl;
							break;
						case 3: 
							std::cout << "Normal" << std::endl;
							break;
						case 4: 
							std::cout << "Easy  " << std::endl;
							break;
					}
				}
			}	
		}
	}
}
