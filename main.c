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
void cityManagement(){
    int choice;
    char name[50];
    do{
      printf("-----------CITY MANAGEMENT--------\n");
      printf("1. Add City\n");
      printf("2. Rename City \n");
      printf("3. Remove City \n");
      printf("4. List of Cities \n");
      printf("5. Back to main menu \n");
      printf("Enter your choice: \n");
      scanf("%d",&choice);

      if (choice==1){
        if (cityCount<MAX_CITIES){
            printf("Enter new City name:");
            scanf("%s",cities[cityCount]);
            cityCount++;
            printf("City Saved");
        }else printf("Max Cities Reached.\n");
    }else if(choice==2){
        int index;
        printf("Enter city index to rename city\n");
        scanf("%d",&index);
        if(index>=0 && index<cityCount){
            printf("Enter new name \n");
            scanf("%s",cities[index]);
            printf("Changed successfully\n");
        }else printf("Invalid index!\n");
    }else if(choice==3){
        int i;
        int j;
        printf("Enter city index to remove:");
        scanf("%d",&i);
        if(i>=0 && index<cityCount){
            for(j=i;j<cityCount-1;i++);
                strcpy(cities[i],cities[i+1]);
                cityCount--;
                printf("City removed \n");
        }else printf("Invalid index\n");
    }else if(choice==4){
        int k;
        for (k=0:k<cityCount;k++){
            printf("%d. %s\n",k,cities[k]);
        }

    }
    }while(choice!=0);
}
