#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#define LINES_PER_SET 5 //Se establece 5 debido a la cantidad de sensores (5)

void print_matrix(vector<vector<string>>& matrix, int sets, ofstream& outfile);

int main() {
    ifstream file("datos.txt"); //Datos del guante capturados desde el monitor serial 
    if (!file) {
        cerr << "No se pudo abrir el archivo de entrada" << endl;
        return 1;
    }

    ofstream outfile("salida.txt");
    if (!outfile) {
        cerr << "No se pudo abrir el archivo de salida" << endl;
        return 1;
    }

    vector<vector<string>> matrix;
    string a, b, c;

    while (file >> a >> b >> c) {
        matrix.push_back({a, b, c});
    }
    file.close();

    int line_count = matrix.size();

    if (line_count % LINES_PER_SET != 0) {
        cout << "El número de líneas en el archivo no es múltiplo de " << LINES_PER_SET << "." << endl;
        return 1;
    }

    int sets = line_count / LINES_PER_SET;
    print_matrix(matrix, sets, outfile);

    outfile.close();

    return 0;
}

void print_matrix(vector<vector<string>>& matrix, int sets, ofstream& outfile) {
    for (int i = 0; i < LINES_PER_SET; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < sets; k++) {
                outfile << matrix[i + k * LINES_PER_SET][j] << " ";
            }
            outfile << ";"; // Caracter usado para identificar renglones en la matriz de matlab
            outfile << endl; //salto de linea
        }
    }
}

