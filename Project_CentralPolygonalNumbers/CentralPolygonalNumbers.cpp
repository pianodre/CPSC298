#include "CentralPolygonalNumbers.h"

CentralPolygonalNumbers::CentralPolygonalNumbers() {
    m_nMax = 0; // Default value for m_nMax
    mp_iNumbers = new int[m_nMax + 1]; // Allocate memory for the array
    // Calculate values for the sequence
    for (int n = 0; n <= m_nMax; ++n) {
        mp_iNumbers[n] = (n * n + n + 2) / 2; 
    }
}

CentralPolygonalNumbers::CentralPolygonalNumbers(int nMax) {
    m_nMax = nMax; // Assign nMax to m_nMax
    mp_iNumbers = new int[m_nMax + 1]; // Allocate memory for the array
    // Calculate values for the sequence
    for (int n = 0; n <= m_nMax; ++n) {
        mp_iNumbers[n] = (n * n + n + 2) / 2; 
    }
}


CentralPolygonalNumbers::~CentralPolygonalNumbers() {
    delete[] mp_iNumbers; // Deallocate the dynamically allocated array
    cout << "Destructor called." << endl;
}

void CentralPolygonalNumbers::display() {
    // Iterate over the array and print each value
    for (int i = 0; i <= m_nMax; ++i) {
        cout << "n: " << i << ", maximum number of pieces: " << mp_iNumbers[i] << endl;
    }
    cout << endl;
}

bool CentralPolygonalNumbers::save(string strFilename) {
    ofstream outFile(strFilename); // Open file for writing
    if (!outFile.is_open()) {
        cerr << "Error: Couldn't open file for writing." << endl;
        return false;
    }
    // Write sequence entries to the file
    for (int i = 0; i <= m_nMax; ++i) {
        outFile << mp_iNumbers[i] << " ";
    }
    outFile.close(); // Close the file
    return true;
}