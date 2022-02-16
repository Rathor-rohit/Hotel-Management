#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct customer
{    int date , month , year;
     char c_name[20];
     int totalPerson;
     char address[30];
     char contact[10];
     char roomType[5];
     int totalPay;
}s;

void menu()
{   int a;
    start:
    printf("\n----------------------------------------------------------------------------------------------------------------------\n");	
    printf("-------------------------------------------- Welcome to Hotel Taaj ----------------------------------------------------"); 
	printf("\n----------------------------------------------------------------------------------------------------------------------\n");	
    printf("\n\t\t 1. Staff Side \n\t\t 2. Client Side\n\t\t Enter Your Choice :- ");
    scanf("\n\t\t\t%d",&a);

    if(a==1)
    {   char uid[5],pwd[5];
        printf("\n------------------------------------------------------------------------------------------------------------------\n");
        printf("  ------------------------------------------------ Staff Login -----------------------------------------------------");
        printf("\n------------------------------------------------------------------------------------------------------------------\n");
        printf("\n Enter User_id :");
        fflush(stdin);
        gets(uid);
        printf("\n Enter Password :");
        fflush(stdin);
        gets(pwd);
        if(((strcmp(uid,"rohit")==0) ||(strcmp(uid,"ROHIT")==0))&& (strcmp(pwd,"0000")==0))
        {
            system("cls");
            staffSide();
        }
        else
        {   printf("\nPlz enter right User_Id or Password !!!!!!!!!\n");
            goto start;
        }
    }
    else if (a==2)
    {
        clientSide();
    }
    else
    {
        printf("Please enter correct choice ");
        goto start;
    }
} 
void addCustomer()
{
    printf("---------------------------- Customer Registration ---------------------------\n");
    
    printf("\nEnter Date of Check-In (1-31) :- ");
    fflush(stdin);
    scanf("%d",&s.date);
    printf("\nEnter Month of check-in (1-12) :- ");
    fflush(stdin);
    scanf("%d",&s.month);
    printf("\n Enter Year of check-in (ex.-2022) :- ");
    fflush(stdin);
    scanf("%d",&s.year);
    printf("\n Enter Customer's Name :- ");
    fflush(stdin);
    gets(s.c_name);
    printf("\n Total person : ");
    fflush(stdin);
    scanf("%d",&s.totalPerson);
    printf("\nEnter Contact Number :- ");
    fflush(stdin);
    gets(s.contact);
    printf("\n Enter Address of Customer :- ");
    fflush(stdin);
    gets(s.address);
    printf("\n Room Type(Ac or Non Ac) : ");
    fflush(stdin);
    gets(s.roomType);
    printf("Total Pay :- ");
    fflush(stdin);
    scanf("%d",&s.totalPay);
    
    FILE *fp;
    fp=fopen("hotelManagement.bin","ab+");
	if(fp==NULL)
	{
		printf("Unable to create file !");
       
	}
    else
    {
	fwrite(&s,sizeof(s),1,fp);
     printf("\n detail saved successsfulyy !");
    
    }
	fclose(fp);
   
}

void SeeRecord(void)
{   
   
    int got=0,i=0;
    
    printf("------------------------------------------------------------------------------------------\n");
    printf("                                 ALL RAGISTRATED CUSTOMERS                                    \n");
    printf("------------------------------------------------------------------------------------------\n");
    FILE *fp;
	fp=fopen("hotelManagement.bin","rb");
	if(fp==NULL)
	{
		printf("Unable to open the file !\n");
	}
    else
    {
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		got=1;
		i++;
		printf("\n-----------------------------------------------------\n");
		printf("\tRecord --> %i ",i);
		fflush(stdout);
		printf("\n\tCheck-In Date : %d-%d-%d",s.date,s.month,s.year);
		fflush(stdout);
		printf("\n\tName    : %s",s.c_name);
		fflush(stdout);
		printf("\n\tNo of Person   : %d",s.totalPerson);
		fflush(stdout);
		printf("\n\tCont. No. : %s",s.contact);
		fflush(stdout);
		printf("\n\tAddress  : %s",s.address);
		fflush(stdout);
        printf("\n Room Type : %s",s.roomType);
        fflush(stdout);
        printf("\n Total pay : %d ", s.totalPay);
		//break;
	}
	fclose(fp);
	if(got==0)
	{
		printf("\nThere is no record !!!!!!!!!!\n\n");
	}
    }
    printf("\n\n\t\t----------------------\n");
    printf("\t\tTotal Customers---> %d\n",i);
    printf("\t\t----------------------\a\n");
    
	
	
}                   

void seeAcRoom()
{
    FILE *fp;
    int i=0;
    int totalRoom=20;
	fp=fopen("hotelManagement.bin","rb");
	if(fp==NULL)
	{
		printf("Unable to open the file !\n");
	}
    else
    {
	while(fread(&s,sizeof(s),1,fp)==1)
	{
        if( strcmp(s.roomType,"AC")==0 || strcmp(s.roomType,"Ac")==0 || strcmp(s.roomType,"ac")==0)
        {
            i++;
        }
        
    }

    if(i==0)
    {
        printf("\nAll Rooms Are vacant :");
    }
    else{
              printf("\nTotal Ac Room Avialable = %d",totalRoom-i);
    }
     
    fclose(fp);
    
    }
    }
    void seeNonAcRoom()
{
    FILE *fp;
    int i=0;
    int totalRoom=20;
	fp=fopen("hotelManagement.bin","rb");
	if(fp==NULL)
	{
		printf("\nUnable to open the file !\n");
	}
    else
    {
	while(fread(&s,sizeof(s),1,fp)==1)
	{
        if( strcmp(s.roomType,"NONAC")==0 || strcmp(s.roomType,"NON-AC")==0 ||  strcmp(s.roomType,"non ac")==0|| strcmp(s.roomType,"Non Ac")==0 ||strcmp(s.roomType,"NON AC")==0)
        {
            i++;
        }
        
    }

    if(i==0)
    {
        printf("\nAll Rooms Are vacant :");
    }
    else{
              printf("\nTotal Non-Ac Room  Avialable = %d",totalRoom-i);
    }
     
    fclose(fp);
    
    }
    }
  void seeCusDet()
  { 
    char name[20];
    int i=0;
    printf("\nEnter Customer Name : ");
    fflush(stdin);
    gets(name);  
    FILE *fp;
	fp=fopen("hotelManagement.bin","rb");
	if(fp==NULL)
	{
		printf("Unable to open the file !\n");
	}
    else
    {
	while(fread(&s,sizeof(s),1,fp)==1)
	{
        if( strcmp(s.c_name,name)==0 )
        {
            printf("\n Name = %s",s.c_name);
            printf("\n Room type %s",s.roomType);
            printf("\n Date %d-%d-%d",s.date,s.month,s.year);
            i=1;
        }
        
    }
    fclose(fp);
    if(i!=1)
    {
        printf("\n No Record Found of this name!!!!!!");
    }


  }
  }
  
  void welcome()
  {
      printf("\n\t---------------------------------------------------------------------------------------------------------------------------------------------");
      printf("\n                    ---------------------------------------  WELCOME TO HOTEL TAJ  ---------------------------------------\n");
      printf("\t---------------------------------------------------------------------------------------------------------------------------------------------");
     
  }
  void hotelDetails()
  {
      printf("coming soon");
  }
  void clientSide()
    {   int ch,cho; 
        start:
      
      printf("\n1. Know about Taj \n2. See Vacant Rooms \n0. Exit \n Enter Choice :-");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1:
          hotelDetails();
          break;
          case 2:
          printf("1. Ac rooms \n 2. Non Ac rooms \n 0. Exit \n Enter choice :-");
          scanf("%d",&cho);
          switch(cho)
          {
              case 1:
              seeAcRoom();
              break;
              case 2:
              seeNonAcRoom();
              break;
              case 0:
              exit(0);
              break;
              default :
              printf("Enter correct choice :");
              goto start;
              
          }
          break;
          case 0:
          exit(0);
          break;
          default :
          printf("Enter correct choice");
          goto start;
      }
  }

  void staffSide()
  {
     
      int choice;
      system("cls");
      again:
      welcome();
      printf("\n  1.Book A Room : \n  2.See A Record(By Name) :\n  3.See All Records :\n  4.Delete a Record :\n  5.See Vacant Ac Rooms :\n  6.");
	  printf("See VAcant Non Ac Rooms :\n  0.Exit :\n\t\t\t Please Enter Choice :- ");
      scanf("%d",&choice);
      switch(choice)
      {
          case 1:
          addCustomer();
          break;
          case 2:
          seeCusDet();
          break;
          case 3:
          SeeRecord();
          break;
          case 4:
          delRecord();
          break;
          case 5:
          seeAcRoom();
          break;
          case 6:
          seeNonAcRoom();
          break;
          case 0:
          exit(0);
          break;
          default :
          printf("Plz Enter correct Choice : ");
          goto again;
      }
  }
   ////////////////////////// Delete a record
   void delRecord()
   {
    FILE *fp1;
	FILE *fp2;
	int l;
	char name[20];
	fp1=fopen("hotelManagement.bin","rb");
	fp2=fopen("hotelManagementDelete.bin","wb");
	if(fp1==NULL||fp2==NULL)
	{
		printf("\n\t Error : Unable to open the file !!!!!!");
		sleep(2);
		return;
    }
    welcome();
    printf("\n\t------------------------------------------ Delete Customer's' Record ---------------------------------");
    printf("\n\tEnter Customer Name     : ");
    fflush(stdin);
    gets(name);
    // Coping data source file to delete file
    while(fread(&s,sizeof(s),1,fp1)==1)
    {
          if(strcmp(name,s.c_name)==0)
          {
          	l=1;
          }
          else
          {
			fwrite(&s,sizeof(s),1,fp2);
		  }
    	
	}
	fclose(fp1);
	fclose(fp2);
	if(l!=1)
	{
		printf("\n\t There is no record with this Name!!!!!!!!!!!!\n");
		return;
	}
	else
  {
	fp1=fopen("hotelManagement.bin","wb");
	fp2=fopen("hotelManagementDelete.bin","rb");
	if(fp1==NULL || fp2==NULL)
	{
		printf("\n\t Error : Unable to open file !!!!\n");
		return;
	}
	else
	{
		// Coping Data from Delete file to Sourse file
	   while(fread(&s,sizeof(s),1,fp2)==1)
	   {
		fwrite(&s,sizeof(s),1,fp1);
	    }
	}
	fclose(fp1);
	fclose(fp2);
  }
	fp2=fopen("hotelManagementDelete.bin","wb");
	fclose(fp2);
	printf("\n\tRecord has been deleted successfully!!!!!!!!!!!!\n");
	getch();
	}
	 
  

int main()
{   
    menu();
   
    
    getch();
    return 0;
}
