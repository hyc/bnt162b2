/* read input .fasta file, spit out 1 codon per line */

#include <stdio.h>

char inbuf[1024];
int main()
{
	int c, i=0;

	/* skip header line */
	fgets(inbuf, sizeof(inbuf), stdin);
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			continue;
		putchar(c);
		i++;
		if (i == 3) {
			putchar('\n');
			i = 0;
		}
	}
}
