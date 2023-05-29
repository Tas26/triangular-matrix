#ifndef HAROMSZOGMATRIX_H_INCLUDED
#define HAROMSZOGMATRIX_H_INCLUDED

struct HaromszogMatrix{
    bool    felsoHaromszog;  // felso haromszog vagy also lesz
    int     n;               // meret, sorok szama
    float  **adatok;        // szmaok tarolasa, vagy adatok
    int     *tomb;
    int     *osszegSor;
    int     *osszegOszlop;

};

void    beolvasTeljesMatrix(float **&Matrix, int &n);
void    beolvasTeljesMatrixFilebol(const char filename[], float **&Matrix, int &n);
void    beolvasStdMatrix(HaromszogMatrix &hMatrix);
void    beolvasStdTombbe(HaromszogMatrix &hMatrix);
void    beolvasFilebolMatrixkent(const char filename[], HaromszogMatrix &hMatrix);
void    beolvasFilebolTombbe(const char filename[], HaromszogMatrix &hMatrix);

void    initAlso(HaromszogMatrix &hMatrix);
void    initFelso(HaromszogMatrix &hMatrix);
void    initTomb(HaromszogMatrix &hMatrix);
void    felsz(int &n, float **&Matrix);
void    felszFelsoHaromszog(int &n, HaromszogMatrix &hMatrix);
void    felszAlsoHaromszog(int &n, HaromszogMatrix &hMatrix);

void    kiirMatrixkent(HaromszogMatrix &hMatrix);
void    kiirTombkent(HaromszogMatrix &hMatrix);
void    kiirFilebaMatrixkent(std::ofstream& fout, HaromszogMatrix &hMatrix);
void    kiirFilebaTombkent(std::ofstream& fout, HaromszogMatrix &hMatrix);
void    kiirOsszegSor(HaromszogMatrix &hMatrix);
void    kiirOsszegSorFileba(std::ofstream& fout, HaromszogMatrix &hMatrix);
void    kiirOsszegOszlop(HaromszogMatrix &hMatrix);
void    kiirOsszegOszlopFileba(std::ofstream& fout, HaromszogMatrix &hMatrix);
void    kiirTeljesMatrix(float **&Matrix, int &n);
void    kiirTeljesMatrixFileba(float **&Matrix, int &n, std::ofstream& fout);


void     sorOsszeg(HaromszogMatrix &hMatrix);
void     oszlopOsszeg(HaromszogMatrix &hMatrix);
long     teljesOsszeg(HaromszogMatrix &hMatrix);

void     LUdekomponzicio(float **&Matrix, int &n, HaromszogMatrix &hMatrix_1, HaromszogMatrix &hMatrix_2);
void     LU(float **&Matrix, int &n, HaromszogMatrix &hMatrix_1, HaromszogMatrix &hMatrix_2);

HaromszogMatrix     transzponalt(HaromszogMatrix &hMatrix);

void                szorzat(int &n, HaromszogMatrix &hMatrix_1, HaromszogMatrix &hMatrix_2, float **&EllenorzoMatrix);  // MATRIX SZORZAS
bool                egyenloE(int &n, float **&Matrix, float **&EllenorzoMatrix);
bool                bonthatoE(int &n, float **&Matrix);
float               determinans(int n, float **&Matrix);
float               HaromszogMatrixDeterminans(int n, HaromszogMatrix &hMatrix_1, HaromszogMatrix &hMatrix_2);



#endif // HAROMSZOGMATRIX_H_INCLUDED
