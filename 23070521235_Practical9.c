//Leaky Bucket

#include <stdio.h>

int main() {
    int bucket_size, n, i, incoming, outgoing, stored = 0;

    printf("Leaky Bucket Algorithm Simulation\n");
    printf("Enter bucket size (capacity): ");
    scanf("%d", &bucket_size);
    printf("Enter outgoing rate: ");
    scanf("%d", &outgoing);
    printf("Enter number of packets (time units): ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("\nTime unit %d:\n", i+1);
        printf("Enter number of incoming packets: ");
        scanf("%d", &incoming);

        if(incoming + stored > bucket_size) {
            printf("Bucket overflow! Packet loss = %d\n", incoming + stored - bucket_size);
            stored = bucket_size;
        } else {
            stored += incoming;
        }

        if(stored <= outgoing) {
            printf("Packets sent: %d\n", stored);
            stored = 0;
        } else {
            printf("Packets sent: %d\n", outgoing);
            stored -= outgoing;
        }

        printf("Packets remaining in bucket: %d\n", stored);
    }

    // Drain remaining packets
    while(stored > 0) {
        printf("\nDraining remaining packets...\n");
        if(stored <= outgoing) {
            printf("Packets sent: %d\n", stored);
            stored = 0;
        } else {
            printf("Packets sent: %d\n", outgoing);
            stored -= outgoing;
        }
        printf("Packets left in bucket: %d\n", stored);
    }

    printf("\nSimulation complete.\n");
    return 0;
}


Token Bucket Algorithm (C Program)
#include <stdio.h>

int main() {
    int bucket_size, n, rate, tokens = 0, incoming, i;

    printf("Token Bucket Algorithm Simulation\n");
    printf("Enter bucket size (capacity): ");
    scanf("%d", &bucket_size);
    printf("Enter token generation rate: ");
    scanf("%d", &rate);
    printf("Enter number of packets (time units): ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("\nTime unit %d:\n", i+1);

        tokens += rate;
        if(tokens > bucket_size) tokens = bucket_size;

        printf("Enter number of packets to send: ");
        scanf("%d", &incoming);

        if(tokens >= incoming) {
            printf("Packets sent: %d\n", incoming);
            tokens -= incoming;
        } else {
            printf("Only %d tokens available, packets sent: %d, packets dropped: %d\n",
                    tokens, tokens, incoming - tokens);
            tokens = 0;
        }

        printf("Tokens left: %d\n", tokens);
    }

    printf("\nSimulation complete.\n");
    return 0;
}

