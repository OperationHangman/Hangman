#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

void zeichneGalgen(int leben)
{
    switch(leben)
    {
    case 8:
        printf(" ---\n");
        printf(" | |\n");
        printf(" | \n");
        printf(" | \n");
        printf(" | \n");
        printf(" | \n");
        printf(" | \n");
        printf(" |\n");
        printf("---------\n");
        break;

    case 7:
        printf(" ---\n");
        printf(" | |\n");
        printf(" | O\n");
        printf(" | \n");
        printf(" | \n");
        printf(" | \n");
        printf(" | \n");
        printf(" |\n");
        printf("---------\n");
        break;

    case 6:
        printf(" ---\n");
        printf(" | |\n");
        printf(" | O\n");
        printf(" | |\n");
        printf(" | \n");
        printf(" | \n");
        printf(" | \n");
        printf(" |\n");
        printf("---------\n");
        break;
    case 5:
        printf(" ---\n");
        printf(" | |\n");
        printf(" | O\n");
        printf(" | |\n");
        printf(" | |\n");
        printf(" | \n");
        printf(" | \n");
        printf(" |\n");
        printf("---------\n");
        break;
    case 4:
        printf(" ---\n");
        printf(" | |\n");
        printf(" | O\n");
        printf(" | |\n");
        printf(" | /|\n");
        printf(" | \n");
        printf(" | \n");
        printf(" |\n");
        printf("---------\n");
        break;

    case 3:
        printf(" ---\n");
        printf(" | |\n");
        printf(" | O\n");
        printf(" | |\n");
        printf(" | /|\\\n");
        printf(" | \n");
        printf(" | \n");
        printf(" |\n");
        printf("---------\n");
        break;

    case 2:
        printf(" ---\n");
        printf(" | |\n");
        printf(" | O\n");
        printf(" | |\n");
        printf(" | /|\\\n");
        printf(" | |\n");
        printf(" | \n");
        printf(" |\n");
        printf("---------\n");
        break;

    case 1:
        printf(" ---\n");
        printf(" | |\n");
        printf(" | O\n");
        printf(" | |\n");
        printf(" | /|\\\n");
        printf(" | |\n");
        printf(" | / \n");
        printf(" |\n");
        printf("---------\n");
        break;

    default:
        printf(" ---\n");
        printf(" | |\n");
        printf(" | O\n");
        printf(" | |\n");
        printf(" | /|\\\n");
        printf(" | |\n");
        printf(" | / \\\n");
        printf(" |\n");
        printf("---------\n");

    }
}
