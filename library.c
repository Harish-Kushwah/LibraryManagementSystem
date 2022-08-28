#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<windows.h>

void login();
void signup();
void OTP();

void color(char col[15])
{
	HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);
  if(strcmp(col,"green")==0)
  {
	SetConsoleTextAttribute(h,2);        //green
  }
  else if(strcmp(col,"blue")==0)
  {
	SetConsoleTextAttribute(h,1);        //blue
  }
  else if(strcmp(col,"white")==0)
  {
	SetConsoleTextAttribute(h,7);        //white
  }
  else if(strcmp(col,"aqua")==0)
  {
	SetConsoleTextAttribute(h,3);       //aqua
  }
  else if(strcmp(col,"yellow")==0)
  {
	SetConsoleTextAttribute(h,6);      //yellow
  }
  else if(strcmp(col,"gray")==0)
  {
	SetConsoleTextAttribute(h,8);      //gray
  }
  else if(strcmp(col,"purple")==0)
  {
	SetConsoleTextAttribute(h,5);     //purple
  }
  else if(strcmp(col,"lightgreen")==0)
  {
	SetConsoleTextAttribute(h,10);
  }
  else if(strcmp(col,"lightblue")==0)
  {
	SetConsoleTextAttribute(h,9);
  }
  else if(strcmp(col,"lightred")==0)
  {
	SetConsoleTextAttribute(h,12);
  }
  else if(strcmp(col,"lightpurple")==0)
  {
	SetConsoleTextAttribute(h,13);
  }
  else if(strcmp(col,"lightyellow")==0)
  {
	SetConsoleTextAttribute(h,14);
  }

}
void delay(int n)
{
	int end = 100*n;
	clock_t st = clock();
	while(clock()<st+end);
}
void line1(){
	int i;
	for(i=1; i<=20;i++){
		printf("_");
	}
}
struct user
{
	char uname[20];
	char upass[20];
};	
struct book
{
	int bookid;
	char bname[20];
	float price;
	int quantity;
	
};
struct maintain
{
	char mname[20];
	char mpass[20];
};
//Add maintainer
void signup1()
{
	FILE *fp;
	struct maintain m1;
	int i;
	fflush(stdin);
	color("yellow");
	printf("_________________[SIGNUP HEAR]________________\n");
	fp = fopen("maintainer_info.dat","ab");
	color("aqua");
	printf("Enter a maintainer name :");
	color("lightgreen");
	gets(m1.mname);
	color("aqua");
	printf("\nEnter a maintainer passowd(4) :");
	fflush(stdin);
	color("lightgreen");
 	scanf("%s", m1.mpass);
 	/*for(i=0;i<4;i++){
 		m1.mpass[i]=getch();
 		//printf("*");
 	}*/
 	printf("\n");
	fwrite(&m1,sizeof(m1),1,fp);
	fclose(fp);
	color("purple");
	printf("Account is succesfully created\n");
	color("white");
	line1();
	
}
//Maintainer login
int login1()
{
	FILE *fp;
	struct maintain m1;
	char mname[20];
	 char  mpass[20];
	int chu,chp,k;
	int i,flag1=0,flag2=0;
	fflush(stdin);
	color("yellow");
	printf("_________________[LOGIN HEAR]_________________\n");
	fp =fopen("maintainer_info.dat","rb");
	color("aqua");
	printf("Enter a user name :");
	color("lightgreen");
	scanf("%s", mname);
    fflush(stdin);
	color("aqua");
	printf("\nEnter a password(4) :");
	color("lightgreen");
		scanf("%s",mpass);
	/*	for(i=0; i<5; i++){
			mpass[i]=getch();
			printf("*");
		}*/
		printf("\n");
	 delay(1);
	line1();
	printf("\n");
	while(fread(&m1,sizeof(m1),1,fp)>0&&flag1==0&&flag2==0){
		chu = strcmp(mname,m1.mname);
		if(chu==0){
			flag1 =1;
		}
		chp = strcmp(mpass,m1.mpass);
		if(chp==0){
			flag2=1;
		}
	}
		if(flag1==1 && flag2==1){
			color("purple");
			printf("User is avaible\n");
			printf("Name of User :");
			color("lightgreen");
			printf("%s " , m1.mname);
	          k=1;
	     }
	  else if(flag1==1 &&flag2!=1){
		color("purple");
		printf("\n Enter a right password\n");
		k=0;
		}
	   else if(flag1!=1 && flag2==1){
		color("purple");
		printf("\n Enter a valide user name\n");
		k=0;
		}
	else{
		color("purple");
	   printf("\nNo user info .. create account\n");
	   k=0;
	}
	printf("\n");
	line1();
	color("white");
	printf("\n");
	  fclose(fp);
	  if(k==1){
	  	return 1;
	  }
	  else
	    return 0;
  }	
//add new book
void addbook(){
	FILE *fp;
	struct book b1;
	char str[20];
	fp = fopen("books_collection.dat", "ab");
	 color("aqua");
	 printf("Enter a bookid :");
	 color("lightgreen");
     scanf("%d", &b1.bookid);
     fflush(stdin);
	 color("aqua");
     printf("Enter a book name :");
	 color("lightgreen");
     gets(b1.bname);
	 color("aqua");
     printf("Enter a book price :");
	 color("lightgreen");
     scanf("%f", &b1.price);
	 color("aqua");
     printf("Enter a quantity of book :");
	 color("lightgreen");
     scanf("%d", &b1.quantity);
     fwrite(&b1,sizeof(b1), 1,fp);
    fclose(fp);
	color("purple");
    printf("\nBook is succesfully added..\n");
	color("white");
}
//show all the books avaible
void showall()
{
	FILE *fp;
	struct book b1;
	int i=1;
	fp = fopen("books_collection.dat", "rb");
	color("lightyellow");
	printf("_______________[WELCOME IN TO STORE]______________\n");
	if(fp ==NULL){
		color("purple");
	     printf("No book is added still");
	     exit(1);
	}
	color("lightgreen");
      line1();	 
     while(fread(&b1,sizeof(b1),1,fp)>0){
	 color("aqua");
     printf("\n%d] BOOK_ID:",i);
	 color("lightgreen");
	 printf("%d",b1.bookid);
	 color("aqua");
	 printf("\n BOOK_NAME :");
	 color("lightgreen");
	 printf("%s",b1.bname);
	 color("aqua");
	 printf("\n BOOK_PRICE:Rs");
	 color("lightgreen");
	 printf("%0.2f",b1.price);
	 color("aqua");
	 printf("\n QUANTITY  :");
	 color("lightgreen");
	 printf("%d",b1.quantity);
     printf("\n");
     line1();
     printf("\n");
     i++;
     }
	fclose(fp);
	color("white");
	
}
//finds a book according to bookid or book name	
int findbook()
{
	FILE *fp;
	struct book b1;
	int bookid,flag = 0,n ;
	fp = fopen("books_collection.dat","rb");
	color("lightblue");
	printf("Enter how want to search\n");
	color("green");
	printf(" 1 ==bookid\n 2 ==bname\n");
	scanf("%d", &n);
	fflush(stdin);
	//by usind bookid
	if(n==1){
	color("aqua");
	printf("Enter a book ID :");
	color("lightgreen");
	scanf("%d" , &bookid);
	int i=1;
	while(fread(&b1,sizeof(b1),1,fp)>0 &&flag ==0){
	  	if(b1.bookid ==bookid){
	  		line1();
	  		//printf("  \n   BOOK_ID :%d\n BOOK_NAME :%s \n BOOK_PRICE:Rs%0.2f\n QUANTITY  :%d",b1.bookid,b1.bname,b1.price,b1.quantity);
             color("aqua");
             printf("\n%d] BOOK_ID:",i);
	         color("lightgreen");
	         printf("%d",b1.bookid);
	         color("aqua");
	         printf("\n BOOK_NAME :");
	         color("lightgreen");
	         printf("%s",b1.bname);
	         color("aqua");
	         printf("\n BOOK_PRICE:Rs");
	         color("lightgreen");
	         printf("%0.2f",b1.price);
	         color("aqua");
	         printf("\n QUANTITY  :");
	         color("lightgreen");
	        printf("%d",b1.quantity);
            printf("\n");
			i++;
	  		flag =1;
	  		return 1;
	  	}
	}	
	}
	else if(n==2){
	//by using name of book
	char bname[20];
	printf("Enter a book name :");
	gets(bname);
	int i=0;
	while(fread(&b1,sizeof(b1),1,fp)>0&&flag ==0){
		   int str = strcmp(b1.bname,bname);
		   if(str==0){
		    line1();
	  		//printf("  \n   BOOK_ID :%d\n BOOK_NAME :%s \n BOOK_PRICE:Rs%0.2f\n QUANTITY  :%d",b1.bookid,b1.bname,b1.price,b1.quantity);
			 color("aqua");
             printf("\n%d] BOOK_ID:",i);
	         color("lightgreen");
	         printf("%d",b1.bookid);
	         color("aqua");
	         printf("\n BOOK_NAME :");
	         color("lightgreen");
	         printf("%s",b1.bname);
	         color("aqua");
	         printf("\n BOOK_PRICE:Rs");
	         color("lightgreen");
	         printf("%0.2f",b1.price);
	         color("aqua");
	         printf("\n QUANTITY  :");
	         color("lightgreen");
	         printf("%d",b1.quantity);
             printf("\n");
			 i++;
	  		 flag =1;
	  		return 0;
	  	}
	}	
	}
	if(flag!=1){
		printf("No book is available");
		return 0;
	}
	fclose(fp);
}
//purchase a book	
void purchase(){
	char ch;
	struct user u1;
	int flag=0;
	color("lightyellow");
	printf("________________[BUY A BOOK]_________________\n");
	color("white");
	if(findbook()){
		fflush(stdin);
		color("purple");
		printf("\nBook is ready for cart\n");
		color("aqua");
		printf("Wants to purchase[y/n] :");
		    color("lightgreen");
			scanf("%c",&ch);
			if(ch=='y'||ch=='Y'){
				color("aqua");
				printf("\nDo you have account[y/n] :");
				fflush(stdin);
				color("lightgreen");
				scanf("%c", &ch);
				 if(ch=='y'||ch=='Y'){
			    	login();                       //login user
			    	flag =1;
				 }
				 else{
					color("purple");
				   printf("Create a account\n");
				   color("white");
				   signup();                      //signup user
				   flag=1;
		     	}
		     	if(flag==1){
					color("purple");
		     		printf("\nBook will be deliver within a hr.");
		     		printf("\nThanks you :");
					color("lightgreen");
					printf(" %s..", u1.uname);
					color("white");
					flag=0;
		     		
			}
			
			}
			else if(ch=='n'||ch=='N' ||flag==1){
				printf("\nThank you dear %s", u1.uname);
			}
		
			
	}
	else {
		printf("\nBook is not availabe");
	}
}
struct bill
{
	char bill_uname[20];
	char bill_bname[20];
	int bill_quantity;
	float bill_price;
};
int strcom(char str[],char str1[])
{
	int i,c=0;
	for(i=0; str[i],str1[i];i++){
		if(str[i]==str1[i]){
			c++;
		}
	}
	if(c==i){
	return 0;
	}
	return 1;
}
//generats bill
void gbill()
{
	FILE *fp;
	FILE *fpu; 
	FILE *fpb;
	struct bill bl1;
	struct user u1;
	struct book b1;
	int bookid,quantity,flag=0,i,flag1,flag2;
	int chu;
	char uname[20];
	fp = fopen("bills_data.dat","ab");      // add bills in bills_data.dat file
	fpu=fopen("user1.txt","rb");            //open user1.txt data file
	fflush(stdin);
	color("lightyellow");
	printf("\n________________[ GENERATE BILL ]_________________\n");
	color("white");
	color("aqua");
	printf("Enter a user name :");
	//gets(uname);
	color("lightgreen");
	scanf("%s", uname);
	//check the user name
	while(fread(&u1,sizeof(u1),1,fpu)>0){
		//char chu = strcmp(u1.uname,uname);
		chu = strcmp(u1.uname,uname);
		if(chu==0){
	       strcpy(bl1.bill_uname,uname);
		 flag1=1;
		 break;
		}
		else{
			color("purple");
		 printf("\nNo user Create a account .\n");
		 color("white");
		 //signup();
		 break;
		}
	}
	
	fclose(fpu);   //file pointer of user
	fflush(stdin);
	fpb=fopen("books_collecton.dat","rb");  //open books_collection.dat 
	//fpb=fopen("bills_data.dat","rb");
	//check the book is present
	if(flag1==1){
	color("aqua");
	printf("Enter a bookid :");
	color("lightgreen");
	scanf("%d", &bookid);
	fflush(stdin);
	color("aqua");
	printf("Enter a quantiy of books :");
	color("lightgreen");
	scanf("%d", &quantity);
	fflush(stdin);
	while(fread(&b1,sizeof(b1),1,fpb)>0){
		if(bookid==b1.bookid){
			line1();
	  		printf("  \n   BOOK_ID :%d\n BOOK_NAME :%s \n BOOK_PRICE:Rs%0.2f\n QUANTITY  :%d",b1.bookid,b1.bname,b1.price,b1.quantity);
	  	//	bl1.bill_bname = b1.name;
	  		bl1.bill_quantity= quantity;
		 	bl1.bill_price= quantity*b1.price;
	  		flag =1;
		}
	}
	 
		 if(flag==1){
		 fwrite(&bl1,sizeof(bl1),1,fp);
		 color("purple");
		 printf("\nCongratulation Bill succesfully generated");
		 color("white");
		 }
		 fclose(fpb);
		 fclose(fp);
   
 }
}
//display all bills
void showbill()
{
	FILE *fp;
	struct bill bl1;
	fp = fopen("bills_data.dat", "r");
	if(fp==NULL){
		printf("File is not opened");
		exit(1);
	}
	while(fread(&bl1,sizeof(bl1),1,fp)>0){
		printf("\nName of user :%s\n Quantity :%d\n Total prise %0.2f ",bl1.bill_uname,bl1.bill_quantity,bl1.bill_price);
	}
	fclose(fp);
}
//information about store
void storeinfo()
{
	struct book b1;
	FILE *fp;
	int tquan=0,tbook=1;
	float tprice=0;
	fp = fopen("books_collection.dat","rb");
	while(fread(&b1,sizeof(b1),1,fp)>0){
		tquan += b1.quantity;
		tbook++;
		tprice += b1.price;
	}
	color("lightyellow");
	printf("\n________________[ STORE STATISTICS ]_________________\n");
	color("white");
	color("aqua");
	printf("\nTotal quantity :");
	color("lightgreen");
	printf("%d",tquan);
	color("aqua");
	printf("\nTotal no.of books :");
	color("lightgreen");
	printf("%d",tbook);
	color("aqua");
	printf("\nTotal price of books : Rs.");
	color("lightgreen");
	printf("%0.2f",tprice);
	color("white");
	fclose(fp);
   
}
//USERS RELATED
//signup for uers
void signup()
{
	FILE *fp;
	struct user u1;
	int i;
	char ch;
	fflush(stdin);
	color("lightyellow");
	printf("_________________[SIGNUP HEAR]________________\n");
	color("white");
	fp = fopen("user1.txt","ab");
	color("aqua");
	printf("Enter a user name :");
	color("lightgreen");
	gets(u1.uname);
	color("aqua");
	printf("\nEnter a user passowd(10) :");
	fflush(stdin);
	color("lightgreen");
 	scanf("%s", u1.upass);
 /*	for(i=0; i<10; i++){
 		u1.upass[i]=getch();
 		printf("*");
 	}*/
 	printf("\n");
	fwrite(&u1,sizeof(u1),1,fp);
	fclose(fp);
	color("purple");
	printf("Account is succesfully created\n");
	line1();
	color("white");
	
}
//login for user
void login()
{
	FILE *fp;
	struct user u1;
	char uname[20];
	 char  upass[20];
	int chu,chp;
	int i,otp,flag1=0,flag2=0;
	fflush(stdin);
	color("lightyellow");
	printf("_________________[LOGIN HEAR]_________________\n");
	color("white");
	fp =fopen("user1.txt","rb");
	color("aqua");
	printf("Enter a user name :");
	color("lightgreen");
	scanf("%s", uname);
    fflush(stdin);
	color("aqua");
	printf("\nEnter a password :");
	color("lightgreen");
		scanf("%s",upass);
/*	for(i=0; i<11; i++){
		upass[i]=getch();
		printf("*");
	}*/
	line1();
	printf("\n");
	while(fread(&u1,sizeof(u1),1,fp)>0&&flag1==0&&flag2==0){
		chu = strcmp(uname,u1.uname);
		if(chu==0){
			flag1 =1;
		}
		chp = strcmp(upass,u1.upass);
		if(chp==0){
			flag2=1;
		}
	}
		if(flag1==1 && flag2==1){
			color("purple");
			printf("User is avaible\n");
			printf("Name of User :");
			color("lightgreen");
			printf("%s " , u1.uname);
			color("white");
			otp=1;
	    }
	  else if(flag1==1 &&flag2!=1){
		color("purple");
		printf("\n Enter a right password\n");
		}
	   else if(flag1!=1 && flag2==1){
		color("purple");
		printf("\n Enter a valide user name\n");
		}
	else{
		color("purple");
	   printf("\nNo user info .. create account\n");
	}
	color("white");
	printf("\n");
	line1();
	printf("\n");
	  fclose(fp);
	  if(otp==1){
	  	OTP();
	  }
	  
  } 
 // show all the users in the file
void showallusr()
{
	FILE *fp;
	struct user u1;
	int i=1;
	fp=fopen("user1.txt", "rb");	
	if(fp==NULL){
		color("purple");
		printf("No User present");
		exit(1);
	}
	printf("\n");
	color("aqua");
	printf("Name of users :\n");
	color("lightgreen");
	while(fread(&u1 ,sizeof(u1),1,fp)>0){
		printf(" %d. %s ",i, u1.uname);
		i++;
		printf("\n");
	}
	color("white");
	fclose(fp);
}
//all users information
void userinfo()
{
	FILE *fp;
	struct user u1;
	int i=0,tuser=0;
	fp = fopen("user1.txt","rb");
	while(fread(&u1,sizeof(u1),1,fp)>0){
		   tuser += i;
		   i++;
		   }
		printf("Total users %d", i);
		
		fclose(fp);
}
void delay1(int n)
{
	int ms = 100*n;
	clock_t st = clock();
	while(clock()<st+ms);
}
//generating OTP for varification
void OTP( )
{
	int n,otp,flag=0;
	char ch;
	srand(time(0));
	color("lightyellow");
	printf("_________________[ VARIFY YOURSELF ]_________________\n");
	color("white");
	while(flag!=1){
    color("purple");
	printf("Generating OTP....\n OTP is : ");
	n = rand()%10000+1;
	delay1(10);
	color("lightyellow");
	printf(" %d", n);
	color("aqua");
	printf("\nEnter your OTP :");
	color("lightgreen");
	scanf("%d", &otp);
	if(otp==n){
		color("purple");
		printf("Succefully login..");
		color("white");
		flag=1;
		break;
	}
	else
	 color("aqua");
	 printf("Enter a correct OTP\n");
	 fflush(stdin);
	 printf("Do you want to regenrate OTP[y/n] :");
	  color("lightgreen");
	 scanf("%c", &ch);
	if(ch=='y'||ch=='Y'){
	   	flag=0;
	   	//clrscr();
	   }
	   else{
	   color("purple");
	     printf("\nSorry..!!you can not login.");
	     flag=1;
	}
	}
	printf("\n");
	color("white");
	line1();

}
void showusr()
{ 
  color("lightyellow");
  printf("__________________[USER MODE]_________________\n");
  color("gray");
  printf(" 1 for all available books\n 2 for search book\n 3 purchase a book\n 4 login\n 5 signup(add)\n 6 Exit\n 7 Clear Screen\n 8 gbill\n 9 show bills\n 10 signup(maintainer)"); 
  color("white");
}
void showmain()
{
	color("lightyellow");
	printf("_______________[ADMINISTER MODE]______________\n");
	color("gray");
    printf(" 1 for add book\n 2 for all available books\n 3 Search book\n 4 all users\n 5 Store info\n 6 User info\n 7 signup(Ad)\n 8 Exit\n 9 Clear screen");
	color("white");	

}					
int main(int argc, char *argv[])
{
	int n,num,i,k,brk=0;
	char ch;
  while(1){
	line1();
	color("green");
	printf("\nEnter Who are you.. \n 1 user\n 2 Maintainer\n 3 Exit");
	color("blue");
	printf("\nEnter a choice :");
	scanf("%d", &k);
	switch(k){
		     //for user 
    case 1:
	 system("cls");
     showusr();   
       while(1){
		color("aqua");
		printf("\nEnter a CHOICES(User) : ");
		color("lightgreen");
	    scanf("%d", &n);
		color("white");
		//clrscr();
	    switch(n){
	  	case 1:
		color("aqua");
	  	 printf("Avilable books are : \n ");
		 color("purple");
		 printf("looding..\n");
		 color("white");
	  	 delay(10);
	  	 showall();
	  	break;
	  	case 2:
		 color("lightyellow");
	  	 printf("________________[SEARCH BOOKS]________________\n");
		 color("white");
	  	 findbook();	
	  	 break;
	  	case 3:
	  	 purchase();
	     break;
	     case 4:
	     login();
	      // printf("please confirm your identity\n");
	      // OTP( );
	       break;
	    case 5:
	     signup();
	    break;
	    case 6:
	     system("cls");
		 color("lightyellow");
         printf("_______________HAVE A NICE DAY________________\n"); 
		 color("white");
	     break;
	    case 7:
	     system("cls");
	     showusr();
	       break;
	    case 8:
	      gbill();
	       break;
	    case 9:
	    showbill();
	    break;
	    default:
		color("purple");
	    printf("Enter a valide CHOISES(User)");
	     break; 
		 case 10:
		 signup1();  //signup for adding maintainer
		 break;    	
	     }
	     if(n==6){
		    break;
	         }
		}
		break;
	//for maintainer
	 case 2:
	   system("cls");
	   if(login1()){
	    showmain();
	   }
	   else{
	   color("lightred");
	   printf("Access denied..");
	   color("white");
	    break;
	   } 
	    
	   while(1){
		color("aqua");
	    printf("\nEnter a CHOICES(Maintain) :");
		color("green");
        scanf("%d", &n);
		color("white");
                 switch(n){
			     case 1:
				 color("lightyellow");
                printf("_________________[ADD BOOKS]__________________\n");
				color("aqua");
                printf("\nEnter how many you want to add :\n");
				color("lightgreen");
                scanf("%d", &num);
				color("white");
                for(i=1; i<=num; i++){
                addbook();
                }
				break;
                case 2:
				color("aqua");
	  	        printf("Avilable books are : \n ");
		        color("purple");
		        printf("looding..\n");
		        color("white");
                delay(10);
                showall();
                break;
				case 3:  
				color("lightyellow");
				 printf("________________[SEARCH BOOKS]________________\n");
				 color("white");
                findbook();
                break;                                                        
               case 4:
			   color("aqua");                                                       
               printf("All users are :\n");
			   color("purple");
               printf("Looding..");
			   color("white");
               delay(10);
               //line();                                                       
               showallusr();
               break;
               case 5:
                storeinfo();
                break;
                case 6:
                userinfo();
                break;
                 case 7:
                  signup1();
                  break;
                  case 8:
                  system("cls");
				  color("lightyellow");
                  printf("______________HAVE A NICE DAY________________\n"); 
				  color("white");
                   break;
                  case 9:
                  system("cls");
                   showmain();
                   break;
                default:
				color("purple");
                printf("Enter a valide CHOISES(Maintain)");
				color("white");
                break;
                }                                                                                                          if(n==8)
                  break;
               }
	    break;
		case 3:
	            system("cls");
				color("lightyellow");
	            printf("\n_______________THANKS FOR HERE________________\n");
				color("white");
				brk=1;
	            break;
	     default:
		      color("purple");
	            printf("\nEnter a valide choise");
				color("white");
	            break;
	
	}
	if(brk==1)
	break;
   }
}