#include <stdio.h>

int main()
{
    int framesize, sent = 0, ack, i;

    printf("Enter the number of frames: ");
    scanf("%d", &framesize);

    while (1)
    {
        for (i = 0; i < framesize; i++)
        {
            printf("Frame %d has been transmitted.\n", sent);
            sent++;
        }

        printf("\nPlease enter the last acknowledgment received: ");
        scanf("%d", &ack);

        if (ack >= framesize)
            break;
        else
            sent = ack;
    }

    return 0;
}
