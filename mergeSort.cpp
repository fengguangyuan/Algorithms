#include <iostream>
using namespace std;

void merge(int *res, int *temp, int start, int mid,  int end)
{
  int i = start;
  int k = start;
  int m = mid + 1;
  while(i != (mid + 1) && m != end+1)
	if(res[i] < res[m])
		temp[k++] = res[i++];
  	else temp[k++] = res[m++];
  while(i != mid+1)
	temp[k++]=res[i++];
  while(m != end+1)
	temp[k++] = res[m++];
  for(i = start;i <= end; i++)
	res[i] = temp[i];
}

void mergeSort(int *a, int *b, int l, int h)
{
  int mid;
  if(l < h)
  {
	mid = (l+h)>>1;
	mergeSort(a,b,l,mid);
	mergeSort(a,b,mid+1,h);
	merge(a,b,l,mid,h);
  }
}

int main() {
	cout<<"Hello"<<endl;
  	int a[] = {3,45,2,1,5,6,234,45,3,2};
	int *b = new int[sizeof a/sizeof(int)];
	mergeSort(a,b,0,sizeof a/sizeof(int)-1);
	for(int i = 0; i < sizeof a/sizeof(int);i++)
	  cout<<a[i]<<",";
	cout<<endl;
	return 0;
}
