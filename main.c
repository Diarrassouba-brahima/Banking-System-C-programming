#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user
{
    char fname[40];
    char sname[40];
    int phonenum;
    int day;
    int month;
    int year;
    char couname[40];
    char adress[40];
    char username[40];
    char accountnum[8];
    char password[12];
    int amount;
};

int main()
{


    int choice;
    printf("\n\t\t---------------------");
    printf("\n\t\tWELCOME TO LAFAD BANK");
    printf("\n\t\t---------------------");
    printf("\n\n\t\t1-CREAT YOUR ACCOUNT");
    printf("\n\t\t2-LOGIN");
    printf("\n\t\t3-LAFAD BANK RESERVE");
    printf("\n\t\t4-EXIT");
    printf("\n\t\tenter your choice : ");
    scanf("%d",&choice);
    if(choice==1)
    {
        system("cls");
        printf("\n\t\tCREAT YOUR ACCOUNT");
        creataccount ();
    }
    if(choice==2)
    {
        system("cls");
        printf("\n\t\t\tLOGIN");
        login ();
    }
    if(choice==3)
    {
        system("cls");
        printf("\n\t\tLAFAD BANK RESERVE");
    }
    if(choice==4)
    {
        exit;
    }


    return 0;
}

void creataccount ()
{
    //char filename[10];
    FILE *fp;
    struct user user;
//    printf("\n\t\tenter file name : ");
//    scanf("%s",&filename);
    printf("\n\n\t\tenter first name : ");
    scanf("%s",user.fname);
    printf("\n\t\tenter second name : ");
    scanf("%s",user.sname);
    printf("\n\t\tenter phone number : ");
    scanf("%d",&user.phonenum);
    printf("\n\t\tenter the date dd/mm/yy : ");
    scanf("%d/%d/%d",&user.day,&user.month,&user.year);
    printf("\n\t\tenter your country name : ");
    scanf("%s",user.couname);
    printf("\n\t\tenter your adress : ");
    scanf("%s",user.adress);
    printf("\n\t\tenter user name : ");
    scanf("%s",user.username);
    printf("\n\t\tenter your account number : ");
    scanf("%s",user.accountnum);
    printf("\n\t\tenter your passe word : ");
    scanf("%s",user.password);
    printf("\n\t\tenter amount : ");
    scanf("%d",&user.amount);
    fp=fopen("filename.txt","w");
    fwrite(&user,sizeof(user),1,fp);
    // fprintf(fp,"%s %s %d %d/%d/%d %s %s %s %s %s %d.taka",user.fname,user.sname,user.phonenum,user.day,user.month,user.year,user.couname,user.adress,user.username,user.accountnum,user.password,user.amount);
    fclose(fp);
    system("cls");
    printf("\n\t\t!!!!your account have created with sucess!!!! ");
    printf("\n\t\t**%d.taka have been deposit in your account**",user.amount);
   printf("\n\n");
   printf("load............................");
   printf("\n\t\tenter");
   login ();
}

void login()
{
    char billcc[12],billce[12],billcw[12];
    char accnum[8],npassw[12],usname[40];
    char passw[12];
    struct user user;
    int choice,amountt;
    FILE *fp;
    printf("\n\n\t\tenter your account number : ");
    scanf("%s",accnum);
    fp=fopen("filename.txt","r");
    fread(&user,sizeof(user),1,fp);
    fclose(fp);
    if(strcmp(accnum,user.accountnum)==0)
    {
        printf("\n\t\tenter your password : ");
        scanf("%s",passw);
        fp=fopen("filename.txt","r");
        fread(&user,sizeof(user),1,fp);
        fclose(fp);
        if(strcmp(passw,user.password)==0)
        {
            system("cls");
            printf("\n\t\t1-ADD fun");
            printf("\n\t\t2-RETIR");
            printf("\n\t\t3-CHEICK YOUR BALANCE");
            printf("\n\t\t4-BILL PAYEMENT");
            printf("\n\t\t5-MONEY TRANSFER");
            printf("\n\t\t6-CHANGE YOUR PASSWORD");
            printf("\n\t\tenter your choice : ");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1 :
                printf("\n\t\tADD fun");
                 printf("\n\t\tenter the amount to add : ");
                scanf("%d",&amountt);
                fp=fopen("filename.txt","r");
                fread(&user,sizeof(user),1,fp);
                fclose(fp);
                fp=fopen("filename.txt","w");
                user.amount+=amountt;
                fwrite(&user,sizeof(user),1,fp);
                fclose(fp);
                printf("\n %d.thaka  have been added your account with sucess",amountt);
                printf("\n\t\t your new balance is %d.thaka",user.amount);
                printf("\n\n\n\n\t\tthank for using BENBANK");
                break;
            case 2 :
                system("cls");
                printf("\n\t\tRETIR");
                printf("\n\t\tenter the amount to withdraw : ");
                scanf("%d",&amountt);
                fp=fopen("filename.txt","r");
                fread(&user,sizeof(user),1,fp);
                fclose(fp);
                fp=fopen("filename.txt","w");

                if(user.amount<amountt)
                {
                    user.amount==user.amount;
                    fwrite(&user,sizeof(user),1,fp);
                    printf("\n\t\tyour money is not enough to make this transaction");
                    printf("\n\t\tplease cheick your balance");
                    printf("\n\n\n\n\t\tthank for using BENBANK");
                    break;
                }
                else
                {
                    user.amount-=amountt;
                    fwrite(&user,sizeof(user),1,fp);
                    printf("\nyour %d.taka have been debited with sucess",amountt);
                printf("\n\t\t your new balance is %d.thaka",user.amount);
                printf("\n\n\n\n\t\tthank for using BENBANK");

                }
                fclose(fp);
                break;
            case 3 :
                printf("\n\t\tCHEICK YOUR BALANCE");
                fp=fopen("filename.txt","r");
                fread(&user,sizeof(user),1,fp);
                printf("\n\t\tyour balance is %d.taka",user.amount);
                fclose(fp);
                break;
            case 4 :
                system("cls");
                printf("\n\t\tBILL PAYEMENT");
               printf("\n\n\t\t1-bill water");
                printf("\n\t\t2-bill electricity");
                printf("\n\t\t3-bill canal+");
                printf("\n\t\tenter your choice : ");
                scanf("%d",&choice);
                if(choice==1)
                {
                    system("cls");
                    printf("\n\n\t\tbill water");
                    printf("\n\n\t\tenter code of water bill : ");
                    scanf("%s",billcw);
                    printf("\n\t\tenter the amount to pay : ");
                    scanf("%d",&amountt);
                    fp=fopen("filename.txt","r");
                    fread(&user,sizeof(user),1,fp);
                    fclose(fp);
                    fp=fopen("filename.txt","w");
                    if(user.amount<amountt)
                {
                    user.amount==user.amount;
                    fwrite(&user,sizeof(user),1,fp);
                    printf("\n\t\tyour money is not enough to make this transaction");
                    printf("\n\t\tplease cheick your balance");
                    break;
                }
                else
                {
                    user.amount-=amountt;
                    fwrite(&user,sizeof(user),1,fp);
                }

                    fclose(fp);
                    printf("\n\n\t\tyour water bill have paid with succes");
                    printf("\nyour account have been debited of %d.thaka with sucess",amountt);
                    printf("\n\t\t your new balance is %d.thaka",user.amount);
                    printf("\n\n\n\n\t\tthank for using BENBANK");
                }
                else
                {
                    if(choice==2)
                    {
                        system("cls");
                        printf("\n\n\t\tbill electricity");
                        printf("\n\n\t\tenter code of electricity bill : ");
                        scanf("%s",billce);
                        printf("\n\t\tenter the amount to pay : ");
                        scanf("%d",&amountt);
                        fp=fopen("filename.txt","r");
                        fread(&user,sizeof(user),1,fp);
                        fclose(fp);
                        fp=fopen("filename.txt","w");
                        if(user.amount<amountt)
                {
                    user.amount==user.amount;
                    fwrite(&user,sizeof(user),1,fp);
                    printf("\n\t\tyour money is not enough to make this transaction");
                    printf("\n\t\tplease cheick your balance");
               break;
                }
                else
                {
                    user.amount-=amountt;
                    fwrite(&user,sizeof(user),1,fp);
                }
                        fclose(fp);
                        printf("\n\n\t\tyour electricity bill have paid with succes");
                        printf("\nyour account have been debited of %d.thaka with sucess",amountt);
                        printf("\n\t\t your new balance is %d.thaka",user.amount);
                        printf("\n\n\n\n\t\tthank for using BENBANK");

                    }
                    else
                    {
                        if(choice==3)
                        {
                            system("cls");
                            printf("\n\n\t\tbill canal+");
                            printf("\n\n\t\tenter code of canal+ bill : ");
                            scanf("%s",billcc);
                            printf("\n\t\tenter the amount to pay : ");
                            scanf("%d",&amountt);
                            fp=fopen("filename.txt","r");
                            fread(&user,sizeof(user),1,fp);
                            fclose(fp);
                            fp=fopen("filename.txt","w");
                            if(user.amount<amountt)
                {
                    user.amount==user.amount;
                    fwrite(&user,sizeof(user),1,fp);
                    printf("\n\t\tyour money is not enough to make this transaction");
                    printf("\n\t\tplease cheick your balance");
                    break;
                }
                else
                {
                    user.amount-=amountt;
                    fwrite(&user,sizeof(user),1,fp);
                }
                            fclose(fp);
                            printf("\n\n\t\tyour canal+ bill have paid with succes");
                            printf("\nyour account have been debited of %d.thaka with sucess",amountt);
                            printf("\n\t\t your new balance is %d.thaka",user.amount);
                            printf("\n\n\n\n\t\tthank for using BENBANK");
                        }
                        else
                        {
                            printf("\n\t\t !!!choice error!!!");
                        }
                    }
                }
                break;
            case 5:
                system("cls");
                printf("\n\t\tMONEY TRANSFER");
                printf("\n\n\t\tenter the account number : ");
                scanf("%s",accnum);
                printf("\n\t\tenter the amount to transfer : ");
                scanf("%d",&amountt);
                fp=fopen("filename.txt","r");
                fread(&user,sizeof(user),1,fp);
                fclose(fp);
                fp=fopen("filename.txt","w");
                if(user.amount<amountt)
                {
                    user.amount==user.amount;
                    fwrite(&user,sizeof(user),1,fp);
                    printf("\n\t\tyour money is not enough to make this transaction");
                    printf("\n\t\tplease cheick your balance");
                     break;
                }
                else
                {
                    user.amount-=amountt;
                    fwrite(&user,sizeof(user),1,fp);
                }
                fclose(fp);
                printf("\nyour %d.taka have been debited with sucess",amountt);
                printf("\n\n");
                fp=fopen("filename.txt","r");
                fread(&user,sizeof(user),1,fp);
                fclose(fp);
                //another account
                fp=fopen("filename.txt","w");  //file must be change for the beneficiare
                user.amount+=amountt;
                fwrite(&user,sizeof(user),1,fp);
                fclose(fp);
                printf("\n\n\nyour %d.taka have been transfered in your account%s with sucess",amountt,accnum);
                break;
            case 6 :
                system("cls");
                printf("\n\t\tCHANGE YOUR PASSWORD");
                 printf("\n\n\t\tenter your user name : ");
                scanf("%s",usname);
                fp=fopen("filename.txt","r");
                fread(&user,sizeof(user),1,fp);
                fclose(fp);
                if(strcmp(usname,user.username)==0)
                {
                    printf("\n\t\tenter the old password : ");
                    scanf("%s",passw);
                    fp=fopen("filename.txt","r");
                    fread(&user,sizeof(user),1,fp);
                    fclose(fp);
                    if(strcmp(passw,user.password)==0)
                    {
                        printf("\n\t\tenter the new password : ");
                        scanf("%s",npassw);
                        strcpy(user.password,npassw);
                        fp=fopen("filename.txt","w");
                        fwrite(&user,sizeof(user),1,fp);
                        printf("\n\t\tSuccesfully registered");
                        fclose(fp);
                    }
                    else
                    {
                        printf("\n\t\twrong password");
                    }
                }
                else
                {
                    printf("\n\n\t\t!!!wrong user name!!!");
                }
                break;
            default :
                printf("\nenter a valid choice");

            }

        }
        else
        {
            printf("\npassword error");
        }


    }
    else
    {
        printf("account number error");
    }
}
