#include<iostream>
using namespace std;
char grid[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}};
bool game_won=0; //1 means the game has finished
int player;
char symbol[3]={'X','O','\n'};
int score_p1=0,score_p2=0;
void draw_line()
{   cout<<" ";
    for(int i=0;i<3;i++)
    cout<<"___ ";
    cout<<endl;
    
}
void grid_input(bool player=1, int position=0)
{   int x,y;
    x = int((position-1)/3);
    y = (position-1) % 3;
    if(player==0)
    grid[x][y]='X';
    else
    grid[x][y]='O';

}
void print_grid()
{   
    cout<<endl;
    draw_line();
    for(int j=0;j<3;j++)
    cout<<"|"<<" "<<grid[0][j]<<" ";
    cout<<"|"<<endl;
    draw_line();
    for(int j=0;j<3;j++)
    cout<<"|"<<" "<<grid[1][j]<<" ";
    cout<<"|"<<endl;
    draw_line();
    for(int j=0;j<3;j++)
    cout<<"|"<<" "<<grid[2][j]<<" ";
    cout<<"|"<<endl;
    draw_line();
}
void game_logic()
{   if  (      ((grid[0][0]==grid[0][1])&&(grid[0][1]==grid[0][2])&&(grid[0][2]=='X')) 
            || ((grid[1][0]==grid[1][1])&&(grid[1][1]==grid[1][2])&&(grid[1][2]=='X'))
            || ((grid[2][0]==grid[2][1])&&(grid[2][1]==grid[2][2])&&(grid[2][2]=='X'))
            || ((grid[0][0]==grid[1][0])&&(grid[1][0]==grid[2][0])&&(grid[2][0]=='X'))
            || ((grid[0][1]==grid[1][1])&&(grid[1][1]==grid[2][1])&&(grid[2][1]=='X'))
            || ((grid[0][2]==grid[1][2])&&(grid[1][2]==grid[2][2])&&(grid[2][2]=='X'))
            || ((grid[0][0]==grid[1][1])&&(grid[1][1]==grid[2][2])&&(grid[2][2]=='X'))
            || ((grid[2][0]==grid[1][1])&&(grid[1][1]==grid[0][2])&&(grid[0][2]=='X'))
        )
    {   game_won=1;
        score_p1++;
        cout<<endl<<"**************************************"<<endl;
        cout<<" PLAYER 1 has won the game"<<endl;
        cout<<"**************************************"<<endl;
    }
    else if (      ((grid[0][0]==grid[0][1])&&(grid[0][1]==grid[0][2])&&(grid[0][2]=='O')) 
            || ((grid[1][0]==grid[1][1])&&(grid[1][1]==grid[1][2])&&(grid[1][2]=='O'))
            || ((grid[2][0]==grid[2][1])&&(grid[2][1]==grid[2][2])&&(grid[2][2]=='O'))
            || ((grid[0][0]==grid[1][0])&&(grid[1][0]==grid[2][0])&&(grid[2][0]=='O'))
            || ((grid[0][1]==grid[1][1])&&(grid[1][1]==grid[2][1])&&(grid[2][1]=='O'))
            || ((grid[0][2]==grid[1][2])&&(grid[1][2]==grid[2][2])&&(grid[2][2]=='O'))
            || ((grid[0][0]==grid[1][1])&&(grid[1][1]==grid[2][2])&&(grid[2][2]=='O'))
            || ((grid[2][0]==grid[1][1])&&(grid[1][1]==grid[0][2])&&(grid[0][2]=='O'))
        )
    {   game_won=1;
        score_p2++;
        cout<<endl<<"**************************************"<<endl;
        cout<<" PLAYER 2 has won the game"<<endl;
        cout<<"**************************************"<<endl;       
    }
}
int main()
{   int box_filled[9]={0,0,0,0,0,0,0,0,0};  //An array to track if a position is already filled. 0 indicates not filled
     
    
    for(int i=0;i<9;i++)    //Game counter, it can have maximum 9 chances
    {   if(i%2==0)
            player=0;
        if(i%2==1)
            player=1;        
        cout<<endl<<endl<<"**************************************"<<endl;
        cout<<" TURN OF PLAYER "<<player+1<<"\t\t"<<symbol[player]<<endl;
        cout<<"--------------------------------------"<<endl;
        
        cout<<endl<<"Enter the number of the position that you want to place your symbol at: "<<endl;
        for(int j=0;j<9;j++)
        {   cout<<j+1<<" ";
            if(j%3==2)
            cout<<endl;
        }   
        int position;
        
        while(1)
        {
            cin>>position;
            if(box_filled[position-1]==0 && position>0 && position<10)
            {   box_filled[position-1]++;
                break;
            }
            else
            {   cout<<"You cannot enter in this position! ";
                cout<<"Enter correct position.";
            }
           
        }
        grid_input(player, position);
        print_grid();
        game_logic();
        if(game_won!=0)
        {   break;
        }
        if(i==8 && game_won==0)
        {   cout<<endl<<"The Game has ended in a draw.";
            break;
        }
    }
    bool temp;
    cin>>temp;
    return 0;
}