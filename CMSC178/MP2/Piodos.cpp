#include <iostream>
#include <graphics.h>
#include <windows.h>
#include <dos.h>
#include <MMSystem.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

class Background {
	int x, y, col;
	public:
		Background() {
			x = 600;
			y = 700;
			col = 10;
		}
		void drawBackground() {
			int points[8] = {	0, 0,
								0, y,
								x, y,
								x, 0};
			setfillstyle(1, 0);
			fillpoly(4, points);
		}		
};

class Bullet {
	int x, y, rad;
	int bx1, bx2, bx3, bx4;
	int by1, by2, by3, by4;
	int flag;
	
	public:
		
		Bullet() {
			x = -100;
			y = 0;
			rad = 30;
		}
		void scaleBullet(float s) {
			rad = rad*s;
		}
		
		int getRad() {
			return rad;
		}
		
		void drawBullet() {
		
		
				setfillstyle(1, WHITE);
				int bodyPoints[8] = { bx1, by1,
									   bx2, by2,
									   bx3, by3,
									   bx4, by4 };
			
				fillpoly(4, bodyPoints);
		
		}
		void set(int xx, int yy) {
			x = xx;
			y = yy;
			setBullet();
		}
		void setBullet() {
			bx1 = x - (rad*0.167);
			by1 = y - (rad*1.5);
			bx2 = x + (rad*0.167);
			by2 = y - (rad*1.5);
			bx3 = x - (rad*0.167);
			by3 = y - rad;
			bx4 = x + (rad*0.167);
			by4 = y - rad;
		}
		void moveBullet() {
			y = y-1;
			setBullet();
		}
		int getY() {
			return by1;
		}
		int getX() {
			return bx1;
		}
		void reset() {
			bx1 = -100;
			by1 = -100;
			bx2 = -100;
			by2 = -100;
			bx3 = -100;
			by3 = -100;
			bx4 = -100;
			by4 = -100;
		}		
};

class Boundary {
	int x;
	int y;
	int len;
	public:
		Line() {
		}
		void setLine() {
			x = 0;
			y = 510;
			len = 5;
		}
		int getY(){
			return y;
		}
		void scaleLine(float s) {
			len = len*s;
		}
		void drawLine() {
			setfillstyle(1, RED);
			int points[8] = { x, y,
							 x, y + len,
							 600, y + len,
							 600, y };
			fillpoly(4, points);
		}
};

class Circle {
	int x, y, rad, col;
	public:
		Circle(){}
		void setCircle(int xx, int yy, int radius, int color) {
			x = xx;
			y = yy;
			rad = radius;
			col = color;
		}
		void draw() {
			setfillstyle(1, col);
			fillellipse(x, y, rad, rad);
		}			
};

class Wings {
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	int col;
	
	public:
		Wings(){}
		
		void setWings(	int px1, int px2, int px3, int px4, int px5, int px6,
						int py1, int py2, int py3, int py4, int py5, int py6,
						int color) {
			x1 = px1;
			y1 = py1;		
			x2 = px2;
			y2 = py2;
			x3 = px3;
			y3 = py3;
			x4 = px4;
			y4 = py4;
			x5 = px5;
			y5 = py5;
			x6 = px6;
			y6 = py6;
			col = color;
		}
		void draw() {
			int points[12] = {  x1, y1,
								x2, y2,
								x3, y3,
								x4, y4,
								x5, y5,
								x6, y6};
			setfillstyle(1, col);
			fillpoly(6, points);
		}
};

class Head {
	int x, y, rad;
	int ex1, ey1, ex2, ey2, erad;
	
	public:
		Circle *eye1 = new Circle();
		Circle *eye2 = new Circle();
		Circle *dhead = new Circle();
		Circle *iris1 = new Circle();
		Circle *iris2 = new Circle();
		
		Head() {
			x = 300;
			y = 550;
			rad = 30;
		}
		void setHead() {
			ex1 = x - rad*0.4;
			ey1 = y - rad*0.93;
			ex2 = x + rad*0.4;
			ey2 = y - rad*0.93;
			erad =  rad*0.2;
			
			dhead->setCircle(x, y, rad, 15);
			eye1->setCircle(ex1, ey1, erad, 4);
			eye2->setCircle(ex2, ey2, erad, 4);
			iris1->setCircle(ex1, ey1, erad/2, 0);
			iris2->setCircle(ex2, ey2, erad/2, 0);
		}
		void drawHead() {
			dhead->draw();
			eye1->draw();
			eye2->draw();
			iris1->draw();
			iris2->draw();
		}
		void scale(int s) {
			rad = rad*s;
			setHead();
		}
		void moveUp() {
			y = y - 3;
		}
		void moveDown() {
			y = y + 3;
		}	
		void moveLeft() {
			x = x - 3;
		}
		void moveRight() {
			x = x + 3;
		}
		int getX() {
			return x;
		}
		int getY() {
			return y;
		}
};

class Body {
	
	int x, y, rad;
	int ax, ay, arad;
	int wx1, wx2, wx3, wx4, wx5, wx6;
	int wy1, wy2, wy3, wy4, wy5, wy6;
	int wwx1, wwx2, wwx3, wwx4, wwx5, wwx6;
	int wwy1, wwy2, wwy3, wwy4, wwy5, wwy6;
	
	public:
		
		Circle *butt = new Circle();
		Wings *wings1 = new Wings();
		Wings *wings2 = new Wings();
		Body() {
			x = 300;
			y = 550;
			rad = 30;
		}
		void setBody() {
			ax = x;
			ay = y + rad * 1.7;
			arad = rad * 1.6;
			
			wx1 = x;
			wy1 = ay - rad*1.8;
			wx2 = x - (rad*3.33);		
			wy2 = wy1 + (rad*1.13);		
			wx3 = x - (rad*2.0);
			wy3 = wy1 + (rad*3.67);
			wx4 = x;
			wy4 = wy1 + (rad*2.0);
			wx5 = x + (rad*2.0);
			wy5 = wy1 + (rad*3.67);
			wx6 = x + (rad*3.33);		
			wy6 = wy1 + (rad*1.13);
			
			wwx1 = wx1;
			wwy1 = wy1;
			wwx2 = wx2 + rad;
			wwy2 = wy2 + rad*0.83;
			wwx3 = wx3 + (rad*0.67);
			wwy3 = wy3;
			wwx4 = wx4;
			wwy4 = wy4;
			wwx5 = wx5 - (rad*0.67);
			wwy5 = wy5;
			wwx6 = wx6 - rad;
			wwy6 = wy6 + (rad*0.83);
		
			butt->setCircle(ax, ay, arad, 14);
			wings1->setWings(	wx1, wx2, wx3, wx4, wx5, wx6,
								wy1, wy2, wy3, wy4, wy5, wy6, 4);
			wings2->setWings(	wwx1, wwx2, wwx3, wwx4, wwx5, wwx6,
								wwy1, wwy2, wwy3, wwy4, wwy5, wwy6, 12);		
		}
		void drawBody() {
			butt->draw();
			wings1->draw();
			wings2->draw();
		}
		void scale(int s) {
			rad = rad*s;
			setBody();
		}
		void moveUp() {
			y = y - 3;
		}
		void moveDown() {
			y = y + 3;
		}	
		void moveLeft() {
			x = x - 3;
		}
		void moveRight() {
			x = x + 3;
		}
		int getX() {
			return x;
		}
		int getY() {
			return y;
		}
};

class IHead {
	int x, y, rad;
	int ex1, ey1, ex2, ey2, erad;
	
	public:
		Circle *ihead = new Circle();
		Circle *ieye1 = new Circle();
		Circle *ieye2 = new Circle();
		Circle *iiris1 = new Circle();
		Circle *iiris2 = new Circle();
		
		IHead() {
			x = 50;
			y = 0;
			rad = 10;
		}
		
		void setHeadXY(int xx, int yy) {
			x = xx;
			y = yy;
		}
		
		void setHead() {
			ex1 = x - (rad*0.4);
			ey1 = y + (rad*0.9);
			ex2 = x + (rad*0.4);
			ey2 = ey1;
			erad = rad*0.3;
			
			ihead->setCircle(x, y, rad, 1);
			ieye1->setCircle(ex1, ey1, erad, 5);
			ieye2->setCircle(ex2, ey2, erad, 5);
		}
		void drawHead() {
			ihead->draw();
			ieye1->draw();
			ieye2->draw();
		}
		void scale(int s) {
			rad = rad*s;
			setHead();
		}
		void moveUp() {
			y = y - 1;
		}
		void moveDown(int p) {
			y = y + p;
			//setHeadXY(x, y);
		}	
		void moveLeft() {
			x = x - 1;
		}
		void moveRight(int p) {
			x = x + p;
		}
		int getX() {
			return x;
		}
		int getY() {
			return y;
		}
		int getRad() {
			return rad;
		}
};

class IBody {
	
	int x, y, rad;
	int ax, ay, arad;
	int wx1, wx2, wx3, wx4, wx5, wx6;
	int wy1, wy2, wy3, wy4, wy5, wy6;
	int wwx1, wwx2, wwx3, wwx4, wwx5, wwx6;
	int wwy1, wwy2, wwy3, wwy4, wwy5, wwy6;
	
	public:
	
		Wings *wings1 = new Wings();
		Wings *wings2 = new Wings();
		
		IBody() {
			x = 50;
			y = 0;
			rad = 10;
		}
		void setBodyXY(int xx, int yy) {
			x = xx;
			y = yy;
		}
		void setBody() {
			wx1 = x + rad*0.5;
			wy1 = y - rad*0.3;
			wx2 = x + rad*1.3;
			wy2 = y - rad*1.3;
			wx3 = wx1;
			wy3 = y - rad*2.5;
			wx4 = x - rad*0.5;
			wy4 = wy3;
			wx5 = x - rad*1.3;
			wy5 = wy2;
			wx6 = wx4;
			wy6 = wy1;
			
		
			wings1->setWings(	wx1, wx2, wx3, wx4, wx5, wx6,
								wy1, wy2, wy3, wy4, wy5, wy6, 4);
//			wings2->setWings(	wwx1, wwx2, wwx3, wwx4, wwx5, wwx6,
//								wwy1, wwy2, wwy3, wwy4, wwy5, wwy6, 12);		
		}
		void drawBody() {
			wings1->draw();
		}
		void scale(int s) {
			rad = rad*s;
			setBody();
		}
		void moveUp() {
			y = y - 1;
		}
		void moveDown(int p) {
			y = y + p;
			setBodyXY(x, y);
		}	
		void moveLeft() {
			x = x - 1;
		}
		void moveRight(int p) {
			x = x + p;
		}
		int getX() {
			return x;
		}
		int getY() {
			return y;
		}
};

class Defender {
	public:
		int bullctr = 0;
		Head *head = new Head();
		Body *body = new Body();
		
		void setDefender() {
			head->setHead();
			body->setBody();
		}
		void drawDefender() {
			head->drawHead();
			body->drawBody();
		}
		void scaleDefender(int s) {
			head->scale(s);
			body->scale(s);
		}
		void moveUpDefender() {
			head->moveUp();
			body->moveUp();
		}
		void moveDownDefender() {
			head->moveDown();
			body->moveDown();
		}
		void moveLeftDefender() {
			head->moveLeft();
			body->moveLeft();
		}
		void moveRightDefender() {
			head->moveRight();
			body->moveRight();
		}
		int getDx() {
			head->getX();
		}
		int getDy() {
			head->getY();
		}
		void move() {
		 if (GetAsyncKeyState(VK_RIGHT)) {
				moveRightDefender();
			} else if (GetAsyncKeyState(VK_LEFT)) {
				moveLeftDefender();
			} if (GetAsyncKeyState(VK_SPACE)) {
				
			}
		}
};

class Invader {
	public:
		IHead *head = new IHead();
		IBody *body = new IBody();
		
		void setInvader(int x, int y) {
			head->setHeadXY(x, y);
			body->setBodyXY(x, y);
			head->setHead();
			body->setBody();
		}
		void drawInvader() {
			head->drawHead();
			body->drawBody();
		}
		void scaleInvader(int s) {
			head->scale(s);
			body->scale(s);
		}
		void move(int l, int ctr) {
			if(ctr%5 != 0) {
				head->moveDown(l);
				body->moveDown(l);
			} else {
				head->moveRight(l);
				body->moveRight(l);
			}

		}
		int getX() {
			head->getX();
		}
		int getY() {
			head->getY();
		}	
		int getRad() {
			head->getRad();
		}
};

class InvaderArray {
	int x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15;
	int y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12, y13, y14, y15;
	float scale;
	int x, y, rad;
	
	public:
		Invader *i1 = new Invader();
		Invader *i2 = new Invader();
		Invader *i3 = new Invader();
		Invader *i4 = new Invader();
		Invader *i5 = new Invader();
		Invader *i6 = new Invader();
		Invader *i7 = new Invader();
		Invader *i8 = new Invader();
		Invader *i9 = new Invader();
		Invader *i10 = new Invader();
		Invader *i11 = new Invader();
		Invader *i12 = new Invader();
		Invader *i13 = new Invader();
		Invader *i14 = new Invader();
		Invader *i15 = new Invader();
		Invader *i16 = new Invader();
		Invader *i17 = new Invader();
		Invader *i18 = new Invader();
		Invader *i19 = new Invader();
		Invader *i20 = new Invader();
		Invader *i21 = new Invader();
		Invader *i22 = new Invader();
		Invader *i23 = new Invader();
		Invader *i24 = new Invader();
		Invader *i25 = new Invader();
		
		InvaderArray() {
			x = 50;
			y = -10;
			rad = 10;
		}
		void setInvaderArray() {
			x1 = x;
			y1 = y;
			x2 = x+rad*5;
			y2 = y;
			x3 = x+rad*10;
			y3 = y;
			x4 = x+rad*15;
			y4 = y;
			x5 = x+rad*20;
			y5 = y;
			x6 = x;
			y6 = y-rad*20;
			x7 = x+rad*5;
			y7 = y-rad*20;
			x8 = x+rad*10;
			y8 = y-rad*20;
			x9 = x+rad*15;
			y9 = y-rad*20;
			x10 = x+rad*20;
			y10 = y-rad*20;
			x11 = x;
			y11 = y-rad*40;
			x12 = x+rad*5;
			y12 = y-rad*40;
			x13 = x+rad*10;
			y13 = y-rad*40;
			x14 = x+rad*15;
			y14 = y-rad*40;
			x15 = x+rad*20;
			y15 = y-rad*40;
			
			
			i1->setInvader(x1, y1);
			i2->setInvader(x2, y2);
			i3->setInvader(x3, y3);
			i4->setInvader(x4, y4);
			i5->setInvader(x5, y5);
			i6->setInvader(x6, y6);
			i7->setInvader(x7, y7);
			i8->setInvader(x8, y8);
			i9->setInvader(x9, y9);
			i10->setInvader(x10, y10);
			i11->setInvader(x11, y11);
			i12->setInvader(x12, y12);
			i13->setInvader(x13, y13);
			i14->setInvader(x14, y14);
			i15->setInvader(x15, y15);
		}
		
		void scaleInvaderArray(float s) {
			scale = s;
			i1->scaleInvader(s);
			i2->scaleInvader(s);
			i3->scaleInvader(s);
			i4->scaleInvader(s);
			i5->scaleInvader(s);
			i6->scaleInvader(s);
			i7->scaleInvader(s);
			i8->scaleInvader(s);
			i9->scaleInvader(s);
			i10->scaleInvader(s);
			i11->scaleInvader(s);
			i12->scaleInvader(s);
			i13->scaleInvader(s);
			i14->scaleInvader(s);
			i15->scaleInvader(s);
		}
		
		void drawInvader() {
			i1->drawInvader();
			i2->drawInvader();
			i3->drawInvader();
			i4->drawInvader();
			i5->drawInvader();
			i6->drawInvader();
			i7->drawInvader();
			i8->drawInvader();
			i9->drawInvader();
			i10->drawInvader();
			i11->drawInvader();
			i12->drawInvader();
			i13->drawInvader();
			i14->drawInvader();
			i15->drawInvader();
		}
		void move(int l, int ctr) {
			i1->move(l, ctr);
			i2->move(l, ctr);
			i3->move(l, ctr);
			i4->move(l, ctr);
			i5->move(l, ctr);
			i6->move(l, ctr);
			i7->move(l, ctr);
			i8->move(l, ctr);
			i9->move(l, ctr);
			i10->move(l, ctr);
			i11->move(l, ctr);
			i12->move(l, ctr);
			i13->move(l, ctr);
			i14->move(l, ctr);
			i15->move(l, ctr);	
		}
		int getScale() {
			return scale;
		}
		int getX() {
			i1->getX();
		}
		int getY() {
			i1->getY();
		}
		int get2X() {
			i2->getX();
		}
		int get2Y() {
			i2->getY();
		}
		int get3X() {
			i3->getX();
		}
		int get3Y() {
			i3->getY();
		}
		int get4X() {
			i4->getX();
		}
		int get4Y() {
			i4->getY();
		}
		int get5X() {
			i5->getX();
		}
		int get5Y() {
			i5->getY();
		}
		int get6X() {
			i6->getX();
		}
		int get6Y() {
			i6->getY();
		}
		int get7X() {
			i7->getX();
		}
		int get7Y() {
			i7->getY();
		}	
		int get8X() {
			i8->getX();
		}
		int get8Y() {
			i8->getY();
		}
		int get9X() {
			i9->getX();
		}
		int get9Y() {
			i9->getY();
		}
		int get10X() {
			i10->getX();
		}
		int get10Y() {
			i10->getY();
		}
		int get11X() {
			i11->getX();
		}
		int get11Y() {
			i11->getY();
		}
		int get12X() {
			i12->getX();
		}
		int get12Y() {
			i12->getY();
		}	
		int get13X() {
			i13->getX();
		}
		int get13Y() {
			i13->getY();
		}
		int get14X() {
			i14->getX();
		}
		int get14Y() {
			i14->getY();
		}
		int get15X() {
			i15->getX();
		}
		int get15Y() {
			i15->getY();
		}
		int getRad() {
			i1->getRad();
		}
};

class Envi {
	
	int ix, iy, dx, dy, bx, by;
	int bx2, by2, bx3, by3, bx4, by4, bx5, by5;
	int bx1, by1;
	int brad;
	int ix2, iy2;
	int ix3, iy3;
	int ix4, iy4;
	int ix5, iy5;
	int ix6, iy6;
	int ix7, iy7;
	int ix8, iy8;
	int ix9, iy9;
	int ix10, iy10;
	int ix11, iy11;
	int ix12, iy12;
	int ix13, iy13;
	int ix14, iy14;
	int ix15, iy15;
	int numberOfHits = 0;
	int collide = 0;
	int r;
	
	public:
		
		
		Background *bg = new Background();
		Defender *defender = new Defender();
		InvaderArray *inv = new InvaderArray();
		Bullet *b1 = new Bullet();
		Boundary *bound = new Boundary();
		
		void setEnvi() {
			defender->setDefender();
			inv->setInvaderArray();
			bound->setLine();
		}
		void drawEnvi() {
			bg->drawBackground();
			defender->drawDefender();
			inv->drawInvader();
			b1->drawBullet();
			bound->drawLine();
		}
		void scaleEnvi(int s) {
			defender->scaleDefender(s);
			inv->scaleInvaderArray(s);
			bound->scaleLine(s);
		}		
		void moveEnvi(int p, int ctr) {
			ix = inv->getX();
			iy = inv->getY();
			ix2 = inv->get2X();
			iy2 = inv->get2Y();
			ix3 = inv->get3X();
			iy3 = inv->get3Y();
			ix4 = inv->get4X();
			iy4 = inv->get4Y();
			ix5 = inv->get5X();
			iy5 = inv->get5Y();
			ix6 = inv->get6X();
			iy6 = inv->get6Y();
			ix7 = inv->get7X();
			iy7 = inv->get7Y();
			ix8 = inv->get8X();
			iy8 = inv->get8Y();
			ix9 = inv->get9X();
			iy9 = inv->get9Y();
			ix10 = inv->get10X();
			iy10 = inv->get10Y();
			ix11 = inv->get11X();
			iy11 = inv->get11Y();
			ix12 = inv->get12X();
			iy12 = inv->get12Y();
			ix13 = inv->get13X();
			iy13 = inv->get13Y();
			ix14 = inv->get14X();
			iy14 = inv->get14Y();
			ix15 = inv->get15X();
			iy15 = inv->get15Y();
			
			r = inv->getRad();
			dx = defender->getDx();
			dy = defender->getDy();
			
			
		//	if(!checkCollision()) {
				inv->move(p, ctr);
				defender->move();
			
				if(GetAsyncKeyState(VK_SPACE)) {
					b1->set(dx, dy);
				}
				bx = b1->getX();
				by = b1->getY();
				
			for (int x = 0; x < 12; x++) {
				if(by > 0) {	
					b1->moveBullet();
					bx = b1->getX();
					by = b1->getY();
					brad = b1->getRad() * 1.4;
						
					if(checkHit()) {
						b1->set(-100, -100);
						numberOfHits++;
						cout << "number of hits" << numberOfHits << endl;
					}
				} else {
					b1->set(-100, -100);
				}
			}
		}
		bool checkCollision() {
				
				int xx = 500;
					if(iy >= xx || iy2 >= xx || iy3 >= xx || iy4 >= xx || iy5 >= xx || iy6 >= xx || iy7 >= xx || iy8 >= xx || iy9 >= xx || iy10 >= xx || iy11 >= xx || iy12 >= xx || iy13 >= xx || iy14 >= xx || iy15 >= xx) {
						cout << "HIT IY 	" << iy << " boundaryY	" << xx << endl;
						cout << "HIT IY 	" << iy2 << " boundaryY	" << xx << endl;
						cout << "HIT IY 	" << iy3 << " boundaryY	" << xx << endl;
						cout << "HIT IY 	" << iy4 << " boundaryY	" << xx << endl;
						cout << "HIT IY5 	" << iy5 << " boundaryY	" << xx << endl;
						cout << "HIT IY 	" << iy6 << " boundaryY	" << xx << endl;
						cout << "HIT IY 	" << iy7 << " boundaryY	" << xx << endl;
						cout << "HIT IY 	" << iy8 << " boundaryY	" << xx << endl;
						cout << "HIT IY 	" << iy9 << " boundaryY	" << xx << endl;
						cout << "HIT IY 	" << iy10 << " boundaryY	" << xx << endl;
						cout << "HIT IY 	" << iy11 << " boundaryY	" << xx << endl;
						cout << "HIT IY 	" << iy12 << " boundaryY	" << xx << endl;
						cout << "HIT IY 	" << iy13 << " boundaryY	" << xx << endl;
						cout << "HIT IY 	" << iy14 << " boundaryY	" << xx << endl;
						cout << "HIT IY 	" << iy15 << " boundaryY	" << xx << endl;
						
						return true;
					} else {
						return false;
					}
		}
		int getHits() {
			return numberOfHits;
		}
		int getCollide() {
			if(checkCollision()) {
				return 1;
			} else {
				return 0;
			}
		}
		bool checkHit() {
			for(int j = 0; j <= brad; j++) {
				for(int z = 0; z <= r; z++) {
					if((((bx + j) == (ix - z) || (bx + j) == (ix + z)) && (by == iy)))  {
							cout << "=======MOVE=======" << endl;
							cout << " inv 	x " << ix << " y " << iy << endl;
							cout << " def 	x " << dx << " y " << dy << endl;
							cout << " bul1 	x " << bx << " y " << by << endl;
							inv->i1->scaleInvader(0);
							inv->i1->setInvader(-10000, -10000);
							return true;
					} else if((((bx + j) == (ix2 - z) || (bx + j) == (ix2 + z)) && (by == iy2)))  {
							cout << "=======MOVE=======" << endl;
							cout << " inv 	x " << ix2 << " y " << iy2 << endl;
							cout << " def 	x " << dx << " y " << dy << endl;
							cout << " bul1 	x " << bx << " y " << by << endl;
							inv->i2->scaleInvader(0);
							inv->i2->setInvader(-10000, -10000);
							b1->reset();
							return true;
					} else if((((bx + j) == (ix3 - z) || (bx + j) == (ix3 + z)) && (by == iy3)))  {
							cout << "=======MOVE=======" << endl;
							cout << " inv 	x " << ix3 << " y " << iy3 << endl;
							cout << " def 	x " << dx << " y " << dy << endl;
							cout << " bul1 	x " << bx << " y " << by << endl;
							inv->i3->scaleInvader(0);
							inv->i3->setInvader(-10000, -10000);
							return true;
					} else if((((bx + j) == (ix4 - z) || (bx + j) == (ix4 + z)) && (by == iy4)))  {
							cout << "=======MOVE=======" << endl;
							cout << " inv 	x " << ix4 << " y " << iy4 << endl;
							cout << " def 	x " << dx << " y " << dy << endl;
							cout << " bul1 	x " << bx << " y " << by << endl;
							inv->i4->scaleInvader(0);
							inv->i4->setInvader(-10000, -10000);
							b1->reset();
							return true;
					} else if((((bx + j) == (ix5 - z) || (bx + j) == (ix5 + z)) && (by == iy5)))  {
							cout << "=======MOVE=======" << endl;
							cout << " inv 	x " << ix5 << " y " << iy5 << endl;
							cout << " def 	x " << dx << " y " << dy << endl;
							cout << " bul1 	x " << bx << " y " << by << endl;
//							inv->i5->scaleInvader(0);
							inv->i5->setInvader(-10000, -10000);
							b1->reset();
							return true;
					} else if((((bx + j) == (ix6 - z) || (bx + j) == (ix6 + z)) && (by == iy6)))  {
							cout << "=======MOVE=======" << endl;
							cout << " inv 	x " << ix6 << " y " << iy6 << endl;
							cout << " def 	x " << dx << " y " << dy << endl;
							cout << " bul1 	x " << bx << " y " << by << endl;
							inv->i6->scaleInvader(0);
							inv->i6->setInvader(-10000, -10000);
							b1->reset();
							return true;
					} else if((((bx + j) == (ix7 - z) || (bx + j) == (ix7 + z)) && (by == iy7)))  {
							cout << "=======MOVE=======" << endl;
							cout << " inv 	x " << ix7 << " y " << iy7 << endl;
							cout << " def 	x " << dx << " y " << dy << endl;
							cout << " bul1 	x " << bx << " y " << by << endl;
							inv->i7->scaleInvader(0);
							inv->i7->setInvader(-10000, -10000);
							b1->reset();
							return true;
					} else if((((bx + j) == (ix8 - z) || (bx + j) == (ix8 + z)) && (by == iy8)))  {
							cout << "=======MOVE=======" << endl;
							cout << " inv 	x " << ix8 << " y " << iy8 << endl;
							cout << " def 	x " << dx << " y " << dy << endl;
							cout << " bul1 	x " << bx << " y " << by << endl;
							inv->i8->scaleInvader(0);
							inv->i8->setInvader(-10000, -10000);
							b1->reset();
							return true;
					}  else if((((bx + j) == (ix9 - z) || (bx + j) == (ix9 + z)) && (by == iy9)))  {
							cout << "=======MOVE=======" << endl;
							cout << " inv 	x " << ix9 << " y " << iy9 << endl;
							cout << " def 	x " << dx << " y " << dy << endl;
							cout << " bul1 	x " << bx << " y " << by << endl;
							inv->i9->scaleInvader(0);
							inv->i9->setInvader(-10000, -10000);
							b1->reset();
							return true;
					} else if((((bx + j) == (ix10 - z) || (bx + j) == (ix10 + z)) && (by == iy10)))  {
							cout << "=======MOVE=======" << endl;
							cout << " inv 	x " << ix10 << " y " << iy10 << endl;
							cout << " def 	x " << dx << " y " << dy << endl;
							cout << " bul1 	x " << bx << " y " << by << endl;
							inv->i10->scaleInvader(0);
							inv->i10->setInvader(-10000, -10000);
							return true;
					} else if((((bx + j) == (ix11 - z) || (bx + j) == (ix11 + z)) && (by == iy11)))  {
							cout << "=======MOVE=======" << endl;
							cout << " inv 	x " << ix11 << " y " << iy11 << endl;
							cout << " def 	x " << dx << " y " << dy << endl;
							cout << " bul1 	x " << bx << " y " << by << endl;
							inv->i11->scaleInvader(0);
							inv->i11->setInvader(-10000, -10000);
							b1->reset();
							return true;
					} else if((((bx + j) == (ix12 - z) || (bx + j) == (ix12 + z)) && (by == iy12)))  {
							cout << "=======MOVE=======" << endl;
							cout << " inv 	x " << ix12 << " y " << iy12 << endl;
							cout << " def 	x " << dx << " y " << dy << endl;
							cout << " bul1 	x " << bx << " y " << by << endl;
							inv->i12->scaleInvader(0);
							inv->i12->setInvader(-10000, -10000);
							b1->reset();
							return true;
					} else if((((bx + j) == (ix13 - z) || (bx + j) == (ix13 + z)) && (by == iy13)))  {
							cout << "=======MOVE=======" << endl;
							cout << " inv 	x " << ix13 << " y " << iy13 << endl;
							cout << " def 	x " << dx << " y " << dy << endl;
							cout << " bul1 	x " << bx << " y " << by << endl;
							inv->i13->scaleInvader(0);
							inv->i13->setInvader(-10000, -10000);
							return true;
					} else if((((bx + j) == (ix14 - z) || (bx + j) == (ix14 + z)) && (by == iy14)))  {
							cout << "=======MOVE=======" << endl;
							cout << " inv 	x " << ix14 << " y " << iy14 << endl;
							cout << " def 	x " << dx << " y " << dy << endl;
							cout << " bul1 	x " << bx << " y " << by << endl;
							inv->i14->scaleInvader(0);
							inv->i14->setInvader(-10000, -10000);
							b1->reset();
							return true;
					} else if((((bx + j) == (ix15 - z) || (bx + j) == (ix15 + z)) && (by == iy15)))  {
							cout << "=======MOVE=======" << endl;
							cout << " inv 	x " << ix15 << " y " << iy15 << endl;
							cout << " def 	x " << dx << " y " << dy << endl;
							cout << " bul1 	x " << bx << " y " << by << endl;
							inv->i15->scaleInvader(0);
							inv->i15->setInvader(-10000, -10000);
							b1->reset();
							return true;
					}
				}
			} return false;
		}
		
		
};

class Levels {
	public: 
		Level(){
		}
		void setLevel(){
			
		}
};
int main() {
	
	
	initwindow(600, 700, "MULT");
	
	
	int page = 0;
	int shot = 1;
	int d = 100;
	bool hit = false;
	int page1 = 0;
	int page2 = 0;
	
	int level = 1;
	int pace = 1;
	int ctr = 0;
	int win = 1;
	int collide; 
	bool hitt = false;
	int hits;
	

	
	while(level > 0) {
		Envi *envi = new Envi();
		collide = envi->getCollide();
		envi->bg->drawBackground();
		cout << "level" << level << endl;
		if(level == 1) {
			outtextxy(250, 350, "LEVEL 1");
		}
//		} else if (level == 2) {
//			outtextxy(250, 350, "LEVEL 2");
//		} else if (level == 3) {
//			outtextxy(250, 350, "LEVEL 3");
//		} else if (level == 4) {
//			outtextxy(250, 350, "LEVEL 4");
//		} else if (level == 5) {
//			outtextxy(250, 350, "LEVEL 5");
//		} else if (level == 6) {
//			outtextxy(250, 350, "LEVEL 6");
//		} else if (level == 7) {
//			outtextxy(250, 350, "LEVEL 7");
//		} else if (level == 8) {
//			outtextxy(250, 350, "LEVEL 8");
//		} else {
//			outtextxy(250, 300, "MASTER LEVEL");
//		}
		
		setactivepage(page1);
		setvisualpage(1-page1);
		delay(2000);
		
		hits = 0;
		hitt = false;
		collide = 0;
		envi->setEnvi();
		
		
		while(!hitt) {
			setactivepage(page);
			setvisualpage(1-page);
			delay(10);
			cout << "hitt " << hitt << endl;
			collide = envi->getCollide();
			hits = envi->getHits();
			if(hits < 15 && collide == 0) {
				cout << "collide " << collide << endl;
				envi->scaleEnvi(1);
				envi->drawEnvi();
				envi->moveEnvi(pace, ctr);
				
				shot++;
				ctr++;
				hitt = false;	
			} else if (hit == 15) {
				level++;
				hitt = true;
			} else {
				
				
//				setactivepage(page2);
//				setvisualpage(1-page2);
//				outtextxy(250, 350, "Y O U  L O S E");
//				delay(10000);
//				page2 = 1-page2;
				hitt = true;
				
				
			}
				page = 1 - page;
		}
		
		if ( collide == 1) {
			level = 0;
		}
		//cout << "hits " << hits << " collide " << collide << endl;
		
		pace = pace*2;
		page1 = 1 - page1;	
	}
	

	return 0;
}



