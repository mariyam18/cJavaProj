#include<stdio.h>
#include<graphics.h>


void boundary_fill(int x, int y, int fill_color,int boundary_color)
{
	if(getpixel(x,y)!=boundary_color && getpixel(x,y) != fill_color)
	{
		putpixel(x,y,fill_color);
		boundary_fill(x+1,y,fill_color,boundary_color);
		boundary_fill(x-1,y,fill_color,boundary_color);
		boundary_fill(x,y+1,fill_color,boundary_color);
		boundary_fill(x,y-1,fill_color,boundary_color);
	}
}


int main()
{
	int gm,gd=DETECT;
   initgraph(&gd,&gm,NULL);
 //  setcolor(2);
    circle(100,50,20);
	boundary_fill(100,50,4,15);
	getch();
	return 0;
}
