#include "MusicNoteAPI.h"

MusicNoteAPI::MusicNoteAPI() {
    // Initialize any member variables here if needed
}

// Destructor definition
MusicNoteAPI::~MusicNoteAPI() {
    // Clean up any resources here if needed
}

double MusicNoteAPI::calcFreq(int n, double k) {
    return fR * std::pow(2.0, n + k / 12.0);
}

double MusicNoteAPI::calcWav(double f) {
    double Wavelength = c / f;
}

string MusicNoteAPI::getNote(int x) {
    return a_strNotes[x];
}
