#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct gameData{
    char row1_col1;
    char row1_col2;
    char row1_col3;
    char row2_col1;
    char row2_col2;
    char row2_col3;
    char row3_col1;
    char row3_col2;
    char row3_col3;
    int player_change;
    int plyaer_changeVariable;
    char* pos_arr[9];
    int player_chossen_choice;

    int playerScore;
    int aiScore;
    int run;

}gDt;
void game_init(gDt* game);//initializes a struct game of type gDt
void gridRender(gDt* game);//renders the playing field for the tic tac toe
void gameLoop(gDt* game);//main gameloop for the game
void menu();//render the menu 
int playerInput(gDt* game);
int userInp();
int game_logic(gDt* game);
void gameReset(gDt* game);
int restrict_user_input(gDt* game,int index);//restrict user input if in a box if there already is a input
// int aiInput(gDt* game);

int main(){
    
    gDt* game=(gDt*)malloc(sizeof(gDt));
    game_init(game);
    gameLoop(game);

    free(game);
    return 0;
}
void gridRender(gDt* game){
    printf("   %c  ||  %c  ||  %c  \n",game->row1_col1,game->row1_col2,game->row1_col3 );
    printf("======||=====||======\n");
    printf("   %c  ||  %c  ||  %c  \n",game->row2_col1,game->row2_col2,game->row2_col3);
    printf("======||=====||======\n");
    printf("   %c  ||  %c  ||  %c  \n",game->row3_col1,game->row3_col2,game->row3_col3);

    printf("Player 1 =  %d    :    %d =  Player 2\n",game->playerScore,game->aiScore);
}
void game_init(gDt* game){
    game->run=1;
    game->aiScore=0;
    game->playerScore=0;
    game->row1_col1=' ';
    game->row1_col2=' ';
    game->row1_col3=' ';
    game->row2_col1=' ';
    game->row2_col2=' ';
    game->row2_col3=' ';
    game->row3_col1=' ';
    game->row3_col2=' ';
    game->row3_col3=' ';
    game->player_change=0;
    game->plyaer_changeVariable=game->player_change%2;
  game->pos_arr[0]=&game->row1_col1;
  game->pos_arr[1]=&game->row1_col2;
  game->pos_arr[2]=&game->row1_col3;
  game->pos_arr[3]=&game->row2_col1;
  game->pos_arr[4]=&game->row2_col2;
  game->pos_arr[5]=&game->row2_col3;
  game->pos_arr[6]=&game->row3_col1;
  game->pos_arr[7]=&game->row3_col2;
  game->pos_arr[8]=&game->row3_col3;
  game->player_chossen_choice=0;
}
void gameLoop(gDt* game){
    while(game->run){
        menu();
        gridRender(game);
        int choice=userInp();
        if(choice==1){
            game->run=0;
            break;
        }
        if(choice==2){
            
        }
        playerInput(game);
        game_logic(game);
        
        
    }
}
void menu(){
    printf("===========================================\n");
    printf("                 TIC TAC TOE               \n");
    printf("===========================================\n");

}
int userInp(){
    int choice;
    printf("1.EXIT\n");
    printf("2.CONTINUE\n");
    printf("Your Choice :");
    scanf(" %d",&choice);
    return choice;
}
void rule(){
    printf("press 1-9 to choose which block to place your choice :");
    printf("numbering is happening from left top to right top(1-3),left middle to right middle(4-6) and so on");
}
int gameInput(gDt* game){

}
int playerInput(gDt* game){
    int player_input;
    int input_choice;
    char inp;
    while(1){
    printf("1.X\n");
    printf("2.O\n");
    printf("Your choice :");
    
    while(1){
        if(scanf(" %d",&input_choice)==1){
            if(game->player_chossen_choice==input_choice||game->player_chossen_choice==0){
            break;
        }
    }
        
        while(1){
            if(getchar()=='\n'){
                break;
            }
        }
        
    }

    
    if(input_choice==1){
      inp='X';
        game->player_chossen_choice=2;
      break;
    }else if(input_choice==2){
        inp='O';
        game->player_chossen_choice=1;
        break;
    }else{
        printf("invalid input!!");
        continue;
    }
}do{
    printf("Make your move :");
    scanf(" %d",&player_input);
}while(!restrict_user_input(game,player_input));

    int valid_choices[9]={1,2,3,4,5,6,7,8,9};
    int isValid=0;
    for(int i=0;i<9;i++){
        if(player_input==valid_choices[i]){
            isValid=1;
        }
    }
    if(isValid){
    switch(player_input){
        case 1:
        game->row1_col1=inp;
        break;
        case 2:
        game->row1_col2=inp;
        break;
        case 3:
        game->row1_col3=inp;
        break;
        case 4:
        game->row2_col1=inp;
        break;
        case 5:
        game->row2_col2=inp;
        break;
        case 6:
        game->row2_col3=inp;
        break;
        case 7:
        game->row3_col1=inp;
        break;
        case 8:
        game->row3_col2=inp;
        break;
        case 9:
        game->row3_col3=inp;
        break;
    }
}
game->player_change++;


}


int aiInput(gDt* game){
    char ai_choice;
    srand(time(NULL));
    int random=(rand()%9)+1;
    int random_C=(rand()%2)+1;
    if(random_C==1){
        ai_choice='X';
        

    }else if(random_C==2){
        ai_choice='O';
    }
    switch(random){
           case 1:
        game->row1_col1=ai_choice;
        break;
        case 2:
        game->row1_col2=ai_choice;
        
        break;
        case 3:
        game->row1_col3=ai_choice;
        break;
        case 4:
        game->row2_col1=ai_choice;
        break;
        case 5:
        game->row2_col2=ai_choice;
        break;
        case 6:
        game->row2_col3=ai_choice;
        break;
        case 7:
        game->row3_col1=ai_choice;
        break;
        case 8:
        game->row3_col2=ai_choice;
        break;
        case 9:
        game->row3_col3=ai_choice;
        break;

    }
    return 1;//As of success


}
int stateCheck(gDt* game){

}
int pos_state(gDt* game){

}
int restrict_user_input(gDt* game,int index){
char* new=game->pos_arr[index-1];
if(*new==' '){
    return 1;
}
return 0;

}
int game_logic(gDt* game){
    int winCombination[8][3]={{0,1,2},{0,4,8},{0,3,6},{1,4,7},{2,5,8},{2,4,6},{3,4,5},{6,7,8}};
    char* ind_1;
    char* ind_2;
    char* ind_3;
    for(int i=0;i<8;i++){
        ind_1=game->pos_arr[winCombination[i][0]];
        ind_2=game->pos_arr[winCombination[i][1]];
        ind_3=game->pos_arr[winCombination[i][2]];
        
        if(*ind_1==*(ind_2)&& *ind_2== *ind_3&& *ind_1!=' '&& *ind_2!=' '&& *ind_3!=' '){
            printf("======================================\n");
            printf("                 GAME OVER            \n");
            printf("======================================\n");
            // game->run=0;
            if(game->plyaer_changeVariable==0){
                printf("        PLAYER 1 WINS SET           \n");
                game->playerScore++;
            }else if(game->plyaer_changeVariable==1){
                printf("        PLAYER 2 WINS SET           \n");
                game->aiScore++;
            }
            gameReset(game);
            break;

        }
    }

}
void playerDecider(gDt* game){
    if(game->plyaer_changeVariable==0){

    }

}
void gameReset(gDt* game){
        game->row1_col1=' ';
    game->row1_col2=' ';
    game->row1_col3=' ';
    game->row2_col1=' ';
    game->row2_col2=' ';
    game->row2_col3=' ';
    game->row3_col1=' ';
    game->row3_col2=' ';
    game->row3_col3=' ';
    game->player_chossen_choice=0;
    game->player_change=0;

}