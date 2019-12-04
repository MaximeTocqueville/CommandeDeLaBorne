#ifndef CLAVIER_H
#define CLAVIER_H
#define ADRESSE 0x22

#include <Arduino.h>

bool ToucheAppuye();
int VerificationLigne();
int VerificationColonne();
char LireTouche(int ligne,int colonne);
int OuvrirBarriere();
int VerifierCode();
bool code();

#endif 
