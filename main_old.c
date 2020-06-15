#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>

// #include <pthread.h>

struct info{
    char* userID;
    char* name;
    int exp;
    int hunger;
    int time;//like day1, day2... day 10 -> finish
    int item;
    int money;
};
typedef struct info Info;

int status(Info *info){
    printf("=====DAMAGOCHI : %s 's STATUS======\n", info->name);
    printf("EXP: [");
    for(int i=0; i<info->exp/5; i++) printf("=");

    printf("]   100/%d \n", info->exp);

    printf("Hunger: [");
    for(int i=0; i<info->hunger/5; i++) printf("=");
    printf("]   100/%d \n", info->hunger);

    // printf("Damagochi name: %s\n",info->name );
    // printf("Exp: %d\n",info->exp);
    // printf("Hunger: %d\n",info->hunger );
    printf("Money: %d\n",info->money );
    printf("item: %d\n",info->item );
    
    return 0;
}
int clear_status(Info *info){
    info->exp=0;
    info->time=0;
    info->item=1;
    info->hunger=100;
    info->money=10;
    return 0;
}

void clear(){printf("\n\n\n\n\n\n\n\n\n\n");}
//funcion Declaration
int market(Info *info)
{
    int money=info->money;
    printf("%d\n",money);
   clear();
   //(윗화면 그래픽1.칼 2.화살 3.총 4.도끼)
   char item;
   printf("1.Sword($10, +LV.3) 2.Arrow($15, +LV.5) 3.Gun($20, +LV.7) 4.Ax($3,+LV.2)\n\n");
   printf("What do you want to buy?\n");
   printf("press 'x' key to back to menu!!\n\n");
   scanf(" %c",&item);
   switch(item-'0')
   {
      case 1:
        if(money<10){
            printf("less money....\n");
            sleep(2);
            return 0;
        }
         info->item+=3;
         info->money-=10;
         printf("Got a sword!!\n");
         break;
      case 2:
        if(money<15){
            printf("less money....\n");
            sleep(2);
            return 0;
        }
         info->item+=5;
         info->money-=15;
         printf("Got a arrow!!\n");
         break;
      case 3:
        if(money<20){
            printf("less money....\n");
            sleep(2);
            return 0;
        }
         info->item+=7;
         info->money-=20;
         printf("Got a gun!!\n");
         break;
      case 4:
        if(money<3){
            printf("less money....\n");
            sleep(2);
            return 0;
        }
         info->item+=2;
         info->money-=3;
         printf("Got a ax!!\n");
         break;
      case 40:
      case 72:
         printf("Moving to menu...\n");
              sleep(2);   
         return 0;
      default:
         printf("Wrong choice!!\n");
         return -1;
   }
   sleep(2);
   return 0;
}

int food(Info *info)
{
   clear();
    int money=info->money;
   //(윗화면 그래픽 1.튜나 2. 스팸 3.라면 4. 사료)
   char key;
   printf("1.TUNA(-$5,+5) 2.SPAM(-$5,+5) 3.Spaghetti(-$10,+10) 4.Feed(-$1,+1)\n\n");
   printf("What do you want to buy?\n");
   printf("press 'x' key to back to menu!!\n\n");
   scanf(" %c",&key);
   switch(key-'0')
   {
      case 1:
        if(money<5){
            printf("less money....\n");
            sleep(2);
            return 0;
        }
         info->hunger+=5;
         info->money-=5;
         printf("eating TUNA...\n");
         break;
      case 2:
        if(money<5){
            printf("less money....\n");
            sleep(2);
            return 0;
        }
         info->hunger+=5;
         info->money-=5;
         printf("eating SPAM...\n");
         break;
      case 3:
        if(money<10){
            printf("less money....\n");
            sleep(2);
            return 0;
        }
         info->hunger+=10;
         info->money-=10;
         printf("eating Spaghetti...\n");
         break;
      case 4:
        if(money<1){
            printf("less money....\n");
            sleep(2);
            return 0;
        }
         info->hunger+=1;
         info->money-=1;
         printf("eating Feed...\n");
         break;
      case 40:
      case 72:
         return 0;
      default:
         printf("Wrong choice!!\n");
         return -1;
   }
   printf("Finish!!");
   sleep(2);
   
}



int hunting(Info *info){
    clear();

    //printf("Hunting...........................\n\n");
    //sleep (2);

    int hunger = info->hunger;
    int money = info->money;
    int exp = info->exp;
    int item = info->item;
    //char back;

    if(hunger<10){
       printf(" Too hungry to hunt ... \n");
       printf(" Go get some food ... \n");
       printf(" \" %s \" is starving ... \n",info->name);
       printf(" Back to menu without hunting ... \n");
       //printf(" Back to menu? (N/Y) ");
       //scanf("%s",&back);
       //if(back == 'N')
       sleep(5);
       return 0;
    }

    printf("Hunting..............\n\n");
    sleep (5);

    hunger=hunger-10;
    //hunger =- 91; //to check code when hungry<10
    info->hunger = hunger;
    printf("hunger : %d", hunger);

    info->money = money+(item*5);
    info->exp = exp+(item*5);
    //info->money = money;
    return 0;
}


// int market(Info *info)
// {
//    //clear();
//    //(윗화면 그래픽1.칼 2.화살 3.총 4.도끼)
//    int item;
//    printf("1.Sword($10, +LV.3) 2.Arrow($15, +LV.5) 3.Gun($20, +LV.7) 4.Ax($3,+LV.2)\n\n");
//    printf("What do you want to buy?\n");

//    scanf("%d",&item);
//    getchar();
//    switch(item)
//    {
//       case 1:
//          info->item+=3;
//          info->money-=10;
//          printf("Got a sword!!\n");
//          break;
//       case 2:
//          info->item+=5;
//          info->money-=15;
//          printf("Got a arrow!!\n");
//          break;
//       case 3:
//          info->item+=7;
//          info->money-=20;
//          printf("Got a gun!!\n");
//          break;
//       case 4:
//          info->item+=2;
//          info->money-=3;
//          printf("Got a ax!!\n");
//          break;
//       case 40:
//       case 72:
//          printf("Moving to menu...\n");
//               sleep(2);   
//          return 0;
//       default:
//          printf("Wrong choice!!\n");
//          return -1;
//    }
//    sleep(2);
//    //clear();
//    return 0;
// }
void savefile(Info *info, int fd_new) {        //save game, save file to directiory and return
    clear();
    printf("savefile function!\n");
    char temp[50];
    sprintf(temp, "%s/%d/%d/%d",info->name, info->hunger, info->money, info->item);
    write(fd_new, temp, strlen(temp));
    sleep(1);
}



// int food(Info *info){
//     clear();
//     printf("Bap mu ger!!!========================== 20 GOLD needed !!!!!===========\n\n\n");
//     sleep(1);
//     int hunger = info->hunger;
//     hunger= hunger+20;
//     int money = info->money;
//     money = money - 10;
//     printf("press 'x' key to back to menu!!\n\n");
//     char xkey;
//     scanf(" %s", &xkey);
//     if(xkey=='x'||xkey=='X') return 0;
//     clear();
//     return -1;
// }


// int market(Info *info){
//     clear();
//     int item_num=0;
//     int item = info->item;
//     int money = info->money;
//     int price = 0;
//     printf("item 1, 2, 3, 4,5...... what do you want to buy?\n");
//     printf("1 is 5 gold, 2 is 10 gold, 3 is 15 gold! \n");
//     scanf("%d", &item);
//     price = item * 5;
//     if(money-price<0){
//         printf("this item is %d GOLD, You have not enough money!\n", price);
//     }
//     else if(money>=price){
//         item = item + item_num;
//         info->item = item;
//         money = money - price;
//     }
//     return 0;
// }

// void savefile(Info *info, int fd_new){        //save game, save file to directiory and return
//     clear();
//     printf("savefile function!\n");
//     printf("\n");
//     write(fd_new, info, sizeof(info));
// }


// void savegame(){
//  printf("savegame fun");
//  printf("\n");
// }
void help(){
    clear();
    printf("game discription");
    printf("\n");printf("\n");
}


int gamemain(Info *info, int fd_new){
    clear();

    int select =0;
    while(1){
        clear();
        printf("this is main game function");
        printf("\n");
        status(info);//print character status

        printf("what do you want to do? type number!!\n\n\n\n\nGAMEMAIN GRAPIC IMPLEMENTATION\n\n\n\n");
        printf("1. food \n2. hunting\n3. market\n4. savegmme >>  ");
        scanf("%d", &select);
        int chk=0;
        int tid;     //thread pid
        clear();
        if(select == 1){//error detection hal geot
            food(info);
            if(chk == -1){
                return -1;
                //error occured!!! return -1
            }
        }
        else if(select == 2){
            hunting(info);
            if(chk == -1) return -1;
            
        }
        else if(select == 3){
            market(info);
            if(chk== -1) return -1;
        }
        else if(select == 4){
            // pthread_create(tid, NULL, savegame(info, fd_new));       //thread!!!
            // print("thread created:%d, wait for thread..", tid);
            // pthread_join(tid, NULL);
            // sleep(2);
            savefile(info, fd_new);
            printf("Save game\n");
            sleep(2);
        }
        else if( 0 > select|| select > 4 ) printf("wrong command!!!: %d", select);
        //scanf + switch 
    }
    return 0;
}

int newgame(Info *info){//new game, call gamemain
    int fd_new=0;
    char savefile_path[50] = "./data/";
    char savefile_name[10];
    char damagochi_name[10];                 //character name
    clear();    
    // printf("new game test!!!!!!!!!!");
    printf("\n");
    
    printf("Type username >>  ");
    scanf("%s", savefile_name);
    strncat(savefile_path, savefile_name, strlen(savefile_name));    //strncat()?
    strcat(savefile_path, ".txt");
    // printf("%s\n", savefile_path);
    // sleep(2);
    printf("Type your DAMAGOCHI NAME(under 10 character) >>  ");
    scanf("%s", damagochi_name);
    info->name=damagochi_name;
    // printf("%s\n", info->name);
    // sleep(2);               //debug
    clear_status(info);
    
    fd_new=open(savefile_path, O_RDWR | O_CREAT, 00777);
    gamemain(info, fd_new);
    
}



void loadgame(Info *info){
    clear();

    DIR *dir;
    struct dirent *dir_file;
    struct stat statbuf;
    char * filename;
    char username[10];
   
    dir = opendir("./data");
    if(NULL != dir)
    {
       printf("----------------------------\n");
       while(dir_file=readdir(dir))
       {
          filename = dir_file->d_name;    
          stat(filename,&statbuf);   
          printf("\n   %s >> %s", filename, ctime(&statbuf.st_mtime));
       }
       printf("\n-----------------------------");
       closedir(dir);
    }
     else { //if file loading goes wrong
        printf("  CANNOT LOAD PREVIOUS FILES.\n   START A NEW GAME !\n");
        sleep(3);
        newgame(info);//fd open => new game cher rom dong jack
        }

    printf("\n\n\n Choose your username  >> ");
    scanf("%s", username);

    clear();
    
    printf("\n\n\n   Loading  \" %s \"  's memory...\n",username);
    sleep(2);
    printf("\n\n\n   WELCOME BACK !\n\n\n");

    char loadfile_path[50] = "./data/";
    strcat(loadfile_path, username);
    strcat(loadfile_path, ".txt");
    int fd_load = open(loadfile_path, O_RDWR);
   // strtokenizing
    char datatemp[50];
    read(fd_load, &datatemp , sizeof(datatemp));
    printf("%s", datatemp);
    sleep(2);
    info->name=strtok(datatemp, "/");
    info->hunger = atoi(strtok(NULL, "/"));
    info->money = atoi(strtok(NULL, "/"));
    info->item = atoi(strtok(NULL, "/"));

    gamemain(info, fd_load);

    //loading the chosen file 

}


    // char *main[100] = {"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
    //                      "┃                                                                              ┃\n",
    //                      "┃                                                                              ┃\n",
    //                      "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
    //                      "┃                                                                              ┃\n",
    //                      "┃                                                                              ┃\n",
    //                      "┃                                                                              ┃\n",
    //                      "┃                                                                              ┃\n",
    //                      "┃                                                                              ┃\n",
    //                      "┃                                                                              ┃\n",
    //                      "┃                                                                              ┃\n",
    //                      "┃                                                                              ┃\n",
    //                      "┃                                                                              ┃\n",
    //                      "┃                                                                              ┃\n",
    //                      "┃                                                                              ┃\n",
    //                      "┃                                                                              ┃\n",
    //                      "┃                                                                              ┃\n",
    //                      "┃                                                                              ┃\n",
    //                      "┃                                                                              ┃\n",
    //                      "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
    //                      "┃                                                                              ┃\n",
    //                      "┃                                                         <made by team Italy> ┃\n",
    //                      "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};       


void cui_dama_start(){
    char *main_l[100] = {"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                         "┃                     PLEASE RESISE YOUR SHELL SCALE                           ┃\n",
                         "┃                                                                              ┃\n",
                         "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                     PLEASE RESISE YOUR SHELL SCALE                           ┃\n",
                         "┃                                [80 X 24]                                     ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                ┏━━━━━━━┓                                     ┃\n",
                         "┃                                ┃ ■ ■   ┃  │                                  ┃\n",
                         "┃                             ┌──┨ ┌──┐  ┠──┘                                  ┃\n",
                         "┃                             │  ┃ └──┘  ┃                                     ┃\n",
                         "┃                                ┗━━━━━━━┛                                     ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                         "┃                                                                              ┃\n",
                         "┃                                                         <made by team Italy> ┃\n",
                         "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};

    char *main_r[100] = {"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                         "┃                      PLEASE RESISE YOUR SHELL SCALE                          ┃\n",
                         "┃                                                                              ┃\n",
                         "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                      PLEASE RESISE YOUR SHELL SCALE                          ┃\n",
                         "┃                                [80 X 24]                                     ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                ┏━━━━━━━┓                                     ┃\n",
                         "┃                             │  ┃  ■ ■  ┃                                     ┃\n",
                         "┃                             └──┨ ┌──┐  ┠──┐                                  ┃\n",
                         "┃                                ┃ └──┘  ┃  │                                  ┃\n",
                         "┃                                ┗━━━━━━━┛                                     ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                         "┃                                                                              ┃\n",
                         "┃                                                         <made by team Italy> ┃\n",
                         "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};                         
    char * dama_nomal[20]
                        ={
                          "┏━━━━━━━┓\n",
                          "┃  ■ ■  ┃\n",                           
                          "┃  ┌─┐  ┃\n",
                          "┃  └─┘  ┃\n",                        
                          "┗━━━━━━━┛\n"};

    //printf  ("┏━━━━━━━━┓\n┃        ┃\n┃  ■  ■  ┃\n┃  ┌──┐  ┃\n┃  └──┘  ┃\n┗━━━━━━━━┛\n");
    for(int j=0; j<2; j++){
        for(int i=0; i<23; i++)
            printf("%s", main_l[i] );
        sleep(1);
        for(int i=0; i<23; i++)
            printf("%s", main_r[i]);
        sleep(1);
    }
}
int cui_dama_main(){
        char *main[100]={       "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                                "┃                                                                              ┃\n",
                                "┃                 __  ___      __  ___          __                             ┃\n",
                                "┃                /  |/  /_  __/  |/  /___ _____/ /                             ┃\n",
                                "┃               / /|_/ / / / / /|_/ / __ `/ __  /                              ┃\n",
                                "┃              / /  / / /_/ / /  / / /_/ / /_/ /                               ┃\n",
                                "┃             /_/  /_/\\__, /_/  /_/\\__,_/\\__,_/                                ┃\n",            
                                "┃                    /____/                                                    ┃\n",
                                "┃                 ____                                         __    _         ┃\n",
                                "┃                / __ \\____ _____ ___  ____ _____ _____  _____/ /_  (_)        ┃\n",
                                "┃               / / / / __ `/ __ `__ \\/ __ `/ __ `/ __ \\/ ___/ __ \\/ /         ┃\n",
                                "┃              / /_/ / /_/ / / / / / / /_/ / /_/ / /_/ / /__/ / / / /          ┃\n",
                                "┃             /_____/\\__,_/_/ /_/ /_/\\__,_/\\__, /\\____/\\___/_/ /_/_/           ┃\n",
                                "┃                                         /____/                               ┃\n",     
                                "┃                 ____  _                                                      ┃\n",
                                "┃                / __ \\(_)___ ________  __                                     ┃\n",
                                "┃               / / / / / __ `/ ___/ / / /                                     ┃\n",
                                "┃              / /_/ / / /_/ / /  / /_/ /                                      ┃\n",
                                "┃             /_____/_/\\__,_/_/   \\__, /                                       ┃\n",
                                "┃                                /____/                                        ┃\n"
                                "┃                                                                              ┃\n",
                                "┃                                                         <made by team Italy> ┃\n",
                                "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"
                                };

                        //  "┃                                                                              ┃\n",
                        //  "┃                                                                              ┃\n",
                        //  "┃                                                                              ┃\n",
                        //  "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                        //  "┃                                                                              ┃\n",
                        //  "┃                                                         <made by team Italy> ┃\n",
                        //  "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"}; 
                        //  1. NEW GAME

        for(int i=0; i<22; i++)
            printf("%s", main[i] );
        sleep(3);

}
    void cui_dama_menuselect(){//mainmenu select
    
    char *main_menu[100]={"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                          "┃                                <MAIN MENU>                                   ┃\n",
                          "┃                                                                              ┃\n",
                          "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                          "┃                                                                              ┃\n",
                          "┃                                                                              ┃\n",
                          "┃                                                                              ┃\n",
                          "┃                          <My Mad Damagochi Diary>                            ┃\n",
                          "┃                                                                              ┃\n",
                          "┃                                                                              ┃\n",
                          "┃                                1. NEW GAME                                   ┃\n",
                          "┃                                                                              ┃\n",
                          "┃                                2. LOAD GAME                                  ┃\n",
                          "┃                                                                              ┃\n",
                          "┃                                3. HELP                                       ┃\n",
                          "┃                                                                              ┃\n",
                          "┃                                                                              ┃\n",
                          "┃                                                                              ┃\n",
                          "┃                                                                              ┃\n",
                          "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                          "┃                                                                              ┃\n",
                          "┃ SELECT MENU!                                            <made by team Italy> ┃\n",
                          "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};       
        for(int i=0; i<23; i++)
            printf("%s", main_menu[i] );
    

    }
    void cui_action(){
        char* action_menu[100]={"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                                "┃                               STATUS AREA!!!                                ┃\n",
                                "┃                                                                             ┃\n",
                                "┃━━━━━━━━┓━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┏━━━━━━━━┓━━━━━━━━━━━━━━━━━━━━━━━┃\n",
                                "┃ market ┃                      ┃            ┃ food   ┃ ┓        ━━━┓         ┃\n",
                                "┃━━━━━━━━┛        ━━━┓          ┃            ┃━━━━━━━━┛┃  ┓  ┏━━━━━━━━━━━┓    ┃\n",
                                "┃           ━━━┓     ┃          ┃            ┃         ┃ ┃  ┓┃    ┓    ■ ┃    ┃\n",
                                "┃           ───╉─────╉──▶       ┃            ┃         ┃ ┃  ┛┃    ┛      ┃⊃   ┃\n",
                                "┃           ━━━┛     ┃          ┃            ┃         ┃  ┛  ┗━━━━━━━━━━━┛    ┃\n",
                                "┃                 ━━━┛          ┃  ┏━━━━━━━┓ ┃          ┛                     ┃\n",
                                "┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛  ┃ ■  ■  ┃ ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n",
                                "┃                                  ┃ ┌──┐  ┃                                  ┃\n",
                                "┃                                  ┃ └──┘  ┃                                  ┃\n",
                                "┃━━━━━━━━┓━━━━━━━━━━━━━━━━━━━━━━┓  ┗━━━━━━━┛ ┏━━━━━━━━┓━━━━━━━━━━━━━━━━━━━━━━━┃\n",
                                "┃hunting ┃      /\\              ┃            ┃ save   ┃   ┏━━━━━━━━━━━━━┓     ┃\n",
                                "┃━━━━━━━━┛     /  \\             ┃            ┃━━━━━━━━┛   ┃  ┏━━━━━━━┓  ┃     ┃\n",
                                "┃              │  │             ┃            ┃            ┃  ┗━━━━━━━┛  ┃     ┃\n",
                                "┃              │  │             ┃            ┃            ┃           ◎ ┃     ┃\n",
                                "┃            ┌─└──┘─┐           ┃            ┃            ┃             ┃     ┃\n",
                                "┃            └─│  │─┘           ┃            ┃            ┗━━━━━━━━━━━━━┛     ┃\n",
                                "┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n",
                                "┃                          COMMAND AREA!!!!!!!!                               ┃\n",
                                "┃                                                                             ┃\n",
                                "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};
        for(int i=0; i<23; i++)
            printf("%s", action_menu[i]);                        
    }
int main(){  
    Info *info;
    // cui_dama_main();
    // cui_dama_start();           //cui main!
    int menu_select = 0;
    mkdir("./data", 00777);
    while(1){
    cui_dama_menuselect();
    printf(">> ");
    scanf("%d", &menu_select);

        switch (menu_select){
            case 1:
                newgame(info);
                break;
            case 2:
                loadgame(info);
                break;
            case 3:
                help();
                break;
            default: printf("unknown input \n");
        }
    }
    return 0;
}   