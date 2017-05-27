#include <graphics.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{ 
	int choice = 0;
	cout << "Choices:" << endl;
	cin >> choice;
	cout << choice << endl;
	
	switch(choice){
		case 1:{ //line
			//lineMaker();
			break;
		}
		case 2:{
			break;
		}
		case 3:{
			break;
		}
		case 4:{
			break;
		}
		case 5:{
			break;
		}
		case 6:{
			break;
		}
		case 7:{
			break;
		}
		case 8:{
			break;
		}
		case 9:{
			break;
		}
		default:{
			break;
		}
	}
	
	getch();
	
	while(!kbhit()){
		delay(200);s
	}
}
