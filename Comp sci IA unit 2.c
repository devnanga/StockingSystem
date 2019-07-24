#include<stdio.h>
typedef struct
{
	char name[40];
	int quantity;
	float cost;
}Item;
void database(Item I)//functions for populating the database
{
    int x,num;
	printf("You must first populate the database");//used to ask user to populate his database
    printf("Enter number of items in database");// used to find out how many products are present
    scanf("%d",num);
    for(x=1;x<=num;x++)//loop to enter all items, costs and quantities
	{   printf("Enter name of item");
		scanf("%c",I[x].name);
		printf("Enter quantity");
		scanf("%d",&I[x].quantity);
		printf("Enter cost");
		scanf("%f",&I[x].cost);
		x=x+1;
	}
	void stock_menu(Item,int);
	stock_menu(I,num);
}
void stock_menu(Item I,int num)//function which allows user to select what he wishes to do
{
	int choice;
	printf("1.Remove item\n 2.Check stock item\n 3.Manipulate Database\n 4.Enter item\n 5.Exit");//menu for what options the user has
	printf("Enter your choice: 1,2,3,4 or 5");
	scanf("%d",&choice);// depending on his choice, the user will be sent to a different function
	if (choice==1)
	{
		void remove_item(Item);
		remove_item(I);
	}
	if (choice==2)
	{
		void check_item(Item,int);
		check_item(I,num);
	}
	if (choice==3)
	{
		void manipulate_stock(Item,int);
		manipulate_stock(I,num);
	}
	if(choice==4)
	{
		void enter_item(Item,int);
		enter_item(I,num);
	}
}
void remove_item(Item I)//function which allows user to delete an item from stock
{
	int x;
	char name[30];
	printf("Enter name of item that you wish to remove");
	scanf("%c",name);
	for(x=1;x<=100;x++)//loop used to locate and delete the item along with its quantity and cost
	{
		if(name==I[x].name)
		{
			I[x].name=='-';
			I[x].quantity==-1;
			I[x].cost==-1;
		}
	}
	void stock_menu(Item);// allows the user to return to the original menu
	stock_menu(I);
}
void enter_item(Item I,int num)//function which allows the user to add an item to the database
{
	int x;
	char name[30];
	int quantity;
	float cost;
	x=num+1;//location used to find the last position in the database, and add 1 location
	printf("Enter name of item that you wish to enter");//accepts name of the new product
	scanf("%c",name);//stores the new item in the created location 'x'
	I[x].name=name;
	printf("Enter quantity of good");
	scanf("%d",&I[x].quantity);
	I[x].quantity=quantity;
	printf("Enter cost");
	scanf("%f",&cost);
	I[x].cost=cost;
	void stock_menu(Item);//returns to the original menu
	stock_menu(I);
}
void manipulate_stock(Item I)//function which allows the user to modify the cost or quantity of an item in stock
{
	char name[30];
	int choice;
	float cost;
	int quantity;
	printf("This menu allows you to modify the amount of stock or cost in inventory");
	printf("Enter name of item you wish to modify");//asks the user to enter name of item he wishes to modify
	scanf("%c",name);
	printf("What do you want to modify? 1.Cost 2.Quantity");//the user may chose what he wishes to modify
	printf("Enter choice");
	scanf("%d",&choice);
	if(choice==1)//used to modify the cost
	{
		for(x=0;x<=num;x++)//this loop locates the item to be modified
		{
			if (name==I[x].name)
			{
				printf("Cost of %c is %f",I[x].name,I[x].cost);
				printf("Enter new cost");
				scanf("%f",&cost);
				I[x].cost=cost;//used to save the new cost 
				printf("New cost of %c is %f",I[x].name,I[x].cost);
			}
		}
	}
	if(choice==2)//used to modify the quantity
	{
		for(x=0;x<=num;x++)//this loop locates the item to be modified
		{
			if (name==I[x].name)
			{
				printf("Quantity of %c is %d",I[x].name,I[x].quantity);
				printf("Enter new quantity");
				scanf("%d",&quantity);
				I[x].quantity=quantity;//used to save the new quantity
				printf("New cost of %c is %d",I[x].name,I[x].quantity);
			}
		}
	}
	void stock_menu(Item);//returns to original menu
	stock_menu(I);
}
void check_item(Item I,int num)//function which allows the user to check the current stock
{
	int x;
	char name[30];
	printf("Enter item to search for");//asks the user which item he wants to search for 
	scanf("%c",name);
	for(x=1;x<=num;x++)//loop used to find the item and display all the information
	{
		if(name==I[x].name)
		{
			printf("Product is %c\n",I[x].name);
			printf("Cost is %f",I[x].cost);
			printf("Number in stock",I[x].quantity);
		}
	}
	void stock_menu(Item);//returns to the original menu
	stock_menu(I);
}
main()
{
	Item I[1000];//this declares the structure, with 1000 locations in case there are any additions to be made
	void database(Item);//the function to populate the database is called here and this information will be passed and modified throughout the program
	database(I);
}




















