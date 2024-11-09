#include <iostream>

#include <algorithm>

using namespace std;

const int DIM_VET = 6;
const int NUM_RIGHE = 2;
const int NUM_COL = 3;

int NumeroDistintiVettore(int v[], int n);
int NumeroDistintiMatrice(int m[][NUM_COL], int righe, int col);

int main()
{
  int vett[DIM_VET];
  int mat[NUM_RIGHE][NUM_COL];
  int i, j;

  cout << "Inserisci un vettore di " << DIM_VET << " valori interi : ";
  for (i = 0; i < DIM_VET; i++)
    cin >> vett[i];
  cout << "Il numero di elementi distinti del vettore e' " 
       << NumeroDistintiVettore(vett,DIM_VET) << endl; 

  cout << "Inserisci una matrice di " << NUM_RIGHE 
       << " righe e " << NUM_COL << " colonne" << endl;
  for (i = 0; i < NUM_RIGHE; i++)
    for (j = 0; j < NUM_COL; j++)
      cin >> mat[i][j];

  cout << "Il numero di elementi distinti della matrice e' " 
       << NumeroDistintiMatrice(mat,NUM_RIGHE,NUM_COL) << endl; 
}

int NumeroDistintiVettore(int v[], int n)
{
  // INSERIRE QUI IL CORPO DELLA FUNZIONE
  int i, cnt = 1, temp = v[0];
  sort(v, v + n);
  for(i = 0; i < n; i++){
    if (temp != v[i]){
        temp = v[i];
        cnt++;
    }
  }
    return cnt;
}

int NumeroDistintiMatrice(int m[][NUM_COL], int righe, int col)
{
  // INSERIRE QUI IL CORPO DELLA FUNZIONE
  // guardare i triangoli superiori e basta
  
}