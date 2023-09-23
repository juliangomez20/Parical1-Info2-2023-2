
#include <iostream>


using namespace std;


const int columnas = 8, filas = 8;

void verificacion(int **matriz);

void patron1(int **matriz);

void patron2(int **matriz);

void patron3(int **matriz);

int main()
{


int **matriz= new int*[filas];
for (int i = 0;i<filas;i++)
{
matriz[i] = new int[columnas];
}


for(int i = 0;i<filas;i++)
{
    cout<<endl;
for(int j = 0; j<columnas;j++)
{
matriz[i][j] = 0;
cout<<"["<<matriz[i][j]<<"]";
}

}

cout<<endl;
verificacion(matriz);

cout<<endl;
patron2(matriz);

cout<<endl;
cout<<"Aquí patron 1"<<endl;
patron1(matriz);

cout<<endl;
cout<<"Aquí patron 3"<<endl;
patron3(matriz);




    return 0;
}


void verificacion(int **matriz)
{
  for(int i = 0;i<filas;i++)
{
    cout<<endl;
for(int j = 0; j<columnas;j++)
{
matriz[i][j] = 1;
cout<<"["<<matriz[i][j]<<"]";
}

}
cout<<endl;
  for(int i = 0;i<filas;i++)
{
    cout<<endl;
for(int j = 0; j<columnas;j++)
{
matriz[i][j] = 0;
cout<<"["<<matriz[i][j]<<"]";
}

}

}

void patron2(int **matriz)
{
  for(int i = 0;i<filas;i++)
{
    cout<<endl;
for(int j = 0; j<columnas;j++)
{
matriz[i][j] = 0;
cout<<"["<<matriz[i][j]<<"]";
}}

for(int i = 0;i<filas;i++){
matriz[i][i] = 1;
matriz[i][7-i]=1;

}

  for(int i = 0;i<filas;i++)
{
    cout<<endl;
for(int j = 0; j<columnas;j++)
{
cout<<"["<<matriz[i][j]<<"]";
}
}
}

void patron1(int **matriz){
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                matriz[i][j] = 0;
            }
        }

for (int i = 0; i < 4; ++i) {
for (int j = 3 - i; j <= 4 + i; ++j) {
matriz[i][j] = 1;
matriz[7 - i][j] = 1;
}
}
 for (int i = 0; i < filas; ++i) {
for (int j = 0; j < columnas; ++j) {
cout << "[" << matriz[i][j] << "]";
}
cout <<endl; // Cambiar de línea al final de cada fila
}
}

void patron3(int **matriz){
    for (int fila = 0; fila < 8; fila++) {
        for (int col = 0; col < 8; col++) {
            int patron = (fila / 2) % 4;
            if (patron == 0 || patron == 2) {
                if ((col == 0) || (col == 1) || (col == 3) || (col == 4) || (col == 6) || (col == 7)) {
                    matriz[fila][col] = 1;
                } else {
                    matriz[fila][col] = 0;
                }
            } else {
                if ((col == 1) || (col == 2) || (col == 4) || (col == 5) || (col == 7)) {
                    matriz[fila][col] = 1;
                } else {
                    matriz[fila][col] = 0;
                }
            }
        }
    }

for (int fila = 0; fila < 8; fila++) {
        for (int col = 0; col < 8; col++) {
            cout << matriz[fila][col] << " ";
        }
        cout<<endl;
    }
}
