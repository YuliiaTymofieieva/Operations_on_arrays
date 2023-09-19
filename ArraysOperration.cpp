// Yuliia Tymofieieva

#include <iostream>


void Add(int n, int* arr) { // podawana z gory jest liczba int, jezli ona mieszci sie w zakresie 1 - 4095, patrzymy na nasza tablice ( ktora jest posortowana) i jak nie ma tam naszej liczby to wstawiany ta liczbe do tablicy
    int size = 0;
    bool found = false;
    for (int i = 0; arr[i] != -1; i++) {
        size++;
        if (arr[i] == n) {
            found = true;
        }
    }
    if (found == false && size < 4094 && n < 4096 && n > 0) {
        arr[size] = n;
        size++;
    }
    arr[size] = -1;

    int temp;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Create(int n, int* cr, int* arr) { // tytaj nie mamy posortowanej tablicy cxyli musimy posortowac 
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (cr[i] > 0 && cr[i] < 4096) {
            arr[k++] = cr[i];
        }
    }
    arr[k] = -1;

    int size = k;
    int temp;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}

void Union(int* first, int* second, int* arr) {
    int i = 0;
    int size = 0;
    for (i; first[i] != -1; i++) {
        arr[i] = first[i];
        size++;
    }

    for (int j = 0; second[j] != -1; i++, j++) {
        arr[i] = second[j];
        size++;
    }

    arr[i] = -1;

    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}

void Intersection(int* first, int* second, int* arr) {

    int k = 0;
    for (int i = 0; first[i] != -1; i++) {
        for (int j = 0; second[j] != -1; j++) {
            if (first[i] == second[j]) {
                arr[k] = first[i];
                k++;
                break;
            }
        }
    }
    arr[k] = -1;
    int size = k;
    int temp;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Difference(int* first, int* second, int* arr) {
    bool found;
    int k = 0;
    for (int i = 0; first[i] != -1; i++) {
        found = false;
        for (int j = 0; second[j] != -1; j++) {
            if (first[i] == second[j]) {
                found = true;
            }
        }
        if (found == false) {
            arr[k] = first[i];
            k++;
        }
    }
    arr[k] = -1;
    int size = k;

    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Symmetric(int* a, int* b, int* arr) {
    int res_index = 0;
    for (int i = 0; a[i] != -1; i++) {
        bool found = false;
        for (int j = 0; b[j] != -1; j++) {
            if (a[i] == b[j]) {
                found = true;
            }
        }
        if (found == false) {
            arr[res_index] = a[i];
            res_index++;
        }
        else {
            found = false;
        }
    }

    for (int i = 0; b[i] != -1; i++) {
        bool found = false;
        for (int j = 0; a[j] != -1; j++) {
            if (a[i] == b[j]) {
                found = true;
            }
        }
        if (found == false) {
            arr[res_index] = b[i];
            res_index++;
        }
        else {
            found = false;
        }
    }
    arr[res_index] = -1;

    int size = res_index;

    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}
void Complement(int* arr, int* second) {
    int res_index = 0;
    for (int i = 0; arr[i] != -1; i++) {
        res_index++;
    }
    for (int j = 0; second[j] != -1; j++) {
        arr[res_index] = second[j];
        res_index++;
    }

    arr[res_index] = -1;
    int size = res_index;

    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}


bool Subset(int* first, int* second) {
    bool found = false;
    for (int i = 0; second[i] != -1; i++) {
        found = false;
        for (int j = 0; first[j] != -1; j++) {
            if (first[j] == second[i]) {
                found = true;
            }
        }
        if (found == false) {
            return false;
        }
    }

    return true;
}

bool Equal(int* first, int* second) {
    bool found = false;
    for (int i = 0; first[i] != -1; i++) {
        for (int j = 0; second[j] != -1; j++) {
            if (first[i] == second[j]) {
                found = true;
            }
        }
        if (found == false) {
            return false;
        }
        else {
            found = false;
        }
    }

    for (int i = 0; second[i] != -1; i++) {
        for (int j = 0; first[j] != -1; j++) {
            if (first[j] == second[i]) {
                found = true;
            }
        }
        if (found == false) {
            return false;
        }
        else {
            found = false;
        }
    }


    return true;
}


bool Empty(int* first) {
    bool found = false;

    if (first[0] == -1)
    {
        found = true;
    }
    else {
        found = false;
    }

    return found;
}


bool Nonempty(int* first) {
    bool found = false;

    if (first[0] == -1)
    {
        found = false;
    }
    else {

        found = true;
    }

    return found;
}


bool Element(int a, int* first) {

    for (int i = 0; first[i] != -1; i++) {
        if (a == first[i]) {
            return true;

        }
    }
    return false;

}

double Arithmetic(int* kolbasa) {
    double a = 0;
    int i = 0;
    for (i; kolbasa[i] != -1; i++) {
        a += kolbasa[i];

    }
    return a / i;
}
double Harmonic(int* kolbasa) {
    double a = 1;
    int i = 0;
    for (i; kolbasa[i] != -1; i++) {
        a *= kolbasa[i];
    }
    return (a, 1 / i);
}