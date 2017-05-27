#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include <iostream>

using namespace std;

class Background{
	int backgroundCoor[10];
	int color;

	public:
	Background(int coor[10], int c){
			for(int i = 0; i < 10; i++){
				backgroundCoor[i] = coor[i];
			}
			color = c;
		}
		void drawBackground(){
			setfillstyle(SOLID_FILL, color);
			fillpoly(5, backgroundCoor);
		}
};
class Avatar{
	public:
		int body[22], head[10];
		Avatar(int lawas[22], int ulo[10]){
			for(int i = 0; i < 22; i++){
				body[i] = lawas[i];
			}
			for(int i = 0; i < 10; i++){
				head[i] = ulo[i];
			}
		}
		void drawAvatar(){
			setcolor(RED);
			setfillstyle(SOLID_FILL, 4);
			fillpoly(11, body);
			setcolor(12);
			setfillstyle(SOLID_FILL, 12);
    		fillpoly(5, head);
		}
		void translateHorizontalRight(){
			for(int i = 0; i < 22; i++){
				if(i % 2 == 0){
					body[i] = body[i] + 4;
				}
			}
			for(int i = 0; i < 10; i++){
				if(i % 2 == 0){
					head[i] = head[i] + 4;
				}
			}
		}
		void translateHorizontalLeft(){
			for(int i = 0; i < 22; i++){
				if(i % 2 == 0){
					body[i] = body[i] - 4;
				}
			}
			for(int i = 0; i < 10; i++){
				if(i % 2 == 0){
					head[i] = head[i] - 4;
				}
			}
		}
		void translateVerticalUp(){
			for(int i = 0; i < 22; i++){
				if(i % 2 != 0){
					body[i] = body[i] - 4;
				}
			}
			for(int i = 0; i < 10; i++){
				if(i % 2 != 0){
					head[i] = head[i] - 4;
				}
			}
		}
		void translateVerticalDown(){
			for(int i = 0; i < 22; i++){
				if(i % 2 != 0){
					body[i] = body[i] + 4;
				}
			}
			for(int i = 0; i < 10; i++){
				if(i % 2 != 0){
					head[i] = head[i] + 4;
				}
			}
		}
		void scale(int p){
			body[2] = body[2] - ((body[2] - body[0]) / p);
			body[4] = body[4] - ((body[4] - body[2]) / p);
			body[6] = body[6] - ((body[6] - body[4]) / p);
			body[8] = body[6];
			body[10] = body[4];
			body[16] = body[16] + ((body[18] - body[16]) / p);
			body[14] = body[16];
			body[18] = body[18] + ((body[20] - body[18]) / p);
			body[12] = body[18];
			body[11] = body[11] - ((body[11] - body[9]) / p) - ((body[9] - body[7]) / p) - ((body[5] - body[3]) / p);
			body[13] = body[11];
			body[9] = body[9] - ((body[9] - body[7]) / p) - ((body[5] - body[3]) / p);
			body[15] = body[9];
			body[5] = body[5] - ((body[5] - body[3]) / p);
			body[19] = body[5];
			body[7] = body[5];
			body[17] = body[5];
			head[2] = head[2] - ((head[2] - head[0]) / p);
			head[4] = head[4] - ((head[4] - head[6]) / p) - ((head[6] - head[0]) / p);
			head[6] = head[6] - ((head[6] - head[0]) / p);
			head[5] = head[5] + ((head[3] - head[5]) / p);
			head[7] = head[5];
		}
};
class Invader{

};
class Environment{
	Background *bg;

	public:
		Environment(int windowWidth, int windowHeight){
			int bgCoordinate[10] = {windowWidth - windowWidth, windowHeight - windowHeight, windowWidth, windowHeight - windowHeight, windowWidth, windowHeight, windowWidth - windowWidth, windowHeight, windowWidth - windowWidth, windowHeight - windowHeight};
			this->bg = new Background(bgCoordinate, 15);
		}
		void drawEnvironment(){
			bg->drawBackground();
		}
};
int main(){
	int ulo[10] = {201, 200, 214, 200, 209.50, 180, 205.75, 180, 201, 200};
	int lawas[22] = {200, 200, 215, 200, 225, 265, 290, 265, 290, 285, 225, 297, 190, 297, 126, 285, 126, 265, 190, 265, 200,200};
	int windowHeight = 700, windowWidth = 1355/2;
	int flag1 = 1, flag2 = 2;
	Environment *envi = new Environment(windowWidth, windowHeight);
	initwindow(windowWidth, windowHeight, "Space Invader");
	Avatar *ava = new Avatar(lawas, ulo), *a1 = new Avatar(lawas, ulo);
	ava->scale(2);
	//ava->scale(2);
	//a1->scale();
	ava->drawAvatar();
	a1->drawAvatar();
	envi->drawEnvironment();
	do{
		envi->drawEnvironment();
		if(flag1 == 1){ //to the right
			ava->translateHorizontalRight();
			if(ava->body[8] >= windowWidth){
				ava->translateVerticalDown();
				flag1 = 2;
			}
		}
		if(flag1 == 2){ //to the left
			ava->translateHorizontalLeft();
			if(ava->body[16] <= 0){
				ava->translateVerticalDown();
				flag1 = 1;
			}
		}
		if(flag2 == 2){ //to the left
			a1->translateHorizontalLeft();
			if(a1->body[16] <= 0){
				a1->translateVerticalUp();
				flag2 = 1;
			}
		}
		if(flag2 == 1){ //to the right
			a1->translateHorizontalRight();
			if(a1->body[8] >= windowWidth){
				a1->translateVerticalUp();
				flag2 = 2;
			}
		}
		ava->drawAvatar();
		a1->drawAvatar();
		delay(10);
	}while(!kbhit( ));
	getch();
    return 0;
}
