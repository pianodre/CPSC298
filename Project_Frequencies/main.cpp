/*
    Use the formula below to compute the frequencies of the following notes: 
    C#0, D0, D3 , C4, D#7, and C8.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double fkv; // Frequency of the note in octave v whose half-step within the octave is k^3
    double fr = 16.35; // Reference Frequency, in this case 16.35 Hz, the Frequency of the note C in octave 0
    double c = 345.0; // Speed of Sound in m/s
    double Wkv; // Wavelength - c/fkv

    string notes[] = {"C#0", "D0", "D3", "C4", "D#7", "C8"}; // notes
    double v[] = {0.0, 0.0, 3.0, 4.0, 7.0, 8.0}; // v is the octave number (range is 0-9)
    double k[] = {1.0, 2.0, 2.0, 0.0, 3.0, 0.0}; // is the half-step within the octave (0-11)

    cout << "Reference Frequency: 16.35 Hz" << endl; // Prints the reference frequency
    cout << "Speed of Sound: 345 m/s" << endl; // Prints the speed of sound

    for (int i = 0; i <= 5; ++i) { // Prints all note frequencies and wavelengths
        fkv = fr * pow(2.0,v[i]) * pow(2, (k[i]/12.0)); // Calculates the frequency in Hertz
        Wkv = c/fkv * 100; // Multiplied by 100 to get in cm (100cm/1m)
        cout << "Note: " << notes[i] << "; Octave: " << v[i] << "; Semi-tone: " << k[i] << "; Frequency: " << fkv << " Hz; Wavelength: " << Wkv << " cm" << endl;
    }
}