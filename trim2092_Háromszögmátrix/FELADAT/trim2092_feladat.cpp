#include <iostream>
#include <fstream>

#include "HaromszogMatrix.h"

using namespace std;

int main()
{
    float **Matrix;
    int n;

    ofstream fout("kimenet_2.txt");

    beolvasTeljesMatrixFilebol("bemenet_2.txt", Matrix, n); // lefoglalja dinamikusan a matrix
    kiirTeljesMatrixFileba(Matrix, n, fout);
    if(n < 2) {
        fout << "Nem Letezik dekompozicio a kiebb mint 2x2 matrixokra." << endl;
    }
    else {
        bool bonthato = bonthatoE(n, Matrix);
        if(!bonthato) {
            fout << "NEM bonthato fel LU dekompozicioval. :(" << endl;
        }
        else {

            float det = determinans(n, Matrix); // lefoglal es szabadit
            fout << "A beolvasott matrix determinansa = " << det << endl;
            if(det == 0) {
                fout << "Letezik megoldas, ugy hogy az L vagy U haromszog matrixnak az atloin 1-sek vannak." << endl;
            }
            else {
                fout << "Letezik tobb megoldas." << endl;
            }

            HaromszogMatrix hMatrix_1;
            HaromszogMatrix hMatrix_2;

            LU(Matrix, n, hMatrix_1, hMatrix_2);

            kiirFilebaMatrixkent(fout, hMatrix_1);

            kiirFilebaMatrixkent(fout, hMatrix_2);

            float **EllenorzoMatrix = new float*[n] {0}; // ez van foglalva
            for(int i = 0; i < n; i++) {
                EllenorzoMatrix[i] = new float[n] {0};
            }

            szorzat(n, hMatrix_1, hMatrix_2, EllenorzoMatrix);

            //for(int i = 0; i < n; i++) {
                //for(int j = 0; j < n; j++) {
                    //cout << EllenorzoMatrix[i][j] << " ";
                //}
                //cout << endl;
            //}

            bool egyenloek = egyenloE(n, Matrix, EllenorzoMatrix);
            if(egyenloek) {
                fout << "Helyes felbontas!" << endl;
                fout << endl;

                float LUDet = HaromszogMatrixDeterminans(n, hMatrix_1, hMatrix_2);
                if(LUDet == -0 || LUDet == 0) {
                    LUDet = 0;
                    fout << "A Matrix determinansa = " << LUDet << endl;
                }
                else
                    fout << "A matrix determinansa = " << LUDet << endl;

                if(det == LUDet) {
                    fout << "MEGEGYEZIIIIK!!!" << endl;
                }

            }
            else {
                fout << "Nem helyes felbontas" << endl;
            }

            felsz(n, EllenorzoMatrix);
            felsz(n, Matrix);
        }
    }

    fout.close();

    return 0;
}


                //HaromszogMatrix TranszponaltA;
               // HaromszogMatrix TranszponaltB;

                //TranszponaltA = transzponalt(hMatrix_1);
//fout << "Transponalt A : " << endl;
              //  kiirFilebaMatrixkent(fout, TranszponaltA);
               // cout << "1" << endl;
               // felszFelsoHaromszog(n, TranszponaltA);
///cout << "2" << endl;

               // TranszponaltB = transzponalt(hMatrix_2);
                //fout << "Transponalt B : " << endl;
               // cout << "igy" << endl;
///kiirFilebaMatrixkent(fout, TranszponaltB);
               // cout << "alma" << endl;
               // felszAlsoHaromszog(n, TranszponaltB);
                //cout << "korte" << endl;
//
