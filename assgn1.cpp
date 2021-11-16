#include<iostream>
#include<string>
using namespace std;
int getlength_ptr(char *s){
    int i=0;
    while(*s){
        i++;
        s++;
    }
    return i;
}
int getlength(char s[50]){
    int i=0;
    while(s[i]!='\0'){
        i++;
        
    }
    return i;
}
void strcopy_str(char *s1,char *s2){
    int i=0;
    while(*s1){
        s2[i]=s1[i];
        s2++;
        s1++;
        
    }
    *s2='\0';
    
}
void strcopy(char s1[50],char s2[50]){
    int i=0;
    while(s1[i]){
        s2[i]=s1[i];
        i++;
        
        
    }
    s2[i]='\0';
    
}
int strcompare(char *s1,char *s2){
    return getlength(s1)-getlength(s2);
    
}

void reverse(char s[50]){
    int n=getlength(s);
    for(int i=0;i<n/2;i++){
    swap(s[i],s[n-i-1]);    
    
    }
}
void reverse_ptr(char *s){
    char *end = s;
    while (*(end + 1))
    {
        end++;
    }
    while (s < end)
    {
        char temp = *s;
        *s = *end;
        *end = temp;
        s++;
        end--;
    }
    
    
}
void concate_ptr(char *s1,char *s2){
    
    while (*s1!='\0')
    {
        s1++;
    }
    while (*s2!='\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    
        
    }
void concate(char s1[50],char s2[50]){
     int i = 0;
     int dis=getlength(s1);
    
    while (s2[i])
    {
        s1[dis+i] = s2[i];
        i++;
    }
    s1[dis+i] = '\0';
}
int main(){
    char *s=new char;
    char *d=new char;
    char *e=new char;
    int seq=-1;
    while(seq!=0){
    cout<<"\n---------------";
    cout<<"\nEnter your choice"<<endl;
    cout<<"1.Length of String"<<endl;
    cout<<"2.Copy a String"<<endl;
    cout<<"3.Concate two Strings"<<endl;
    cout<<"4.Compare two strings"<<endl;
    cout<<"5.Reverse a string"<<endl;
    cout<<"6.Exit the program"<<endl;
    cout<<"\n";
    int n;
    cin>>n;
    if(n==1){
        cout<<"Enter a string"<<endl;
        cin>>s;
        cout<<"The length of string with pointer is: "<<getlength(s)<<endl;
        cout<<"The length of string without pointer is: "<<getlength_ptr(s)<<endl;
    }
    else if(n==2){
        cout<<"Enter a string"<<endl;
        cin>>s;
        strcopy(s,d);
        strcopy_str(s,e);
        cout<<"The copied string is "<<d<<endl;
        cout<<"The copied string with pointer is"<<d<<endl;
    }
    else if(n==3){
        cout<<"Enter first string"<<endl;
        cin>>s;
        cout<<"Enter second string"<<endl;
        cin>>d;
        char *temp=new char;
        *temp=*s;
        concate(temp,d);
        concate_ptr(s,d);
        cout<<"The concatonated string is "<<temp<<endl;
        cout<<"The concatonated string with pointer is"<<s<<endl;
        
    }
    else if(n==4){
        cout<<"Enter first string"<<endl;
        cin>>s;
        cout<<"Enter second string"<<endl;
        cin>>d;
        int diff=strcompare(s,d);
        if(diff>0){
            cout<<"First string has more character "<<endl;
        }
        else if(diff<0){
            cout<<"Second string has more characters "<<endl;
        }
        else{
            cout<<"Both strings are equal "<<endl;
        }
    }
    else if(n==5){
        cout<<"Enter string to Reverse "<<endl;
        cin>>s;
        char*temp=new char;
        *temp=*s;
        
        reverse(s);
        reverse_ptr(temp);
        cout<<"Reversed string is "<<s<<endl;
        cout<<"Reversed string using pointer is"<<temp<<endl;
    }
    else{
        cout<<"Exited Sucessfully!!"<<endl;
        break;
        
    }
}
    return 0;
}

