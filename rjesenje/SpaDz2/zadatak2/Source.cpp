#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <random>
#include <ctime>

#include "Vec2i.h"

const int WIDTH=30;
const int HEIGHT=25;

using namespace std;
char get_user_input() {
	if (_kbhit()) {
		return _getch();
	}
	return 0;
}

int rand(int range){
	return rand()%range;
}

void setFruit(Vec2i &player, Vec2i &fruit){
	do{
		fruit.set(rand(HEIGHT),rand(WIDTH));
	}while(fruit.equals(player));
}


void update(Vec2i &player, Vec2i &fruit, Vec2i &dir){

	switch(get_user_input())
	{
	case 'a':dir.set( 0,-1);break;
	case 'd':dir.set( 0, 1);break;
	case 'w':dir.set(-1, 0);break;
	case 's':dir.set( 1, 0);break;
	case 'k':exit(0);
	}

	player.add(dir);

	if(fruit.equals(player))setFruit(player,fruit);
}

void draw(Vec2i &player, Vec2i &fruit){

	system("cls");
	for(int x=-1,i=HEIGHT+1;x<i;x++){
		for(int y=-1,j=WIDTH+1;y<j;y++){
			if(x==-1||x==HEIGHT||y==-1||y==WIDTH)cout<<"#";
			else{
				if(player.equals(x,y))cout<<"X";
				else if(fruit.equals(x,y))cout<<"D";
				else cout<<" ";
			}
		}
		cout<<endl;
	}

}

void main(){
	srand(time(NULL));

	Vec2i player(HEIGHT/2-1,WIDTH/2-1);
	Vec2i fruit;
	Vec2i dir(1,0);

	setFruit(player,fruit);

	while(true){//GAME LOOP
		update(player,fruit,dir);
		draw(player,fruit);

		if(player.x<0||player.y<0||player.x>=HEIGHT||player.y>=WIDTH)break;
		else Sleep(100);
	}
}