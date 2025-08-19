#include <iostream>
using namespace std;
int i=1;
int main() {
    if(i>5) return 0;
    cout<<"Hello World"<<endl;
    i++;
    main();
    return 0;
}