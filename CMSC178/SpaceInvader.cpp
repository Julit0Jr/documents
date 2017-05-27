#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <dos.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

class Background{
	int backgroundCoor[10];
	int color;
	int stars;

	public:
		Background(int coor[10], int c, int stars){
			for(int i = 0; i < 10; i++){
				backgroundCoor[i] = coor[i];
			}
			color = c;
			this->stars = stars;
		}
		void drawBackground(){
			int x = 0, y = 0;
			setfillstyle(SOLID_FILL, color);
			fillpoly(5, backgroundCoor);
		   for(int i=0; i<=stars; i++) {
	       	 	x=rand()%getmaxx();
	          	y=rand()%getmaxy();
	          	putpixel(x,y,15);
			}
			settextstyle(BOLD_FONT, HORIZ_DIR, 1);
			outtextxy(10, 5, "LIFE");
		}
};
class Rect{
	int xstart, ystart, xend, yend;
	int side[8];
	float scalefactor;
	public:
		int color;
		Rect(int xstart, int ystart, int xend, int yend, int c){
			this->xstart = xstart;
			this->ystart = ystart;
			this->xend = xend;
			this->yend = yend;
			this->color = c;
			this->scalefactor = 1;
		}
		Rect(int xstart, int ystart, int xend, int yend){
			this->xstart = xstart;
			this->ystart = ystart;
			this->xend = xend;
			this->yend = yend;
			this->color = RED;
			this->scalefactor = 1;
		}
		void drawRect(){
			setcolor(color);
			side[0] = xstart * scalefactor;
			side[1] = ystart * scalefactor;
			side[2] = xstart * scalefactor;
			side[3] = yend * scalefactor;
			side[4] = xend * scalefactor;
			side[5] = yend * scalefactor;
			side[6] = xend * scalefactor;
			side[7] = ystart * scalefactor;
			setfillstyle(USER_FILL, color);
			fillpoly(4, side);
		}
		void drawStylishRect(){
			setcolor(color);
			side[0] = xstart * scalefactor;
			side[1] = ystart * scalefactor;
			side[2] = xstart * scalefactor;
			side[3] = yend * scalefactor;
			side[4] = xend * scalefactor;
			side[5] = yend * scalefactor;
			side[6] = xend * scalefactor;
			side[7] = ystart * scalefactor;
			setfillstyle(INTERLEAVE_FILL, color);
			fillpoly(4, side);
		}
		void scaleRect(float scaleFactor){
			this->scalefactor = scaleFactor;
		}
		void translateRect(int x, int y){
			this->xstart += x;
			this->ystart += y;
			this->xend += x;
			this->yend += y;
		}
};
class Avatar{
	int body[22], head[10];
	Rect *leftwingdesign, *rightwingdesign;
	Rect *brace;
	public:
		Avatar(){
			int ulo[10] = {201, 200, 208, 200, 205, 190, 203, 190, 201, 200};
			int lawas[22] = {200, 200, 208, 200, 217, 233, 254, 233, 254, 243, 217, 249, 195, 249, 158, 243, 158, 233, 195, 233, 200,200};
			for(int i = 0; i < 22; i++){
				body[i] = lawas[i];
			}
			for(int i = 0; i < 10; i++){
				head[i] = ulo[i];
			}
			this->rightwingdesign = new Rect(221, 233, 248, 238, RED);
			this->leftwingdesign = new Rect(164, 233, 191, 238, RED);
			this->brace = new Rect(194, 226, 218, 229, RED);
			//Putting the Avatar at the starting position
			for(int i = 0; i< 15; i++){
				if(i < 6){
					this->translateAvatar(20, 20);
				}else{
					this->translateAvatar(0, 20);
				}
			}
		}
		void drawAvatar(){
			setcolor(WHITE);
			setfillstyle(SOLID_FILL, WHITE);
			fillpoly(11, body);
			setcolor(12);
			setfillstyle(SOLID_FILL, 12);
    		fillpoly(5, head);
    		setcolor(RED);
    		this->rightwingdesign->drawStylishRect();
    		this->leftwingdesign->drawStylishRect();
    		this->brace->drawStylishRect();
		}
		void translateAvatar(int x, int y){
			if(!(x < 0 && body[16] <= 6 || x > 0 && body[8] >= 1355/2 - 6 || y < 0 && head[7] <= 10 || y > 0 && body[11] >= 625)){
				for(int i = 0; i< 22; i++){
					if(i%2 == 0){
						body[i] += x;
					} else{
						body[i] += y;
					}
				}
				for(int i = 0; i< 10; i++){
					if(i%2 == 0){
						head[i] += x;
					} else{
						head[i] += y;
					}
				}
				this->rightwingdesign->translateRect(x, y);
				this->leftwingdesign->translateRect(x, y);
				this->brace->translateRect(x, y);
			}
		}
};
class Invader1{
	Rect *part1, *part2, *part3, *partfoot1, *partfoot2, *partfoot3, *leye, *reye;
	float distance;
	public:
		Invader1(int xmin, int ymin, int xmax, int ymax, int color){
			distance = (xmin + xmax)/8;
			this->part1 = new Rect(xmin, ymin, xmax, ymax, color);
			this->part2 = new Rect(xmin - distance, ymax, xmax + distance, ymax + (ymax - ymin), color);
			this->part3 = new Rect(xmin - distance*2, ymax + (ymax - ymin), xmax + distance*2, ymax + (ymax - ymin)*2, color);
			this->partfoot1 = new Rect(xmin - distance, ymax + (ymax - ymin)*2, xmin, ymax + (ymax - ymin)*3, color);
			this->partfoot2 = new Rect(xmin + distance/2, ymax + (ymax - ymin)*2, xmax - distance/2, ymax + (ymax - ymin)*3, color);
			this->partfoot3 = new Rect(xmax, ymax + (ymax - ymin)*2, xmax + distance, ymax + (ymax - ymin)*3, color);
			this->leye = new Rect(xmin - distance + distance / 2, ymax + distance/2, xmin + distance/2, ymax + (ymax - ymin) + distance/4, RED);
			this->reye = new Rect(xmax + distance - distance / 2, ymax + distance/2, xmax - distance/2, ymax + (ymax - ymin) + distance/4, RED);
		}
		Invader1(int xmin, int ymin, int xmax, int ymax){
			distance = (xmin + xmax)/8;
			this->part1 = new Rect(xmin, ymin, xmax, ymax, BLUE);
			this->part2 = new Rect(xmin - distance, ymax, xmax + distance, ymax + (ymax - ymin), BLUE);
			this->part3 = new Rect(xmin - distance*2, ymax + (ymax - ymin), xmax + distance*2, ymax + (ymax - ymin)*2, BLUE);
			this->partfoot1 = new Rect(xmin - distance, ymax + (ymax - ymin)*2, xmin, ymax + (ymax - ymin)*3, BLUE);
			this->partfoot2 = new Rect(xmin + distance/2, ymax + (ymax - ymin)*2, xmax - distance/2, ymax + (ymax - ymin)*3, BLUE);
			this->partfoot3 = new Rect(xmax, ymax + (ymax - ymin)*2, xmax + distance, ymax + (ymax - ymin)*3, BLUE);
			this->leye = new Rect(xmin - distance + distance / 2, ymax + distance/2, xmin + distance/2, ymax + (ymax - ymin) + distance/4, RED);
			this->reye = new Rect(xmax + distance - distance / 2, ymax + distance/2, xmax - distance/2, ymax + (ymax - ymin) + distance/4, RED);
		}
		void drawInvader1(){
//			int i = rand() % 3;
//			if(i == 0){
//				this->part1->color = RED;
//			} else if(i == 1){
//				this->part1->color = BLUE;
//			} else{
//				this->part1->color = GREEN;
//			}
			this->part1->drawStylishRect();
			this->part2->drawStylishRect();
			this->part3->drawStylishRect();
			this->partfoot1->drawStylishRect();
			this->partfoot2->drawStylishRect();
			this->partfoot3->drawStylishRect();
			this->leye->drawRect();
			this->reye->drawRect();
		}
		void translateInvader1(int x, int y){
			this->part1->translateRect(x, y);
			this->part2->translateRect(x, y);
			this->part3->translateRect(x, y);
			this->partfoot1->translateRect(x, y);
			this->partfoot2->translateRect(x, y);
			this->partfoot3->translateRect(x, y);
			this->leye->translateRect(x, y);
			this->reye->translateRect(x, y);
		}
};
class Invader2{
	Rect *part1, *part2, *parthead1, *parthead2, *partfoot1, *partfoot2, *leye, *reye, *mouth;
	float distance;
	public:
		Invader2(int xmin, int ymin, int xmax, int ymax, int color){
			distance = (xmin + xmax)/32;
			this->part1 = new Rect(xmin, ymin, xmax, ymax, color);
			this->part2 = new Rect(xmin - distance, ymax, xmax + distance, ymax + (ymax - ymin), color);
			this->partfoot1 = new Rect(xmin, ymax + (ymax - ymin), xmin + distance*1.5, ymax + (ymax - ymin)*2, color);
			this->partfoot2 = new Rect(xmax - distance*1.5, ymax + (ymax - ymin), xmax, ymax + (ymax - ymin)*2, color);
			this->parthead1 = new Rect(xmin + distance/2, ymax - (ymax - ymin), xmin + (distance/2)*3, ymax - (ymax - ymin)*2, color);
			this->parthead2 = new Rect(xmax - (distance/2)*3, ymax - (ymax - ymin), xmax - distance/2, ymax - (ymax - ymin)*2, color);
			this->leye = new Rect(xmin+distance/2, ymin + distance/2, xmin + (distance/2)*3, ymax + distance/4, RED);
			this->reye = new Rect(xmax - (distance/2)*3, ymin + distance/2, xmax - distance/2, ymax + distance/4, RED);
			this->mouth = new Rect(xmin + (distance/2)*3, ymax + distance/2, xmax - (distance/2)*3, ymax + (ymax - ymin) - distance/4, RED);
		}
		Invader2(int xmin, int ymin, int xmax, int ymax){
			distance = (xmin + xmax)/32;
			this->part1 = new Rect(xmin, ymin, xmax, ymax, BLUE);
			this->part2 = new Rect(xmin - distance, ymax, xmax + distance, ymax + (ymax - ymin), BLUE);
			this->partfoot1 = new Rect(xmin, ymax + (ymax - ymin), xmin + distance*1.5, ymax + (ymax - ymin)*2, BLUE);
			this->partfoot2 = new Rect(xmax - distance*1.5, ymax + (ymax - ymin), xmax, ymax + (ymax - ymin)*2, BLUE);
			this->parthead1 = new Rect(xmin + distance/2, ymax - (ymax - ymin), xmin + (distance/2)*3, ymax - (ymax - ymin)*2, BLUE);
			this->parthead2 = new Rect(xmax - (distance/2)*3, ymax - (ymax - ymin), xmax - distance/2, ymax - (ymax - ymin)*2, BLUE);
			this->leye = new Rect(xmin+distance/2, ymin + distance/2, xmin + (distance/2)*3, ymax + distance/4, RED);
			this->reye = new Rect(xmax - (distance/2)*3, ymin + distance/2, xmax - distance/2, ymax + distance/4, RED);
			this->mouth = new Rect(xmin + (distance/2)*3, ymax + distance/2, xmax - (distance/2)*3, ymax + (ymax - ymin) - distance/4, RED);
		}
		void drawInvader2(){
			this->part1->drawStylishRect();
			this->part2->drawStylishRect();
			this->partfoot1->drawStylishRect();
			this->partfoot2->drawStylishRect();
			this->parthead1->drawStylishRect();
			this->parthead2->drawStylishRect();
			this->leye->drawRect();
			this->reye->drawRect();
			this->mouth->drawRect();
		}
		void translateInvader2(int x, int y){
			this->part1->translateRect(x, y);
			this->part2->translateRect(x, y);
			this->partfoot1->translateRect(x, y);
			this->partfoot2->translateRect(x, y);
			this->parthead1->translateRect(x, y);
			this->parthead2->translateRect(x, y);
			this->leye->translateRect(x, y);
			this->reye->translateRect(x, y);
			this->mouth->translateRect(x, y);
		}
};
class Invader3{
	Rect *parthead, *partforehead, *partface, *partjaw, *partchin, *leye, *reye, *mouth;
	float distance;
	public:
		Invader3(int xmin, int ymin, int xmax, int ymax, int color){
			distance = (xmin + xmax)/64;
			this->partforehead = new Rect(xmin, ymin, xmax, ymax, color);
			this->parthead = new Rect(xmin + distance - distance/4, ymin - (ymax - ymin), xmax - distance + distance/4, ymax - (ymax - ymin), color);
			this->partface = new Rect(xmin - distance + distance/6, ymax, xmax + distance - distance/6, ymax + (ymax - ymin)*2.75, color);
			this->partjaw = new Rect(xmin, ymax + (ymax - ymin)*2.75, xmax, ymax + (ymax - ymin)*3.75, color);
			this->partchin = new Rect(xmin + distance - distance/2, ymax + (ymax - ymin)*3.75, xmax - distance + distance/2, ymax + (ymax - ymin)*4.75, color);
			this->leye = new Rect(xmin + distance/4, ymax, xmin + (distance/2)*2.5, ymax + (ymax - ymin), 12);
			this->reye = new Rect(xmax - (distance/2)*2.5, ymax, xmax - distance/4, ymax + (ymax - ymin), 12);
			this->mouth = new Rect(xmin + distance - distance/2, ymax + (ymax - ymin)*2, xmax - distance + distance/2, ymax + (ymax - ymin)*3, 12);
		}
		Invader3(int xmin, int ymin, int xmax, int ymax){
			distance = (xmin + xmax)/64;
			this->partforehead = new Rect(xmin, ymin, xmax, ymax, 5);
			this->parthead = new Rect(xmin + distance - distance/4, ymin - (ymax - ymin), xmax - distance + distance/4, ymax - (ymax - ymin), 5);
			this->partface = new Rect(xmin - distance + distance/6, ymax, xmax + distance - distance/6, ymax + (ymax - ymin)*2.75, 5);
			this->partjaw = new Rect(xmin, ymax + (ymax - ymin)*2.75, xmax, ymax + (ymax - ymin)*3.75, 5);
			this->partchin = new Rect(xmin + distance - distance/2, ymax + (ymax - ymin)*3.75, xmax - distance + distance/2, ymax + (ymax - ymin)*4.75, 5);
			this->leye = new Rect(xmin + distance/4, ymax, xmin + (distance/2)*2.5, ymax + (ymax - ymin), 12);
			this->reye = new Rect(xmax - (distance/2)*2.5, ymax, xmax - distance/4, ymax + (ymax - ymin), 12);
			this->mouth = new Rect(xmin + distance - distance/2, ymax + (ymax - ymin)*2, xmax - distance + distance/2, ymax + (ymax - ymin)*3, 12);
		}
		void drawInvader3(){
			this->parthead->drawStylishRect();
			this->partforehead->drawStylishRect();
			this->partface->drawStylishRect();
			this->partjaw->drawStylishRect();
			this->partchin->drawStylishRect();
			this->leye->drawRect();
			this->reye->drawRect();
			this->mouth->drawRect();
		}
		void translateInvader3(int x, int y){
			this->parthead->translateRect(x, y);
			this->partforehead->translateRect(x, y);
			this->partface->translateRect(x, y);
			this->partjaw->translateRect(x, y);
			this->partchin->translateRect(x, y);
			this->leye->translateRect(x, y);
			this->reye->translateRect(x, y);
			this->mouth->translateRect(x, y);
		}
};
class Invader4{
	Rect *parthead, *parthorn1, *parthorn2, *partlongfoot1, *partlongfoot2, *partfoot1, *partfoot2, *leye, *reye;
	float distance;
	public:
		Invader4(int xmin, int ymin, int xmax, int ymax, int color){
			distance = (xmin + xmax)/64;
			this->parthead = new Rect(xmin, ymin, xmax, ymax + (ymax - ymin), color);
			this->partlongfoot1 = new Rect(xmin - distance, ymax, xmin, ymax + (ymax - ymin)*2, color);
			this->partlongfoot2 = new Rect(xmax, ymax, xmax + distance, ymax + (ymax - ymin)*2, color);
			this->partfoot1 = new Rect(xmin + distance/2, ymax + (ymax - ymin), xmin + distance*1.5, ymax + (ymax - ymin)*2, color);
			this->partfoot2 = new Rect(xmax - distance*1.5, ymax + (ymax - ymin), xmax - distance/2, ymax + (ymax - ymin)*2, color);
			this->leye = new Rect(xmin + distance/2.5, ymin + (ymax - ymin)/2, xmin + distance*1.5, ymin + (ymax - ymin)*1.5, RED);
			this->reye = new Rect(xmax - distance*1.5, ymin + (ymax - ymin)/2, xmax - distance/2.5, ymin + (ymax - ymin)*1.5, RED);
			this->parthorn1 = new Rect(xmin + distance/2, ymin - (ymax - ymin), xmin + distance*1.5, ymax - (ymax - ymin), color);
			this->parthorn2 = new Rect(xmax - distance*1.5, ymin - (ymax - ymin), xmax - distance/2, ymax - (ymax - ymin), color);
		}
		Invader4(int xmin, int ymin, int xmax, int ymax){

		}
		void drawInvader4(){
			this->parthead->drawStylishRect();
			this->partlongfoot1->drawStylishRect();
			this->partlongfoot2->drawStylishRect();
			this->partfoot1->drawStylishRect();
			this->partfoot2->drawStylishRect();
			this->leye->drawRect();
			this->reye->drawRect();
			this->parthorn1->drawStylishRect();
			this->parthorn2->drawStylishRect();
		}
		void stranslateInvader4(int x, int y){
			this->parthead->translateRect(x, y);
			this->partlongfoot1->translateRect(x, y);
			this->partlongfoot2->translateRect(x, y);
			this->partfoot1->translateRect(x, y);
			this->partfoot2->translateRect(x, y);
			this->leye->translateRect(x, y);
			this->reye->translateRect(x, y);
			this->parthorn1->translateRect(x, y);
			this->parthorn2->translateRect(x, y);
		}
};
class Environment{
	Background *bg;
	Invader1 *n;
	Invader2 *n2;
	Invader3 *n3;
	Invader4 *n4;
	public:
		Environment(int windowWidth, int windowHeight){
			int bgCoordinate[10] = {windowWidth - windowWidth, windowHeight - windowHeight, windowWidth, windowHeight - windowHeight, windowWidth, windowHeight, windowWidth - windowWidth, windowHeight, windowWidth - windowWidth, windowHeight - windowHeight};
			this->bg = new Background(bgCoordinate, 0, 100);
			this->n = new Invader1(50, 50, 70, 60, BLUE);
			this->n2 = new Invader2(150, 50, 190, 60, GREEN);
			this->n3 = new Invader3(500, 50, 545, 60, 9);
			this->n4 = new Invader4(250, 50, 280, 60, 5);
		}
		void drawEnvironment(){
			this->bg->drawBackground();
			this->n->drawInvader1();
			this->n2->drawInvader2();
			this->n3->drawInvader3();
			this->n4->drawInvader4();
			this->n->translateInvader1(0, 4);
			this->n2->translateInvader2(0, 6);
			this->n3->translateInvader3(0,7);
			this->n4->stranslateInvader4(0, 5);
		}
};
void initGameWindow(){
	int windowHeight = 650, windowWidth = 1355/2;
	struct arccoordstype a, b;
	int x = 0, y = 0, color, angle = 0;
	initwindow(windowWidth, windowHeight, "Space Invader");
	while(angle <= 360){
		setcolor(BLACK);
		arc(getmaxx()/2, getmaxy()/2, angle, angle + 2, 100);
		setcolor(RED);
		getarccoords(&a);
		setfillstyle(SOLID_FILL, RED);
		circle(a.xstart, a.ystart, 25);
		setcolor(BLACK);
		arc(getmaxx()/2, getmaxy()/2, angle, angle + 2, 150);
		getarccoords(&a);
		setcolor(GREEN);
		circle(a.xstart, a.ystart, 25);
		setcolor(BLACK);
		arc(getmaxx()/2, getmaxy()/2, angle, angle + 2, 200);
		getarccoords(&a);
		setcolor(BLUE);
		circle(a.xstart, a.ystart, 25);
		angle = angle + 5;
		delay(1);
	}
	setcolor(WHITE);
	settextstyle(3, HORIZ_DIR, 5);
	outtextxy(1355/4 - 73, 300, "ENTER");
	getch();
}
int main(){
	initGameWindow();
	int life = 5;
	Environment *envi = new Environment(1355/2, 650); // windowHeight = 650, windowWidth = 1355/2;
	Avatar *ava = new Avatar();
	ava->drawAvatar();
	envi->drawEnvironment();
	do{
		envi->drawEnvironment();
		if(kbhit()){
	        if (GetAsyncKeyState(VK_RIGHT)){
	        	ava->translateAvatar(20, 0);
	        }
	        if (GetAsyncKeyState(VK_LEFT)){
				ava->translateAvatar(-20, 0);
	        }
	        if (GetAsyncKeyState(VK_UP)){
				ava->translateAvatar(0, -20);
	        }
	        if (GetAsyncKeyState(VK_DOWN)){
	        	ava->translateAvatar(0, 20);
	        }
 		}
		ava->drawAvatar();
		delay(200);
	}while(life != 0);
	getch();
    return 0;
}
