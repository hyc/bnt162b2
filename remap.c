#include <stdio.h>

typedef enum bases { A=0, C, G, T } bases;
bases c2i[128];

char i2c[4] = {'A', 'C', 'G', 'T'};

typedef enum aminos { aA = 0, aC, aD, aE, aF, aG, aH, aI, aK, aL, aL2,
	aM, aN, aP, aQ, aR, aR2, as, as2, aS, aS2, aT, aV, aW, aY } aminos;

aminos b2a[4][4][4] =
	{
		{
			{aK, aN, aK, aN},
			{aT, aT, aT, aT},
			{aR, aS, aR, aS},
			{aI, aI, aM, aI}
		},
		{
			{aQ, aH, aQ, aH},
			{aP, aP, aP, aP},
			{aR2, aR2, aR2, aR2},
			{aL, aL, aL, aL}
		},
		{
			{aE, aD, aE, aD},
			{aA, aA, aA, aA},
			{aG, aG, aG, aG},
			{aV, aV, aV, aV}
		},
		{
			{as, aY, as, aY},
			{aS2, aS2, aS2, aS2},
			{as2, aC, aW, aC},
			{aL2, aF, aL2, aF}
		}
	};

typedef bases codon[3];

codon a2c[25][2] =
	{
		{{G,C,C},{G,C,G}},
		{{T,G,C},{T,G,C}},
		{{G,A,C},{G,A,C}},
		{{G,A,G},{G,A,G}},
		{{T,T,C},{T,T,C}},
		{{G,G,C},{G,G,G}},
		{{C,A,C},{C,A,C}},
		{{A,T,C},{A,T,C}},
		{{A,A,G},{A,A,G}},
		{{C,T,G},{C,T,G}},	/* prefer CTG over CTC */
		{{T,T,G},{T,T,G}},
		{{A,T,G},{A,T,G}},
		{{A,A,C},{A,A,C}},
		{{C,C,C},{C,C,G}},
		{{C,A,G},{C,A,G}},
		{{A,G,G},{A,G,G}},
		{{C,G,C},{C,G,G}},
		{{T,G,A},{T,G,A}},	/* prefer TGA over TAG */
		{{T,G,A},{T,G,A}},
		{{A,G,C},{A,G,C}},
		{{T,C,C},{T,C,G}},
		{{A,C,C},{A,C,G}},
		{{G,T,G},{G,T,G}},	/* prefer GTG over GTC */
		{{T,G,G},{T,G,G}},
		{{T,A,C},{T,A,C}}
	};

char inbuf[1024];

int
main()
{
	int c;
	aminos a0;
	codon bx, *cx;

	c2i['A'] = A;
	c2i['C'] = C;
	c2i['G'] = G;
	c2i['T'] = T;

#if 0
	/* skip header line */
	fgets(inbuf, sizeof(inbuf), stdin);
#endif

	while ((c = getchar()) != EOF) {
		if (c == '\n')
			continue;

		bx[0] = c2i[c];
		bx[1] = c2i[getchar()];
		bx[2] = c2i[getchar()];

		a0 = b2a[bx[0]][bx[1]][bx[2]];
		cx = &a2c[a0][0];
		putchar(i2c[cx[0][0]]);
		putchar(i2c[cx[0][1]]);
		putchar(i2c[cx[0][2]]);
		putchar('\n');
	}
}
