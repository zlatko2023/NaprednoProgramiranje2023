// Kodot presmetuva prosti broevi vo radius od 2 do 99999

#include <stdio.h> 
#include <time.h> 
#include <math.h> 

int frequency_of_primes(int n) {
    int i, j;
    int freq = n - 1;
    
    // Loop na site broevi od 2 do n 
    for (i = 2; i <= n; ++i) {
        // Loop na site broevi od sqrt(i) do 2 i proverka dali e deliv so i
        for (j = sqrt(i); j > 1; --j) {
            if (i % j == 0) { 
                --freq; 
                break;
            }
        }
    }
    
    return freq;
}

int main() {
    clock_t t; 
    int f; 
    
    t = clock(); // zemanje na tekovonoto vreme
    printf("-- Presmetka --\n");
    f = frequency_of_primes(99999); // povikuvanje na funkcijata frequency_of_primes 
    printf("Brojot na prosti broevi pomal od 100,000 e: %d\n", f);
    t = clock() - t; //presmetuvanje na momentalnoto vreme minus kalkulacijata na t 
    printf("Potrebni se %d klikovi (%f sekundi).\n", t, ((float)t)/CLOCKS_PER_SEC);
    
    return 0; 
}

