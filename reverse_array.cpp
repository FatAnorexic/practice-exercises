/*
Write a function that accepts an int array and the array’s size as arguments. The function
should create a copy of the array, except that the element values should be reversed
in the copy. The function should return a pointer to the new array. Demonstrate the
function in a complete program.
*/

#include <iostream>
#include <memory>

//Function prototype

int *reverse(int [], int);

int main(){
    const int size=10;
    int array[size] = {1,2,3,4,5,6,7,8,9,10};

    //Pointer that will recieve a reversed array
    int *reversed=nullptr;

    reversed=reverse(array, size);

    for(int x=0;x<size;x++){
        std::cout<<*(reversed+x)<<" ";
    }
    return 0;
}

int *reverse(int array[], int size){
    int *rev=nullptr;

    if(size<0){
        return nullptr;
    }

    rev=new int[size];

    for(int x=0;x<size;x++){
        rev[x]=array[size-(x+1)];
    }

    return rev;
}