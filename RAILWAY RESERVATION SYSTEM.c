/* Railway Reservation System */
#include <stdio.h>

struct ticket
{
    int pnr;
    char name[20];
    int age;
    int train;
    int seat;
};

struct ticket t[100];
int count = 0;
int pnrNo = 1001;

int showTrains()
{
    printf("\nTrain List\n");
    printf("1. Shatabdi Express (Delhi - Kalka)\n");
    printf("2. Rajdhani Express (Delhi - Chandigarh)\n");
    printf("3. Kalka Mail (Kalka - Howrah)\n");
    return 0;
}

int bookTicket()
{
    int train, seat, i, booked = 0;

    showTrains();
    printf("Enter train number (1-3): ");
    scanf("%d", &train);
    printf("Enter seat number (1-10): ");
    scanf("%d", &seat);

    if (train < 1 || train > 3 || seat < 1 || seat > 10)
    {
        printf("Invalid train or seat\n");
        return 0;
    }

    for (i = 0; i < count; i++)
    {
        if (t[i].train == train && t[i].seat == seat)
            booked = 1;
    }

    if (booked == 1)
        printf("Seat already booked\n");
    else
    {
        printf("Enter name: ");
        scanf("%s", t[count].name);
        printf("Enter age: ");
        scanf("%d", &t[count].age);

        t[count].pnr = pnrNo;
        t[count].train = train;
        t[count].seat = seat;

        printf("Ticket booked. Your PNR is %d\n", pnrNo);
        pnrNo++;
        count++;
    }
    return 0;
}

int cancelTicket()
{
    int pnr, i, j, found = 0;

    printf("Enter PNR to cancel: ");
    scanf("%d", &pnr);

    for (i = 0; i < count; i++)
    {
        if (t[i].pnr == pnr)
        {
            for (j = i; j < count - 1; j++)
                t[j] = t[j + 1];
            count--;
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        printf("Ticket cancelled\n");
    }
    else
        printf("PNR not found\n");
    return 0;
}

int display()
{
    int i;
    if (count == 0)
        printf("No reservations\n");
    else
    {
        printf("\nPNR\tName\tAge\tTrain\tSeat\n");
        for (i = 0; i < count; i++)
            printf("%d\t%s\t%d\t%d\t%d\n", t[i].pnr, t[i].name, t[i].age, t[i].train, t[i].seat);
    }
    return 0;
}

int main()
{
    int choice;

    printf("***** RAILWAY RESERVATION SYSTEM *****\n");

    while (1)
    {
        printf("\n1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Display Reservations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: bookTicket(); break;
            case 2: cancelTicket(); break;
            case 3: display(); break;
            case 4: printf("Thank you!\n"); return 0;
            default: printf("Wrong choice\n");
        }
    }
}