#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WRONG_GUESSES 10 // največje število napačnih ugibanj, preden igralec izgubi

const char *words[] = {"racunalnik", "okno", "miza", "bozic", "dvigalo", "juha", "obleka", "slovenscina"}; // niz moznih besed

// funkcija
void drawHangman(int wrongGuesses);

int main()
{
    srand(time(0)); // posadite generator nakljucnih stevil
    int numWords = sizeof(words) / sizeof(words[0]); // stevilo besed v polju
    int index = rand() % numWords; // izberite nakljucno besedo iz polja
    const char *word = words[index]; // izbrana beseda
    int wordLength = strlen(word); // dolzina besede
    char wordGuess[wordLength + 1]; // polje za ugibanje besed (en dodaten presledek za ničelno besedo)
    for (int i = 0; i < wordLength; i++)
    {
        wordGuess[i] = '_'; // inicializirajte polje za ugibanje besed s podcrtankami
    }
    wordGuess[wordLength] = '\0'; // null-terminate polje za ugibanje besed
    int wrongGuesses = 0; //  stevilo napacnih ugibanj
    char letter; //crka ki jo vnese igralec
    int alreadyGuessed = 0; // za preverjanje ali je bila crka ze uganjena
    printf("Dobrodošli v Hangmanu!\n");
    while (wrongGuesses < MAX_WRONG_GUESSES)
    {
        alreadyGuessed = 0;

        drawHangman(wrongGuesses); // narisi obesenca
        printf("Beseda: %s\n", wordGuess); // natisne polje za ugibanje besed
        printf("Ostale ugibanja: %d\n", MAX_WRONG_GUESSES - wrongGuesses); // izpise stevilo preostalih ugibanj 
        printf("Vnesite crko: ");
        scanf(" %c", &letter); //preberi pismo igralca
        for (int i = 0; i < wordLength; i++)
        {
            if (word[i] == letter) //ce je crka v besedi
            {
                wordGuess[i] = letter; // Izpolnite prazen prostor
                alreadyGuessed = 1; //  nastavi zastavico ki oznacuje, da je bila crka uganjena
            }
        }
        if (!alreadyGuessed) //ce crka ni bila uganjena
        {
            wrongGuesses++; // povecanje stevila napacnih ugibanj
        }
        if (strcmp(word, wordGuess) == 0) // ce je bila beseda v celoti uganjena 
        {

            drawHangman(wrongGuesses); // narisi obesenca
            printf("Čestitamo, zmagali ste! Beseda je bila %s.\n", word);
            return 0; // izhod iz programa
        }
    }

    drawHangman(wrongGuesses); // narisi obesenca
    printf("Žal nam je, da ste izgubili. Beseda je bila %s.\n", word);
    return 0;
}
//funkcija za risanje obešenjaka
void drawHangman(int wrongGuesses){
    if (wrongGuesses >= 1)
        printf(" |\n");
    else
        printf("");

    if (wrongGuesses >= 2)
        printf(" |\n");
    else
        printf("");

    if (wrongGuesses >= 3)
        printf(" O\n");
    else
        printf("");

    if (wrongGuesses == 4)
        printf("/  \n");

    if (wrongGuesses == 5)
        printf("/| \n");

    if (wrongGuesses >= 6)
        printf("/|\\ \n");
    else
        printf("");

    if (wrongGuesses >= 7)
        printf(" | \n");
    else
        printf("");

    if (wrongGuesses == 8)
        printf("/ \n");

    if (wrongGuesses >= 9)
        printf("/ \\ \n");
    else
        printf("");
}
