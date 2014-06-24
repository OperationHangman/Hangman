#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>


// Liste der Wörter, die erraten werden können
//Die [4] gibt an wieviele Wörter in der Liste stehen
void zeichneGalgen(int leben);
//struct list erstmal vermieden und einfache variante gewählt. Wollte erst die Wörter mit bestimmten Hinweisen belegen

char *list[4] =
{
    "schmetterling", "elch",
    "helikopter", "tafelbild"
};

int main(void)
{
    int worti, leben=8, schwierigkeitsgrad=1, punkte = 0;
    char wort[25];
    int x,richtig,i = 0;
    int laenge, hoechstpunktzahl;
    char eingabe;

    //Initialisiert einen zufallsnummer generator
    srand((unsigned int)time(NULL));
    printf("\nWillkommen. Du hast noch %d Leben \n", leben);
    printf("Waehlen sie einen Schwierigkeitsgrad von 1-3:");
    scanf("%d", &schwierigkeitsgrad);

    worti = rand() % 4; //Die Zufallsnummer wird gespeichert in worti(index)

    //Nimmt den Wert aus der Stelle in list heraus, die worti(random 1-X) erzeugt hat. Zudem speichert er auch die länge des Wortes in die Variable laenge
    laenge = strlen(list[worti]);
    hoechstpunktzahl = strlen(list[worti])*100;
    //Speichert in die variable wort das Symbol _ für die laenge des Wortes stellvertretend [x]
    //Wird zur Ausgabe des Raten benutzt bzw. um das Wort zu verschlüsseln
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

        // Zeile Code, um zu betruegen oder auch zum testen :3
        // Auskommentieren bei richtigen Spiel
        printf("%c, %s\n",eingabe,list[worti]);
        printf("Geben sie einen oder mehrere Buchstaben ein.\nAuch koennen sie das Wort direkt loesen: \n");
        printf("Hinweis: Pro falsch erratenden Buchstaben erhalten Sie Abzüge\n");

        do
        {
            scanf("%c", &eingabe);

            eingabe = tolower(eingabe);

            if((eingabe > 32) && ((eingabe < 97) || (eingabe > 122)))
            {
                system("cls");
                zeichneGalgen(leben);
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
                zeichneGalgen(leben);
                printf("Du hast den Buchstaben schon benutzt \n");
                printf("Bisher erraten %s\n",wort);
                //Springt aus der Funktion zum Start der oberen while-schleife
                break;
            }
        }

        if(x==laenge)
        {
            for(x=0; x<laenge; x++)
            {


                //Wenn die Eingabe == wie die Stelle aus list des randomindex worti und x ist, so wird in wort diese Stelle von einem _ zu dem Buchstaben gesetzt
                if(eingabe == list[worti][x])
                {
                    wort[x] = eingabe;
                    //i wird hochgezählt für die Abbruchbedingung ganz oben. Daran erkennt er, ob das Wort erraten wurde oder (noch) nicht
                    i++;
                    richtig = 1;
                    punkte = punkte + 100;
                }

            }

            if(richtig == 0)
            {
                leben--;
                if(leben > 0)
                {
                    system("cls");
                    //HIER AUFRUF FUNKTION ZEICHNE GALGEN
                    zeichneGalgen(leben);
                    printf("Falsch. Du hast noch %i Leben uebrig.\n",leben);
                    printf("Bisher erraten %s\n",wort);
                    punkte = punkte - 100;



                }
                else
                {
                    system("cls");
                    zeichneGalgen(leben);
                    printf("Du bist tot. :(\n");
                    printf("Das zu erratende Wort war:\n");
                    printf("%s\n",list[worti]);
                    printf("%d",punkte);
                }

            }
            else
            {
                if(i < laenge)
                {
                    system("cls");
                    zeichneGalgen(leben);
                    //HIER AUFRUF FUNKTION ZEICHNE GALGEN
                    printf("Richtig.\n");
                    printf("Bisher erraten %s\n",wort);
                }
                else
                {
                    system("cls");
                    printf("Du gewinnst! :)\n");
                    printf("Du hast %d von %d Punkten erreicht",punkte, hoechstpunktzahl);
                }

            }

        }
    }


}
