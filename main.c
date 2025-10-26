#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_DELIVERIES 50
#define MAX_VEHICLES 3

char cities[MAX_CITIES][50];
int distance[MAX_CITIES][MAX_CITIES];
int cityCount=0;
char vehicleTypes[MAX_VEHICLES][50]={"Van","Truck","Lorry"};
int vehicleMatrix[MAX_VEHICLES][4]={
        {1000,30,60,12},
        {500,40,50,6},
        {10000,80,45,4},
    };
typedef struct{
    int source;
    int destination;
    float weight;
    int vehicleType;
    float distance;
    float deliveryCost;
    float fuelCost;
    float totalCost;
    float profit;
    float customerCharge;
    float time;
} Delivery;
Delivery deliveries[MAX_DELIVERIES];
int deliveryCount=0;


void cityManagement();
void distanceManagement();
void vehicleManagement();
void deliveryHandling();
float findLeastCostRoute(int source,int dest,int path[]);
void reports(int source,int dest,float weight,int vehicleType);
void viewDeliveries();
void performanceReports();

int main()
{
    int choice;
    do{
        printf("---------LOGISTICS MANAGEMENT SYSTEM-------\n");
        printf("1. City Management \n");
        printf("2. Distance Management \n");
        printf("3. Vehicle Management \n");
        printf("4. Delivery Handling & Reports \n");
        printf("5. Performance Reports \n");
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
            performanceReports();
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
    char input;
    char name[50];
    int x;
    int y;
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
            do{
            printf("Enter new City name: ");
            scanf("%s",cities[cityCount]);
            cityCount++;
            printf("City Saved\n");
            printf("Do you want to add another city? (Y/N):\n");
            scanf(" %c", &input);
            for (x=0;x<cityCount;x++){
                for(y=0;y<cityCount;y++){
                    if (x==y)
                        distance[x][y]=0;
                    else if (distance[x][y]==0)
                        distance[x][y]=-1;
                }
            }
            }while (input!='n' && input!='N');
        }else {
            printf("Max Cities Reached.\n");
        }
    }else if(choice==2){
        int index;
        printf("Enter city index to rename city\n");
        scanf(" %d",&index);
        if(index>=0 && index<cityCount){
            printf("Enter new name \n");
            scanf("%s",cities[index]);
            printf("Changed successfully\n");
        }else {
            printf("Invalid index!\n");
    }
    }else if(choice==3){
        int i;
        int j;
        int k;
        printf("Enter city index to remove:");
        scanf("%d",&i);
        if(i>=0 && i<cityCount){
            for(j=i;j<cityCount-1;i++);
                strcpy(cities[i],cities[i+1]);
        }
        for (j=i;j<cityCount-1;j++){
            for (k=0;k<cityCount;k++){
                distance[j][k]=distance[j+1][k];
                distance[k][j]=distance[k][j+1];
                }
        }
        cityCount--;
        printf("City removed\n");
    } else if(choice==4){
        int n;
        if (cityCount<1){
            printf("No data entered yet\n");
        }
        for (n=0;n<cityCount;n++){
            printf("%d. %s\n",n+1,cities[n]);
        }
    }
    }while(choice!=5);
}
void distanceManagement(){
    if (cityCount<2){
        printf("Please add atleast two cities first \n");
        return;
    }
int i;
int j;
int choice;
int dist;
do{
     printf("-------DISTANCE MANAGEMENT------\n");
     printf("1.View all Distances\n");
     printf("2.Edit distances between cities\n");
     printf("3.Back to main menu\n");
     printf("Enter your choice:\n");
     scanf("%d",&choice);

    switch(choice){
    case 1:
        printf("--------DISTANCES--------\n");
        printf("%-10s","");
        for (i=0;i<cityCount;i++){
            printf("%10s",cities[i]);

        }
        printf("\n");
        for (i=0;i<cityCount;i++){
            printf("%-10s",cities[i]);
            for (j=0;j<cityCount;j++){
                printf("%10d",distance[i][j]);
            }
            printf("\n");
        }
        break;
    case 2:
        printf("Enter 1st city index(1-%d):",cityCount-1);
        scanf("%d",&i);
        printf("Enter destination city number(1-%d):",cityCount-1);
        scanf("%d",&j);
        i--;
        j--;
        if (i==j){
            printf("Distance to self is always 0");
            distance[i][j]=0;
            break;
            }
        if (i>=cityCount || j>=cityCount || i<0 || j<0){
            printf("Invalid city index.\n");
            break;
        }
        printf("Enter distance between %s and %s (km): ",cities[i],cities[j]);
        scanf("%d",&dist);
        distance[i][j]=dist;
        distance[j][i]=dist;
        printf("Saved successfully\n");
        break;
    case 3:
        printf("Returning to main menu...\n");
        break;
    default:
        printf("Invalid choice. \n");
    }
}while (choice!=3);
}
void vehicleManagement(){
    int choice;
    int i;
    do{
    printf("----VEHICLE MANAGEMENT-----\n");
    printf("1.View vehicle details\n");
    printf("2.Back to main menu\n");
    printf("Enter your choice: \n");
    scanf("%d",&choice);

    switch(choice){
    case 1:
        printf("\n---------VEHICLE DETAILS--------------\n");
        printf("%-5s %-10s %-10s %-10s %-10s %-10s\n","No", "Type", "Capacity", "Rate/km", "Speed", "Efficiency");
        for (i=0;i<MAX_VEHICLES;i++){
                printf("%-5d %-10s %-10d %-10d %-10d %-10d\n",i+1,vehicleTypes[i],vehicleMatrix[i][0],vehicleMatrix[i][1],vehicleMatrix[i][2],vehicleMatrix[i][3]);
        }
        break;
    case 2:
        printf("Returning to main menu\n");
        break;
    default:
        printf("Invalid Choice\n");
        break;
    }
    }
    while(choice!=2);
}
void deliveryHandling(){
    int source;
    int dest;
    int vehicleType;
    float weight;
    int choice;
    int i;
    int path[MAX_CITIES];
    float minDistance=0;
    printf("-------DELIVERY REQUEST HANDLING------\n");
    do{
        printf("1.Enter a new report\n");
        printf("2.View Reports\n");
        printf("3.View all deliveries\n");
        printf("4.Return to main menu\n");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                printf("Available Cities: \n");
                for (i=0;i<cityCount;i++){
                    printf("%d. %s\n",i+1,cities[i]);
                }
            printf("\nEnter source city index: \n");
            scanf("%d",&source);
            printf("Enter destination city index: \n");
            scanf("%d",&dest);
            if (source==dest){
                printf("Error: The source cannot be the same as the destination\n");
                return;
            }
            printf("Enter weight (in kg):\n");
            scanf("%f",&weight);
            printf("\nSelect vehicle type\n");
            printf("1. Van\n2. Truck\n3. Lorry \n");
            scanf("%d",&vehicleType);
            if (vehicleType<1||vehicleType>3){
                printf("Invalid vehicle type \n");
                return;
            }
            int capacity=vehicleMatrix[vehicleType-1][0];
            if (weight>capacity){
                printf("Error: Weight exceeds selected vehicle's capacity\n");
                return;
            }
            int D=distance[source-1][dest-1];
            float R=vehicleMatrix[vehicleType-1][1];
            float S=vehicleMatrix[vehicleType-1][2];
            float E=vehicleMatrix[vehicleType-1][3];
            float F=310;

            float deliveryCost=D*R*(1+(weight/1000.0));
            float deliveryTime=D/S;
            float fuelUsed=D/E;
            float fuelCost=fuelUsed*F;
            float totalCost=deliveryCost+fuelCost;
            float profit=deliveryCost*0.25;
            float customerCharge=totalCost+profit;

            deliveries[deliveryCount].source=source-1;
            deliveries[deliveryCount].destination=dest-1;
            deliveries[deliveryCount].weight=weight;
            deliveries[deliveryCount].vehicleType=vehicleType-1;
            deliveries[deliveryCount].distance=D;
            deliveries[deliveryCount].deliveryCost=deliveryCost;
            deliveries[deliveryCount].fuelCost=fuelCost;
            deliveries[deliveryCount].totalCost=totalCost;
            deliveries[deliveryCount].profit=profit;
            deliveries[deliveryCount].customerCharge=customerCharge;
            deliveries[deliveryCount].time=deliveryTime;
            deliveryCount++;
            break;
            case 2:
                minDistance=findLeastCostRoute(source-1,dest-1,path);
                printf("\nLeast cost distance between %s and %s: %.2f km\n",cities[source-1],cities[dest-1],minDistance);
                reports(source-1,dest-1,weight,vehicleType-1);
                break;
            case 3:
                viewDeliveries();
                break;
            case 4:
                printf("Returning to main menu\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        }
        while (choice!=4);
}
void reports(int source,int dest,float weight,int vehicleType){
        int D=distance[source][dest];
        float W=weight;
        float R=vehicleMatrix[vehicleType-1][1];
        float S=vehicleMatrix[vehicleType-1][2];
        float E=vehicleMatrix[vehicleType-1][3];
        float F=310;

        float deliveryCost=D*R*(1+(W/1000.0));
        float deliveryTime=D/S;
        float fuelUsed=D/E;
        float fuelCost=fuelUsed*F;
        float totalCost=deliveryCost+fuelCost;
        float profit=deliveryCost*0.25;
        float customerCharge=totalCost+profit;

        printf("\n-------DELIVERY SUMMARY------\n");
        printf("From        : %s\n",cities[source]);
        printf("To          : %s\n",cities[dest]);
        printf("Vehicle Type: %s\n",vehicleTypes[vehicleType-1]);
        printf("---------------------------\n");
        printf("Distance    :%d km\n",D);
        printf("Rate per km :%.2f LKR\n",R);
        printf("Weight      :%.2f kg\n",W);
        printf("Efficiency  :%.2f km/l\n",E);
        printf("Fuel Price  :%.2f LKR\n",F);
        printf("----------------------------\n");
        printf("Delivery Cost           :%.2f LKR\n",deliveryCost);
        printf("Estimated Time          :%.2f hours\n",deliveryTime);
        printf("Fuel Used               :%.2f liters\n",fuelUsed);
        printf("Fuel Cost               :%.2f LKR\n",fuelCost);
        printf("Total Operational Cost  :%.2f LKR\n",totalCost);
        printf("Profit (25%%)           :%.2f LKR\n",profit);
        printf("Final Charge to Customer:%.2f LKR\n",customerCharge);
        printf("===================================\n");
}
float findLeastCostRoute(int source,int dest,int path[]){
    int visited[MAX_CITIES];
    float cost[MAX_CITIES];
    int prev[MAX_CITIES];
    int i;
    int j;
    int k;
    int n;
    int minIndex;
    float minDist;
    for (i=0;i<cityCount;i++){
        cost[i]=1e9;
        visited[i]=0;
        prev[i]=-1;
    }
    cost[source]=0;
    for (j=0;j<cityCount-1;j++){
        minDist=1e9;
        minIndex=-1;
        for(k=0;k<cityCount;k++){
            if(!visited[k]&&cost[k]<minDist){
                minDist=cost[k];
                minIndex=k;
            }
        }
        if (minIndex==-1){
            break;
        }
        visited[minIndex]=1;
        for (n=0;n<cityCount;n++){
            if(distance[minIndex][n]>0&&!visited[n]){
                float newDist=cost[minIndex]+distance[minIndex][n];
                if(newDist<cost[n]){
                    cost[n]=newDist;
                    prev[n]=minIndex;
                }
            }
        }
    }
    int stack[MAX_CITIES];
    int top=0;
    int current=dest;
    while (current!=-1){
        stack[top++]=current;
        current=prev[current];
    }
    int index=0;
    printf("\nShortest Route:");
    int x;
    for (x=top-1;x>=0;x--){
        path[index++]=stack[x];
        printf("%s",cities[stack[x]]);
        if(i>0){
            printf("->");
        }
        }
    printf("\nTotal Distance: %.2f km\n",cost[dest]);
    return cost[dest];
}
void viewDeliveries(){
    if (deliveryCount==0){
        printf("\nNo delivery  records yet. \n");
        return;
        }
    printf("\n-------------DELIVERY RECORDS----------\n");
    int i;
    for(i=0;i<deliveryCount;i++){
       printf("\nDelivery #%d\n",i+1);
        printf("From   : %-10s\n",cities[deliveries[i].source]);
        printf("To     : %-10s\n",cities[deliveries[i].destination]);
        printf("Vehicle: %-10s\n",vehicleTypes[deliveries[i].vehicleType]);
        printf("Weight         : %.2f kg\n",deliveries[i].weight);
        printf("Distance       : %.2f km\n",deliveries[i].distance);
        printf("Delivery Cost  : %.2f LKR\n",deliveries[i].deliveryCost);
        printf("Fuel Cost      : %.2f LKR\n",deliveries[i].fuelCost);
        printf("Total Cost     : %.2f LKR\n",deliveries[i].totalCost);
        printf("Profit         : %.2f LKR\n",deliveries[i].profit);
        printf("Customer Charge: %.2f LKR\n",deliveries[i].customerCharge);
        printf("Estimated Time : %.2f hours\n",deliveries[i].time);
        printf("------------------------------------\n");
         }
 }
 void performanceReports(){
        if (deliveryCount==0){
            printf("\nNo deliveries recorded yet.\n");
            return;
        }
 float totalDistance=0;
 float totalTime=0;
 float totalRevenue=0;
 float totalProfit=0;
 float longest=deliveries[0].distance;
 float shortest=deliveries[0].distance;
 int i;

 for (i=0;i<deliveryCount;i++){
    totalDistance+=deliveries[i].distance;
    totalTime+=deliveries[i].time;
    totalRevenue+=deliveries[i].customerCharge;
    totalProfit+=deliveries[i].profit;
    if (deliveries[i].distance>longest)
        longest=deliveries[i].distance;
    if (deliveries[i].distance<shortest)
        shortest=deliveries[i].distance;
 }
 float avgTime=totalTime/deliveryCount;
 printf("\n=======PERFORMANCE REPORTS==========\n");
 printf("Total deliveries completed: %d\n",deliveryCount);
 printf("Total distance covered    : %.2f km\n",totalDistance);
 printf("Average delivery time     : %.2f hours\n",avgTime);
 printf("Total revenue earned      : %.2f LKR\n",totalRevenue);
 printf("Total profit earned       : %.2f LKR\n",totalProfit);
 printf("Longest route completed   : %.2f km\n",longest);
 printf("Shortest route completed  : %.2f km\n",shortest);
 printf("=======================================\n");
 int userInput;
 printf("Press 1 to return to main menu\n");
 scanf("%d",&userInput);
 if(userInput==1){
    return;
 }else{
    printf("Invalid input\n");
 }
 }











