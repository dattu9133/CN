#include<stdio.h>

int main() {
    int i = 0, len_ip = 0, count;
    int len_op = 0;
    int j = 0, s = 0, xxx = 0, five = 0;
    char ip[100], op[200], decode_op[100]; // Adjust sizes according to your requirements
    char pre_post[] = {'0', '1', '1', '1', '1', '1', '1', '0'};

    printf("Enter input bit sequence: \n");
    scanf("%s", ip);

    while (ip[len_ip] != '\0') len_ip++;

    for (i = 0; i < 8; i++) op[i] = pre_post[i];
    count = 8;

    do {
        if (ip[j] == '1') five++;
        else five = 0;

        op[count++] = ip[j++];

        if (five == 5) {
            op[count++] = '0';
            five = 0;
        }
    } while (j < len_ip);

    for (s = count, xxx = 0; s < (count + 8); s++, xxx++) {
        op[s] = pre_post[xxx];
    }

    printf("\nOutput\n");
  	printf("-------------------------------------- \n");
 
    printf("Stuffed Bit Sequence is: %s\n", op);

    j = 0;
    five = 0;
    len_op = count + 8;
    i = 8;

    do {
	    decode_op[j++] = op[i];
	
	    if (op[i] == '1') five++;
	    else five = 0;
	
	    if (five == 5) {
	        i++;
	        five = 0;
	    }
	
	    len_op--;
	    i++;
	} while ((len_op - 8) >= 0); // Adjusted termination condition


    decode_op[len_ip - 1] = '\0';

    printf("Destuffed Bit Sequence is: %s\n", decode_op);

    return 0;
}

