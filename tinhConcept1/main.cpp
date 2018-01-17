#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
const int maxptu=1000;
int n,m,a[maxptu][maxptu];
int intent[maxptu],result;
string extent1[maxptu];
//ifstream myfile1;


template <typename T>
  std::string NumberToString ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }
//string NumberToString(int x)
//{
//    return "1";
//}
int input()
{
    //myfile1.open ("input.txt");
    cin>>n>>m;
    //myfile1>>n>>m;
    int x,y;
    cin>>x>>y;
    //myfile1>>x>>y;
    while (x!=-99 && y!=-99)
    {
        a[x][y]=1;
        cin>>x>>y;
        //myfile1>>x>>y;
    }
    //myfile1.close();
//    for (int i=0; i<n;i++)
//    {
//
//
//        for (int j=0;j<m; j++)
//            cout <<a[i][j]<<" ";
//        cout <<endl;
//    }

}
int gen(int b[],int n1,string &ch)
{
    int tmp[maxptu];
    for (int i=0; i<n; i++)
        tmp[i]=1;
    for (int j=0; j<n1;j++)
        for (int i=0; i<n; i++)
            if (a[i][b[j]]==0 && tmp[i]==1)
                tmp[i]=0;
    ch=" ";
    int i;
    for (i=0; i<n; i++)
        if (tmp[i]==1)
            ch=ch+NumberToString(i)+" ";

}
int TinhConcept(int k, int count1)
{
    for (int j=k; j<m;j++)
    {
        intent[count1]=j;
        //for (int i=0; i<=count1; )
        string ch;
        gen(intent,count1+1,ch);
        int flag=1;
        for (int i=0; i<=result;i++)
            if (ch==extent1[i])
            {
                flag=0;
                break;
            }
        if (flag==1)
        {
            result++;
            extent1[result]=ch;
        }
        TinhConcept(j+1,count1+1);
    }
}
int main()
{
    input();
//    int b[2];
//    b[0]=1;
//    b[1]=3;
//    string ch;
//    gen(b,2,ch);
//    cout <<ch;
    string ch=" ";
    TinhConcept(0,0);
    int i;
    for (i=0; i<n; i++)
        ch=ch+NumberToString(i)+" ";
    int flag=1;
    for (int i=0; i<=result;i++)
            if (ch==extent1[i])
            {
                flag=0;
                break;
            }
    if (flag==1)
    {
        result++;
        //extent1[result]=ch;
    }
    cout <<result;

    return 0;
}
