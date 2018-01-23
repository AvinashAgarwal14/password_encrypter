#include <iostream>
#include <ctype.h>
#include <stdio.h>

using namespace std;

char* encrypt(char encrypt[80]);
int sumfinder(int a);

int main()
{
    //Taking Name as Input
    int i,j;
    char name[80];
    cout<<"Enter Your Name:"<<endl;
    cin>>name;
    /*char *nameptr;
    nameptr = encrypt(name);
    char enname[241];
    int i,j;
    for(i=0;*(nameptr+i)!='\0';i++)
        enname[i]=*(nameptr+i);
    enname[i]='\0';*/
    //Taking sentence as input
    char sen[80];
    cout<<"Enter a Sentence:"<<endl;
    cin.ignore();
    cin.getline(sen,80);
    char changedsen[80];
    int l=0;
    for(i=0,j=0;sen[i]!='\0';i++)
    {
        if((sen[i]>=65 && sen[i]<=90) || (sen[i]>=97 && sen[i]<=122))
        {
            changedsen[j++]=sen[i];
            l++;
        }
    }
    changedsen[j]='\0';
    //Take signature as input
    char sign[80];
    cout<<"Signature:"<<endl;
    cin.getline(sign,80);
    char *checkptr;
    checkptr = encrypt(sign);
    char checksign[241];
    int k=0;
    for(i=0;*(checkptr+i)!='\0';i++)
        {
            checksign[i]=*(checkptr+i);
            k++;
        }
    checksign[i]='\0';
    //Taking encoded sentence as input
    char encodedmessage[321];
    for(i=0;i<j;i++)
    {
        encodedmessage[i]=changedsen[i];
    }
    for(i=0;i<k;i++)
    {
        encodedmessage[j++]=checksign[i];
    }
    encodedmessage[j]='\0';
    cout<<encodedmessage<<endl;
    char ensen[80];
    cout<<"Enter the Encoded Sentence:"<<endl;
    cin.getline(ensen,80);
    //Output Determining statements
    int m1=0;
    int s1=0;
    int f1=0;
    int f2=0;
    for(i=0;ensen[i]!='\0';i++)
    {
        if(ensen[i]>48 && ensen[i]<58)
            break;
        m1++;
    }
    for(i=m1;ensen[i]!='\0';i++)
    {
        s1++;
    }
    /*cout<<m1<<s1<<l<<(j-l)<<endl;*/
    if(m1<l)
        f1=1;
    if(s1<(j-l) || s1>(j-l))
        f2=1;
    if(m1!=l && s1==(j-l))
    {
        for(i=l;encodedmessage[i]!='\0';i++)
        {
            if(ensen[m1++]!=encodedmessage[i])
            {
                f2=1;
                break;
            }
        }
    }
    if(m1>l && j!=(m1+s1))
    {
        for(i=0;i<l;i++)
            if(ensen[i]!=encodedmessage[i])
            {
                f1=1;
                break;
            }
    }
    if(j==(m1+s1))
    {
        for(i=0;ensen[i]!='\0';i++)
        {
            if(ensen[i]!= encodedmessage[i] && i<l)
                    f1=1;
            else if(ensen[i]!=encodedmessage[i] && i>=l)
                    f2=1;
        }
    }
    if(f1==1 && f2==1)
        {
        cout<<"Both The Entered Encoded String and Signature are Incorrect"<<endl;
        cout<<name<<" is a not Verified User"<<endl;
        }
    else if(f2==1)
        {
            cout<<"The Entered Encoded Signature is Incorrect"<<endl;
            cout<<name<<" is a not Verified User"<<endl;
        }
    else if(f1==1)
        {
            cout<<"The Entered Encoded String is Incorrect"<<endl;
            cout<<name<<" is a not Verified User"<<endl;
        }
    if((f1==0 & f2==0) && m1!=0)
        {
            cout<<"The Encoded Message is Correct"<<endl;
            cout<<name<<" is a Verified User"<<endl;
        }
    return 0;
}

char* encrypt(char encrypt[80])
{
    char nabc[26];
    for(int i=0,j=97;i<26;i++,j++)
    {
        nabc[i]=(char)j;
    }
    char iabc[26];
    for(int i=0,j=122;i<26;i++,j--)
    {
        iabc[i]=(char)j;
    }
    char enname[241];
    char ch;
    int p;
    int k=0;
    int temp;
    for(int i=0;encrypt[i]!='\0';i++)
    {
        ch=(char)tolower(encrypt[i]);
        for(int j=0;j<26;j++)
        {
            if(nabc[j]==ch)
                p=j;
        }
        int curr=i+1;
        //First Encrypted Letter
        int pos=p+curr;
        if(pos>25)
            pos=pos-26;
        temp=(int)toupper(iabc[pos]) + (26-pos);
        temp=sumfinder(temp);
        enname[k++]=(temp+48);
        //Second Encrypted Letter
        pos=pos+curr;
        if(pos>25)
            pos=pos-26;
        pos=pos+temp;
        if(pos>25)
            pos=pos-26;
        enname[k++]=iabc[pos];
        //Third Encrypted Letter
        pos=pos+curr;
        if(pos>25)
            pos=pos-26;
        temp=(int)iabc[pos] + (26-pos);
        temp=sumfinder(temp);
        if(temp<=4)
        enname[k++]=(char)(60+temp);
        else
        enname[k++]=(char)(30+temp);
    }
    enname[k]='\0';
        return enname;
}

int sumfinder(int a)
{
    while(a>9)
        {
            int sum=0;
            while(a>0)
            {
                sum=sum+a%10;
                a=a/10;
            }
            a=sum;
        }
        return a;
}
