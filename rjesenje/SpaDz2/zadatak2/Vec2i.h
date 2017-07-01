#ifndef VEC2I_H
#define VEC2I_H

#include <math.h>
#include <string>
#include <sstream>

using namespace std;

struct Vec2i{
	int x=0,y=0;

	Vec2i(){}
	Vec2i(Vec2i &vec){
		set(vec.x,vec.y);
	}
	Vec2i(int x, int y){
		set(x,y);
	}

	void set(int x, int y){
		this->x=x;
		this->y=y;
	}

	//dodao sam na pocetku matematicke operacije koje prakticki uvijek koristim, npr https://goo.gl/cJwgRf
	void add(Vec2i &vec){
		add(vec.x,vec.y);
	}
	void add(int x, int y){
		this->x+=x;
		this->y+=y;
	}

	void sub(Vec2i &vec){
		sub(vec.x,vec.y);
	}
	void sub(int x, int y){
		this->x-=x;
		this->y-=y;
	}

	bool equals(Vec2i &vec){
		return equals(vec.x,vec.y);
	}
	bool equals(int x,int y){
		return this->x==x&&this->y==y;
	}
	string toString(){
		stringstream ss;
		ss<<x<<" "<<y;
		return ss.str();
	}
};

#endif // !VEC2I_H
