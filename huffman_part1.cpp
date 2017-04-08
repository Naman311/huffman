#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

void sort_fre(char tab[], int fre[])
{
    for(int i=1;i<strlen(tab);i++)
    {
        int temp=fre[i];
        char ctemp=tab[i];
        int j=i-1;
        while(temp<fre[j] && j>=0)
        {
            fre[j+1]=fre[j];
            tab[j+1]=tab[j];
            --j;
        }
        fre[j+1]=temp;
        tab[j+1]=ctemp;
    }
    cout<<"\nThe frequency are :"<<endl;
    for(int i=0;i<strlen(tab);i++)
    {
        cout<<tab[i]<<"  "<<fre[i]<<endl;
    }
}

int main()
{
    char ostr[30],str[30],tab[30],f=1,j=0;
    int n,fre[30];
    cout<<"Enter the string :"<<endl;
    cin.getline(ostr,29);
    n=strlen(ostr);
    strcpy(str,ostr);
    std::sort(str,str+n);
    for(int i=0;i<n;i++)
    {
        if(str[i]==str[i+1])
        {
            f++;
        }
        else
        {
            tab[j]=str[i];
            fre[j]=f;
            f=1;
            j++;
        }
    }
    tab[j]='\0';
    sort_fre(tab,fre);
    return 0;
}
