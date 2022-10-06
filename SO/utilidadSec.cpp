/*
 * UNIVERSIDAD DEL ISTMO
 * Sistemas Operativos
 *
 * utilidadSec.cpp
 * Diego V
 */

#include <iostream>
#include <stdio.h>		
#include <cmath>		
#include <vector>
#include <unistd.h>
#include <numeric>
#include <ctime>

using namespace std;

const int JULIO = 8;
long long ventas_total_julio = 0.0;
long long utilidad_total_julio = 0.0;
vector<int> unidad_julio{300, 400, 1590, 200, 390, 1455, 800, 60};
vector<double>ventas_julio(8);
vector<double>utilidad_julio(8);

const int AGOSTO = 8;
long long ventas_total_agosto = 0.0;
long long utilidad_total_agosto = 0.0;
vector<int> unidad_agosto{250, 380, 800, 250, 600, 1200, 1540, 15};
vector<double>ventas_agosto(8);
vector<double>utilidad_agosto(8);

vector<double> precio{60.00, 32.00, 22.00, 24.00, 28.00, 24.00, 32.00, 60.00};
vector<double> costo{20.00, 19.20, 13.20, 17.20, 20.10, 17.20, 23.00, 20.00};
vector<string> nombres{"Porcion Pastelito Chocolate", "White Mocha", "Cafe americano 8onz", "Latte 8onz", "Toffee Coffee", "Capucchino 8onz", "Smores Latte", "Cafe Tostado Molido"};


void julio(float item) {
    float valor = item;
    float ventasProducto, utilidadProducto, totalVentas, totalUtilidad;
    cout << "calculo JULIO " << valor << " iniciado." << endl;
    sleep(1);
    ventasProducto = unidad_julio[valor] * precio[valor];
    utilidadProducto = ventasProducto - (costo[valor] * unidad_julio[valor]);
    ventas_julio[valor] = ventasProducto;
    utilidad_julio[valor] = utilidadProducto;

};

void agosto(float item) {
    float valor = item;
    float ventasProducto, utilidadProducto, totalVentas, totalUtilidad;
    cout << "calculo AGOSTO " << valor << " iniciado." << endl;
    sleep(1);
    ventasProducto = unidad_agosto[valor] * precio[valor];
    utilidadProducto = ventasProducto - (costo[valor] * unidad_agosto[valor]);
    ventas_agosto[valor] = ventasProducto;
    utilidad_agosto[valor] = utilidadProducto;

};

int main() {
    float j, a, rcJ, rcA;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for(long long i = 0; i < JULIO; i++) {
        julio(i);
    }

    for(long long i = 0; i < AGOSTO; i++) {
        agosto(i);
    }


    cout << "--- REPORTE DEL MES DE JULIO ---\n" << endl;
    cout << "- Ventas por producto -" << endl;
    for(int i = 0; i < JULIO; i++) {
        cout << nombres[i] << ": Q." << ventas_julio[i] << endl;
    }
    cout << "\n- Utilidad por producto -" << endl;
    for (int i = 0; i < JULIO; i++) {
        cout << nombres[i] << ": Q." << utilidad_julio[i] << endl;
    }
    int costos_julio = 45640;
    cout << "\nTotal ventas: Q." << accumulate(ventas_julio.begin(), ventas_julio.end(), 0) << endl;
    cout << "Costos variables: Q." << costos_julio << endl;
    cout << "Utilidad del mes: Q." << (accumulate(utilidad_julio.begin(), utilidad_julio.end(), 0) - costos_julio) << "\n" << endl;

    cout << "--- REPORTE DEL MES DE AGOSTO ---\n" << endl; 
    cout << "- Ventas por producto -" << endl;
    for (int i = 0; i < AGOSTO; i++) {
        cout << nombres[i] << ": Q." << ventas_agosto[i] << endl;
    }
    cout << "\n- Utilidad por producto -" << endl;
    for (int i = 0; i < AGOSTO; i++) {
        cout << nombres[i] << ": Q." << utilidad_agosto[i] << endl;
    }
    int costos_agosto = 40590;
    cout << "\nTotal ventas: Q." << accumulate(ventas_agosto.begin(), ventas_agosto.end(), 0) << endl;
    cout << "Costos variables: Q." << costos_agosto << endl;
    cout << "Utilidad del mes: Q." << (accumulate(utilidad_agosto.begin(), utilidad_agosto.end(), 0) - costos_agosto) << "\n" << endl;

    clock_gettime(CLOCK_MONOTONIC, &end);
    double duration = end.tv_sec - start.tv_sec;
    duration += (end.tv_nsec - start.tv_nsec) / 1000000000.0;

    cout << duration << " segundos." << endl;
    
};
