#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdio>

#include "HaromszogMatrix.h"

using namespace std;

void initAlso(HaromszogMatrix &hMatrix) {
    hMatrix.adatok = new float*[hMatrix.n] {0};
    for(int i = 0; i < hMatrix.n; i++) {
        hMatrix.adatok[i] = new float[i+1] {0};
    }
}

void initFelso(HaromszogMatrix &hMatrix){
    hMatrix.adatok = new float*[hMatrix.n] {0};
    for(int i = 0; i < hMatrix.n; i++) {
        hMatrix.adatok[i] = new float[hMatrix.n-i] {0};
    }
}

void initTomb(HaromszogMatrix &hMatrix) {
    hMatrix.tomb = new int[hMatrix.n*(hMatrix.n+1)/2];

}

void felsz(int &n, float **&Matrix) {
    for(int i = 0; i < n; i++) {
        delete[] Matrix[i];
    }
    delete[] Matrix;
}

void felszFelsoHaromszog(int &n, HaromszogMatrix &hMatrix) {
    for(int i = 0; i < n; i++) {
        delete[] hMatrix.adatok[n-i];
    }
    delete[] hMatrix.adatok;
}

void felszAlsoHaromszog(int &n, HaromszogMatrix &hMatrix) {
    for(int i = 0; i < n; i++) {
        delete[] hMatrix.adatok[n+i];
    }
    delete[] hMatrix.adatok;
}

void beolvasTeljesMatrix(float **&Matrix, int &n) {

    cout << "Olvasd be a matrix meretet: ";
    cin >> n;

    Matrix = new float*[n];
    for(int i = 0; i < n; i++) {
        Matrix[i] = new float[n];
    }

    cout << "Olvasd be a matrixot: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> Matrix[i][j];
        }
    }

}

void beolvasTeljesMatrixFilebol(const char filename[], float **&Matrix, int &n) {
    ifstream fin(filename);

    fin >> n;

    Matrix = new float*[n];
    for(int i = 0; i < n; i++) {
        Matrix[i] = new float[n];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            fin >> Matrix[i][j];
        }
    }

    fin.close();
}

void beolvasStdMatrix(HaromszogMatrix &hMatrix) {
    cout << "Olvasd be a matrix meretet: ";
    cin >> hMatrix.n;
    cout << "Add meg hogy felso haromszog(1) vagy also haromszog(0): ";
    cin >> hMatrix.felsoHaromszog;

    cout << "Olvasd be a matrixot: " << endl;
    if(hMatrix.felsoHaromszog) {
        initFelso(hMatrix);
        for(int i = 0; i < hMatrix.n; i++) {
            for(int k = 0; k < i; k++) {
                    cout << setw(2) << " ";
            }
            for(int j = 0; j < hMatrix.n-i; j++) {
                cin >> hMatrix.adatok[i][j];
            }
        }
    }
    else{
        initAlso(hMatrix);
        for(int i = 0; i < hMatrix.n; i++) {
            for(int j = 0; j < i+1; j++) {
                cin >> hMatrix.adatok[i][j];
            }
        }
    }
}

void beolvasStdTombbe(HaromszogMatrix &hMatrix) {
    cout << "Olvasd be a matrix meretet: ";
    cin >> hMatrix.n;
    cout << "Add meg hogy felso haromszog(1) vagy also haromszog(0): ";
    cin >> hMatrix.felsoHaromszog;
    cout << "Olvasd be a tombot: ";

    initTomb(hMatrix);
    for(int i = 0; i < hMatrix.n*(hMatrix.n+1)/2; i++) {
        cin >> hMatrix.tomb[i];
    }
}


void beolvasFilebolTombbe(const char filename[], HaromszogMatrix &hMatrix) {
    ifstream fin(filename);

    fin >> hMatrix.n;
    fin >> hMatrix.felsoHaromszog;

    initTomb(hMatrix);
    for(int i = 0; i < hMatrix.n*(hMatrix.n+1)/2; i++) {
        fin >> hMatrix.tomb[i];
    }

    fin.close();
}

void beolvasFilebolMatrixkent(const char filename[], HaromszogMatrix &hMatrix) {
    ifstream fin(filename);

    fin >> hMatrix.n;
    fin >> hMatrix.felsoHaromszog;

    if(hMatrix.felsoHaromszog) {
        // 1 2 3
        //   4 5
        //     6
        initFelso(hMatrix);

        for(int i = 0; i < hMatrix.n; i++) {
            for(int j = 0; j < hMatrix.n-i; j++) {
                fin >> hMatrix.adatok[i][j];
            }
        }
    }
    else{
        // 1
        // 2 3
        // 4 5 6
        initAlso(hMatrix);

        for(int i = 0; i < hMatrix.n; i++) {
            for(int j = 0; j < i+1; j++) {
                fin >> hMatrix.adatok[i][j];
            }
        }
    }

    fin.close();
}



void kiirMatrixkent(HaromszogMatrix &hMatrix) {
    cout << "HaromszogMatrix merete: " << hMatrix.n << endl;
    if(hMatrix.felsoHaromszog) {
        cout << "Felso haromszog." << endl;
    }
    else {
        cout << "Also haromszog." << endl;
    }
    cout << endl;

    if(hMatrix.felsoHaromszog) {

        for(int i = 0; i < hMatrix.n; i++) {

            for(int k = 0; k < i; k++) {
                cout << setw(10) << " ";
            }

            for(int j = 0; j < hMatrix.n-i; j++) {
                //cout << "a" << endl;
                cout << setw(10) << fixed << setprecision(1) << hMatrix.adatok[i][j];  // 3 poziciot probal a kepernyon foglalni
                //cout << "b" << endl;
            }

            cout << endl;
        }
        cout << endl;
    }
    else{
        for(int i = 0; i < hMatrix.n; i++) {
            for(int j = 0; j < i+1; j++) {
                cout << setw(10) << fixed << setprecision(1) << hMatrix.adatok[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void kiirTombkent(HaromszogMatrix &hMatrix) {
    cout << hMatrix.n << " " << hMatrix.felsoHaromszog;
    cout << endl;

    for(int i = 0; i < hMatrix.n*(hMatrix.n+1)/2; i++) {
        cout << hMatrix.tomb[i] << " ";
    }
    cout << endl;
}

void kiirFilebaMatrixkent(ofstream& fout, HaromszogMatrix &hMatrix) {

    fout << hMatrix.n << " " << hMatrix.felsoHaromszog << endl;
    if(hMatrix.felsoHaromszog) {
        for(int i = 0; i < hMatrix.n; i++) {

            for(int k = 0; k < i; k++) {
                fout << setw(10) << " ";
            }

            for(int j = i; j < hMatrix.n; j++) {
                fout << setw(10) << hMatrix.adatok[i][j];  // 3 poziciot probal a kepernyon foglalni
            }

            fout << endl;
        }
        fout << endl;
    }
    else{
        for(int i = 0; i < hMatrix.n; i++) {

            for(int j = 0; j < i+1; j++) {

                fout << setw(10) << hMatrix.adatok[i][j] << " ";
            }

            fout << endl;
        }
        fout << endl;
    }
    fout << endl;

}

void kiirFilebaTombkent(ofstream& fout, HaromszogMatrix &hMatrix) {

    fout << hMatrix.n << " " << hMatrix.felsoHaromszog << endl;
    if(hMatrix.felsoHaromszog) {
        for(int i = 0; i < hMatrix.n*(hMatrix.n+1)/2; i++) {
            fout << hMatrix.tomb[i] << " ";
        }
    }
    else {
        for(int i = 0; i < hMatrix.n*(hMatrix.n+1)/2; i++) {
            fout << hMatrix.tomb[i] << " ";
        }
    }

}

void kiirOsszegSor(HaromszogMatrix &hMatrix) {
    for(int i = 0; i < hMatrix.n; i++) {
        cout << i+1 << ". sor osszege" << hMatrix.osszegSor[i] << " ";
    }
    cout << endl;
}

void kiirOsszegSorFileba(ofstream& fout, HaromszogMatrix &hMatrix) {

    for(int i = 0; i < hMatrix.n; i++) {
        fout << i+1 << ". sor osszege: " << hMatrix.osszegSor[i] << endl;
    }
    fout << endl;

}

void kiirOsszegOszlop(HaromszogMatrix &hMatrix) {
    for(int i = 0; i < hMatrix.n; i++) {
        cout << i+1 << ". oszlop osszege" << hMatrix.osszegSor[i] << " ";
    }
    cout << endl;
}

void kiirOsszegOszlopFileba(ofstream& fout, HaromszogMatrix &hMatrix) {

    for(int i = 0; i < hMatrix.n; i++) {
        fout << i+1 << ". oszlop osszege: " << hMatrix.osszegSor[i] << endl;
    }
    fout << endl;

}

void kiirTeljesMatrix(float **&Matrix, int &n) {
    cout << "Matrix merete = " << n << endl;
    cout << "A matrix: " << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void kiirTeljesMatrixFileba(float **&Matrix, int &n, ofstream& fout) {

    fout << "Matrix merete = " << n << endl;
    fout << "A matrix: " << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            fout << Matrix[i][j] << " ";
        }
        fout << endl;
    }
    fout << endl;
}

void sorOsszeg(HaromszogMatrix &hMatrix) {

    hMatrix.osszegSor = new int[hMatrix.n];
    int osszeg = 0;

    for(int i = 0; i < hMatrix.n; i++) {
        for(int j = 0; j < hMatrix.n; j++) {
            osszeg += hMatrix.adatok[i][j];
        }
        hMatrix.osszegSor[i] = osszeg;
        osszeg = 0;
    }
}

void oszlopOsszeg(HaromszogMatrix &hMatrix) {
    hMatrix.osszegOszlop = new int[hMatrix.n];
    int osszeg = 0;
    for(int i = 0; i < hMatrix.n; i++) {
        for(int j = 0; j < hMatrix.n; j++) {
            osszeg += hMatrix.adatok[j][i];
        }
        hMatrix.osszegOszlop[i] = osszeg;
        osszeg = 0;
    }

}

long teljesOsszeg(HaromszogMatrix &hMatrix) {
    int osszeg = 0;
    if(hMatrix.felsoHaromszog) {
        for(int i = 0; i < hMatrix.n; i++) {
            for(int j = 0; j < hMatrix.n-i; j++) {
                osszeg += hMatrix.adatok[i][j];
            }
        }
    }
    else {
        for(int i = 0; i < hMatrix.n; i++) {
            for(int j = 0; j < i+1; j++) {
                osszeg += hMatrix.adatok[i][j];
            }
        }
    }

    return osszeg;
}



HaromszogMatrix transzponalt(HaromszogMatrix &hMatrix) {

    HaromszogMatrix transponaltMatrix;

    if (hMatrix.felsoHaromszog) {

        transponaltMatrix.felsoHaromszog = !hMatrix.felsoHaromszog;             // felsobol lesz also
        transponaltMatrix.n = hMatrix.n;

        initFelso(transponaltMatrix);

        for (int i = 0; i < transponaltMatrix.n; i++) {
            for (int j = 0; j < i + 1; j++) {

                transponaltMatrix.adatok[i][j] = hMatrix.adatok[j][i - j];

            }
        }
    }
    else {

        transponaltMatrix.felsoHaromszog = !hMatrix.felsoHaromszog;           // alsobol lesz felso
        transponaltMatrix.n = hMatrix.n;

        initAlso(transponaltMatrix);                                        // meretuk megegyezik

        for (int i = 0; i < transponaltMatrix.n; i++) {
            for (int j = 0; j < transponaltMatrix.n - i; j++) {

                transponaltMatrix.adatok[i][j] = hMatrix.adatok[j + i][i];

            }
        }
    }

    return transponaltMatrix;
}

void LU(float **&Matrix, int &n, HaromszogMatrix &hMatrix_1, HaromszogMatrix &hMatrix_2) {
    hMatrix_1.n = n;
    hMatrix_1.felsoHaromszog = 0;   // also lesz

    hMatrix_2.n = n;
    hMatrix_2.felsoHaromszog = 1;   // felso lesz


    if(n > 1) {

        hMatrix_1.adatok = new float*[n] {0};
        for(int i = 0; i < n; i++) {
            hMatrix_1.adatok[i] = new float[n] {0};
        }

        hMatrix_2.adatok = new float*[n] {0};
        for(int i = 0; i < n; i++) {
            hMatrix_2.adatok[i] = new float[n] {0};
        }

        for(int i = 0; i < n; i++) {

            // felso haromszog
            for(int k = i; k < n; k++) {

                int sum = 0;
                for(int j = 0; j < i; j++) {
                    cout << hMatrix_1.adatok[i][j] << " * " << hMatrix_2.adatok[j][k] << " ";
                    sum += (hMatrix_1.adatok[i][j] * hMatrix_2.adatok[j][k]);

                }
                cout << sum << endl;
                cout << endl;
                cout << Matrix[i][k] << " - " << sum << endl;
                hMatrix_2.adatok[i][k] = Matrix[i][k] - sum;
                cout << "Matrixba kerul = " << hMatrix_2.adatok[i][k] << endl;
                cout << endl;
            }



            // also
            for(int k = i; k < n; k++) {
                if(i == k) {
                    hMatrix_1.adatok[i][i] = 1;
                }
                else {
                    int sum = 0;
                    for(int j = 0; j < i; j++) {
                        sum += (hMatrix_1.adatok[k][j] * hMatrix_2.adatok[j][i]);
                    }
                    cout << i << " ----- " << Matrix[k][i] <<  " - " << sum << " / " << hMatrix_2.adatok[i][i] << endl;
                    hMatrix_1.adatok[k][i] = (Matrix[k][i] - sum) / hMatrix_2.adatok[i][i];
                }

                cout << i << "----> Matrixba kerul: " << hMatrix_1.adatok[k][i] << endl;
            }
        }
    }
}

void szorzat(int &n, HaromszogMatrix &hMatrix_1, HaromszogMatrix &hMatrix_2, float **&EllenorzoMatrix) {
    // hMatrix_1 also , hMatrix_2 felso
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                EllenorzoMatrix[i][j] += (hMatrix_1.adatok[i][k]) * (hMatrix_2.adatok[k][j]);
            }
        }
    }
}

bool egyenloE(int &n, float **&Matrix, float **&EllenorzoMatrix) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(Matrix[i][j] != EllenorzoMatrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool bonthatoE(int &n, float **&Matrix) {
    for(int i = 0; i < n; i++) {
        if(Matrix[i][i] == 0)
            return false;
    }
    return true;
}

float determinans(int n, float **&Matrix) {
    float det = 0;
    float **temp = new float*[n];
    for(int i =0; i < n; i++) {
        temp[i] = new float[n];
    }

    if(n == 2) {
        return ((Matrix[0][0] * Matrix[1][1]) - (Matrix[1][0] * Matrix[0][1]));
    }
    else {
        for(int i = 0; i < n; i++) {
            int subj = 0;
            for(int j = 1; j < n; j++) {
                int subk = 0;
                for(int k = 0; k < n; k++) {
                    if(i == k) {
                        continue;
                    }
                    temp[subj][subk] = Matrix[j][k];
                    subk++;
                }
                subj++;
            }
            det += (pow(-1, i) * Matrix[0][i] * determinans(n-1, temp));
        }
    }

    felsz(n, temp);
    return det;
}

float HaromszogMatrixDeterminans(int n, HaromszogMatrix &hMatrix_1, HaromszogMatrix &hMatrix_2) {

    float det1 = 1, det2 = 1;
    for(int i = 0; i < n; i++) {
        det1 *= (hMatrix_1.adatok[i][i]);
        det2 *= (hMatrix_2.adatok[i][i]);
    }

    return (int)det1*det2;
}


