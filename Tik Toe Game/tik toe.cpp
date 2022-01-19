#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='x';
int row,col;
bool draw=true;
void display_board()
{
     system("cls");
    cout<<"\n\t\t\t\t T I C  T O E  G A M E  "<<endl;
    cout<<"\n\n\tPlayer1 [x] "<<endl<<"\tPlayer2 [O] "<<endl<<endl;
    cout<<"\t\t\t\t     |     |     "<<endl;
    cout<<"\t\t\t\t "<<board[0][0]<<"   |  "<<board[0][1]<<"  |   "<<board[0][2]<<"  "<<endl;
    cout<<"\t\t\t\t_____|_____|_____"<<endl;
    cout<<"\t\t\t\t     |     |     "<<endl;
    cout<<"\t\t\t\t "<<board[1][0]<<"   |  "<<board[1][1]<<"  |   "<<board[1][2]<<"  "<<endl;
    cout<<"\t\t\t\t_____|_____|_____"<<endl;
    cout<<"\t\t\t\t     |     |     "<<endl;
    cout<<"\t\t\t\t "<<board[2][0]<<"   |  "<<board[2][1]<<"  |   "<<board[2][2]<<"  "<<endl;
    cout<<"\t\t\t\t     |     |     "<<endl;
}
void player_turn()
{
    int choice;
    if(turn=='x')
      cout<<"\n\n\t Player1 [x] turn:";
    if(turn=='O')
      cout<<"\n\n\t Player1 [O] turn:";
    cin>>choice;
    switch(choice)
    {
      case 1: row=0;col=0;break;
      case 2: row=0;col=1;break;
      case 3: row=0;col=2;break;
      case 4: row=1;col=0;break;
      case 5: row=1;col=1;break;
      case 6: row=1;col=2;break;
      case 7: row=2;col=0;break;
      case 8: row=2;col=1;break;
      case 9: row=2;col=2;break;
     default:
        cout<<"Invalid choice"<<endl;
    }
    if(turn=='x'&& board[row][col]!='x'&& board[row][col]!='O')
    {
        board[row][col]='x';
        turn='O';
    }
    else if(turn=='O'&& board[row][col]!='x'&& board[row][col]!='O')
    {
        board[row][col]='O';
        turn='x';
    }
    else
    {
        cout<<"Box already filled  try again"<<endl;
        cout<<"Try again"<<endl;
        player_turn();

    }
   display_board();
}
bool game_over()
{
    //check who win
    for( int i=0;i<3;i++)
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i] || board[0][0]==board[1][1]&& board[0][0]==board[2][2] ||board[0][2]==board[1][1]&& board[0][2]==board[2][0])
        return false;
    //play continue
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
    {
        if(board[i][j]!='x'&& board[i][j]!='O')
            return true;
    }
    draw=false;
    return draw;


}
int main()
{
    while( game_over())
    {

       display_board();
        player_turn();
    }
    if(turn=='x' && draw==true)
        cout<<"\n\n\tplayer2 [O] win congrutulations!!"<<endl;
    else if(turn=='O' && draw==true)
    cout<<"\n\n\tplayer1 [X] win congrutulations!!"<<endl;
    else if(draw==false)
        cout<<"\n\n\tGame draw!!!"<<endl;



}
