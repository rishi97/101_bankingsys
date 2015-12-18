#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


//void manlogin();
//void clrklogin();
//int custlogin();
void login(int m);
void manmenu(int m);
void clrkmenu(int m);
//void custmenu();
//FILE createfile();
void addacc(int m);
void delacc();
void amendacc();
void custinfo();
void balance();
void withdraw();
void deposit();
void standord();
void write();
int openfile();

struct custacc
{

	char fname[20];
	char gname[20];
	long int account;
	long int pin;
	long int phone_number;
	char email[50];
	char idtype[10];
	float balance;
	bool blocked;
	struct custacc *next;
};
struct custacc *accounts;
char filename[20];
long int staff[2][2] = { {19900001, 123456},
					{19900002, 987654}	};

int main()
{

	int z;
	puts("Welcome to the Bank Info System.");
	z = openfile();
	login(z);
	/*while(1)
	{
		puts("What user type do want to login as?");
		puts("1. Manager.");
		puts("2. Clerk.");
		puts("3. Customer.");
		puts("4. Quit");
		printf("You are: ");
		fflush(stdin);
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
			{
				manlogin();
				break;
			}
			case 2:
			{
				clrklogin();
				break;
			}
			case 3:
			{
				custmenu();
				break;
			}
			case 4: exit(0);
			default:
			{
				puts("Invalid input, try again.");
				continue;
			}
		}
		puts("Thank You for choosing us. Goodbye!");
		break;
	}*/
}

/*

void manlogin()
{
	long int id, pass;
	char input = 'y';
	puts("Please enter manager's login info.");
	while(1)
	{
		printf("ID: ");
		scanf("%li",&id);
		printf("Password: ");
		scanf("%li",&pass);
		if(staff[0][0]==id&&staff[0][1]==pass)
		{
			puts("Login successful.");
			manmenu();
			break;
		}
		else
		{
			puts("Incorrect info, try again.");
			continue;
		}
	}
	while(input == 'y')
	{
		printf("Would you like to change your password? (y/n): ");
		fflush(stdin);
		scanf("%c",&input);
		if (input == 'n')
		{
			break;
		}
		if (input == 'y')
		{
			printf("Enter a new 6 digit PIN number: ");
			scanf("%li",staff[0][1]);
		}
		else
		{
			puts("Invalid input, try again.");
		}

	}
}

void clrklogin()
{
	long int id, pass;
	puts("Please enter clerk's login info.");
	while(1)
	{
		printf("ID: ");
		scanf("%li",&id);
		printf("Password: ");
		scanf("%li",&pass);
		if(staff[1][0]==id&&staff[1][1]==pass)
		{
			puts("Login succesful.");
			clrkmenu();
			break;
		}
		else
		{
			puts("Incorrect info, try again.");
			continue;
		}
	}
}*/
/*
int custlogin()
{
	int pin;
	long int accid;
	puts("Please enter customer's login info.");
	while(1)
	{
		struct custacc *index;
		index = accounts->next;
		printf("Account number: ");
		scanf("%ld",&accid);
		printf("PIN: ");
		scanf("%d",&pin);
		while (index != NULL) 				//traversing the linked list
		{
			if((index->account == accid) && (index->pin == pin))
			{
				puts("Login succesful.");
				custmenu(index);
				break;
			}
			else
			{
				index=index->next;
				puts("Incorrect info, try again.");
				continue;
			}
	}
}*/

void login(int m)
{
	long int PIN, id;
	bool y=1;
	int opt;
	struct custacc *temp;
	//char input = 'y';
	while(1)
	{
		printf("Enter Manager ID / Clerk ID / Customer account number: ");
		fflush(stdin);
		scanf("%li",&id);
		if(staff[0][0]==id)
		{
			while(1)
			{
				printf("Manager, enter your account PIN: ");
				fflush(stdin);
				scanf("%li",&PIN);
				if(staff[0][1]==PIN)
				{
					puts("Login successful. Welcome manager!");
					manmenu(m);
					break;
				}
				else
				{
					puts("Wrong PIN, try again!");
					continue;
				}
			}
			break;
		}
		else if(staff[1][0]==id)
		{
			while(1)
			{
				printf("Clerk, enter your account PIN: ");
				fflush(stdin);
				scanf("%li",&PIN);
				if(staff[1][1]==PIN)
				{
					puts("Login successful. Welcome clerk!");
					clrkmenu(m);
					break;
				}
				else
				{
					puts("Wrong PIN, try again!");
					continue;
				}
			}
			break;
		}
		else if((id != staff[0][0])&&(id != staff[1][0]))
		{
			while(y != 1)
			{
				//printf("Enter your account number: ");
				//fflush(stdin);
				//scanf("%li",&accid);
				temp = accounts->next;
				while(temp != NULL)
				{
					if((temp->account == id)&&(temp->blocked == false))
					{
						puts("Success!");
						while(1)
						{
							puts("Please select an action.");
							puts("1. View Balance");
							puts("2. Make a withdrawwal");
							puts("3. View Earlier Banking Activity");
							puts("4. View your account information");
							puts("4. Quit");
							scanf("%d",&opt);
							switch(opt)
							{
								case 1:
								{
									balance();
									break;
								}
								case 2:
								{
									withdraw();
									break;
								}
								case 3:
								{
									//banklog();
									break;
								}
								case 4:
								{
									printf("Family Name: %s\n",temp->fname);
									printf("Given Name: %s\n",temp->gname);
									printf("Account Number: %li\n",temp->account);
									printf("Phone Number: %li\n",temp->phone_number);
									printf("Email: %s\n",temp->email);
									printf("ID type: %s\n",temp->idtype);
									break;
								}
								case 5: break;;
								default:
								{
									puts("Invalid input, try again.");
									continue;
								}
							}
							break;
						}
						y = 1;
						break;
					}
					else
					{
						puts("Account not found or Account is blocked. Try again!");
						temp = temp->next;
						y = 0;
					}
				}
			}
			break;
		}
		else
		{
			puts("Incorrect account number, try again!");
			continue;
		}

	}

}

void manmenu(int m)
{
	int opt;
	while(1)
	{
		puts("Please select an action.");
		puts("1. Access customer account info.");
		puts("2. Set a customer account as blocked.");
		puts("3. View banking stats.");
		puts("4. Quit");
		fflush(stdin);
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
			{
				custinfo();
				break;
			}
			case 2:
			{
				//block();
				break;
			}
			case 3:
			{
				//stats();
				break;
			}
			case 4:
			{
				exit(0);
			}
			default:
			{
				puts("Invalid input, try again.");
				continue;
			}
		}
	}
}

void clrkmenu(int m)
{
	int opt;
	while(1)
	{
		puts("Please select an action.");
		puts("1. Add customer accounts.");
		puts("2. Delete customer accounts.");
		puts("3. Amend customer accounts.");
		puts("4. Deposit into customer accounts.");
		puts("5. Set a stading order.");
		puts("6. Quit");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
			{
				addacc(m);
				break;
			}
			case 2:
			{
				delacc();
				break;
			}
			case 3:
			{
				amendacc();
				break;
			}
			case 4:
			{
				deposit();
				break;
			}
			case 5:
			{
				//standord();
				break;
			}
			case 6:
			{
				exit(0);
			}
			default:
			{
				puts("Invalid input, try again.");
				continue;
			}
		}
	}
}

void addacc(int m)
{
	//int a, n;
	struct custacc *index;
	struct custacc *temp;
	index = accounts;
	while (m == 2 && index->next != NULL) /*traversing the linked list*/
	{
		index = index->next;
	}
	bool y;
	char input='y';
	while(input=='y')
	{
		temp = (struct custacc *)malloc(sizeof(struct custacc));
		printf("Please enter customer family name: ");
		fflush(stdin);
		scanf("%s",temp->fname);
		printf("Please enter customer given name: ");
		fflush(stdin);
		scanf("%s", temp->gname);
		printf("Please enter customer account pin: ");
		fflush(stdin);
		scanf("%li", &temp->pin);
		printf("Please enter customer email address: ");
		fflush(stdin);
		scanf("%s", temp->email);
		printf("Please enter customer phone number:");
		fflush(stdin);
		scanf("%li", &temp->phone_number);
		printf("Please enter customer ID type presented: ");
		fflush(stdin);
		scanf("%s", temp->idtype);
		printf("Please enter customer account balance:");
		fflush(stdin);
		scanf("%f", &temp->balance);
		(temp->blocked)=false;
		(temp->account)=((index->account)+(long int)1);
		printf("New customer account number is : %li",temp->account);
		temp->next = NULL;
		index->next = temp;
		index = temp;
		temp = NULL;
		while (1) /*write records to file after all custaccs have been input*/
		{
			printf("\nWould you like to add another customer account? (y/n) ");
			fflush(stdin);
			scanf("%c", &input);
			if (input == 'n')
			{
				write();
				break;
			}
			if (input == 'y')
			{
				break;
			}
			else
			{
				puts("Invalid input, try again.");
			}
		}
	}
}


void delacc()
{
	long int accid;
	char input='y';
	bool a=false;
	struct custacc *index;
	struct custacc *prevind;
	while(input=='y')
	{
		index = accounts;
		prevind = index;
		puts("Please enter the customer account number you want to delete: ");
		scanf("%li",&accid);
		while ((index->account!=accid)) /*traversing the linked list*/
		{
			index = index->next;
			if(a)
			{
				prevind = prevind->next;
			}
			a=true;
		}
		if(index==accounts)
		{
			accounts=index->next;
		}
		prevind->next=index->next;
		while (1) /*write records to file after all custaccs have been input*/
		{
			printf("\nWould you like to delete more customer accounts? (y/n) ");
			fflush(stdin);
			scanf("%c", &input);
			if (input == 'n')
			{
				write();
				break;
			}
			if (input == 'y')
			{
				break;
			}
			else
			{
				puts("Invalid input, try again.");
			}
		}
	}
}

void amendacc()
{
	long int accid;
	char input='y';
	struct custacc *index;
	index = accounts->next;
	while(input=='y')
	{
		puts("Please enter the customer account number you want to amend: ");
		scanf("%li",&accid);
		while(index != NULL)
		{
			if(index->account == accid)
			{
				break;
			}
			else
			{
				puts("Invalid PIN, try again");
				index = index->next;
			}
		}

		printf("Please enter the family name: ");
		fflush(stdin);
		scanf("%s",index->fname);
		printf("Please enter the given name: ");
		fflush(stdin);
		scanf("%s", index->gname);
		printf("Please enter the pin: ");
		fflush(stdin);
		scanf("%li", &index->pin);
		printf("Please enter the email address: ");
		fflush(stdin);
		scanf("%s", index->email);
		printf("Please enter the phone number:");
		fflush(stdin);
		scanf("%li", &index->phone_number);
		printf("Please enter the ID type: ");
		fflush(stdin);
		scanf("%s", index->idtype);

		while (1) /*write records to file after all custaccs have been input*/
		{
			printf("\nWould you like to amend more accounts? (y/n) ");
			fflush(stdin);
			scanf("%c", &input);
			if (input == 'n')
			{
				write();
				break;
			}
			if (input == 'y')
			{
				break;
			}
			else
			{
				puts("Invalid input, try again.");
			}
		}
	}
}

void balance()
{
	bool y;
	long int PIN;
	struct custacc *index;
	while(y != 1)
	{
		printf("Enter your PIN: ");
		fflush(stdin);
		scanf("%li",&PIN);
		index = accounts->next;
		while(index != NULL)
		{
			if(index->pin == PIN)
			{
				printf("Your current balance is $%f",index->balance);
				y = 1;
				break;
			}
			else
			{
				puts("Invalid PIN, try again");
				index = index->next;
				y = 0;
			}
		}
	}
}

void withdraw()
{
	bool y;
	long int PIN;
	int wdamt;
	float newamt;
	struct custacc *index;
	while(y != 1)
	{
		printf("Enter your PIN: ");
		fflush(stdin);
		scanf("%li",&PIN);
		index = accounts->next;
		while(index != NULL)
		{
			if(index->pin == PIN)
			{
				while(1)
				{
					printf("The maximum withdraw amount is $2000.\nEnter amount to withdraw: $");
					fflush(stdin);
					scanf("%d",&wdamt);
					if(wdamt<=2000)
					{
						newamt = (index->balance) - (float)wdamt;
						puts("Withdrawal Sucsessful!");
						index->balance = newamt;
						write();
						break;
					}
					else
					{
						puts("Enter amount less than $2000.");
						continue;
					}

				}
				y = 1;
				break;
			}
			else
			{
				puts("Invalid PIN, try again");
				index = index->next;
				y = 0;
			}
		}
	}
}

void custinfo()
{
	bool y=1;
	long int accid;
	struct custacc *temp;
	while(y != 1)
	{
		printf("Enter customer account number: ");
		fflush(stdin);
		scanf("%li",&accid);
		temp = accounts->next;
		while(temp != NULL)
		{
			if(temp->account == accid)
			{
				printf("Family Name: %s\n",temp->fname);
				printf("Given Name: %s\n",temp->gname);
				printf("Account Number: %li\n",temp->account);
				printf("Phone Number: %li\n",temp->phone_number);
				printf("Email: %s\n",temp->email);
				printf("ID type: %s\n",temp->idtype);
				printf("Account Balance: %f\n",temp->balance);
				y = 1;
				break;
			}
			else
			{
				puts("Account not found, try again!");
				temp = temp->next;
				y = 0;
			}
		}
	}
}

void deposit()
{
	bool y;
	long int accnum, PIN;
	int dpamt;
	float newamt;
	struct custacc *index;
	while(y != 1)
	{
		printf("Enter customer account number: ");
		fflush(stdin);
		scanf("%li",&accnum);
		printf("Enter your PIN: ");
		fflush(stdin);
		scanf("%li",&PIN);
		index = accounts->next;
		while(index != NULL)
		{
			if((index->account == accnum)&&(index->pin == PIN))
			{
				while(1)
				{
					printf("Enter amount to deposit: $");
					fflush(stdin);
					scanf("%d",&dpamt);
					if(dpamt>0)
					{
						newamt = (index->balance) + (float)dpamt;
						puts("Deposit Registered!");
						index->balance = newamt;
						write();
						break;
					}
					else
					{
						puts("Invalid input");
						continue;
					}

				}
				y = 1;
				break;
			}
			else
			{
				index = index->next;
				y = 0;
			}
		}
	}
}


int openfile()
{
	int emp_fl, n = 0;
	FILE *fptr;
	struct custacc *temp;
	struct custacc *index;

	printf("Please enter file name: ");
	fflush(stdin);
	scanf("%s",filename);
	fptr = fopen(filename,"rb");
	if(fptr==0)
	{
		puts("The file does not exist.");
		puts("Creating file by inputed name........");
		fopen(filename,"w+b");
		accounts = (struct custacc *)malloc(sizeof(struct custacc));
		puts("File created!");
		fclose(fptr);
		return 1;
	}
	else
	{
		puts("File open sucessful!");
		index = NULL;
		accounts = (struct custacc *)malloc(sizeof(struct custacc));
		accounts->next = NULL;
		temp = (struct custacc *)malloc(sizeof(struct custacc));
		accounts = temp;
		rewind(fptr);
		while(fread(temp, sizeof(struct custacc), 1, fptr)!= 0)
		{
			emp_fl = 0;
			index = temp;
			temp = (struct custacc *)malloc(sizeof(struct custacc));
			index->next = temp;
		}
		if (emp_fl == 0)
		{
			index->next = NULL;
			index = NULL;
			free(temp);
			temp = NULL;
			temp = accounts->next;
			while(temp != NULL)
			{
				n++;
				temp = temp->next;
			}
		}
		fclose(fptr);
		free(index);
		return n;
	}
}

void write()
{
	FILE *fp; /*declaring file pointer*/
	struct custacc *temp; /*pointer to a structure*/
	struct custacc *t2; /*pointer to a structure*/
	temp = accounts;
	if ((fp = fopen(filename, "w+b")) != NULL) /*write input records to file*/
	{
		while (temp != NULL)
		{
			fwrite(temp, sizeof(struct custacc), 1, fp);
			temp = temp->next;
		}
		t2 = accounts->next;
		/*while (t2 != NULL)
		{
			printf("ID: %d\nSurname: %s\nGiven name: %s\n Email: %s\nGrades: %.2f %.2f %.2f %.2f %.2f %.2f\nAverage: %.2f\n\n", t2->id, t2->sname, t2->gname, t2->email, t2->grade1, t2->grade2, t2->grade3, t2->grade4, t2->grade5, t2->grade6, t2->avg);
			t2 = t2->next;
		*/
		fclose(fp);
	}
}
/*
FILE createfile()
{
	FILE *fptr;
	fptr = fopen(filename, "rb");
	fopen(filename,"w+b");
	accounts = (struct custacc *)malloc(sizeof(struct custacc));
	puts("File created!");
	fclose(fptr);
} */
