#include <iostream>

using namespace std;
const int maxptu=1000;
int n,m,a[maxptu][maxptu];
int intent[maxptu],result;
string extent1[maxptu];
int input()
{

    cin>>n>>m;
    int x,y;
    cin>>x>>y;
    while (x!=-99 && y!=-99)
    {
        a[x][y]=1;
        cin>>x>>y;
    }
}



int main()
{
    //input();
    return 0;
}
