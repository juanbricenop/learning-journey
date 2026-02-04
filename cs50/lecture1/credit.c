#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");

    int sum = 0;
    int position = 0;
    long temp = number;

    // Algoritmo de Luhn
    while (temp > 0)
    {
        int digit = temp % 10;

        if (position % 2 == 1)
        {
            int doubled = digit * 2;
            sum += (doubled / 10) + (doubled % 10);
        }
        else
        {
            sum += digit;
        }

        temp /= 10;
        position++;
    }

    // Si no pasa Luhn
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Contar dígitos
    int length = 0;
    temp = number;
    while (temp > 0)
    {
        temp /= 10;
        length++;
    }

    // Obtener primeros dos dígitos
    temp = number;
    while (temp >= 100)
    {
        temp /= 10;
    }
    int first_two = temp;
    int first_one = first_two / 10;

    // AMEX
    if (length == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    // MASTERCARD
    else if (length == 16 && (first_two >= 51 && first_two <= 55))
    {
        printf("MASTERCARD\n");
    }
    // VISA
    else if ((length == 13 || length == 16) && first_one == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
