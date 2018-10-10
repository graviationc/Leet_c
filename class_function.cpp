#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class clockta{
    friend class line;//friend class f
public: clockta(int h,int m,int se):
            hour(h),minute(m),second(se)//constructor function
    {count++;};
    ~clockta(){count--;};//deconstructor
        clockta():clockta(0,0,0){};//default constructor function
    
    clockta(const clockta &c){ //copy constructor
        hour=c.hour;
        minute=c.minute;
        second=c.second;
        count++;
        //cout<<"copy constructor f is used"<<endl;
    }
    
    void settime(int h,int m,int se){hour =h;minute = m;second = se;};
    void showtime(){cout<<"timeis"<<hour<<minute<<second<<endl;};
    int gethour(){return hour;};
    //void showcount(){cout<<"count is "<<count<<endl;}
    
    static void showcount(){cout<<"count is "<<count<<endl;};//global class static
    
    friend void getsum(const clockta &c_sample){cout<<c_sample.hour+c_sample.minute<<endl;};//friend function

private:int hour,minute,second; //initial value
    static int count;
};

int clockta::count=0;//initialize static int value


class line{ //composite construction+union
public: line(clockta xp1,clockta xp2){
    clc_1=xp1;
    clc_2=xp2;
    lenn=xp1.gethour()+xp2.gethour();}
    void getlenn(){cout<<"len is "<<lenn<<endl;};
    
    
    void grade(int chengji ){ //union
        mode=AAA; shuzi =chengji;};
    void grade(char hanzi ){
        mode=BBB;zimu=hanzi;};
    void show(){
        switch(mode){
            case AAA:cout<<"AAA"<<endl;break;
            case BBB:cout<<"BBB"<<endl;break;}};
    void show_friend(){cout<<clc_2.hour<<"friend2's hour"<<endl;};//friend class
    
private:clockta clc_1,clc_2;
    int lenn;
    enum {AAA,BBB} mode;//enumerate
    union{char zimu;int shuzi;};
};

class arrayclc{
public:
    arrayclc(int size):size1(size){
        clcs = new clockta[size];}
    ~arrayclc(){delete[]clcs;}
    clockta&element(int index){
        assert(index>=0 && index <= size1);
        return clcs[index];}
private:
    clockta *clcs;
    int size1;
};

struct swufe{ //struct 🏠
    int num;
    string name;
    char const *sex;
};

enum class side{right,left};

int global_v=100;
void other(){
    static int static_local_v=200; //
    static_local_v++;
    int local_v=300;
    local_v++;
    global_v++;
    cout<<global_v<<static_local_v<<local_v<<endl;
}
/*
void show_array(){
    int array[]={91,92,93};
    for (auto e:array) {
        cout<<e<<endl;e++;}
}*/

void print_array(const int *p,int n){
    int i=0;
    while (i<n) {
        cout<<"@"<<p[i];
        i++;}
}



int compute(int a,int b,int(*func)(int,int)){
    cout<<func(a,b)<<endl;return 0;}
int maxx(int a,int b){
    return (a>b)?a:b;}

int main() {
    cout<<"#######"<<endl;
    arrayclc sd(6);  //dynamic array
    sd.element(0).settime(9, 9, 9);
    sd.element(0).showtime();
    sd.element(1).showtime();
    
    cout<<"#######"<<endl;
    clockta::showcount();
    clockta ha(9,5,6);
    
    clockta *clc_1=&ha; // class pointer
    cout<<clc_1->gethour()<<endl;
    
    ha.showcount();
    clockta ha_copy(ha);
    ha_copy.showcount();
    //clockta ha_default;//0,0,0
    ha.settime(1,2,3);
    line l1(ha,ha_copy);
    l1.getlenn();
    clockta::showcount();
    
    cout<<"#######"<<endl;
    clockta *clc_2=new clockta(5,5,5); //dynamic memory allocation
    delete clc_2;
    clc_2=new clockta(7,7,7);
    delete clc_2;
    
    cout<<"#######"<<endl;
    swufe c5={527,"ch","male"};
    cout<<c5.sex<<endl;
    
    cout<<"#######"<<endl;
    l1.grade(123);//union
    l1.show();
    l1.show_friend();//friend f
    
    cout<<"#######"<<endl;
    //side s = side::right;
    other();
    other();
    
    cout<<"#######"<<endl;
    getsum(ha);
    
    cout<<"#######"<<endl;
    //show_array();
    int a_array[5]={1,2,3,4,5};//{{0,1},{1,2}}
    int* ptr =&a_array[0];
    cout<< *(ptr+1)<<ptr[1]<<endl;
    print_array(a_array,5);
    
    cout<<"#######"<<endl;
    compute(1, 2, &maxx);
    
    int(*dy_point)[10][20]=new int[5][10][20];
    for (int i=0; i<5; i++) {
        for (int j=0; i<10; i++){
            for (int z=0; i<20; i++){
                *(*(*(dy_point+i)+j)+z)=1;}}}
    
    vector<int> ve={1,2,3};
    for(auto e:ve)
        cout<<e;
    
    return 0;
}


