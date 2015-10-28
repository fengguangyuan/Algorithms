#include <iostream>
using namespace std;

void insertSort(int *a, int n)
{
  for(int i = 1; i < n; i++)
  {
	int tmp = a[i];
	int k = i - 1;
	for(; k >= 0; k--)
  		{
			if(tmp < a[k])
			  a[k+1]=a[k];
	  		else
			  break;
  		}
	a[k+1] = tmp;
	cout<<i<<" time:";
	for(int m=0;m<n;m++)
	  cout<<a[m]<<",";
	cout<<endl;
  }
}

int main() {
	cout<<"Hello"<<endl;
  int a[] = {3,4,64,12,54,6,34,6};
  cout<<"origin:";
  for(int i = 0; i < sizeof a/sizeof(int);i++)
	cout<<a[i]<<",";
  cout<<endl;
  insertSort(a,sizeof a/sizeof(int));
  cout<<"result:";
  for(int i = 0; i < sizeof a/sizeof(int);i++)
	cout<<a[i]<<",";
  cout<<endl;
	return 0;
}
