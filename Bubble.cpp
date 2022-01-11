#include <iostream>
#include <string>
using namespace std;
void Bubble(int arr[],int len);
void printf(int arr[],int len);
int main()
{
   int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
   int len=sizeof(arr)/sizeof(int);
   Bubble(arr,len);
   printf(arr,len);
   return 0;
}

void Bubble(int arr[],int len)
{
   int i,j,tmp;
   for(i=0;i<len-1;i++)
   {
      for(j=0;j<len-i-1;j++)
      {
         if(arr[j]>arr[j+1])
         {
            tmp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=tmp;
         }
      }
   }
}
void printf(int arr[],int len)
{
   int i;
   for(i=0;i<len;i++)
   {
      cout<<" "<<arr[i];
   }
}