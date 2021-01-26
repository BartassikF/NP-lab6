#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 6; // Liczebnoœæ zbioru. Nie wstawiaj liczb
                 // wiêkszych od 9, bo mo¿esz siê nie
                 // doczekaæ rozwi¹zania
int d[N];

// Funkcja sprawdzaj¹ca uporz¹dkowanie w zbiorze
//-----------------------------------------------------
bool Posortowane()
{
  int i;

  for(i = 0; i < N - 1; i++) if(d[i] > d[i+1]) return false;
  return true;
}

// Procedura tasuj¹ca zbiór
//-------------------------
void Tasuj()
{
  int i,i1,i2;

  for(i = 1; i <= 3 * N; i++)
  {
    i1 = rand() % N; i2 = rand() % N;
    swap(d[i1], d[i2]);
  }
}

//******************************************************

int main()
{
  int i;

  cout << "Sortowanie  zwariowane\n"
          "----------------------\n"
          "(C)2005 Jerzy Walaszek\n\n";

// Najpierw wype³niamy tablicê d[] liczbami pseudolosowymi
// a nastêpnie wyœwietlamy jej zawartoœæ

  srand((unsigned)time(NULL));

  for(i = 0; i < N; i++) d[i] = rand() % 10000;
  cout << "Przed sortowaniem:\n\n";
  for(i = 0; i < N; i++) cout << setw(6) << d[i];
  cout << endl << endl;

// Sortujemy

  while(!Posortowane()) Tasuj();

// Wyœwietlamy wynik sortowania

  cout << "Po sortowaniu:\n\n";
  for(i = 0; i < N; i++) cout << setw(6) << d[i];
  cout << endl << endl;
  return 0;
}
