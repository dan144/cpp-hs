/*Checkers: You play checkers
By Daniel Gross,	Last edit: 12/10/09
 */
#include<common.h>
#include "J:\headers\piece.h"
#include "J:\headers\board.h"

void ginit()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "");
}

void setmenu(int &setd,int &fjump,int &imeth,int &achan,int &super,int &games)
{
	int command;
	do{
		clrscr();
		gotoxy(1,1);
		cout<<"Checkers v2.0 - Settings menu"<<endl;
		cout<<" 1 - Graphics level: ";
		switch(setd)
		{
			case 1:	cout<<"Low";	break;
			case 2:	cout<<"Moderate";	break;
			case 3:	cout<<"High";	break;
		}
		cout<<endl<<" 2 - Forced jump: ";
		switch(fjump)
		{
			case 0:	cout<<"Off";	break;
			case 1:	cout<<"On";	break;
		}
		cout<<endl<<" 3 - Method of input: ";
		switch(imeth)
		{
			case 1:	cout<<"Text input";	break;
			case 2:	cout<<"Visual input";	break;
		}
		cout<<endl<<" 4 - Chance of running animation: "<<achan<<endl;
		cout<<" 5 - Super checkers: ";
		switch(super)
		{
			case 0:	cout<<"Off";	break;
			case 1:	cout<<"On";	break;
		}
		cout<<endl<<" 6 - Type of game: ";
		switch(games)
		{
			case 1:	cout<<"8x8 2-player";	break;
			case 2:	cout<<"8x8 4-player";	break;
			case 3:	cout<<"14x14 4-player";	break;
			case 4:	cout<<"14x14 6-player";	break;
			case 5:	cout<<"14x14 8-player";	break;
		}
		cout<<endl<<" 7 - Quit"<<endl;
		cout<<"Command >>";
		cin>>command;
		if(command==1)
		{
			do{
				clrscr();
				gotoxy(1,1);
				cout<<"Checkers v2.0 - Settings menu - Graphics level"<<endl;
				cout<<"*:  Currently unavailable"<<endl;
				cout<<"Input new level for graphics (1-Low, 2-Moderate, 3-High) >>";
				cin>>setd;
			}while((setd<1)||(setd>3));
		}
		if(command==2)
		{
			do{
				clrscr();
				gotoxy(1,1);
				cout<<"Checkers v2.0 - Settings menu - Forced jump"<<endl;
				cout<<"Use forced jump (0-Off, 1-On) >>";
				cin>>fjump;
			}while((fjump<0)||(fjump>1));
		}
		if(command==3)
		{
			do{
				clrscr();
				gotoxy(1,1);
				cout<<"Checkers v2.0 - Settings menu - Input method"<<endl;
				cout<<"Method of input (1-Text, 2-Visual) >>";
				cin>>imeth;
			}while((imeth<1)||(imeth>2));
		}
		if(command==4)
		{
			do{
				clrscr();
				gotoxy(1,1);
				cout<<"Checkers v2.0 - Settings menu - Animation chance"<<endl;
				cout<<"Chance of running animation (0-100) >>";
				cin>>achan;
			}while((achan<0)||(achan>100));
		}
		if(command==5)
		{
			do{
				clrscr();
				gotoxy(1,1);
				cout<<"Checkers v2.0 - Settings menu - Super checkers"<<endl;
				cout<<"Enable super checkers	(0 - Off, 1 - On) >>";
				cin>>super;
			}while((super<0)||(super>1));
		}
		if(command==6)
		{
			do{
				clrscr();
				gotoxy(1,1);
				cout<<"Checekrs v2.0 - Settings menu - Type of checkers"<<endl;
				cout<<"Type of game (1-5) >>";
				cin>>games;
			}while((games<1)||(games>5));
		}
		if((games==2)||(games==4)||(games==5))
		{
			super=0;
		}
	}while(command!=7);
}

void main()
{
	randomize();
	int cmd=1;
	int optd=2;
	int fj=1;
	int inpmtd=2;
	int anchan=0;
	int sup=1;
	int gtype=2;
	do{
		clrscr();
		gotoxy(1,1);
		cout<<"Checkers v2.0"<<endl;
		cout<<" 1 - Play"<<endl;
		cout<<" 2 - Settings"<<endl;
		cout<<" 3 - Quit"<<endl;
		cout<<"Command >>";
		cin>>cmd;
		if(cmd==2)
		{
			setmenu(optd,fj,inpmtd,anchan,sup,gtype);
		}
	}while((cmd!=1)&&(cmd!=3));
	if(cmd==1)
	{
		if(optd!=1)
		{
			ginit();
		}
		Board mainb(gtype,sup);
		mainb.setopt(optd,fj,inpmtd,anchan);
		mainb.execute();
		if(optd!=1)
		{
			closegraph();
		}
	}
}