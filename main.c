#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_DELIVERIES 50

void cityManagement();
void distanceManagement();
void vehicleManagement();
void deliveryHandling();
void reports();

int main()
{
    int choice;
    char cities[MAX_CITIES][50];
    int cityCount=0;
    do{
        printf("---------LOGISTICS MANAGEMENT SYSTEM-------\n");
        printf("1. City Management \n");
        printf("2. Distance Management \n");
        printf("3. Vehicle Management \n");
        printf("4. Delivery Handling \n");
        printf("5. Reports \n");
        printf("6. Exit \n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);

        switch(choice){
        case 1:
            cityManagement();
            break;
        case 2:
            distanceManagement();
            break;
        case 3:
            vehicleManagement();
            break;
        case 4:
            deliveryHandling();
            break;
        case 5:
            reports();
            break;
        case 6:
            printf("Exiting Program..");
            break;
        default:
            printf("Invalid Input...Please enter a number (1-6)");
        }
    }while (choice!=6);

return 0;
}
