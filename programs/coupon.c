#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct
{
    int quantity;
    int price;
} coupon_t;

int minimumCost(coupon_t coupons[], int numCoupons, int units)
{
    if (numCoupons != 1)
    {

        for (int i = 0; i < numCoupons - 1; i++)
        {
            if (coupons[numCoupons - 1].quantity + coupons[i].quantity == units)
            {
                if (minimumCost(coupons, numCoupons - 1, units) != -1 && minimumCost(coupons, numCoupons - 1, units) < coupons[numCoupons - 1].price + coupons[i].price)
                {
                    return minimumCost(coupons, numCoupons - 1, units);
                }
                else
                {
                    return coupons[numCoupons - 1].price + coupons[i].price;
                }
            }
        }
    }

    return -1;
}

int main(void)
{
    coupon_t c[] = {{3, 10}, {2, 4}, {2, 4}, {1, 3}};

    int min = minimumCost(c, 4, 4);

    printf("%d", min);

    return 0;
}
