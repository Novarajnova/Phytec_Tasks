//42.draw a flow chart to print bill of shoping items,quantity,unit price to be entered.

#include <stdio.h>
int main() {
    int qty;
    float unit_price, total;
    printf("Enter quantity and unit price: ");
    scanf("%d%f", &qty, &unit_price);
    total = qty * unit_price;
    printf("Total Bill = ₹%.2f\n", total);
    return 0;
}

