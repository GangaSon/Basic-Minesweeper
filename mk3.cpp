//GAME WORKING PROPERLY.....
//TO-DO - Game is not showing WIN even if completed correctly
#include<bits/stdc++.h>
using namespace std;
int const n=10,mineNum=15;
void plantMines(int a[][n])
{
    vector<pair<int,int>> p;
    for(int i=1;i<=mineNum;i++)
    {
        int x=rand()%(9-0+1)+0;
        int y=rand()%(9-0+1)+0;
        pair<int,int> t=make_pair(x,y);
        if(find(p.begin(),p.end(),t)==p.end())  {
            a[x][y]=9;
            p.push_back(make_pair(x,y));
        }
        else
            i--;
    }
}
void initializingGame(int a[][n])
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=-1;
    plantMines(a);
}
void plotGround(int a[][n])
{
    system("cls");
    cout<<"M I N E S W E E P E R\n";
    for(int i=0;i<n;i++)    {
        for(int j=0;j<n;j++)
            if(a[i][j]==-1||a[i][j]==9)
                cout<<"- ";
            else if(a[i][j]==0)
                cout<<"  ";
            else
                cout<<a[i][j]<<" ";
        cout<<i+1<<"\n";
    }
    for(int i=1;i<=10;i++)
        cout<<i<<" ";
    cout<<"\n";
}
void check(int a[][n],int x,int y,vector<pair<int,int>> v)
{
    int i,j,c=0;
    pair<int,int> p=make_pair(x,y);
    //cout<<"GG\n";
    if(find(v.begin(),v.end(),p)!=v.end())
        return;
    if(a[x][y]==9)  {
        cout<<"B O O M\n";
        system("pause");
        exit(0);
    }
    else
    {
        //i=(x-1<0)?0:x-1;
        //j=(y-1<0)?0:y-1;
        //cout<<i<<" "<<j<<"\n";
        for(i=(x-1<0)?0:x-1;i<=x+1&&i<=n-1;i++)
            for(j=(y-1<0)?0:y-1;j<=y+1&&j<=n-1;j++)
                if(a[i][j]==9)
                    c++;
        //cout<<c<<"\n";
        if(c==0)    {
            //cout<<"G1\n";
            a[x][y]=0;
            v.push_back(p);
            if(x==0&&y==0)  {
                //a[x+1][y+1]=0;  a[x][y+1]=0;    a[x+1][y]=0;
                check(a,x+1,y+1,v);   check(a,x,y+1,v); check(a,x+1,y,v);
            }
            else if(x==n-1&&y==0)   {
                //a[x][y+1]=0;    a[x-1][y+1]=0;  a[x-1][y]=0;
                check(a,x,y+1,v);   check(a,x-1,y+1,v); check(a,x-1,y,v);
            }
            else if(x==n-1&&y==n-1) {
                //a[x-1][y-1]=0;  a[x][y-1]=0;    a[x-1][y]=0;
                check(a,x-1,y-1,v);   check(a,x,y-1,v); check(a,x-1,y,v);
            }
            else if(x==0&&y==n-1)   {
                //a[x][y-1]=0;    a[x+1][y]=0;    a[x+1][y-1]=0;
                check(a,x,y-1,v);   check(a,x+1,y,v); check(a,x+1,y-1,v);
            }
            else if(x==0&&y>0&&y<9) {
                //a[x+1][y+1]=0;  a[x+1][y]=0;    a[x+1][y-1]=0;
                //a[x][y-1]=0;    a[x][y+1]=0;
                check(a,x+1,y+1,v);   check(a,x+1,y,v); check(a,x+1,y-1,v);
                check(a,x,y-1,v);   check(a,x,y+1,v);
            }
            else if(y==0&&x>0&&x<9) {
                //a[x+1][y+1]=0;  a[x][y+1]=0;    a[x-1][y+1]=0;
                //a[x+1][y]=0;    a[x-1][y]=0;
                check(a,x+1,y+1,v);   check(a,x,y+1,v); check(a,x-1,y+1,v);
                check(a,x+1,y,v);   check(a,x-1,y,v);
            }
            else if(x==n-1&&y>0&&y<9) {
                //a[x-1][y+1]=0;  a[x-1][y]=0;    a[x-1][y-1]=0;
                //a[x][y-1]=0;    a[x][y+1]=0;
                check(a,x-1,y+1,v);   check(a,x-1,y,v); check(a,x-1,y-1,v);
                check(a,x,y-1,v);   check(a,x,y+1,v);
            }
            else if(y==n-1&&x>0&&x<9) {
                //a[x+1][y-1]=0;  a[x][y-1]=0;    a[x-1][y-1]=0;
                //a[x+1][y]=0;    a[x-1][y]=0;
                check(a,x+1,y-1,v);   check(a,x,y-1,v); check(a,x-1,y-1,v);
                check(a,x+1,y,v);   check(a,x-1,y,v);
            }
            else    {
                //a[x][y+1]=0;    a[x-1][y+1]=0;  a[x+1][y+1]=0;
                //a[x+1][y]=0;    a[x-1][y]=0;    a[x+1][y-1]=0;
                //a[x-1][y-1]=0;  a[x][y-1]=0;
                check(a,x,y+1,v); check(a,x-1,y+1,v); check(a,x-1,y,v);
                check(a,x-1,y-1,v); check(a,x,y-1,v); check(a,x+1,y-1,v);
                check(a,x+1,y,v); check(a,x+1,y+1,v);
            }
            //return ;
        }
        else    {
            //cout<<"G2\n";
            a[x][y]=c;
            v.push_back(p);
        }
    }
    //cout<<"gg";
    if(v.size()==(n*n-mineNum)) {
        cout<<"YOU WON\n";
        system("pause");
        exit(0);
    }
}
void play(int a[][n],vector<pair<int,int>> v)
{
    int x,y;
    plotGround(a);
    cin>>x;
    if(x==0)    {
        system("pause");
        exit(0);
    }
    cin>>y;
    check(a,x-1,y-1,v);
}
void instruction()
{
    system("cls");
    cout<<"M I N E S W E E P E R\n"
        <<"1. There is a field of size NxN under which "
        <<"some Mines are planted.\n"
        <<"2. You have to clear the field without "
        <<"detonating the Mines using clues about number "
        <<"of mines around each location.\n"
        <<"3. You have to enter location coordinates (X Y)."
        <<" X=1 to N (downwards) and Y=1 to N (rightwards).\n"
        <<"4. If you want to leave the game, enter \"0\" "
        <<"without quotation marks.\n";
    return;
}
int main()
{
    int a[n][n];
    int c;
    srand(time(0));
    vector<pair<int,int>> v;    //discovered locations on field
    if(system(NULL)==0) {
        cout<<"This game is not Compatible with the "
            <<"installed Operating System.\n";
        system("pause");
        exit(0);
    }
    while(1)    {
        cout<<"\nM I N E S W E E P E R\n"
            <<"1. Start Game\n"
            <<"2. Instruction\n"
            <<"3. Exit\n...";
        cin>>c;
        switch(c)   {
            case 1: initializingGame(a);
                    while(1)
                        play(a,v);
                    break;
            case 2: instruction();
                    break;
            case 3: system("pause");
                    exit(0);
            default:system("cls");
        }
    }
    //initializingGame(a);
    //plotGround(a);
    //cout<<getc(stdin);
    //while(1)
    //    play(a,v);
    return 0;
}
