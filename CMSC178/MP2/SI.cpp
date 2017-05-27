#include<graphics.h>
#include<conio.h>
#include<stdio.h> 
#include <iostream>
#include <dos.h>
#include <stdlib.h>
#include <cstdlib>
#include <MMSystem.h>

using namespace std;

class Arrow{
	int xstart, ystart, xend, yend;
	float scalefactor;
	public:
		int side[6];
		int color;
		Arrow(int xstart, int ystart, int xend, int yend, int c){
			this->xstart = xstart;
			this->ystart = ystart;
			this->xend = xend;
			this->yend = yend;
			this->color = c;
			this->scalefactor = 1;
		}
		Arrow(int xstart, int ystart, int xend, int yend){
			this->xstart = xstart;
			this->ystart = ystart;
			this->xend = xend;
			this->yend = yend;
			this->color = RED;
			this->scalefactor = 1;
		}
		void drawArrow(){
			setcolor(color);
			side[0] = xstart * scalefactor;
			side[1] = ystart * scalefactor;
			side[2] = xstart * scalefactor;
			side[3] = yend * scalefactor;
			side[4] = xend * scalefactor; 
			side[5] = ystart + (yend - ystart) /2* scalefactor;
			setfillstyle(USER_FILL, color);
			fillpoly(3, side);
		}
		void drawStylishArrow(){
			setcolor(color);
			side[0] = xstart * scalefactor;
			side[1] = ystart * scalefactor;
			side[2] = xstart * scalefactor;
			side[3] = yend * scalefactor;
			side[4] = xend * scalefactor; 
			side[5] = ystart + (yend - ystart /2)* scalefactor;
			setfillstyle(INTERLEAVE_FILL, color);
			fillpoly(4, side);
		}
		void scaleArrow(float scaleFactor){
			this->scalefactor = scaleFactor;
		}
		void translateArrow(int x, int y){
			this->xstart += x;
			this->ystart += y;
			this->xend += x;
			this->yend += y;
		}
};
class Background{
	int backgroundCoor[10];
	int color;
	int stars;
	public:
		Background(int coor[10], int c, int stars){
			for(int i = 0; i < 10; i++){
				backgroundCoor[i] = coor[i];
			}
			this->color = c;
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
//			settextstyle(BOLD_FONT, HORIZ_DIR, 1);
//			outtextxy(10, 5, "LIFE");
		}
};
class Rect{
	int xstart, ystart, xend, yend;
	float scalefactor;
	public:
		int side[8];
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
class Rock{
	float distance;
	public:
		Rect *block1, *block2, *block3, *block4, *block5, *block6, *block7, *block8, *block9, *block10, *block11;
		Rock(int xmin, int ymin, int xmax, int ymax){
			distance = (xmin + xmax)/32;
			this->block1 = new Rect(xmin, ymin, xmax, ymax, 8);
			this->block2 = new Rect(xmin - distance, ymin + (ymax - ymin)/2, xmin + distance/2, ymax + (ymax - ymin)/2, 8);
			this->block3 = new Rect(xmax - distance/1.5, ymin + (ymax - ymin)/1.5, xmax + distance/1.5, ymax + (ymax - ymin)/1.5, 8);
			this->block4 = new Rect(xmin - distance - distance/2, ymin + (ymax - ymin), xmin - distance/8, ymax + (ymax - ymin), 8);
			this->block5 = new Rect(xmax + distance/8, ymin + (ymax - ymin), xmax + distance*1.25, ymax + (ymax - ymin), 8);
			this->block6 = new Rect(xmin - distance/2, ymin + (ymax - ymin)*1.25, xmin + distance/1.2, ymax + (ymax - ymin)*1.25, 7);
			this->block7 = new Rect(xmax - distance, ymin + (ymax - ymin)*1.5, xmax + distance/2, ymax + (ymax - ymin)*1.5, 7);
			this->block8 = new Rect(xmin - distance/1.5, ymin + (ymax - ymin)*1.75, xmin + distance/1.5, ymax + (ymax - ymin)*1.75, 8);
			this->block9 = new Rect(xmax - distance - distance/3, ymin + (ymax - ymin)*2, xmax + distance/4, ymax + (ymax - ymin)*2, 8);
			this->block10 = new Rect(xmin, ymin + (ymax - ymin)/1.25, xmax, ymax + (ymax - ymin)/1.5, 7);
			this->block11 = new Rect(xmin - distance/4, ymin + (ymax - ymin)*2.5, xmin + distance, ymax + (ymax - ymin)*2.25, 8);
		}
		void drawRock(){
			this->block1->drawStylishRect();
			this->block4->drawStylishRect();
			this->block8->drawStylishRect();
			this->block5->drawStylishRect();
			this->block11->drawStylishRect();
			this->block9->drawStylishRect();
			this->block2->drawStylishRect();
			this->block3->drawStylishRect();
			this->block6->drawStylishRect();
			this->block7->drawStylishRect();
			this->block10->drawStylishRect();
		}
		void translateRock(int x, int y){
			this->block1->translateRect(x, y);
			this->block2->translateRect(x, y);
			this->block3->translateRect(x, y);
			this->block4->translateRect(x, y);
			this->block5->translateRect(x, y);
			this->block6->translateRect(x, y);
			this->block7->translateRect(x, y);
			this->block8->translateRect(x, y);
			this->block9->translateRect(x, y);
			this->block10->translateRect(x, y);
			this->block11->translateRect(x, y);
		}
};
class Avatar{
	Rect *leftwingdesign, *rightwingdesign;
	Rect *brace;
	Rect *light1, *light2;
	public:
		int body[22], head[10];
		int life, points;
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
			this->light1 = new Rect(195, 233, 217, 233, RED);
			this->light2 = new Rect(195, 233, 217, 233, RED);
			this->brace = new Rect(194, 226, 218, 229, RED);
			this->life = 1;
			this->points = 1;
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
	float distance;
	public:
		Rect *part1, *part2, *part3, *partfoot1, *partfoot2, *partfoot3, *leye, *reye;
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
	float distance;
	public:
		Rect *part1, *part2, *parthead1, *parthead2, *partfoot1, *partfoot2, *leye, *reye, *mouth;
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
	float distance;
	public:
		Rect *parthead, *partforehead, *partface, *partjaw, *partchin, *leye, *reye, *mouth;
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
	float distance;
	public:
		Rect *parthead, *parthorn1, *parthorn2, *partlongfoot1, *partlongfoot2, *partfoot1, *partfoot2, *leye, *reye;
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
			distance = (xmin + xmax)/64;
			this->parthead = new Rect(xmin, ymin, xmax, ymax + (ymax - ymin), 5);
			this->partlongfoot1 = new Rect(xmin - distance, ymax, xmin, ymax + (ymax - ymin)*2, 5);
			this->partlongfoot2 = new Rect(xmax, ymax, xmax + distance, ymax + (ymax - ymin)*2, 5);
			this->partfoot1 = new Rect(xmin + distance/2, ymax + (ymax - ymin), xmin + distance*1.5, ymax + (ymax - ymin)*2, 5);
			this->partfoot2 = new Rect(xmax - distance*1.5, ymax + (ymax - ymin), xmax - distance/2, ymax + (ymax - ymin)*2, 5);
			this->leye = new Rect(xmin + distance/2.5, ymin + (ymax - ymin)/2, xmin + distance*1.5, ymin + (ymax - ymin)*1.5, RED);
			this->reye = new Rect(xmax - distance*1.5, ymin + (ymax - ymin)/2, xmax - distance/2.5, ymin + (ymax - ymin)*1.5, RED);
			this->parthorn1 = new Rect(xmin + distance/2, ymin - (ymax - ymin), xmin + distance*1.5, ymax - (ymax - ymin), 5);
			this->parthorn2 = new Rect(xmax - distance*1.5, ymin - (ymax - ymin), xmax - distance/2, ymax - (ymax - ymin), 5);
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
		void translateInvader4(int x, int y){
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
class Invader5{
	float distance;
	public:
		Rect *body1, *body2, *body3, *body4, *leg1, *leg2, *leg3, *leg4, *foot1, *foot2, *horn1, *horn2, *upperhorn1, *upperhorn2, *leye, *reye;
		Invader5(int xmin, int ymin, int xmax, int ymax, int color){
			distance = (xmin + xmax)/64;
			this->body1 = new Rect(xmin, ymin, xmax, ymax, color);
			this->body2 = new Rect(xmin - distance, ymin + (ymax- ymin), xmax + distance, ymax + (ymax-ymin), color);
			this->body3 = new Rect(xmin - distance*2, ymax + (ymax- ymin), xmax + distance*2, ymax + (ymax-ymin)*2, color);
			this->body4 = new Rect(xmin - distance/1.5, ymax + (ymax- ymin)*2, xmax + distance/1.5, ymax + (ymax-ymin)*3, color);
			this->leg1 = new Rect(xmin - distance*2, ymax + (ymax- ymin)*2, xmin - distance*1.5, ymax + (ymax-ymin)*4, color);
			this->leg2 = new Rect(xmax + distance*1.5, ymax + (ymax- ymin)*2, xmax + distance*2, ymax + (ymax-ymin)*4, color);
			this->leg3 = new Rect(xmin - distance/1.5, ymax + (ymax- ymin)*2, xmin - distance/4.5, ymax + (ymax-ymin)*4, color);
			this->leg4 = new Rect(xmax + distance/4.5, ymax + (ymax- ymin)*2, xmax + distance/1.5, ymax + (ymax-ymin)*4, color);
			this->foot1 = new Rect(xmin - distance/4.5, ymax + (ymax- ymin)*4, xmin + distance/1.5, ymax + (ymax-ymin)*4.6, color);
			this->foot2 = new Rect(xmax - distance/1.5, ymax + (ymax- ymin)*4, xmax + distance/4.5, ymax + (ymax-ymin)*4.6, color);
			this->horn1 = new Rect(xmin + distance/4, ymin - (ymax-ymin)*0.6, xmin + distance/1.5, ymin, color);
			this->horn2 = new Rect(xmax - distance/1.5, ymin - (ymax-ymin)*0.6, xmax - distance/4, ymin, color);
			this->upperhorn1 = new Rect(xmin - distance/2, ymin - (ymax-ymin)*1.2, xmin + distance/4, ymin - (ymax-ymin)*0.6, color);
			this->upperhorn2 = new Rect(xmax - distance/4, ymin - (ymax-ymin)*1.2, xmax + distance/2, ymin - (ymax-ymin)*0.6, color);
			this->leye = new Rect(xmin - distance/2, ymin + (ymax- ymin)*1.75, xmin + distance/2, ymin + (ymax-ymin)*2.5, WHITE);
			this->reye = new Rect(xmax - distance/2, ymin + (ymax- ymin)*1.75, xmax + distance/2, ymin + (ymax-ymin)*2.5, WHITE);
		}
		Invader5(int xmin, int ymin, int xmax, int ymax){
			distance = (xmin + xmax)/64;
			this->body1 = new Rect(xmin, ymin, xmax, ymax, 12);
			this->body2 = new Rect(xmin - distance, ymin + (ymax- ymin), xmax + distance, ymax + (ymax-ymin), 12);
			this->body3 = new Rect(xmin - distance*2, ymax + (ymax- ymin), xmax + distance*2, ymax + (ymax-ymin)*2, 12);
			this->body4 = new Rect(xmin - distance/1.5, ymax + (ymax- ymin)*2, xmax + distance/1.5, ymax + (ymax-ymin)*3, 12);
			this->leg1 = new Rect(xmin - distance*2, ymax + (ymax- ymin)*2, xmin - distance*1.5, ymax + (ymax-ymin)*4, 12);
			this->leg2 = new Rect(xmax + distance*1.5, ymax + (ymax- ymin)*2, xmax + distance*2, ymax + (ymax-ymin)*4, 12);
			this->leg3 = new Rect(xmin - distance/1.5, ymax + (ymax- ymin)*2, xmin - distance/4.5, ymax + (ymax-ymin)*4, 12);
			this->leg4 = new Rect(xmax + distance/4.5, ymax + (ymax- ymin)*2, xmax + distance/1.5, ymax + (ymax-ymin)*4, 12);
			this->foot1 = new Rect(xmin - distance/4.5, ymax + (ymax- ymin)*4, xmin + distance/1.5, ymax + (ymax-ymin)*4.6, 12);
			this->foot2 = new Rect(xmax - distance/1.5, ymax + (ymax- ymin)*4, xmax + distance/4.5, ymax + (ymax-ymin)*4.6, 12);
			this->horn1 = new Rect(xmin + distance/4, ymin - (ymax-ymin)*0.6, xmin + distance/1.5, ymin, 12);
			this->horn2 = new Rect(xmax - distance/1.5, ymin - (ymax-ymin)*0.6, xmax - distance/4, ymin, 12);
			this->upperhorn1 = new Rect(xmin - distance/2, ymin - (ymax-ymin)*1.2, xmin + distance/4, ymin - (ymax-ymin)*0.6, 12);
			this->upperhorn2 = new Rect(xmax - distance/4, ymin - (ymax-ymin)*1.2, xmax + distance/2, ymin - (ymax-ymin)*0.6, 12);
			this->leye = new Rect(xmin - distance/2, ymin + (ymax- ymin)*1.75, xmin + distance/2, ymin + (ymax-ymin)*2.5, WHITE);
			this->reye = new Rect(xmax - distance/2, ymin + (ymax- ymin)*1.75, xmax + distance/2, ymin + (ymax-ymin)*2.5, WHITE);
		}
		void drawInvader5(){
			this->body1->drawStylishRect();
			this->body2->drawStylishRect();
			this->body3->drawStylishRect();
			this->body4->drawStylishRect();
			this->leg1->drawStylishRect();
			this->leg2->drawStylishRect();
			this->leg3->drawStylishRect();
			this->leg4->drawStylishRect();
			this->foot1->drawStylishRect();
			this->foot2->drawStylishRect();
			this->horn1->drawStylishRect();
			this->horn2->drawStylishRect();
			this->upperhorn1->drawStylishRect();
			this->upperhorn2->drawStylishRect();
			this->leye->drawRect();
			this->reye->drawRect();
		}
		void translateInvader5(int x, int y){
			this->body1->translateRect(x, y);
			this->body2->translateRect(x, y);
			this->body3->translateRect(x, y);
			this->body4->translateRect(x, y);
			this->leg1->translateRect(x, y);
			this->leg2->translateRect(x, y);
			this->leg3->translateRect(x, y);
			this->leg4->translateRect(x, y);
			this->foot1->translateRect(x, y);
			this->foot2->translateRect(x, y);
			this->horn1->translateRect(x, y);
			this->horn2->translateRect(x, y);
			this->upperhorn1->translateRect(x, y);
			this->upperhorn2->translateRect(x, y);
			this->leye->translateRect(x, y);
			this->reye->translateRect(x, y);
		}
};
class Invader6{
	Rect *body1, *body2, *body3, *body4, *leg1, *leg2, *leg3, *leg4, *foot1, *foot2, *horn1, *horn2, *upperhorn1, *upperhorn2, *leye, *reye;
	float distance;
	public:
		Invader6(int xmin, int ymin, int xmax, int ymax, int color){
			distance = (xmin + xmax)/64;
			this->body1 = new Rect(xmin, ymin, xmax, ymax, color);
			this->body2 = new Rect(xmin - distance, ymin + (ymax- ymin), xmax + distance, ymax + (ymax-ymin), color);
			this->body3 = new Rect(xmin - distance*2, ymax + (ymax- ymin), xmax + distance*2, ymax + (ymax-ymin)*2, color);
			this->body4 = new Rect(xmin - distance/1.5, ymax + (ymax- ymin)*2, xmax + distance/1.5, ymax + (ymax-ymin)*3, color);
			this->leg1 = new Rect(xmin - distance*2, ymax + (ymax- ymin)*2, xmin - distance*1.5, ymax + (ymax-ymin)*4, color);
			this->leg2 = new Rect(xmax + distance*1.5, ymax + (ymax- ymin)*2, xmax + distance*2, ymax + (ymax-ymin)*4, color);
			this->leg3 = new Rect(xmin - distance/1.5, ymax + (ymax- ymin)*2, xmin - distance/4.5, ymax + (ymax-ymin)*4, color);
			this->leg4 = new Rect(xmax + distance/4.5, ymax + (ymax- ymin)*2, xmax + distance/1.5, ymax + (ymax-ymin)*4, color);
			this->foot1 = new Rect(xmin - distance/4.5, ymax + (ymax- ymin)*4, xmin + distance/1.5, ymax + (ymax-ymin)*4.6, color);
			this->foot2 = new Rect(xmax - distance/1.5, ymax + (ymax- ymin)*4, xmax + distance/4.5, ymax + (ymax-ymin)*4.6, color);
			this->horn1 = new Rect(xmin + distance/4, ymin - (ymax-ymin)*0.6, xmin + distance/1.5, ymin, color);
			this->horn2 = new Rect(xmax - distance/1.5, ymin - (ymax-ymin)*0.6, xmax - distance/4, ymin, color);
			this->upperhorn1 = new Rect(xmin - distance/2, ymin - (ymax-ymin)*1.2, xmin + distance/4, ymin - (ymax-ymin)*0.6, color);
			this->upperhorn2 = new Rect(xmax - distance/4, ymin - (ymax-ymin)*1.2, xmax + distance/2, ymin - (ymax-ymin)*0.6, color);
			this->leye = new Rect(xmin - distance/2, ymin + (ymax- ymin)*1.75, xmin + distance/2, ymin + (ymax-ymin)*2.5, WHITE);
			this->reye = new Rect(xmax - distance/2, ymin + (ymax- ymin)*1.75, xmax + distance/2, ymin + (ymax-ymin)*2.5, WHITE);
		}
		Invader6(int xmin, int ymin, int xmax, int ymax){
			distance = (xmin + xmax)/64;
			this->body1 = new Rect(xmin, ymin, xmax, ymax, 12);
			this->body2 = new Rect(xmin - distance, ymin + (ymax- ymin), xmax + distance, ymax + (ymax-ymin), 12);
			this->body3 = new Rect(xmin - distance*2, ymax + (ymax- ymin), xmax + distance*2, ymax + (ymax-ymin)*2, 12);
			this->body4 = new Rect(xmin - distance/1.5, ymax + (ymax- ymin)*2, xmax + distance/1.5, ymax + (ymax-ymin)*3, 12);
			this->leg1 = new Rect(xmin - distance*2, ymax + (ymax- ymin)*2, xmin - distance*1.5, ymax + (ymax-ymin)*4, 12);
			this->leg2 = new Rect(xmax + distance*1.5, ymax + (ymax- ymin)*2, xmax + distance*2, ymax + (ymax-ymin)*4, 12);
			this->leg3 = new Rect(xmin - distance/1.5, ymax + (ymax- ymin)*2, xmin - distance/4.5, ymax + (ymax-ymin)*4, 12);
			this->leg4 = new Rect(xmax + distance/4.5, ymax + (ymax- ymin)*2, xmax + distance/1.5, ymax + (ymax-ymin)*4, 12);
			this->foot1 = new Rect(xmin - distance/4.5, ymax + (ymax- ymin)*4, xmin + distance/1.5, ymax + (ymax-ymin)*4.6, 12);
			this->foot2 = new Rect(xmax - distance/1.5, ymax + (ymax- ymin)*4, xmax + distance/4.5, ymax + (ymax-ymin)*4.6, 12);
			this->horn1 = new Rect(xmin + distance/4, ymin - (ymax-ymin)*0.6, xmin + distance/1.5, ymin, 12);
			this->horn2 = new Rect(xmax - distance/1.5, ymin - (ymax-ymin)*0.6, xmax - distance/4, ymin, 12);
			this->upperhorn1 = new Rect(xmin - distance/2, ymin - (ymax-ymin)*1.2, xmin + distance/4, ymin - (ymax-ymin)*0.6, 12);
			this->upperhorn2 = new Rect(xmax - distance/4, ymin - (ymax-ymin)*1.2, xmax + distance/2, ymin - (ymax-ymin)*0.6, 12);
			this->leye = new Rect(xmin - distance/2, ymin + (ymax- ymin)*1.75, xmin + distance/2, ymin + (ymax-ymin)*2.5, WHITE);
			this->reye = new Rect(xmax - distance/2, ymin + (ymax- ymin)*1.75, xmax + distance/2, ymin + (ymax-ymin)*2.5, WHITE);
		}
		void drawInvader6(){
			this->body1->drawStylishRect();
			this->body2->drawStylishRect();
			this->body3->drawStylishRect();
			this->body4->drawStylishRect();
			this->leg1->drawStylishRect();
			this->leg2->drawStylishRect();
			this->leg3->drawStylishRect();
			this->leg4->drawStylishRect();
			this->foot1->drawStylishRect();
			this->foot2->drawStylishRect();
			this->horn1->drawStylishRect();
			this->horn2->drawStylishRect();
			this->upperhorn1->drawStylishRect();
			this->upperhorn2->drawStylishRect();
			this->leye->drawRect();
			this->reye->drawRect();
		}
		void translateInvader6(int x, int y){
			this->body1->translateRect(x, y);
			this->body2->translateRect(x, y);
			this->body3->translateRect(x, y);
			this->body4->translateRect(x, y);
			this->leg1->translateRect(x, y);
			this->leg2->translateRect(x, y);
			this->leg3->translateRect(x, y);
			this->leg4->translateRect(x, y);
			this->foot1->translateRect(x, y);
			this->foot2->translateRect(x, y);
			this->horn1->translateRect(x, y);
			this->horn2->translateRect(x, y);
			this->upperhorn1->translateRect(x, y);
			this->upperhorn2->translateRect(x, y);
			this->leye->translateRect(x, y);
			this->reye->translateRect(x, y);
		}
};
class Environment{
	Background *bg;
	Rock *rock1;
	Invader1 *n, *na;
	Invader2 *n2, *n2a;
	Invader3 *n3, *n3a;
	Invader4 *n4, *n4a;
	Invader5 *n5, *n5a;
	Avatar *ava;
	int counter, speed, lvl, rand;
	float winWidth, winHeight;
	public:
		Environment(int windowWidth, int windowHeight){
			int bgCoordinate[10] = {windowWidth - windowWidth, windowHeight - windowHeight, windowWidth, windowHeight - windowHeight, windowWidth, windowHeight, windowWidth - windowWidth, windowHeight, windowWidth - windowWidth, windowHeight - windowHeight};
			this->bg = new Background(bgCoordinate, 0, 75);
			this->rock1 = new Rock(300, 0, 330, 15); //+30
			this->n = new Invader1(50, 0, 70, 10, BLUE); //+20
			this->n2 = new Invader2(150, 0, 190, 10, GREEN); //+40
			this->n3 = new Invader3(500, 0, 545, 10, 9); //+45
			this->n4 = new Invader4(250, 0, 280, 10, 5); //+30
			this->n5 = new Invader5(350, 0, 370, 7, 12); //+20
			this->n5a = new Invader5(350, 0, 370, 7, YELLOW); //+20
			this->n4a = new Invader4(250, 0, 280, 10, WHITE); //+30
			this->n3a = new Invader3(500, 0, 545, 10, 13); //+45
			this->na = new Invader1(50, 0, 70, 10, CYAN); //+20
			this->n2a = new Invader2(150, 0, 190, 10, BROWN); //+40
			this->ava = new Avatar();
			this->winWidth = windowWidth; this->winHeight = windowHeight;
			counter = 0, speed = 150, lvl = 10;
			this->n->translateInvader1(125, 0);
			this->n2->translateInvader2(400, 0);
			this->n3->translateInvader3(-200,0);
			this->n4->translateInvader4(-200, 0);
			this->n5->translateInvader5(75, 0);
			this->n5a->translateInvader5(-300, 0);
			this->n4a->translateInvader4(300, 0);
			this->n3a->translateInvader3(-200,0);
			this->na->translateInvader1(375,0);
			this->n2a->translateInvader2(25,0);
		}
		int drawEnvironment(){
			do{	
				this->pointGiver();
				this->counterReset();
				this->speedUp();
				this->levelUp();
				this->pointChecker();
				this->bg->drawBackground();
				if(kbhit()){
					this->moveAvatar();
				}
				if(this->ava->points >= 8){
					this->drawInvadersLvl2(); 							// draws new invaders for level up
				}
				this->rock1->drawRock();
				this->n->drawInvader1();
				this->n2->drawInvader2();
				this->n3->drawInvader3(); 
				this->n4->drawInvader4();
				this->n5->drawInvader5();
				this->drawScore();
				this->rock1->translateRock(0,3);
				this->n->translateInvader1(0, 4);
				this->n2->translateInvader2(0, 5);
				this->n3->translateInvader3(0,7);
				this->n4->translateInvader4(0, 5);
				this->n5->translateInvader5(0, 6);
				
				this->ava->drawAvatar();
				delay(this->speed);
				this->checkCollision();
				this->checkOutofBorder();
				this->counter++;
			} while(this->ava->life > 0);
			return this->ava->points;
		}
		void drawInvadersLvl2(){
			this->n5a->drawInvader5();
			this->n5a->translateInvader5(0, 6);
			this->n4a->drawInvader4();
			this->n4a->translateInvader4(0, 5);
			this->n3a->drawInvader3();
			this->n3a->translateInvader3(0, 7);
			this->na->drawInvader1();
			this->na->translateInvader1(0, 4);
			this->n2a->drawInvader2();
			this->n2a->translateInvader2(0, 5);
		}
		void levelUp(){
			if(this->ava->points % 50 == 0){
				cout << "LEVEL UP" << endl;
				this->lvl = this->lvl + 0;
			}
		}
		void speedUp(){
			if(this->ava->points % 50 == 0){
				cout << "SPEEDING TO THE NEXT LEVEL!" << endl;
				this->speed = this->speed - 50;
			}
		}
		void pointChecker(){
			if(this->ava->points % 50 == 0){
				cout << "POINTER CHECKER" << endl;
				this->ava->points = this->ava->points + 1;
			}
		}
		void pointGiver(){
			if(this->counter == this->lvl){
				cout << "POINT GIVER" << endl;
				this->ava->points = this->ava->points +  1;
			}
		}
		void counterReset(){
			if(this->counter == this->lvl){
				cout << "COUNTER RESET" << endl;
				this->counter = 0;
			}
		}
		void moveAvatar(){
			if (GetAsyncKeyState(VK_RIGHT)){
	        	this->ava->translateAvatar(20, 0);
	        }
	        if (GetAsyncKeyState(VK_LEFT)){
				this->ava->translateAvatar(-20, 0);
	        }
	        if (GetAsyncKeyState(VK_UP)){
				this->ava->translateAvatar(0, -20);
	        }
	        if (GetAsyncKeyState(VK_DOWN)){
	        	this->ava->translateAvatar(0, 20);
	        }
		}
		void drawScore(){
			char myScore [20]; 					//int will be stored here as a string
			itoa(this->ava->points, myScore,10);
			settextstyle(BOLD_FONT, HORIZ_DIR, 1);
			outtextxy(15, 5, myScore);
		}
		void checkCollision(){
			collisionOnRock();
			collisionOnInvader1();
			collisionOnInvader2();
			collisionOnInvader3();
			collisionOnInvader4();
			collisionOnInvader5();
			collisionOnInvader1a();
			collisionOnInvader2a();
			collisionOnInvader5a();
			collisionOnInvader4a();
			collisionOnInvader3a();
//			collisionOnInvader6();
		}
		void collisionOnInvader1(){
			if((this->ava->head[6]>= this->n->partfoot1->side[2] && this->ava->head[6]<= this->n->partfoot1->side[4] || this->ava->head[4]>= this->n->partfoot1->side[2] && this->ava->head[4]<= this->n->partfoot1->side[4])
				&& this->ava->head[3] - 15 >= this->n->partfoot1->side[1] && this->ava->head[3] - 15 <= this->n->partfoot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at Invader1 foot 1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n->partfoot2->side[2] && this->ava->head[6]<= this->n->partfoot2->side[4] || this->ava->head[4]>= this->n->partfoot2->side[2] && this->ava->head[4]<= this->n->partfoot2->side[4])
				&& this->ava->head[3] - 15 >= this->n->partfoot2->side[1] && this->ava->head[3] - 15 <= this->n->partfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at Invader1 foot 2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n->partfoot3->side[2] && this->ava->head[6]<= this->n->partfoot3->side[4] || this->ava->head[4]>= this->n->partfoot3->side[2] && this->ava->head[4]<= this->n->partfoot3->side[4])
				&& this->ava->head[3] - 15 >= this->n->partfoot3->side[1] && this->ava->head[3] - 15 <= this->n->partfoot3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at Invader1 foot 3!"<<endl;
			}
			else if((this->ava->head[6]>= this->n->part3->side[2] && this->ava->head[6]<= this->n->part3->side[4] || this->ava->head[4]>= this->n->part3->side[2] && this->ava->head[4]<= this->n->part3->side[4])
				&& this->ava->head[3] - 15 >= this->n->part3->side[1] && this->ava->head[3] - 15 <= this->n->part3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at Invader1 part 3!"<<endl;
			}
			else if((this->ava->body[16] >= this->n->partfoot3->side[2] && this->ava->body[16] <= this->n->partfoot3->side[4] || this->ava->body[18] >= this->n->partfoot3->side[2] && this->ava->body[18] <= this->n->partfoot3->side[4])
				&& this->ava->body[17] - 2 >= this->n->partfoot3->side[1] && this->ava->body[17] - 2 <= this->n->partfoot3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing!"<<endl;
			}
			else if((this->ava->body[16] <= this->n->part3->side[2] && this->ava->body[18] >= this->n->part3->side[2] || this->ava->body[16] <= this->n->part3->side[4] && this->ava->body[18] >= this->n->part3->side[4])
				&& this->ava->body[17] - 2 >= this->n->part3->side[1] && this->ava->body[17] - 2 <= this->n->part3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing part3!"<<endl;
			}
			else if((this->ava->body[4] <= this->n->partfoot1->side[2] && this->ava->body[6] >= this->n->partfoot1->side[2] || this->ava->body[4] <= this->n->partfoot1->side[4] && this->ava->body[6] >= this->n->partfoot1->side[4])
				&& this->ava->body[17] - 15 <= this->n->partfoot1->side[1] && this->ava->body[15] - 15 >= this->n->partfoot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing!"<<endl;
			}
			else if((this->ava->body[4] <= this->n->part3->side[2] && this->ava->body[6] >= this->n->part3->side[2] || this->ava->body[4] <= this->n->part3->side[4] && this->ava->body[6] >= this->n->part3->side[4])
				&& this->ava->body[17] - 2 >= this->n->part3->side[1] && this->ava->body[17] - 2 <= this->n->part3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing part3!"<<endl;
			}
			else if((this->ava->body[12] >= this->n->part1->side[0] && this->ava->body[12] <= this->n->part1->side[6] || this->ava->body[10] >= this->n->part1->side[0] && this->ava->body[10] <= this->n->part1->side[6])
				&& this->ava->body[11] + 2>= this->n->part1->side[1] && this->ava->body[13] + 2 <= this->n->part1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at BUTT!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n->part1->side[1] && this->ava->body[17] + 15 <= this->n->part1->side[3] || this->ava->body[15] + 15 <= this->n->part1->side[1] && this->ava->body[15] + 15 >= this->n->part1->side[3])
				&& (this->ava->body[16] >= this->n->part1->side[2] && this->ava->body[16] <= this->n->part1->side[4] || this->ava->body[14] >= this->n->part1->side[2] && this->ava->body[14] <= this->n->part1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing part1: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n->part2->side[1] && this->ava->body[17] + 15 <= this->n->part2->side[3] || this->ava->body[15] + 15 <= this->n->part2->side[1] && this->ava->body[15] + 15 >= this->n->part2->side[3])
				&& (this->ava->body[16] >= this->n->part2->side[2] && this->ava->body[16] <= this->n->part2->side[4] || this->ava->body[14] >= this->n->part2->side[2] && this->ava->body[14] <= this->n->part2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing part2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n->part3->side[1] && this->ava->body[17] + 15 <= this->n->part3->side[3] || this->ava->body[15] + 15 <= this->n->part3->side[1] && this->ava->body[15] + 15 >= this->n->part3->side[3])
				&& (this->ava->body[16] >= this->n->part3->side[2] && this->ava->body[16] <= this->n->part3->side[4] || this->ava->body[14] >= this->n->part3->side[2] && this->ava->body[14] <= this->n->part3->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing part3: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n->partfoot3->side[1] && this->ava->body[17] + 15 <= this->n->partfoot3->side[3] || this->ava->body[15] + 15 <= this->n->partfoot3->side[1] && this->ava->body[15] + 15 >= this->n->partfoot3->side[3])
				&& (this->ava->body[16] >= this->n->partfoot3->side[2] && this->ava->body[16] <= this->n->partfoot3->side[4] || this->ava->body[14] >= this->n->partfoot3->side[2] && this->ava->body[14] <= this->n->partfoot3->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partfoot3: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n->part1->side[1] && this->ava->body[7] + 15 <= this->n->part1->side[3] || this->ava->body[9] + 15 <= this->n->part1->side[1] && this->ava->body[9] + 15 >= this->n->part1->side[3])
				&& (this->ava->body[6] >= this->n->part1->side[2] && this->ava->body[6] <= this->n->part1->side[4] || this->ava->body[8] >= this->n->part1->side[2] && this->ava->body[8] <= this->n->part1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing part1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n->part2->side[1] && this->ava->body[7] + 15 <= this->n->part2->side[3] || this->ava->body[9] + 15 <= this->n->part2->side[1] && this->ava->body[9] + 15 >= this->n->part2->side[3])
				&& (this->ava->body[6] >= this->n->part2->side[2] && this->ava->body[6] <= this->n->part2->side[4] || this->ava->body[8] >= this->n->part2->side[2] && this->ava->body[8] <= this->n->part2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing part2: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n->part3->side[1] && this->ava->body[7] + 15 <= this->n->part3->side[3] || this->ava->body[9] + 15 <= this->n->part3->side[1] && this->ava->body[9] + 15 >= this->n->part3->side[3])
				&& (this->ava->body[6] >= this->n->part3->side[2] && this->ava->body[6] <= this->n->part3->side[4] || this->ava->body[8] >= this->n->part3->side[2] && this->ava->body[8] <= this->n->part3->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing part3: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n->partfoot3->side[1] && this->ava->body[7] + 15 <= this->n->partfoot3->side[3] || this->ava->body[9] + 15 <= this->n->partfoot3->side[1] && this->ava->body[9] + 15 >= this->n->partfoot3->side[3])
				&& (this->ava->body[6] >= this->n->partfoot3->side[2] && this->ava->body[6] <= this->n->partfoot3->side[4] || this->ava->body[8] >= this->n->partfoot3->side[2] && this->ava->body[8] <= this->n->partfoot3->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partfoot3: side!"<<endl;
			}
		};
		void collisionOnInvader1a(){
			if((this->ava->head[6]>= this->na->partfoot1->side[2] && this->ava->head[6]<= this->na->partfoot1->side[4] || this->ava->head[4]>= this->na->partfoot1->side[2] && this->ava->head[4]<= this->na->partfoot1->side[4])
				&& this->ava->head[3] - 15 >= this->na->partfoot1->side[1] && this->ava->head[3] - 15 <= this->na->partfoot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at Invader1 foot 1!"<<endl;
			}
			else if((this->ava->head[6]>= this->na->partfoot2->side[2] && this->ava->head[6]<= this->na->partfoot2->side[4] || this->ava->head[4]>= this->na->partfoot2->side[2] && this->ava->head[4]<= this->na->partfoot2->side[4])
				&& this->ava->head[3] - 15 >= this->na->partfoot2->side[1] && this->ava->head[3] - 15 <= this->na->partfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at Invader1 foot 2!"<<endl;
			}
			else if((this->ava->head[6]>= this->na->partfoot3->side[2] && this->ava->head[6]<= this->na->partfoot3->side[4] || this->ava->head[4]>= this->na->partfoot3->side[2] && this->ava->head[4]<= this->na->partfoot3->side[4])
				&& this->ava->head[3] - 15 >= this->na->partfoot3->side[1] && this->ava->head[3] - 15 <= this->na->partfoot3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at Invader1 foot 3!"<<endl;
			}
			else if((this->ava->head[6]>= this->na->part3->side[2] && this->ava->head[6]<= this->na->part3->side[4] || this->ava->head[4]>= this->na->part3->side[2] && this->ava->head[4]<= this->na->part3->side[4])
				&& this->ava->head[3] - 15 >= this->na->part3->side[1] && this->ava->head[3] - 15 <= this->na->part3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at Invader1 part 3!"<<endl;
			}
			else if((this->ava->body[16] >= this->na->partfoot3->side[2] && this->ava->body[16] <= this->na->partfoot3->side[4] || this->ava->body[18] >= this->na->partfoot3->side[2] && this->ava->body[18] <= this->na->partfoot3->side[4])
				&& this->ava->body[17] - 2 >= this->na->partfoot3->side[1] && this->ava->body[17] - 2 <= this->na->partfoot3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing!"<<endl;
			}
			else if((this->ava->body[16] <= this->na->part3->side[2] && this->ava->body[18] >= this->na->part3->side[2] || this->ava->body[16] <= this->na->part3->side[4] && this->ava->body[18] >= this->na->part3->side[4])
				&& this->ava->body[17] - 2 >= this->na->part3->side[1] && this->ava->body[17] - 2 <= this->na->part3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing part3!"<<endl;
			}
			else if((this->ava->body[4] <= this->na->partfoot1->side[2] && this->ava->body[6] >= this->na->partfoot1->side[2] || this->ava->body[4] <= this->na->partfoot1->side[4] && this->ava->body[6] >= this->na->partfoot1->side[4])
				&& this->ava->body[17] - 15 <= this->na->partfoot1->side[1] && this->ava->body[15] - 15 >= this->na->partfoot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing!"<<endl;
			}
			else if((this->ava->body[4] <= this->na->part3->side[2] && this->ava->body[6] >= this->na->part3->side[2] || this->ava->body[4] <= this->na->part3->side[4] && this->ava->body[6] >= this->na->part3->side[4])
				&& this->ava->body[17] - 2 >= this->na->part3->side[1] && this->ava->body[17] - 2 <= this->na->part3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing part3!"<<endl;
			}
			else if((this->ava->body[12] >= this->na->part1->side[0] && this->ava->body[12] <= this->na->part1->side[6] || this->ava->body[10] >= this->na->part1->side[0] && this->ava->body[10] <= this->na->part1->side[6])
				&& this->ava->body[11] + 2>= this->na->part1->side[1] && this->ava->body[13] + 2 <= this->na->part1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at BUTT!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->na->part1->side[1] && this->ava->body[17] + 15 <= this->na->part1->side[3] || this->ava->body[15] + 15 <= this->na->part1->side[1] && this->ava->body[15] + 15 >= this->na->part1->side[3])
				&& (this->ava->body[16] >= this->na->part1->side[2] && this->ava->body[16] <= this->na->part1->side[4] || this->ava->body[14] >= this->na->part1->side[2] && this->ava->body[14] <= this->na->part1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing part1: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->na->part2->side[1] && this->ava->body[17] + 15 <= this->na->part2->side[3] || this->ava->body[15] + 15 <= this->na->part2->side[1] && this->ava->body[15] + 15 >= this->na->part2->side[3])
				&& (this->ava->body[16] >= this->na->part2->side[2] && this->ava->body[16] <= this->na->part2->side[4] || this->ava->body[14] >= this->na->part2->side[2] && this->ava->body[14] <= this->na->part2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing part2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->na->part3->side[1] && this->ava->body[17] + 15 <= this->na->part3->side[3] || this->ava->body[15] + 15 <= this->na->part3->side[1] && this->ava->body[15] + 15 >= this->na->part3->side[3])
				&& (this->ava->body[16] >= this->na->part3->side[2] && this->ava->body[16] <= this->na->part3->side[4] || this->ava->body[14] >= this->na->part3->side[2] && this->ava->body[14] <= this->na->part3->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing part3: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->na->partfoot3->side[1] && this->ava->body[17] + 15 <= this->na->partfoot3->side[3] || this->ava->body[15] + 15 <= this->na->partfoot3->side[1] && this->ava->body[15] + 15 >= this->na->partfoot3->side[3])
				&& (this->ava->body[16] >= this->na->partfoot3->side[2] && this->ava->body[16] <= this->na->partfoot3->side[4] || this->ava->body[14] >= this->na->partfoot3->side[2] && this->ava->body[14] <= this->na->partfoot3->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partfoot3: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->na->part1->side[1] && this->ava->body[7] + 15 <= this->na->part1->side[3] || this->ava->body[9] + 15 <= this->na->part1->side[1] && this->ava->body[9] + 15 >= this->na->part1->side[3])
				&& (this->ava->body[6] >= this->na->part1->side[2] && this->ava->body[6] <= this->na->part1->side[4] || this->ava->body[8] >= this->na->part1->side[2] && this->ava->body[8] <= this->na->part1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing part1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->na->part2->side[1] && this->ava->body[7] + 15 <= this->na->part2->side[3] || this->ava->body[9] + 15 <= this->na->part2->side[1] && this->ava->body[9] + 15 >= this->na->part2->side[3])
				&& (this->ava->body[6] >= this->na->part2->side[2] && this->ava->body[6] <= this->na->part2->side[4] || this->ava->body[8] >= this->na->part2->side[2] && this->ava->body[8] <= this->na->part2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing part2: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->na->part3->side[1] && this->ava->body[7] + 15 <= this->na->part3->side[3] || this->ava->body[9] + 15 <= this->na->part3->side[1] && this->ava->body[9] + 15 >= this->na->part3->side[3])
				&& (this->ava->body[6] >= this->na->part3->side[2] && this->ava->body[6] <= this->na->part3->side[4] || this->ava->body[8] >= this->na->part3->side[2] && this->ava->body[8] <= this->na->part3->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing part3: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->na->partfoot3->side[1] && this->ava->body[7] + 15 <= this->na->partfoot3->side[3] || this->ava->body[9] + 15 <= this->na->partfoot3->side[1] && this->ava->body[9] + 15 >= this->na->partfoot3->side[3])
				&& (this->ava->body[6] >= this->na->partfoot3->side[2] && this->ava->body[6] <= this->na->partfoot3->side[4] || this->ava->body[8] >= this->na->partfoot3->side[2] && this->ava->body[8] <= this->na->partfoot3->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partfoot3: side!"<<endl;
			}
		};
		void collisionOnRock(){
			if((this->ava->head[6]>= this->rock1->block11->side[2] && this->ava->head[6]<= this->rock1->block11->side[4] || this->ava->head[4]>= this->rock1->block11->side[2] && this->ava->head[4]<= this->rock1->block11->side[4])
				&& this->ava->head[3] - 15 >= this->rock1->block11->side[1] && this->ava->head[3] - 15 <= this->rock1->block11->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at block11!"<<endl;
			}
			else if((this->ava->head[6]>= this->rock1->block9->side[2] && this->ava->head[6]<= this->rock1->block9->side[4] || this->ava->head[4]>= this->rock1->block9->side[2] && this->ava->head[4]<= this->rock1->block9->side[4])
				&& this->ava->head[3] - 15 >= this->rock1->block9->side[1] && this->ava->head[3] - 15 <= this->rock1->block9->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at block9!"<<endl;
			}
			else if((this->ava->head[6]>= this->rock1->block7->side[2] && this->ava->head[6]<= this->rock1->block7->side[4] || this->ava->head[4]>= this->rock1->block7->side[2] && this->ava->head[4]<= this->rock1->block7->side[4])
				&& this->ava->head[3] - 15 >= this->rock1->block7->side[1] && this->ava->head[3] - 15 <= this->rock1->block7->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at block7!"<<endl;
			}
			else if((this->ava->head[6]>= this->rock1->block5->side[2] && this->ava->head[6]<= this->rock1->block5->side[4] || this->ava->head[4]>= this->rock1->block5->side[2] && this->ava->head[4]<= this->rock1->block5->side[4])
				&& this->ava->head[3] - 15 >= this->rock1->block5->side[1] && this->ava->head[3] - 15 <= this->rock1->block5->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at block5!"<<endl;
			}
			else if((this->ava->head[6]>= this->rock1->block8->side[2] && this->ava->head[6]<= this->rock1->block8->side[4] || this->ava->head[4]>= this->rock1->block8->side[2] && this->ava->head[4]<= this->rock1->block8->side[4])
				&& this->ava->head[3] - 15 >= this->rock1->block8->side[1] && this->ava->head[3] - 15 <= this->rock1->block8->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at block8!"<<endl;
			}
			else if((this->ava->head[6]>= this->rock1->block4->side[2] && this->ava->head[6]<= this->rock1->block4->side[4] || this->ava->head[4]>= this->rock1->block4->side[2] && this->ava->head[4]<= this->rock1->block4->side[4])
				&& this->ava->head[3] - 15 >= this->rock1->block4->side[1] && this->ava->head[3] - 15 <= this->rock1->block4->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at block4!"<<endl;
			}
			else if((this->ava->body[12] >= this->rock1->block1->side[0] && this->ava->body[12] <= this->rock1->block1->side[6] || this->ava->body[10] >= this->rock1->block1->side[0] && this->ava->body[10] <= this->rock1->block1->side[6])
				&& this->ava->body[11] + 2>= this->rock1->block1->side[1] && this->ava->body[13] + 2 <= this->rock1->block1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at block1 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->rock1->block2->side[0] && this->ava->body[12] <= this->rock1->block2->side[6] || this->ava->body[10] >= this->rock1->block2->side[0] && this->ava->body[10] <= this->rock1->block2->side[6])
				&& this->ava->body[11] + 2>= this->rock1->block2->side[1] && this->ava->body[13] + 2 <= this->rock1->block2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at block2 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->rock1->block3->side[0] && this->ava->body[12] <= this->rock1->block3->side[6] || this->ava->body[10] >= this->rock1->block3->side[0] && this->ava->body[10] <= this->rock1->block3->side[6])
				&& this->ava->body[11] + 2>= this->rock1->block3->side[1] && this->ava->body[13] + 2 <= this->rock1->block3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at block3 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->rock1->block10->side[0] && this->ava->body[12] <= this->rock1->block10->side[6] || this->ava->body[10] >= this->rock1->block10->side[0] && this->ava->body[10] <= this->rock1->block10->side[6])
				&& this->ava->body[11] + 2>= this->rock1->block10->side[1] && this->ava->body[13] + 2 <= this->rock1->block10->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at block10 (butt)!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->rock1->block1->side[1] && this->ava->body[17] + 15 <= this->rock1->block1->side[3] || this->ava->body[15] + 15 <= this->rock1->block1->side[1] && this->ava->body[15] + 15 >= this->rock1->block1->side[3])
				&& (this->ava->body[16] - 3 >= this->rock1->block1->side[2] && this->ava->body[16] - 3 <= this->rock1->block1->side[4] || this->ava->body[14] - 3 >= this->rock1->block1->side[2] && this->ava->body[14] - 3 <= this->rock1->block1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing block1: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->rock1->block3->side[1] && this->ava->body[17] + 15 <= this->rock1->block3->side[3] || this->ava->body[15] + 15 <= this->rock1->block3->side[1] && this->ava->body[15] + 15 >= this->rock1->block3->side[3])
				&& (this->ava->body[16] - 3 >= this->rock1->block3->side[2] && this->ava->body[16] - 3 <= this->rock1->block3->side[4] || this->ava->body[14] - 3 >= this->rock1->block3->side[2] && this->ava->body[14] - 3 <= this->rock1->block3->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing block3: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->rock1->block5->side[1] && this->ava->body[17] + 15 <= this->rock1->block5->side[3] || this->ava->body[15] + 15 <= this->rock1->block5->side[1] && this->ava->body[15] + 15 >= this->rock1->block5->side[3])
				&& (this->ava->body[16] - 3 >= this->rock1->block5->side[2] && this->ava->body[16] - 3 <= this->rock1->block5->side[4] || this->ava->body[14] - 3 >= this->rock1->block5->side[2] && this->ava->body[14] - 3 <= this->rock1->block5->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing block5: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->rock1->block7->side[1] && this->ava->body[17] + 15 <= this->rock1->block7->side[3] || this->ava->body[15] + 15 <= this->rock1->block7->side[1] && this->ava->body[15] + 15 >= this->rock1->block7->side[3])
				&& (this->ava->body[16] - 3 >= this->rock1->block7->side[2] && this->ava->body[16] - 3 <= this->rock1->block7->side[4] || this->ava->body[14] - 3 >= this->rock1->block7->side[2] && this->ava->body[14] - 3 <= this->rock1->block7->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing block7: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->rock1->block9->side[1] && this->ava->body[17] + 15 <= this->rock1->block9->side[3] || this->ava->body[15] + 15 <= this->rock1->block9->side[1] && this->ava->body[15] + 15 >= this->rock1->block9->side[3])
				&& (this->ava->body[16] - 3 >= this->rock1->block9->side[2] && this->ava->body[16] - 3 <= this->rock1->block9->side[4] || this->ava->body[14] - 3 >= this->rock1->block9->side[2] && this->ava->body[14] - 3 <= this->rock1->block9->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing block9: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->rock1->block11->side[1] && this->ava->body[17] + 15 <= this->rock1->block11->side[3] || this->ava->body[15] + 15 <= this->rock1->block11->side[1] && this->ava->body[15] + 15 >= this->rock1->block11->side[3])
				&& (this->ava->body[16] - 3 >= this->rock1->block11->side[2] && this->ava->body[16] - 3 <= this->rock1->block11->side[4] || this->ava->body[14] - 3 >= this->rock1->block11->side[2] && this->ava->body[14] - 3 <= this->rock1->block11->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing block11: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->rock1->block1->side[1] && this->ava->body[17] + 15 <= this->rock1->block1->side[3] || this->ava->body[15] + 15 <= this->rock1->block1->side[1] && this->ava->body[15] + 15 >= this->rock1->block1->side[3])
				&& (this->ava->body[16] - 6 >= this->rock1->block1->side[2] && this->ava->body[16] - 6 <= this->rock1->block1->side[4] || this->ava->body[14] - 6 >= this->rock1->block1->side[2] && this->ava->body[14] - 6 <= this->rock1->block1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing block1: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->rock1->block3->side[1] && this->ava->body[17] + 15 <= this->rock1->block3->side[3] || this->ava->body[15] + 15 <= this->rock1->block3->side[1] && this->ava->body[15] + 15 >= this->rock1->block3->side[3])
				&& (this->ava->body[16] - 6 >= this->rock1->block3->side[2] && this->ava->body[16] - 6 <= this->rock1->block3->side[4] || this->ava->body[14] - 6 >= this->rock1->block3->side[2] && this->ava->body[14] - 6 <= this->rock1->block3->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing block3: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->rock1->block5->side[1] && this->ava->body[17] + 15 <= this->rock1->block5->side[3] || this->ava->body[15] + 15 <= this->rock1->block5->side[1] && this->ava->body[15] + 15 >= this->rock1->block5->side[3])
				&& (this->ava->body[16] - 6 >= this->rock1->block5->side[2] && this->ava->body[16] - 6 <= this->rock1->block5->side[4] || this->ava->body[14] - 6 >= this->rock1->block5->side[2] && this->ava->body[14] - 6 <= this->rock1->block5->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing block5: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->rock1->block7->side[1] && this->ava->body[17] + 15 <= this->rock1->block7->side[3] || this->ava->body[15] + 15 <= this->rock1->block7->side[1] && this->ava->body[15] + 15 >= this->rock1->block7->side[3])
				&& (this->ava->body[16] - 6 >= this->rock1->block7->side[2] && this->ava->body[16] - 6 <= this->rock1->block7->side[4] || this->ava->body[14] - 6 >= this->rock1->block7->side[2] && this->ava->body[14] - 6 <= this->rock1->block7->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing block7: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->rock1->block9->side[1] && this->ava->body[17] + 15 <= this->rock1->block9->side[3] || this->ava->body[15] + 15 <= this->rock1->block9->side[1] && this->ava->body[15] + 15 >= this->rock1->block9->side[3])
				&& (this->ava->body[16] - 6 >= this->rock1->block9->side[2] && this->ava->body[16] - 6 <= this->rock1->block9->side[4] || this->ava->body[14] - 6 >= this->rock1->block9->side[2] && this->ava->body[14] - 6 <= this->rock1->block9->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing block9: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->rock1->block11->side[1] && this->ava->body[17] + 15 <= this->rock1->block11->side[3] || this->ava->body[15] + 15 <= this->rock1->block11->side[1] && this->ava->body[15] + 15 >= this->rock1->block11->side[3])
				&& (this->ava->body[16] - 6 >= this->rock1->block11->side[2] && this->ava->body[16] - 6 <= this->rock1->block11->side[4] || this->ava->body[14] - 6 >= this->rock1->block11->side[2] && this->ava->body[14] - 6 <= this->rock1->block11->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing block11: side!"<<endl;
			}
			else if((this->ava->body[16] >= this->rock1->block11->side[2] && this->ava->body[16] <= this->rock1->block11->side[4] || this->ava->body[18] >= this->rock1->block11->side[2] && this->ava->body[18] <= this->rock1->block11->side[4])
				&& this->ava->body[17] - 2 >= this->rock1->block11->side[1] && this->ava->body[17] - 2 <= this->rock1->block11->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing block11!"<<endl;
			}
			else if((this->ava->body[16] >= this->rock1->block9->side[2] && this->ava->body[16] <= this->rock1->block9->side[4] || this->ava->body[18] >= this->rock1->block9->side[2] && this->ava->body[18] <= this->rock1->block9->side[4])
				&& this->ava->body[17] - 2 >= this->rock1->block9->side[1] && this->ava->body[17] - 2 <= this->rock1->block9->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing block9!"<<endl;
			}
			else if((this->ava->body[16] >= this->rock1->block7->side[2] && this->ava->body[16] <= this->rock1->block7->side[4] || this->ava->body[18] >= this->rock1->block7->side[2] && this->ava->body[18] <= this->rock1->block7->side[4])
				&& this->ava->body[17] - 2 >= this->rock1->block7->side[1] && this->ava->body[17] - 2 <= this->rock1->block7->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing block7!"<<endl;
			}
			else if((this->ava->body[16] >= this->rock1->block5->side[2] && this->ava->body[16] <= this->rock1->block5->side[4] || this->ava->body[18] >= this->rock1->block5->side[2] && this->ava->body[18] <= this->rock1->block5->side[4])
				&& this->ava->body[17] - 2 >= this->rock1->block5->side[1] && this->ava->body[17] - 2 <= this->rock1->block5->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing block5!"<<endl;
			}
			else if((this->ava->body[4] >= this->rock1->block11->side[2] && this->ava->body[4] <= this->rock1->block11->side[4] || this->ava->body[6] >= this->rock1->block11->side[2] && this->ava->body[6] <= this->rock1->block11->side[4])
				&& (this->ava->body[7] - 2 >= this->rock1->block11->side[1] && this->ava->body[7] - 2 <= this->rock1->block11->side[3] || this->ava->body[9] - 2 >= this->rock1->block11->side[1] && this->ava->body[9] - 2 <= this->rock1->block11->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing block11!"<<endl;
			}
			else if((this->ava->body[4] >= this->rock1->block8->side[2] && this->ava->body[4] <= this->rock1->block8->side[4] || this->ava->body[6] >= this->rock1->block8->side[2] && this->ava->body[6] <= this->rock1->block8->side[4])
				&& (this->ava->body[7] - 2 >= this->rock1->block8->side[1] && this->ava->body[7] - 2 <= this->rock1->block8->side[3] || this->ava->body[9] - 2 >= this->rock1->block8->side[1] && this->ava->body[9] - 2 <= this->rock1->block8->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing block8!"<<endl;
			}
			else if((this->ava->body[4] >= this->rock1->block4->side[2] && this->ava->body[4] <= this->rock1->block4->side[4] || this->ava->body[6] >= this->rock1->block4->side[2] && this->ava->body[6] <= this->rock1->block4->side[4])
				&& (this->ava->body[7] - 2 >= this->rock1->block4->side[1] && this->ava->body[7] - 2 <= this->rock1->block4->side[3] || this->ava->body[9] - 2 >= this->rock1->block4->side[1] && this->ava->body[9] - 2 <= this->rock1->block4->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing block4!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->rock1->block11->side[1] && this->ava->body[7] + 15 <= this->rock1->block11->side[3] || this->ava->body[9] + 15 <= this->rock1->block11->side[1] && this->ava->body[9] + 15 >= this->rock1->block11->side[3])
				&& (this->ava->body[6] + 3 >= this->rock1->block11->side[2] && this->ava->body[6] + 3 <= this->rock1->block11->side[4] || this->ava->body[8] + 3 >= this->rock1->block11->side[2] && this->ava->body[8] + 3 <= this->rock1->block11->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing block11: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->rock1->block8->side[1] && this->ava->body[7] + 15 <= this->rock1->block8->side[3] || this->ava->body[9] + 15 <= this->rock1->block8->side[1] && this->ava->body[9] + 15 >= this->rock1->block8->side[3])
				&& (this->ava->body[6] + 3 >= this->rock1->block8->side[2] && this->ava->body[6] + 3 <= this->rock1->block8->side[4] || this->ava->body[8] + 3 >= this->rock1->block8->side[2] && this->ava->body[8] + 3 <= this->rock1->block8->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing block8: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->rock1->block4->side[1] && this->ava->body[7] + 15 <= this->rock1->block4->side[3] || this->ava->body[9] + 15 <= this->rock1->block4->side[1] && this->ava->body[9] + 15 >= this->rock1->block4->side[3])
				&& (this->ava->body[6] + 3 >= this->rock1->block4->side[2] && this->ava->body[6] + 3 <= this->rock1->block4->side[4] || this->ava->body[8] + 3 >= this->rock1->block4->side[2] && this->ava->body[8] + 3 <= this->rock1->block4->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing block4: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->rock1->block2->side[1] && this->ava->body[7] + 15 <= this->rock1->block2->side[3] || this->ava->body[9] + 15 <= this->rock1->block2->side[1] && this->ava->body[9] + 15 >= this->rock1->block2->side[3])
				&& (this->ava->body[6] + 3 >= this->rock1->block2->side[2] && this->ava->body[6] + 3 <= this->rock1->block2->side[4] || this->ava->body[8] + 3 >= this->rock1->block2->side[2] && this->ava->body[8] + 3 <= this->rock1->block2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing block2: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->rock1->block1->side[1] && this->ava->body[7] + 15 <= this->rock1->block1->side[3] || this->ava->body[9] + 15 <= this->rock1->block1->side[1] && this->ava->body[9] + 15 >= this->rock1->block1->side[3])
				&& (this->ava->body[6] + 3 >= this->rock1->block1->side[2] && this->ava->body[6] + 3 <= this->rock1->block1->side[4] || this->ava->body[8] + 3 >= this->rock1->block1->side[2] && this->ava->body[8] + 3 <= this->rock1->block1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing block1: side!"<<endl;
			}
}
		void collisionOnInvader3(){
			if((this->ava->head[6]>= this->n3->partchin->side[2] && this->ava->head[6]<= this->n3->partchin->side[4] || this->ava->head[4]>= this->n3->partchin->side[2] && this->ava->head[4]<= this->n3->partchin->side[4])
				&& this->ava->head[3] - 13 >= this->n3->partchin->side[1] && this->ava->head[3] - 13 <= this->n3->partchin->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partchin!"<<endl;
			}
			else if((this->ava->head[6]>= this->n3->partjaw->side[2] && this->ava->head[6]<= this->n3->partjaw->side[4] || this->ava->head[4]>= this->n3->partjaw->side[2] && this->ava->head[4]<= this->n3->partjaw->side[4])
				&& this->ava->head[3] - 13 >= this->n3->partjaw->side[1] && this->ava->head[3] - 13 <= this->n3->partjaw->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partjaw!"<<endl;
			}
			else if((this->ava->head[6]>= this->n3->partface->side[2] && this->ava->head[6]<= this->n3->partface->side[4] || this->ava->head[4]>= this->n3->partface->side[2] && this->ava->head[4]<= this->n3->partface->side[4])
				&& this->ava->head[3] - 13 >= this->n3->partface->side[1] && this->ava->head[3] - 13 <= this->n3->partface->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partface!"<<endl;
			}
			else if((this->ava->body[12] >= this->n3->parthead->side[0] && this->ava->body[12] <= this->n3->parthead->side[6] || this->ava->body[10] >= this->n3->parthead->side[0] && this->ava->body[10] <= this->n3->parthead->side[6])
				&& this->ava->body[11] + 2>= this->n3->parthead->side[1] && this->ava->body[13] + 2 <= this->n3->parthead->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthead (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n3->partforehead->side[0] && this->ava->body[12] <= this->n3->partforehead->side[6] || this->ava->body[10] >= this->n3->partforehead->side[0] && this->ava->body[10] <= this->n3->partforehead->side[6])
				&& this->ava->body[11] + 2>= this->n3->partforehead->side[1] && this->ava->body[13] + 2 <= this->n3->partforehead->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partforehead (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n3->partface->side[0] && this->ava->body[12] <= this->n3->partface->side[6] || this->ava->body[10] >= this->n3->partface->side[0] && this->ava->body[10] <= this->n3->partface->side[6])
				&& this->ava->body[11] + 2>= this->n3->partface->side[1] && this->ava->body[13] + 2 <= this->n3->partface->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partface (butt)!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n3->parthead->side[1] && this->ava->body[17] + 15 <= this->n3->parthead->side[3] || this->ava->body[15] + 15 <= this->n3->parthead->side[1] && this->ava->body[15] + 15 >= this->n3->parthead->side[3])
				&& (this->ava->body[16] - 3 >= this->n3->parthead->side[2] && this->ava->body[16] - 3 <= this->n3->parthead->side[4] || this->ava->body[14] - 3 >= this->n3->parthead->side[2] && this->ava->body[14] - 3 <= this->n3->parthead->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing parthead: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n3->partforehead->side[1] && this->ava->body[17] + 15 <= this->n3->partforehead->side[3] || this->ava->body[15] + 15 <= this->n3->partforehead->side[1] && this->ava->body[15] + 15 >= this->n3->partforehead->side[3])
				&& (this->ava->body[16] - 3 >= this->n3->partforehead->side[2] && this->ava->body[16] - 3 <= this->n3->partforehead->side[4] || this->ava->body[14] - 3 >= this->n3->partforehead->side[2] && this->ava->body[14] - 3 <= this->n3->partforehead->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partforehead: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n3->partface->side[1] && this->ava->body[17] + 15 <= this->n3->partface->side[3] || this->ava->body[15] + 15 <= this->n3->partface->side[1] && this->ava->body[15] + 15 >= this->n3->partface->side[3])
				&& (this->ava->body[16] - 3 >= this->n3->partface->side[2] && this->ava->body[16] - 3 <= this->n3->partface->side[4] || this->ava->body[14] - 3 >= this->n3->partface->side[2] && this->ava->body[14] - 3 <= this->n3->partface->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partface: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n3->partjaw->side[1] && this->ava->body[17] + 15 <= this->n3->partjaw->side[3] || this->ava->body[15] + 15 <= this->n3->partjaw->side[1] && this->ava->body[15] + 15 >= this->n3->partjaw->side[3])
				&& (this->ava->body[16] - 3 >= this->n3->partjaw->side[2] && this->ava->body[16] - 3 <= this->n3->partjaw->side[4] || this->ava->body[14] - 3 >= this->n3->partjaw->side[2] && this->ava->body[14] - 3 <= this->n3->partjaw->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partjaw: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n3->partchin->side[1] && this->ava->body[17] + 15 <= this->n3->partchin->side[3] || this->ava->body[15] + 15 <= this->n3->partchin->side[1] && this->ava->body[15] + 15 >= this->n3->partchin->side[3])
				&& (this->ava->body[16] - 3 >= this->n3->partchin->side[2] && this->ava->body[16] - 3 <= this->n3->partchin->side[4] || this->ava->body[14] - 3 >= this->n3->partchin->side[2] && this->ava->body[14] - 3 <= this->n3->partchin->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partchin: side!"<<endl;
			}
			else if((this->ava->body[16] >= this->n3->partchin->side[2] && this->ava->body[16] <= this->n3->partchin->side[4] || this->ava->body[18] >= this->n3->partchin->side[2] && this->ava->body[18] <= this->n3->partchin->side[4])
				&& this->ava->body[17] - 2 >= this->n3->partchin->side[1] && this->ava->body[17] - 2 <= this->n3->partchin->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partchin!"<<endl;
			}
			else if((this->ava->body[16] >= this->n3->partjaw->side[2] && this->ava->body[16] <= this->n3->partjaw->side[4] || this->ava->body[18] >= this->n3->partjaw->side[2] && this->ava->body[18] <= this->n3->partjaw->side[4])
				&& this->ava->body[17] - 2 >= this->n3->partjaw->side[1] && this->ava->body[17] - 2 <= this->n3->partjaw->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partjaw!"<<endl;
			}
			else if((this->ava->body[16] >= this->n3->partface->side[2] && this->ava->body[16] <= this->n3->partface->side[4] || this->ava->body[18] >= this->n3->partface->side[2] && this->ava->body[18] <= this->n3->partface->side[4])
				&& this->ava->body[17] - 2 >= this->n3->partface->side[1] && this->ava->body[17] - 2 <= this->n3->partface->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partface!"<<endl;
			}
			else if((this->ava->body[4] >= this->n3->partchin->side[2] && this->ava->body[4] <= this->n3->partchin->side[4] || this->ava->body[6] >= this->n3->partchin->side[2] && this->ava->body[6] <= this->n3->partchin->side[4])
				&& (this->ava->body[7] - 2 >= this->n3->partchin->side[1] && this->ava->body[7] - 2 <= this->n3->partchin->side[3] || this->ava->body[9] - 2 >= this->n3->partchin->side[1] && this->ava->body[9] - 2 <= this->n3->partchin->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partchin!"<<endl;
			}
			else if((this->ava->body[4] >= this->n3->partjaw->side[2] && this->ava->body[4] <= this->n3->partjaw->side[4] || this->ava->body[6] >= this->n3->partjaw->side[2] && this->ava->body[6] <= this->n3->partjaw->side[4])
				&& (this->ava->body[7] - 2 >= this->n3->partjaw->side[1] && this->ava->body[7] - 2 <= this->n3->partjaw->side[3] || this->ava->body[9] - 2 >= this->n3->partjaw->side[1] && this->ava->body[9] - 2 <= this->n3->partjaw->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partjaw!"<<endl;
			}
			else if((this->ava->body[4] >= this->n3->partface->side[2] && this->ava->body[4] <= this->n3->partface->side[4] || this->ava->body[6] >= this->n3->partface->side[2] && this->ava->body[6] <= this->n3->partface->side[4])
				&& (this->ava->body[7] - 2 >= this->n3->partface->side[1] && this->ava->body[7] - 2 <= this->n3->partface->side[3] || this->ava->body[9] - 2 >= this->n3->partface->side[1] && this->ava->body[9] - 2 <= this->n3->partface->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partface!"<<endl;
			}
		}
		void collisionOnInvader3a(){
			if((this->ava->head[6]>= this->n3a->partchin->side[2] && this->ava->head[6]<= this->n3a->partchin->side[4] || this->ava->head[4]>= this->n3a->partchin->side[2] && this->ava->head[4]<= this->n3a->partchin->side[4])
				&& this->ava->head[3] - 13 >= this->n3a->partchin->side[1] && this->ava->head[3] - 13 <= this->n3a->partchin->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partchin!"<<endl;
			}
			else if((this->ava->head[6]>= this->n3a->partjaw->side[2] && this->ava->head[6]<= this->n3a->partjaw->side[4] || this->ava->head[4]>= this->n3a->partjaw->side[2] && this->ava->head[4]<= this->n3a->partjaw->side[4])
				&& this->ava->head[3] - 13 >= this->n3a->partjaw->side[1] && this->ava->head[3] - 13 <= this->n3a->partjaw->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partjaw!"<<endl;
			}
			else if((this->ava->head[6]>= this->n3a->partface->side[2] && this->ava->head[6]<= this->n3a->partface->side[4] || this->ava->head[4]>= this->n3a->partface->side[2] && this->ava->head[4]<= this->n3a->partface->side[4])
				&& this->ava->head[3] - 13 >= this->n3a->partface->side[1] && this->ava->head[3] - 13 <= this->n3a->partface->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partface!"<<endl;
			}
			else if((this->ava->body[12] >= this->n3a->parthead->side[0] && this->ava->body[12] <= this->n3a->parthead->side[6] || this->ava->body[10] >= this->n3a->parthead->side[0] && this->ava->body[10] <= this->n3a->parthead->side[6])
				&& this->ava->body[11] + 2>= this->n3a->parthead->side[1] && this->ava->body[13] + 2 <= this->n3a->parthead->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthead (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n3a->partforehead->side[0] && this->ava->body[12] <= this->n3a->partforehead->side[6] || this->ava->body[10] >= this->n3a->partforehead->side[0] && this->ava->body[10] <= this->n3a->partforehead->side[6])
				&& this->ava->body[11] + 2>= this->n3a->partforehead->side[1] && this->ava->body[13] + 2 <= this->n3a->partforehead->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partforehead (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n3a->partface->side[0] && this->ava->body[12] <= this->n3a->partface->side[6] || this->ava->body[10] >= this->n3a->partface->side[0] && this->ava->body[10] <= this->n3a->partface->side[6])
				&& this->ava->body[11] + 2>= this->n3a->partface->side[1] && this->ava->body[13] + 2 <= this->n3a->partface->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partface (butt)!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n3a->parthead->side[1] && this->ava->body[17] + 15 <= this->n3a->parthead->side[3] || this->ava->body[15] + 15 <= this->n3a->parthead->side[1] && this->ava->body[15] + 15 >= this->n3a->parthead->side[3])
				&& (this->ava->body[16] - 3 >= this->n3a->parthead->side[2] && this->ava->body[16] - 3 <= this->n3a->parthead->side[4] || this->ava->body[14] - 3 >= this->n3a->parthead->side[2] && this->ava->body[14] - 3 <= this->n3a->parthead->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing parthead: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n3a->partforehead->side[1] && this->ava->body[17] + 15 <= this->n3a->partforehead->side[3] || this->ava->body[15] + 15 <= this->n3a->partforehead->side[1] && this->ava->body[15] + 15 >= this->n3a->partforehead->side[3])
				&& (this->ava->body[16] - 3 >= this->n3a->partforehead->side[2] && this->ava->body[16] - 3 <= this->n3a->partforehead->side[4] || this->ava->body[14] - 3 >= this->n3a->partforehead->side[2] && this->ava->body[14] - 3 <= this->n3a->partforehead->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partforehead: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n3a->partface->side[1] && this->ava->body[17] + 15 <= this->n3a->partface->side[3] || this->ava->body[15] + 15 <= this->n3a->partface->side[1] && this->ava->body[15] + 15 >= this->n3a->partface->side[3])
				&& (this->ava->body[16] - 3 >= this->n3a->partface->side[2] && this->ava->body[16] - 3 <= this->n3a->partface->side[4] || this->ava->body[14] - 3 >= this->n3a->partface->side[2] && this->ava->body[14] - 3 <= this->n3a->partface->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partface: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n3a->partjaw->side[1] && this->ava->body[17] + 15 <= this->n3a->partjaw->side[3] || this->ava->body[15] + 15 <= this->n3a->partjaw->side[1] && this->ava->body[15] + 15 >= this->n3a->partjaw->side[3])
				&& (this->ava->body[16] - 3 >= this->n3a->partjaw->side[2] && this->ava->body[16] - 3 <= this->n3a->partjaw->side[4] || this->ava->body[14] - 3 >= this->n3a->partjaw->side[2] && this->ava->body[14] - 3 <= this->n3a->partjaw->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partjaw: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n3a->partchin->side[1] && this->ava->body[17] + 15 <= this->n3a->partchin->side[3] || this->ava->body[15] + 15 <= this->n3a->partchin->side[1] && this->ava->body[15] + 15 >= this->n3a->partchin->side[3])
				&& (this->ava->body[16] - 3 >= this->n3a->partchin->side[2] && this->ava->body[16] - 3 <= this->n3a->partchin->side[4] || this->ava->body[14] - 3 >= this->n3a->partchin->side[2] && this->ava->body[14] - 3 <= this->n3a->partchin->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partchin: side!"<<endl;
			}
			else if((this->ava->body[16] >= this->n3a->partchin->side[2] && this->ava->body[16] <= this->n3a->partchin->side[4] || this->ava->body[18] >= this->n3a->partchin->side[2] && this->ava->body[18] <= this->n3a->partchin->side[4])
				&& this->ava->body[17] - 2 >= this->n3a->partchin->side[1] && this->ava->body[17] - 2 <= this->n3a->partchin->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partchin!"<<endl;
			}
			else if((this->ava->body[16] >= this->n3a->partjaw->side[2] && this->ava->body[16] <= this->n3a->partjaw->side[4] || this->ava->body[18] >= this->n3a->partjaw->side[2] && this->ava->body[18] <= this->n3a->partjaw->side[4])
				&& this->ava->body[17] - 2 >= this->n3a->partjaw->side[1] && this->ava->body[17] - 2 <= this->n3a->partjaw->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partjaw!"<<endl;
			}
			else if((this->ava->body[16] >= this->n3a->partface->side[2] && this->ava->body[16] <= this->n3a->partface->side[4] || this->ava->body[18] >= this->n3a->partface->side[2] && this->ava->body[18] <= this->n3a->partface->side[4])
				&& this->ava->body[17] - 2 >= this->n3a->partface->side[1] && this->ava->body[17] - 2 <= this->n3a->partface->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partface!"<<endl;
			}
			else if((this->ava->body[4] >= this->n3a->partchin->side[2] && this->ava->body[4] <= this->n3a->partchin->side[4] || this->ava->body[6] >= this->n3a->partchin->side[2] && this->ava->body[6] <= this->n3a->partchin->side[4])
				&& (this->ava->body[7] - 2 >= this->n3a->partchin->side[1] && this->ava->body[7] - 2 <= this->n3a->partchin->side[3] || this->ava->body[9] - 2 >= this->n3a->partchin->side[1] && this->ava->body[9] - 2 <= this->n3a->partchin->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partchin!"<<endl;
			}
			else if((this->ava->body[4] >= this->n3a->partjaw->side[2] && this->ava->body[4] <= this->n3a->partjaw->side[4] || this->ava->body[6] >= this->n3a->partjaw->side[2] && this->ava->body[6] <= this->n3a->partjaw->side[4])
				&& (this->ava->body[7] - 2 >= this->n3a->partjaw->side[1] && this->ava->body[7] - 2 <= this->n3a->partjaw->side[3] || this->ava->body[9] - 2 >= this->n3a->partjaw->side[1] && this->ava->body[9] - 2 <= this->n3a->partjaw->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partjaw!"<<endl;
			}
			else if((this->ava->body[4] >= this->n3a->partface->side[2] && this->ava->body[4] <= this->n3a->partface->side[4] || this->ava->body[6] >= this->n3a->partface->side[2] && this->ava->body[6] <= this->n3a->partface->side[4])
				&& (this->ava->body[7] - 2 >= this->n3a->partface->side[1] && this->ava->body[7] - 2 <= this->n3a->partface->side[3] || this->ava->body[9] - 2 >= this->n3a->partface->side[1] && this->ava->body[9] - 2 <= this->n3a->partface->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partface!"<<endl;
			}
		}
		void collisionOnInvader2(){
			if((this->ava->head[6]>= this->n2->partfoot2->side[2] && this->ava->head[6]<= this->n2->partfoot2->side[4] || this->ava->head[4]>= this->n2->partfoot2->side[2] && this->ava->head[4]<= this->n2->partfoot2->side[4])
				&& this->ava->head[3] - 15 >= this->n2->partfoot2->side[1] && this->ava->head[3] - 15 <= this->n2->partfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partfoot2!"<<endl;
			}
			if((this->ava->head[6]>= this->n2->partfoot1->side[2] && this->ava->head[6]<= this->n2->partfoot1->side[4] || this->ava->head[4]>= this->n2->partfoot1->side[2] && this->ava->head[4]<= this->n2->partfoot1->side[4])
				&& this->ava->head[3] - 15 >= this->n2->partfoot1->side[1] && this->ava->head[3] - 15 <= this->n2->partfoot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partfoot1!"<<endl;
			}
			if((this->ava->head[6]>= this->n2->part2->side[2] && this->ava->head[6]<= this->n2->part2->side[4] || this->ava->head[4]>= this->n2->part2->side[2] && this->ava->head[4]<= this->n2->part2->side[4])
				&& this->ava->head[3] - 15 >= this->n2->part2->side[1] && this->ava->head[3] - 15 <= this->n2->part2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at part2!"<<endl;
			}
			else if((this->ava->body[12] >= this->n2->parthead1->side[0] && this->ava->body[12] <= this->n2->parthead1->side[6] || this->ava->body[10] >= this->n2->parthead1->side[0] && this->ava->body[10] <= this->n2->parthead1->side[6])
				&& this->ava->body[11] + 2>= this->n2->parthead1->side[1] && this->ava->body[13] + 2 <= this->n2->parthead1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthead1 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n2->parthead2->side[0] && this->ava->body[12] <= this->n2->parthead2->side[6] || this->ava->body[10] >= this->n2->parthead2->side[0] && this->ava->body[10] <= this->n2->parthead2->side[6])
				&& this->ava->body[11] + 2>= this->n2->parthead2->side[1] && this->ava->body[13] + 2 <= this->n2->parthead2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthead2 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n2->part1->side[0] && this->ava->body[12] <= this->n2->part1->side[6] || this->ava->body[10] >= this->n2->part1->side[0] && this->ava->body[10] <= this->n2->part1->side[6])
				&& this->ava->body[11] + 2>= this->n2->part1->side[1] && this->ava->body[13] + 2 <= this->n2->part1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at part1 (butt)!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n2->partfoot2->side[1] && this->ava->body[17] + 15 <= this->n2->partfoot2->side[3] || this->ava->body[15] + 15 <= this->n2->partfoot2->side[1] && this->ava->body[15] + 15 >= this->n2->partfoot2->side[3])
				&& (this->ava->body[16] - 3 >= this->n2->partfoot2->side[2] && this->ava->body[16] - 3 <= this->n2->partfoot2->side[4] || this->ava->body[14] - 3 >= this->n2->partfoot2->side[2] && this->ava->body[14] - 3 <= this->n2->partfoot2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partfoot2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n2->parthead2->side[1] && this->ava->body[17] + 15 <= this->n2->parthead2->side[3] || this->ava->body[15] + 15 <= this->n2->parthead2->side[1] && this->ava->body[15] + 15 >= this->n2->parthead2->side[3])
				&& (this->ava->body[16] - 3 >= this->n2->parthead2->side[2] && this->ava->body[16] - 3 <= this->n2->parthead2->side[4] || this->ava->body[14] - 3 >= this->n2->parthead2->side[2] && this->ava->body[14] - 3 <= this->n2->parthead2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing parthead2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n2->part2->side[1] && this->ava->body[17] + 15 <= this->n2->part2->side[3] || this->ava->body[15] + 15 <= this->n2->part2->side[1] && this->ava->body[15] + 15 >= this->n2->part2->side[3])
				&& (this->ava->body[16] - 3 >= this->n2->part2->side[2] && this->ava->body[16] - 3 <= this->n2->part2->side[4] || this->ava->body[14] - 3 >= this->n2->part2->side[2] && this->ava->body[14] - 3 <= this->n2->part2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing part2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n2->part1->side[1] && this->ava->body[17] + 15 <= this->n2->part1->side[3] || this->ava->body[15] + 15 <= this->n2->part1->side[1] && this->ava->body[15] + 15 >= this->n2->part1->side[3])
				&& (this->ava->body[16] - 3 >= this->n2->part1->side[2] && this->ava->body[16] - 3 <= this->n2->part1->side[4] || this->ava->body[14] - 3 >= this->n2->part1->side[2] && this->ava->body[14] - 3 <= this->n2->part1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing part1: side!"<<endl;
			}
			else if((this->ava->body[16] >= this->n2->partfoot2->side[2] && this->ava->body[16] <= this->n2->partfoot2->side[4] || this->ava->body[18] >= this->n2->partfoot2->side[2] && this->ava->body[18] <= this->n2->partfoot2->side[4])
				&& this->ava->body[17] - 2 >= this->n2->partfoot2->side[1] && this->ava->body[17] - 2 <= this->n2->partfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partfoot2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n2->parthead2->side[2] && this->ava->body[16] <= this->n2->parthead2->side[4] || this->ava->body[18] >= this->n2->parthead2->side[2] && this->ava->body[18] <= this->n2->parthead2->side[4])
				&& this->ava->body[17] - 2 >= this->n2->parthead2->side[1] && this->ava->body[17] - 2 <= this->n2->parthead2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing parthead2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n2->part2->side[2] && this->ava->body[16] <= this->n2->part2->side[4] || this->ava->body[18] >= this->n2->part2->side[2] && this->ava->body[18] <= this->n2->part2->side[4])
				&& this->ava->body[17] - 2 >= this->n2->part2->side[1] && this->ava->body[17] - 2 <= this->n2->part2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing part2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n2->part1->side[2] && this->ava->body[16] <= this->n2->part1->side[4] || this->ava->body[18] >= this->n2->part1->side[2] && this->ava->body[18] <= this->n2->part1->side[4])
				&& this->ava->body[17] - 2 >= this->n2->part1->side[1] && this->ava->body[17] - 2 <= this->n2->part1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing part1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n2->partfoot1->side[2] && this->ava->body[4] <= this->n2->partfoot1->side[4] || this->ava->body[6] >= this->n2->partfoot1->side[2] && this->ava->body[6] <= this->n2->partfoot1->side[4])
				&& (this->ava->body[7] - 2 >= this->n2->partfoot1->side[1] && this->ava->body[7] - 2 <= this->n2->partfoot1->side[3] || this->ava->body[9] - 2 >= this->n2->partfoot1->side[1] && this->ava->body[9] - 2 <= this->n2->partfoot1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partfoot1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n2->parthead1->side[2] && this->ava->body[4] <= this->n2->parthead1->side[4] || this->ava->body[6] >= this->n2->parthead1->side[2] && this->ava->body[6] <= this->n2->parthead1->side[4])
				&& (this->ava->body[7] - 2 >= this->n2->parthead1->side[1] && this->ava->body[7] - 2 <= this->n2->parthead1->side[3] || this->ava->body[9] - 2 >= this->n2->parthead1->side[1] && this->ava->body[9] - 2 <= this->n2->parthead1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing parthead1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n2->part2->side[2] && this->ava->body[4] <= this->n2->part2->side[4] || this->ava->body[6] >= this->n2->part2->side[2] && this->ava->body[6] <= this->n2->part2->side[4])
				&& (this->ava->body[7] - 2 >= this->n2->part2->side[1] && this->ava->body[7] - 2 <= this->n2->part2->side[3] || this->ava->body[9] - 2 >= this->n2->part2->side[1] && this->ava->body[9] - 2 <= this->n2->part2->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing part2!"<<endl;
			}
			else if((this->ava->body[4] >= this->n2->part1->side[2] && this->ava->body[4] <= this->n2->part1->side[4] || this->ava->body[6] >= this->n2->part1->side[2] && this->ava->body[6] <= this->n2->part1->side[4])
				&& (this->ava->body[7] - 2 >= this->n2->part1->side[1] && this->ava->body[7] - 2 <= this->n2->part1->side[3] || this->ava->body[9] - 2 >= this->n2->part1->side[1] && this->ava->body[9] - 2 <= this->n2->part1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing part1!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n2->partfoot1->side[1] && this->ava->body[7] + 15 <= this->n2->partfoot1->side[3] || this->ava->body[9] + 15 <= this->n2->partfoot1->side[1] && this->ava->body[9] + 15 >= this->n2->partfoot1->side[3])
				&& (this->ava->body[6] + 3 >= this->n2->partfoot1->side[2] && this->ava->body[6] + 3 <= this->n2->partfoot1->side[4] || this->ava->body[8] + 3 >= this->n2->partfoot1->side[2] && this->ava->body[8] + 3 <= this->n2->partfoot1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partfoot1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n2->parthead1->side[1] && this->ava->body[7] + 15 <= this->n2->parthead1->side[3] || this->ava->body[9] + 15 <= this->n2->parthead1->side[1] && this->ava->body[9] + 15 >= this->n2->parthead1->side[3])
				&& (this->ava->body[6] + 3 >= this->n2->parthead1->side[2] && this->ava->body[6] + 3 <= this->n2->parthead1->side[4] || this->ava->body[8] + 3 >= this->n2->parthead1->side[2] && this->ava->body[8] + 3 <= this->n2->parthead1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing parthead1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n2->part2->side[1] && this->ava->body[7] + 15 <= this->n2->part2->side[3] || this->ava->body[9] + 15 <= this->n2->part2->side[1] && this->ava->body[9] + 15 >= this->n2->part2->side[3])
				&& (this->ava->body[6] + 3 >= this->n2->part2->side[2] && this->ava->body[6] + 3 <= this->n2->part2->side[4] || this->ava->body[8] + 3 >= this->n2->part2->side[2] && this->ava->body[8] + 3 <= this->n2->part2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing part2: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n2->part1->side[1] && this->ava->body[7] + 15 <= this->n2->part1->side[3] || this->ava->body[9] + 15 <= this->n2->part1->side[1] && this->ava->body[9] + 15 >= this->n2->part1->side[3])
				&& (this->ava->body[6] + 3 >= this->n2->part1->side[2] && this->ava->body[6] + 3 <= this->n2->part1->side[4] || this->ava->body[8] + 3 >= this->n2->part1->side[2] && this->ava->body[8] + 3 <= this->n2->part1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing part1: side!"<<endl;
			}
		}
				void collisionOnInvader2a(){
			if((this->ava->head[6]>= this->n2a->partfoot2->side[2] && this->ava->head[6]<= this->n2a->partfoot2->side[4] || this->ava->head[4]>= this->n2a->partfoot2->side[2] && this->ava->head[4]<= this->n2a->partfoot2->side[4])
				&& this->ava->head[3] - 15 >= this->n2a->partfoot2->side[1] && this->ava->head[3] - 15 <= this->n2a->partfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partfoot2!"<<endl;
			}
			if((this->ava->head[6]>= this->n2a->partfoot1->side[2] && this->ava->head[6]<= this->n2a->partfoot1->side[4] || this->ava->head[4]>= this->n2a->partfoot1->side[2] && this->ava->head[4]<= this->n2a->partfoot1->side[4])
				&& this->ava->head[3] - 15 >= this->n2a->partfoot1->side[1] && this->ava->head[3] - 15 <= this->n2a->partfoot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partfoot1!"<<endl;
			}
			if((this->ava->head[6]>= this->n2a->part2->side[2] && this->ava->head[6]<= this->n2a->part2->side[4] || this->ava->head[4]>= this->n2a->part2->side[2] && this->ava->head[4]<= this->n2a->part2->side[4])
				&& this->ava->head[3] - 15 >= this->n2a->part2->side[1] && this->ava->head[3] - 15 <= this->n2a->part2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at part2!"<<endl;
			}
			else if((this->ava->body[12] >= this->n2a->parthead1->side[0] && this->ava->body[12] <= this->n2a->parthead1->side[6] || this->ava->body[10] >= this->n2a->parthead1->side[0] && this->ava->body[10] <= this->n2a->parthead1->side[6])
				&& this->ava->body[11] + 2>= this->n2a->parthead1->side[1] && this->ava->body[13] + 2 <= this->n2a->parthead1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthead1 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n2a->parthead2->side[0] && this->ava->body[12] <= this->n2a->parthead2->side[6] || this->ava->body[10] >= this->n2a->parthead2->side[0] && this->ava->body[10] <= this->n2a->parthead2->side[6])
				&& this->ava->body[11] + 2>= this->n2a->parthead2->side[1] && this->ava->body[13] + 2 <= this->n2a->parthead2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthead2 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n2a->part1->side[0] && this->ava->body[12] <= this->n2a->part1->side[6] || this->ava->body[10] >= this->n2a->part1->side[0] && this->ava->body[10] <= this->n2a->part1->side[6])
				&& this->ava->body[11] + 2>= this->n2a->part1->side[1] && this->ava->body[13] + 2 <= this->n2a->part1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at part1 (butt)!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n2a->partfoot2->side[1] && this->ava->body[17] + 15 <= this->n2a->partfoot2->side[3] || this->ava->body[15] + 15 <= this->n2a->partfoot2->side[1] && this->ava->body[15] + 15 >= this->n2a->partfoot2->side[3])
				&& (this->ava->body[16] - 3 >= this->n2a->partfoot2->side[2] && this->ava->body[16] - 3 <= this->n2a->partfoot2->side[4] || this->ava->body[14] - 3 >= this->n2a->partfoot2->side[2] && this->ava->body[14] - 3 <= this->n2a->partfoot2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partfoot2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n2a->parthead2->side[1] && this->ava->body[17] + 15 <= this->n2a->parthead2->side[3] || this->ava->body[15] + 15 <= this->n2a->parthead2->side[1] && this->ava->body[15] + 15 >= this->n2a->parthead2->side[3])
				&& (this->ava->body[16] - 3 >= this->n2a->parthead2->side[2] && this->ava->body[16] - 3 <= this->n2a->parthead2->side[4] || this->ava->body[14] - 3 >= this->n2a->parthead2->side[2] && this->ava->body[14] - 3 <= this->n2a->parthead2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing parthead2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n2a->part2->side[1] && this->ava->body[17] + 15 <= this->n2a->part2->side[3] || this->ava->body[15] + 15 <= this->n2a->part2->side[1] && this->ava->body[15] + 15 >= this->n2a->part2->side[3])
				&& (this->ava->body[16] - 3 >= this->n2a->part2->side[2] && this->ava->body[16] - 3 <= this->n2a->part2->side[4] || this->ava->body[14] - 3 >= this->n2a->part2->side[2] && this->ava->body[14] - 3 <= this->n2a->part2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing part2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n2a->part1->side[1] && this->ava->body[17] + 15 <= this->n2a->part1->side[3] || this->ava->body[15] + 15 <= this->n2a->part1->side[1] && this->ava->body[15] + 15 >= this->n2a->part1->side[3])
				&& (this->ava->body[16] - 3 >= this->n2a->part1->side[2] && this->ava->body[16] - 3 <= this->n2a->part1->side[4] || this->ava->body[14] - 3 >= this->n2a->part1->side[2] && this->ava->body[14] - 3 <= this->n2a->part1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing part1: side!"<<endl;
			}
			else if((this->ava->body[16] >= this->n2a->partfoot2->side[2] && this->ava->body[16] <= this->n2a->partfoot2->side[4] || this->ava->body[18] >= this->n2a->partfoot2->side[2] && this->ava->body[18] <= this->n2a->partfoot2->side[4])
				&& this->ava->body[17] - 2 >= this->n2a->partfoot2->side[1] && this->ava->body[17] - 2 <= this->n2a->partfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partfoot2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n2a->parthead2->side[2] && this->ava->body[16] <= this->n2a->parthead2->side[4] || this->ava->body[18] >= this->n2a->parthead2->side[2] && this->ava->body[18] <= this->n2a->parthead2->side[4])
				&& this->ava->body[17] - 2 >= this->n2a->parthead2->side[1] && this->ava->body[17] - 2 <= this->n2a->parthead2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing parthead2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n2a->part2->side[2] && this->ava->body[16] <= this->n2a->part2->side[4] || this->ava->body[18] >= this->n2a->part2->side[2] && this->ava->body[18] <= this->n2a->part2->side[4])
				&& this->ava->body[17] - 2 >= this->n2a->part2->side[1] && this->ava->body[17] - 2 <= this->n2a->part2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing part2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n2a->part1->side[2] && this->ava->body[16] <= this->n2a->part1->side[4] || this->ava->body[18] >= this->n2a->part1->side[2] && this->ava->body[18] <= this->n2a->part1->side[4])
				&& this->ava->body[17] - 2 >= this->n2a->part1->side[1] && this->ava->body[17] - 2 <= this->n2a->part1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing part1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n2a->partfoot1->side[2] && this->ava->body[4] <= this->n2a->partfoot1->side[4] || this->ava->body[6] >= this->n2a->partfoot1->side[2] && this->ava->body[6] <= this->n2a->partfoot1->side[4])
				&& (this->ava->body[7] - 2 >= this->n2a->partfoot1->side[1] && this->ava->body[7] - 2 <= this->n2a->partfoot1->side[3] || this->ava->body[9] - 2 >= this->n2a->partfoot1->side[1] && this->ava->body[9] - 2 <= this->n2a->partfoot1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partfoot1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n2a->parthead1->side[2] && this->ava->body[4] <= this->n2a->parthead1->side[4] || this->ava->body[6] >= this->n2a->parthead1->side[2] && this->ava->body[6] <= this->n2a->parthead1->side[4])
				&& (this->ava->body[7] - 2 >= this->n2a->parthead1->side[1] && this->ava->body[7] - 2 <= this->n2a->parthead1->side[3] || this->ava->body[9] - 2 >= this->n2a->parthead1->side[1] && this->ava->body[9] - 2 <= this->n2a->parthead1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing parthead1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n2a->part2->side[2] && this->ava->body[4] <= this->n2a->part2->side[4] || this->ava->body[6] >= this->n2a->part2->side[2] && this->ava->body[6] <= this->n2a->part2->side[4])
				&& (this->ava->body[7] - 2 >= this->n2a->part2->side[1] && this->ava->body[7] - 2 <= this->n2a->part2->side[3] || this->ava->body[9] - 2 >= this->n2a->part2->side[1] && this->ava->body[9] - 2 <= this->n2a->part2->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing part2!"<<endl;
			}
			else if((this->ava->body[4] >= this->n2a->part1->side[2] && this->ava->body[4] <= this->n2a->part1->side[4] || this->ava->body[6] >= this->n2a->part1->side[2] && this->ava->body[6] <= this->n2a->part1->side[4])
				&& (this->ava->body[7] - 2 >= this->n2a->part1->side[1] && this->ava->body[7] - 2 <= this->n2a->part1->side[3] || this->ava->body[9] - 2 >= this->n2a->part1->side[1] && this->ava->body[9] - 2 <= this->n2a->part1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing part1!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n2a->partfoot1->side[1] && this->ava->body[7] + 15 <= this->n2a->partfoot1->side[3] || this->ava->body[9] + 15 <= this->n2a->partfoot1->side[1] && this->ava->body[9] + 15 >= this->n2a->partfoot1->side[3])
				&& (this->ava->body[6] + 3 >= this->n2a->partfoot1->side[2] && this->ava->body[6] + 3 <= this->n2a->partfoot1->side[4] || this->ava->body[8] + 3 >= this->n2a->partfoot1->side[2] && this->ava->body[8] + 3 <= this->n2a->partfoot1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partfoot1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n2a->parthead1->side[1] && this->ava->body[7] + 15 <= this->n2a->parthead1->side[3] || this->ava->body[9] + 15 <= this->n2a->parthead1->side[1] && this->ava->body[9] + 15 >= this->n2a->parthead1->side[3])
				&& (this->ava->body[6] + 3 >= this->n2a->parthead1->side[2] && this->ava->body[6] + 3 <= this->n2a->parthead1->side[4] || this->ava->body[8] + 3 >= this->n2a->parthead1->side[2] && this->ava->body[8] + 3 <= this->n2a->parthead1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing parthead1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n2a->part2->side[1] && this->ava->body[7] + 15 <= this->n2a->part2->side[3] || this->ava->body[9] + 15 <= this->n2a->part2->side[1] && this->ava->body[9] + 15 >= this->n2a->part2->side[3])
				&& (this->ava->body[6] + 3 >= this->n2a->part2->side[2] && this->ava->body[6] + 3 <= this->n2a->part2->side[4] || this->ava->body[8] + 3 >= this->n2a->part2->side[2] && this->ava->body[8] + 3 <= this->n2a->part2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing part2: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n2a->part1->side[1] && this->ava->body[7] + 15 <= this->n2a->part1->side[3] || this->ava->body[9] + 15 <= this->n2a->part1->side[1] && this->ava->body[9] + 15 >= this->n2a->part1->side[3])
				&& (this->ava->body[6] + 3 >= this->n2a->part1->side[2] && this->ava->body[6] + 3 <= this->n2a->part1->side[4] || this->ava->body[8] + 3 >= this->n2a->part1->side[2] && this->ava->body[8] + 3 <= this->n2a->part1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing part1: side!"<<endl;
			}
		}
		void collisionOnInvader4(){
			if((this->ava->head[6]>= this->n4->partfoot2->side[2] && this->ava->head[6]<= this->n4->partfoot2->side[4] || this->ava->head[4]>= this->n4->partfoot2->side[2] && this->ava->head[4]<= this->n4->partfoot2->side[4])
				&& this->ava->head[3] - 15 >= this->n4->partfoot2->side[1] && this->ava->head[3] - 15 <= this->n4->partfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partfoot2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n4->partfoot1->side[2] && this->ava->head[6]<= this->n4->partfoot1->side[4] || this->ava->head[4]>= this->n4->partfoot1->side[2] && this->ava->head[4]<= this->n4->partfoot1->side[4])
				&& this->ava->head[3] - 15 >= this->n4->partfoot1->side[1] && this->ava->head[3] - 15 <= this->n4->partfoot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partfoot1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n4->partfoot1->side[2] && this->ava->head[6]<= this->n4->partfoot1->side[4] || this->ava->head[4]>= this->n4->partfoot1->side[2] && this->ava->head[4]<= this->n4->partfoot1->side[4])
				&& this->ava->head[3] - 15 >= this->n4->partfoot1->side[1] && this->ava->head[3] - 15 <= this->n4->partfoot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partfoot1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n4->partlongfoot2->side[2] && this->ava->head[6]<= this->n4->partlongfoot2->side[4] || this->ava->head[4]>= this->n4->partlongfoot2->side[2] && this->ava->head[4]<= this->n4->partlongfoot2->side[4])
				&& this->ava->head[3] - 15 >= this->n4->partlongfoot2->side[1] && this->ava->head[3] - 15 <= this->n4->partlongfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partlongfoot2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n4->partlongfoot1->side[2] && this->ava->head[6]<= this->n4->partlongfoot1->side[4] || this->ava->head[4]>= this->n4->partlongfoot1->side[2] && this->ava->head[4]<= this->n4->partlongfoot1->side[4])
				&& this->ava->head[3] - 15 >= this->n4->partlongfoot1->side[1] && this->ava->head[3] - 15 <= this->n4->partlongfoot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partlongfoot1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n4->parthorn2->side[2] && this->ava->head[6]<= this->n4->parthorn2->side[4] || this->ava->head[4]>= this->n4->parthorn2->side[2] && this->ava->head[4]<= this->n4->parthorn2->side[4])
				&& this->ava->head[3] - 15 >= this->n4->parthorn2->side[1] && this->ava->head[3] - 15 <= this->n4->parthorn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthorn2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n4->parthorn1->side[2] && this->ava->head[6]<= this->n4->parthorn1->side[4] || this->ava->head[4]>= this->n4->parthorn1->side[2] && this->ava->head[4]<= this->n4->parthorn1->side[4])
				&& this->ava->head[3] - 15 >= this->n4->parthorn1->side[1] && this->ava->head[3] - 15 <= this->n4->parthorn1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthorn1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n4->parthead->side[2] && this->ava->head[6]<= this->n4->parthead->side[4] || this->ava->head[4]>= this->n4->parthead->side[2] && this->ava->head[4]<= this->n4->parthead->side[4])
				&& this->ava->head[3] - 15 >= this->n4->parthead->side[1] && this->ava->head[3] - 15 <= this->n4->parthead->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthead!"<<endl;
			}
			else if((this->ava->body[12] >= this->n4->parthead->side[0] && this->ava->body[12] <= this->n4->parthead->side[6] || this->ava->body[10] >= this->n4->parthead->side[0] && this->ava->body[10] <= this->n4->parthead->side[6])
				&& this->ava->body[11] + 2>= this->n4->parthead->side[1] && this->ava->body[13] + 2 <= this->n4->parthead->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthead (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n4->parthorn1->side[0] && this->ava->body[12] <= this->n4->parthorn1->side[6] || this->ava->body[10] >= this->n4->parthorn1->side[0] && this->ava->body[10] <= this->n4->parthorn1->side[6])
				&& this->ava->body[11] + 2>= this->n4->parthorn1->side[1] && this->ava->body[13] + 2 <= this->n4->parthorn1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthorn1 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n4->parthorn2->side[0] && this->ava->body[12] <= this->n4->parthorn2->side[6] || this->ava->body[10] >= this->n4->parthorn2->side[0] && this->ava->body[10] <= this->n4->parthorn2->side[6])
				&& this->ava->body[11] + 2>= this->n4->parthorn2->side[1] && this->ava->body[13] + 2 <= this->n4->parthorn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthorn2 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n4->partlongfoot1->side[0] && this->ava->body[12] <= this->n4->partlongfoot1->side[6] || this->ava->body[10] >= this->n4->partlongfoot1->side[0] && this->ava->body[10] <= this->n4->partlongfoot1->side[6])
				&& this->ava->body[11] + 2>= this->n4->partlongfoot1->side[1] && this->ava->body[13] + 2 <= this->n4->partlongfoot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partlongfoot1 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n4->partlongfoot2->side[0] && this->ava->body[12] <= this->n4->partlongfoot2->side[6] || this->ava->body[10] >= this->n4->partlongfoot2->side[0] && this->ava->body[10] <= this->n4->partlongfoot2->side[6])
				&& this->ava->body[11] + 2>= this->n4->partlongfoot2->side[1] && this->ava->body[13] + 2 <= this->n4->partlongfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partlongfoot2 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n4->partfoot1->side[0] && this->ava->body[12] <= this->n4->partfoot1->side[6] || this->ava->body[10] >= this->n4->partfoot1->side[0] && this->ava->body[10] <= this->n4->partfoot1->side[6])
				&& this->ava->body[11] + 2>= this->n4->partfoot1->side[1] && this->ava->body[13] + 2 <= this->n4->partfoot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partfoot1 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n4->partfoot2->side[0] && this->ava->body[12] <= this->n4->partfoot2->side[6] || this->ava->body[10] >= this->n4->partfoot2->side[0] && this->ava->body[10] <= this->n4->partfoot2->side[6])
				&& this->ava->body[11] + 2>= this->n4->partfoot2->side[1] && this->ava->body[13] + 2 <= this->n4->partfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partfoot2 (butt)!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n4->partlongfoot2->side[1] && this->ava->body[17] + 15 <= this->n4->partlongfoot2->side[3] || this->ava->body[15] + 15 <= this->n4->partlongfoot2->side[1] && this->ava->body[15] + 15 >= this->n4->partlongfoot2->side[3])
				&& (this->ava->body[16] - 3 >= this->n4->partlongfoot2->side[2] && this->ava->body[16] - 3 <= this->n4->partlongfoot2->side[4] || this->ava->body[14] - 3 >= this->n4->partlongfoot2->side[2] && this->ava->body[14] - 3 <= this->n4->partlongfoot2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partlongfoot2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n4->partfoot2->side[1] && this->ava->body[17] + 15 <= this->n4->partfoot2->side[3] || this->ava->body[15] + 15 <= this->n4->partfoot2->side[1] && this->ava->body[15] + 15 >= this->n4->partfoot2->side[3])
				&& (this->ava->body[16] - 3 >= this->n4->partfoot2->side[2] && this->ava->body[16] - 3 <= this->n4->partfoot2->side[4] || this->ava->body[14] - 3 >= this->n4->partfoot2->side[2] && this->ava->body[14] - 3 <= this->n4->partfoot2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partfoot2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n4->parthorn2->side[1] && this->ava->body[17] + 15 <= this->n4->parthorn2->side[3] || this->ava->body[15] + 15 <= this->n4->parthorn2->side[1] && this->ava->body[15] + 15 >= this->n4->parthorn2->side[3])
				&& (this->ava->body[16] - 3 >= this->n4->parthorn2->side[2] && this->ava->body[16] - 3 <= this->n4->parthorn2->side[4] || this->ava->body[14] - 3 >= this->n4->parthorn2->side[2] && this->ava->body[14] - 3 <= this->n4->parthorn2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing parthorn2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n4->parthead->side[1] && this->ava->body[17] + 15 <= this->n4->parthead->side[3] || this->ava->body[15] + 15 <= this->n4->parthead->side[1] && this->ava->body[15] + 15 >= this->n4->parthead->side[3])
				&& (this->ava->body[16] - 3 >= this->n4->parthead->side[2] && this->ava->body[16] - 3 <= this->n4->parthead->side[4] || this->ava->body[14] - 3 >= this->n4->parthead->side[2] && this->ava->body[14] - 3 <= this->n4->parthead->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing parthead: side!"<<endl;
			}
			else if((this->ava->body[16] >= this->n4->partlongfoot2->side[2] && this->ava->body[16] <= this->n4->partlongfoot2->side[4] || this->ava->body[18] >= this->n4->partlongfoot2->side[2] && this->ava->body[18] <= this->n4->partlongfoot2->side[4])
				&& this->ava->body[17] - 2 >= this->n4->partlongfoot2->side[1] && this->ava->body[17] - 2 <= this->n4->partlongfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partlongfoot2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n4->partfoot2->side[2] && this->ava->body[16] <= this->n4->partfoot2->side[4] || this->ava->body[18] >= this->n4->partfoot2->side[2] && this->ava->body[18] <= this->n4->partfoot2->side[4])
				&& this->ava->body[17] - 2 >= this->n4->partfoot2->side[1] && this->ava->body[17] - 2 <= this->n4->partfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partfoot2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n4->parthorn2->side[2] && this->ava->body[16] <= this->n4->parthorn2->side[4] || this->ava->body[18] >= this->n4->parthorn2->side[2] && this->ava->body[18] <= this->n4->parthorn2->side[4])
				&& this->ava->body[17] - 2 >= this->n4->parthorn2->side[1] && this->ava->body[17] - 2 <= this->n4->parthorn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing parthorn2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n4->parthead->side[2] && this->ava->body[16] <= this->n4->parthead->side[4] || this->ava->body[18] >= this->n4->parthead->side[2] && this->ava->body[18] <= this->n4->parthead->side[4])
				&& this->ava->body[17] - 2 >= this->n4->parthead->side[1] && this->ava->body[17] - 2 <= this->n4->parthead->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing parthead!"<<endl;
			}
			else if((this->ava->body[4] >= this->n4->partlongfoot1->side[2] && this->ava->body[4] <= this->n4->partlongfoot1->side[4] || this->ava->body[6] >= this->n4->partlongfoot1->side[2] && this->ava->body[6] <= this->n4->partlongfoot1->side[4])
				&& (this->ava->body[7] - 2 >= this->n4->partlongfoot1->side[1] && this->ava->body[7] - 2 <= this->n4->partlongfoot1->side[3] || this->ava->body[9] - 2 >= this->n4->partlongfoot1->side[1] && this->ava->body[9] - 2 <= this->n4->partlongfoot1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partlongfoot1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n4->partfoot1->side[2] && this->ava->body[4] <= this->n4->partfoot1->side[4] || this->ava->body[6] >= this->n4->partfoot1->side[2] && this->ava->body[6] <= this->n4->partfoot1->side[4])
				&& (this->ava->body[7] - 2 >= this->n4->partfoot1->side[1] && this->ava->body[7] - 2 <= this->n4->partfoot1->side[3] || this->ava->body[9] - 2 >= this->n4->partfoot1->side[1] && this->ava->body[9] - 2 <= this->n4->partfoot1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partfoot1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n4->parthorn1->side[2] && this->ava->body[4] <= this->n4->parthorn1->side[4] || this->ava->body[6] >= this->n4->parthorn1->side[2] && this->ava->body[6] <= this->n4->parthorn1->side[4])
				&& (this->ava->body[7] - 2 >= this->n4->parthorn1->side[1] && this->ava->body[7] - 2 <= this->n4->parthorn1->side[3] || this->ava->body[9] - 2 >= this->n4->parthorn1->side[1] && this->ava->body[9] - 2 <= this->n4->parthorn1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing parthorn1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n4->parthead->side[2] && this->ava->body[4] <= this->n4->parthead->side[4] || this->ava->body[6] >= this->n4->parthead->side[2] && this->ava->body[6] <= this->n4->parthead->side[4])
				&& (this->ava->body[7] - 2 >= this->n4->parthead->side[1] && this->ava->body[7] - 2 <= this->n4->parthead->side[3] || this->ava->body[9] - 2 >= this->n4->parthead->side[1] && this->ava->body[9] - 2 <= this->n4->parthead->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing parthead!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n4->partlongfoot1->side[1] && this->ava->body[7] + 15 <= this->n4->partlongfoot1->side[3] || this->ava->body[9] + 15 <= this->n4->partlongfoot1->side[1] && this->ava->body[9] + 15 >= this->n4->partlongfoot1->side[3])
				&& (this->ava->body[6] + 3 >= this->n4->partlongfoot1->side[2] && this->ava->body[6] + 3 <= this->n4->partlongfoot1->side[4] || this->ava->body[8] + 3 >= this->n4->partlongfoot1->side[2] && this->ava->body[8] + 3 <= this->n4->partlongfoot1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partlongfoot1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n4->partlongfoot1->side[1] && this->ava->body[7] + 15 <= this->n4->partlongfoot1->side[3] || this->ava->body[9] + 15 <= this->n4->partlongfoot1->side[1] && this->ava->body[9] + 15 >= this->n4->partlongfoot1->side[3])
				&& (this->ava->body[6] + 3 >= this->n4->partlongfoot1->side[2] && this->ava->body[6] + 3 <= this->n4->partlongfoot1->side[4] || this->ava->body[8] + 3 >= this->n4->partlongfoot1->side[2] && this->ava->body[8] + 3 <= this->n4->partlongfoot1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partlongfoot1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n4->partlongfoot1->side[1] && this->ava->body[7] + 15 <= this->n4->partlongfoot1->side[3] || this->ava->body[9] + 15 <= this->n4->partlongfoot1->side[1] && this->ava->body[9] + 15 >= this->n4->partlongfoot1->side[3])
				&& (this->ava->body[6] + 3 >= this->n4->partlongfoot1->side[2] && this->ava->body[6] + 3 <= this->n4->partlongfoot1->side[4] || this->ava->body[8] + 3 >= this->n4->partlongfoot1->side[2] && this->ava->body[8] + 3 <= this->n4->partlongfoot1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partlongfoot1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n4->partlongfoot1->side[1] && this->ava->body[7] + 15 <= this->n4->partlongfoot1->side[3] || this->ava->body[9] + 15 <= this->n4->partlongfoot1->side[1] && this->ava->body[9] + 15 >= this->n4->partlongfoot1->side[3])
				&& (this->ava->body[6] + 3 >= this->n4->partlongfoot1->side[2] && this->ava->body[6] + 3 <= this->n4->partlongfoot1->side[4] || this->ava->body[8] + 3 >= this->n4->partlongfoot1->side[2] && this->ava->body[8] + 3 <= this->n4->partlongfoot1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partlongfoot1: side!"<<endl;
			}
		}
		void collisionOnInvader4a(){
			if((this->ava->head[6]>= this->n4a->partfoot2->side[2] && this->ava->head[6]<= this->n4a->partfoot2->side[4] || this->ava->head[4]>= this->n4a->partfoot2->side[2] && this->ava->head[4]<= this->n4a->partfoot2->side[4])
				&& this->ava->head[3] - 15 >= this->n4a->partfoot2->side[1] && this->ava->head[3] - 15 <= this->n4a->partfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partfoot2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n4a->partfoot1->side[2] && this->ava->head[6]<= this->n4a->partfoot1->side[4] || this->ava->head[4]>= this->n4a->partfoot1->side[2] && this->ava->head[4]<= this->n4a->partfoot1->side[4])
				&& this->ava->head[3] - 15 >= this->n4a->partfoot1->side[1] && this->ava->head[3] - 15 <= this->n4a->partfoot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partfoot1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n4a->partfoot1->side[2] && this->ava->head[6]<= this->n4a->partfoot1->side[4] || this->ava->head[4]>= this->n4a->partfoot1->side[2] && this->ava->head[4]<= this->n4a->partfoot1->side[4])
				&& this->ava->head[3] - 15 >= this->n4a->partfoot1->side[1] && this->ava->head[3] - 15 <= this->n4a->partfoot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partfoot1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n4a->partlongfoot2->side[2] && this->ava->head[6]<= this->n4a->partlongfoot2->side[4] || this->ava->head[4]>= this->n4a->partlongfoot2->side[2] && this->ava->head[4]<= this->n4a->partlongfoot2->side[4])
				&& this->ava->head[3] - 15 >= this->n4a->partlongfoot2->side[1] && this->ava->head[3] - 15 <= this->n4a->partlongfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partlongfoot2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n4a->partlongfoot1->side[2] && this->ava->head[6]<= this->n4a->partlongfoot1->side[4] || this->ava->head[4]>= this->n4a->partlongfoot1->side[2] && this->ava->head[4]<= this->n4a->partlongfoot1->side[4])
				&& this->ava->head[3] - 15 >= this->n4a->partlongfoot1->side[1] && this->ava->head[3] - 15 <= this->n4a->partlongfoot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partlongfoot1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n4a->parthorn2->side[2] && this->ava->head[6]<= this->n4a->parthorn2->side[4] || this->ava->head[4]>= this->n4a->parthorn2->side[2] && this->ava->head[4]<= this->n4a->parthorn2->side[4])
				&& this->ava->head[3] - 15 >= this->n4a->parthorn2->side[1] && this->ava->head[3] - 15 <= this->n4a->parthorn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthorn2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n4a->parthorn1->side[2] && this->ava->head[6]<= this->n4a->parthorn1->side[4] || this->ava->head[4]>= this->n4a->parthorn1->side[2] && this->ava->head[4]<= this->n4a->parthorn1->side[4])
				&& this->ava->head[3] - 15 >= this->n4a->parthorn1->side[1] && this->ava->head[3] - 15 <= this->n4a->parthorn1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthorn1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n4a->parthead->side[2] && this->ava->head[6]<= this->n4a->parthead->side[4] || this->ava->head[4]>= this->n4a->parthead->side[2] && this->ava->head[4]<= this->n4a->parthead->side[4])
				&& this->ava->head[3] - 15 >= this->n4a->parthead->side[1] && this->ava->head[3] - 15 <= this->n4a->parthead->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthead!"<<endl;
			}
			else if((this->ava->body[12] >= this->n4a->parthead->side[0] && this->ava->body[12] <= this->n4a->parthead->side[6] || this->ava->body[10] >= this->n4a->parthead->side[0] && this->ava->body[10] <= this->n4a->parthead->side[6])
				&& this->ava->body[11] + 2>= this->n4a->parthead->side[1] && this->ava->body[13] + 2 <= this->n4a->parthead->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthead (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n4a->parthorn1->side[0] && this->ava->body[12] <= this->n4a->parthorn1->side[6] || this->ava->body[10] >= this->n4a->parthorn1->side[0] && this->ava->body[10] <= this->n4a->parthorn1->side[6])
				&& this->ava->body[11] + 2>= this->n4a->parthorn1->side[1] && this->ava->body[13] + 2 <= this->n4a->parthorn1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthorn1 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n4a->parthorn2->side[0] && this->ava->body[12] <= this->n4a->parthorn2->side[6] || this->ava->body[10] >= this->n4a->parthorn2->side[0] && this->ava->body[10] <= this->n4a->parthorn2->side[6])
				&& this->ava->body[11] + 2>= this->n4a->parthorn2->side[1] && this->ava->body[13] + 2 <= this->n4a->parthorn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at parthorn2 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n4a->partlongfoot1->side[0] && this->ava->body[12] <= this->n4a->partlongfoot1->side[6] || this->ava->body[10] >= this->n4a->partlongfoot1->side[0] && this->ava->body[10] <= this->n4a->partlongfoot1->side[6])
				&& this->ava->body[11] + 2>= this->n4a->partlongfoot1->side[1] && this->ava->body[13] + 2 <= this->n4a->partlongfoot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partlongfoot1 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n4a->partlongfoot2->side[0] && this->ava->body[12] <= this->n4a->partlongfoot2->side[6] || this->ava->body[10] >= this->n4a->partlongfoot2->side[0] && this->ava->body[10] <= this->n4a->partlongfoot2->side[6])
				&& this->ava->body[11] + 2>= this->n4a->partlongfoot2->side[1] && this->ava->body[13] + 2 <= this->n4a->partlongfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partlongfoot2 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n4a->partfoot1->side[0] && this->ava->body[12] <= this->n4a->partfoot1->side[6] || this->ava->body[10] >= this->n4a->partfoot1->side[0] && this->ava->body[10] <= this->n4a->partfoot1->side[6])
				&& this->ava->body[11] + 2>= this->n4a->partfoot1->side[1] && this->ava->body[13] + 2 <= this->n4a->partfoot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partfoot1 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n4a->partfoot2->side[0] && this->ava->body[12] <= this->n4a->partfoot2->side[6] || this->ava->body[10] >= this->n4a->partfoot2->side[0] && this->ava->body[10] <= this->n4a->partfoot2->side[6])
				&& this->ava->body[11] + 2>= this->n4a->partfoot2->side[1] && this->ava->body[13] + 2 <= this->n4a->partfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at partfoot2 (butt)!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n4a->partlongfoot2->side[1] && this->ava->body[17] + 15 <= this->n4a->partlongfoot2->side[3] || this->ava->body[15] + 15 <= this->n4a->partlongfoot2->side[1] && this->ava->body[15] + 15 >= this->n4a->partlongfoot2->side[3])
				&& (this->ava->body[16] - 3 >= this->n4a->partlongfoot2->side[2] && this->ava->body[16] - 3 <= this->n4a->partlongfoot2->side[4] || this->ava->body[14] - 3 >= this->n4a->partlongfoot2->side[2] && this->ava->body[14] - 3 <= this->n4a->partlongfoot2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partlongfoot2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n4a->partfoot2->side[1] && this->ava->body[17] + 15 <= this->n4a->partfoot2->side[3] || this->ava->body[15] + 15 <= this->n4a->partfoot2->side[1] && this->ava->body[15] + 15 >= this->n4a->partfoot2->side[3])
				&& (this->ava->body[16] - 3 >= this->n4a->partfoot2->side[2] && this->ava->body[16] - 3 <= this->n4a->partfoot2->side[4] || this->ava->body[14] - 3 >= this->n4a->partfoot2->side[2] && this->ava->body[14] - 3 <= this->n4a->partfoot2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partfoot2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n4a->parthorn2->side[1] && this->ava->body[17] + 15 <= this->n4a->parthorn2->side[3] || this->ava->body[15] + 15 <= this->n4a->parthorn2->side[1] && this->ava->body[15] + 15 >= this->n4a->parthorn2->side[3])
				&& (this->ava->body[16] - 3 >= this->n4a->parthorn2->side[2] && this->ava->body[16] - 3 <= this->n4a->parthorn2->side[4] || this->ava->body[14] - 3 >= this->n4a->parthorn2->side[2] && this->ava->body[14] - 3 <= this->n4a->parthorn2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing parthorn2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n4a->parthead->side[1] && this->ava->body[17] + 15 <= this->n4a->parthead->side[3] || this->ava->body[15] + 15 <= this->n4a->parthead->side[1] && this->ava->body[15] + 15 >= this->n4a->parthead->side[3])
				&& (this->ava->body[16] - 3 >= this->n4a->parthead->side[2] && this->ava->body[16] - 3 <= this->n4a->parthead->side[4] || this->ava->body[14] - 3 >= this->n4a->parthead->side[2] && this->ava->body[14] - 3 <= this->n4a->parthead->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing parthead: side!"<<endl;
			}
			else if((this->ava->body[16] >= this->n4a->partlongfoot2->side[2] && this->ava->body[16] <= this->n4a->partlongfoot2->side[4] || this->ava->body[18] >= this->n4a->partlongfoot2->side[2] && this->ava->body[18] <= this->n4a->partlongfoot2->side[4])
				&& this->ava->body[17] - 2 >= this->n4a->partlongfoot2->side[1] && this->ava->body[17] - 2 <= this->n4a->partlongfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partlongfoot2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n4a->partfoot2->side[2] && this->ava->body[16] <= this->n4a->partfoot2->side[4] || this->ava->body[18] >= this->n4a->partfoot2->side[2] && this->ava->body[18] <= this->n4a->partfoot2->side[4])
				&& this->ava->body[17] - 2 >= this->n4a->partfoot2->side[1] && this->ava->body[17] - 2 <= this->n4a->partfoot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing partfoot2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n4a->parthorn2->side[2] && this->ava->body[16] <= this->n4a->parthorn2->side[4] || this->ava->body[18] >= this->n4a->parthorn2->side[2] && this->ava->body[18] <= this->n4a->parthorn2->side[4])
				&& this->ava->body[17] - 2 >= this->n4a->parthorn2->side[1] && this->ava->body[17] - 2 <= this->n4a->parthorn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing parthorn2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n4a->parthead->side[2] && this->ava->body[16] <= this->n4a->parthead->side[4] || this->ava->body[18] >= this->n4a->parthead->side[2] && this->ava->body[18] <= this->n4a->parthead->side[4])
				&& this->ava->body[17] - 2 >= this->n4a->parthead->side[1] && this->ava->body[17] - 2 <= this->n4a->parthead->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing parthead!"<<endl;
			}
			else if((this->ava->body[4] >= this->n4a->partlongfoot1->side[2] && this->ava->body[4] <= this->n4a->partlongfoot1->side[4] || this->ava->body[6] >= this->n4a->partlongfoot1->side[2] && this->ava->body[6] <= this->n4a->partlongfoot1->side[4])
				&& (this->ava->body[7] - 2 >= this->n4a->partlongfoot1->side[1] && this->ava->body[7] - 2 <= this->n4a->partlongfoot1->side[3] || this->ava->body[9] - 2 >= this->n4a->partlongfoot1->side[1] && this->ava->body[9] - 2 <= this->n4a->partlongfoot1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partlongfoot1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n4a->partfoot1->side[2] && this->ava->body[4] <= this->n4a->partfoot1->side[4] || this->ava->body[6] >= this->n4a->partfoot1->side[2] && this->ava->body[6] <= this->n4a->partfoot1->side[4])
				&& (this->ava->body[7] - 2 >= this->n4a->partfoot1->side[1] && this->ava->body[7] - 2 <= this->n4a->partfoot1->side[3] || this->ava->body[9] - 2 >= this->n4a->partfoot1->side[1] && this->ava->body[9] - 2 <= this->n4a->partfoot1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partfoot1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n4a->parthorn1->side[2] && this->ava->body[4] <= this->n4a->parthorn1->side[4] || this->ava->body[6] >= this->n4a->parthorn1->side[2] && this->ava->body[6] <= this->n4a->parthorn1->side[4])
				&& (this->ava->body[7] - 2 >= this->n4a->parthorn1->side[1] && this->ava->body[7] - 2 <= this->n4a->parthorn1->side[3] || this->ava->body[9] - 2 >= this->n4a->parthorn1->side[1] && this->ava->body[9] - 2 <= this->n4a->parthorn1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing parthorn1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n4a->parthead->side[2] && this->ava->body[4] <= this->n4a->parthead->side[4] || this->ava->body[6] >= this->n4a->parthead->side[2] && this->ava->body[6] <= this->n4a->parthead->side[4])
				&& (this->ava->body[7] - 2 >= this->n4a->parthead->side[1] && this->ava->body[7] - 2 <= this->n4a->parthead->side[3] || this->ava->body[9] - 2 >= this->n4a->parthead->side[1] && this->ava->body[9] - 2 <= this->n4a->parthead->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing parthead!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n4a->partlongfoot1->side[1] && this->ava->body[7] + 15 <= this->n4a->partlongfoot1->side[3] || this->ava->body[9] + 15 <= this->n4a->partlongfoot1->side[1] && this->ava->body[9] + 15 >= this->n4a->partlongfoot1->side[3])
				&& (this->ava->body[6] + 3 >= this->n4a->partlongfoot1->side[2] && this->ava->body[6] + 3 <= this->n4a->partlongfoot1->side[4] || this->ava->body[8] + 3 >= this->n4a->partlongfoot1->side[2] && this->ava->body[8] + 3 <= this->n4a->partlongfoot1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partlongfoot1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n4a->partlongfoot1->side[1] && this->ava->body[7] + 15 <= this->n4a->partlongfoot1->side[3] || this->ava->body[9] + 15 <= this->n4a->partlongfoot1->side[1] && this->ava->body[9] + 15 >= this->n4a->partlongfoot1->side[3])
				&& (this->ava->body[6] + 3 >= this->n4a->partlongfoot1->side[2] && this->ava->body[6] + 3 <= this->n4a->partlongfoot1->side[4] || this->ava->body[8] + 3 >= this->n4a->partlongfoot1->side[2] && this->ava->body[8] + 3 <= this->n4a->partlongfoot1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partlongfoot1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n4a->partlongfoot1->side[1] && this->ava->body[7] + 15 <= this->n4a->partlongfoot1->side[3] || this->ava->body[9] + 15 <= this->n4a->partlongfoot1->side[1] && this->ava->body[9] + 15 >= this->n4a->partlongfoot1->side[3])
				&& (this->ava->body[6] + 3 >= this->n4a->partlongfoot1->side[2] && this->ava->body[6] + 3 <= this->n4a->partlongfoot1->side[4] || this->ava->body[8] + 3 >= this->n4a->partlongfoot1->side[2] && this->ava->body[8] + 3 <= this->n4a->partlongfoot1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partlongfoot1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n4a->partlongfoot1->side[1] && this->ava->body[7] + 15 <= this->n4a->partlongfoot1->side[3] || this->ava->body[9] + 15 <= this->n4a->partlongfoot1->side[1] && this->ava->body[9] + 15 >= this->n4a->partlongfoot1->side[3])
				&& (this->ava->body[6] + 3 >= this->n4a->partlongfoot1->side[2] && this->ava->body[6] + 3 <= this->n4a->partlongfoot1->side[4] || this->ava->body[8] + 3 >= this->n4a->partlongfoot1->side[2] && this->ava->body[8] + 3 <= this->n4a->partlongfoot1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing partlongfoot1: side!"<<endl;
			}
		}
		void collisionOnInvader5(){
			if((this->ava->head[6]>= this->n5->body1->side[2] && this->ava->head[6]<= this->n5->body1->side[4] || this->ava->head[4]>= this->n5->body1->side[2] && this->ava->head[4]<= this->n5->body1->side[4])
				&& this->ava->head[3] - 15 >= this->n5->body1->side[1] && this->ava->head[3] - 15 <= this->n5->body1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at body1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5->body2->side[2] && this->ava->head[6]<= this->n5->body2->side[4] || this->ava->head[4]>= this->n5->body2->side[2] && this->ava->head[4]<= this->n5->body2->side[4])
				&& this->ava->head[3] - 15 >= this->n5->body2->side[1] && this->ava->head[3] - 15 <= this->n5->body2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at body2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5->body2->side[2] && this->ava->head[6]<= this->n5->body2->side[4] || this->ava->head[4]>= this->n5->body2->side[2] && this->ava->head[4]<= this->n5->body2->side[4])
				&& this->ava->head[3] - 15 >= this->n5->body2->side[1] && this->ava->head[3] - 15 <= this->n5->body2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at body2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5->body3->side[2] && this->ava->head[6]<= this->n5->body3->side[4] || this->ava->head[4]>= this->n5->body3->side[2] && this->ava->head[4]<= this->n5->body3->side[4])
				&& this->ava->head[3] - 15 >= this->n5->body3->side[1] && this->ava->head[3] - 15 <= this->n5->body3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at body3!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5->body4->side[2] && this->ava->head[6]<= this->n5->body4->side[4] || this->ava->head[4]>= this->n5->body4->side[2] && this->ava->head[4]<= this->n5->body4->side[4])
				&& this->ava->head[3] - 15 >= this->n5->body4->side[1] && this->ava->head[3] - 15 <= this->n5->body4->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at body4!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5->leg1->side[2] && this->ava->head[6]<= this->n5->leg1->side[4] || this->ava->head[4]>= this->n5->leg1->side[2] && this->ava->head[4]<= this->n5->leg1->side[4])
				&& this->ava->head[3] - 15 >= this->n5->leg1->side[1] && this->ava->head[3] - 15 <= this->n5->leg1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at leg1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5->leg2->side[2] && this->ava->head[6]<= this->n5->leg2->side[4] || this->ava->head[4]>= this->n5->leg2->side[2] && this->ava->head[4]<= this->n5->leg2->side[4])
				&& this->ava->head[3] - 15 >= this->n5->leg2->side[1] && this->ava->head[3] - 15 <= this->n5->leg2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at leg2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5->leg3->side[2] && this->ava->head[6]<= this->n5->leg3->side[4] || this->ava->head[4]>= this->n5->leg3->side[2] && this->ava->head[4]<= this->n5->leg3->side[4])
				&& this->ava->head[3] - 15 >= this->n5->leg3->side[1] && this->ava->head[3] - 15 <= this->n5->leg3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at leg3!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5->leg4->side[2] && this->ava->head[6]<= this->n5->leg4->side[4] || this->ava->head[4]>= this->n5->leg4->side[2] && this->ava->head[4]<= this->n5->leg4->side[4])
				&& this->ava->head[3] - 15 >= this->n5->leg4->side[1] && this->ava->head[3] - 15 <= this->n5->leg4->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at leg4!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5->foot1->side[2] && this->ava->head[6]<= this->n5->foot1->side[4] || this->ava->head[4]>= this->n5->foot1->side[2] && this->ava->head[4]<= this->n5->foot1->side[4])
				&& this->ava->head[3] - 15 >= this->n5->foot1->side[1] && this->ava->head[3] - 15 <= this->n5->foot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at foot1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5->foot2->side[2] && this->ava->head[6]<= this->n5->foot2->side[4] || this->ava->head[4]>= this->n5->foot2->side[2] && this->ava->head[4]<= this->n5->foot2->side[4])
				&& this->ava->head[3] - 15 >= this->n5->foot2->side[1] && this->ava->head[3] - 15 <= this->n5->foot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at foot2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5->horn1->side[2] && this->ava->head[6]<= this->n5->horn1->side[4] || this->ava->head[4]>= this->n5->horn1->side[2] && this->ava->head[4]<= this->n5->horn1->side[4])
				&& this->ava->head[3] - 15 >= this->n5->horn1->side[1] && this->ava->head[3] - 15 <= this->n5->horn1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at horn1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5->horn2->side[2] && this->ava->head[6]<= this->n5->horn2->side[4] || this->ava->head[4]>= this->n5->horn2->side[2] && this->ava->head[4]<= this->n5->horn2->side[4])
				&& this->ava->head[3] - 15 >= this->n5->horn2->side[1] && this->ava->head[3] - 15 <= this->n5->horn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at horn2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5->upperhorn1->side[2] && this->ava->head[6]<= this->n5->upperhorn1->side[4] || this->ava->head[4]>= this->n5->upperhorn1->side[2] && this->ava->head[4]<= this->n5->upperhorn1->side[4])
				&& this->ava->head[3] - 15 >= this->n5->upperhorn1->side[1] && this->ava->head[3] - 15 <= this->n5->upperhorn1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at upperhorn1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5->upperhorn2->side[2] && this->ava->head[6]<= this->n5->upperhorn2->side[4] || this->ava->head[4]>= this->n5->upperhorn2->side[2] && this->ava->head[4]<= this->n5->upperhorn2->side[4])
				&& this->ava->head[3] - 15 >= this->n5->upperhorn2->side[1] && this->ava->head[3] - 15 <= this->n5->upperhorn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at upperhorn2!"<<endl;
			}
			else if((this->ava->body[12] >= this->n5->upperhorn1->side[0] && this->ava->body[12] <= this->n5->upperhorn1->side[6] || this->ava->body[10] >= this->n5->upperhorn1->side[0] && this->ava->body[10] <= this->n5->upperhorn1->side[6])
				&& this->ava->body[11] + 2>= this->n5->upperhorn1->side[1] && this->ava->body[13] + 2 <= this->n5->upperhorn1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at upperhorn1 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n5->upperhorn2->side[0] && this->ava->body[12] <= this->n5->upperhorn2->side[6] || this->ava->body[10] >= this->n5->upperhorn2->side[0] && this->ava->body[10] <= this->n5->upperhorn2->side[6])
				&& this->ava->body[11] + 2>= this->n5->upperhorn2->side[1] && this->ava->body[13] + 2 <= this->n5->upperhorn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at upperhorn2 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n5->horn1->side[0] && this->ava->body[12] <= this->n5->horn1->side[6] || this->ava->body[10] >= this->n5->horn1->side[0] && this->ava->body[10] <= this->n5->horn1->side[6])
				&& this->ava->body[11] + 2>= this->n5->horn1->side[1] && this->ava->body[13] + 2 <= this->n5->horn1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at horn1 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n5->horn2->side[0] && this->ava->body[12] <= this->n5->horn2->side[6] || this->ava->body[10] >= this->n5->horn2->side[0] && this->ava->body[10] <= this->n5->horn2->side[6])
				&& this->ava->body[11] + 2>= this->n5->horn2->side[1] && this->ava->body[13] + 2 <= this->n5->horn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at horn2 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n5->body1->side[0] && this->ava->body[12] <= this->n5->body1->side[6] || this->ava->body[10] >= this->n5->body1->side[0] && this->ava->body[10] <= this->n5->body1->side[6])
				&& this->ava->body[11] + 2>= this->n5->body1->side[1] && this->ava->body[13] + 2 <= this->n5->body1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at body1 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n5->body2->side[0] && this->ava->body[12] <= this->n5->body2->side[6] || this->ava->body[10] >= this->n5->body2->side[0] && this->ava->body[10] <= this->n5->body2->side[6])
				&& this->ava->body[11] + 2>= this->n5->body2->side[1] && this->ava->body[13] + 2 <= this->n5->body2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at body2 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n5->body3->side[0] && this->ava->body[12] <= this->n5->body3->side[6] || this->ava->body[10] >= this->n5->body3->side[0] && this->ava->body[10] <= this->n5->body3->side[6])
				&& this->ava->body[11] + 2>= this->n5->body3->side[1] && this->ava->body[13] + 2 <= this->n5->body3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at body3 (butt)!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5->leg2->side[1] && this->ava->body[17] + 15 <= this->n5->leg2->side[3] || this->ava->body[15] + 15 <= this->n5->leg2->side[1] && this->ava->body[15] + 15 >= this->n5->leg2->side[3])
				&& (this->ava->body[16] - 3 >= this->n5->leg2->side[2] && this->ava->body[16] - 3 <= this->n5->leg2->side[4] || this->ava->body[14] - 3 >= this->n5->leg2->side[2] && this->ava->body[14] - 3 <= this->n5->leg2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing leg2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5->leg4->side[1] && this->ava->body[17] + 15 <= this->n5->leg4->side[3] || this->ava->body[15] + 15 <= this->n5->leg4->side[1] && this->ava->body[15] + 15 >= this->n5->leg4->side[3])
				&& (this->ava->body[16] - 3 >= this->n5->leg4->side[2] && this->ava->body[16] - 3 <= this->n5->leg4->side[4] || this->ava->body[14] - 3 >= this->n5->leg4->side[2] && this->ava->body[14] - 3 <= this->n5->leg4->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing leg4: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5->foot2->side[1] && this->ava->body[17] + 15 <= this->n5->foot2->side[3] || this->ava->body[15] + 15 <= this->n5->foot2->side[1] && this->ava->body[15] + 15 >= this->n5->foot2->side[3])
				&& (this->ava->body[16] - 3 >= this->n5->foot2->side[2] && this->ava->body[16] - 3 <= this->n5->foot2->side[4] || this->ava->body[14] - 3 >= this->n5->foot2->side[2] && this->ava->body[14] - 3 <= this->n5->foot2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing foot2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5->body1->side[1] && this->ava->body[17] + 15 <= this->n5->body1->side[3] || this->ava->body[15] + 15 <= this->n5->body1->side[1] && this->ava->body[15] + 15 >= this->n5->body1->side[3])
				&& (this->ava->body[16] - 3 >= this->n5->body1->side[2] && this->ava->body[16] - 3 <= this->n5->body1->side[4] || this->ava->body[14] - 3 >= this->n5->body1->side[2] && this->ava->body[14] - 3 <= this->n5->body1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing body1: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5->body2->side[1] && this->ava->body[17] + 15 <= this->n5->body2->side[3] || this->ava->body[15] + 15 <= this->n5->body2->side[1] && this->ava->body[15] + 15 >= this->n5->body2->side[3])
				&& (this->ava->body[16] - 3 >= this->n5->body2->side[2] && this->ava->body[16] - 3 <= this->n5->body2->side[4] || this->ava->body[14] - 3 >= this->n5->body2->side[2] && this->ava->body[14] - 3 <= this->n5->body2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing body2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5->body3->side[1] && this->ava->body[17] + 15 <= this->n5->body3->side[3] || this->ava->body[15] + 15 <= this->n5->body3->side[1] && this->ava->body[15] + 15 >= this->n5->body3->side[3])
				&& (this->ava->body[16] - 3 >= this->n5->body3->side[2] && this->ava->body[16] - 3 <= this->n5->body3->side[4] || this->ava->body[14] - 3 >= this->n5->body3->side[2] && this->ava->body[14] - 3 <= this->n5->body3->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing body3: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5->horn1->side[1] && this->ava->body[17] + 15 <= this->n5->horn1->side[3] || this->ava->body[15] + 15 <= this->n5->horn1->side[1] && this->ava->body[15] + 15 >= this->n5->horn1->side[3])
				&& (this->ava->body[16] - 3 >= this->n5->horn1->side[2] && this->ava->body[16] - 3 <= this->n5->horn1->side[4] || this->ava->body[14] - 3 >= this->n5->horn1->side[2] && this->ava->body[14] - 3 <= this->n5->horn1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing horn1: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5->horn2->side[1] && this->ava->body[17] + 15 <= this->n5->horn2->side[3] || this->ava->body[15] + 15 <= this->n5->horn2->side[1] && this->ava->body[15] + 15 >= this->n5->horn2->side[3])
				&& (this->ava->body[16] - 3 >= this->n5->horn2->side[2] && this->ava->body[16] - 3 <= this->n5->horn2->side[4] || this->ava->body[14] - 3 >= this->n5->horn2->side[2] && this->ava->body[14] - 3 <= this->n5->horn2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing horn2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5->upperhorn1->side[1] && this->ava->body[17] + 15 <= this->n5->upperhorn1->side[3] || this->ava->body[15] + 15 <= this->n5->upperhorn1->side[1] && this->ava->body[15] + 15 >= this->n5->upperhorn1->side[3])
				&& (this->ava->body[16] - 3 >= this->n5->upperhorn1->side[2] && this->ava->body[16] - 3 <= this->n5->upperhorn1->side[4] || this->ava->body[14] - 3 >= this->n5->upperhorn1->side[2] && this->ava->body[14] - 3 <= this->n5->upperhorn1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing upperhorn1: side!"<<endl;
			}
			else if((this->ava->body[16] >= this->n5->foot2->side[2] && this->ava->body[16] <= this->n5->foot2->side[4] || this->ava->body[18] >= this->n5->foot2->side[2] && this->ava->body[18] <= this->n5->foot2->side[4])
				&& this->ava->body[17] - 2 >= this->n5->foot2->side[1] && this->ava->body[17] - 2 <= this->n5->foot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing foot2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n5->leg4->side[2] && this->ava->body[16] <= this->n5->leg4->side[4] || this->ava->body[18] >= this->n5->leg4->side[2] && this->ava->body[18] <= this->n5->leg4->side[4])
				&& this->ava->body[17] - 2 >= this->n5->leg4->side[1] && this->ava->body[17] - 2 <= this->n5->leg4->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing leg4!"<<endl;
			}
			else if((this->ava->body[16] >= this->n5->leg2->side[2] && this->ava->body[16] <= this->n5->leg2->side[4] || this->ava->body[18] >= this->n5->leg2->side[2] && this->ava->body[18] <= this->n5->leg2->side[4])
				&& this->ava->body[17] - 2 >= this->n5->leg2->side[1] && this->ava->body[17] - 2 <= this->n5->leg2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing leg2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n5->body1->side[2] && this->ava->body[16] <= this->n5->body1->side[4] || this->ava->body[18] >= this->n5->body1->side[2] && this->ava->body[18] <= this->n5->body1->side[4])
				&& this->ava->body[17] - 2 >= this->n5->body1->side[1] && this->ava->body[17] - 2 <= this->n5->body1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing body1!"<<endl;
			}
			else if((this->ava->body[16] >= this->n5->body2->side[2] && this->ava->body[16] <= this->n5->body2->side[4] || this->ava->body[18] >= this->n5->body2->side[2] && this->ava->body[18] <= this->n5->body2->side[4])
				&& this->ava->body[17] - 2 >= this->n5->body2->side[1] && this->ava->body[17] - 2 <= this->n5->body2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing body2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n5->body3->side[2] && this->ava->body[16] <= this->n5->body3->side[4] || this->ava->body[18] >= this->n5->body3->side[2] && this->ava->body[18] <= this->n5->body3->side[4])
				&& this->ava->body[17] - 2 >= this->n5->body3->side[1] && this->ava->body[17] - 2 <= this->n5->body3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing body3!"<<endl;
			}
			else if((this->ava->body[16] >= this->n5->horn2->side[2] && this->ava->body[16] <= this->n5->horn2->side[4] || this->ava->body[18] >= this->n5->horn2->side[2] && this->ava->body[18] <= this->n5->horn2->side[4])
				&& this->ava->body[17] - 2 >= this->n5->horn2->side[1] && this->ava->body[17] - 2 <= this->n5->horn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing horn2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n5->upperhorn2->side[2] && this->ava->body[16] <= this->n5->upperhorn2->side[4] || this->ava->body[18] >= this->n5->upperhorn2->side[2] && this->ava->body[18] <= this->n5->upperhorn2->side[4])
				&& this->ava->body[17] - 2 >= this->n5->upperhorn2->side[1] && this->ava->body[17] - 2 <= this->n5->upperhorn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing upperhorn2!"<<endl;
			}
			else if((this->ava->body[4] >= this->n5->foot1->side[2] && this->ava->body[4] <= this->n5->foot1->side[4] || this->ava->body[6] >= this->n5->foot1->side[2] && this->ava->body[6] <= this->n5->foot1->side[4])
				&& (this->ava->body[7] - 2 >= this->n5->foot1->side[1] && this->ava->body[7] - 2 <= this->n5->foot1->side[3] || this->ava->body[9] - 2 >= this->n5->foot1->side[1] && this->ava->body[9] - 2 <= this->n5->foot1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing foot1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n5->leg1->side[2] && this->ava->body[4] <= this->n5->leg1->side[4] || this->ava->body[6] >= this->n5->leg1->side[2] && this->ava->body[6] <= this->n5->leg1->side[4])
				&& (this->ava->body[7] - 2 >= this->n5->leg1->side[1] && this->ava->body[7] - 2 <= this->n5->leg1->side[3] || this->ava->body[9] - 2 >= this->n5->leg1->side[1] && this->ava->body[9] - 2 <= this->n5->leg1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing leg1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n5->leg3->side[2] && this->ava->body[4] <= this->n5->leg3->side[4] || this->ava->body[6] >= this->n5->leg3->side[2] && this->ava->body[6] <= this->n5->leg3->side[4])
				&& (this->ava->body[7] - 2 >= this->n5->leg3->side[1] && this->ava->body[7] - 2 <= this->n5->leg3->side[3] || this->ava->body[9] - 2 >= this->n5->leg3->side[1] && this->ava->body[9] - 2 <= this->n5->leg3->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing leg3!"<<endl;
			}
			else if((this->ava->body[4] >= this->n5->body1->side[2] && this->ava->body[4] <= this->n5->body1->side[4] || this->ava->body[6] >= this->n5->body1->side[2] && this->ava->body[6] <= this->n5->body1->side[4])
				&& (this->ava->body[7] - 2 >= this->n5->body1->side[1] && this->ava->body[7] - 2 <= this->n5->body1->side[3] || this->ava->body[9] - 2 >= this->n5->body1->side[1] && this->ava->body[9] - 2 <= this->n5->body1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing body1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n5->body2->side[2] && this->ava->body[4] <= this->n5->body2->side[4] || this->ava->body[6] >= this->n5->body2->side[2] && this->ava->body[6] <= this->n5->body2->side[4])
				&& (this->ava->body[7] - 2 >= this->n5->body2->side[1] && this->ava->body[7] - 2 <= this->n5->body2->side[3] || this->ava->body[9] - 2 >= this->n5->body2->side[1] && this->ava->body[9] - 2 <= this->n5->body2->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing body2!"<<endl;
			}
			else if((this->ava->body[4] >= this->n5->body3->side[2] && this->ava->body[4] <= this->n5->body3->side[4] || this->ava->body[6] >= this->n5->body3->side[2] && this->ava->body[6] <= this->n5->body3->side[4])
				&& (this->ava->body[7] - 2 >= this->n5->body3->side[1] && this->ava->body[7] - 2 <= this->n5->body3->side[3] || this->ava->body[9] - 2 >= this->n5->body3->side[1] && this->ava->body[9] - 2 <= this->n5->body3->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing body3!"<<endl;
			}
			else if((this->ava->body[4] >= this->n5->horn1->side[2] && this->ava->body[4] <= this->n5->horn1->side[4] || this->ava->body[6] >= this->n5->horn1->side[2] && this->ava->body[6] <= this->n5->horn1->side[4])
				&& (this->ava->body[7] - 2 >= this->n5->horn1->side[1] && this->ava->body[7] - 2 <= this->n5->horn1->side[3] || this->ava->body[9] - 2 >= this->n5->horn1->side[1] && this->ava->body[9] - 2 <= this->n5->horn1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing horn1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n5->upperhorn1->side[2] && this->ava->body[4] <= this->n5->upperhorn1->side[4] || this->ava->body[6] >= this->n5->upperhorn1->side[2] && this->ava->body[6] <= this->n5->upperhorn1->side[4])
				&& (this->ava->body[7] - 2 >= this->n5->upperhorn1->side[1] && this->ava->body[7] - 2 <= this->n5->upperhorn1->side[3] || this->ava->body[9] - 2 >= this->n5->upperhorn1->side[1] && this->ava->body[9] - 2 <= this->n5->upperhorn1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing upperhorn1!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5->horn1->side[1] && this->ava->body[7] + 15 <= this->n5->horn1->side[3] || this->ava->body[9] + 15 <= this->n5->horn1->side[1] && this->ava->body[9] + 15 >= this->n5->horn1->side[3])
				&& (this->ava->body[6] + 3 >= this->n5->horn1->side[2] && this->ava->body[6] + 3 <= this->n5->horn1->side[4] || this->ava->body[8] + 3 >= this->n5->horn1->side[2] && this->ava->body[8] + 3 <= this->n5->horn1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing horn1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5->upperhorn1->side[1] && this->ava->body[7] + 15 <= this->n5->upperhorn1->side[3] || this->ava->body[9] + 15 <= this->n5->upperhorn1->side[1] && this->ava->body[9] + 15 >= this->n5->upperhorn1->side[3])
				&& (this->ava->body[6] + 3 >= this->n5->upperhorn1->side[2] && this->ava->body[6] + 3 <= this->n5->upperhorn1->side[4] || this->ava->body[8] + 3 >= this->n5->upperhorn1->side[2] && this->ava->body[8] + 3 <= this->n5->upperhorn1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing upperhorn1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5->upperhorn2->side[1] && this->ava->body[7] + 15 <= this->n5->upperhorn2->side[3] || this->ava->body[9] + 15 <= this->n5->upperhorn2->side[1] && this->ava->body[9] + 15 >= this->n5->upperhorn2->side[3])
				&& (this->ava->body[6] + 3 >= this->n5->upperhorn2->side[2] && this->ava->body[6] + 3 <= this->n5->upperhorn2->side[4] || this->ava->body[8] + 3 >= this->n5->upperhorn2->side[2] && this->ava->body[8] + 3 <= this->n5->upperhorn2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing upperhorn2: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5->horn2->side[1] && this->ava->body[7] + 15 <= this->n5->horn2->side[3] || this->ava->body[9] + 15 <= this->n5->horn2->side[1] && this->ava->body[9] + 15 >= this->n5->horn2->side[3])
				&& (this->ava->body[6] + 3 >= this->n5->horn2->side[2] && this->ava->body[6] + 3 <= this->n5->horn2->side[4] || this->ava->body[8] + 3 >= this->n5->horn2->side[2] && this->ava->body[8] + 3 <= this->n5->horn2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing horn2: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5->body1->side[1] && this->ava->body[7] + 15 <= this->n5->body1->side[3] || this->ava->body[9] + 15 <= this->n5->body1->side[1] && this->ava->body[9] + 15 >= this->n5->body1->side[3])
				&& (this->ava->body[6] + 3 >= this->n5->body1->side[2] && this->ava->body[6] + 3 <= this->n5->body1->side[4] || this->ava->body[8] + 3 >= this->n5->body1->side[2] && this->ava->body[8] + 3 <= this->n5->body1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing body1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5->body2->side[1] && this->ava->body[7] + 15 <= this->n5->body2->side[3] || this->ava->body[9] + 15 <= this->n5->body2->side[1] && this->ava->body[9] + 15 >= this->n5->body2->side[3])
				&& (this->ava->body[6] + 3 >= this->n5->body2->side[2] && this->ava->body[6] + 3 <= this->n5->body2->side[4] || this->ava->body[8] + 3 >= this->n5->body2->side[2] && this->ava->body[8] + 3 <= this->n5->body2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing body2: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5->body3->side[1] && this->ava->body[7] + 15 <= this->n5->body3->side[3] || this->ava->body[9] + 15 <= this->n5->body3->side[1] && this->ava->body[9] + 15 >= this->n5->body3->side[3])
				&& (this->ava->body[6] + 3 >= this->n5->body3->side[2] && this->ava->body[6] + 3 <= this->n5->body3->side[4] || this->ava->body[8] + 3 >= this->n5->body3->side[2] && this->ava->body[8] + 3 <= this->n5->body3->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing body3: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5->leg1->side[1] && this->ava->body[7] + 15 <= this->n5->leg1->side[3] || this->ava->body[9] + 15 <= this->n5->leg1->side[1] && this->ava->body[9] + 15 >= this->n5->leg1->side[3])
				&& (this->ava->body[6] + 3 >= this->n5->leg1->side[2] && this->ava->body[6] + 3 <= this->n5->leg1->side[4] || this->ava->body[8] + 3 >= this->n5->leg1->side[2] && this->ava->body[8] + 3 <= this->n5->leg1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing leg1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5->leg3->side[1] && this->ava->body[7] + 15 <= this->n5->leg3->side[3] || this->ava->body[9] + 15 <= this->n5->leg3->side[1] && this->ava->body[9] + 15 >= this->n5->leg3->side[3])
				&& (this->ava->body[6] + 3 >= this->n5->leg3->side[2] && this->ava->body[6] + 3 <= this->n5->leg3->side[4] || this->ava->body[8] + 3 >= this->n5->leg3->side[2] && this->ava->body[8] + 3 <= this->n5->leg3->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing leg3: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5->leg2->side[1] && this->ava->body[7] + 15 <= this->n5->leg2->side[3] || this->ava->body[9] + 15 <= this->n5->leg2->side[1] && this->ava->body[9] + 15 >= this->n5->leg2->side[3])
				&& (this->ava->body[6] + 3 >= this->n5->leg2->side[2] && this->ava->body[6] + 3 <= this->n5->leg2->side[4] || this->ava->body[8] + 3 >= this->n5->leg2->side[2] && this->ava->body[8] + 3 <= this->n5->leg2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing leg2: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5->leg4->side[1] && this->ava->body[7] + 15 <= this->n5->leg4->side[3] || this->ava->body[9] + 15 <= this->n5->leg4->side[1] && this->ava->body[9] + 15 >= this->n5->leg4->side[3])
				&& (this->ava->body[6] + 3 >= this->n5->leg4->side[2] && this->ava->body[6] + 3 <= this->n5->leg4->side[4] || this->ava->body[8] + 3 >= this->n5->leg4->side[2] && this->ava->body[8] + 3 <= this->n5->leg4->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing leg4: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5->foot1->side[1] && this->ava->body[7] + 15 <= this->n5->foot1->side[3] || this->ava->body[9] + 15 <= this->n5->foot1->side[1] && this->ava->body[9] + 15 >= this->n5->foot1->side[3])
				&& (this->ava->body[6] + 3 >= this->n5->foot1->side[2] && this->ava->body[6] + 3 <= this->n5->foot1->side[4] || this->ava->body[8] + 3 >= this->n5->foot1->side[2] && this->ava->body[8] + 3 <= this->n5->foot1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing foot1: side!"<<endl;
			}
		}
		void collisionOnInvader5a(){
			if((this->ava->head[6]>= this->n5a->body1->side[2] && this->ava->head[6]<= this->n5a->body1->side[4] || this->ava->head[4]>= this->n5a->body1->side[2] && this->ava->head[4]<= this->n5a->body1->side[4])
				&& this->ava->head[3] - 15 >= this->n5a->body1->side[1] && this->ava->head[3] - 15 <= this->n5a->body1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at body1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5a->body2->side[2] && this->ava->head[6]<= this->n5a->body2->side[4] || this->ava->head[4]>= this->n5a->body2->side[2] && this->ava->head[4]<= this->n5a->body2->side[4])
				&& this->ava->head[3] - 15 >= this->n5a->body2->side[1] && this->ava->head[3] - 15 <= this->n5a->body2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at body2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5a->body2->side[2] && this->ava->head[6]<= this->n5a->body2->side[4] || this->ava->head[4]>= this->n5a->body2->side[2] && this->ava->head[4]<= this->n5a->body2->side[4])
				&& this->ava->head[3] - 15 >= this->n5a->body2->side[1] && this->ava->head[3] - 15 <= this->n5a->body2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at body2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5a->body3->side[2] && this->ava->head[6]<= this->n5a->body3->side[4] || this->ava->head[4]>= this->n5a->body3->side[2] && this->ava->head[4]<= this->n5a->body3->side[4])
				&& this->ava->head[3] - 15 >= this->n5a->body3->side[1] && this->ava->head[3] - 15 <= this->n5a->body3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at body3!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5a->body4->side[2] && this->ava->head[6]<= this->n5a->body4->side[4] || this->ava->head[4]>= this->n5a->body4->side[2] && this->ava->head[4]<= this->n5a->body4->side[4])
				&& this->ava->head[3] - 15 >= this->n5a->body4->side[1] && this->ava->head[3] - 15 <= this->n5a->body4->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at body4!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5a->leg1->side[2] && this->ava->head[6]<= this->n5a->leg1->side[4] || this->ava->head[4]>= this->n5a->leg1->side[2] && this->ava->head[4]<= this->n5a->leg1->side[4])
				&& this->ava->head[3] - 15 >= this->n5a->leg1->side[1] && this->ava->head[3] - 15 <= this->n5a->leg1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at leg1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5a->leg2->side[2] && this->ava->head[6]<= this->n5a->leg2->side[4] || this->ava->head[4]>= this->n5a->leg2->side[2] && this->ava->head[4]<= this->n5a->leg2->side[4])
				&& this->ava->head[3] - 15 >= this->n5a->leg2->side[1] && this->ava->head[3] - 15 <= this->n5a->leg2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at leg2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5a->leg3->side[2] && this->ava->head[6]<= this->n5a->leg3->side[4] || this->ava->head[4]>= this->n5a->leg3->side[2] && this->ava->head[4]<= this->n5a->leg3->side[4])
				&& this->ava->head[3] - 15 >= this->n5a->leg3->side[1] && this->ava->head[3] - 15 <= this->n5a->leg3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at leg3!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5a->leg4->side[2] && this->ava->head[6]<= this->n5a->leg4->side[4] || this->ava->head[4]>= this->n5a->leg4->side[2] && this->ava->head[4]<= this->n5a->leg4->side[4])
				&& this->ava->head[3] - 15 >= this->n5a->leg4->side[1] && this->ava->head[3] - 15 <= this->n5a->leg4->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at leg4!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5a->foot1->side[2] && this->ava->head[6]<= this->n5a->foot1->side[4] || this->ava->head[4]>= this->n5a->foot1->side[2] && this->ava->head[4]<= this->n5a->foot1->side[4])
				&& this->ava->head[3] - 15 >= this->n5a->foot1->side[1] && this->ava->head[3] - 15 <= this->n5a->foot1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at foot1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5a->foot2->side[2] && this->ava->head[6]<= this->n5a->foot2->side[4] || this->ava->head[4]>= this->n5a->foot2->side[2] && this->ava->head[4]<= this->n5a->foot2->side[4])
				&& this->ava->head[3] - 15 >= this->n5a->foot2->side[1] && this->ava->head[3] - 15 <= this->n5a->foot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at foot2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5a->horn1->side[2] && this->ava->head[6]<= this->n5a->horn1->side[4] || this->ava->head[4]>= this->n5a->horn1->side[2] && this->ava->head[4]<= this->n5a->horn1->side[4])
				&& this->ava->head[3] - 15 >= this->n5a->horn1->side[1] && this->ava->head[3] - 15 <= this->n5a->horn1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at horn1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5a->horn2->side[2] && this->ava->head[6]<= this->n5a->horn2->side[4] || this->ava->head[4]>= this->n5a->horn2->side[2] && this->ava->head[4]<= this->n5a->horn2->side[4])
				&& this->ava->head[3] - 15 >= this->n5a->horn2->side[1] && this->ava->head[3] - 15 <= this->n5a->horn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at horn2!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5a->upperhorn1->side[2] && this->ava->head[6]<= this->n5a->upperhorn1->side[4] || this->ava->head[4]>= this->n5a->upperhorn1->side[2] && this->ava->head[4]<= this->n5a->upperhorn1->side[4])
				&& this->ava->head[3] - 15 >= this->n5a->upperhorn1->side[1] && this->ava->head[3] - 15 <= this->n5a->upperhorn1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at upperhorn1!"<<endl;
			}
			else if((this->ava->head[6]>= this->n5a->upperhorn2->side[2] && this->ava->head[6]<= this->n5a->upperhorn2->side[4] || this->ava->head[4]>= this->n5a->upperhorn2->side[2] && this->ava->head[4]<= this->n5a->upperhorn2->side[4])
				&& this->ava->head[3] - 15 >= this->n5a->upperhorn2->side[1] && this->ava->head[3] - 15 <= this->n5a->upperhorn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at upperhorn2!"<<endl;
			}
			else if((this->ava->body[12] >= this->n5a->upperhorn1->side[0] && this->ava->body[12] <= this->n5a->upperhorn1->side[6] || this->ava->body[10] >= this->n5a->upperhorn1->side[0] && this->ava->body[10] <= this->n5a->upperhorn1->side[6])
				&& this->ava->body[11] + 2>= this->n5a->upperhorn1->side[1] && this->ava->body[13] + 2 <= this->n5a->upperhorn1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at upperhorn1 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n5a->upperhorn2->side[0] && this->ava->body[12] <= this->n5a->upperhorn2->side[6] || this->ava->body[10] >= this->n5a->upperhorn2->side[0] && this->ava->body[10] <= this->n5a->upperhorn2->side[6])
				&& this->ava->body[11] + 2>= this->n5a->upperhorn2->side[1] && this->ava->body[13] + 2 <= this->n5a->upperhorn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at upperhorn2 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n5a->horn1->side[0] && this->ava->body[12] <= this->n5a->horn1->side[6] || this->ava->body[10] >= this->n5a->horn1->side[0] && this->ava->body[10] <= this->n5a->horn1->side[6])
				&& this->ava->body[11] + 2>= this->n5a->horn1->side[1] && this->ava->body[13] + 2 <= this->n5a->horn1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at horn1 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n5a->horn2->side[0] && this->ava->body[12] <= this->n5a->horn2->side[6] || this->ava->body[10] >= this->n5a->horn2->side[0] && this->ava->body[10] <= this->n5a->horn2->side[6])
				&& this->ava->body[11] + 2>= this->n5a->horn2->side[1] && this->ava->body[13] + 2 <= this->n5a->horn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at horn2 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n5a->body1->side[0] && this->ava->body[12] <= this->n5a->body1->side[6] || this->ava->body[10] >= this->n5a->body1->side[0] && this->ava->body[10] <= this->n5a->body1->side[6])
				&& this->ava->body[11] + 2>= this->n5a->body1->side[1] && this->ava->body[13] + 2 <= this->n5a->body1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at body1 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n5a->body2->side[0] && this->ava->body[12] <= this->n5a->body2->side[6] || this->ava->body[10] >= this->n5a->body2->side[0] && this->ava->body[10] <= this->n5a->body2->side[6])
				&& this->ava->body[11] + 2>= this->n5a->body2->side[1] && this->ava->body[13] + 2 <= this->n5a->body2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at body2 (butt)!"<<endl;
			}
			else if((this->ava->body[12] >= this->n5a->body3->side[0] && this->ava->body[12] <= this->n5a->body3->side[6] || this->ava->body[10] >= this->n5a->body3->side[0] && this->ava->body[10] <= this->n5a->body3->side[6])
				&& this->ava->body[11] + 2>= this->n5a->body3->side[1] && this->ava->body[13] + 2 <= this->n5a->body3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at body3 (butt)!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5a->leg2->side[1] && this->ava->body[17] + 15 <= this->n5a->leg2->side[3] || this->ava->body[15] + 15 <= this->n5a->leg2->side[1] && this->ava->body[15] + 15 >= this->n5a->leg2->side[3])
				&& (this->ava->body[16] - 3 >= this->n5a->leg2->side[2] && this->ava->body[16] - 3 <= this->n5a->leg2->side[4] || this->ava->body[14] - 3 >= this->n5a->leg2->side[2] && this->ava->body[14] - 3 <= this->n5a->leg2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing leg2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5a->leg4->side[1] && this->ava->body[17] + 15 <= this->n5a->leg4->side[3] || this->ava->body[15] + 15 <= this->n5a->leg4->side[1] && this->ava->body[15] + 15 >= this->n5a->leg4->side[3])
				&& (this->ava->body[16] - 3 >= this->n5a->leg4->side[2] && this->ava->body[16] - 3 <= this->n5a->leg4->side[4] || this->ava->body[14] - 3 >= this->n5a->leg4->side[2] && this->ava->body[14] - 3 <= this->n5a->leg4->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing leg4: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5a->foot2->side[1] && this->ava->body[17] + 15 <= this->n5a->foot2->side[3] || this->ava->body[15] + 15 <= this->n5a->foot2->side[1] && this->ava->body[15] + 15 >= this->n5a->foot2->side[3])
				&& (this->ava->body[16] - 3 >= this->n5a->foot2->side[2] && this->ava->body[16] - 3 <= this->n5a->foot2->side[4] || this->ava->body[14] - 3 >= this->n5a->foot2->side[2] && this->ava->body[14] - 3 <= this->n5a->foot2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing foot2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5a->body1->side[1] && this->ava->body[17] + 15 <= this->n5a->body1->side[3] || this->ava->body[15] + 15 <= this->n5a->body1->side[1] && this->ava->body[15] + 15 >= this->n5a->body1->side[3])
				&& (this->ava->body[16] - 3 >= this->n5a->body1->side[2] && this->ava->body[16] - 3 <= this->n5a->body1->side[4] || this->ava->body[14] - 3 >= this->n5a->body1->side[2] && this->ava->body[14] - 3 <= this->n5a->body1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing body1: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5a->body2->side[1] && this->ava->body[17] + 15 <= this->n5a->body2->side[3] || this->ava->body[15] + 15 <= this->n5a->body2->side[1] && this->ava->body[15] + 15 >= this->n5a->body2->side[3])
				&& (this->ava->body[16] - 3 >= this->n5a->body2->side[2] && this->ava->body[16] - 3 <= this->n5a->body2->side[4] || this->ava->body[14] - 3 >= this->n5a->body2->side[2] && this->ava->body[14] - 3 <= this->n5a->body2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing body2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5a->body3->side[1] && this->ava->body[17] + 15 <= this->n5a->body3->side[3] || this->ava->body[15] + 15 <= this->n5a->body3->side[1] && this->ava->body[15] + 15 >= this->n5a->body3->side[3])
				&& (this->ava->body[16] - 3 >= this->n5a->body3->side[2] && this->ava->body[16] - 3 <= this->n5a->body3->side[4] || this->ava->body[14] - 3 >= this->n5a->body3->side[2] && this->ava->body[14] - 3 <= this->n5a->body3->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing body3: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5a->horn1->side[1] && this->ava->body[17] + 15 <= this->n5a->horn1->side[3] || this->ava->body[15] + 15 <= this->n5a->horn1->side[1] && this->ava->body[15] + 15 >= this->n5a->horn1->side[3])
				&& (this->ava->body[16] - 3 >= this->n5a->horn1->side[2] && this->ava->body[16] - 3 <= this->n5a->horn1->side[4] || this->ava->body[14] - 3 >= this->n5a->horn1->side[2] && this->ava->body[14] - 3 <= this->n5a->horn1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing horn1: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5a->horn2->side[1] && this->ava->body[17] + 15 <= this->n5a->horn2->side[3] || this->ava->body[15] + 15 <= this->n5a->horn2->side[1] && this->ava->body[15] + 15 >= this->n5a->horn2->side[3])
				&& (this->ava->body[16] - 3 >= this->n5a->horn2->side[2] && this->ava->body[16] - 3 <= this->n5a->horn2->side[4] || this->ava->body[14] - 3 >= this->n5a->horn2->side[2] && this->ava->body[14] - 3 <= this->n5a->horn2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing horn2: side!"<<endl;
			}
			else if((this->ava->body[17] + 15 >= this->n5a->upperhorn1->side[1] && this->ava->body[17] + 15 <= this->n5a->upperhorn1->side[3] || this->ava->body[15] + 15 <= this->n5a->upperhorn1->side[1] && this->ava->body[15] + 15 >= this->n5a->upperhorn1->side[3])
				&& (this->ava->body[16] - 3 >= this->n5a->upperhorn1->side[2] && this->ava->body[16] - 3 <= this->n5a->upperhorn1->side[4] || this->ava->body[14] - 3 >= this->n5a->upperhorn1->side[2] && this->ava->body[14] - 3 <= this->n5a->upperhorn1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing upperhorn1: side!"<<endl;
			}
			else if((this->ava->body[16] >= this->n5a->foot2->side[2] && this->ava->body[16] <= this->n5a->foot2->side[4] || this->ava->body[18] >= this->n5a->foot2->side[2] && this->ava->body[18] <= this->n5a->foot2->side[4])
				&& this->ava->body[17] - 2 >= this->n5a->foot2->side[1] && this->ava->body[17] - 2 <= this->n5a->foot2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing foot2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n5a->leg4->side[2] && this->ava->body[16] <= this->n5a->leg4->side[4] || this->ava->body[18] >= this->n5a->leg4->side[2] && this->ava->body[18] <= this->n5a->leg4->side[4])
				&& this->ava->body[17] - 2 >= this->n5a->leg4->side[1] && this->ava->body[17] - 2 <= this->n5a->leg4->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing leg4!"<<endl;
			}
			else if((this->ava->body[16] >= this->n5a->leg2->side[2] && this->ava->body[16] <= this->n5a->leg2->side[4] || this->ava->body[18] >= this->n5a->leg2->side[2] && this->ava->body[18] <= this->n5a->leg2->side[4])
				&& this->ava->body[17] - 2 >= this->n5a->leg2->side[1] && this->ava->body[17] - 2 <= this->n5a->leg2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing leg2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n5a->body1->side[2] && this->ava->body[16] <= this->n5a->body1->side[4] || this->ava->body[18] >= this->n5a->body1->side[2] && this->ava->body[18] <= this->n5a->body1->side[4])
				&& this->ava->body[17] - 2 >= this->n5a->body1->side[1] && this->ava->body[17] - 2 <= this->n5a->body1->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing body1!"<<endl;
			}
			else if((this->ava->body[16] >= this->n5a->body2->side[2] && this->ava->body[16] <= this->n5a->body2->side[4] || this->ava->body[18] >= this->n5a->body2->side[2] && this->ava->body[18] <= this->n5a->body2->side[4])
				&& this->ava->body[17] - 2 >= this->n5a->body2->side[1] && this->ava->body[17] - 2 <= this->n5a->body2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing body2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n5a->body3->side[2] && this->ava->body[16] <= this->n5a->body3->side[4] || this->ava->body[18] >= this->n5a->body3->side[2] && this->ava->body[18] <= this->n5a->body3->side[4])
				&& this->ava->body[17] - 2 >= this->n5a->body3->side[1] && this->ava->body[17] - 2 <= this->n5a->body3->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing body3!"<<endl;
			}
			else if((this->ava->body[16] >= this->n5a->horn2->side[2] && this->ava->body[16] <= this->n5a->horn2->side[4] || this->ava->body[18] >= this->n5a->horn2->side[2] && this->ava->body[18] <= this->n5a->horn2->side[4])
				&& this->ava->body[17] - 2 >= this->n5a->horn2->side[1] && this->ava->body[17] - 2 <= this->n5a->horn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing horn2!"<<endl;
			}
			else if((this->ava->body[16] >= this->n5a->upperhorn2->side[2] && this->ava->body[16] <= this->n5a->upperhorn2->side[4] || this->ava->body[18] >= this->n5a->upperhorn2->side[2] && this->ava->body[18] <= this->n5a->upperhorn2->side[4])
				&& this->ava->body[17] - 2 >= this->n5a->upperhorn2->side[1] && this->ava->body[17] - 2 <= this->n5a->upperhorn2->side[3]){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at left wing upperhorn2!"<<endl;
			}
			else if((this->ava->body[4] >= this->n5a->foot1->side[2] && this->ava->body[4] <= this->n5a->foot1->side[4] || this->ava->body[6] >= this->n5a->foot1->side[2] && this->ava->body[6] <= this->n5a->foot1->side[4])
				&& (this->ava->body[7] - 2 >= this->n5a->foot1->side[1] && this->ava->body[7] - 2 <= this->n5a->foot1->side[3] || this->ava->body[9] - 2 >= this->n5a->foot1->side[1] && this->ava->body[9] - 2 <= this->n5a->foot1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing foot1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n5a->leg1->side[2] && this->ava->body[4] <= this->n5a->leg1->side[4] || this->ava->body[6] >= this->n5a->leg1->side[2] && this->ava->body[6] <= this->n5a->leg1->side[4])
				&& (this->ava->body[7] - 2 >= this->n5a->leg1->side[1] && this->ava->body[7] - 2 <= this->n5a->leg1->side[3] || this->ava->body[9] - 2 >= this->n5a->leg1->side[1] && this->ava->body[9] - 2 <= this->n5a->leg1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing leg1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n5a->leg3->side[2] && this->ava->body[4] <= this->n5a->leg3->side[4] || this->ava->body[6] >= this->n5a->leg3->side[2] && this->ava->body[6] <= this->n5a->leg3->side[4])
				&& (this->ava->body[7] - 2 >= this->n5a->leg3->side[1] && this->ava->body[7] - 2 <= this->n5a->leg3->side[3] || this->ava->body[9] - 2 >= this->n5a->leg3->side[1] && this->ava->body[9] - 2 <= this->n5a->leg3->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing leg3!"<<endl;
			}
			else if((this->ava->body[4] >= this->n5a->body1->side[2] && this->ava->body[4] <= this->n5a->body1->side[4] || this->ava->body[6] >= this->n5a->body1->side[2] && this->ava->body[6] <= this->n5a->body1->side[4])
				&& (this->ava->body[7] - 2 >= this->n5a->body1->side[1] && this->ava->body[7] - 2 <= this->n5a->body1->side[3] || this->ava->body[9] - 2 >= this->n5a->body1->side[1] && this->ava->body[9] - 2 <= this->n5a->body1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing body1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n5a->body2->side[2] && this->ava->body[4] <= this->n5a->body2->side[4] || this->ava->body[6] >= this->n5a->body2->side[2] && this->ava->body[6] <= this->n5a->body2->side[4])
				&& (this->ava->body[7] - 2 >= this->n5a->body2->side[1] && this->ava->body[7] - 2 <= this->n5a->body2->side[3] || this->ava->body[9] - 2 >= this->n5a->body2->side[1] && this->ava->body[9] - 2 <= this->n5a->body2->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing body2!"<<endl;
			}
			else if((this->ava->body[4] >= this->n5a->body3->side[2] && this->ava->body[4] <= this->n5a->body3->side[4] || this->ava->body[6] >= this->n5a->body3->side[2] && this->ava->body[6] <= this->n5a->body3->side[4])
				&& (this->ava->body[7] - 2 >= this->n5a->body3->side[1] && this->ava->body[7] - 2 <= this->n5a->body3->side[3] || this->ava->body[9] - 2 >= this->n5a->body3->side[1] && this->ava->body[9] - 2 <= this->n5a->body3->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing body3!"<<endl;
			}
			else if((this->ava->body[4] >= this->n5a->horn1->side[2] && this->ava->body[4] <= this->n5a->horn1->side[4] || this->ava->body[6] >= this->n5a->horn1->side[2] && this->ava->body[6] <= this->n5a->horn1->side[4])
				&& (this->ava->body[7] - 2 >= this->n5a->horn1->side[1] && this->ava->body[7] - 2 <= this->n5a->horn1->side[3] || this->ava->body[9] - 2 >= this->n5a->horn1->side[1] && this->ava->body[9] - 2 <= this->n5a->horn1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing horn1!"<<endl;
			}
			else if((this->ava->body[4] >= this->n5a->upperhorn1->side[2] && this->ava->body[4] <= this->n5a->upperhorn1->side[4] || this->ava->body[6] >= this->n5a->upperhorn1->side[2] && this->ava->body[6] <= this->n5a->upperhorn1->side[4])
				&& (this->ava->body[7] - 2 >= this->n5a->upperhorn1->side[1] && this->ava->body[7] - 2 <= this->n5a->upperhorn1->side[3] || this->ava->body[9] - 2 >= this->n5a->upperhorn1->side[1] && this->ava->body[9] - 2 <= this->n5a->upperhorn1->side[3])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing upperhorn1!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5a->horn1->side[1] && this->ava->body[7] + 15 <= this->n5a->horn1->side[3] || this->ava->body[9] + 15 <= this->n5a->horn1->side[1] && this->ava->body[9] + 15 >= this->n5a->horn1->side[3])
				&& (this->ava->body[6] + 3 >= this->n5a->horn1->side[2] && this->ava->body[6] + 3 <= this->n5a->horn1->side[4] || this->ava->body[8] + 3 >= this->n5a->horn1->side[2] && this->ava->body[8] + 3 <= this->n5a->horn1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing horn1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5a->upperhorn1->side[1] && this->ava->body[7] + 15 <= this->n5a->upperhorn1->side[3] || this->ava->body[9] + 15 <= this->n5a->upperhorn1->side[1] && this->ava->body[9] + 15 >= this->n5a->upperhorn1->side[3])
				&& (this->ava->body[6] + 3 >= this->n5a->upperhorn1->side[2] && this->ava->body[6] + 3 <= this->n5a->upperhorn1->side[4] || this->ava->body[8] + 3 >= this->n5a->upperhorn1->side[2] && this->ava->body[8] + 3 <= this->n5a->upperhorn1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing upperhorn1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5a->upperhorn2->side[1] && this->ava->body[7] + 15 <= this->n5a->upperhorn2->side[3] || this->ava->body[9] + 15 <= this->n5a->upperhorn2->side[1] && this->ava->body[9] + 15 >= this->n5a->upperhorn2->side[3])
				&& (this->ava->body[6] + 3 >= this->n5a->upperhorn2->side[2] && this->ava->body[6] + 3 <= this->n5a->upperhorn2->side[4] || this->ava->body[8] + 3 >= this->n5a->upperhorn2->side[2] && this->ava->body[8] + 3 <= this->n5a->upperhorn2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing upperhorn2: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5a->horn2->side[1] && this->ava->body[7] + 15 <= this->n5a->horn2->side[3] || this->ava->body[9] + 15 <= this->n5a->horn2->side[1] && this->ava->body[9] + 15 >= this->n5a->horn2->side[3])
				&& (this->ava->body[6] + 3 >= this->n5a->horn2->side[2] && this->ava->body[6] + 3 <= this->n5a->horn2->side[4] || this->ava->body[8] + 3 >= this->n5a->horn2->side[2] && this->ava->body[8] + 3 <= this->n5a->horn2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing horn2: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5a->body1->side[1] && this->ava->body[7] + 15 <= this->n5a->body1->side[3] || this->ava->body[9] + 15 <= this->n5a->body1->side[1] && this->ava->body[9] + 15 >= this->n5a->body1->side[3])
				&& (this->ava->body[6] + 3 >= this->n5a->body1->side[2] && this->ava->body[6] + 3 <= this->n5a->body1->side[4] || this->ava->body[8] + 3 >= this->n5a->body1->side[2] && this->ava->body[8] + 3 <= this->n5a->body1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing body1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5a->body2->side[1] && this->ava->body[7] + 15 <= this->n5a->body2->side[3] || this->ava->body[9] + 15 <= this->n5a->body2->side[1] && this->ava->body[9] + 15 >= this->n5a->body2->side[3])
				&& (this->ava->body[6] + 3 >= this->n5a->body2->side[2] && this->ava->body[6] + 3 <= this->n5a->body2->side[4] || this->ava->body[8] + 3 >= this->n5a->body2->side[2] && this->ava->body[8] + 3 <= this->n5a->body2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing body2: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5a->body3->side[1] && this->ava->body[7] + 15 <= this->n5a->body3->side[3] || this->ava->body[9] + 15 <= this->n5a->body3->side[1] && this->ava->body[9] + 15 >= this->n5a->body3->side[3])
				&& (this->ava->body[6] + 3 >= this->n5a->body3->side[2] && this->ava->body[6] + 3 <= this->n5a->body3->side[4] || this->ava->body[8] + 3 >= this->n5a->body3->side[2] && this->ava->body[8] + 3 <= this->n5a->body3->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing body3: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5a->leg1->side[1] && this->ava->body[7] + 15 <= this->n5a->leg1->side[3] || this->ava->body[9] + 15 <= this->n5a->leg1->side[1] && this->ava->body[9] + 15 >= this->n5a->leg1->side[3])
				&& (this->ava->body[6] + 3 >= this->n5a->leg1->side[2] && this->ava->body[6] + 3 <= this->n5a->leg1->side[4] || this->ava->body[8] + 3 >= this->n5a->leg1->side[2] && this->ava->body[8] + 3 <= this->n5a->leg1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing leg1: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5a->leg3->side[1] && this->ava->body[7] + 15 <= this->n5a->leg3->side[3] || this->ava->body[9] + 15 <= this->n5a->leg3->side[1] && this->ava->body[9] + 15 >= this->n5a->leg3->side[3])
				&& (this->ava->body[6] + 3 >= this->n5a->leg3->side[2] && this->ava->body[6] + 3 <= this->n5a->leg3->side[4] || this->ava->body[8] + 3 >= this->n5a->leg3->side[2] && this->ava->body[8] + 3 <= this->n5a->leg3->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing leg3: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5a->leg2->side[1] && this->ava->body[7] + 15 <= this->n5a->leg2->side[3] || this->ava->body[9] + 15 <= this->n5a->leg2->side[1] && this->ava->body[9] + 15 >= this->n5a->leg2->side[3])
				&& (this->ava->body[6] + 3 >= this->n5a->leg2->side[2] && this->ava->body[6] + 3 <= this->n5a->leg2->side[4] || this->ava->body[8] + 3 >= this->n5a->leg2->side[2] && this->ava->body[8] + 3 <= this->n5a->leg2->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing leg2: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5a->leg4->side[1] && this->ava->body[7] + 15 <= this->n5a->leg4->side[3] || this->ava->body[9] + 15 <= this->n5a->leg4->side[1] && this->ava->body[9] + 15 >= this->n5a->leg4->side[3])
				&& (this->ava->body[6] + 3 >= this->n5a->leg4->side[2] && this->ava->body[6] + 3 <= this->n5a->leg4->side[4] || this->ava->body[8] + 3 >= this->n5a->leg4->side[2] && this->ava->body[8] + 3 <= this->n5a->leg4->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing leg4: side!"<<endl;
			}
			else if((this->ava->body[7] + 15 >= this->n5a->foot1->side[1] && this->ava->body[7] + 15 <= this->n5a->foot1->side[3] || this->ava->body[9] + 15 <= this->n5a->foot1->side[1] && this->ava->body[9] + 15 >= this->n5a->foot1->side[3])
				&& (this->ava->body[6] + 3 >= this->n5a->foot1->side[2] && this->ava->body[6] + 3 <= this->n5a->foot1->side[4] || this->ava->body[8] + 3 >= this->n5a->foot1->side[2] && this->ava->body[8] + 3 <= this->n5a->foot1->side[4])){
				this->ava->life = this->ava->life - 1;
				cout<< "Game Over at right wing foot1: side!"<<endl;
			}
		}
		void checkOutofBorder(){
			checkRock();
			checkInvader1();
			checkInvader2();
			checkInvader3();
			checkInvader4();
			checkInvader5();
			checkInvader5a();
			checkInvader4a();
			checkInvader3a();
			checkInvader1a();
			checkInvader2a();
			//checkInvader6();
		}
		checkRock(){
			if(this->rock1->block1->side[1] >= this->winHeight){
//				this->rock1 = new Rock(300, 0, 330, 15);
				this->rock1->translateRock(0, -winHeight);
			}
		}
		checkInvader1(){
			if(this->n->part1->side[1] >= this->winHeight){
//				this->n = new Invader1(50, 0, 70, 10, BLUE);
				if(this->n->part1->side[0] == 175){
					this->n->translateInvader1(375, -winHeight);
				}else if(this->n->part1->side[0] == 550){
					this->n->translateInvader1(-250, -winHeight);
				}
				else if(this->n->part1->side[0] == 300){
					this->n->translateInvader1(-125, -winHeight);
				}
				else if(this->n->part1->side[0] == 50){
					this->n->translateInvader1(375, -winHeight);
				}
				else if(this->n->part1->side[0] == 425){
					this->n->translateInvader1(-375, -winHeight);
				}

			}
		}
		checkInvader1a(){
			if(this->na->part1->side[1] >= this->winHeight){
//				this->n = new Invader1(50, 0, 70, 10, BLUE);
				if(this->na->part1->side[0] == 175){
					this->na->translateInvader1(125, -winHeight);
				}else if(this->na->part1->side[0] == 550){
					this->na->translateInvader1(-375, -winHeight);
				}
				else if(this->na->part1->side[0] == 300){
					this->na->translateInvader1(-250, -winHeight);
				}
				else if(this->na->part1->side[0] == 50){
					this->na->translateInvader1(375, -winHeight);
				}
				else if(this->na->part1->side[0] == 425){
					this->na->translateInvader1(125, -winHeight);
				}

			}
		}
		checkInvader2(){
			if(this->n2->part1->side[1] >= this->winHeight){
//				this->n2 = new Invader2(150, 0, 190, 10, GREEN);
				if(this->n2->part1->side[0] == 175){
					this->n2->translateInvader2(375, -winHeight);
				}else if(this->n2->part1->side[0] == 550){
					this->n2->translateInvader2(-250, -winHeight);
				}
				else if(this->n2->part1->side[0] == 300){
					this->n2->translateInvader2(-125, -winHeight);
				}
				else if(this->n2->part1->side[0] == 50){
					this->n2->translateInvader2(375, -winHeight);
				}
				else if(this->n2->part1->side[0] == 425){
					this->n2->translateInvader2(-375, -winHeight);
				}
			}
		}
		checkInvader2a(){
			if(this->n2a->part1->side[1] >= this->winHeight){
//				this->n2 = new Invader2(150, 0, 190, 10, GREEN);
				if(this->n2a->part1->side[0] == 175){
					this->n2a->translateInvader2(125, -winHeight);
				}else if(this->n2a->part1->side[0] == 550){
					this->n2a->translateInvader2(-375, -winHeight);
				}
				else if(this->n2a->part1->side[0] == 300){
					this->n2a->translateInvader2(-250, -winHeight);
				}
				else if(this->n2a->part1->side[0] == 50){
					this->n2a->translateInvader2(375, -winHeight);
				}
				else if(this->n2a->part1->side[0] == 425){
					this->n2a->translateInvader2(125, -winHeight);
				}
			}
		}
		checkInvader3(){
			if(this->n3->parthead->side[1] >= this->winHeight){
//				this->n3 = new Invader3(500, 0, 545, 10, 9);
				if(this->n3->partforehead->side[0] == 175){
					this->n3->translateInvader3(375, -winHeight);
				}else if(this->n3->partforehead->side[0] == 550){
					this->n3->translateInvader3(-250, -winHeight);
				}
				else if(this->n3->partforehead->side[0] == 300){
					this->n3->translateInvader3(-125, -winHeight);
				}
				else if(this->n3->partforehead->side[0] == 50){
					this->n3->translateInvader3(375, -winHeight);
				}
				else if(this->n3->partforehead->side[0] == 425){
					this->n3->translateInvader3(-375, -winHeight);
				}
			}
		}
		checkInvader4(){
			if(this->n4->parthorn1->side[1] >= this->winHeight){
//				this->n4 = new Invader4(250, 0, 280, 10, 5);
				if(this->n4->parthead->side[0] == 175){
					this->n4->translateInvader4(375, -winHeight);
				}else if(this->n4->parthead->side[0] == 550){
					this->n4->translateInvader4(-250, -winHeight);
				}
				else if(this->n4->parthead->side[0] == 300){
					this->n4->translateInvader4(-125, -winHeight);
				}
				else if(this->n4->parthead->side[0] == 50){
					this->n4->translateInvader4(375, -winHeight);
				}
				else if(this->n4->parthead->side[0] == 425){
					this->n4->translateInvader4(-375, -winHeight);
				}
			}
		}
		checkInvader4a(){
			if(this->n4a->parthorn1->side[1] >= this->winHeight){
				if(this->n4a->parthead->side[0] == 175){
					this->n4a->translateInvader4(125, -winHeight);
				}else if(this->n4a->parthead->side[0] == 550){
					this->n4a->translateInvader4(-375, -winHeight);
				}
				else if(this->n4a->parthead->side[0] == 300){
					this->n4a->translateInvader4(-250, -winHeight);
				}
				else if(this->n4a->parthead->side[0] == 50){
					this->n4a->translateInvader4(375, -winHeight);
				}
				else if(this->n4a->parthead->side[0] == 425){
					this->n4a->translateInvader4(125, -winHeight);
				}
			}
		}
		checkInvader3a(){
			if(this->n3a->parthead->side[1] >= this->winHeight){
//				this->n3a = new Invader3(500, 0, 545, 10, 9);
				if(this->n3a->partforehead->side[0] == 175){
					this->n3a->translateInvader3(125, -winHeight);
				}else if(this->n3a->partforehead->side[0] == 550){
					this->n3a->translateInvader3(-375, -winHeight);
				}
				else if(this->n3a->partforehead->side[0] == 300){
					this->n3a->translateInvader3(-250, -winHeight);
				}
				else if(this->n3a->partforehead->side[0] == 50){
					this->n3a->translateInvader3(375, -winHeight);
				}
				else if(this->n3a->partforehead->side[0] == 425){
					this->n3a->translateInvader3(125, -winHeight);
				}
			}
		}
		checkInvader5(){
			if(this->n5->upperhorn1->side[1] >= this->winHeight){
//				this->n5 = new Invader5(350, 0, 370, 7, 12);
				if(this->n5->body1->side[0] == 175){
					this->n5->translateInvader5(375, -winHeight);
				}else if(this->n5->body1->side[0] == 550){
					this->n5->translateInvader5(-250, -winHeight);
				}
				else if(this->n5->body1->side[0] == 300){
					this->n5->translateInvader5(-125, -winHeight);
				}
				else if(this->n5->body1->side[0] == 50){
					this->n5->translateInvader5(375, -winHeight);
				}
				else if(this->n5->body1->side[0] == 425){
					this->n5->translateInvader5(-375, -winHeight);
				}
			}
		}
		checkInvader5a(){
			if(this->n5a->upperhorn1->side[1] >= this->winHeight){
//				this->n5a = new Invader5(350, 0, 370, 7, 12);
				if(this->n5a->body1->side[0] == 175){
					this->n5a->translateInvader5(125, -winHeight);
				}else if(this->n5a->body1->side[0] == 550){
					this->n5a->translateInvader5(-375, -winHeight);
				}
				else if(this->n5a->body1->side[0] == 300){
					this->n5a->translateInvader5(-250, -winHeight);
				}
				else if(this->n5a->body1->side[0] == 50){
					this->n5a->translateInvader5(375, -winHeight);
				}
				else if(this->n5a->body1->side[0] == 425){
					this->n5a->translateInvader5(125, -winHeight);
				}
			}
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
int gameOverScreen(int score, int flag){
	char myScore [20]; 					//int will be stored here as a string
	itoa(score, myScore,10);
	int windowHeight = 650, windowWidth = 1355/2, x =1;
	int bgCoordinate[10] = {windowWidth - windowWidth, windowHeight - windowHeight, windowWidth, windowHeight - windowHeight, windowWidth, windowHeight, windowWidth - windowWidth, windowHeight, windowWidth - windowWidth, windowHeight - windowHeight};
	Background *bg = new Background(bgCoordinate, 0, 75);
	Arrow *ar = new Arrow(135, windowHeight - 99, 155, windowHeight - 95 - 25);
	do{
		bg->drawBackground();
		ar->drawArrow();
		settextstyle(BOLD_FONT, HORIZ_DIR, 8);
		outtextxy(300, 150, myScore);
		setcolor(WHITE);
		settextstyle(BOLD_FONT, HORIZ_DIR, 9);
		outtextxy(75, 30, "GAME OVER");
		settextstyle(BOLD_FONT, HORIZ_DIR, 5);
		outtextxy(260, windowHeight - 200, "AGAIN?");
		settextstyle(BOLD_FONT, HORIZ_DIR, 4);
		outtextxy(165, windowHeight - 125, "YES");
		outtextxy(430, windowHeight - 125, "NO");
		if(kbhit()){
			if(GetAsyncKeyState(VK_RIGHT)){
				if(flag != 0){
					ar->translateArrow(265, 0);
				}
				flag = 0;
				cout<< "RIGHT!" << endl;
			}
			else if(GetAsyncKeyState(VK_LEFT)){
				if(flag != 1){
					ar->translateArrow(-265, 0);
				}
				flag = 1;
				cout<< "LEFT!" << endl;
			} 
			else if(GetAsyncKeyState(VK_SPACE)){
				cout<< "ENTER!" << endl;
				return flag;
			}
		}
		delay(125);
	}while(x > 0);
	cout<< "NIgawas sya"<< endl;
}
int main(){
	int again = 1, score = 0;
	initGameWindow();
	do{
		Environment *envi = new Environment(1355/2, 650); // windowHeight = 650, windowWidth = 1355/2;
		score = envi->drawEnvironment();
		again = gameOverScreen(score, 1);
	}while(again == 1);
	getch();
    return 0;
}
