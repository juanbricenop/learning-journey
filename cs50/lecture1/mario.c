#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Pedir altura válida
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Construir la pirámide
    for (int i = 0; i < height; i++)
    {
        // Espacios izquierda
        for (int s = 0; s < height - i - 1; s++)
        {
            printf(" ");
        }

        // Numerales izquierda
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        // Espacio central
        printf("  ");

        // Numerales derecha
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
