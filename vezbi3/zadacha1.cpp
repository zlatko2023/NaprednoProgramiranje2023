#include <stdio.h> 
#include <time.h>   

int main ()
{
    time_t now; // Deklariranje promenliva 'now' od tipot time_t
    struct tm newyear; // Deklariranje promenliva new year od tipot tm
    double seconds;     
    
    time(&now); // so pomosh na funkcijata time, go dodavame momentalnoto vreme kako vrednost na promenlivata now
    
    newyear = *localtime(&now);  // dodeluvame konvertirana vrednost na newyear od segashnoto vreme vo lokalno vreme(spored zonata vo koja e povikana skriptata)
    
    // dodeluvanje na vrednosti na newyear za nova godina, pr. vo 00:00 na 1vi
    newyear.tm_hour = 0; 
    newyear.tm_min = 0; 
    newyear.tm_sec = 0;
    newyear.tm_mon = 0; 
    newyear.tm_mday = 1;
    
    // presmetuvanje na sekundi od pochetokot na godinata vo momentalnata vremenska zona
    seconds = difftime(now, mktime(&newyear));
    
    printf ("%.f sekundi od nova godina vo momentalna vremenska zona.\n", seconds);
    
    return 0;
}
