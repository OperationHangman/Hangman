#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>


// Liste der Wörter, die erraten werden können
//Die [4] gibt an wieviele Wörter in der Liste stehen
char *list[4] =
{
    "schmetterling", "elch",
    "helikopter", "tafelbild"
};

int main(void)
{
    int worti, leben=8;
    char wort[25];
    int x,richtig,i = 0;
    int laenge;
    char eingabe;

    //Initialisiert einen zufallsnummer generator
    srand((unsigned int)time(NULL));
    printf("\nWillkommen. Du hast noch %d Leben \n", leben);

    worti = rand() % 4; //Die Zufallsnummer wird gespeichert in worti(index)

    //Nimmt den Wert aus der Stelle in list heraus, die worti(random 1-X) erzeugt hat. Zudem speichert er auch die länge des Wortes in die Variable laenge
    laenge = strlen(list[worti]);

    //Speichert in die variable wort das Symbol _ für die laenge des Wortes stellvertretend [x]
    //Wird zur Ausgabe des Raten benutzt
    for(x=0; x<laenge; x++)
    {
        wort[x] = '_';
    }

    wort[laenge] = 0;

    printf("%s\n",wort);

    //Solange wie leben groeßer als 0 ist und das Wort nicht erraten wurde, also i kleiner als laenge ist
    while ((leben>0) && (i < laenge))
    {
        //Leben wird auf 0 gesetzt. Sollte der Buchstabe nicht richtig geraten sein, so führt er die unten bestehende Zeile if(richtig == 0) aus und zieht ein Leben ab.
        richtig = 0;
        printf("Geben sie einen Buchstaben ein: ");

        do
        {
            scanf("%c", &eingabe);

            eingabe = tolower(eingabe);

            if((eingabe > 32) && ((eingabe < 97) || (eingabe > 122)))
            {
                printf("Ungueltiger Buchstabe\n Bitte geben Sie einen Buchstaben von A-Z ein: ");
                printf("Bisher erraten %s\n",wort);
            }


        }
        while((eingabe < 97) || (eingabe > 122));

        for(x=0; x<laenge; x++)
        {
            if(eingabe == wort[x])
            {
                system("cls");
                printf("Du hast den Buchstaben schon benutzt \n");
                printf("Bisher erraten %s\n",wort);
                //Springt aus der Funktion zum Start der oberen while-schleife
                break;
            }
        }

        if(x==laenge)
        {

            // Zeile Code, um zu betruegen oder auch zum testen :3
            // Auskommentieren bei richtigen Spiel
            printf("%c, %s\n",eingabe,list[worti]);

            for(x=0; x<laenge; x++)
            {


                //Wenn die Eingabe == wie die Stelle aus list des randomindex worti und x ist, so wird in wort diese Stelle von einem _ zu dem Buchstaben gesetzt
                if(eingabe == list[worti][x])
                {
                    wort[x] = eingabe;
                    //i wird hochgezählt für die Abbruchbedingung ganz oben. Daran erkennt er, ob das Wort erraten wurde oder (noch) nicht
                    i++;
                    richtig = 1;
                }
            }

            if(richtig == 0)
            {
                leben--;
                if(leben > 0)
                {
                    system("cls");
                    printf("Falsch. Du hast noch %i Leben uebrig.\n",leben);
                    printf("Bisher erraten %s\n",wort);
                }
                else
                {
                    system("cls");
                    printf("Du bist tot. :(\n");
                }

            }
            else
            {
                if(i < laenge)
                {
                    system("cls");
                    printf("Richtig.\n");
                    printf("Bisher erraten %s\n",wort);
                }
                else
                {
                    system("cls");
                    printf("Du gewinnst! :)\n");
                }
            }

        }
    }
}
