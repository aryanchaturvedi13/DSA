#include <iostream>
#include <vector>
using namespace std;

void merge(int* arr,int low, int mid,int high){
    int left=low;
    int right=mid+1;
    vector<int> temp; 
   while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
             temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
   }
   while(left<=mid){
    temp.push_back(arr[left]);
    left++;
   }
   while(right<=high){
    temp.push_back(arr[right]);
    right++;
   }
    for(int i=low;i<high;i++){
        arr[i]=temp[i-low];
        cout<<arr[i]<<" ";
    }

}
void ms(int* arr, int low, int high){
    if(low==high) return;
    int mid=(low+high)/2;

    ms(arr,low,mid);
    ms(arr,mid+1,high);

    merge(arr,low,mid,high);
}
int main(){
    int arr[]={5,9,13,1,19};
    ms(arr,0,4);
}