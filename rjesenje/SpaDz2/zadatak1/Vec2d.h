#ifndef VEC2D_H
#define VEC2D_H

#include <math.h>
#include <string>
#include <sstream>

using namespace std;

struct Vec2d{
	double x=0,y=0;

	Vec2d(){}
	Vec2d(Vec2d &vec){
		this->x=vec.x;
		this->y=vec.y;
	}
	Vec2d(double x, double y){
		this->x=x;
		this->y=y;
	}

	//dodao sam na pocetku matematicke operacije koje prakticki uvijek koristim, npr https://goo.gl/cJwgRf
	void add(Vec2d &vec){
		add(vec.x,vec.y);
	}
	void add(double x, double y){
		this->x+=x;
		this->y+=y;
	}

	void sub(Vec2d &vec){
		sub(vec.x,vec.y);
	}
	void sub(double x, double y){
		this->x-=x;
		this->y-=y;
	}

	double len(){
		return sqrt((x*x)+(y*y));
	}
	void normalize(){
		double length=len();
		x/=length;
		y/=length;
	}
	bool equals(Vec2d &vec){
		return equals(vec.x,vec.y);
	}
	bool equals(double x,double y){
		return this->x==x&&this->y==y;
	}
	string toString(){
		stringstream ss;
		ss<<x<<" "<<y;
		return ss.str();
	}
};

#endif // !VEC2D_H
