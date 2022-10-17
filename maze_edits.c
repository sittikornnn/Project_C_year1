#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define W 61
#define H 61
struct what{
	int wallx;
	int wally;
}w[1000];
int count=0;
char maze[W][H];
void setmaze();
void wall(int x,int y);
void show();
int main(){
	srand(time(NULL));
	setmaze();
	wall(1,1);
	maze[1][1] = 'O';
	maze[W-2][H-2] = 'X';
	show();
	return 0;
}
void wall(int x,int y){
	//show();
	//system("pause");
	//printf("x=%d,y=%d\n",x,y);
	if(maze[x+2][y] == 't'){//mark point walk with A
		maze[x+2][y] = 'A';	
		w[count].wallx = x+2;
		w[count].wally = y;
		++count;
	}
	if(maze[x-2][y] == 't'){
		maze[x-2][y] = 'A';	
		w[count].wallx = x-2;
		w[count].wally = y;
		++count;
	}
	if(maze[x][y+2] == 't'){
		maze[x][y+2] = 'A';	
		w[count].wallx = x;
		w[count].wally = y+2;
		++count;	
	}
	if(maze[x][y-2] == 't'){
		maze[x][y-2] = 'A';	
		w[count].wallx = x;
		w[count].wally = y-2;
		++count;
	}
	int num,px,py;
	while(maze[x][y] == 'A' || maze[x+2][y] == 'A' || maze[x-2][y] == 'A' || maze[x][y+2] == 'A' || maze[x][y-2] == 'A'){//loop play until no A
	num = rand()%count;// random A position x and position y
	//printf("%d\n",num);
	px = w[num].wallx; //this is position x random of struct w(A)  
	py = w[num].wally; //this is position y random of struct w(A)  
	//printf("px = %d py = %d\n",px,py);
	int arrow;
	arrow = rand()%4; //random direction for build ' '
	if(arrow == 0){
		if(maze[px-2][py] ==' ' && maze[px][py] == 'A'){
		maze[px][py] = ' ';
		--px;
		maze[px][py] = ' ';
		++px;
		wall(px,py);
		}	
	}else if(arrow == 1){
		if(maze[px+2][py] ==' ' && maze[px][py] == 'A'){
		maze[px][py] = ' ';
		++px;
		maze[px][py] = ' ';
		--px;
		wall(px,py);
		}	
	}else if(arrow == 2){
		if(maze[px][py-2] ==' ' && maze[px][py] == 'A'){
		maze[px][py] = ' ';
		--py;
		maze[px][py] = ' ';
		++py;
		wall(px,py);
		}	
	}else{
		if(maze[px][py+2] ==' ' && maze[px][py] == 'A'){
		maze[px][py] = ' ';
		++py;
		maze[px][py] = ' ';
		--py;
		wall(px,py);
		}	
	}
}
}
void setmaze(){
	int i,j;
	for(i=0;i<W;i++){
		for(j=0;j<H;j++){
			maze[i][j] = 't';//build t
		}
	}
	for(i=0;i<W;i++){//build room
		maze[i][0] = '#';
		maze[i][H-1] = '#';
	}
	for(i=0;i<H;i++){//build wall
		maze[0][i] = '#';
		maze[W-1][i] = '#'; 
	}
	for(i=0;i<W;i+=2){//build wall
		for(j=0;j<H;j++){
			maze[i][j] = '#';
		}
	}
	for(i=1;i<W;i+=2){
		for(j=0;j<H;j+=2){
			maze[i][j] = '#';
		}
	}
	maze[1][1] = ' ';
}
void show(){
	int i,j;
	for(i=0;i<W;i++){
		for(j=0;j<H;j++){
			printf("%c",maze[i][j]);
		}
		printf("\n");
	}
}
