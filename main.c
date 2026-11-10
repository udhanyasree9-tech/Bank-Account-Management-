#include <stdio.h>
int main()
{
   int choice, acc[50], n = 0, i, found;
   char name[50][30];
   float balance[50], amount;
   printf("\n====================================");
   printf("\n       BANK ACCOUNT MANAGEMENT");
   printf("\n====================================");
   do
   {
      printf("\n1.Create Account");
      printf("\n2.Deposit Money");
      printf("\n3.Withdraw Money");
      printf("\n4.Display Accounts");
      printf("\n5.Exit");
      printf("\nEnter choice: ");
      scanf("%d", &choice);
      switch(choice)
      {
          case 1:
              printf("Enter account number: ");
              scanf("%d", &acc[n]);
              found = 0;
              for(i = 0; i < n; i++)
                  if(acc[i] == acc[n])
                      found = 1;
              if(found || n == 50)
              {
                  printf("Account already exists or limit reached!");
                  break;
              }
              printf("Enter name: ");
              scanf(" %[^\n]", name[n]);

              printf("Enter initial balance: ");
              scanf("%f", &balance[n]);

              if(balance[n] < 0)
              {
                  printf("Invalid balance!");
                  break;
              }
              n++;
              printf("Account Created Successfully!");
              break;
          case 2:
          case 3:
              printf("Enter account number: ");
              scanf("%d", &acc[50]);
              found = 0;
	      for(i = 0; i < n; i++)
              {
                  if(acc[i] == acc[50])
                  {
                      found = 1;
                      printf("Enter amount: ");
                      scanf("%f", &amount);

                      if(amount <= 0)
                          printf("Invalid amount!");
                      else if(choice == 2)
                          balance[i] += amount;
                      else if(amount <= balance[i])
                          balance[i] -= amount;
                      else
                          printf("Insufficient balance!");
                      break;
                  }
              }
              if(!found)
                   printf("Account not found!");
              break;
          case 4:                
              for(i = 0; i < n; i++)
                  printf("\n%d  %s  %.2f",acc[i], name[i], balance[i]);
              break;
          case 5:
              printf("Thank You!");
              break;

          default:
              printf("Invalid Choice!");
      }
   } while(choice != 5);
   return 0;
}







