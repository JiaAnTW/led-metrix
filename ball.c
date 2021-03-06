#include"ball.h"

void Delay(unsigned int secs) 
{
	unsigned int retTime = time(0) + secs;   
	while (time(0) < retTime);               
}

void move_ball(void)
{
	int x_direct;
	int y_direct;
	int i;

	if(ball_x > ball_last_x)//determine direction
		x_direct = 1;//right
	else
		x_direct = 0;//left
	if(ball_y > ball_last_y)
		y_direct = 1;//down
	else
		y_direct = 0;//up

	if(x_direct == 1)//move
	{
		(ball_x)++;
		(ball_last_x)++;
	}
	if(x_direct == 0)
	{
		(ball_x)--;
		(ball_last_x)--;
	}
    if(y_direct == 1)
    {
        (ball_y)++;
        (ball_last_y)++;
    }
    if(y_direct == 0)
    {
        (ball_y)--;
        (ball_last_y)--;
    }

	if(ball_y<0)
		ball_y = 1;
	if(ball_y>15)
		ball_y = 14;

	int rebound = 0;
	if(ball_x == 0)
	{
		if(left_board[ball_last_y] == 1)
			rebound = 1;
		if(rebound == 1)
		{
			//printf("rebound\n");
			ball_x = 2;
			ball_last_x = 1;
		}
	}
	if(ball_x == 15)
    {
        if(right_board[*ball_last_y] == 1)
            rebound = 1;
        if(rebound == 1)
        {
			//printf("rebound\n");
            ball_x = 13;
            ball_last_x = 14;
		}
    }
    if(ball_y<0)
        ball_y = 1;
    if(ball_y>15)
        ball_y = 14;
}

void initial(void)
{
    int k;
	for(k=0;k<16;k++)
	{
		LED[k][0] = left_board[k];
		LED[k][15] = right_board[k];
		LED[ball_y][ball_x]=1;
	}
}
void ball(void)
{
	int i,j;

	/*for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		{
			printf("%2d",LED[i][j]);
		}
		printf("\n");
	}*/
	//while(1)
	//{
        
	move_ball();
	for(i=0;i<16;i++)
	{
		for(j=1;j<15;j++)
			LED[i][j] = 0;
	}
	LED[ball_y][ball_x] = 1;
	//printf("\n");
	/*for(i=0;i<16;i++)
       {
    	for(j=0;j<16;j++)
       {
        	printf("%2d",LED[i][j]);
       }
       printf("\n");
       }*/
	//printf("\n");
}
void board(void)
{
    int i;
    int left_up,left_down,right_up,right_down;
    
	if(ball_x == 0 || ball_x == 15)//end
	{
		break;
	}
	if(left_up == 1)
	{
		if(left_board[0] != 1)
		{
			for(i=0;i<15;i++)
			{
				left_board[i] = left_board[i+1];
			}
		}	
	}
    if(left_down == 1)
    {
        if(left_board[15] != 1)
        {       
            for(i=15;i>0;i--)
            {
                left_board[i] = left_board[i-1];
            }
        }
    }
    if(right_up == 1)
    {
        if(right_board[0] != 1)
        {       
            for(i=0;i<15;i++)
            {
                right_board[i] = right_board[i+1];
            }
        }
    }
    if(right_up == 1)
    {
        if(right_board[0] != 1)
        {       
            for(i=15;i>0;i--)
            {
                right_board[i] = right_board[i-1];
            }
        }
    }
	//	Delay(1);
	//}
}
