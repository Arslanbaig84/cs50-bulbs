#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
//void reverse(int arr[][8], int size);

int main(void)
{
    //PROMPTING FOR A STRING
    string s = get_string("Leave a message: ");
    int ascii[strlen(s)];
    int binary[strlen(s)][BITS_IN_BYTE];
    int reversed[strlen(s)][BITS_IN_BYTE];

    //CONVERTING STRING TO ASCII CHARACTERS AND STORING IN AN ARRAY

    for (int i = 0; i < strlen(s); i++)
    {
        ascii[i] = s[i];
        //printf("%i ", ascii[i]);

        //  CONVERTING ASCII TO BINARY
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            binary[i][j] = ascii[i] % 2;
            ascii[i] = ascii[i] / 2;
            //printf("%i", binary[i][j]);
        }
        //printf("\n");
    }

    for (int i = 0 ; i < strlen(s); i++)
    {
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            reversed[i][j] = binary[i][BITS_IN_BYTE - j - 1];

            //printf("%i", reversed[i][j]);
        }
        //printf("\n");
    }


    for (int i = 0; i < strlen(s); i++)
    {
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            //PRINT FUNCTION
            //printf("%i", reversed[i][j]);
            print_bulb(reversed[i][j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

