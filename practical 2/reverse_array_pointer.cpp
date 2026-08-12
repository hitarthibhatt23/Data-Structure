#include<iostream>
using namespace std;
int main()
{
  int n,arr[100];
cout<<"Enter array elements:";
cin>>n;
cout<<"Enter array elements:";
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
cout<<"Array in reverse order:';
  int*ptr=arr+n-1;
  for(inti=0;i<n;i++)
  {cout<<*ptr<<" ";
  ptr--;
}
cout<<endl;
return 0;
}
