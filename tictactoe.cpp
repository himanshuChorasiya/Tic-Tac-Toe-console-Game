#include<iostream>
using namespace std;

char turn = 'X';

void display(char tic[3][3]){
	
	system("cls");//clear screen;
	
	cout<<"\n\n\t!!*********************************@...Tic Tac Toe...@***********************************!!\n\n\n";
	cout<<"\tPlayer[1] = X"<<endl;
	cout<<"\tPlayer[2] = O"<<endl;
	cout<<"\n\tGame Starts Now Select between 1 to 9 as index : \n"<<endl;
	
	cout<<"\t\t\t\t\t      |       |      "<<endl;
	cout<<"\t\t\t\t\t   "<<tic[0][0]<<"  |   "<<tic[0][1]<<"   |  "<<tic[0][2]<<"   "<<endl;
	cout<<"\t\t\t\t\t______|_______|______"<<endl;
	cout<<"\t\t\t\t\t      |       |      "<<endl;
    cout<<"\t\t\t\t\t   "<<tic[1][0]<<"  |   "<<tic[1][1]<<"   |  "<<tic[1][2]<<"   "<<endl;
	cout<<"\t\t\t\t\t______|_______|______"<<endl;
	cout<<"\t\t\t\t\t      |       |      "<<endl;
	cout<<"\t\t\t\t\t   "<<tic[2][0]<<"  |   "<<tic[2][1]<<"   |  "<<tic[2][2]<<"   "<<endl;
	cout<<"\t\t\t\t\t      |       |      "<<endl;
	
}

void play_Game(char tic[3][3]){//fill value in the board;
	
	int choice, row, column;	
	if(turn == 'X')
		cout<<"\n\n\t\tPlayer-1[X] Turn :";
	else
		cout<<"\n\n\t\tPlayer-2[O] Turn :";	
		
	cin>>choice;
	
	switch(choice){
		case 1:
			row = 0;
			column = 0;
			break;
		case 2:
			row = 0;
		    column = 1;
	        break;
		case 3:
			row = 0;
		    column = 2;
	        break;
		case 4:
			row = 1;
		    column = 0;
	        break;
		case 5:
	    	row = 1;
		    column = 1;
	        break;
		case 6:
			row = 1;
		    column = 2;
	        break;
		case 7:
			row = 2;
		    column = 0;
	        break;
		case 8:
		row = 2;
		    column = 1;
	        break;
		case 9:
			row = 2;
		    column = 2;
	        break;
		default:
			cout<<"\n\t\tPlease select correct Index\n"<<endl;								
	}
	if(turn == 'X' && tic[row][column] != 'X' && tic[row][column] != 'O'){
		tic[row][column] = 'X'; 
		turn  = 'O';
	}
	else if(turn == 'O' &&  tic[row][column] != 'X' && tic[row][column] != 'O'){
		tic[row][column] = 'O';	
		turn  = 'X';
	}
	else
		{
			cout<<"\n\t\tBox Already filled please try again...!";
			play_Game(tic);
		}
}

bool gameover(char tic[3][3]){
	
	//row win condition
	for(int i = 0; i < 3; i++){
		if(tic[i][0] == tic[i][1] && tic[i][0] == tic[i][2])
		{
			if(turn == 'O'){
				cout<<"\n\n\tPlayer[1] Win... Congratulations!!\n";
				return true;
			}
			else
				{
				 cout<<"\n\n\tPlayer[2] Win... Congratulations!!\n";
				 return true;
			   }
			   
		}
	}
	
	//colunm win condition
	for(int i = 0; i < 3; i++){
		if(tic[0][i] == tic[1][i] && tic[0][i] == tic[2][i])
		{
			if(turn == 'O'){
				cout<<"\n\n\tPlayer[1] Win... Congratulations!!\n";
				return true;
			}
			else
				{
				   cout<<"\n\n\tPlayer[2] Win... Congratulations!!\n";
				   return true;
				}
			   
		}
	}
	
	//diagonal win condition;
	if((tic[0][0] == tic[1][1] && tic[0][0] == tic[2][2]) || (tic[0][2] == tic[1][1] && tic[0][2] == tic[2][0])){
		if(turn == 'O'){
		  cout<<"\n\n\tPlayer[1] Win... Congratulations!!\n";
		  return true;	
		}
		else{
			cout<<"\n\n\tPlayer[2] Win... Congratulations!!\n";
			return true;
		}
	}
	
	//check all the box filled or not 
	for(int i = 0; i < 3; i++){
    	for(int j = 0; j < 3; j++){
    		if(tic[i][j] != 'X' || tic[i][j] != 'O')
    		  	return false;
		}
   }

    //Game tie condition;
	cout<<"\n\n\tGame Tie...!!";
	return true;	
}

int main(){
	
	char tic[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
	int choice = 0;
	display(tic);
	
	    //loop untill gameOver;
        while(1){
        	
        	display(tic);
        	play_Game(tic);
        	display(tic);
        	if(gameover(tic))
        	  break;

		}
	
	return 0;
}
