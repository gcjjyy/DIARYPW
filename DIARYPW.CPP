#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned char password[10] = {
        0,
    };

    if (argc < 2)
    {
        printf("Usage: %s <diary filename>\n", argv[0]);
        return 0;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp)
    {
        fread(password, sizeof(unsigned char), 10, fp);
        fclose(fp);

        for (int i = 0; i < 10; i += 2)
        {
            unsigned char b = (password[i + 1] - 1) >> 1;
            if (b == 0) break;
            printf("%c", b);

            b = (password[i] - 1) >> 1;
            if (b == 0) break;
            printf("%c", b);
        }

        printf("\n");
    }

    return 0;
}

