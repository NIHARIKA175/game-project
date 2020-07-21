#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int i,j,cnt=0,m,n,sc=0,x=150,y=150;
int bomb[4][4]={0},disp[4][4]={0},score[4][4]={0};
char *ch;
void placebomb()
{
bomb[0][0]=1;
bomb[1][2]=1;
bomb[2][1]=1;
bomb[3][3]=1;
}
void placescore()
{
score[0][1]=1;score[0][2]=2;score[0][3]=4;
score[1][0]=4;score[1][1]=1;score[1][3]=3;
score[2][0]=3;score[2][2]=1;score[2][3]=4;
score[3][0]=1;score[3][1]=2;score[3][2]=3;
}
void reinitiate()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
setbkcolor(BLACK);
}
void displaymat()
{
x=150;y=100;
for(i=0;i<4;i++){
for(j=0;j<4;j++){
sprintf(ch,"%d",disp[i][j]);
setfillstyle(SOLID_FILL,LIGHTGREEN);
rectangle(x,y,x+30,y+30);
floodfill(x+1,y+1,WHITE);
if(disp[i][j]!=0)
setcolor(RED);
outtextxy(x+15,y+15,ch);
setcolor(WHITE);
x=x+30;
}
x=150;
y=y+30;
}
}
void displaybomb()
{
x=150,y=300;
for(i=0;i<4;i++){
for(j=0;j<4;j++){
sprintf(ch,"%d",bomb[i][j]);
setfillstyle(SOLID_FILL,LIGHTBLUE);
rectangle(x,y,x+30,y+30);
floodfill(x+1,y+1,WHITE);
if(bomb[i][j]!=0)
setcolor(RED);
outtextxy(x+15,y+15,ch);
setcolor(WHITE);
x=x+30;
}
x=150;
y=y+30;
}
}
void checkuser()
{
printf("\nenter the coordinates:");
scanf("%d%d",&m,&n);

if(disp[m][n]!=0){
printf("these coordinates are already entered");
delay(2000);
displaymat();
printf("SCORE:%d",sc);
checkuser();
}
else if(bomb[m][n]==1)
{
outtextxy(10,250,"YOU PRESSED A MINE!!\n GAMEOVER \n");
outtextxy(10,270,"Mine sweeper layout");
displaybomb();
}
else
{
cnt++;
sc=sc+score[m][n];
disp[m][n]=score[m][n];
cleardevice();
reinitiate();
displaymat();
printf("SCORE:%d",sc);
if(cnt<12)
checkuser();
else
printf("\nCONGO YOU WON THE GAME!");
}
}
void main()
{
int errcode;
reinitiate();
errcode=graphresult();
if(errcode!=grOk)
printf("graphics not initialized");
else
{
placebomb();
placescore();
displaymat();
checkuser();
}
getch();
}
