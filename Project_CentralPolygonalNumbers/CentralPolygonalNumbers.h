#ifndef CENTRAL_POLYGONAL_NUMBERS
#define CENTRAL_POLYGONAL_NUMBERS

using namespace std;
#include <iostream>
#include <fstream>

class CentralPolygonalNumbers {
    public:
        CentralPolygonalNumbers();
        CentralPolygonalNumbers(int nMax);
        ~CentralPolygonalNumbers();
        void display();
        bool save(string strFilename);
    private:
        int m_nMax;
        int* mp_iNumbers;  
};

#endif