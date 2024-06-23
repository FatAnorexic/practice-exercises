/*
Modify Program 9-19 (the United Cause case study program) so it can be used with
any set of donations. The program should dynamically allocate the donations array
and ask the user to input its values.
*/

#include <memory>
#include <iostream>
#include <vector>

std::vector<int> setDonations();
void sortPtr(std::unique_ptr<int[]>&, int);
void showArr(std::vector<int>);
void showArrPtr(std::unique_ptr<int[]>&);

int main(){
    //create the vector for a dynamically allocated array.
    std::vector<int> donations=setDonations();
    //create the unique pointer and point to the vector 
    std::unique_ptr<int[]> donSort(new int[donations.size()]);
    int size=donations.size();

    for(int x=0;x<donations.size();x++){
        donSort[x]=donations[x];
    }

    sortPtr(donSort, size);

    for (int x=0;x<size;x++){
        std::cout<<donSort[x]<<" ";
    }
    
    return 0;
}

std::vector<int> setDonations(){
    int size, donation;
    std::vector<int> donations;
    std::cout<<"Enter the number of donations recieved: ";
    std::cin>>size;
    std::cin.ignore();

    for(int x=0;x<size;x++){
        printf("Enter the amount for donation %i: ", (x+1));
        std::cin>>donation;
        donations.push_back(donation);
    }

    return donations;
}

void sortPtr(std::unique_ptr<int[]>& donations, int size){
    int min, temp;

    //use selection sort to sort the refrenced array
    for(int x=0;x<size-1;x++){
        min=x;
        temp=donations[x];
        for(int y=x+1;y<size;y++){
            if(donations[y]<temp){
                temp=donations[y];
                min=y;
            }
        }
        donations[min]=donations[x];
        donations[x]=temp;
    }
}