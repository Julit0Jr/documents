#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<iostream>
const double PI = 3.141592654;

using namespace std;
class Background{
	int backgroundCoor[10];
	int color;
	
	public:
		void setBackground(int coor[10], int c){
			for(int i = 0; i < 10; i++){
				backgroundCoor[i] = coor[i];
			}
			color = c;
		}
		void drawBackground(){
			setfillstyle(SOLID_FILL, color);
			fillpoly(5, backgroundCoor);
		}
		void changeColor(int c){
			color = c;
		}
};
class Mountain{
	int mtCoor[20];
	
	public:
		void setMountain(int coor[20]){
			for(int i = 0; i < 20; i++){
				mtCoor[i] = coor[i];
			}
		}
		void drawMountain(){
			setcolor(GREEN);
			setfillstyle(SOLID_FILL, GREEN);
			fillpoly(10, mtCoor);
		}
};
class Road{
	int roadCoor[10];
	int lineCoor[10];
	
	public:
		void setRoad(int rcoor[10], int lcoor[10]){
			for(int i = 0; i < 10; i++){
				roadCoor[i] = rcoor[i];
				lineCoor[i] = lcoor[i];
			}
		}
		void drawRoad(){
			setcolor(LIGHTGRAY);
			setfillstyle(SOLID_FILL, LIGHTGRAY);
			fillpoly(5, roadCoor);
			setcolor(BLACK);
			setfillstyle(SOLID_FILL, 0);
			fillpoly(5, lineCoor);
		}
};
class Cab{
	public:
		int c[18];
		int color;
		
		void setCab(int x[18], int col){
			for(int i = 0; i < 18; i++){
				c[i] = x[i];
			}
			color = col;
		}
		void drawCab(){
			setcolor(RED);
			setfillstyle(SOLID_FILL, color);
			fillpoly(9, c);
		}
		void translate(){
			for(int i = 0; i < 18; i++){
				if(i % 2 == 0){
					c[i] = c[i] + 8;
				}
			}
		}
};
class Wheel{
	public:
		int x, y, rad, color;
		int l1[4], l2[4], l3[4], l4[4];

		void setWheel(int xx, int yy, int r, int col){
			x = xx;
			y = yy;
			rad = r;
			color = col;
			l1[0] = x;
			l1[1] = y;
			l1[2] = x;
			l1[3] = y + rad;
			
			l2[0] = x;
			l2[1] = y;
			l2[2] = x + rad;
			l2[3] = y;
			l3[0] = x;
			l3[1] = y;
			l3[2] = x - rad;
			l3[3] = y;
			l4[0] = x;
			l4[1] = y;
			l4[2] = x;
			l4[3] = y - rad;	
		}
		void drawWheel(){
			int r = rad;
			setfillstyle(SOLID_FILL, color);
			setcolor(0);
			for(int i = 0; i < 3; i++){
				circle(x, y, r);
				r = r -2;
			}
			r = 10;
			for(int i = 0; i < 5; i++){
				circle(x, y, r);
				r = r -2;
			}
			line(l1[0], l1[1], l1[2], l1[3]);
			line(l2[0], l2[1], l2[2], l2[3]);
			line(l3[0], l3[1], l3[2], l3[3]);
			line(l4[0], l4[1], l4[2], l4[3]);
		}
		void translate(int angle){
			x = x + 8;
			int theta = PI * angle / 180;
			l1[0] = x; l1[1] = y;
			l1[2] = x + rad * cos (theta);
			l1[3] = y + rad * sin (theta);
			l2[0] = x; l2[1] = y;
			l2[2] = x + rad * cos (theta+67.5);
			l2[3] = y + rad * sin (theta+67.5);
			l3[0] = x; l3[1] = y;
			l3[2] = x + rad * cos (theta+202.5);
			l3[3] = y + rad * sin (theta+202.5);
			l4[0] = x; l4[1] = y;
			l4[2] = x + rad * cos (theta+135);
			l4[3] = y + rad * sin (theta+135);
		}
};
class Line{
	private:
		int x1, x2, y1, y2;
		int len, angle;

	public:
		Line(int x1, int y1, int len, int angle){
			this->x1 = x1;
			this->y1 = y1;
			this->len = len;
			this->angle = angle;
			rotateLine(angle);
		}

		void drawLine(int color){
			setcolor(color);
			line(x1,y1,x2,y2);

		}

		void translateLine(int x, int y){
			this->x1 += x;
			this->y1 += y;
			this->x2 += x;
			this->y2 += y;
		}

		void rotateLine(float angle){
			float rotateFactor = 3.1415*angle/180;
			x2 = (cos(rotateFactor) * (len/2)) - (sin(rotateFactor) * (len/2));
			y2 = (sin(rotateFactor) * (len/2)) + (cos(rotateFactor) * (len/2));

			x2 += x1;
			y2 += y1;

			//line(x1,y1,currX,currY);
		}
};
class Sun{
	public:
		int x, y, radius, angle;
		Line *line1, *line2, *line3, *line4, *line5, *line6, *line7, *line8;
		Sun(int x, int y, int radius){
			this->x = x;
			this->y = y;
			this->radius = radius;
			this->line1  = new Line(x,y,3*radius,0);
			this->line2  = new Line(x,y,3*radius,45);
			this->line3  = new Line(x,y,3*radius,90);
			this->line4  = new Line(x,y,3*radius,135);
			this->line5  = new Line(x,y,3*radius,180);
			this->line6  = new Line(x,y,3*radius,225);
			this->line7  = new Line(x,y,3*radius,270);
			this->line8  = new Line(x,y,3*radius,315);
		}

		void drawSun(){
			setcolor(YELLOW);
			setfillstyle(1, YELLOW);
			fillellipse(x,y, radius, radius);

			line1->drawLine(YELLOW);
			line2->drawLine(YELLOW);
			line3->drawLine(YELLOW);
			line4->drawLine(YELLOW);
			line5->drawLine(YELLOW);
			line6->drawLine(YELLOW);
			line7->drawLine(YELLOW);
			line8->drawLine(YELLOW);
		}

		void translateSun(int x, int y){
			rotateRays(y*8);
			this->x += x;
			this->y += y;
			line1->translateLine(x,y);
			line2->translateLine(x,y);
			line3->translateLine(x,y);
			line4->translateLine(x,y);
			line5->translateLine(x,y);
			line6->translateLine(x,y);
			line7->translateLine(x,y);
			line8->translateLine(x,y);
		}

		void rotateRays(int angle){
			line1->rotateLine(0  + angle);
			line2->rotateLine(45 + angle);
			line3->rotateLine(90 + angle);
			line4->rotateLine(135+ angle);
			line5->rotateLine(180+ angle);
			line6->rotateLine(225+ angle);
			line7->rotateLine(270+ angle);
			line8->rotateLine(315+ angle);
		}
//	public:
//		int x, y, radius, ray;
//		void setSun(int xx, int yy, int rad, int r){
//			x = xx;
//			y = yy;
//			radius = rad;
//			ray = r;
//		}
//		void drawSun(){
//			setcolor(YELLOW);
//			setfillstyle(SOLID_FILL, YELLOW);
//			fillellipse(x, y, radius, radius);
//			line(x, y, x, y - radius - 40); //North
//			line(x, y, x + radius + 40, y); //East
//			line(x, y, x, y + radius + 40); //South
//			line(x, y, x - radius - 40, y); //West
//			line(x, y, x + radius/2 + 40, y - radius/2 - 40); //North East
//			line(x, y, x + radius/2 + 40, y + radius/2 + 40); //South East
//			line(x, y, x - radius/2 - 40, y + radius/2 + 40); //South West
//			line(x, y, x - radius/2 - 40, y - radius/2 - 40); //North West
////			setcolor(0);
////			ellipse(x, y, 0, 360, radius, radius);
////			circle(x, y, radius);
//		}
//		void rotate(int angle){
//			int theta = PI * angle / 180;
//			setcolor(YELLOW);
//			setfillstyle(SOLID_FILL, YELLOW);
//			y = y + 2;
//			fillellipse(x, y, radius, radius);
//			int rad = radius + 40;			
//			line(x, y,  x + rad * cos (theta), y + rad * sin (theta)); //North
//			angle = angle + 20;
//			theta = PI * angle / 180;
//			line(x, y,  x + rad * cos (theta), y + rad * sin (theta)); //East
//			angle = angle + 20;
//			theta = PI * angle / 180;
//			line(x, y,  x + rad * cos (theta), y + rad * sin (theta)); //South
//			angle = angle + 20;
//			theta = PI * angle / 180;
//			line(x, y,  x + rad * cos (theta), y + rad * sin (theta)); //West
//			angle = angle + 20;
//			theta = PI * angle / 180;
//			line(x, y,  x + rad * cos (theta), y + rad * sin (theta)); //North East
//			angle = angle + 20;
//			theta = PI * angle / 180;
//			line(x, y,  x + rad * cos (theta), y + rad * sin (theta)); //South East
//			angle = angle + 20;
//			theta = PI * angle / 180;
//			line(x, y,  x + rad * cos (theta), y + rad * sin (theta)); //South West
//			angle = angle + 20;
//			theta = PI * angle / 180;
//			line(x, y,  x + rad * cos (theta), y + rad * sin (theta)); //North West
//		}
};
class Rect{
	private:
		int xmin, ymin, xmax, ymax;
		float scalefactor;
		int rect[8];

	public:

		Rect(int xmin, int ymin, int xmax, int ymax){
			this->xmin = xmin;
			this->ymin = ymin;
			this->xmax = xmax;
			this->ymax = ymax;
			this->scalefactor = 1;
		};

		void drawRect(int color, int style){
			rect[0] = xmin;
			rect[1] = ymin;
			rect[2] = xmin;
			rect[3] = ymax;
			rect[4] = xmax;
			rect[5] = ymax;
			rect[6] = xmax;
			rect[7] = ymin;

			for(int i = 0; i < 8; i++){
				rect[i] *= scalefactor;
			}

			setcolor(color);
			setfillstyle(style, color);
			fillpoly(4, rect);
		}

		void translateRect(int x, int y){
			this->xmin += x;
			this->xmax += x;
			this->ymin += y;
			this->ymin += y;
		}

		void scaleRect(float scalefactor){
			this->scalefactor = scalefactor;
		}
};
class Vane{
	private:
		int x, y, x2, y2;
		float scalefactor, rotatefactor;
		int vane[8];
	public:
		Vane(){
			this->x = 0;
			this->y = 0;
			this->scalefactor = 1;
			this->rotatefactor = 3.1415*0/180;

		}

		void drawVane(int color){
			vane[0] = (cos(rotatefactor) * (x)) - (sin(rotatefactor) * (y));; //x;
			vane[1] = (sin(rotatefactor) * (x)) + (cos(rotatefactor) * (y)); //y;
			vane[2] = (cos(rotatefactor) * (x-7)) - (sin(rotatefactor) * (y-30)); //x-5;
			vane[3] = (sin(rotatefactor) * (x-7)) + (cos(rotatefactor) * (y-30)); //y-20;
			vane[4] = (cos(rotatefactor) * x) - (sin(rotatefactor) * (y-130)); //x;
			vane[5] = (sin(rotatefactor) * x) + (cos(rotatefactor) * (y-130)); //y-70;
			vane[6] = (cos(rotatefactor) * (x+7)) - (sin(rotatefactor) * (y-30)); //x+5;
			vane[7] = (sin(rotatefactor) * (x+7)) + (cos(rotatefactor) * (y-30)); //y-20;

			//translateVane(x2,y2);

		/*	{
				x	, y		,
				x-05, y-20	,
				x	, y-70	,
				x+05, y-20
			};*/
			for(int i = 0; i < 8; i++){
			/*	if(i != 0 && i != 1){
					if(i % 2 == 1)
						vane[i] = (sin(rotatefactor) * vane[i-1]) + (cos(rotatefactor) * vane[i]);
					else if(i % 2 == 0)
						vane[i]  = (cos(rotatefactor) * vane[i]) - (sin(rotatefactor) * vane[i+1]);
				}*/
				if(i % 2 == 0)
					vane[i] += x2;
				else
					vane[i] += y2;
				vane[i] *= scalefactor;
			}

			setfillstyle(1, color);
			fillpoly(4, vane);
		}

		void rotateVane(int angle){
			this->rotatefactor = 3.1415*angle/180;
//			vane[0] = (cos(rotatefactor) * (x)) - (sin(rotatefactor) * (y));; //x;
//			vane[1] = (sin(rotatefactor) * (x)) + (cos(rotatefactor) * (y)); //y;
//			vane[2] = (cos(rotatefactor) * (x-5)) - (sin(rotatefactor) * (y-20)); //x-5;
//			vane[3] = (sin(rotatefactor) * (x-5)) + (cos(rotatefactor) * (y-20)); //y-20;
//			vane[4] = (cos(rotatefactor) * (x)) - (sin(rotatefactor) * (y-70)); //x;
//			vane[5] = (sin(rotatefactor) * (x)) + (cos(rotatefactor) * (y-70)); //y-70;
//			vane[6] = (cos(rotatefactor) * (x+5)) - (sin(rotatefactor) * (y-20)); //x+5;
//			vane[7] = (sin(rotatefactor) * (x+5)) + (cos(rotatefactor) * (y-20)); //y-20;

		}

		void translateVane(int x, int y){
			this->x2 = x;
			this->y2 = y;
		}

		void scaleVane(float scalefactor){
			this->scalefactor = scalefactor;
		}
};
class Windmill{
	private:
		int x,  y;
		float scalefactor, rotatefactor;
		Vane *vane1, *vane2, *vane3;
		Rect *pole;
	public:
		Windmill(int x, int y){
			this->x = x;
			this->y = y;
			this->scalefactor = 1;
			this->rotatefactor = 225;
			this->vane1 = new Vane();
			this->vane2 = new Vane();
			this->vane3 = new Vane();
			this->pole = new Rect(x-2,y,x+2,y+300);
		}

		void drawWindmill(int i){
			pole->scaleRect(scalefactor);
			vane1->scaleVane(scalefactor);
			vane2->scaleVane(scalefactor);
			vane3->scaleVane(scalefactor);

			rotateWindmill(i * 8);

			vane1->translateVane(x,y);
			vane2->translateVane(x,y);
			vane3->translateVane(x,y);


			/*for(int i = 0; i < 7; i++){
				vane[i]   = (cos(rotateFactor) * vane[i]) - (sin(rotateFactor) * vane[i]);
				vane[i+1] = (sin(rotateFactor) * vane[i+1]) + (cos(rotateFactor) * vane[i+1]);
			}*/
            pole->drawRect(DARKGRAY,1);

            setcolor(BROWN);
			setfillstyle(1,BLACK);
			fillellipse(x*scalefactor,y*scalefactor,4*scalefactor,4*scalefactor);

            setcolor(RED);
			vane1->drawVane(RED);
			vane2->drawVane(RED);
			vane3->drawVane(RED);

		}

		void scaleWindmill(float scalefactor){
			this->scalefactor = scalefactor;
		}

		void rotateWindmill(int i){
			vane1->rotateVane(0 + i);
			vane2->rotateVane(120 + i);
			vane3->rotateVane(240 + i);
		}

};
class Environment{
	public:
		//Rect	*sky;
		//Rect	*ground;
		//Rect	*road, *line;
		//Hills	*hill;
		Mountain *mt;
		Windmill *windmill1, *windmill2, *windmill3;
		Sun	*sun;
		Environment(){
//			this->sky	= new Rect(0,0,1280,720);
//			//this->ground= new Rect(0,600,1280,720);
//			this->road	= new Rect(0,500,1280,600);
//			this->line	= new Rect(0,548,1280,553);
//			this->hill  = new Hills(0,720);
			int bukid[20] = {0, 400, 250, 300, 300, 350, 550, 200, 800, 400, 800 + (555/2), 275, 1355, 400, 1355, 700, 0, 700, 0, 400};
			this->mt = new Mountain();
			mt->setMountain(bukid);
			this->windmill1 = new Windmill(200,250);
			this->windmill2 = new Windmill(700,150);
			this->windmill3 = new Windmill(350,100);
			this->sun 	= new Sun(1200, 100, 37);
		}
		void drawEnvironment(int sunr, int i){
//			sky->drawRect(COLOR(210,230,255),1);
			sun->translateSun(0,sunr);
			sun->drawSun();
			mt->drawMountain();
//			//ground->drawRect(GREEN,1);
//			hill->drawHills(GREEN);
//			road->drawRect(DARKGRAY,1);
//			line->drawRect(WHITE,1);
			windmill1->scaleWindmill(0.7);
			windmill1->drawWindmill(i);
			windmill2->drawWindmill(i);
			windmill3->scaleWindmill(1.2);
			windmill3->drawWindmill(i);
		}

//		void rotate(int i){
//			windmill1->rotateWindmill(i);
//			windmill2->rotateWindmill(i);
//			windmill3->rotateWindmill(i);
//		}
};
int main(){
	Environment *env = new Environment();
	int windowHeight = 700, windowWidth = 1355;
	Background *bg = new Background();
	env->drawEnvironment(0,0);
	//Pole *p1 = new Pole, *p2 = new Pole, *p3 = new Pole;
	//Fan *f1 = new Fan(), *f2 = new Fan(), *f3 = new Fan(), *f4 = new Fan(), *f5 = new Fan(), *f6 = new Fan(), *f7 = new Fan(), *f8 = new Fan(), *f9 = new Fan();
	Road *road = new Road();
	Cab *cab = new Cab();
	Wheel *w1 = new Wheel(), *w2 = new Wheel();
//	Sun *sun = new Sun();
	int cabCoordinate[18] = {200, 400, 300, 400, 300, 450, 370, 450, 370, 525, 150, 525, 150, 450, 200, 450, 200, 400};
	int bgCoordinate[10] = {windowWidth - windowWidth, windowHeight - windowHeight, windowWidth, windowHeight - windowHeight, windowWidth, windowHeight, windowWidth - windowWidth, windowHeight, windowWidth - windowWidth, windowHeight - windowHeight};
	int dalan[10] = {0, 515, windowWidth, 515, windowWidth, 665, 0, 665, 0, 515};
	int linya[10] = {0, 585, windowWidth, 585, windowWidth, 595, 0, 595, 0 ,585};
	int tubo1[10] = {200, 480, 205, 480, 205, 300, 200, 300, 200, 480};
	int tubo2[10] = {760, 430, 765, 430, 765, 250, 760, 250, 760, 430};
	int tubo3[10] = {880, 450, 885, 450, 885, 270, 880, 270, 880, 450};
	int fan1[10] = {202.5, 300, 197.5, 260, 202.5, 220, 207.5, 260, 202.5, 300},
		fan2[10] = {202.5, 300, 200.5, 315, 190.5, 330, 192.5, 310.5, 202.5, 300},
		fan4[10] = {762.5, 250, 757.5, 230, 762.5, 210, 767.5, 230, 762.5, 250},
		fan7[10] = {882.5, 270, 877.5, 250, 882.5, 230, 887.5, 250, 882.5, 270};
	bg->setBackground(bgCoordinate, 15);
	road->setRoad(dalan, linya);
	cab->setCab(cabCoordinate, 4);
	w1->setWheel(205, 545, 37, 4);
	w2->setWheel(307, 545, 37, 4);
	//sun->setSun(1200, 100, 37, 4);
	//p1->setPole(tubo1); p2->setPole(tubo2); p3->setPole(tubo3); 
//	f1->setFan(fan1); f4->setFan(fan4); f7->setFan(fan7);
//	f2->setFan(fan2);
	int gd = DETECT, gm;
//   	initgraph(&gd, &gm, "C:\\TC\\BGI");
	initwindow(windowWidth, windowHeight);
	bg->drawBackground();
	//sun->drawSun();
	//mt->drawMountain();
	//p1->drawPole(); p2->drawPole(); p3->drawPole();
//	f1->drawFan(); f4->drawFan(); f7->drawFan();
//	f2->drawFan();
	road->drawRoad();
	w1->drawWheel();
	w2->drawWheel();
	cab->drawCab();
	int angle = 0;
	int i = 0;
	do{
		if(env->sun-> y >= 200 && env->sun-> y < 410 /*sun->y == 200*/){
			bg->changeColor(12);
		}
		if(env->sun-> y > 410){
			bg->changeColor(BLACK);
		}
		bg->drawBackground();
		//sun->rotate(angle);
		env->drawEnvironment(i-2,i+2);
		//mt->drawMountain();
		//p1->drawPole(); p2->drawPole(); p3->drawPole();
//		f1->rotate(angle); f4->drawFan(); f7->drawFan();
//		f2->drawFan();
		road->drawRoad();
		cab->translate();
		w1->translate(angle);
		w2->translate(angle);
		w1->drawWheel();
		w2->drawWheel();
		cab->drawCab();
		delay(200);
		angle+= 20;
		if(cab->c[12] > windowWidth){
			w1->setWheel(-171, 545, 37, 4);
			w2->setWheel(-69, 545, 37, 4);
			int cabCoordinate[18] = {-176, 400, -76, 400, -76, 450, -6, 450, -6, 525, -226, 525, -226, 450, -176, 450, -176, 400};
			cab->setCab(cabCoordinate, 4);
		}
		i++;
	}while(!kbhit());
	getch();
}
