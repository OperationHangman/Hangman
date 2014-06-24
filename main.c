#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>


// Liste der Wörter, die erraten werden können
//Die [4] gibt an wieviele Wörter in der Liste stehen
char *list[4] =
{
    "analfetisch", "hartgeldnutte",
    "bokunopico", "analgeneral"
};

int main(void)
{
    int ausgangswort, leben=8;
    char wort[25];
    int x,richtig,i = 0;
    int laenge;
    char eingabe;

    srand((unsigned int)time(NULL));
    printf("\nWillkommen. Du hast noch %d Leben \n", leben);

    ausgangswort = rand() % 4;

    //Speichert die laenge des Ausgangswortes in laenge
    laenge = strlen(list[ausgangswort]);

    //Speichert das urspruenglich erzeugte Randomwort(ausgangswort) in die variable wort und ersetzt die Buchstaben durch _
    for(x=0; x<laenge; x++)
    {
        wort[x] = '_';
    }
    wort[laenge] = 0;

    printf("%s\n",wort);

    while ((leben>0) && (i < laenge))
    {
        richtig = 0;
        printf("Geben sie einen Buchstaben ein: ");
        do
        {
            scanf("%c", &eingabe);

            eingabe = tolower(eingabe);

            if((eingabe > 32) && ((eingabe < 97) || (eingabe > 122)))
            {
                printf("Ungueltiger Buchstabe\n Bitte geben Sie einen Buchstaben von A-Z ein: ");
            }

        }
        while((eingabe < 97) || (eingabe > 122));

        for(x=0; x<laenge; x++)
        {
            if(eingabe == wort[x])
            {
                printf("Du hast den Buchstaben schon benutzt \n");
                break;
            }
        }

        if(x==laenge)
        {
            // Zeile Code, um zu betruegen oder auch zum testen :3
            // Auskommentieren bei richtigen Spiel
            printf("%c, %s\n",eingabe,list[ausgangswort]);

            for(x=0; x<laenge; x++)
            {
                if(eingabe == list[ausgangswort][x])
                {
                    wort[x] = eingabe;
                    i++;
                    richtig = 1;
                }
            }

            if(richtig == 0)
            {
                leben--;
                if(leben > 0)
                {
                    printf("Falsch. %i Du hast noch Leben uebrig.\n",leben);
                }
                else
                {
                    printf("Du bist tot. :(\n");
                }

            }
            else
            {
                if(i < laenge)
                {
                    printf("Richtig.\n");
                }
                else
                {
                    printf("Du gewinnst! :)\n");
                }
            }
            printf("Bisher erraten %s\n",wort);
        }
    }
}
