#include <iostream>
using namespace std;

void swapSort(int *a, int n)
{
  for(int i = 0; i < n - 1; i++)
	for(int j = i+1; j < n; j++)
		if(a[i]>a[j])
			swap(a[i],a[j]);	
}

int main() {
	cout<<"Hello"<<endl;
  	int a[] = {5,3,35,21,2,4,57,4,1,10};
  	for(int i = 0; i < 10; i++)
	  cout<<a[i]<<",";
  	cout<<endl;
  	swapSort(a,10);
  	for(int i = 0; i < 10; i++)
	  cout<<a[i]<<",";
  	cout<<endl;
	return 0;
}
