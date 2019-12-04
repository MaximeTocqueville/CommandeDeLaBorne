#ifndef FONCTIONBARRIERE_H
#define FONCTIONBARRIERE_H

#define MECA 0x20
#define OUVRIR 0x7D
#define FERMER 0x7E
#define BARRIERE 0x78

void ouverture(int address);
void fermeture(int address);
int lectureBoucle(int address);
void configurationBarriere(int address);
boolean boucleAval();
boolean boucleAmond();

#endif
