#include <stdio.h>
#include <math.h>
#define MAXVALUE 5

double computeD(double a, double b, double c){
    double powa = pow(a,3);
    double powb = pow(b,3);
    double powc = pow(c,3);

    return cbrt(powa + powb - powc);
}

int main(void){
    int a,b,c,d;


    // for (a = 1; a < MAXVALUE; a++)
    // {
    //     for (b = 1; b < MAXVALUE; b++)
    //     {
    //         for (c = 1; c < MAXVALUE; c++)
    //         {
    //             for (d = 1; d < MAXVALUE; d++)
    //             {
    //                 if ((pow(a,3) + pow(b, 3) == (pow(c,3) + pow(d,3))))
    //                 {
    //                     printf("a=%d, b=%d, c=%d, d=%d\n",a,b,c,d);
    //                 }
    //             }
    //         }
    //     }
    // }
    //d = (a^3 + b^3 - c^3)^1/3

    for (a = 1; a < MAXVALUE; a++)
    {
        for (b = 1; b < MAXVALUE; b++)
        {
            for (c = 1; c < MAXVALUE; c++)
            {
                d = computeD(a,b,c);
                if ((pow(a,3) + pow(b, 3) == (pow(c,3) + pow(d,3))))
                    {
                        printf("a=%d, b=%d, c=%d, d=%d\n",a,b,c,d);
                    }
            }
        }
    }
    double PairAB[MAXVALUE * MAXVALUE];
    int i = 0;
    int j =0;
    Reslist[] 
    coupleCD[(c,d)] = c^3 + d^3

    for (c = 1; c < MAXVALUE; c++)
    {
        for (d = 1; d < MAXVALUE; d++)
        {
            coupleCD[pow(c,3) + pow(d,3)].append((c,d));
            //c = 1, d = 1 -> resCD[2] = (1,1)
            //c = 1, d = 2 -> resCD[9] = (1,2)
            //c = 2, d = 1 -> resCD[9] = (2,1)
            //resCD[1] = 
        }
    }

    for (a = 1; a < MAXVALUE; a++)
    {
        for (b = 1; b < MAXVALUE; b++)
        {
            res = pow(a,3) + pow(b,3);
            coupleAB = coupleCD[res];
            for each i in coupleAB:
                print(a,b,i)
        }
    }

    foreach res,couple in coupleCD:
        foreach pair1 in couple:
            foreach pair2 in couple:
                print( pair1, pair2)

res = 0, couple =(0,0),(0,0)
    pair1 = (0,0)
        pair2 = (0,0)
res = 1, couple = (1,1),(1,1)   
    pair1 = (1,1)
        pair2 = (1,1)
res = 9, couple = (2,1),(1,2)   
    pair1 = (2,1)
        pair2 = (1,2)

    for (a = 1; a < MAXVALUE; a++)
    {
        for (b = 1; b < MAXVALUE; b++)
        {
            //PairAB[i] = pow(a,3) + pow(b,3);
            ResAB[(a,b)] = c + computeD(a,b,c);
            i++;
        }
    }

    for (j = 1; j < MAXVALUE * MAXVALUE; j++)
    {
        if ((PairAB[j] == (pow(c,3) + pow(d,3))))
        {
            printf("a=%d, b=%d, c=%d, d=%d\n",a,b,c,d);
        }
    }
    
    
    return 0;
}