#include <stdio.h>

int main() {
    double hours, wage;
    double grossPay, taxes, netPay;

    // Input: hours worked and hourly wage
    printf("Enter hours worked in a week:\n ");
    scanf("%lf", &hours);
    printf("Enter hourly wage: \n");
    scanf("%lf", &wage);

    // Calculate gross pay with overtime
    if (hours <= 40) {
        grossPay = hours * wage;
    } else {
        double overtimeHours = hours - 40;
        grossPay = (40 * wage) + (overtimeHours * wage * 1.5);
    }

    // Calculate taxes
    if (grossPay <= 600) {
        taxes = grossPay * 0.15;
    } else {
        taxes = (600 * 0.15) + ((grossPay - 600) * 0.20);
    }

    // Calculate net pay
    netPay = grossPay - taxes;

    // Output results
    printf("Gross Pay:\n $%.2f\n", grossPay);
    printf("Taxes:\n $%.2f\n", taxes);
    printf("Net Pay:\n $%.2f\n", netPay);

    return 0;
}