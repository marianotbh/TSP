#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

struct
{
    char nombre;
    int freq;
    int duration;
    int volume;
}typedef s_Melodia;

int parseMelodias(ArrayList* this);
void printMelodia(ArrayList* this, int index);

