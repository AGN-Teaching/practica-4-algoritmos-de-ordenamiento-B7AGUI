#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>
#include "ordenamiento_t.h"
#include "ordenamiento_rec_t.h"

using namespace std;
using namespace std::chrono;

void guardarTiempos(string nombreArchivo, double tiempos[], int numRepeticiones, int numAlgoritmos) {
    ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        archivo << "algoritmo 1 = merge_sort, algoritmo 2 = quick_sort, algoritmo 3 = bubble_sort, algoritmo 4 = insertion_sort, algoritmo 5 = select_sort"<< endl;
        archivo << "Tiempo de ejecución por cada repetición" << endl;

        for (int i = 0; i < numRepeticiones; i++) {
            archivo << "Repetición " << i + 1 << ":" << endl;
            for (int j = 0; j < numAlgoritmos; j++) {
                archivo << "\tAlgoritmo " << j + 1 << ": " << tiempos[i * numAlgoritmos + j] << " segundos" << endl;
            }
            archivo << endl;
        }
        archivo.close();
        cout << "Tiempos guardados en el archivo " << nombreArchivo << endl;
    } else {
        cerr << "No se pudo abrir el archivo para guardar los tiempos." << endl;
    }
}

duration<double> crear_arreglo(int *A, int TAM_ARREGLO, int RANGO_MAX) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    for (int i = 0; i < TAM_ARREGLO; i++) {
        int x = rand() % RANGO_MAX;
        A[i] = x;
    }
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

duration<double> ordenar_insertion_sort(int *A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    insertion_sort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

duration<double> ordenar_selection_sort(int *A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    selection_sort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

duration<double> ordenar_bubblesort(int *A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    bubblesort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

duration<double> ordenar_merge_sort(int *A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    merge_sort(A, 0, TAM_ARREGLO - 1);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

duration<double> ordenar_quicksort(int *A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    quicksort(A, 0, TAM_ARREGLO - 1);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

int *copiar_arreglo(int A[], int n) {
    int *aux = new int[n];
    for (int i = 0; i < n; i++) {
        aux[i] = A[i];
    }
    return aux;
}

void experimentos(int tam, int reps, bool ms, bool qs, bool buble, bool insertion, bool selection) {
    int TAM_ARREGLO = tam;
    int RANGO_MAX = 10 * TAM_ARREGLO;
    int REPETICIONES = reps;
    double t_prom_ms = 0.0;
    double t_prom_qs = 0.0;
    double t_prom_buble = 0.0;
    double t_prom_insertion = 0.0;
    double t_prom_selection = 0.0;

    // Número de algoritmos seleccionados
    int numAlgoritmos = 0;
    if (ms) numAlgoritmos++;
    if (qs) numAlgoritmos++;
    if (buble) numAlgoritmos++;
    if (insertion) numAlgoritmos++;
    if (selection) numAlgoritmos++;

    double *tiempos = new double[REPETICIONES * numAlgoritmos];

    srand((unsigned)time(0));
    for (int i = 0; i < REPETICIONES; i++) {
        cout << "*** REPETICION " << i + 1 << " ***" << endl;
        int *A = new int[TAM_ARREGLO];
        duration<double> tiempo;

        // Arreglo aleatorio
        cout << "Creando arreglo aleatorio de tamanio " << TAM_ARREGLO << "... " << flush;
        tiempo = crear_arreglo(A, TAM_ARREGLO, RANGO_MAX);
        cout << "\tCreado. ";
        cout << "\tTiempo: " << tiempo.count() << "s" << endl;

        int *aux;
        if (ms) {
            aux = copiar_arreglo(A, TAM_ARREGLO);
            cout << "Iniciando ordenamiento con MERGE SORT... " << flush;
            tiempo = ordenar_merge_sort(aux, TAM_ARREGLO);
            cout << "\tOrdenado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl;
            t_prom_ms = t_prom_ms + tiempo.count();
            tiempos[i * numAlgoritmos] = tiempo.count();
            delete[] aux;
        }

        if (qs) {
            aux = copiar_arreglo(A, TAM_ARREGLO);
            cout << "Iniciando ordenamiento con QUICKSORT... " << flush;
            tiempo = ordenar_quicksort(aux, TAM_ARREGLO);
            cout << "\tOrdenado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl;
            t_prom_qs = t_prom_qs + tiempo.count();
            tiempos[i * numAlgoritmos + 1] = tiempo.count();
            delete[] aux;
        }

        if (buble) {
            aux = copiar_arreglo(A, TAM_ARREGLO);
            cout << "Iniciando ordenamiento con bubblesort... " << flush;
            tiempo = ordenar_bubblesort(aux, TAM_ARREGLO);
            cout << "\tOrdenado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl;
            t_prom_buble = t_prom_buble + tiempo.count();
            tiempos[i * numAlgoritmos + 2] = tiempo.count();
            delete[] aux;
        }
        if (insertion) {
            aux = copiar_arreglo(A, TAM_ARREGLO);
            cout << "Iniciando ordenamiento con insertion short... " << flush;
            tiempo = ordenar_insertion_sort(aux, TAM_ARREGLO);
            cout << "\tOrdenado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl;
            t_prom_insertion = t_prom_insertion + tiempo.count();
            tiempos[i * numAlgoritmos + 3] = tiempo.count();
            delete[] aux;
        }
        if (selection) {
            aux = copiar_arreglo(A, TAM_ARREGLO);
            cout << "Iniciando ordenamiento con selection short... " << flush;
            tiempo = ordenar_selection_sort(aux, TAM_ARREGLO);
            cout << "\tOrdenado. ";
            cout << "\tTiempo: " << tiempo.count() << "s" << endl;
            t_prom_selection = t_prom_selection + tiempo.count();
            tiempos[i * numAlgoritmos + 4] = tiempo.count();
            delete[] aux;
        }

        delete[] A;
        cout << endl;
    }
    t_prom_ms = t_prom_ms / REPETICIONES;
    t_prom_qs = t_prom_qs / REPETICIONES;
    t_prom_buble = t_prom_buble / REPETICIONES;
    t_prom_insertion = t_prom_insertion / REPETICIONES;
    t_prom_selection = t_prom_selection / REPETICIONES;
    cout << "*** TIEMPO PROMEDIO ***" << endl;
    if (ms) {
        cout << "Merge sort:\t" << t_prom_ms << endl;
    }
    if (qs) {
        cout << "Quicksort:\t" << t_prom_qs << endl;
    }

    if (buble) {
        cout << "bubblesort:\t" << t_prom_buble << endl;
    }
    if (insertion) {
        cout << "insertion short:\t" << t_prom_insertion << endl;
    }
    if (selection) {
        cout << "selection short:\t" << t_prom_selection << endl;
    }

    guardarTiempos("tiempos.txt", tiempos, REPETICIONES, numAlgoritmos);

    // Calcular la desviación estándar
    double sumaCuadrados = 0.0;
    for (int i = 0; i < numAlgoritmos; i++) {
        double promedio = 0.0;
        for (int j = 0; j < REPETICIONES; j++) {
            promedio += tiempos[j * numAlgoritmos + i];
        }
        promedio /= REPETICIONES;

        for (int j = 0; j < REPETICIONES; j++) {
            sumaCuadrados += pow(tiempos[j * numAlgoritmos + i] - promedio, 2);
        }
    }

    double desviacionEstandar = sqrt(sumaCuadrados / (REPETICIONES * numAlgoritmos));
    cout << "Desviación estándar (en segundos)= " << desviacionEstandar << endl;

    delete[] tiempos;
}

bool incluirAlgoritmo(string listaAlgs, char alg) {
    size_t incluir = listaAlgs.find(alg);
    return incluir != string::npos;
}

int main() {
    int TAM_ARREGLO, REPETICIONES;
    string listaAlgoritmos;

    cout << "Tamaño del arreglo: ";
    cin >> TAM_ARREGLO;

    cout << "Numero de repeticiones: ";
    cin >> REPETICIONES;

    cout << "Ingrese la lista de algoritmos m=Merge Sort, q=Quicksort, i=insertion Sort, b=bubble Sort, s=selection Sort LOS 5 AL MISMO TIEMPO= mqibs " << endl;
    cin >> listaAlgoritmos;

    bool ms = incluirAlgoritmo(listaAlgoritmos, 'm');
    bool qs = incluirAlgoritmo(listaAlgoritmos, 'q');
    bool buble = incluirAlgoritmo(listaAlgoritmos, 'b');
    bool insertion = incluirAlgoritmo(listaAlgoritmos, 'i');
    bool selection = incluirAlgoritmo(listaAlgoritmos, 's');
    experimentos(TAM_ARREGLO, REPETICIONES, ms, qs, buble, insertion, selection);

    return EXIT_SUCCESS;
}
