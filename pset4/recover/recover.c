#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
int block_size = 512;
typedef uint8_t BYTE;
bool isjpg(BYTE buffer[]);
int invalidUse();

int main(int argc, char *argv[])
{
    //makes sure the person only puts 1 argument in
    if (argc != 2)
    {
        return invalidUse(1);
    }

    FILE *f = fopen(argv[1], "r");

    //makes sure the file exists
    if (f == NULL)
    {
        return invalidUse(2);
    }
    
    char filename[8];
    FILE *output = NULL;
    BYTE buffer[block_size];
    int numberOfJPGs = 0; 
    
    //reads and writes the bytes of each jpg into seperate files
    while (fread(buffer, sizeof(BYTE), block_size, f) || feof(f) == 0)
    {
        if (isjpg(buffer))
        {
            if (output != NULL)
            {
                fclose(output);
            }
            sprintf(filename, "%03i.jpg", numberOfJPGs);
            output = fopen(filename, "w");
            numberOfJPGs++;
        }
        if (output != NULL)
        {
            //actually writes the contents read from the memory card to the new file
            fwrite(buffer, sizeof(buffer), 1, output);
        }
    }
    //makes sure the output file isn't null
    if (output == NULL)
    {
        fclose(output);
    }
    if (f == NULL)
    {
        fclose(f);
    }
 

}
//returns 1 when a certain error occurs, printing a corresponding error message to go along with it, otherwise it just returns 0
int invalidUse(int a)
{
    //returns different error messages if it is passed a certain int
    if (a == 1)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }
    if (a == 2)
    {
        printf("Invalid file");
        return 1;
    }
    return 0;
}
//Sees if the first 4 bytes are indicative of a jpg file
bool isjpg(BYTE buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    return false;
}
