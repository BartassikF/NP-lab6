#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int liczba, n;

	//cout<<"Ile liczb b�dziesz chcia� posortowa�? ";
	cin>>n;

	int p = 2000000000/n;  //zakres jednego kube�ka
	//przedzia�y dla kolejnych kube�kow:
	//[0, p), [p, 2p), [2p, 3p), ..., [(n-1)p, n*p)

	vector  kubelki[n]; //tworzymy kube�ki

	//wczytanie liczb i wrzucenie ich do odpowiednich kube�k�w
	for(int i=0;i<n;i++)
	{
		cin>>liczba;
		//wrzucam liczb� do odpowiedniego kube�ka
		kubelki[liczba/p].push_back(liczba);
	}
	//sortowanie element�w w poszczeg�lnych kube�kach
	for(int i=0;i<n;i++)
	//sortujemy tylko, jesli kube�ek ma co najmniej dwie liczby
	if(kubelki[i].size()>1)
		sort(kubelki[i].begin(), kubelki[i].end());

	//wypisanie posortowanych liczb
	for(int i=0;i<n;i++)
		for(int j=0;j<kubelki[i].size();j++)
			cout<<kubelki[i][j]<<' ';

	return 0;
}
