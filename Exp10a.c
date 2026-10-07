#include<stdio.h>
int linearsearch(int arr[],int n,int key){
for(int i =0; i<n;++i){
if(arr[i]==key){
return i;
}
}
return -1;
}
int main(){
int arr[]={12,45,67,23,56,89,9,43};
int n=sizeof(arr)/sizeof(arr[0]);
int key,index;
printf("enter the element to search:");
scanf("%d",&key);
index=linearsearch(arr,n,key);
if(index!=-1){
printf("element %d found at position %d.\n",key,index+1);
}
else{
printf("element %d not found in  the array.\n",key);
}
return 0;
}
