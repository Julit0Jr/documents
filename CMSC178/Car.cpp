#include<graphics.h>
#include<conio.h>
#include<stdio.h>

class Cab{
	int c[18];
	int color;
	
	public:
		void setCab(int x[18], int col){
			for(int i = 0; i < 18; i++){
				c[i] = x[i];
			}
			color = col;
		}
		void makeCab(){
			setfillstyle(SOLID_FILL, color);
			drawpoly(9, c);
		}
};

class Wheel{
	int x, y;
	int rad;
	int color;
	
	public:
		void setWheel(int xx, int yy, int r, int col){
			x = xx;
			y = yy;
			rad = r;
			color = col;
		}
		void makeWheel(){
			setfillstyle(SOLID_FILL, color);
			circle(x,y,rad);
		}
};
int main(){
	Cab *cab = new Cab();
	Wheel *w = new Wheel();
	int cabCoordinate18[] = {};
//	cab.setCab();
	w->setWheel(208, 280, 10, 4);
	w->makeWheel();
}
