#include <iostream>
using namespace std;

void shellSort(int *a, int n)
{
  if(n <= 1 || a == NULL)
	return;
  for(int div = (n>>1); div >= 1; div=div>>1)
	for(int i = div; i < n; i++)
		for(int j = i;(a[j]<a[j-div])&&j>=0;j-=div)
			swap(a[j],a[j-div]);
}

int main() {
	cout<<"Hello"<<endl;
  	int a[]={2,53,5,7,23,6,8,2,10};
  	shellSort(a,sizeof a/sizeof(int));
  	for(int i = 0;i<sizeof a/sizeof(int);i++)
	  cout<<a[i]<<",";
  	cout<<endl;
	return 0;
}
