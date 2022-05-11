#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListLinkedBased.h"
#include "LinkedListAdmin.h"





BankAccount CreateBankAccount();
void AccountsInit();
void AdminInit();
void Insert_Name( BankAccount* client_Account);
void InsertAddress(BankAccount* client_Account);
void  InsertNationalID(long long int* NationalID);
void InsertAge(BankAccount* client_Account);
void CreateBankAccountID(BankAccount* client_Account);
void AccountStatus(BankAccount* client_Account,int closed);
void AccountBalance(BankAccount* client_Account);
void CreatePassword(BankAccount* client_Account);

List L;
AdminList LA;



BankAccount CreateBankAccount()
{
    BankAccount NewAccount;

    
    Insert_Name(&NewAccount );
    InsertAddress(&NewAccount);
    InsertNationalID(&NewAccount.NationalID);
    InsertAge(&NewAccount);
    CreateBankAccountID(&NewAccount);
    AccountStatus(&NewAccount,0);
    AccountBalance(&NewAccount);
    CreatePassword(&NewAccount); 
	
	

    return NewAccount;



}

void Insert_Name( BankAccount* client_Account){


    int count=0;

    fgets(client_Account->name , sizeof(client_Account->name), stdin);
       
    

        for(int i = 0; i < strlen(client_Account->name); i++) {
            if(client_Account->name[i] == ' ')
            {
            count++;
            }

        }
		
    while(count< 3)
    {

        printf("Enter at least your first four names: ");
        count = 0;

       
        fgets(client_Account->name , sizeof(client_Account->name), stdin);



        for(int i = 0; i < strlen(client_Account->name); i++) {
            if(client_Account->name[i] == ' ')
            {
            count++;
            }

        }



    }




}

void InsertAddress(BankAccount* client_Account)
{

    printf("Enter Your Full Address: ");
    fgets(client_Account->Address, sizeof(client_Account->Address), stdin);


}

void InsertNationalID(long long int* NationalID)
{

    int count=0;

    while (count != 14)
    {
        count=0;

        printf("\nEnter A valid National ID: ");
		
        scanf("%lld", NationalID);


       long long int n = *NationalID
;
        do {
            n /= 10;
            ++count;
        } while (n != 0);
        // printf("%d",count);
    }




}


void InsertAge(BankAccount* client_Account)
{

    printf("Enter Age: ");
    scanf("%d", &client_Account->Age);
    // printf("\n%d",client_Account->Age);


    if (client_Account->Age <21)
    {

        printf("\nneed Guardian");
        InsertNationalID(&client_Account->Guardian_NationalID);
    }
    else
    {
        client_Account->Guardian_NationalID=0;

    }


}

void CreateBankAccountID(BankAccount* client_Account)
{


     do
     {
         srand(time(0));
         client_Account->BankAccountID = rand() % 10;
     } while(client_Account->BankAccountID == 0);

     for(int i = 1; i < 16; i++)
     {
         client_Account->BankAccountID *= 10;
         client_Account->BankAccountID += rand() % 10;
     }


}


void AccountStatus(BankAccount* client_Account,int closed)
{


    if (closed ==1){

        strcpy(client_Account->Account_Status, "Restricted");

    }
    else
    {

        strcpy(client_Account->Account_Status, "Active");

    }

}

void AccountBalance(BankAccount* client_Account)
{

    printf("\nAdd Account Balance: ");
    scanf("%lld", &client_Account->Balance);
}

void CreatePassword(BankAccount* client_Account)
{


     do
     {
         client_Account->Password = rand() % 10;
     } while(client_Account->Password == 0);

     for(int i = 1; i < 10; i++)
     {
         client_Account->Password *= 10;
         client_Account->Password += rand() % 10;
     }


}

void AccountsInit()
{
    BankAccount client1, client2, client3;

    //client1
    strcpy(client1.name ,"Ahmed Mohamed AHmed Ali");
    strcpy(client1.Address ,"abas st 12 ");
    client1.NationalID=97823467493456;
    client1.Age = 24;
    client1.Guardian_NationalID = 0;
    client1.BankAccountID=2347895748754673;

    strcpy(client1.Account_Status ,"Active");
    client1.Balance=2500000;
    client1.Password=1023456789;

   




    List_voidInit(&L);
	
    List_voidInsertList(L.Size,&L,client1);









}

void AdminInit()
{
    Admin admin1, admin2, admin3;



    strcpy(admin1.username, "Ali Amr");
    strcpy(admin1.password, "23847593");


    
    AdminList_voidInit(&LA);


    AdminList_voidInsertList(LA.Size,&LA,admin1);




}
