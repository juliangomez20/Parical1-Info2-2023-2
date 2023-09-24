#include <iostream>

using namespace std;

const int columnas = 8, filas = 8;

int** crearMatriz() {
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = 0;
        }
    }
    return matriz;
}

void liberarMatriz(int** matriz) {
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void imprimirMatriz(int** matriz) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "[" << matriz[i][j] << "]";
        }
        cout << endl;
    }
}

void encenderLEDs(int** matriz) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = 1;
        }
    }
    imprimirMatriz(matriz);
    cout<<endl;
        for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = 0;
        }
    }

    imprimirMatriz(matriz);
}

void mostrarImagen(int** matriz) {
    cout << "Ingrese el patrón de la matriz (0: apagado, 1: encendido), o ingrese 'fin' para terminar:" << endl;

        for (int i = 0; i < filas; i++) {
        string entrada;
        cin >> entrada;

        if (entrada == "fin") {
            break; // Salir si el usuario ingresa 'fin'
        }

        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = entrada[j] - '0'; // Convertir de char a int
        }
    }

    imprimirMatriz(matriz);
}

void generarPatron(int** matriz, int patron) {
    // Implementa la lógica para los patrones aquí
    switch (patron) {
    case 1:
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
        break;

    case 2:
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                matriz[i][j] = 0;
            }
        }

        for (int i = 0; i < filas; i++) {
            matriz[i][i] = 1;
            matriz[i][7 - i] = 1;
        }
        break;

    case 3:
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
        break;

    case 4:
        for (int fila = 0; fila < filas; fila++) {
            for (int col = 0; col < columnas; col++) {
                if ((fila == 0 && col >= 0 && col <= 3) || (fila == 1 && col >= 1 && col <= 4) || (fila == 2 && col >= 2 && col <= 5) || (fila == 3 && col >= 3 && col <= 6) || (fila == 4 && col >= 3 && col <= 6) || (fila == 5 && col >= 2 && col <= 5) || (fila == 6 && col >= 1 && col <= 4) || (fila == 7 && col >= 0 && col <= 3)) {
                    matriz[fila][col] = 1;
                } else {
                    matriz[fila][col] = 0;
                }
            }
        }


        break;

    default:
        cout << "Patron no válido." << endl;
    }

    imprimirMatriz(matriz);
}

void publik(int** matriz) {
    char comando;

    while (true) {
        cout << "Ingrese un comando (v: Verificar, i: Mostrar Imagen, 1-4: Mostrar Patron, q: Salir): ";
                cin >> comando;

        switch (comando) {
        case 'v':
            encenderLEDs(matriz);
            break;
        case 'i':
            mostrarImagen(matriz);
            break;
        case '1':
        case '2':
        case '3':
        case '4':
            generarPatron(matriz, comando - '0'); // Convertir char a int
            break;
        case 'q':
            liberarMatriz(matriz);
            return;
        default:
            cout << "Comando no valido!!" << endl;
        }
    }
}

int main() {
    int** matriz = crearMatriz();
    publik(matriz);

    return 0;
}
