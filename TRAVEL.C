#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>

#define spacing printf("\t\t\t")
#define vspacing printf("\n\n\n\n\n\n\n\n\n\n\n\n\n")

void layout1();
void layout2();

void initial();
void loading();

void menu_staff();
void menu_assign();

void add_new_staff_det();
void view_staff_det();
void modify_staff_det();
void delete_staff_det();

void assign_staff();
void view_assigned_staff();

void view_passenger_detail();
void avail_book();
void cancel();
void booking();

void avail();

void ticket_detail();
void add_ticket_detail();

void changepw();

void compare();
int compare_date(char *filename1);

void filenaming_staff(char* filename);
void filenaming_passenger(char* filename);
void final_filename(char *);

struct passenger{
	int seat;
	char name1[20],name2[20],dtn[40],side[2];
};

struct mandatory{
	int age,id;
	char fname[20],lname[20],bloodgroup[4],address[40],phno[15],profession[10];
};

struct ticket{
	char location[20];
	int price;
};

int i,j,x=639,y=400;
char choice;
char fn[15],vno[20],filename[30],aim[4],fn_final[9],compare_filename[20];;

void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	system("cd /");
	system("mkdir TRAVEL");
	system("cd TRAVEL");
	system("mkdir Vehicle");
	system("mkdir Mand");

	clrscr();

	initial();

	compare();

	loop:
	clrscr();

	layout1();
	setcolor(WHITE);
	circle(x/2-30,380,5);
	circle(x/2,380,5);
	circle(x/2+30,380,5);

	setfillstyle(1,GREEN);
	floodfill(x/2-30,380,WHITE);
	floodfill(x/2,380,WHITE);
	floodfill(x/2+30,380,WHITE);

	setcolor(YELLOW);
	settextstyle(0,HORIZ_DIR,1);

	outtextxy(x/2-250,190,"Staff details            [1]");
	outtextxy(x/2-250,220,"Assigning staff          [2]");

	outtextxy(x/2-250,250,"View Passenger Record    [3]");
	outtextxy(x/2-250,280,"Book ticket              [4]");
	outtextxy(x/2-250,310,"Cancel Ticket            [5]");

	outtextxy(x/2+50,190,"Seat avaibility           [6]");
	outtextxy(x/2+50,220,"Ticket detail             [7]");
	outtextxy(x/2+50,250,"Add ticket detail         [8]");
	outtextxy(x/2+50,280,"Change password           [9]");
	outtextxy(x/2+50,310,"Quit                      [q]");

	setcolor(WHITE);

	//midline
	line(x/2,190,x/2,320);

	setcolor(WHITE);
	outtextxy(x/2-90,335,"What do you want to do?");

	choice=getche();

	if(isdigit(choice))
	{
		switch(choice)
		{
			case '1':
				menu_staff();
				break;
			case '2':
				menu_assign();
				break;
			case '3':
				view_passenger_detail();
				break;
			case '4':
				booking();
				break;
			case '5':
				cancel();
				break;
			case '6':
				avail();
				break;
			case '7':
				ticket_detail();
				break;
			case '8':
				add_ticket_detail();
				break;
			case '9':
				changepw();
				break;
			default:
				gotoxy(34,23);
				printf("Invalid choice!\n");
				getch();
				goto loop;
		}
		goto loop;
	}
	if(!isdigit(choice))
	{
		if(choice=='q')
		{
			//loading();
			exit(0);
		}
		else
		{
			gotoxy(34,23);
				printf("Invalid choice!");
			getch();
		}
		goto loop;
	}
	getch();
	closegraph();
}

//showing or adding staff details
void menu_staff()
{
	loop:
	clrscr();

	layout1();

	setcolor(YELLOW);
	outtextxy(x/2-115,y/2+20, "Add new staff details    [1]");
	outtextxy(x/2-115,y/2+40, "View staff details       [2]");
	outtextxy(x/2-115,y/2+60, "Modify staff detail      [3]");
	outtextxy(x/2-115,y/2+80, "Delete staff detail      [4]");
	outtextxy(x/2-115,y/2+100,"Go back to main menu     [5]");

	setcolor(WHITE);
	outtextxy(x/2-115,y/2+130,"Enter your choice : ");
	choice=getche();

	if(isdigit(choice))
	{
		switch(choice)
		{
			case '1':
				add_new_staff_det();
				break;
			case '2':
				view_staff_det();
				break;
			case '3':
				modify_staff_det();
				break;
			case '4':
				delete_staff_det();
				break;
			case '5':
				getch();
				break;
			deafult:
				setcolor(RED);
				gotoxy(34,23);
				printf("Invalis choice!");
				getch();
				menu_staff();
		}
	}
	else
	{
		gotoxy(34,23);
		printf("Invalis choice!");
		getch();
		menu_staff();
	}
}

//adding new detail details
void add_new_staff_det()
{
	FILE *fp;

	struct mandatory det,compare;
	int count=0;

	clrscr();

	layout1();

	fp=fopen("staff.det","rb");

	if(fp==NULL)
	{
		fclose(fp);

		layout1();

		fp=fopen("staff.det","wb");

		gotoxy(26,12);
			printf("Enter staff detail\n");

		gotoxy(26,14);	printf("Id           : ");
			scanf("%d",&det.id);
			fflush(stdin);

		gotoxy(26,15);
			printf("Name         : ");
			scanf("%s %s",det.fname,det.lname);
			fflush(stdin);
			strupr(det.fname);
			strupr(det.lname);

		gotoxy(26,16);
			printf("Profession   : ");
			scanf("%s",det.profession);
			fflush(stdin);
			strupr(det.profession);

		gotoxy(26,17);
			printf("Age          : ");
			scanf("%d",&det.age);
			fflush(stdin);

		gotoxy(26,18);
			printf("Blood group  : ");
			scanf("%s",det.bloodgroup);
			fflush(stdin);
			strupr(det.bloodgroup);

		gotoxy(26,19);
			printf("Phone number : ");
			scanf("%s",det.phno);
			fflush(stdin);

		gotoxy(26,20);
			printf("Address      : ");
			scanf("%s",det.address);
			fflush(stdin);
			strupr(det.address);

		fwrite(&det,sizeof(det),1,fp);

		gotoxy(26,22);
			printf("Details added.\n");

		getch();

		fclose(fp);
	}
	else
	{
		fclose(fp);

		gotoxy(26,12);
			printf("Enter staff detail\n");

		gotoxy(26,14);	printf("Id           : ");
			scanf("%d",&det.id);
			fflush(stdin);

		gotoxy(26,15);
			printf("Name         : ");
			scanf("%s %s",det.fname,det.lname);
			fflush(stdin);
			strupr(det.fname);
			strupr(det.lname);

		gotoxy(26,16);
			printf("Profession   : ");
			scanf("%s",det.profession);
			fflush(stdin);
			strupr(det.profession);

		gotoxy(26,17);
			printf("Age          : ");
			scanf("%d",&det.age);
			fflush(stdin);

		gotoxy(26,18);
			printf("Blood group  : ");
			scanf("%s",det.bloodgroup);
			fflush(stdin);
			strupr(det.bloodgroup);

		gotoxy(26,19);
			printf("Phone number : ");
			scanf("%s",det.phno);
			fflush(stdin);

		gotoxy(26,20);
			printf("Address      : ");
			scanf("%s",det.address);
			fflush(stdin);
			strupr(det.address);

		//checking if the detail is already present in the record
		fp=fopen("staff.det","rb");
		while(fread(&compare,sizeof(compare),1,fp)!=0)
		{
			if(compare.id==det.id)
				count++;
		}
		fclose(fp);

		if(count==0)
		{
			fp=fopen("staff.det","ab");
				fwrite(&det,sizeof(det),1,fp);
			fclose(fp);

			gotoxy(26,22);
			printf("Details added.\n");
		}
		else
		{
			gotoxy(15,22);
			printf("Detail of same id is already present in the record.");
		}
	}

	gotoxy(26,24);
	printf("Add another detail [y|n] ? ");
	choice=getche();

	if(choice=='y' || choice=='Y')
		add_new_staff_det();
	else
	{
		gotoxy(26,25);
		printf("Thanks for adding details :)");
	}
	getch();
}

//Viewing staff details
void view_staff_det()
{
	FILE *fp;
	int count=0;
	struct mandatory det;

	fp=fopen("staff.det","rb");

	clrscr();
	setfillstyle(1,BLACK);
	floodfill(1,1,WHITE);

	setcolor(WHITE);
	rectangle(0,0,639,400);

	gotoxy(3,2);
	printf("ID    Name                  Age    Profession    Address    BG    Phone No  \n\n");
	rectangle(0,0,639,400);
	if(fp!=NULL)
	{
		i=0;

		while(fread(&det,sizeof(det),1,fp))
			count++;

		rewind(fp);

		while(fread(&det,sizeof(det),1,fp))
		{
			if(i!=0 && i%5==0)
			{
				getch();
				clrscr();
				setfillstyle(1,BLACK);
				floodfill(1,1,WHITE);
				printf("\n");
				printf("  ID    Name                  Age    Profession    Address    BG    Phone No  \n\n");
				rectangle(0,0,639,400);
			}
			printf("  %-5d %-10s %-10s %-6d %-13s %-10s %-5s %-10s\n",
				det.id,det.fname,det.lname,det.age,det.profession,det.address,det.bloodgroup,det.phno);
			i++;
			rectangle(0,0,639,400);
		}
		if(count==0)
			outtextxy(x/2-165,y/2,"Details of employees has not been added yet.");
	}
	else
	{
		gotoxy(26,13);
		printf("Details of employees has not been added yet.");
	}
	rectangle(0,0,639,400);
	fclose(fp);
	getch();
}

void modify_staff_det()
{
	FILE *fp,*fp_dup;

	int num,count=0;
	struct mandatory det;

	clrscr();
	layout1();

	fp=fopen("staff.det","rb");

	if(fp==NULL)
	{
		fclose(fp);
		outtextxy(x/2-165,y/2+100,"Details of employees has not been added yet to be modified.");
	}
	else
	{
		fclose(fp);
		fp=fopen("staff.det","rb");

		outtextxy(x/2-105,y/2+70,"Enter staff ID to modify : ");

		gotoxy(38,19);	scanf("%d",&num);
				fflush(stdin);

		while(fread(&det,sizeof(det),1,fp)!=0)
		{
			if(num==det.id)
				count++;
		}
		rewind(fp);
		if(count==0)
			outtextxy(x/2-165,y/2+145,"No details of employee found with this ID");
		else
		{
			fp_dup=fopen("staff_dup","wb");

			while(fread(&det,sizeof(det),1,fp)!=0)
				if(num!=det.id)
					fwrite(&det,sizeof(det),1,fp_dup);

			fclose(fp_dup);
			fclose(fp);
			remove("staff.det");
			rename("staff_dup","staff.det");

			clrscr();
			layout1();

			fp=fopen("staff.det","ab");

			gotoxy(26,14);
				printf("Enter the new details of ID : %d",num);

			gotoxy(26,16);
				printf("Name         : ");
				scanf("%s %s",det.fname,det.lname);
				fflush(stdin);
				strupr(det.fname);
				strupr(det.lname);

			gotoxy(26,17);
				printf("Profession   : ");
				scanf("%s",det.profession);
				fflush(stdin);
				strupr(det.profession);

			gotoxy(26,18);
				printf("Age          : ");
				scanf("%d",&det.age);
				fflush(stdin);

			gotoxy(26,19);
				printf("Blood group  : ");
				scanf("%s",det.bloodgroup);
				fflush(stdin);
				strupr(det.bloodgroup);

			gotoxy(26,20);
				printf("Phone number : ");
				scanf("%s",det.phno);
				fflush(stdin);

			gotoxy(26,21);
				printf("Address      : ");
				scanf("%s",det.address);
				fflush(stdin);
				strupr(det.address);

			det.id=num;

			fwrite(&det,sizeof(det),1,fp);
				gotoxy(26,23);
				printf("Detail modified");
			fclose(fp);
		}
	}
	getch();
}

void delete_staff_det()
{
	FILE *fp,*fp_dup;

	int rem,count=0;
	struct mandatory det;

	clrscr();
	layout1();

	fp=fopen("staff.det","rb");

	if(fp==NULL)
	{
		fclose(fp);
		outtextxy(x/2-165,y/2+100,"Details of employees has not been added yet.");
	}
	else
	{
		fclose(fp);
		fp=fopen("staff.det","rb");

		outtextxy(x/2-105,y/2+70,"Enter staff ID to delete : ");

		gotoxy(38,19);
			scanf("%d",&rem);
		fflush(stdin);

		while(fread(&det,sizeof(det),1,fp)!=0)
		{
			if(rem==det.id)
				count++;
		}
		rewind(fp);
		if(count==0)
			outtextxy(x/2-118,y/2+145,"No details found with this ID");
		else
		{
			fp_dup=fopen("staff_dup","wb");

			while(fread(&det,sizeof(det),1,fp)!=0)
			{
				if(rem!=det.id)
					fwrite(&det,sizeof(det),1,fp_dup);
			}

			fclose(fp_dup);
			fclose(fp);
			remove("staff.det");
			rename("staff_dup","staff.det");

			gotoxy(27,23);
			printf("Detail removed successfully");
			fclose(fp);
		}
	}
	getch();
}

//function for assigning staffs
void menu_assign()
{
	clrscr();

	setfillstyle(1,BLACK);
	floodfill(1,1,WHITE);
	setcolor(WHITE);
	rectangle(1,1,x,y);

	settextstyle(1,HORIZ_DIR,6);
	outtextxy(x/2-123,87,"Traveller's");

	settextstyle(0,HORIZ_DIR,1);
	outtextxy(x/2-123,144,"********              **********");

	outtextxy(x/2-50,144,"Safe Journey");

	setcolor(YELLOW);
	outtextxy(x/2-115,y/2+30,"Assign staffs              [1]");
	outtextxy(x/2-115,y/2+50,"View assigned staffs       [2]");
	outtextxy(x/2-115,y/2+70,"Goto main menu             [3]");

	setcolor(WHITE);
	outtextxy(x/2-115,y/2+100,"Enter your choice : ");
	choice=getche();

	if(isdigit(choice))
	{
		switch(choice)
		{
			case '1':
				assign_staff();
				break;
			case '2':
				view_assigned_staff();
				break;
			case '3':
				getch();
				break;
			default:
				gotoxy(34,23);
				printf("Invalid choice");
				getch();
				menu_assign();
		}
	}
	else
	{
		gotoxy(20,20);
		printf("Invalid choice");
		getch();
		menu_staff();
	}
}

//This function is for assigning the staff
void assign_staff()
{
	FILE *fp1,*fp2,*fp3;

	struct mandatory det;

	int c=0,count=0,flag,d_id,c_id,number=0;
	char fn[15],fn_vec[16],v_no[10];

	clrscr();

	filenaming_staff(fn);

	flag=compare_date(fn);

	final_filename(fn);

	for(i=0;i<strlen(fn_final)-3;i++)
		fn_vec[i]=fn_final[i];

	fn_vec[i]='V';                 	    	i++;
	fn_vec[i]=fn_final[6];                 	i++;
	fn_vec[i]=fn_final[7];                 	i++;
	fn_vec[i]='\0';

	if(flag==0)
	{
		layout1();
		outtextxy(x/2-175,y/2+30,"Sorry! you can not assign staff to this date.");
	}
	else
	{
		loop:
		fp1=fopen("staff.det","rb");
		if(fp1==NULL)
		{
			layout1();
			outtextxy(x/2-100,y/2+25,"Record not found.");
			fclose(fp1);
			getch();
		}
		else
		{
			fp2=fopen(fn,"rb");

			if(fp2!=NULL)
			{
				layout1();
				gotoxy(30,18);
				printf("Record already added.");
				fclose(fp1);
				fclose(fp2);
			}
			else
			{
				clrscr();
				setfillstyle(1,BLACK);
				floodfill(1,1,WHITE);
				rectangle(0,0,639,400);
				i=0;

				//Viewing staff details
				gotoxy(3,2);
					printf("Driver's detail :");
				gotoxy(3,3);
					printf("ID    Name                  Age    Profession    Address    BG    Phone No  \n\n");

				rectangle(0,0,639,400);

				while(fread(&det,sizeof(det),1,fp1)!=0)
					count++;

				rewind(fp1);

				while(fread(&det,sizeof(det),1,fp1))
				{
					if(i!=0 && i%10==0)
					{
						getch();
						clrscr();
						setfillstyle(1,BLACK);
						floodfill(1,1,WHITE);

						gotoxy(3,2);
							printf("Driver's detail :");
						gotoxy(3,3);
							printf("ID    Name                  Age    Profession    Address    BG    Phone No  \n\n");
					}
					i++;
					if(strcmp(det.profession,"DRIVER")==0)
					{
						printf("  %-5d %-10s %-10s %-6d %-13s %-10s %-5s %-10s\n",
							det.id,det.fname,det.lname,det.age,det.profession,det.address,det.bloodgroup,det.phno);
					}
					rectangle(0,0,639,400);
				}
				if(count!=0)
				{
					gotoxy(3,18);
					printf("Enter driver ID to assign : ");
					scanf("%d",&d_id);

					rewind(fp1);
					while(fread(&det,sizeof(det),1,fp1)!=0)
					{
						//if(d_id==det.id)
						if(d_id==det.id && strcmp(det.profession,"DRIVER")==0)
							c++;
					}
					if(c==0)
					{
						gotoxy(3,20);
						printf("Sorry! staff with ID : %d is not found.",d_id);
						getch();
						c=0;
						if(count!=0)
						{
							fclose(fp1);
							goto loop;
						}
					}
					else
						number++;
					fclose(fp1);
				}
				else
				{
					outtextxy(x/2-60,y/2,"File is empty.");
					getch();
				}

				loop1:
				clrscr();
				setfillstyle(1,BLACK);
				floodfill(1,1,WHITE);
				rectangle(0,0,639,400);

				gotoxy(3,3);
				printf("Conductor's detail :\n");

				rectangle(0,0,639,400);

				gotoxy(3,3);
				printf("ID    Name                  Age    Profession    Address    BG    Phone No  \n\n");

				fclose(fp1);
				fp1=fopen("staff.det","rb");
				i=0;
				while(fread(&det,sizeof(det),1,fp1))
				{
					if(i!=0 && i%10==0)
					{
						getch();
						clrscr();
						setfillstyle(1,BLACK);
						floodfill(1,1,WHITE);
						gotoxy(3,3);
							printf("ID    Name                  Age    Profession    Address    BG    Phone No  \n\n");
					}
					i++;
					if(strcmp(det.profession,"CONDUCTOR")==0)
					{
						printf("  %-5d %-10s %-10s %-6d %-13s %-10s %-5s %-10s\n",
							det.id,det.fname,det.lname,det.age,det.profession,det.address,det.bloodgroup,det.phno);
					}
				}
				if(count!=0)
				{
					rectangle(0,0,639,400);
					gotoxy(3,18);
					printf("Enter conductor ID to assign : ");
					scanf("%d",&c_id);

					rewind(fp1);
					c=0;
					while(fread(&det,sizeof(det),1,fp1)!=0)
					{
						if(c_id==det.id && strcmp(det.profession,"CONDUCTOR")==0)
							c++;
					}
					if(c==0)
					{
						gotoxy(3,20);
						printf("Sorry! staff with ID : %d is not found.",c_id);
						getch();

						goto loop1;
					}
					else
						number++;
					fclose(fp1);
				}
				else
					outtextxy(x/2-60,y/2,"File is empty.");

				fclose(fp1);

				if(number!=0)
				{
					//Vehicle number
					system("cd VEHICLE");

					fp3=fopen(fn_vec,"w");
						gotoxy(3,19);
						printf("Enter the vehicle number : ");
						scanf("%s",v_no);
						fflush(stdin);
						fprintf(fp3,"%s",v_no);
					fclose(fp3);
					system("cd ..");

					fp1=fopen("staff.det","rb");
					fp2=fopen(fn_final,"wb");

					while(fread(&det,sizeof(det),1,fp1)!=0)
					{
						if(det.id==d_id && d_id!=0)
							fwrite(&det,sizeof(det),1,fp2);

					}
					rewind(fp1);

					while(fread(&det,sizeof(det),1,fp1)!=0)
					{
						if(det.id==c_id && c_id!=0)
							fwrite(&det,sizeof(det),1,fp2);
					}

					gotoxy(3,20);	printf("Detail added :)");

					fclose(fp2);
					fclose(fp1);
				}
			}
		}
	}
	getch();
}

//This function shows the details of assigned staff
void view_assigned_staff()
{
	FILE *fp1,*fp2;

	struct mandatory det;

	char file[20], fn_vec[16],v_no[10];

	filenaming_staff(file);
	final_filename(file);

	for(i=0;i<strlen(fn_final)-3;i++)
		fn_vec[i]=fn_final[i];

	fn_vec[i]='V';                 		i++;
	fn_vec[i]=fn_final[6];                 	i++;
	fn_vec[i]=fn_final[7];                 	i++;
	fn_vec[i]='\0';

	clrscr();

	layout1();

	fp1=fopen(fn_final,"rb");

	if(fp1==NULL)
	{
		gotoxy(22,18);
		printf("No staff has been assigned to this date.");
	}
	else
	{
		system("cd VEHICLE");
		fp2=fopen(fn_vec,"r");
			fscanf(fp2,"%s",v_no);
			fflush(stdin);
		fclose(fp2);
		system("cd ..");

		i=0;
		while(fread(&det,sizeof(det),1,fp1)!=0)
		{
			i++;
			if(i==1)
			{
				gotoxy(6,15);	printf("ID             : %d",det.id);
				gotoxy(6,16);	printf("Name           : %s %s",det.fname,det.lname);
				gotoxy(6,17);	printf("Age            : %d",det.age);
				gotoxy(6,18);	printf("Profession     : %s",det.profession);
				gotoxy(6,19);	printf("Blood group    : %s",det.bloodgroup);
				gotoxy(6,20);	printf("Address        : %s",det.address);
				gotoxy(6,21);	printf("Phone number   : %s",det.phno);
			}
			else
			{
				gotoxy(46,15);	printf("ID             : %d",det.id);
				gotoxy(46,16);	printf("Name           : %s %s",det.fname,det.lname);
				gotoxy(46,17);	printf("Age            : %d",det.age);
				gotoxy(46,18);	printf("Profession     : %s",det.profession);
				gotoxy(46,19);	printf("Blood group    : %s",det.bloodgroup);
				gotoxy(46,20);	printf("Address        : %s",det.address);
				gotoxy(46,21);	printf("Phone number   : %s",det.phno);
			}
		}
		gotoxy(6,23);
		printf("Vechicle no    : %s",v_no);
	}
	fclose(fp1);
	rectangle(0,0,639,400);
	getch();
}

//This function shows the detail of passengers
//This function shows the detail of passengers
void view_passenger_detail()
{
	FILE *fp;
	int k,min;
	char string1[20],string2[20],string3[40];
	char fn1[20];

	struct passenger det;

	filenaming_passenger(fn1);
	
	final_filename(fn1);

	clrscr();

	setfillstyle(1,BLACK);
	floodfill(1,1,WHITE);
	rectangle(0,0,639,400);

	fp=fopen(fn_final,"rb");
	
	if(fp==NULL)
	{
		layout1();
		gotoxy(21,20);
		printf("No ticket has been booked for this date.");
	}
	else
	{
		gotoxy(22,2);
		printf("Seat  Side  Name                 Destination\n");

		i=0;

		while(fread(&det,sizeof(det),1,fp)!=0)
		{
			i++;
			spacing;
			printf("\b\b\b%-5d %-5s %-10s %-9s %-11s\n",det.seat, det.side, det.name1, det.name2,det.dtn);
			
			if(i%15==0)
			{
				getch();
				clrscr();
				layout1();
				gotoxy(22,2);
				printf("Seat  Side  Name                 Destination\n");
			}
		}

		fclose(fp);
	}
	fclose(fp);
	rectangle(0,0,639,400);
	getch();
}

//shows the avaibility of seats white booking the ticket in real-time
void avail_book(char *filename)
{
	FILE *fp;
	int i;
	struct passenger det;

	setfillstyle(1,BLACK);
	floodfill(2,2,BLACK);

	//border
	rectangle(0,0,639,400);

	//midline
	line(x/2,0,x/2,400);

	setlinestyle(0,0,1);

	//section A
	rectangle(x/2+70,60,x/2-150+280,330);

	//section B
	rectangle(x/2+190,30,x/2+250,330);

	//lines side A
	line(x/2+70,90 ,x/2+130,90);
	line(x/2+70,120,x/2+130,120);
	line(x/2+70,150,x/2+130,150);
	line(x/2+70,180,x/2+130,180);
	line(x/2+70,210,x/2+130,210);
	line(x/2+70,240,x/2+130,240);
	line(x/2+70,270,x/2+130,270);
	line(x/2+70,300,x/2+130,300);

	line(x/2+100,y/2-140,x/2+100,y/2+130);

	line(x/2+70,330,x/2-30+280,330);

	line(x/2+70,300,x/2-30+280,300);

	//lines side B
	line(x/2+190,60,x/2+250,60);
	line(x/2+190,90,x/2+250,90);
	line(x/2+190,120,x/2+250,120);
	line(x/2+190,150,x/2+250,150);
	line(x/2+190,180,x/2+250,180);
	line(x/2+190,210,x/2+250,210);
	line(x/2+190,240,x/2+250,240);
	line(x/2+190,270,x/2+250,270);
	line(x/2+190,300,x/2+250,300);

	line(x/2+220,y/2-170,x/2+220,y/2+130);

	//last seat
	line(x/2+160,y/2+100,x/2+160,y/2+130);

	//note
	rectangle(x/2+40,y/2+155,x/2+60,y/2+175);
	outtextxy(x/2+70,y/2+161,"Available");

	rectangle(x/2+168,y/2+155,x/2+188,y/2+175);
	outtextxy(x/2+198,y/2+161,"Reserved");

	//side
	outtextxy(x/2+75,y/2-150,"Side A");
	outtextxy(x/2+195,y/2-180,"Side B");

	//color representation
	setfillstyle(1,GREEN);
	floodfill(x/2+45,y/2+157,WHITE);

	setfillstyle(1,RED);
	floodfill(x/2+170,y/2+157,WHITE);

	//mid seats
	floodfill(x/2+145,y/2+115,WHITE);
	floodfill(x/2+175,y/2+115,WHITE);

	floodfill(x/2+205,y/2-155,WHITE);
	floodfill(x/2+235,y/2-155,WHITE);

	fp=fopen(filename,"rb");

	setfillstyle(1,RED);

	if(fp!=NULL)
	{
		setfillstyle(1,GREEN);
		//coloring all seat green
		for(i=0;i<270;i+=30)
		{
			floodfill(x/2+85,y/2-125+i,WHITE);
			floodfill(x/2+115,y/2-125+i,WHITE);
			floodfill(x/2+85+120,y/2-125+i,WHITE);
			floodfill(x/2+85+150,y/2-125+i,WHITE);
		}

		//mid seats
		floodfill(x/2+145,y/2+115,WHITE);
		floodfill(x/2+175,y/2+115,WHITE);

		floodfill(x/2+205,y/2-155,WHITE);
		floodfill(x/2+235,y/2-155,WHITE);

		while(fread(&det,sizeof(det),1,fp))
		{
			setfillstyle(1,RED);
			//side A
			if(det.seat==1 && (strcmp(det.side,"A")==0))
				floodfill(x/2+85,y/2-125,WHITE);
			else if(det.seat==3 && (strcmp(det.side,"A")==0))
				floodfill(x/2+85,y/2-95,WHITE);
			else if(det.seat==5 && (strcmp(det.side,"A")==0))
				floodfill(x/2+85,y/2-65,WHITE);
			else if(det.seat==7 && (strcmp(det.side,"A")==0))
				floodfill(x/2+85,y/2-35,WHITE);
			else if(det.seat==9 && (strcmp(det.side,"A")==0))
				floodfill(x/2+85,y/2-5,WHITE);
			else if(det.seat==11 && (strcmp(det.side,"A")==0))
				floodfill(x/2+85,y/2+25,WHITE);
			else if(det.seat==13 && (strcmp(det.side,"A")==0))
				floodfill(x/2+85,y/2+55,WHITE);
			else if(det.seat==15 && (strcmp(det.side,"A")==0))
				floodfill(x/2+85,y/2+85,WHITE);
			else if(det.seat==17 && (strcmp(det.side,"A")==0))
				floodfill(x/2+85,y/2+115,WHITE);
			else if(det.seat==19 && (strcmp(det.side,"A")==0))
				floodfill(x/2+145,y/2+115,WHITE);
				
			//even side A
			else if(det.seat==2 && (strcmp(det.side,"A")==0))
				floodfill(x/2+115,y/2-125,WHITE);
			else if(det.seat==4 && (strcmp(det.side,"A")==0))
				floodfill(x/2+115,y/2-95,WHITE);
			else if(det.seat==6 && (strcmp(det.side,"A")==0))
				floodfill(x/2+115,y/2-65,WHITE);
			else if(det.seat==8 && (strcmp(det.side,"A")==0))
				floodfill(x/2+115,y/2-35,WHITE);
			else if(det.seat==10 && (strcmp(det.side,"A")==0))
				floodfill(x/2+115,y/2+5,WHITE);
			else if(det.seat==12 && (strcmp(det.side,"A")==0))
				floodfill(x/2+115,y/2+25,WHITE);
			else if(det.seat==14 && (strcmp(det.side,"A")==0))
				floodfill(x/2+115,y/2+55,WHITE);
			else if(det.seat==16 && (strcmp(det.side,"A")==0))
				floodfill(x/2+115,y/2+85,WHITE);
			else if(det.seat==18 && (strcmp(det.side,"A")==0))
				floodfill(x/2+115,y/2+115,WHITE);	
			
			//side B
			else if(det.seat==1 && (strcmp(det.side,"B")==0))
				floodfill(x/2+205,y/2-155,WHITE);

			else if(det.seat==3 && (strcmp(det.side,"B")==0))
				floodfill(x/2+205,y/2-125,WHITE);

			else if(det.seat==5 && (strcmp(det.side,"B")==0))
				floodfill(x/2+205,y/2-95,WHITE);
				
			else if(det.seat==7 && (strcmp(det.side,"B")==0))
				floodfill(x/2+205,y/2-65,WHITE);
				
			else if(det.seat==9 && (strcmp(det.side,"B")==0))
				floodfill(x/2+205,y/2-35,WHITE);
				
			else if(det.seat==11 && (strcmp(det.side,"B")==0))
				floodfill(x/2+205,y/2-5,WHITE);

			else if(det.seat==13 && (strcmp(det.side,"B")==0))
				floodfill(x/2+205,y/2+25,WHITE);

			else if(det.seat==15 && (strcmp(det.side,"B")==0))
				floodfill(x/2+205,y/2+55,WHITE);
				
			else if(det.seat==17 && (strcmp(det.side,"B")==0))
				floodfill(x/2+205,y/2+85,WHITE);

			else if(det.seat==19 && (strcmp(det.side,"B")==0))
				floodfill(x/2+175,y/2+115,WHITE);

			else if(det.seat==21 && (strcmp(det.side,"B")==0))
				floodfill(x/2+235,y/2+115,WHITE);

			else if(det.seat==2 && (strcmp(det.side,"B")==0))
				floodfill(x/2+235,y/2-155,WHITE);

			else if(det.seat==4 && (strcmp(det.side,"B")==0))
				floodfill(x/2+235,y/2-125,WHITE);

			else if(det.seat==6 && (strcmp(det.side,"B")==0))
				floodfill(x/2+235,y/2-95,WHITE);

			else if(det.seat==8 && (strcmp(det.side,"B")==0))
				floodfill(x/2+235,y/2-65,WHITE);

			else if(det.seat==10 && (strcmp(det.side,"B")==0))
				floodfill(x/2+235,y/2-35,WHITE);

			else if(det.seat==12 && (strcmp(det.side,"B")==0))
				floodfill(x/2+235,y/2-5,WHITE);

			else if(det.seat==14 && (strcmp(det.side,"B")==0))
				floodfill(x/2+235,y/2+25,WHITE);

			else if(det.seat==16 && (strcmp(det.side,"B")==0))
				floodfill(x/2+235,y/2+55,WHITE);

			else if(det.seat==18 && (strcmp(det.side,"B")==0))
				floodfill(x/2+235,y/2+85,WHITE);

			else if(det.seat==20 && (strcmp(det.side,"B")==0))
				floodfill(x/2+205,y/2+115,WHITE);

			else
				x=639;
			//	floodfill(x/2+235,y/2+85,WHITE);
			//	outtextxy(x/2+235,y/2+85,"x");
				
			//side A
			setcolor(WHITE);
			outtextxy(x/2+85,y/2-125,"1");
			outtextxy(x/2+85,y/2-95,"3");
			outtextxy(x/2+85,y/2-65,"5");
			outtextxy(x/2+85,y/2-35,"7");
			outtextxy(x/2+85,y/2-5,"9");
			outtextxy(x/2+80,y/2+25,"11");
			outtextxy(x/2+80,y/2+55,"13");
			outtextxy(x/2+80,y/2+85,"15");
			outtextxy(x/2+80,y/2+115,"17");
			outtextxy(x/2+140,y/2+115,"19");

			outtextxy(x/2+115,y/2-125,"2");
			outtextxy(x/2+115,y/2-95,"4");
			outtextxy(x/2+115,y/2-65,"6");
			outtextxy(x/2+115,y/2-35,"8");
			outtextxy(x/2+110,y/2-5,"10");
			outtextxy(x/2+110,y/2+25,"12");
			outtextxy(x/2+110,y/2+55,"14");
			outtextxy(x/2+110,y/2+85,"16");
			outtextxy(x/2+110,y/2+115,"18");
		
			//side B
			outtextxy(x/2+205,y/2-155,"1");
			outtextxy(x/2+205,y/2-125,"3");
			outtextxy(x/2+205,y/2-95,"5");
			outtextxy(x/2+205,y/2-65,"7");
			outtextxy(x/2+205,y/2-35,"9");

			outtextxy(x/2+200,y/2-5,"11");
			outtextxy(x/2+200,y/2+25,"13");
			outtextxy(x/2+200,y/2+55,"15");
			outtextxy(x/2+200,y/2+85,"17");
			outtextxy(x/2+170,y/2+115,"19");
			outtextxy(x/2+230,y/2+115,"21");

			outtextxy(x/2+235,y/2-155,"2");
			outtextxy(x/2+235,y/2-125,"4");
			outtextxy(x/2+235,y/2-95,"6");
			outtextxy(x/2+235,y/2-65,"8");

			outtextxy(x/2+230,y/2-35,"10");
			outtextxy(x/2+230,y/2-5,"12");
			outtextxy(x/2+230,y/2+25,"14");
			outtextxy(x/2+230,y/2+55,"16");
			outtextxy(x/2+230,y/2+85,"18");
			outtextxy(x/2+200,y/2+115,"20");
		}
	}
	else
	{
		//coloring every seats black to represent that all seats neither booked nor available.
		setfillstyle(1,BLACK);
		for(i=0;i<270;i+=30)
		{
			floodfill(x/2+85,y/2-125+i,WHITE);
			floodfill(x/2+115,y/2-125+i,WHITE);
			floodfill(x/2+85+120,y/2-125+i,WHITE);
			floodfill(x/2+85+150,y/2-125+i,WHITE);
		}
		//mid seats
		floodfill(x/2+145,y/2+115,WHITE);
		floodfill(x/2+175,y/2+115,WHITE);

		floodfill(x/2+205,y/2-155,WHITE);
		floodfill(x/2+235,y/2-155,WHITE);

		outtextxy(x/2+45,y/2,"No ticket has been booked yet :(");
	}
	fclose(fp);
}

//This function is for booking ticket
//this function should detect whether the seat is already booked or not -> add this function
void booking()
{
	FILE *fp;
	int flag,count;

	struct passenger det,check;

	filenaming_passenger(fn);
	flag=compare_date(fn);

	final_filename(fn);

	loop1:

	clrscr();

	avail_book(fn_final);
	
	if(flag==0)
	{
		setfillstyle(1,BLACK);
		floodfill(3,3,WHITE);
		rectangle(0,0,639,400);

		settextstyle(1,HORIZ_DIR,4);
		outtextxy(x/2-235,y/2-85,"Traveller's");

		settextstyle(0,HORIZ_DIR,1);
		outtextxy(x/2-238,150,"***             ****");

		outtextxy(x/2-210,150,"Safe Journey");

		settextstyle(0,HORIZ_DIR,1);
		outtextxy(x/4-70,y/2+60,"Sorry you can not");
		setcolor(RED);
		outtextxy(x/4-20,y/2+80,"book");
		setcolor(WHITE);
		outtextxy(x/4-17,y/2+100,"the");
		outtextxy(x/4-80,y/2+120,"ticket for past date.");
	}
	else
	{
		settextstyle(1,HORIZ_DIR,4);
		outtextxy(x/2-235,y/2-85,"Traveller's");

		settextstyle(0,HORIZ_DIR,1);
		outtextxy(x/2-238,150,"***             ****");

		outtextxy(x/2-210,150,"Safe Journey");

		count=0;

		setcolor(WHITE);
		circle(x/2-30,380,5);
		circle(x/2,380,5);
		circle(x/2+30,380,5);

		setfillstyle(1,GREEN);
		floodfill(x/2-30,380,WHITE);
		floodfill(x/2,380,WHITE);
		floodfill(x/2+30,380,WHITE);

		gotoxy(9,15);
			printf("Seat number : ");
			scanf("%d",&det.seat);
			fflush(stdin);

		gotoxy(9,16);
			printf("Side        : ");
			scanf("%s",det.side);
			fflush(stdin);
			strupr(det.side);
			
		if(strcmp(det.side,"A")==0)
		{
			if(det.seat<1 || det.seat>19)
			{
				gotoxy(9,20);
				printf("Invalid seat number.");
				getch();
				goto loop;
			}
		}

		if(strcmp(det.side,"B")==0)
		{
			if(det.seat<1 || det.seat>21)
			{
				gotoxy(9,20);
				printf("Invalid seat number.");
				getch();
				goto loop;
			}
		}

		if(strcmp(det.side,"A")!=0 && strcmp(det.side,"B")!=0)
		{
			gotoxy(9,20);
			printf("Invalid seat side.");
			getch();
			goto loop;
		}
		
		gotoxy(9,17);
			printf("Name        : ");
			scanf("%s %s",det.name1,det.name2);
			strupr(det.name1);
			strupr(det.name2);
			fflush(stdin);

		gotoxy(9,18);
			printf("Destination : ");
			scanf("%s",det.dtn);
			fflush(stdin);
			strupr(det.dtn);

		//checking if the seat is already booked or not
		fp=fopen(fn_final,"rb");

		while(fread(&check,sizeof(check),1,fp)!=0)
		{
			if(check.seat==det.seat && strcmp(check.side,det.side)==0)
				count++;
		}
		if(count>0)
		{
			outtextxy(x/4-115,y/2+110,"Sorry! seat is already booked.");
			getch();
			fclose(fp);
		}
		else
		{
			fclose(fp);

			//appending data if seat is not booked
			fp=fopen(fn_final,"ab");
				fwrite(&det,sizeof(det),1,fp);
			fclose(fp);

			gotoxy(9,20);
			printf("Ticket booked :)");
			getch();
		}
		loop:
		clrscr();
		avail_book(fn_final);
		settextstyle(1,HORIZ_DIR,4);
		outtextxy(x/2-235,y/2-85,"Traveller's");

		settextstyle(0,HORIZ_DIR,1);
		outtextxy(x/2-238,150,"***             ****");
		outtextxy(x/2-210,150,"Safe Journey");
		outtextxy(x/4-98,y/2+125,"Book ticket again [Y/N] ?");

		gotoxy(19,22);
		//scanf("%c",&choice);
		choice=getch();
		fflush(stdin);

		if(isalpha(choice))
		{
			if(choice=='y' || choice=='Y')
				goto loop1;
			else if(choice=='N' || choice=='n')
				outtextxy(x/4-104,y/2+155,"Thanks for booking ticket.");
			else
				outtextxy(x/4-80,y/2+155,"Sorry! Invalid choice");
		}
		if(!isalpha(choice))
			outtextxy(x/4-80,y/2+110,"Sorry! Invalid choice");
	}
	getch();
}


//This function is for cancelling ticket
void cancel()
{
	FILE *fp1,*fp2;

	int no,sc,flag,count1,count2;

	char si[2];

	struct passenger det, check;

	loop1:

	filenaming_passenger(fn);

	flag=compare_date(fn);

	final_filename(fn);

	if(flag==0)
	{
		clrscr();
		layout1();
		setfillstyle(1,BLACK);
		floodfill(3,3,WHITE);
		rectangle(0,0,639,400);
		outtextxy(x/2-142,y/2+50,"Ticket cannot be booked for past date.");
	}
	else
	{
		fp1=fopen(fn_final,"rb");
		if(fp1==NULL)
		{
			fclose(fp1);
			layout1();
			setfillstyle(1,BLACK);
			floodfill(3,3,WHITE);
			rectangle(0,0,639,400);
			outtextxy(x/2-150,y/2+50,"No ticket has been booked for this date.");
		}
		else
		{
			fclose(fp1);

			loop2:
			count1=0;
			count2=0;

			clrscr();

			layout1();

			gotoxy(28,15);
				printf("Seat Number : ");
				scanf("%d",&no);
				fflush(stdin);

			gotoxy(28,16);
				printf("Side        : ");
				scanf("%s",si);
				strupr(si);
				fflush(stdin);

			//checking if the seat is already booked or not
			fp1=fopen(fn_final,"rb");

			while(fread(&check,sizeof(check),1,fp1)!=0)
			{
				if(check.seat==no && strcmp(check.side,si)==0)
					count1++;
			}

			if(count1==0)
			{
				fclose(fp1);
				gotoxy(22,20);
					printf("Sorry! this seat is not booked yet.");
			}
			else
			{
				rewind(fp1);

				while(fread(&det,sizeof(det),1,fp1)!=0)
					count2++;

				fclose(fp1);

				fp1=fopen(fn_final,"rb");
				fp2=fopen("cancel.txt","wb");

				for(i=0;i<count2;i++)
				{
					fread(&det,sizeof(det),1,fp1);

					sc=strcmp(si,det.side);
					if(no!=det.seat && sc!=0)
						fwrite(&det,sizeof(det),1,fp2);
					else if(no!=det.seat && sc==0)
						fwrite(&det,sizeof(det),1,fp2);
					else if(no==det.seat && sc!=0)
						fwrite(&det,sizeof(det),1,fp2);
					else
					{
						gotoxy(34,22);
						printf("Ticket cancelled");
					}
				}
				fclose(fp1);
				fclose(fp2);

				remove(fn_final);

				rename("cancel.txt",fn_final);
			}
		}
	}
	getch();
}


//shows the avaibility of seat in graphical mode
void avail()
{
	FILE *fp;
	struct passenger det;

	char destination[20];
	char fname[40];

	filenaming_passenger(fname);
	final_filename(fname);
	clrscr();

	for(i=0;fname[i]!='\0';i++)
		aim[0]=fname[i];

	aim[1]='\0';

	if((strcmp(aim,"H"))==0)
		strcpy(destination,"Haibung");
	
	else if((strcmp(aim,"D"))==0)
		strcpy(destination,"Damak");
	
	else if((strcmp(aim,"M"))==0)
		strcpy(destination,"Melamchi");
	
	else if((strcmp(aim,"I"))==0)
		strcpy(destination,"Itahari");
	else
		strcpy(destination,"Tibeni");

	layout2();
	//destination
	gotoxy(48,2);
	printf("Destination : %s",destination);

	setlinestyle(0,0,1);

	//section A
	rectangle(x/2-210,90,x/2-150,360);

	//section B
	rectangle(x/2-90,60,x/2-30,360);

	//lines side A
	line(x/2-210,120,x/2-150,120);
	line(x/2-210,150,x/2-150,150);
	line(x/2-210,180,x/2-150,180);
	line(x/2-210,210,x/2-150,210);
	line(x/2-210,240,x/2-150,240);
	line(x/2-210,270,x/2-150,270);
	line(x/2-210,300,x/2-150,300);

	line(x/2-180,y/2-110,x/2-180,y/2+160);

	line(x/2-210,330,x/2-30,330);
	line(x/2-210,360,x/2-30,360);

	//lines side B
	line(x/2-90,90,x/2-30,90);
	line(x/2-90,120,x/2-30,120);
	line(x/2-90,150,x/2-30,150);
	line(x/2-90,180,x/2-30,180);
	line(x/2-90,210,x/2-30,210);
	line(x/2-90,240,x/2-30,240);
	line(x/2-90,270,x/2-30,270);
	line(x/2-90,300,x/2-30,300);
	line(x/2-90,330,x/2-30,330);
	line(x/2-60,y/2-140,x/2-60,y/2+160);

	//last seat
	line(x/2-120,y/2+130,x/2-120,y/2+160);

	outtextxy(x/2-210,y/2-120,"Side A");
	outtextxy(x/2-90,y/2-150,"Side B");

	//note
	rectangle(x/2+60,y/2-120,x/2+90,y/2-90);
	setfillstyle(1,GREEN);
	floodfill(x/2+75,y/2-105,WHITE);

	rectangle(x/2+60,y/2-60,x/2+90,y/2-30);
	setfillstyle(1,RED);
	floodfill(x/2+75,y/2-45,WHITE);

	outtextxy(x/2+110,y/2-110,"Available");
	outtextxy(x/2+110,y/2-50,"Reserved");

	fp=fopen(fn_final,"rb");

	setfillstyle(1,RED);

	if(fp!=NULL)
	{
		//filling the colors
		setfillstyle(1,GREEN);
		for(i=0;i<=240;i+=30)
		{
			floodfill(x/2-195,y/2-105+i,WHITE);
			floodfill(x/2-165,y/2-105+i,WHITE);
		}
		for(i=0;i<=270;i+=30)
		{
			floodfill(x/2-75,y/2-135+i,WHITE);
			floodfill(x/2-45,y/2-135+i,WHITE);
		}
		floodfill(x/2-105,y/2+135,WHITE);
		floodfill(x/2-135,y/2+135,WHITE);
		
		setfillstyle(1,RED);

		setcolor(WHITE);
		//outtextxy(x/2-,y/2-,"");
		while(fread(&det,sizeof(det),1,fp))
		{
			//side A
			if(det.seat==1 && (strcmp(det.side,"A")==0))
				floodfill(x/2-195,y/2-105,WHITE);
			else if(det.seat==3 && (strcmp(det.side,"A")==0))
				floodfill(x/2-195,y/2-75,WHITE);
			else if(det.seat==5 && (strcmp(det.side,"A")==0))
				floodfill(x/2-195,y/2-45,WHITE);
			else if(det.seat==7 && (strcmp(det.side,"A")==0))
				floodfill(x/2-195,y/2-15,WHITE);
			else if(det.seat==9 && (strcmp(det.side,"A")==0))
				floodfill(x/2-195,y/2+15,WHITE);
			else if(det.seat==11 && (strcmp(det.side,"A")==0))
				floodfill(x/2-195,y/2+45,WHITE);
			else if(det.seat==13 && (strcmp(det.side,"A")==0))
				floodfill(x/2-195,y/2+75,WHITE);
			else if(det.seat==15 && (strcmp(det.side,"A")==0))
				floodfill(x/2-195,y/2+105,WHITE);
			else if(det.seat==17 && (strcmp(det.side,"A")==0))
				floodfill(x/2-195,y/2+135,WHITE);
			else if(det.seat==19 && (strcmp(det.side,"A")==0))
				floodfill(x/2-135,y/2+135,WHITE);
			else if(det.seat==2 && (strcmp(det.side,"A")==0))
				floodfill(x/2-165,y/2-105,WHITE);
			else if(det.seat==4 && (strcmp(det.side,"A")==0))
				floodfill(x/2-165,y/2-75,WHITE);
			else if(det.seat==6 && (strcmp(det.side,"A")==0))
				floodfill(x/2-165,y/2-45,WHITE);
			else if(det.seat==8 && (strcmp(det.side,"A")==0))
				floodfill(x/2-165,y/2-15,WHITE);
			else if(det.seat==10 && (strcmp(det.side,"A")==0))
				floodfill(x/2-165,y/2+15,WHITE);
			else if(det.seat==12 && (strcmp(det.side,"A")==0))
				floodfill(x/2-165,y/2+45,WHITE);
			else if(det.seat==14 && (strcmp(det.side,"A")==0))
				floodfill(x/2-165,y/2+75,WHITE);
			else if(det.seat==16 && (strcmp(det.side,"A")==0))
				floodfill(x/2-165,y/2+105,WHITE);
			else if(det.seat==18 && (strcmp(det.side,"A")==0))
				floodfill(x/2-165,y/2+145,WHITE);
				
			//side B
			else if(det.seat==1 && (strcmp(det.side,"B")==0))
				floodfill(x/2-75,y/2-135,WHITE);
			else if(det.seat==3 && (strcmp(det.side,"B")==0))
				floodfill(x/2-75,y/2-105,WHITE);
			else if(det.seat==5 && (strcmp(det.side,"B")==0))
				floodfill(x/2-75,y/2-75,WHITE);
			else if(det.seat==7 && (strcmp(det.side,"B")==0))
				floodfill(x/2-75,y/2-44,WHITE);
			else if(det.seat==9 && (strcmp(det.side,"B")==0))
				floodfill(x/2-75,y/2-15,WHITE);
			else if(det.seat==11 && (strcmp(det.side,"B")==0))
				floodfill(x/2-75,y/2+15,WHITE);
			else if(det.seat==13 && (strcmp(det.side,"B")==0))
				floodfill(x/2-75,y/2+45,WHITE);
			else if(det.seat==15 && (strcmp(det.side,"B")==0))
				floodfill(x/2-75,y/2+75,WHITE);
			else if(det.seat==17 && (strcmp(det.side,"B")==0))
				floodfill(x/2-75,y/2+105,WHITE);
			else if(det.seat==19 && (strcmp(det.side,"B")==0))
				floodfill(x/2-105,y/2+135,WHITE);
			else if(det.seat==21 && (strcmp(det.side,"B")==0))
			{
				floodfill(x/2-45,y/2+147,WHITE);
				//outtextxy(x/2-45,y/2+145,"Hello");
			}
			else if(det.seat==2 && (strcmp(det.side,"B")==0))
				floodfill(x/2-45,y/2-135,WHITE);
			else if(det.seat==4 && (strcmp(det.side,"B")==0))
				floodfill(x/2-45,y/2-105,WHITE);
			else if(det.seat==6 && (strcmp(det.side,"B")==0))
				floodfill(x/2-45,y/2-75,WHITE);
			else if(det.seat==8 && (strcmp(det.side,"B")==0))
				floodfill(x/2-45,y/2-45,WHITE);
			else if(det.seat==10 && (strcmp(det.side,"B")==0))
				floodfill(x/2-45,y/2-15,WHITE);
			else if(det.seat==12 && (strcmp(det.side,"B")==0))
				floodfill(x/2-45,y/2+15,WHITE);
			else if(det.seat==14 && (strcmp(det.side,"B")==0))
				floodfill(x/2-45,y/2+45,WHITE);
			else if(det.seat==16 && (strcmp(det.side,"B")==0))
				floodfill(x/2-45,y/2+75,WHITE);
			else if(det.seat==18 && (strcmp(det.side,"B")==0))
				floodfill(x/2-45,y/2+105,WHITE);
			else if(det.seat==20 && (strcmp(det.side,"B")==0))
				floodfill(x/2-75,y/2+135,WHITE);
			else
				x=639;

			//naming side A
			outtextxy(x/2-197,y/2-100,"1");
			outtextxy(x/2-197,y/2-70,"3");
			outtextxy(x/2-197,y/2-40,"5");
			outtextxy(x/2-197,y/2-5,"7");
			outtextxy(x/2-197,y/2+20,"9");
			outtextxy(x/2-200,y/2+55,"11");
			outtextxy(x/2-200,y/2+85,"13");
			outtextxy(x/2-200,y/2+115,"15");
			outtextxy(x/2-200,y/2+145,"17");

			outtextxy(x/2-140,y/2+145,"19");

			outtextxy(x/2-167,y/2-100,"2");
			outtextxy(x/2-167,y/2-70,"4");
			outtextxy(x/2-167,y/2-40,"6");
			outtextxy(x/2-167,y/2-5,"8");

			outtextxy(x/2-171,y/2+20,"10");
			outtextxy(x/2-171,y/2+55,"12");
			outtextxy(x/2-171,y/2+85,"14");
			outtextxy(x/2-171,y/2+115,"16");
			outtextxy(x/2-171,y/2+145,"18");
			
			//naming side B
			outtextxy(x/2-78,y/2-130,"1");
			outtextxy(x/2-78,y/2-100,"3");
			outtextxy(x/2-78,y/2-70,"5");
			outtextxy(x/2-78,y/2-39,"7");
			outtextxy(x/2-78,y/2-10,"9");

			outtextxy(x/2-81,y/2+20,"11");
			outtextxy(x/2-81,y/2+50,"13");
			outtextxy(x/2-81,y/2+80,"15");
			outtextxy(x/2-81,y/2+110,"17");
			outtextxy(x/2-110,y/2+145,"19");
			outtextxy(x/2-48,y/2+145,"21");

			outtextxy(x/2-50,y/2-130,"2");
			outtextxy(x/2-50,y/2-100,"4");
			outtextxy(x/2-50,y/2-70,"6");
			outtextxy(x/2-50,y/2-40,"8");
			outtextxy(x/2-50,y/2-10,"10");
			outtextxy(x/2-50,y/2+20,"12");
			outtextxy(x/2-50,y/2+50,"14");
			outtextxy(x/2-50,y/2+80,"16");
			outtextxy(x/2-50,y/2+110,"18");
			outtextxy(x/2-80,y/2+145,"20");
		}
	}
	else
	{
		//filling the black color to represent the seat is neither booked nor reserved
		setfillstyle(1,BLACK);
		for(i=0;i<=240;i+=30)
		{
			floodfill(x/2-195,y/2-105+i,WHITE);
			floodfill(x/2-165,y/2-105+i,WHITE);
		}
		for(i=0;i<=270;i+=30)
		{
			floodfill(x/2-75,y/2-135+i,WHITE);
			floodfill(x/2-45,y/2-135+i,WHITE);
		}
		floodfill(x/2-105,y/2+135,WHITE);
		floodfill(x/2-135,y/2+135,WHITE);

		setcolor(WHITE);
		//naming side A
		outtextxy(x/2-197,y/2-100,"1");
		outtextxy(x/2-197,y/2-70,"3");
		outtextxy(x/2-197,y/2-40,"5");
		outtextxy(x/2-197,y/2-5,"7");
		outtextxy(x/2-197,y/2+20,"9");
		outtextxy(x/2-200,y/2+55,"11");
		outtextxy(x/2-200,y/2+85,"13");
		outtextxy(x/2-200,y/2+115,"15");
		outtextxy(x/2-200,y/2+145,"17");
		outtextxy(x/2-140,y/2+145,"19");

		outtextxy(x/2-167,y/2-100,"2");
		outtextxy(x/2-167,y/2-70,"4");
		outtextxy(x/2-167,y/2-40,"6");
		outtextxy(x/2-167,y/2-5,"8");
		outtextxy(x/2-171,y/2+20,"10");
		outtextxy(x/2-171,y/2+55,"12");
		outtextxy(x/2-171,y/2+85,"14");
		outtextxy(x/2-171,y/2+115,"16");
		outtextxy(x/2-171,y/2+145,"18");

		//naming side B
		outtextxy(x/2-78,y/2-130,"1");
		outtextxy(x/2-78,y/2-100,"3");
		outtextxy(x/2-78,y/2-70,"5");
		outtextxy(x/2-78,y/2-39,"7");
		outtextxy(x/2-78,y/2-10,"9");
		outtextxy(x/2-81,y/2+20,"11");
		outtextxy(x/2-81,y/2+50,"13");
		outtextxy(x/2-81,y/2+80,"15");
		outtextxy(x/2-81,y/2+110,"17");
		outtextxy(x/2-110,y/2+145,"19");
		outtextxy(x/2-48,y/2+145,"21");

		outtextxy(x/2-50,y/2-130,"2");
		outtextxy(x/2-50,y/2-100,"4");
		outtextxy(x/2-50,y/2-70,"6");
		outtextxy(x/2-50,y/2-40,"8");
		outtextxy(x/2-50,y/2-10,"10");
		outtextxy(x/2-50,y/2+20,"12");
		outtextxy(x/2-50,y/2+50,"14");
		outtextxy(x/2-50,y/2+80,"16");
		outtextxy(x/2-50,y/2+110,"18");
		outtextxy(x/2-80,y/2+145,"20");

		gotoxy(46,18);
		printf("No ticket has not been booked :(");
	}
	fclose(fp);
	getch();
}

//ticket detail
void ticket_detail()
{
	FILE *fp1;

	struct ticket det;

	i=1;

	system("cd MAND");

	fp1=fopen("ticket","rb");

	layout1();

	gotoxy(22,15);
		printf("S.N.	Destination		Price\n");

	if(fp1==NULL)
	{
		gotoxy(33,18);	printf("File not found.");
	}
	else
	{
		while(fread(&det,sizeof(det),1,fp1)!=0)
		{
			spacing;
			printf("\b\b\b%-11d%-23s Rs.%-5d\n",i,det.location,det.price);
			i++;
		}
	}
	rectangle(0,0,639,400);
	fclose(fp1);
	system("cd ..");
	getch();
}


//Adding ticket detail
void add_ticket_detail()
{
	FILE *fp1;
	struct ticket det;
	clrscr();
	layout1();
	system("cd MAND");
	fp1=fopen("ticket","r");
	if(fp1==NULL)
	{
		outtextxy(x/2-60,y/2+20,"File not found.");
		getch();
		clrscr();
		layout1();
		fclose(fp1);
		fp1=fopen("ticket","wb");
	}
	else
	{
		fclose(fp1);
		clrscr();
		layout1();
		fp1=fopen("ticket","ab");
	}

	gotoxy(32,17);	
		printf("Location : ");
		scanf("%s",det.location);
		fflush(stdin);
		strupr(det.location);

	gotoxy(32,18);	
		printf("Price    : ");
		scanf("%d",&det.price);

	fwrite(&det,sizeof(det),1,fp1);

	fclose(fp1);

	gotoxy(32,21);	printf("Detail added.");
	system("cd ..");
	getch();
}


//for changing the password
void changepw()
{
	FILE *fp;
	char realpw[20],oldpw[20],newpw1[40],newpw2[40];

	system("cd /");
	system("cd TRAVEL");
	system("cd MAND");
	loop:
	clrscr();
	layout1();

	rectangle(x/2,y/2+22,x/2+150,y/2+40);
	rectangle(x/2,y/2+55,x/2+150,y/2+73);
	rectangle(x/2,y/2+86,x/2+150,y/2+104);

	gotoxy(20,15);	printf("Old password      ");
	gotoxy(20,17);	printf("New password      ");
	gotoxy(20,19);	printf("Confirm password  ");

	gotoxy(43,15);	scanf("%s",oldpw);
	gotoxy(43,17);  scanf("%s",newpw1);
	gotoxy(43,19);  scanf("%s",newpw2);

	fp=fopen("pw.dt","r");
		fscanf(fp,"%s",realpw);
	fclose(fp);

	if((strcmp(newpw1,newpw2))!=0  || (strcmp(realpw,oldpw)!=0))
	{
		if(strcmp(newpw1,newpw2)!=0)
		{
			gotoxy(20,22);	printf("Password confirmation failed :(");
		}
		if(strcmp(realpw,oldpw)!=0)
		{
			gotoxy(20,21);
			printf("You entered old password wrong :(");
		}
		getch();
		goto loop;
	}
	if(strcmp(realpw,newpw1)==0)
	{
		gotoxy(20,22);
		printf("New password and old password are same :(");
		getch();
		goto loop;
	}

	fp=fopen("pw.dt","w");
		fprintf(fp,"%s",newpw1);
	fclose(fp);

	gotoxy(20,22);
		printf("New password added :)");
	system("cd ..");
	getch();
}


//returns the filename of the file related to staff details
void filenaming_staff(char* filename)
{
	int yy,mm,dd;
	char year[12],month[6],date[3];
	char space_month[4]="0",space_date[4]="0";
	char destination[40],filename1[20];

	loop:
	layout1();

	rectangle(x/2-115,y/2+130+20,x/2+110,y/2+148+20);

	gotoxy(29,15);	printf("Destination : ");
	gotoxy(29,16);	printf("Year        : ");
	gotoxy(29,17);	printf("Month       : ");
	gotoxy(29,18);	printf("Date        : ");

	gotoxy(44,15);
		scanf("%s",destination);
		fflush(stdin);
		strupr(destination);

	gotoxy(44,16);
		scanf("%s",year);
		fflush(stdin);
		yy=atoi(year);

	gotoxy(44,17);
		scanf("%s",month);
		fflush(stdin);
		mm=atoi(month);

	gotoxy(44,18);
		scanf("%s",date);
		fflush(stdin);
		dd=atoi(date);

	if(yy>99 || yy<0 || mm>12 || mm<=0 || dd>=31 || dd<=0)
	{
		setcolor(RED);
		if(yy>99 || yy<0)
		{
			outtextxy(x/2-95,y/2+155,"Mistake in entering year");
			getch();
			setfillstyle(1,BLACK);
			floodfill(x/2,y/2+138+20,WHITE);
			delay(500);
		}

		if(mm>12 || mm<=0)
		{
			outtextxy(x/2-95,y/2+155,"Mistake in entering month");
			getch();
			setfillstyle(1,BLACK);
			floodfill(x/2,y/2+138+20,WHITE);
			delay(500);
		}

		if(dd>30 || dd<=0)
		{
			outtextxy(x/2-95,y/2+155,"Mistake in entering date");
			getch();
			setfillstyle(1,BLACK);
			floodfill(x/2,y/2+158,WHITE);
			delay(500);
		}
		outtextxy(x/2-108,y/2+155,"Mistake in entering details");
		getch();
		goto loop;
	}
	else
	{
		if(mm<10 || dd<10)
		{
			if(mm<10 && dd>=10)
			{
				strcat(space_month,month);
				strcpy(filename1,strcat(year,strcat(space_month,strcat(date,"S"))));

				if((strcmp(destination,"DAMAK"))==0)
					strcat(filename1,"D");
				
				else if((strcmp(destination,"HAIBUNG"))==0)
					strcat(filename1,"H");

				else if((strcmp(destination,"MELAMCHI"))==0)
					strcat(filename1,"M");

				else if((strcmp(destination,"ITAHARI"))==0)
					strcat(filename1,"I");
				
				else
					strcat(filename1,"T");

				strcpy(filename,filename1);
			}
			else if(dd<10 && mm>=10)
			{
				strcat(space_date,date);
				strcpy(filename1,strcat(year,strcat(month,strcat(space_date,"S"))));

				if((strcmp(destination,"DAMAK"))==0)
					strcat(filename1,"D");
				
				else if((strcmp(destination,"HAIBUNG"))==0)
					strcat(filename1,"H");
				
				else if((strcmp(destination,"MELAMCHI"))==0)
					strcat(filename1,"M");
				
				else if((strcmp(destination,"ITAHARI"))==0)
					strcat(filename1,"I");
				else
					strcat(filename1,"T");

				strcpy(filename,filename1);
			}
			else
			{
				strcat(space_month,month);
				strcat(space_date,date);
				strcpy(filename1,strcat(year,strcat(space_month,strcat(space_date,"S"))));

				if((strcmp(destination,"DAMAK"))==0)
					strcat(filename1,"D");
				
				else if((strcmp(destination,"HAIBUNG"))==0)
					strcat(filename1,"H");

				else if((strcmp(destination,"MELAMCHI"))==0)
					strcat(filename1,"M");

				else if((strcmp(destination,"ITAHARI"))==0)
					strcat(filename1,"I");
				
				else
					strcat(filename1,"T");

				strcpy(filename,filename1);
			}
		}
		else
		{
			strcpy(filename1,strcat(year,strcat(month,strcat(date,"S"))));

			if((strcmp(destination,"DAMAK"))==0)
				strcat(filename1,"D");
			else if((strcmp(destination,"HAIBUNG"))==0)
				strcat(filename1,"H");
			else if((strcmp(destination,"MELAMCHI"))==0)
				strcat(filename1,"M");
			else if((strcmp(destination,"ITAHARI"))==0)
				strcat(filename1,"I");
			else
				strcat(filename1,"T");

			strcpy(filename,filename1);
		}
	}
}


//This function is for filenaming a file related to passenger
void filenaming_passenger(char* filename)
{
	int yy,mm,dd;
	char year[12],month[6],date[3];
	char space_month[4]="0",space_date[4]="0";
	char destination[40],filename1[20];

	loop:
	clrscr();
	layout1();

	setcolor(WHITE);
	rectangle(0,0,639,400);
	rectangle(x/2-115,y/2+130+20,x/2+110,y/2+148+20);

	gotoxy(29,15);	printf("Destination : ");
	gotoxy(29,16);	printf("Year        : ");
	gotoxy(29,17);	printf("Month       : ");
	gotoxy(29,18);	printf("Date        : ");

	gotoxy(44,15);	
		scanf("%s",destination);
		fflush(stdin);
		strupr(destination);

	gotoxy(44,16);  
		scanf("%s",year);
		fflush(stdin);
		yy=atoi(year);

	gotoxy(44,17);  
		scanf("%s",month);
		fflush(stdin);
		mm=atoi(month);

	gotoxy(44,18);  
		scanf("%s",date);
		fflush(stdin);
		dd=atoi(date);

	if(yy>99 || yy<0 || mm>12 || mm<=0 || dd>=31 || dd<=0)
	{
		if(yy>99 || yy<0)
		{
			setcolor(RED);
			outtextxy(x/2-95,y/2+155,"Mistake in entering year");
			getch();
			setfillstyle(1,BLACK);
			floodfill(x/2,y/2+138+20,WHITE);
			delay(500);
		}

		if(mm>12 || mm<=0)
		{
			setcolor(RED);
			outtextxy(x/2-95,y/2+155,"Mistake in entering month");
			getch();
			setfillstyle(1,BLACK);
			floodfill(x/2,y/2+138+20,WHITE);
			delay(500);
		}

		if(dd>30 || dd<=0)
		{
			setcolor(RED);
			outtextxy(x/2-95,y/2+155,"Mistake in entering date");
			getch();
			setfillstyle(1,BLACK);
			floodfill(x/2,y/2+158,WHITE);
			delay(500);
		}

		outtextxy(x/2-108,y/2+155,"Mistake in entering details");
		getch();
		clrscr();
		goto loop;
	}
	else
	{
		if(mm<10 || dd<10)
		{
			if(mm<10 && dd>=10)
			{
				strcat(space_month,month);
				strcpy(filename1,strcat(year,strcat(space_month,strcat(date,"P"))));

				if((strcmp(destination,"DAMAK"))==0)
					strcat(filename1,"D");
				
				else if((strcmp(destination,"HAIBUNG"))==0)
					strcat(filename,"H");

				else if((strcmp(destination,"MELAMCHI"))==0)
					strcat(filename1,"M");

				else if((strcmp(destination,"ITAHARI"))==0)
					strcat(filename1,"I");
				
				else
					strcat(filename1,"T");

				strcpy(filename,filename1);
			}
			else if(dd<10 && mm>=10)
			{
				strcat(space_date,date);
				strcpy(filename1,strcat(year,strcat(month,strcat(space_date,"P"))));

				if((strcmp(destination,"DAMAK"))==0)
					strcat(filename1,"D");
				
				else if((strcmp(destination,"HAIBUNG"))==0)
					strcat(filename,"H");

				else if((strcmp(destination,"MELAMCHI"))==0)
					strcat(filename1,"M");

				else if((strcmp(destination,"ITAHARI"))==0)
					strcat(filename1,"I");
				
				else
					strcat(filename1,"T");

				strcpy(filename,filename1);
			}
			else
			{
				strcat(space_month,month);
				strcat(space_date,date);
				strcpy(filename1,strcat(year,strcat(space_month,strcat(space_date,"P"))));

				if((strcmp(destination,"DAMAK"))==0)
					strcat(filename1,"D");
				else if((strcmp(destination,"HAIBUNG"))==0)
					strcat(filename,"H");

				else if((strcmp(destination,"MELAMCHI"))==0)
					strcat(filename1,"M");

				else if((strcmp(destination,"ITAHARI"))==0)
					strcat(filename1,"I");
				else
					strcat(filename1,"T");

				strcpy(filename,filename1);
			}
		}
		else
		{
			strcpy(filename1,strcat(year,strcat(month,strcat(date,"P"))));

			if((strcmp(destination,"DAMAK"))==0)
				strcat(filename1,"D");
				
			else if((strcmp(destination,"HAIBUNG"))==0)
				strcat(filename1,"H");

			else if((strcmp(destination,"MELAMCHI"))==0)
				strcat(filename1,"M");

			else if((strcmp(destination,"ITAHARI"))==0)
				strcat(filename1,"I");
				
			else
				strcat(filename1,"T");

			strcpy(filename,filename1);
		}
	}
}


//On first run of the program, password is checked 
//if password is right,	main menu is loading screen is shown else, program gets terminated
void initial()
{
	FILE *fp;
	int j,count=0,cmp;
	char password[40];
	char pw[40],first[40]="pass";

	loop1:
	clrscr();
	rectangle(0,0,x,y);
	setfillstyle(1,GREEN);
	floodfill(10,10,WHITE);
	rectangle(2,2,x-2,y-2);

	//Border
	setfillstyle(1,RED);
	floodfill(1,1,WHITE);

	settextstyle(1,HORIZ_DIR,6);
	outtextxy(x/2-122,y/2-150,"Traveller's");
	settextstyle(0,HORIZ_DIR,1);
	outtextxy(x/2-54,y/2-95," Safe Journey");
	outtextxy(x/2+55,y/2-94,"**********");
	outtextxy(x/2-129,y/2-94,"**********");

	circle(x/2-30,y/2,10);
	setfillstyle(1,BLACK);
	floodfill(x/2-30,y/2,WHITE);
	arc(x/2-30,y/2,0,180,12);
	circle(x/2+50,y/2,10);
	floodfill(x/2+50,y/2,WHITE);
	arc(x/2+50,y/2,0,180,12);
	line(x/2-77,y/2-40,x/2+76,y/2-40);
	line(x/2-80,y/2,x/2-42,y/2);
	line(x/2-18,y/2,x/2+38,y/2);
	line(x/2+62,y/2,x/2+80,y/2);

	//bus outer part
	arc(x/2,y/2-15,350,18,81);
	arc(x/2,y/2-15,162,190,81);

	//hoodie
	rectangle(x/2-72,y/2-45,x/2+30,y/2-40);
	floodfill(x/2-69,y/2-42,WHITE);

	//window
	rectangle(x/2-72,y/2-33,x/2+40,y/2-25);
	arc(x/2+50,y/2,10,90,17);
	line(x/2+50,y/2-17,x/2+50,y/2-33);
	line(x/2+50,y/2-33,x/2+72,y/2-33);
	line(x/2+72,y/2-33,x/2+72,y/2-3);
	line(x/2+72,y/2-3,x/2+68,y/2-3);

	//pw box
	rectangle(0,y/2+137,x,y/2+117);
	setfillstyle(1,BLACK);
	floodfill(x/2,y/2+119,WHITE);

	//roadline
	outtextxy(x/2-80,y/2+10,"----------------------");

	//buscolor
	setfillstyle(1,RED);
	floodfill(x/2-10,y/2-10,WHITE);
	setfillstyle(1,CYAN);
	floodfill(x/2-70,y/2-30,WHITE);
	floodfill(x/2+53,y/2-20,WHITE);

	outtextxy(x/2-57,y/2+105,"Enter password");

	gotoxy(38,21);
		scanf("%s",pw);
		fflush(stdin);

	system("cd MAND");
	fp=fopen("pw.dt","r");
	if(fp==NULL)
	{
		fclose(fp);
		fp=fopen("pw.dt","w");
		fprintf(fp,"%s",first);
		fclose(fp);
	}
	fclose(fp);

	fp=fopen("pw.dt","r");
	while(!feof(fp))
	{
		count++;
		fscanf(fp,"%s",password);
		cmp=strcmp(pw,password);
		if(cmp==0)
		{
			sound(260);delay(500);nosound();
			sound(360);delay(500);nosound();
			sound(460);delay(500);nosound();
			//loading();
		}
		else
		{
			if(count<3)
			{
				clrscr();
				setfillstyle(1,RED);
				floodfill(630,390,WHITE);
				rectangle(0,0,639,400);
				sound(261);delay(1000);nosound();
				setcolor(WHITE);
				outtextxy(x/2-55,y/2,"Wrong password");
				getch();
				fclose(fp);
				goto loop1;
			}
			else
			{
				for(i=0;i<5;i++)
				{
					if(i%2!=0)
					{
						clrscr();
						rectangle(0,0,639,400);
						setfillstyle(1,RED);
						floodfill(630,390,WHITE);
					}
					else
					{
						clrscr();
						rectangle(0,0,639,400);
						setfillstyle(1,BLUE);
						floodfill(630,390,WHITE);
						setcolor(WHITE);
						rectangle(0,0,639,400);
					}
					for(j=0;j<=250;j+=50)
					{
						sound(1042+j);delay(250);nosound();
						outtextxy(x/2-150,y/2,"You entered wrong password for three times");
					}
				}
				exit(1);
			}
		}
	}
	system("cd ..");
}

//for loading screen
void loading()
{
	setcolor(WHITE);
	for(i=0;i<400;i+=2)
	{
		clrscr();
		setlinestyle(0,0,1);
		rectangle(0,0,x,y);
		rectangle(2,2,x-2,y-2);

		//Border
		settextstyle(1,HORIZ_DIR,6);
		outtextxy(x/2-122,y/2-150,"Traveller's");
		settextstyle(0,HORIZ_DIR,1);
		outtextxy(x/2-54,y/2-95," Safe Journey");
		outtextxy(x/2+55,y/2-94,"**********");
		outtextxy(x/2-129,y/2-94,"**********");

		circle(x/2-30+i,y/2,10);
		arc(x/2-30+i,y/2,0,180,12);
		circle(x/2+50+i,y/2,10);
		arc(x/2+50+i,y/2,0,180,12);
		line(x/2-77+i,y/2-40,x/2+76+i,y/2-40);
		line(x/2-80+i,y/2,x/2-42+i,y/2);
		line(x/2-18+i,y/2,x/2+38+i,y/2);
		line(x/2+62+i,y/2,x/2+80+i,y/2);

		//bus outer part
		arc(x/2+i,y/2-15,350,18,81);
		arc(x/2+i,y/2-15,162,190,81);
		//hoodie
		rectangle(x/2-72+i,y/2-45,x/2+30+i,y/2-40);

		//window
		rectangle(x/2-72+i,y/2-33,x/2+40+i,y/2-25);
		arc(x/2+50+i,y/2,10,90,17);
		line(x/2+50+i,y/2-17,x/2+50+i,y/2-33);
		line(x/2+50+i,y/2-33,x/2+72+i,y/2-33);
		line(x/2+72+i,y/2-33,x/2+72+i,y/2-3);
		line(x/2+72+i,y/2-3,x/2+68+i,y/2-3);

		//roadline
		setlinestyle(3,0,1);
		line(0-i,y/2+12,1000+x-i,y/2+12);

		//boxes
		setlinestyle(0,0,1);
		rectangle(x/2-50-i,y/2,x/2-47-i,y/2+12);
		rectangle(x/2-150-i,y/2,x/2-147-i,y/2+12);
		rectangle(x/2-250-i,y/2,x/2-247-i,y/2+12);
		rectangle(x/2+50-i,y/2,x/2+47-i,y/2+12);
		rectangle(x/2+150-i,y/2,x/2+147-i,y/2+12);
		rectangle(x/2+250-i,y/2,x/2+247-i,y/2+12);
		rectangle(x/2+350-i,y/2,x/2+347-i,y/2+12);
		rectangle(x/2+450-i,y/2,x/2+447-i,y/2+12);
		rectangle(x/2+550-i,y/2,x/2+547-i,y/2+12);
		rectangle(x/2+650-i,y/2,x/2+647-i,y/2+12);

		//pw box
		rectangle(x/4,y/2+117,x/2+x/4,y/2+127);

		delay(50);
	}
	clrscr();
}


//renaming the final filename
void final_filename(char *fn)
{
	char dep;

	i=0;
	fn_final[i]=fn[i];	i++;
	fn_final[i]=fn[i];	i++;

	if(fn[2]=='0' && fn[3]=='1')		fn_final[i]='A';
	else if(fn[2]=='0' && fn[3]=='2')	fn_final[i]='B';
	else if(fn[2]=='0' && fn[3]=='3')	fn_final[i]='C';
	else if(fn[2]=='0' && fn[3]=='4')	fn_final[i]='D';
	else if(fn[2]=='0' && fn[3]=='5')	fn_final[i]='E';
	else if(fn[2]=='0' && fn[3]=='6')	fn_final[i]='F';
	else if(fn[2]=='0' && fn[3]=='7')	fn_final[i]='G';
	else if(fn[2]=='0' && fn[3]=='8')	fn_final[i]='H';
	else if(fn[2]=='0' && fn[3]=='9')	fn_final[i]='I';
	else if(fn[2]=='1' && fn[3]=='0')	fn_final[i]='J';
	else if(fn[2]=='1' && fn[3]=='1')	fn_final[i]='K';
	else 								fn_final[i]='L';

	i++;
	fn_final[i]=fn[4];	i++;
	fn_final[i]=fn[5];	i++;
	fn_final[i]=fn[6];	i++;
	fn_final[i]=fn[7];	i++;

	layout1();

	gotoxy(14,16);
	printf("Enter departure time [Morning/Day/Night] [M/D/N] : ");
	scanf("%c",&dep);
	fflush(stdin);

	if(dep=='M' || dep=='m')
		fn_final[i]='M';
	else if(dep=='D' || dep=='d')
		fn_final[i]='D';
	else
		fn_final[i]='N';
	i++;

	fn_final[i]='\0';
}

//On startup, this program checks if the provided date is is correct or not
void compare()
{
	int yy,mm,dd;
	char year[12],month[6],date[3];
	char space_month[4]="0",space_date[4]="0";

	loop:
	clrscr();

	setcolor(WHITE);

	setfillstyle(1,BLACK);
	floodfill(1,1,WHITE),

	layout1();

	rectangle(0,0,639,400);

	rectangle(x/2-115,y/2+130+20,x/2+110,y/2+148+20);

	outtextxy(x/2-87,y/2,"Enter today's details :");
	outtextxy(x/2-15,y/2+25,"Year");
	outtextxy(x/2-18,y/2+57,"Month");
	outtextxy(x/2-16,y/2+91,"Date");

	gotoxy(40,16);
	scanf("%s",year);
	fflush(stdin);
	yy=atoi(year);

	gotoxy(40,18);
	scanf("%s",month);
	fflush(stdin);
	mm=atoi(month);

	gotoxy(40,20);
	scanf("%s",date);
	fflush(stdin);
	dd=atoi(date);

	if(yy>99 || yy<0 || mm>12 || mm<=0 || dd>=31 || dd<=0)
	{
		if(yy>99 || yy<0)
		{
			setcolor(RED);
			outtextxy(x/2-95,y/2+155,"Mistake in entering year");
			getch();
			setfillstyle(1,BLACK);
			floodfill(x/2,y/2+138+20,WHITE);
			delay(500);
		}

		if(mm>12 || mm<=0)
		{
			setcolor(RED);
			outtextxy(x/2-95,y/2+155,"Mistake in entering month");
			getch();
			setfillstyle(1,BLACK);
			floodfill(x/2,y/2+138+20,WHITE);
			delay(500);
		}

		if(dd>30 || dd<=0)
		{
			setcolor(RED);
			outtextxy(x/2-95,y/2+155,"Mistake in entering date");
			getch();
			setfillstyle(1,BLACK);
			floodfill(x/2,y/2+158,WHITE);
			delay(500);
		}

		outtextxy(x/2-108,y/2+155,"Mistake in entering details");
		getch();
		goto loop;
	}
	else
	{
		if(mm<10 || dd<10)
		{
			if(mm<10 && dd>=10)
			{
				strcat(space_month,month);
				strcpy(compare_filename,strcat(year,strcat(space_month,date)));
			}
			else if(dd<10 && mm>=10)
			{
				strcat(space_date,date);
				strcpy(compare_filename,strcat(year,strcat(month,space_date)));
			}
			else
			{
				strcat(space_month,month);
				strcat(space_date,date);
				strcpy(compare_filename,strcat(year,strcat(space_month,space_date)));
			}
		}
		else
			strcpy(compare_filename,strcat(year,strcat(month,date)));
	}
}

//Comparing two dates
//return 0 if present date is smaller than date on which daetai is to be added
int compare_date(char *filename1)
{
	int i,len1,len2,num1[6],num2[6];
	int f1yy,f1mm,f1dd;
	int f2yy,f2mm,f2dd;
	clrscr();

	len1=strlen(filename1);
	for(i=0;i<len1-2;i++)
	{
		if(filename1[i]=='0')			num1[i]=0;
		else if (filename1[i]=='1')     num1[i]=1;
		else if (filename1[i]=='2')     num1[i]=2;
		else if (filename1[i]=='3')     num1[i]=3;
		else if (filename1[i]=='4')     num1[i]=4;
		else if (filename1[i]=='5')     num1[i]=5;
		else if (filename1[i]=='6')     num1[i]=6;
		else if (filename1[i]=='7')     num1[i]=7;
		else if (filename1[i]=='8')     num1[i]=8;
		else                            num1[i]=9;
	}

	//compare_filename
	len2=strlen(compare_filename);
	for(i=0;i<len2;i++)
	{
		if(compare_filename[i]=='0')    		num2[i]=0;
		else if (compare_filename[i]=='1')      num2[i]=1;
		else if (compare_filename[i]=='2')      num2[i]=2;
		else if (compare_filename[i]=='3')      num2[i]=3;
		else if (compare_filename[i]=='4')      num2[i]=4;
		else if (compare_filename[i]=='5')      num2[i]=5;
		else if (compare_filename[i]=='6')      num2[i]=6;
		else if (compare_filename[i]=='7')      num2[i]=7;
		else if (compare_filename[i]=='8')      num2[i]=8;
		else                                    num2[i]=9;
	}
	f1yy=num1[0]*10+num1[1];
	f1mm=num1[2]*10+num1[3];
	f1dd=num1[4]*10+num1[5];

	f2yy=num2[0]*10+num2[1];
	f2mm=num2[2]*10+num2[3];
	f2dd=num2[4]*10+num2[5];

	//comparing two dates
	if(f2yy>f1yy || f2mm>f1mm || f2dd>f1dd)
		return 0;
	else
		return 1;
}

//graphical layout 1
void layout1()
{
	clrscr();
	setfillstyle(1,BLACK);
	floodfill(1,1,WHITE);
	setcolor(WHITE);
	rectangle(0,0,639,400);
		line(0,40,40,0);
		line(0,80,80,0);
		line(0,100,100,0);
		line(0,140,140,0);
	setfillstyle(1,GREEN);
	floodfill(5,45,WHITE);
	floodfill(5,105,WHITE);
	settextstyle(1,HORIZ_DIR,6);
	outtextxy(x/2-123,87,"Traveller's");
	settextstyle(0,HORIZ_DIR,1);
	outtextxy(x/2-123,144,"********              **********");
	outtextxy(x/2-50,144,"Safe Journey");
}

//graphical layout2
void layout2()
{
	clrscr();
	setfillstyle(1,BLACK);
	floodfill(1,1,WHITE);
	rectangle(0,0,639,400);
		line(0,20,20,0);
		line(0,40,40,0);
		line(0,60,60,0);
		line(0,80,80,0);
	setfillstyle(1,GREEN);
	floodfill(5,25,WHITE);
	floodfill(5,65,WHITE);
}
