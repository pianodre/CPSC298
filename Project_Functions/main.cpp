#include "MusicNoteAPI.h"

using namespace std;

const int k_nOctaves = 9; // Number of octaves to consider
const int k_nHalfTones = 12; // Number of Half-tones in an octave

int main() {

    MusicNoteAPI noteAPI; 

    for (int nu = 0; nu < k_nOctaves; ++nu) {
        for (int k = 0; k < k_nHalfTones; ++k) {
            // Calculates the frequency (f)
            double f = noteAPI.calcFreq(nu, k);

            // Calculates the wavelength (in centimeters)
            double Wavelength = noteAPI.calcWav(f);

            // Sets the note name from the array
            string note = noteAPI.getNote((nu * k_nHalfTones) + k);

            // Output the results
            cout << fixed << setprecision(3);
            cout << "Note: " << note << "; nu: " << nu << "; k: " << k << "; frequency: " << f << " Hz; wavelength: " << Wavelength << " cm" << endl;
        }
    }

    return 0;
}
