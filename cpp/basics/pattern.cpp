#include<iostream>
using namespace std;
void pattern1() {
     for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern2() {
    for(int i=0;i<6;i++){
        for(int j=0;j<i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern3() {
    int k=1;
    for(int i=1;i<6;i++){
        for(int j=0;j<i;j++){
            cout<<k<<" ";
            k++;
        }
        cout<<endl;
        k=1;
    }
}

void pattern4() {
    int k=1;
    for(int i=0;i<5;i++){
        for(int j=0;j<i+1;j++){
            cout<<k<<" ";
        }
        k++;
        cout<<endl;
    }
}

void pattern5() {
    for(int i=0;i<5;i++){
        for (int j=5;j>i;j--){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern6() {
    int k=1;
     for (int i=0;i<5;i++){
        for (int j=5;j>i;j--){
            cout<<k<<" ";
            k++;
        }
        k=1;
        cout<<endl;
     }
}

void pattern7() {
    for(int i=0;i<5;i++){
        for(int j=0;j<9;j++){
            if(i>=0 && j==4) cout<<"* ";
            else if(i>=1 && j==3 || i>=1 && j==5) cout<<"* ";
            else if(i>=2 && j==2 || i>=2 && j==6) cout<<"* "; 
            else if(i>=3 && j==1 || i>=3 && j==7) cout<<"* ";
            else if(i>=4 && j==0 || i>=4 && j==8) cout<<"* ";
            else cout<<"- ";
        }
        cout<<endl;
    }

}

void pattern8() {
    for(int i=0;i<5;i++){
        for(int j=0;j<9;j++){
            if(i==0) cout<<"* ";
            else if(i>0 && j==0 || i>0 && j==8) cout<<"- ";
            else if(i>1 && j==1 || i>1 && j==7) cout<<"- ";
            else if(i>2 && j==2 || i>2 && j==6) cout<<"- ";
            else if(i>3 && j==3 || i>3 && j==5) cout<<"- ";
            else cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern9() {
    for(int i=0;i<5;i++){
        for(int j=0;j<4-i;j++) {
            cout<<"- ";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<"* ";
        }
        for(int j=0;j<4-i;j++){
            cout<<"- ";
        }
        cout<<endl;
    }
}

void pattern10() {
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i;j++){
            cout<<"- ";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<"* ";
        }
        for(int j=0;j<5-i;j++){
            cout<<"- ";
        }
        cout<<endl;
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<i+1;j++){
            cout<<"- ";
        }
        for(int j=0;j<2*(5-i)-1;j++){
            cout<<"* ";
        }
        for(int j=0;j<i+1;j++){
            cout<<"- ";
        }
        cout<<endl;
    }
}

void pattern11() {
     for(int i=0;i<5;i++){
        for(int j=0;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
     }
     for(int i=0;i<4;i++){
        for(int j=0;j<4-i;j++){
            cout<<"* ";
        }
        cout<<endl;
     }
}

void pattern12() {
    int s;
    for(int i=0;i<5;i++){
        for(int j=0;j<=i;j++){
            if(i%2==0) {
                s=1;
                cout<<s<<" ";
                s=1-s;
            }
            else {
                s=0; 
                
                cout<<s<<" ";
                s=1-s;
            }
        }
        cout<<endl;
    }
}
int main () {
      pattern12();
}