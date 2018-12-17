/*yay its pong! the ultimate vintage game thingy! except it's 3D
By Daniel Gross,	Last edit: 10/13/09*/
#include<common.h>

class Threedim
{
	private:
		int m_x;
		int m_y;
		int m_z;
		int m_score;
	public:
		void setX(int x)	{m_x=x;}
		void setY(int y)	{m_y=y;}
		void setZ(int z)	{m_z=z;}
		void setScore(int s)	{m_score=s;}
		int getX()	{return m_x;}
		int getY()	{return m_y;}
		int getZ()	{return m_z;}
		int getScore()	{return m_score;}
		void setpos(int x,int y,int z)
		{
			m_x=x;
			m_y=y;
			m_z=z;
		}
		void setcol(int outcol,int sty)
		{
			setcolor(outcol);
			setfillstyle(sty,outcol);
		}
		void drawcir(int fltp)
		{
			setcol(4,fltp);
			int rad=((400-m_z)/10);
			circle(m_x,m_y,rad);
			floodfill(m_x,m_y,getcolor());
		}
		void drawpol(int fltp,int s)
		{
			setcol(15,fltp);
			int poly[10];
			poly[0]=m_x;
			poly[1]=m_y;
			poly[2]=m_x+s;
			poly[3]=m_y;
			poly[4]=m_x+s;
			poly[5]=m_y+s;
			poly[6]=m_x;
			poly[7]=m_y+s;
			poly[8]=poly[0];
			poly[9]=poly[1];
			fillpoly(5,poly);
		}
		void bchnpos(int x,int y,int z)
		{
			m_x+=x;
			m_y+=y;
			m_z+=z;
		}
		void incx(int x)
		{
			m_x+=x;
		}
		void decx(int x)
		{
			m_x-=x;
		}
		void incy(int y)
		{
			m_y+=y;
		}
		void decy(int y)
		{
			m_y-=y;
		}
};

void ginit()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "");
}

void threed()
{
	//begin init
	ginit();
	char pres;
	int maxx=getmaxx();
	int maxy=getmaxy();
	Threedim human;
	human.setScore(0);
	Threedim ai;
	ai.setScore(0);
	Threedim ball;
	int m[3];
	const int incre=5;
	const int dely=75;
	int lose=0;
	//end init
	do{
		m[0]=incre;
		m[1]=incre;
		m[2]=incre;
		human.setpos(maxx/2,maxy/2,0);
		ai.setpos((maxx/2)-100,maxy/2,370);
		ball.setpos(maxx/2,maxy/2,185);
		lose=0;
		do{
			do{
				cleardevice();
					//look for human move from key pressed
				if(((pres=='4')||(pres=='7')||(pres=='1'))&&(human.getX()>1))
				{
					human.decx(2*incre);
				}
				if(((pres=='6')||(pres=='9')||(pres=='3'))&&(human.getX()<maxx-101))
				{
					human.incx(2*incre);
				}
				if(((pres=='2')||(pres=='1')||(pres=='3'))&&(human.getY()<maxy-101))
				{
					human.incy(2*incre);
				}
				if(((pres=='8')||(pres=='7')||(pres=='9'))&&(human.getY()>1))
				{
					human.decy(2*incre);
				}
					//ball movement
				ball.bchnpos(m[0],m[1],m[2]);
				if((ball.getX()<=19)||(ball.getX()>=maxx-19))	//left-right
				{
					m[0]=-1*m[0];
				}
				if((ball.getY()<=19)||(ball.getY()>=maxy-19))	//up-down
				{
					m[1]=-1*m[1];
				}
				if(ball.getZ()>=351)
				{
					if((ball.getX()<=ai.getX()+10)&&(ball.getY()>=ai.getY())&&(ball.getY()<=human.getY()+10))	//depth
					{
						m[2]=-1*m[2];
					}
					else
					{
						lose=-1;
					}
				}
				if(ball.getZ()<=19)
				{	//if the paddle is above the ball
					if((ball.getX()>=human.getX())&&(ball.getX()<=human.getX()+100)&&(ball.getY()>=human.getY())&&(ball.getY()<=human.getY()+100))
					{
						m[2]=-1*m[2];
					}
					else
					{
						lose=1;
					}
				}
					//ai
				ai.setX(ball.getX()-5);
				ai.setY(ball.getY()-5);
					//drawing
				ai.drawpol(1,10);
				ball.drawcir(2);
				human.drawpol(1,100);
					//end drawing
				delay(dely);
			}while((!kbhit())&&(lose==0));
			if(lose==0)
			{
				pres=getche();
			}
		}while((lose==0)&&(pres!='q'));
		if(lose==1)
		{
			ai.setScore(ai.getScore()+1);
		}
		if(lose==-1)
		{
			human.setScore(human.getScore()+1);
		}
		if(pres!='q')
		{
			gotoxy(35,20);
			cout<<"Your score:  "<<human.getScore()<<endl;
			gotoxy(35,21);
			cout<<"Comp score:  "<<ai.getScore()<<endl;
			pres=getche();
		}
	}while(pres!='q');
	closegraph();
	clrscr();
	gotoxy(35,20);
	cout<<"Your score:  "<<human.getScore()<<endl;
	gotoxy(35,21);
	cout<<"Comp score:  "<<ai.getScore()<<endl;
	getch();
}

class Twodim
{
	private:
		int m_x;
		int m_y;
		int m_score;
	public:
		void setX(int x)	{m_x=x;}
		void setY(int y)	{m_y=y;}
		void setScore(int s)	{m_score=s;}
		int getX()	{return m_x;}
		int getY()	{return m_y;}
		int getScore()	{return m_score;}
		void decy(int y)
		{
			m_y-=y;
		}
		void incy(int y)
		{
			m_y+=y;
		}
		void bchnpos(int x,int y)
		{
			m_x+=x;
			m_y+=y;
		}
		void setcol(int outcol,int sty)
		{
			setcolor(outcol);
			setfillstyle(sty,outcol);
		}
		void drawcir(int fltp)
		{
			setcol(15,fltp);
			circle(m_x,m_y,10);
			floodfill(m_x,m_y,getcolor());
		}
		void drawpol()
		{
			setcol(15,1);
			int poly[6];
			poly[0]=m_x;
			poly[1]=m_y;
			poly[2]=m_x;
			poly[3]=m_y+50;
			poly[4]=poly[0];
			poly[5]=poly[1];
			fillpoly(3,poly);
		}
};

void twod()
{
	ginit();
	char pres;
	int maxx=getmaxx();
	int maxy=getmaxy();
	Twodim human;
	human.setScore(0);
	Twodim ai;
	ai.setScore(0);
	Twodim ball;
	int m[2];
	const int dely=50;
	const int incre=15;
	int lose=0;
	do{
		human.setX(1);
		human.setY((maxy/2)-25);
		ai.setX(maxx);
		ai.setY((maxy/2)-25);
		ball.setX(maxx/2);
		ball.setY(maxy/2);
		m[0]=incre;
		m[1]=incre;
		lose=0;
		do{
			do{
				cleardevice();
					//look for human move from key pressed
				if((pres=='P')&&(human.getY()<maxy-incre-50))
				{
					human.incy(incre);
				}
				if((pres=='H')&&(human.getY()>incre))
				{
					human.decy(incre);
				}
					//ball movement
				ball.bchnpos(m[0],m[1]);
				if((ball.getY()<=10)||(ball.getY()>=maxy-10))
				{	//switch ball up/down action
					m[1]=-1*m[1];
				}
				if(ball.getX()<=10)
				{	//if ball is near human player (left side)
					if((human.getY()<=ball.getY())&&(human.getY()+50>=ball.getY()))
					{	//switch x axis l/r
						m[0]=-1*m[0];
					}
					else
					{	//human player loses
						lose=1;
					}
				}
				if(ball.getX()>=maxx-10)
				{	//right side of screen
					if((ai.getY()<=ball.getY())&&(ai.getY()+50>=ball.getY()))
					{	//switch x axis movement
						m[0]=-1*m[0];
					}
					else
					{	//computer player loses
						lose=-1;
					}
				}
					//ai
				ai.setY(ball.getY()-25);
				if(ai.getY()<1)
				{
					ai.setY(1);
				}
				if(ai.getY()>maxy-50)
				{
					ai.setY(maxy-50);
				}
					//drawing
				ai.drawpol();
				ball.drawcir(1);
				human.drawpol();
					//end drawing
				delay(dely);
			}while((!kbhit())&&(lose==0));
			if(lose==0)
			{	//get key press from keyboard
				pres=getche();
			}
		}while((lose==0)&&(pres!='q'));
		if(lose==1)
		{
			ai.setScore(ai.getScore()+1);
		}
		if(lose==-1)
		{
			human.setScore(human.getScore()+1);
		}
		if(pres!='q')
		{
			gotoxy(35,20);
			cout<<"Your score:  "<<human.getScore()<<endl;
			gotoxy(35,21);
			cout<<"Comp score:  "<<ai.getScore()<<endl;
			pres=getche();
		}
	}while(pres!='q');
	closegraph();
	clrscr();
	gotoxy(35,20);
	cout<<"Your score:  "<<human.getScore()<<endl;
	gotoxy(35,21);
	cout<<"Comp score:  "<<ai.getScore()<<endl;
	getch();
}

void main()
{
	clrscr();
	cout<<"Pong!"<<endl
			<<" 2 dimensional game play"<<endl
			<<" 3 dimensional game play"<<endl
			<<"(Press spacebar to select)";
	int select=1;
	char test;
	do
	{
		gotoxy(1,select+1);
		cout<<">";
		gotoxy(3,25);
		test=getche();
		gotoxy(3,25);
		cout<<" ";
		gotoxy(1,select+1);
		cout<<" ";
		if(test=='P')
		{
			select=2;
		}
		if(test=='H')
		{
			select=1;
		}
	}while(test!=' ');
	if(select==1)	//two dimensional
	{
		twod();
	}
	if(select==2)	//three dimensional
	{
		threed();
	}
}