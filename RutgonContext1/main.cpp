#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
const int maxptu=1000;
int n,m,a[maxptu][maxptu],used[maxptu],row[maxptu],col[maxptu];
ifstream myfile1;

bool Equal_Row(int s[],int x)
{
    for (int i=0; i<m;i++)
        if (s[i]!=a[x][i]) return false;
    return true;
}
bool Equal_Col(int s[],int x)
{
    for (int i=0; i<n;i++)
        if (s[i]!=a[i][x]) return false;
    return true;
}
int giao_Row(int s[],int x,int tmp[])
{
    for (int i=0; i<m; i++)
    {
        if (s[i]!=a[x][i]) tmp[i]=0;
        else tmp[i]=s[i];
    }
}

int giao_Col(int s[],int x,int tmp[])
{
    for (int i=0; i<n; i++)
    {
        if (s[i]!=a[i][x]) tmp[i]=0;
        else tmp[i]=s[i];
    }
}
int RowRemove(int x,int s[])
{
    for (int i=0;i<n; i++ )
        if (i!=x && used[i]==0 && row[i]==0)
        {
            int tmp[maxptu];
            giao_Row(s,i,tmp);
            if (Equal_Row(tmp,x)) row[x]=1;
            else
            {
                used[i]=1;
                RowRemove(x,tmp);
                used[i]=0;
            }


        }
}
int ColRemove(int x,int s[])
{
    for (int i=0;i<m; i++ )
        if (i!=x && used[i]==0 && col[i]==0)
        {
            int tmp[maxptu];
            giao_Col(s,i,tmp);
            if (Equal_Col(tmp,x)) col[x]=1;
            else
            {
                used[i]=1;
                ColRemove(x,tmp);
                used[i]=0;
            }


        }
}
int input()
{

    int x,y;

//    cin>>n>>m;
//    cin>>x>>y;
    myfile1.open ("input.txt");

    myfile1>>n>>m;
    myfile1>>x>>y;
    while (x!=-99 && y!=-99)
    {
        a[x][y]=1;
//        cin>>x>>y;
        myfile1>>x>>y;
    }
    myfile1.close();
//    for (int i=0; i<n;i++)
//    {
//        for (int j=0;j<m; j++)
//            cout <<a[i][j]<<" ";
//        cout <<endl;
//    }

}
int input_console()
{

    int x,y;

    cin>>n>>m;
    cin>>x>>y;

    while (x!=-99 && y!=-99)
    {
        a[x][y]=1;
        cin>>x>>y;

    }

}
int first_step_reduce()
{
    //neu dong, cot nao rong thi loai bo
    int flag0,flag1,flag;
    for (int i=0; i<n;i++)
    {
        flag0=0; flag1=0;
        for (int j=0;j<m; j++)
            if (a[i][j]==1) flag1++;
            else flag0++;
        if (flag0==m || flag1==m) row[i]=1;  //xoa thi row=1
    }
    for (int j=0; j<m;j++)
    {
        flag0=0; flag1=0;
        for (int i=0;i<n; i++)
            if (a[i][j]==1) flag1++;
            else flag0++;
        if (flag0==n || flag1==n) col[j]=1;
    }
    //neu dong, cot nao trung thi xoa dong, cot dung sau
    for (int i=0; i<n-1;i++)
        if (row[i]==0)
            for (int i2=i+1; i2<n; i2++)
                if (row[i2]==0)
                {
                    flag=0;
                    for (int j=0; j<m; j++)
                    {
                        if (a[i][j]!=a[i2][j]){flag=1; break;}
                    }
                    if (flag==0) row[i2]=1;
                }
    for (int j=0; j<m-1;j++)
        if (col[j]==0)
            for (int j2=j+1; j2<m; j2++)
                if (col[j2]==0)
                {
                    flag=0;
                    for (int i=0; i<n; i++)
                    {
                        if (a[i][j]!=a[i][j2]){flag=1; break;}
                    }
                    if (flag==0) col[j2]=1;
                }


}


int main()
{
    //input();
    input_console();
    first_step_reduce();

    int tmp[maxptu];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            tmp[j]=1;
        RowRemove(i,tmp);
    }


    for (int i=0; i<n; i++)
        //cout <<row[i]<<" ";
        if (row[i]==0) cout <<"r"<<i+1<<" ";
    cout<<endl;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            tmp[j]=1;
        ColRemove(i,tmp);
    }
    for (int i=0; i<m; i++)
        //cout <<col[i]<<" ";
        if (col[i]==0) cout <<"c"<<i+1<<" ";
////    if (!Equal_Row(tmp,3)) cout <<"fail";
}
