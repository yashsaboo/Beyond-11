#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//char arr[9][3]={"0","0","0","0","0","0","0","0","0"};
int iarr[9]={0,0,0,0,0,0,0,0,0};//array to hold the values of the block w.r.t. its index
int high=1; // Max number in the whole grid
int flag1=0;
struct scoreCard
{
	char name[10];
	int score;
}highScore[5], newPlayer;

void home()
{
	int i=0;
	while(!kbhit())
	{
		if(i==14)
		i=0;
		setbkcolor(i);
		settextstyle(0,0,4);
		outtextxy(200,150,"BEYOND 11");
		delay(100);
		i++;
	}
	cleardevice();
	setbkcolor(BLACK);
}
int checkHighScore()
{
	int i, flag=0;
	FILE *fp;
	fp=fopen("mytextfile.txt","r");
	for(i=0;i<5;i++)
	{
		fscanf(fp,"%s %d",highScore[i].name, &highScore[i].score);
	}
	fclose(fp);
	//this just reads the text file and assigns the value to struct members
	//ok till here.
	for(i=0;i<5;i++)
	{
		if (newPlayer.score>=highScore[i].score)
		{
			char tempName[20];
			int tempScore, j;
			strcpy(tempName,highScore[i].name);
			tempScore=highScore[i].score;
			strcpy(highScore[i].name,newPlayer.name);
			highScore[i].score=newPlayer.score;
			for(j=i+1;j<5;j++)
			{
				char anothertempName[20];
				int anothertempScore;
				strcpy(anothertempName,highScore[j].name);
				anothertempScore=highScore[j].score;
				strcpy(highScore[j].name,tempName);
				highScore[j].score=tempScore;
				strcpy(tempName,anothertempName);
				tempScore=anothertempScore;
			}
			FILE *fp;
			fp=fopen("mytextfile.txt","w");
			for(j=0;j<5;j++)
			{
				fprintf(fp,"%s %d",highScore[j].name,highScore[j].score);
			}
			fclose(fp);
			flag=1;
			break;
		}
	}
	if(flag==0)
		return 0;
	else if(flag==1)
		return 1;
}
void displayHighScore()
{
	int i;
	char text1[20], text2[20], text3[20], text4[20], text5[20];
	FILE *fp;
	fp=fopen("mytextfile.txt","r");
	for(i=0;i<5;i++)
	{
		fscanf(fp,"%s %d",highScore[i].name, &highScore[i].score);
	}
	fclose(fp);
	setfillstyle(XHATCH_FILL, BLUE);
	bar(200,125,400,275);
	rectangle(200,125,400,275);
	settextstyle(0,0,2);

	outtextxy(205,140,"HALL OF FAME");
	settextstyle(0,0,1);
	sprintf(text1,"%s %d",highScore[0].name, highScore[0].score);
	outtextxy(255,170,text1);
	sprintf(text2,"%s %d",highScore[1].name, highScore[1].score);
	outtextxy(255,190,text2);
	sprintf(text3,"%s %d",highScore[2].name, highScore[2].score);
	outtextxy(255,210,text3);
	sprintf(text4,"%s %d",highScore[3].name, highScore[3].score);
	outtextxy(255,230,text4);
	sprintf(text5,"%s %d",highScore[4].name, highScore[4].score);
	outtextxy(255,250,text5);
}
void mainMenu()
{
	char msg[30];
	displayHighScore();
	getch();
	settextstyle(0,0,3);
	setcolor(GREEN);
	outtextxy(200,50,"MAIN MENU");
	settextstyle(0,0,1);
	setcolor(WHITE);
	outtextxy(190,350,"Press any key to start playing");
	getch();
	cleardevice();
	settextstyle(0,0,2);
	setcolor(BROWN);
	outtextxy(205,160,"Hello player!");
	outtextxy(200,200,"What's your name?");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t");
	scanf("%s",newPlayer.name);
	clrscr();
	cleardevice();
	sprintf(msg,"%s, Welcome to BEYOND 11",newPlayer.name);
	outtextxy(getmaxx()/2-200,getmaxy()/2,msg);
	delay(2000);
	clrscr();
	cleardevice();
}



void buildrectangle()//to build the rectangles for the grid
{
   //rectangle(l,t,r,b)
   int i;
   setfillstyle(WIDE_DOT_FILL,BROWN);
   bar(0,0,getmaxx(),getmaxy());
   setlinestyle(SOLID_LINE,0,1);
   setcolor(GREEN);
   i=iarr[0];
   setfillstyle(SOLID_FILL,i);
   bar(30, 40, 130, 140);
   i=iarr[1];
   setfillstyle(SOLID_FILL,i);
   bar(130, 40, 230, 140);
   i=iarr[2];
   setfillstyle(SOLID_FILL,i);
   bar(230, 40, 330, 140);
   i=iarr[3];
   setfillstyle(SOLID_FILL,i);
   bar(30, 140, 130, 240);
   i=iarr[4];
   setfillstyle(SOLID_FILL,i);
   bar(130, 140, 230, 240);
   i=iarr[5];
   setfillstyle(SOLID_FILL,i);
   bar(230, 140, 330, 240);
   i=iarr[6];
   setfillstyle(SOLID_FILL,i);
   bar(30, 240, 130, 340);
   i=iarr[7];
   setfillstyle(SOLID_FILL,i);
   bar(130, 240, 230, 340);
   i=iarr[8];
   setfillstyle(SOLID_FILL,i);
   bar(230, 240, 330, 340);
   //this
   rectangle(30, 40, 130, 140);
   rectangle(130, 40, 230, 140);
   rectangle(230, 40, 330, 140);
   rectangle(30, 140, 130, 240);
   rectangle(130, 140, 230, 240);
   rectangle(230, 140, 330, 240);
   rectangle(30, 240, 130, 340);
   rectangle(130, 240, 230, 340);
   rectangle(230, 240, 330, 340);
   setcolor(BLUE);
   setlinestyle(DOTTED_LINE,0,5);
   rectangle(30,40,330,340);
   setcolor(WHITE);
}

int isempty(int n1)//To check if the particular block is empty or not
{
	if(iarr[n1]==0)
	{
		return 0;//0 means it is empty
	}
	else
	{
		return 1;//1 means it i not empty
	}
}

int gameover()//To find if the grid is out of zeros, i.e. Out Of Moves
{
	int i, flag=0;
	for(i=0;i<9;i++)
	{
		if(iarr[i]==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		return 1;
	}
	else
		return 0;
}

int rand_int(int a,int b)//To generate random number between a and b
{
    //The basic function here is like (rand() % range)+ Lower_bound

    srand(time(0));
    if (a > b)
	return((rand() % (a-b+1)) + b);
    else if (b > a)
	return((rand() % (b-a+1)) + a);
    else
	return a;
}

void checkadj(int n1, int t, int x)//To compare the adjacent block value with inserted value of the user's block
{       //t refers to value inserted in the user's block
	//x refers to block number to compare with
	if(t==iarr[x])
	{       if(iarr[n1]==t)//to check if old vlue and adjacent value is same so that we dont increment it multiple times
		{
		iarr[n1]++;flag1=1;
		}
		newPlayer.score++;//increases score
		iarr[x]=0;//to make the adjacent block 0
	}
}

int algo(int n1)//Applying algorithm for the particular block, i.e. to compare it with all the adjacent block
{
	int t=iarr[n1];
	if(n1==0)//Block 0
	{
		checkadj(n1,t,1);
		checkadj(n1,t,4);
		checkadj(n1,t,3);
	}
	if(n1==2)//Block 2
	{
		checkadj(n1,t,1);
		checkadj(n1,t,4);
		checkadj(n1,t,5);
	}
	if(n1==6)
	{
		checkadj(n1,t,3);
		checkadj(n1,t,4);
		checkadj(n1,t,7);
	}
	if(n1==8)
	{
		checkadj(n1,t,4);
		checkadj(n1,t,5);
		checkadj(n1,t,7);
	}
	if(n1==1)
	{
		checkadj(n1,t,0);
		checkadj(n1,t,2);
		checkadj(n1,t,3);
		checkadj(n1,t,4);
		checkadj(n1,t,5);
	}
	if(n1==7)
	{
		checkadj(n1,t,3);
		checkadj(n1,t,4);
		checkadj(n1,t,5);
		checkadj(n1,t,6);
		checkadj(n1,t,8);
	}
	if(n1==3)
	{
		checkadj(n1,t,0);
		checkadj(n1,t,1);
		checkadj(n1,t,4);
		checkadj(n1,t,6);
		checkadj(n1,t,7);
	}
	if(n1==5)
	{
		checkadj(n1,t,1);
		checkadj(n1,t,2);
		checkadj(n1,t,4);
		checkadj(n1,t,7);
		checkadj(n1,t,8);
	}
	if(n1==4)
	{
		checkadj(n1,t,0);
		checkadj(n1,t,1);
		checkadj(n1,t,2);
		checkadj(n1,t,3);
		checkadj(n1,t,5);
		checkadj(n1,t,6);
		checkadj(n1,t,7);
		checkadj(n1,t,8);
	}
	//checks if there was any change of value after adding all the values in the adjacent boxes
	if(iarr[n1]==t)
	{
		return 0;//No change
	}
	else
	{
		return 1;//Change, so algo will run again
	}
}

int high1()// Claculates the highest number in the grid
{
	printf("\nThe array: ");
	int i1= 0; int max=0;
	for(i1=0;i1<9;i1++)
	{
		printf("%d",iarr[i1]);
		if(iarr[i1]>max)
		max=iarr[i1];
	}
	return max
	;
}
void printscore()//Prints Score
{       char msg[15];
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	sprintf(msg,"Score: %d",newPlayer.score*7);
	outtextxy(10,getmaxy()-116,msg);
}
void writetext()//Prints the number in each block
{
	int i=0;
	char ar[50];
	//for  the box numbers:
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	outtextxy(120,130,"0");
	outtextxy(220,130,"1");
	outtextxy(320,130,"2");
	outtextxy(120,230,"3");
	outtextxy(220,230,"4");
	outtextxy(320,230,"5");
	outtextxy(120,330,"6");
	outtextxy(220,330,"7");
	outtextxy(320,330,"8");
	//for the score in the boxes
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
		sprintf(ar,"%d",iarr[i++]);
		outtextxy(65,50,ar);
		sprintf(ar,"%d",iarr[i++]);
		outtextxy(165,50,ar);
		sprintf(ar,"%d",iarr[i++]);
		outtextxy(265,50,ar);
		sprintf(ar,"%d",iarr[i++]);
		outtextxy(65,150,ar);
		sprintf(ar,"%d",iarr[i++]);
		outtextxy(165,150,ar);
		sprintf(ar,"%d",iarr[i++]);
		outtextxy(265,150,ar);
		sprintf(ar,"%d",iarr[i++]);
		outtextxy(65,250,ar);
		sprintf(ar,"%d",iarr[i++]);
		outtextxy(165,250,ar);
		sprintf(ar,"%d",iarr[i++]);
		outtextxy(265,250,ar);
}

int perform(int n1, int n2)//Game Play is performed
{
	int algoagain=1;
	char msg[20];
	if(isempty(n1)==0)//Checks if empty
	{
		iarr[n1]=n2;//Stores the next value to the postioned block
		while(algoagain==1)
		{
			algoagain = algo(n1);//Performs algo
		}
		return 1;
	}

	else//If not empty then prints wrong input
	{
		setcolor(RED);
		settextstyle(0,0,3);
		outtextxy(30,getmaxy()-50,"Wrong Input");
		sound(600);
		setcolor(WHITE);
		delay(500);
		nosound();
		return 0;
	}

}

void main()
{
   newPlayer.score=0;//score of the player
   int gd = DETECT, gm, x, y, color,z; //angle = 0;
   struct arccoordstype a, b;
   initgraph(&gd, &gm, (char *)"C://turboc++//disk//turboc3//bgi//disk//turboc3//bgi");
   home();
   mainMenu();
   buildrectangle();
   writetext();
   int n=0; int r1=1 ,r2=1; int old1, new1;
   char message1[20],message2[20],message3[70], message4[20];
   int performed;
   while(n>=0)
   {
	   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	   printf("\n\n\n\n\n");
	   if(gameover()==1)
		{
			printf("\nGAME OVER.");
			printscore();
			newPlayer.score=newPlayer.score*7;
			z=checkHighScore();
			getch();
			if(z)
			{
				clrscr();
				cleardevice();
				settextstyle(5,HORIZ_DIR,4);
				outtextxy(getmaxx()/2-300,(getmaxy()/2-50),"Congratulations, and welcome to");
				settextstyle(0,HORIZ_DIR,3);
				outtextxy(getmaxx()/2-150,(getmaxy()/2+50),"THE HALL OF FAME!");
				settextstyle(0,0,1);
				getch();
				clrscr();
				cleardevice();

			}
			displayHighScore();
			getch();
			break;
		}
		else
		{
			settextstyle(SMALL_FONT, HORIZ_DIR, 5);
			sprintf(message1,"Next to next number: %d",r2);
			outtextxy(10,getmaxy()-140,message1);
			sprintf(message2,"Next number: %d",r1);
			outtextxy(10,getmaxy()-128,message2);
			sprintf(message3,"Enter the position where you want to enter the number");
			printscore();
			outtextxy(10,getmaxy()-104,message3);
			sprintf(message4,"(Enter a negative number to exit)");
			outtextxy(10,getmaxy()-92,message4);
			scanf("%d",&n);
			if(n>=0)
			{
			   performed=perform(n,r1);
			   if(performed==1)
			   {       clrscr();
				   cleardevice();
				   buildrectangle();
				   writetext();
				   r1=r2;
				   r2= rand_int(1,high);
				   high = high1();
				   if(flag1==1)
				   {
					sound(750);
					delay(250);
					nosound();
					flag1=0;
				   }
			   }
			   else if(performed==0) //in case of wrong input
			   {
				clrscr();
				cleardevice();
				buildrectangle();
				writetext();
			   }
			}
		}
   }
   getch();
   clrscr();
   closegraph();
}