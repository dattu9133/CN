#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h> // Include for time function
#define bucketSize 512

void bucketInput(int pktSize, int op)
{
    if (pktSize > bucketSize)
        printf("\n\t\tBucket overflow");
    else
    {
        // sleep(2);
        while (pktSize > op)
        {
            printf("\n\t\t%d bytes outputted.", op);
            pktSize -= op;
            // sleep(2);
        }
        if (pktSize > 0)
            printf("\n\t\tLast %d bytes sent", pktSize);
        printf("\n\t\tBucket output successful");
    }
}

int main()
{
    int op, i, pktSize;
    printf("Enter output rate: ");
    scanf("%d", &op);

    for (i = 1; i <= 5; i++)
    {
        // sleep(2);
        pktSize = rand() % 1000; // Random packet size between 0 and 999
        printf("\n\nPacket no: %d \tPacket size: %d ", i, pktSize);
        bucketInput(pktSize, op);
    }

    return 0;
}
