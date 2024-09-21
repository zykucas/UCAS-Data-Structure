#include<stdio.h>

int main(void)
{
	
	int x,y,z,t;	
	scanf("%d %d %d",&x,&y,&z);
	if(x<y)
	{
		t=x;
		x=y;
		y=t;
	} 
	if(y<z)
	{
		t=z;
		z=y;
		y=t;
		if(x>t)
		{
			y=t;
		}
		else
		{
			y=x;
			x=t;
		}
	}
	printf("%d %d %d",x,y,z);
	return 0; 
 } 
