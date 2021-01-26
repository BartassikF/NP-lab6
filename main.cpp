#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int liczba, n;

	//cout<<"Ile liczb bêdziesz chcia³ posortowaæ? ";
	cin>>n;

	int p = 2000000000/n;  //zakres jednego kube³ka
	//przedzia³y dla kolejnych kube³kow:
	//[0, p), [p, 2p), [2p, 3p), ..., [(n-1)p, n*p)

	vector  kubelki[n]; //tworzymy kube³ki

	//wczytanie liczb i wrzucenie ich do odpowiednich kube³ków
	for(int i=0;i<n;i++)
	{
		cin>>liczba;
		//wrzucam liczbê do odpowiedniego kube³ka
		kubelki[liczba/p].push_back(liczba);
	}
	//sortowanie elementów w poszczególnych kube³kach
	for(int i=0;i<n;i++)
	//sortujemy tylko, jesli kube³ek ma co najmniej dwie liczby
	if(kubelki[i].size()>1)
		sort(kubelki[i].begin(), kubelki[i].end());

	//wypisanie posortowanych liczb
	for(int i=0;i<n;i++)
		for(int j=0;j<kubelki[i].size();j++)
			cout<<kubelki[i][j]<<' ';

	return 0;
}
