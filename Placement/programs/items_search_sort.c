#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    double price;
} item_t;

void get_min_max_price(item_t items[], int size, double *min_p, double *max_p) {
    double min_buff,max_buff;
    min_buff = items[0].price;
    max_buff = items[0].price;
    
    for (int i = 1; i < size; i++) {
        if (items[i].price > max_buff) {
            max_buff = items[i].price;
        }
        if (items[i].price < min_buff) {
            min_buff = items[i].price;
        }
    }

    *min_p = min_buff;
    *max_p = max_buff;
}

int search_item(item_t items[], int size, int id) {
    int high = size - 1, low = 0, mid = (high + low)/2;

    while (low <= high && items[mid].id != id) {
        if (items[mid].id < id) {
            low = mid + 1;
        }

        if (items[mid].id > id) {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }

    if (items[mid].id == id) {
        return mid;
    } else {
        return -1;
    }
}

void sort_items(item_t items[], int size)
{

    item_t temp;
    for (int i = 0; i < size - 1; i++)
    {
        int max_price = i;
        

        for (int j = i + 1; j < size; j++)
        {
            if (items[max_price].price < items[j].price)
            {
                max_price = j;
            }
            temp = items[i];
            items[i] = items[max_price];
            items[max_price] = temp;
        }
    }

    for (int limit = size - 1; limit >= 0; limit--)
    {

        for (int i = 0; i < limit; i++)
        {
            if (items[i].id > items[i + 1].id && items[i].price == items[i+1].price)
            {
                temp = items[i];
            items[i] = items[i+1];
            items[i+1] = temp;
            }
        }
    }
}

int main(void)
{
    item_t items[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &items[i].id);
        scanf("%lf", &(items[i].price));
    }

    for (int i = 0; i<5; i++) {
        printf("%d, %0.2f, ", items[i].id, items[i].price);
    }

    double min_p;
    double max_p;

    get_min_max_price(items, 5, &min_p, &max_p);

    printf("\n%0.2f, %0.2f\n", min_p, max_p);

    printf("%d\n", search_item(items, 5, 3));
    
    sort_items(items, 5);

    for (int i = 0; i<5; i++) {
        printf("%d, %0.2f, ", items[i].id, items[i].price);
    }

// 0 2.5 1 3.5 2 4.5 3 5.5 4 6.6
}
