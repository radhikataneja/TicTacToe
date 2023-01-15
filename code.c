#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

char square[10]={'o','1','2','3','4','5','6','7','8','9'};

int checkWinner()
{
    if(square[1] == square[2] && square[2] == square[3])
        return 1;
    else if(square[4] == square[5] && square[5] == square[6])
        return 1;
    else if(square[7] == square[8] && square[8] == square[9])
        return 1;
    else if(square[1] == square[4] && square[4] == square[7])
        return 1;
    else if(square[2] == square[5] && square[5] == square[8])
        return 1;
    else if(square[3] == square[6] && square[6] == square[9])
        return 1;
    else if(square[1] == square[5] && square[5] == square[9])
        return 1;
    else if(square[3] == square[5] && square[5] == square[7])
        return 1;
    else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] !='4' 
    && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0; //draw
    else
        return -1; //game is still ongoing
}

void drawBoard()
{
    system("cls");
    printf("\n\n\t Tic Tac Toe \n\n");
	printf("Player1 (X) - Player2 (O) \n\n\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",square[1],square[2],square[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",square[4],square[5],square[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",square[7],square[8],square[9]);
	printf("     |     |     \n");	
}

int main()
{
    int player=1;
    int i,choice;
    char symbol; //X or O
    do
    {
       drawBoard();
       player=(player%2)?1:2; //if player%2 is 1, returns true
       printf("Player %d, enter your choice for the position: \n",player);
       scanf("%d",&choice);
       symbol=(player==1)?'X':'O';
       if(choice==1 && square[1]=='1') //if 1st position in square has 1 it means it is vacant
            square[1]=symbol;
       else if(choice==2 && square[2]=='2')
            square[2]=symbol;
       else if(choice==3 && square[3]=='3')
            square[3]=symbol;
       else if(choice==4 && square[4]=='4')
            square[4]=symbol;
       else if(choice==5 && square[5]=='5')
            square[5]=symbol;
       else if(choice==6 && square[6]=='6')
            square[6]=symbol;
       else if(choice==7 && square[7]=='7')
            square[7]=symbol;
       else if(choice==8 && square[8]=='8')
            square[8]=symbol;
       else if(choice==9 && square[9]=='9')
            square[9]=symbol;  
       else
       {
           printf("Invalid!");
           player--;
           getch();
       }
       i=checkWinner();
       player++; /*if player 1 enters invalid choice, he gets another chance to enter option since player-- is done above
       else if player 1 enters all valid choices, it is incremented to player 2*/                 
    } while (i==-1);
    drawBoard();
    if(i==1)
    {
        printf("Winner is Player %d",--player);
    }
    else
    {
        printf("Draw");
        getch();
    }
    return 0;
}
