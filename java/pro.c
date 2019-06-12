
#include<stdio.h>
#include<graphics.h>
void displayMan(int x,int y)
{
    circle(x,y,10);         //face
    line(x,y+10,x,y+30);        //neck
    line(x,y+30,x-20,y+40);    //left hand
    line(x,y+30,x+20,y+40);    //right hand
    line(x+20,y+40,x+30,y+30);			//holding
    line(x,y+30,x,y+80);        //body
    line(x+30,y+30,x+30,y-40);  //umbrella line
    pieslice(x+30,y-40,180,360,55);  //umbrella upper     
 
}
 
 
void main()
{
    int gd=DETECT, gm,i,d=0,x=50,y=340,shouldMove=1;
    int rx,ry;
    initgraph(&gd,&gm,"C:\\tc\\bgi");
 
    while(!kbhit())
    {
        cleardevice();
        displayMan(x,340);
        line(0,450,639,450);
         
for(i=0;i<500;i++)
        {
            rx=rand()%639;
            ry=rand()%439;
            if(rx>=(x-40)&&rx<=(x+110))
                if(ry>=(y-50)&&ry<=479)
                    continue;
            line(rx,ry,rx,ry+10);
        }
 
        //legs
        if(shouldMove)
        {
            if(d<20)
                d+=4;
            else
                shouldMove=0;
            line(x,y+80,x-d,y+110);
            line(x,y+80,x+d,y+110);
        }
        else
        {
            if(d>0)
                d-=4;
            else
                shouldMove=1;
            line(x,y+80,x-d,y+110);
            line(x,y+80,x+d,y+110);
        }
        delay(50);
        x=(x+10)%639;
    }
    getch();

}
