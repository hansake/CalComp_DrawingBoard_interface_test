#include "stdio.h"

int main()
    {
    int inchar;
    int frameindex;
    int framebyte[6];

     while (1)
        {
        for (frameindex = 0; frameindex <= 5; frameindex++)
            {
            inchar = getchar();
            if (inchar & 0x80)
                frameindex = 0;
            framebyte[frameindex] = inchar;
            }
        printf("\rFrame: [");
        for (frameindex = 0; frameindex <= 5; frameindex++)
            {
            printf("%02x ", framebyte[frameindex]);
            }
        printf("\b]  ");
        printf("X: %5d, ", framebyte[1] * 128 + framebyte[2]);
        printf("Y: %5d, ", framebyte[4] * 128 + framebyte[5]);
        printf("Button: ");
        if (framebyte[0] & 0x04)
            printf("0 ");
        else
            printf("- ");
        if (framebyte[0] & 0x08)
            printf("1 ");
        else
            printf("- ");
        if (framebyte[0] & 0x10)
            printf("2 ");
        else
            printf("- ");
        if (framebyte[0] & 0x20)
            printf("3 ");
        else
            printf("- ");
        if ((framebyte[0] & 0x3c) == 0x3c)
            {
            printf("\nExit dtest\n");
            return (0);
            }
        }
        return (1);
    }
