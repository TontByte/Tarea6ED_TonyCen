// Tarea6ED_TonyCen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cmath>
#include "LinkedList.h"

using std::cout;
using std::runtime_error;
using std::cin;
using std::endl;
using std::pow;

int getNumValue(int maxIndex, int minIndex) {
    if (maxIndex < 0 || minIndex > maxIndex) {
        throw runtime_error("Implementacion erronea de getNumValue");
    }

    int res;
    bool gotten = false;

    while (!gotten) {
        cin >> res;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Seleccion invalida. Volver a intentar." << endl;
        }
        else if (res < 0 || res > maxIndex || res < minIndex) {
            cin.ignore(1000, '\n');
            cout << "Seleccion invalida. Volver a intentar." << endl;
        }
        else {
            cin.ignore(1000, '\n');
            gotten = true;
            return res;
        }
    }
}

void fillRand(LinkedList<int>& refList, int listSize) {
    int i = 0;
    while (i < listSize) {
        int randNum = rand() % 1000;
        refList.append(randNum);
        i++;
    }
}

int maxDigits(LinkedList<int>& refList) {
    if (refList.getSize() == 0) {
        throw runtime_error("Lista de referencia esta vacia. Secuencia incorrecta");
    }
    int temp = 0;
    for (refList.goToStart(); !refList.atEnd(); refList.next()) {
        if (refList.getElement() > temp) {
            temp = refList.getElement();
        }
    }

    if (temp == 0) {
        return 1;
    }

    int cant = 0;
    while (temp != 0) {
        cant++;
        temp = temp / 10;
    }
    return cant;
}

void radixSort(LinkedList<int>& refList, int base) {
    LinkedList<int> tempList;
    LinkedList<int> resList;
    int digitCant = maxDigits(refList);
    int cont = 0; //contador??
    while (cont < digitCant) {
        for (refList.goToStart(); !refList.atEnd(); refList.next()) {
            int num = refList.getElement();
            int digit = (num / (int)pow(10, cont)) % 10;

        }
    }
}


//exponente no es para cantidad de baldes, pero para cantidad de digitos
//(num/pow(10,exponent))%10
//converted with base itd be (num/pow(base,exponent))%base

int main(){
    cout << "Ingrese el tamaño de la lista que desea ordenar (mayor que 1): " << endl;
    int listSize = getNumValue(2147483647, 1);
    LinkedList<int>* lista = new LinkedList<int>();

    cout << "Ingrese la base numerica que desea utilziar en el ordenamiento (mayor que 2): " << endl;
    int base = getNumValue(2147483647, 1);

    srand(time(0));
    fillRand(*lista, listSize);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
