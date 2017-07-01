#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>

#include "Vec2d.h"

using namespace std;

int getInt(string msg){
	cout<<msg;
	int i;
	cin>>i;
	return i;
}

int prefix(double num){
	return num<0?-1:1;
}

void update(Vec2d &end, Vec2d &pos){

	Vec2d direction(end);
	direction.sub(pos);
	direction.normalize();

	if(abs(direction.x)>abs(direction.y))pos.x+=prefix(direction.x);
	else pos.y+=prefix(direction.y);

}
void draw(Vec2d &start, Vec2d &end, Vec2d &pos){

	system("cls");
	for(int x=1;x<21;x++){
		for(int y=1;y<41;y++){
			if(pos.equals(x,y))cout<<"#";
			else if(start.equals(x,y))cout<<"A";
			else if(end.equals(x,y))cout<<"B";
			else cout<<"-";
		}
		cout<<endl;
	}

}

void main(){
	Vec2d start(getInt("A redak: "),getInt("A stupac: "));
	Vec2d end(getInt("B redak: "),getInt("B stupac: "));

	Vec2d pos(start);

	while(true){
		update(end, pos);
		draw(start,end,pos);

		if(!pos.equals(end))Sleep(100);
		else break;
	}
}