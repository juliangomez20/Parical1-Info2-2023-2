

#include <iostream>


using namespace std;


const int columnas = 8, filas = 8;

void verificacion(int **matriz);

void patron1(int **matriz);

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
patron1(matriz);


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

void patron1(int **matriz)
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
