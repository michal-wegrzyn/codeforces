#include <iostream>
using namespace std;

int main(){
    int n, a, x1=1, y1=1, x2=1, y2=2;
    cin >> n;
    for(int i=0; i<n*n; i++){
        cin >> a;
        if(x2>0 && x1>0){
            if(a==2){
                cout << 1 << ' ' << x1 << ' ' << y1 << '\n';
                y1 += 2;
                if(y1 > n){
                    x1++;
                    y1 = 2 - (x1%2);
                    if(x1>n) x1=-1;
                } 
                cout.flush();
            }
            else{
                cout << 2 << ' ' << x2 << ' ' << y2 << '\n';
                y2 += 2;
                if(y2 > n){
                    x2++;
                    y2 = (x2%2)+1;
                    if(x2>n) x2=-1;
                } 
                cout.flush();
            }
        }
        else if(x2==-1){
            if(a==3){
                cout << 1 << ' ' << x1 << ' ' << y1 << '\n';
                y1 += 2;
                if(y1 > n){
                    x1++;
                    y1 = 2 - (x1%2);
                    if(x1>n) x1=-1;
                } 
                cout.flush();
            }
            else{
                cout << 3 << ' ' << x1 << ' ' << y1 << '\n';
                y1 += 2;
                if(y1 > n){
                    x1++;
                    y1 = 2 - (x1%2);
                    if(x1>n) x1=-1;
                } 
                cout.flush();
            }
        }
        else if(x1==-1){
            if(a==3){
                cout << 2 << ' ' << x2 << ' ' << y2 << '\n';
                y2 += 2;
                if(y2 > n){
                    x2++;
                    y2 = (x2%2)+1;
                    if(x2>n) x2=-1;
                } 
                cout.flush();
            }
            else{
                cout << 3 << ' ' << x2 << ' ' << y2 << '\n';
                y2 += 2;
                if(y2 > n){
                    x2++;
                    y2 = (x2%2)+1;
                    if(x2>n) x2=-1;
                } 
                cout.flush();
            }
        }
    }
}