#include <graphics.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <conio.h>

using namespace std;
void colorChoice();
void makeLine(); //1
void makeRect(); //2
void makeLineplusColor(); //3
void makeLineplusHalfColor(); //4
void makeRectplusRound(); //5
void makeOval(); //6
void makePolygon(); //8
void makeBezierCurve(); //9
int main(){ 
	int choice = 0, again = 0;
	do{
		cout << "\t\tMenu:" << endl;
		cout << "\n\t [1]     ->      Line" << endl;
		cout << "\t [2]     ->      Rectangle" << endl;
		cout << "\t [3]     ->      Line with color" << endl;
		cout << "\t [4]     ->      Two-colored Line" << endl;
		cout << "\t [5]     ->      Rounded corners rectangle" << endl;
		cout << "\t [6]     ->      Oval" << endl;
		cout << "\t [7]     ->      Shape in winding pattern" << endl;
		cout << "\t [8]     ->      Polygon" << endl;
		cout << "\t [9]     ->      Bezier curve" << endl;
		cout << "\n\tchoice: ";
		cin >> choice;
		system("cls");
		if(choice == 1){ //line
			makeLine();
		}
		else if(choice == 2){ //rectangle
			makeRect();
		}
		else if(choice == 3){ //colored-line
			makeLineplusColor();
		}
		else if(choice == 4){ //two-colored line
			makeLineplusHalfColor();
		}
		else if(choice == 5){ //rectangle with rounded corners
			makeRectplusRound();
		}
		else if(choice == 6){ //oval
			makeOval();
		}
		else if(choice == 7){ //filled polygon in winding pattern
			
		}
		else if(choice == 8){ //polygon
			makePolygon();
		}
		else if(choice == 9){ //bezier curve
			makeBezierCurve();
		}
		else{
			cout << "Invalid Choice!" << endl;
		}
		do{
			cout << "Again? [1] -> Yes || [2] -> No" << endl;
			cout << "choice: ";
			cin >> again;
			if(again < 1 || again >2){
				cout << "Invalid Choice! " << endl;
				system("cls");
			}	
		}while(again < 1 || again >2);
		system("cls");
	}while(again == 1);
	
	cout << "Program Ended!" << endl;
	return 0;
}
void makeLine(){
	/* initialize graphics window at 400 x 300 */
	cout << "Make a LINE" << endl;
	int xmin, ymin, xmax, ymax;
   	cout <<"\nEnter xmin: ";
   	cin >> xmin;
   	cout <<"Enter ymin: ";
   	cin >> ymin;
   	cout <<"Enter xmax: ";
	cin >> xmax;
   	cout <<"Enter ymax: ";
   	cin >> ymax;
   	initwindow(500, 500);
	line(xmin, ymin, xmax,ymax);
    getch();
    closegraph();
}
void makeRect(){
	cout << "Make a RECTANGLE" << endl;
	int cleft, cright, cbottom, ctop;
	cout <<"\nEnter left coordinate: ";
   	cin >> cleft;
   	cout <<"Enter right coordinate: ";
   	cin >> cright;
   	cout <<"Enter bottom coordinate: ";
	cin >> cbottom;
   	cout <<"Enter top coordinate: ";
   	cin >> ctop;
   	
	int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
 	
    /* Draw rectangle on screen */
    rectangle(cleft, cright, cbottom, ctop);
 
   	/* Draw Bar on screen */
	//    bar(150, 200, 400, 350);
 
    getch();
    closegraph();
}
void makeLineplusColor(){
	cout << "LINE WITH COLOR" << endl;
	int xmin, ymin, xmax, ymax, rgb;
   	cout <<"\nEnter xmin: ";
   	cin >> xmin;
   	cout <<"Enter ymin: ";
   	cin >> ymin;
   	cout <<"Enter xmax: ";
	cin >> xmax;
   	cout <<"Enter ymax: ";
   	cin >> ymax;
   	colorChoice();
   	do{
   		cout << "\nEnter RGB value: ";
		cin >> rgb;
		if(rgb < 0 || rgb > 15){
			cout << "Color out of choice!" << endl;
		}
	}while(rgb < 0 || rgb > 15);
   	initwindow(500, 500);
   	setcolor(rgb);
	line(xmin, ymin, xmax,ymax);
    getch();
    closegraph();
}
void makeLineplusHalfColor(){
	cout << "Two-colored Line" << endl;
	int xmin, ymin, xmax, ymax, rgbval1, rgbval2;
   	cout <<"\nEnter xmin: ";
   	cin >> xmin;
   	cout <<"Enter ymin: ";
   	cin >> ymin;
   	cout <<"Enter xmax: ";
	cin >> xmax;
   	cout <<"Enter ymax: ";
   	cin >> ymax;
   	colorChoice();
   	
   	do{
   		cout << "\nEnter 1st RGB value: ";
		cin >> rgbval1;
		if(rgbval1 < 0 || rgbval1> 15){
			cout << "Color out of choice!" << endl;
		}
	}while(rgbval1 < 0 || rgbval1 > 15);
	do{
   		cout << "\nEnter 2nd RGB value: ";
		cin >> rgbval2;
		if(rgbval2 < 0 || rgbval2 > 15){
			cout << "Color out of choice!" << endl;
		}
	}while(rgbval2 < 0 || rgbval2 > 15);
	initwindow(500, 500);
	line(xmin, ymin, abs((xmin + xmax)/2), abs((ymin + ymax)/2));
	setcolor(rgbval1);
	line(abs((xmin + xmax)/2), abs((ymin + ymax)/2), xmax, ymax);
	setcolor(rgbval2);
    getch();
    closegraph();
}
void makeRectplusRound(){
	int gd = DETECT, gm;
    int xmin, ymin, xmax, ymax, partial = 4;

    cout<<"\nInput xmin: ";
    cin>>xmin;
    cout<<"Input ymin: ";
    cin>>ymin;
    cout<<"Input xmax: ";
    cin>>xmax;
    cout<<"Input ymax: ";
    cin>>ymax;

    int radp = ((xmax - xmin)/partial);
    int x1 = xmin + radp;
    int y1 = ymin + radp;
    int x2 = xmax - radp;
    int y2 = ymax - radp;


    initgraph(&gd, &gm, "C:\\TC\\BGI");

    ellipse(x1, y1, 90, 180, radp, radp);
    line(x1, ymin, x2, ymin);
    ellipse(x2, y1, 0, 90, radp, radp);
    line(xmin, y1, xmin, y2);
    ellipse(x1, y2, 180, 270, radp, radp);
    line(xmax, y1, xmax, y2);
    ellipse(x2, y2, 270, 360, radp, radp);
    line(x1, ymax, x2, ymax);

    getch();
    closegraph();
}
void makeOval(){
	cout << "Make an OVAL" << endl; //vertical if r2 is greater, otherwise horizontal
	int x, y, r1, r2, angle1 = 0, angle2 = 360;
	cout <<"\nEnter x-coordinate: ";
   	cin >> x;
   	cout <<"Enter y-coordinate: ";
   	cin >> y;
   	cout <<"Enter radius1: ";
	cin >> r1;
   	cout <<"Enter radius2: "; 
   	cin >> r2;
	int gd = DETECT, gm;
   	initgraph(&gd, &gm, "C:\\TC\\BGI");
   	ellipse(x, y, angle1, angle2, r1, r2);
   	getch();
   	closegraph();
}
void makePolygon(){
	int gd = DETECT, gm;
	int side = 0, rad= 100, angle, xline, yline;
	int xstart = 0, xcurr = 0, ystart = 0, ycurr= 0;
	cout << "POLYGON (with variation)" << endl;	
	cout << "\nEnter number of sides: ";
	cin >> side;
	cout << "Enter x-coordinate: ";
	cin >> xline;
	cout << "Enter y-coordinate: ";
	cin >> yline;
	
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	for (int i = 1; i <= side; i++){
		angle =  i * ((2*3.14159265)/side);
		xline = 250 + rad * cos(angle);			
		yline = 250 + rad * sin(angle);
		if(i==1){
			xstart = xline;
			xcurr = xline;
			ystart = yline;
			ycurr = yline;
		}else{
			line(xstart, ystart, xline, yline);
			xstart = xline;
			ystart = yline;
		}
	}  		
	line(xstart, ystart, xcurr, ycurr);
	xstart = xcurr;
	ystart = ycurr;
	getch();
	closegraph();
}
void makeBezierCurve(){
	int gd = DETECT, gm, index = 6;
	double t;
	int a[index], b[index], i;
	for (int i=0; i<index; i++){
		cout<<"Enter for a: ";
		cin>>a[i];
		cout<<"Enter for b: ";
		cin>>b[i];	
	}	
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	for (t = 0.0; t < 1.0; t += 0.0005){
		double xt = pow (1-t, 3) * a[0] + 3 * t * pow (1-t, 2) * a[1] + 3 * pow (t, 2) * (1-t) * a[2] + pow (t, 3) * a[3];
		double yt = pow (1-t, 3) * b[0] + 3 * t * pow (1-t, 2) * b[1] + 3 * pow (t, 2) * (1-t) * b[2] + pow (t, 3) * b[3];
		putpixel (xt, yt, WHITE);
	}
//	for (int i=0; i<4; i++){
//		putpixel (b[i], b[i], YELLOW);
//	}
	getch();
	closegraph();
}
void colorChoice(){
	cout << "\nColor choices:" << endl;
   	cout << "[0] -> Black   \t   [8] -> Dark gray" << endl;
   	cout << "[1] -> Blue   \t   [9] -> Light blue" << endl;
   	cout << "[2] -> Green   \t   [10]-> Light green" << endl;
   	cout << "[3] -> Cyan   \t   [11]-> Light cyan" << endl;
   	cout << "[4] -> Red   \t   [12]-> Light red" << endl;
   	cout << "[5] -> Magenta     [13]-> Light Magenta" << endl;
   	cout << "[6] -> Brown   \t   [14]-> Yellow" << endl;
   	cout << "[7] -> Light gray  [15]-> White" << endl;
}
