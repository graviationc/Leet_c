#include <iostream>
using namespace std;

int huiwen(int num){
    int s=0;
    while(num>0){
        s = s*10 +num%10;
        num=num/10;
    }
    return s;
}

int main() {
    int shuru;
    cin>>shuru;
    int sum = shuru + huiwen(shuru);
    while(sum!=huiwen(sum)){
        sum = sum + huiwen(sum);
    }
    cout<<sum;
    
    return 0;
}
