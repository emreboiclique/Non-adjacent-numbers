//Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative. For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5.
#include <iostream>
using namespace std;
int arr[100]={},specialnumbers[100]={},arrsize,largestresult,result,index=0;;
int Findlargestnonadjacent(int arr[],int arrsize);
void Placethearr(int arr[],int arrsize);
void Findspecialnumbers(int originalarr[],int specialarr[],int arrsize);


int main(){
cout<<"Enter the array size\n";
cin>>arrsize;
cout<<"Enter the numbers for the array\n";
Placethearr(arr,arrsize);
Findspecialnumbers(arr,specialnumbers,arrsize);
cout<<"Result is: "<<Findlargestnonadjacent(arr,arrsize);
return 0;
}

//Special numbers are the numbers which should be prefered instead of it's previous or next number because it's larger than their sum
void Findspecialnumbers(int originalarr[],int specialarr[],int arrsize){
for(int i=0;i<=arrsize;i++){
if(i>0&&i!=arrsize){
//We should check if the current number is larger than the sum of its previous and next number and then put it in the special array
if(originalarr[i-1]+originalarr[i+1]<originalarr[i]){specialarr[index]=originalarr[i]; index++;}     
}
}
}

void Placethearr(int arr[],int arrsize){
for(int i=0;i<arrsize;i++){
cin>>arr[i];
}
}

int Findlargestnonadjacent(int arr[],int arrsize){
bool specialfinder=false;
for(int k=0;k<=arrsize;k++){
    result=0;
    for(int i=k;i<=arrsize;i+=2){
    //we should check if the number where 3 steps away is a special or not (if not we will prefer the number else we'll prefer the special one)
    for(int l=0;l<index;l++)if(arr[i+1]==specialnumbers[l])specialfinder=true;
    if(specialfinder){i++;}
    result+=arr[i];
    specialfinder=false;        }
if(result>largestresult)largestresult=result;
}
return largestresult;
}