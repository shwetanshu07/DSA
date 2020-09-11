/*
i/p   7 1 2 5 4 3 1
o/p  -1 7 7 7 5 4 3
*/


#include <iostream>
#include <stack>

void nglCalculate(int *arr, int *ngl, int size){
    std::stack<int> mystack;
    for(int i=0; i<size; i++){
        if(mystack.empty()){
            mystack.push(arr[i]);
            ngl[i] = -1;
        }
        else{
            if(mystack.top()>arr[i]){
                ngl[i] = mystack.top();
                mystack.push(arr[i]);
            }
            else{
                while(!mystack.empty() && mystack.top()<=arr[i]){
                    //mystack.top()<=arr[i] && !mystack.empty() can lead to segmentation fault
                    mystack.pop();
                }
                if(mystack.empty()){
                    ngl[i] = -1;
                    mystack.push(arr[i]);
                }
                if(mystack.top()>arr[i]){
                    ngl[i] = mystack.top();
                    mystack.push(arr[i]);
                }
            }
        }
    }
};

int main(){
    int arr[] = {7,1,2,5,4,3,1};
    int size = sizeof(arr)/sizeof(int);
    int ngl[size];
    nglCalculate(arr, ngl, size);
    for(int i=0; i<size; i++){
        std::cout<<ngl[i]<<" ";
    }
    return 0;
}
