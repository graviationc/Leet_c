//三步反转
#include <iostream>
#include <ctime>

using namespace std;
void shift1(char *s,int m ){
    int n= 0;
    while (s[n] != '\0') n++; //length of char
    while (m--) {
        char t=s[0];
        for (int i=1; i<n; i++) {
            s[i-1]=s[i];
        }
        s[n-1]=t;
    }
    cout<<s<<endl;
}

void reverse1(char *s, int from,int to){
        while (from<to) {
            char t=s[from];
            s[from++]=s[to];
            s[to--]=t;
        }
}

void shift2(char *ss, int m){
    int sizess=0;
    while (ss[sizess] != '\0') sizess++;
    reverse1(ss,0,m-1);
    reverse1(ss,m,sizess-1);
    reverse1(ss,0,sizess-1);
    cout<<ss<<endl;
}

int main() {
    char word[]="abcdeftqwwettqewqewqewqewqewqerewfdsfsvccdsfds";
    shift1(word,4);//5.2e-05 s
    shift2(word,4);//6.3e-05 s
    return 0;
}


