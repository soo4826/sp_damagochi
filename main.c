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

void cui_status(Info *info){
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃                   ===== DAMAGOCHI%10s 's STATUS ====                   ┃\n", info->name );
    char exp_ctemp[20];
    // char exp_cctemp[20];
    char exp_itemp[10];
    char exp_out[40];
    strcat(exp_ctemp, "EXP: [");
    for(int i=0; i<info->exp/5; i++)    strcat(exp_ctemp, "=");
    // sprintf(exp_ctemp, "%s", exp_cctemp);
    // strcat(exp_ctemp, " ]");
    // strcat(exp_out, )
    sprintf(exp_out, "EXP : [%-20s]", exp_ctemp);
    sprintf(exp_itemp, "[%3d/100]", info->exp);
    strcat(exp_out, exp_itemp);

    char hunger_itemp[20];
    char hunger_out[10];
    char hunger_ctemp[40];
    for(int i=0; i<info->hunger/5; i++) strcat(hunger_ctemp, "=");
    sprintf(hunger_out, "Huger : [%-20s]", hunger_ctemp);
    sprintf(hunger_itemp, "[%3d/100]", info->hunger);
    strcat(hunger_out, hunger_itemp);

    printf("┃%38s%38s┃\n", exp_out, hunger_out);
    printf("┃ [MONEY : %5d Gold]   [Item : %2d]                                           ┃\n", info->money, info->item);
      
}

    void cui_action(){  
        char* action_menu[100]={/*"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                                "┃                                STATUS AREA!!!                                ┃\n",
                                "┃                                                                              ┃\n",
                                "┃                                                                              ┃\n",*/
                                "┃━━━━━━━━┓━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┏━━━━━━━━┓━━━━━━━━━━━━━━━━━━━━━━━┃\n",
                                "┃ market ┃                       ┃            ┃ food   ┃ ┓        ━━━┓         ┃\n",
                                "┃━━━━━━━━┛        ━━━┓           ┃            ┃━━━━━━━━┛┃  ┓  ┏━━━━━━━━━━━┓    ┃\n",
                                "┃           ━━━┓     ┃           ┃            ┃         ┃ ┃  ┓┃    ┓    ■ ┃    ┃\n",
                                "┃           ───╂─────╂──▶        ┃            ┃         ┃ ┃  ┛┃    ┛      ┃⊃   ┃\n",
                                "┃           ━━━┛     ┃           ┃            ┃         ┃  ┛  ┗━━━━━━━━━━━┛    ┃\n",
                                "┃                 ━━━┛           ┃  ┏━━━━━━━┓ ┃          ┛                     ┃\n",
                                "┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛  ┃ ■  ■  ┃ ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n",
                                "┃                                   ┃ ┌──┐  ┃                                  ┃\n",
                                "┃━━━━━━━━┓━━━━━━━━━━━━━━━━━━━━━━━┓  ┃ └──┘  ┃ ┏━━━━━━━━┓━━━━━━━━━━━━━━━━━━━━━━━┃\n",
                                "┃hunting ┃      /\\               ┃  ┗━━━━━━━┛ ┃ save   ┃   ┏━━━━━━━━━━━━━┓     ┃\n",
                                "┃━━━━━━━━┛     /  \\              ┃            ┃━━━━━━━━┛   ┃  ┏━━━━━━━┓  ┃     ┃\n",
                                "┃              │  │              ┃            ┃            ┃  ┗━━━━━━━┛  ┃     ┃\n",
                                "┃              │  │              ┃            ┃            ┃           ◎ ┃     ┃\n",
                                "┃            ┌─└──┘─┐            ┃            ┃            ┃             ┃     ┃\n",
                                "┃            └─│  │─┘            ┃            ┃            ┗━━━━━━━━━━━━━┛     ┃\n",
                                "┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n",
                                "┃             CHOOSE ACTION! [1.Market  2.Hunting  3.Food  4.Save]             ┃\n",
                                "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};
                                //┗━━━━━━━┛
        for(int i=0; i<19; i++)
            printf("%s", action_menu[i]);                        
    }


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
    info->exp+=5;
    int money=info->money;


    char *itemmain[100]={"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                         "┃                                 CHOICE ONE!!                                 ┃\n",
                         "┃                      [ press 'x' key to back to menu!! ]                     ┃\n",
                         "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                         "┃                    __  __    _    ____ _____ _  _______ _____                ┃\n",
                         "┃                   |  \\/  |  / \\  |  _ \\_   _| |/ / ____|_   _|               ┃\n",
                         "┃                   | |\\/| | / _ \\ | |_) || | | ' /|  _|   | |                 ┃\n", 
                         "┃                   | |  | |/ ___ \\|  _ < | | | . \\| |___  | |                 ┃\n",  
                         "┃                   |_|  |_/_/   \\_\\_| \\_\\|_| |_|\\_\\_____| |_|                 ┃\n",                 
                         "┃                                                                              ┃\n",
                         "┃    SWORD ($10,+LV.3)    ARROW($15,+LV5)    GUN($20,+LV.7)     AX($3, +LV.2)  ┃\n",
                         "┃          /\\                  \\                                 ┌──────/──┐   ┃\n",
                         "┃         |  │                 |\\           ┌─────────────┐      │      \\  │   ┃\n",
                         "┃         |  │                 | \\          │   ───────── ]      │      /  │   ┃\n",
                         "┃         |  │                 |  \\         │   ⊇┌────────┘      │ ┌────\\──┘   ┃\n",
                         "┃         |  │          》》――――――――――▶     │ ┌─┘                │ │           ┃\n",
                         "┃         |  │                 |  /         │ │                  │ │           ┃\n",
                         "┃      ┌──┘──└──┐              | /          │ │                  │ │           ┃\n",
                         "┃      └──┐──┌──┘              |/           └─┘                  │ │           ┃\n",
                         "┃         └──┘                 /                                 └─┘           ┃\n",
                         "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                         "┃ 1.SWORD 2.ARROW 3.GUN 4.AX                              <made by team Italy> ┃\n",
                         "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};       
   
   //(윗화면 그래픽1.칼 2.화살 3.총 4.도끼) wrong choice impl needed
    for(int i=0; i<23; i++) printf("%s", itemmain[i]);
    char* main_nomoney[100];
    char* main_buy[100];
    char buy_temp[10];
    for(int i=0; i<23; i++){
        main_nomoney[i]=itemmain[i];
        main_buy[i]=itemmain[i];
    }
    main_nomoney[21]=     "┃   Not Enough money!                                     <made by team Italy> ┃\n";
    main_buy[21]         ="┃   Purchasing....                                        <made by team Italy> ┃\n";
    char item;  
    // char* item_arr[4] = {"SWORD", "ARROW", "GUN", "AX"};
    printf(">> ");
    scanf(" %c",&item);
    // strcat(main_buy[21], "Got a ");
    // sprintf(buy_temp, "%5s", item_arr[item-'0'-1]);
    // strcat(main_buy[21], buy_temp);
    // strcat(main_buy[21], "                     <made by team Italy> ┃\n");
    switch(item-'0')
    {
        case 1:
            if(money<10){
                for(int i=0; i<23; i++) printf("%s", main_nomoney[i]);
                sleep(2);
                return 0;
            }
            info->item+=3;
            info->money-=10;
            for(int i=0; i<23; i++) printf("%s", main_buy[i]);
            break;
        case 2:
            if(money<15){
                for(int i=0; i<23; i++) printf("%s", main_nomoney[i]);
                sleep(2);
                return 0;
            }
            info->item+=5;
            info->money-=15;
            for(int i=0; i<23; i++) printf("%s", main_buy[i]);
            break;
        case 3:
            if(money<20){
                for(int i=0; i<23; i++) printf("%s", main_nomoney[i]);
                sleep(2);
                return 0;
            }
            info->item+=7;
            info->money-=20;
            for(int i=0; i<23; i++) printf("%s", main_buy[i]);
            break;
        case 4:
            if(money<3){
                for(int i=0; i<23; i++) printf("%s", main_nomoney[i]);
                sleep(2);
                return 0;
            }
            info->item+=2;
            info->money-=3;
            for(int i=0; i<23; i++) printf("%s", main_buy[i]);
            break;
        case 40:
        case 72:
            // printf("Moving to menu...\n");
            //     sleep(2);   
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
    info->exp+=5;
    int money=info->money;
    char *main[100]  =  {"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                         "┃                                 CHOICE ONE!!                                 ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                      [ press 'x' key to back to menu!! ]                     ┃\n",
                         "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                         "┃                        _____    ___     ___    ____                          ┃\n",
                         "┃                       |  ___|  / _ \\   / _ \\  |  _ \\                         ┃\n",
                         "┃                       | |_    | | | | | | | | | | | |                        ┃\n",
                         "┃                       |  _|   | |_| | | |_| | | |_| |                        ┃\n",
                         "┃                       |_|      \\___/   \\___/  |____/                         ┃\n",
                         "┃                                                                              ┃\n",
                         "┃  ┏━━━━━━━━━━━━━━━━┓   ╭───────────────╮                                      ┃\n",
                         "┃  ┃                ┃   │               │   ┓        ━━━┓         Feed(-$1,+1) ┃\n",
                         "┃  ┃                ┃   ╰───────────────╯  ┃  ┓  ┏━━━━━━━━━━━┓       □ □       ┃\n",
                         "┃  ┣━━━━━━━━━━━━━━━━┫   │ ───────────── │  ┃ ┃  ┓┃    ┓    ■ ┃      □ □ □      ┃\n",
                         "┃  ┃                ┃   │               │  ┃ ┃  ┛┃    ┛      ┃⊃    □ □□ □□□    ┃\n",
                         "┃  ┃    T U N A     ┃   │    S P A M    │  ┃  ┛  ┗━━━━━━━━━━━┛    □□□ □ □□□ □  ┃\n",
                         "┃  ┃                ┃   │               │   ┛                    ╭──────────╮  ┃\n",
                         "┃  ┃   (-$5, +5)    ┃   │   (-$5, +5)   │       (-$10,+10)       ╰──────────╯  ┃\n",
                         "┃  ┗━━━━━━━━━━━━━━━━┛   ╰───────────────╯        F I S H            F E E D    ┃\n",
                         "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                         "┃ 1.TUNA 2.SPAM 3.Fish 4.Feed                             <made by team Italy> ┃\n",
                         "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};       
    char* main_money[100];
    char* main_eating[100];
    char* main_full[100];

    for(int i=0; i<23; i++){
        main_money[i]=main[i];
        main_full[i]=main[i];
        main_eating[i]=main[i];
    }

    char *food_list[4]={"TUNA", "SPAM", "FISH", "FEED"};
    main_money[21]=     "┃   Not Enough money!                                     <made by team Italy> ┃\n";
    main_full[21]=      "┃   Can't eat! I'm full!!                                 <made by team Italy> ┃\n";
   //(윗화면 그래픽 1.튜나 2. 스팸 3.라면 4. 사료)
   char key;
//    printf("1.TUNA(-$5,+5) 2.SPAM(-$5,+5) 3.Spaghetti(-$10,+10) 4.Feed(-$1,+1)\n\n");
//    printf("What do you want to buy?\n");
//    printf("press 'x' key to back to menu!!\n\n");
    for(int i=0; i<23; i++) printf("%s", main[i]);
    scanf(" %c",&key);   
    
    switch(key-'0')
    {
        case 1:
            if(money<5){
                for(int i=0; i<23; i++) printf("%s", main_money[i]);
                sleep(2);
                return 0;
            }
            else if((info->hunger)+5>100){
                for(int i=0; i<23; i++) printf("%s", main_full[i]);
                break;
            }
            info->hunger+=5;
            info->money-=5;
            main_eating[21]="┃   Eating !!                                             <made by team Italy> ┃\n";
            for(int i=0; i<23; i++) printf("%s", main_eating[i]);
            break;
        case 2:
            if(money<5){
                for(int i=0; i<23; i++) printf("%s", main_money[i]);
                sleep(2);
                return 0;
            }
            else if((info->hunger)+5>100){
                for(int i=0; i<23; i++) printf("%s", main_full[i]);
                break;
            }
            info->hunger+=5;
            info->money-=5;
            main_eating[21]="┃   Eating !!                                             <made by team Italy> ┃\n";
            for(int i=0; i<23; i++) printf("%s", main_eating[i]);
            break;
            break;
        case 3:
            if(money<10){
                for(int i=0; i<23; i++) printf("%s", main_money[i]);
                sleep(2);
                return 0;
            }
            else if((info->hunger)+10>100){
                for(int i=0; i<23; i++) printf("%s", main_full[i]);
                break;
            }
            info->hunger+=10;
            info->money-=10;
            main_eating[21]="┃   Eating !!                                             <made by team Italy> ┃\n";
            for(int i=0; i<23; i++) printf("%s", main_eating[i]);
            break;
            break;
        case 4:
            if(money<1){
                for(int i=0; i<23; i++) printf("%s", main_money[i]);
                sleep(2);
                return 0;
            }
            else if((info->hunger)+1>100){
                for(int i=0; i<23; i++) printf("%s", main_full[i]);;
                break;
            }
            info->hunger+=1;
            info->money-=1;
            main_eating[21]="┃   Eating !!                                             <made by team Italy> ┃\n";
            for(int i=0; i<23; i++) printf("%s", main_eating[i]);
            break;
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

    //printf("Hunting...........................\n\n");
    //sleep (2);

    int hunger = info->hunger;
    int money = info->money;
    int exp = info->exp;
    int item = info->item;
    char *hunt_1   [100]  =  {"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                              "┃                                                                              ┃\n",
                              "┃                                   Hunting..                                  ┃\n",
                              "┃                                                                              ┃\n",
                              "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃           ┏━━━━━━━┓                                    ┏┓     ┏┓             ┃\n",
                              "┃           ┃  ■ ■  ┃                                    ┃┗━━━━━┛┃             ┃\n",
                              "┃           ┃  ┌─┐  ┃     ◎                              ┃ ▶   ╋ ┃             ┃\n",
                              "┃           ┃  └─┘  ┃                                    ┃   ∇   ┃             ┃\n",
                              "┃           ┗━┳━━━┳━┛                                    ┗━┳━━━┳━┛             ┃\n",
                              "┃             ┃   ┃                                        ┃   ┃               ┃\n",
                              "┃             ┛   ┗                                       ┏╋┓ ┏╋┓              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                              "┃                                                         <made by team Italy> ┃\n",
                              "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"}; 
                               
   char *hunt_2   [100]  =   {"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                              "┃                                                                              ┃\n",
                              "┃                                   Hunting...                                 ┃\n",
                              "┃                                                                              ┃\n",
                              "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃           ┏━━━━━━━┓                                    ┏┓     ┏┓             ┃\n",
                              "┃           ┃  ■ ■  ┃                _                   ┃┗━━━━━┛┃             ┃\n",
                              "┃           ┃  ┌─┐  ┃               (_)                  ┃ ▶   ╋ ┃             ┃\n",
                              "┃           ┃  └─┘  ┃                                    ┃   ∇   ┃             ┃\n",
                              "┃           ┗━┳━━━┳━┛                                    ┗━┳━━━┳━┛             ┃\n",
                              "┃             ┃   ┃                                        ┃   ┃               ┃\n",
                              "┃             ┛   ┗                                       ┏╋┓ ┏╋┓              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                              "┃                                                         <made by team Italy> ┃\n",
                              "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};        
       char *hunt_3[100]  =  {"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                              "┃                                                                              ┃\n",
                              "┃                                   Hunting.                                   ┃\n",
                              "┃                                                                              ┃\n",
                              "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃           ┏━━━━━━━┓                                    ┏┓     ┏┓             ┃\n",
                              "┃           ┃  ■ ■  ┃                          ┌┴┴┴┐     ┃┗━━━━━┛┃             ┃\n",
                              "┃           ┃  ┌─┐  ┃                          ┤ ◆ ├     ┃ ▶   ╋ ┃             ┃\n",
                              "┃           ┃  └─┘  ┃                          └┬┬┬┘     ┃   ∇   ┃             ┃\n",
                              "┃           ┗━┳━━━┳━┛                                    ┗━┳━━━┳━┛             ┃\n",
                              "┃             ┃   ┃                                        ┃   ┃               ┃\n",
                              "┃             ┛   ┗                                       ┏╋┓ ┏╋┓              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┃                                                                              ┃\n",
                              "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                              "┃                                                         <made by team Italy> ┃\n",
                              "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};
                                                                                  
    // char * dama_nomal[20]
    //                     ={
    //                       "┏━━━━━━━┓\n",
    //                       "┃  ■ ■  ┃\n",                           
    //                       "┃  ┌─┐  ┃\n",
    //                       "┃  └─┘  ┃\n",                        
    //                       "┗━━━━━━━┛\n"};

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

    for(int j=0; j<3; j++){
        for(int i=0; i<23; i++)
            printf("%s", hunt_1[i] );
        sleep(1);
        for(int i=0; i<23; i++)
            printf("%s", hunt_2[i]);
        sleep(1);
        for(int i=0; i<23; i++)
            printf("%s", hunt_3[i]);
        sleep(1);
    }

    hunger=hunger-10;
    //hunger =- 91; //to check code when hungry<10
    info->hunger = hunger;
    // printf("hunger : %d", hunger);

    info->money = money+(item*5);
    info->exp = exp+(item*5);
    //info->money = money;
    return 0;
}

// void gameExit(int fd_new){
// 	close(fd_new);
// 	printf("close files and game exit...\n");
// 	sleep(2);
// 	exit();
// }

// void savefile(Info *info, int fd_new) {        //save game, save file to directiory and return
//     int a;
//     clear();
//     printf("1.only save.\n2.save and break.\n");
//     printf("press 'x' key to back to menu!!\n\n");
//     scanf("%d",&a);
//     switch(a)
//     {
//       case 1:
//         printf("savefile function!\n");
//         char temp[50];
//         sprintf(temp, "%s/%d/%d/%d",info->name, info->hunger, info->money, info->item);
//         write(fd_new, temp, strlen(temp));
//         sleep(1);
//         break;
//       case 2:
//         printf("savefile function and exit game...\n");
//         sprintf(temp, "%s/%d/%d/%d",info->name, info->hunger, info->money, info->item);
//         write(fd_new, temp, strlen(temp));
//         sleep(2);
//         gameExit(fd_new);
//         return 0;
//       case 40:
//       case 72:
//          printf("Moving to menu...\n");
//               sleep(2);   
//          return 0;
//       default:
//          printf("Wrong choice!!\n");
//          return -1;
//    }
    
// }
void gameExit(int fd_new){
	close(fd_new);
	printf("Thank you for playing..\n");
	sleep(2);
	exit(0);
}

void savefile(Info *info, int fd_new) {        //save game, save file to directiory and return
    char key;
    char *main[100]  = {"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                        "┃                                                                              ┃\n",
                        "┃                                S A V E  F I L E                              ┃\n",
                        "┃                                                                              ┃\n",
                        "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                        "┃                          ┃                          ┃                        ┃\n",
                        "┃                          ┃                          ┃                        ┃\n",
                        "┃      1) SAVE GAME        ┃    2) SAVE AND BREAK     ┃   X)PRESS 'X'TO EXIT   ┃\n",
                        "┃                          ┃                          ┃                        ┃\n",
                        "┃                  ┏━╆┓    ┃              ⊂⊃          ┃        \\     /         ┃\n",
                        "┃                  ┃ └┃    ┃             (            ┃         \\   /          ┃\n",
                        "┃      ┏━━━━━━━┓   ┗━━┛    ┃              )           ┃          \\ /           ┃\n",
                        "┃      ┃ /\\ /\\ ┃ /         ┃             (            ┃           x            ┃\n",
                        "┃      ┃  ┌─┐  ┃/          ┃          /━━━━\\          ┃          / \\           ┃\n",
                        "┃      ┃  └─┘  ┃           ┃        /━ >  < ━\\        ┃         /   \\          ┃\n",
                        "┃      ┗━━━━━━━┛           ┃      /━    /\\    ━\\      ┃        /     \\         ┃\n",
                        "┃                          ┃                          ┃                        ┃\n",
                        "┃                          ┃                          ┃                        ┃\n",
                        "┃                          ┃                          ┃                        ┃\n",
                        "┃                          ┃                          ┃                        ┃\n",
                        "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                        "┃  Type number!                                           <made by team Italy> ┃\n",
                        "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"}; 
    for(int i=0; i<23; i++) printf("%s", main[i]);
    char* main_save[100];
    char* main_savebreak[100];
    char* main_wrongchoice[100];
    for(int i=0; i<23; i++){
        main_save[i]=main[i];
        main_savebreak[i]=main[i];
        main_wrongchoice[i]=main[i];
    }

    main_save[21]         ="┃  File Saving..                                          <made by team Italy> ┃\n";
    main_savebreak[21]    ="┃  File Saving and quit!                                  <made by team Italy> ┃\n";
    main_wrongchoice[21]  ="┃  Wrong choice!    Type number!                          <made by team Italy> ┃\n";
    char temp[50];
    while (1){
        printf(">> ");
        scanf(" %s",&key);
        switch(key-'0')
        {
            case 1:
                sprintf(temp, "%s/%d/%d/%d",info->name, info->hunger, info->money, info->item);
                write(fd_new, temp, strlen(temp));
                for(int i=0; i<23; i++) printf("%s", main_save[i]);
                sleep(1);
                return;
            case 2:
                sprintf(temp, "%s/%d/%d/%d",info->name, info->hunger, info->money, info->item);
                write(fd_new, temp, strlen(temp));
                for(int i=0; i<23; i++) printf("%s", main_savebreak[i]);
                sleep(2);
                gameExit(fd_new);
                return;
            case 40:
            case 72:
                //  printf("Moving to menu...\n");
                //       sleep(2); back to menu   
                return ;
            default:
                for(int i=0; i<23; i++) printf("%s", main_wrongchoice[i]);
                break;
        }
    }
    
}

void help(){
        char *main[100]  = {"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                            "┃                    This is a game that grows Damagochi!                      ┃\n",
                            "┃                     [Press any key to go back to menu]                       ┃\n",
                            "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",    
                            "┃        This game's goal is to graduate Tamagochi when it fully grows         ┃\n",
                            "┃                                                                              ┃\n",
                            "┃                 Tamagochi graduates when its' EXP is full                    ┃\n",
                            "┃                                                                              ┃\n",
                            "┃         To fill up the hunger level, user should regulary feed Tamagochi     ┃\n",
                            "┃                     The food must be fed through hunting                     ┃\n",
                            "┃                                                                              ┃\n",
                            "┃             User can but items to enhance the effiency of hunting            ┃\n",
                            "┃                                                                              ┃\n",
                            "┃              1. Food: User can buy food with the money he have.              ┃\n",
                            "┃               The degree of hunger is filled due to this activity            ┃\n",
                            "┃           and the degree of hunger is differed by the cost of the food.      ┃\n",
                            "┃                                                                              ┃\n",
                            "┃                 2. Hunting: User should do hunting to get money.             ┃\n",
                            "┃             Items you buy in market enhances the efficiency of hunting       ┃\n",
                            "┃                                                                              ┃\n",
                            "┃                 3. Market: User can buy weapon in the market.                ┃\n",
                            "┃      It enhances efficiency of hunting depending on the cost of the item.    ┃\n",
                            "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};
    for(int i=0; i<23; i++) printf("%s", main[i]);
    char key;
    scanf(" %c", &key);
    
}

void graduation(int fd_new){    
    char *gra_1[100] =  {"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                         "┃                                                                              ┃\n",
                         "┃                ____               _             _           _   _            ┃\n",
                         "┃               / ___|_ __ __ _  __| |_   _  __ _| |_ ___  __| | | |           ┃\n",
                         "┃              | |  _| '__/ _` |/ _` | | | |/ _` | __/ _ \\/ _` | | |           ┃\n",
                         "┃              | |_| | | | (_| | (_| | |_| | (_| | ||  __/ (_| | |_|           ┃\n",
                         "┃               \\____|_|  \\__,_|\\__,_|\\__,_|\\__,_|\\__\\___|\\__,_| (_)           ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                         /──────────────────────────────                      ┃\n",
                         "┃                        /                              /∥                     ┃\n",
                         "┃                       /                              / ∥                     ┃\n",
                         "┃                      ∠───────┳────────────────┳─────/  ∥                     ┃\n",
                         "┃                              ┃                ┃        ∥                     ┃\n",
                         "┃                              ┃                ┃       ┏━┓                    ┃\n",
                         "┃                         ┏━━━━┸━━━━━━━━━━━━━━━━┸━━━┓   ┗━┛                    ┃\n",
                         "┃                    ┃    ┃                         ┃                          ┃\n",
                         "┃                    ┗━━━━┃       ■          ■      ┃━━━━┓                     ┃\n",
                         "┃                         ┃           ┗━━┛          ┃    ┃<made by team Italy> ┃\n",
                         "┗━━━━━━━━━━━━━━━━━━━━━━━━━┸━━━━━━━━━━━━━━━━━━━━━━━━━┸━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"}; 
    char *gra_2[100]  = {"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                                                                              ┃\n",
                         "┃                         /──────────────────────────────                      ┃\n",
                         "┃                        /                              /∥                     ┃\n",
                         "┃                       /                              / ∥                     ┃\n",
                         "┃                      ∠───────┳────────────────┳─────/  ∥                     ┃\n",
                         "┃                              ┃                ┃        ∥                     ┃\n",
                         "┃                              ┃                ┃       ┏━┓                    ┃\n",
                         "┃                         ┏━━━━┸━━━━━━━━━━━━━━━━┸━━━┓   ┗━┛                    ┃\n",
                         "┃                         ┃                         ┃    ┃                     ┃\n",
                         "┃                    ┏━━━━┃       ■   ┏━━┓   ■      ┃━━━━┛                     ┃\n",
                         "┃                    ┃    ┃           ┗━━┛          ┃     <made by team Italy> ┃\n",
                         "┗━━━━━━━━━━━━━━━━━━━━━━━━━┸━━━━━━━━━━━━━━━━━━━━━━━━━┸━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"}; 


    for(int j=0; j<10; j++){
        for(int i=0; i<23; i++)
            printf("%s", gra_1[i] );
        sleep(1);
        for(int i=0; i<23; i++)
            printf("%s", gra_2[i]);
        sleep(1);
    }
    close(fd_new);
    exit(0);
}

void starving(int fd_new){
    char *gra[100] =      { "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                            "┃                                                                              ┃\n",
                            "┃                                                                              ┃\n",
                            "┃                                                                              ┃\n",
                            "┃                ____    _    __  __ _____ _____     _______ ____              ┃\n",
                            "┃               / ___|  / \\  |  \\/  | ____/ _ \\ \\   / / ____|  _ \\             ┃\n",
                            "┃              | |  _  / _ \\ | |\\/| |  _|| | | \\ \\ / /|  _| | |_) |            ┃\n",
                            "┃              | |_| |/ ___ \\| |  | | |__| |_| |\\ V / | |___|  _ <             ┃\n",
                            "┃               \\____/_/   \\_\\_|  |_|_____\\___/  \\_/  |_____|_| \\_\\            ┃\n",
                            "┃                                                                              ┃\n",
                            "┃                                                                              ┃\n",
                            "┃                                                                              ┃\n",
                            "┃                                                                              ┃\n",
                            "┃                        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓                     ┃\n",
                            "┃                        ┃                               ┃                     ┃\n",
                            "┃                        ┃                               ┃                     ┃\n",
                            "┃                        ┃                               ┃                     ┃\n",
                            "┃                        ┃     ┏━━━━━━━┓       \\/        ┃                     ┃\n",
                            "┃                        ┃     ┃       ┃       /\\        ┃                     ┃\n",
                            "┃                        ┃     ┃       ┃       \\/        ┃                     ┃\n",
                            "┃                        ┃     ┗━━━━━━━┛       /\\        ┃                     ┃\n",
                            "┃                        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛                     ┃\n",
                            "┃                                                         <made by team Italy> ┃\n",
                            "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"
                            }; 

            for(int i=0; i<24; i++)
                printf("%s", gra[i] );
            sleep(3);
    close(fd_new);
    exit(0);
}


int gamemain(Info *info, int fd_new){
    clear();

    int select =0;
    while(1){
        clear();
        if((info->hunger) <= 0)
            starving(fd_new);
        else if((info->exp) >= 100)
            graduation(fd_new);

        cui_status(info);//print character status
        cui_action();
        printf(">> ");
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
    int cnt = 12;

    DIR *dir;
    struct dirent *dir_file;
    struct stat statbuf;
    char * filename;
    char username[10];
   
    char *main_top[100]={"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                          "┃                                                                              ┃\n",
                          "┃                                 < LOAD GAME >                                ┃\n",
                          "┃                                                                              ┃\n",
                          "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                          "┃                                SAVEFILE LIST!                                ┃\n"};
                        //  "┃                                                                              ┃\n",1
                        //  "┃                                                                              ┃\n",2
                        //  "┃                                                                              ┃\n",3
                        //  "┃                                                                              ┃\n",4
                        //  "┃                                                                              ┃\n",5
                        //  "┃                        savefile list                                         ┃\n",6
                        //  "┃                                                                              ┃\n",7
                        //  "┃                                                                              ┃\n",8
                        //  "┃                                                                              ┃\n",9
                        //  "┃                                                                              ┃\n",0
                        //  "┃                                                                              ┃\n",1
                        //  "┃                                                                              ┃\n",2
                        //  "┃                                                                              ┃\n",3
    char* main_bottom[100]={"┃                                                                              ┃\n",
                            "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                            "┃ Type your username!                                     <made by team Italy> ┃\n",
                            "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};      
    char* main_nofile[100]={"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                             "┃                                                                              ┃\n",
                             "┃                                LOADGAME ERROR!                               ┃\n",
                             "┃                                                                              ┃\n",
                             "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                           CANNOT LOAD PREVIOUS FILES.                        ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                               START A NEW GAME !                             ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                             "┃  please wait..                                          <made by team Italy> ┃\n",
                             "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};

    char* main_loading_1[100]={"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                             "┃                                                                              ┃\n",
                             "┃                                  LOADING.                                    ┃\n",
                             "┃                                                                              ┃\n",
                             "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                Ｏ   ｏ   ｏ                                  ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                             "┃  please wait..                                          <made by team Italy> ┃\n",
                             "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};
    char* main_loading_2[100]={"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                             "┃                                                                              ┃\n",
                             "┃                                  LOADING..                                   ┃\n",
                             "┃                                                                              ┃\n",
                             "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                ｏ   Ｏ   ｏ                                  ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┃                                                                              ┃\n",
                             "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                             "┃  please wait..                                          <made by team Italy> ┃\n",
                             "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};                             
     char* main_loading_3[100]={"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                                "┃                                                                              ┃\n",
                                "┃                                  LOADING...                                  ┃\n",
                                "┃                                                                              ┃\n",
                                "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                                "┃                                                                              ┃\n",
                                "┃                                                                              ┃\n",
                                "┃                                                                              ┃\n",
                                "┃                                                                              ┃\n",
                                "┃                                                                              ┃\n",
                                "┃                                                                              ┃\n",
                                "┃                                                                              ┃\n",
                                "┃                                ｏ   ｏ   Ｏ                                  ┃\n",
                                "┃                                                                              ┃\n",
                                "┃                                                                              ┃\n",
                                "┃                                                                              ┃\n",
                                "┃                                                                              ┃\n",
                                "┃                                                                              ┃\n",
                                "┃                                                                              ┃\n",
                                "┃                                                                              ┃\n",
                                "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n",
                                "┃  please wait..                                          <made by team Italy> ┃\n",
                                "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};                           

    dir = opendir("./data");
    if(NULL != dir)
    {
       for(int i=0; i<6; i++) printf("%s", main_top[i]);
       while(dir_file=readdir(dir))
       {
          filename = dir_file->d_name;    
          stat(filename,&statbuf);   
          printf("┃    %-10s     >>  %-20s    ┃", filename, ctime(&statbuf.st_mtime));
          cnt--;
       }
       for(int i=0; i<cnt; i++) printf("┃                                                                              ┃\n");
       for(int i=0; i<4; i++) printf("%s", main_bottom[i]);
       closedir(dir);
    }
     else { //if file loading goes wrong
        for(int i=0; i<23; i++) printf("%s", main_nofile[i]);
        // printf("  CANNOT LOAD PREVIOUS FILES.\n   START A NEW GAME !\n");
        sleep(2);
        newgame(info);//fd open => new game cher rom dong jack
        }

    printf(" >> ");
    scanf("%s", username);
    //loading cui
    for(int j=0; j<2; j++){
        for(int i=0; i<23; i++)
            printf("%s", main_loading_1[i] );
        sleep(1);
        for(int i=0; i<23; i++)
            printf("%s", main_loading_2[i]);
        sleep(1);
        for(int i=0; i<23; i++)
            printf("%s", main_loading_3[i]);
        sleep(1);
    }

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


            //CUI MAIN STRUCT

    // char *main[100]  =  {"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
    //                      "┃                                                                              ┃\n",
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
    //                      "┃                                                         <made by team Italy> ┃\n",
    //                      "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};       


void cui_dama_start(){
    char *main_l[100] = {"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                         "┃                                                                              ┃\n",
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
                         "┃                                                         <made by team Italy> ┃\n",
                         "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};

    char *main_r[100] = {"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n",
                         "┃                                                                              ┃\n",
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
                          "┃                                                                              ┃\n",
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
                          "┃ SELECT MENU!                                            <made by team Italy> ┃\n",
                          "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"};       
        for(int i=0; i<23; i++)
            printf("%s", main_menu[i] );
    }



// int status(Info *info){
//     printf("=====DAMAGOCHI : %s 's STATUS======\n", info->name);
//     printf("EXP: [");
//     for(int i=0; i<info->exp/5; i++) printf("=");

//     printf("]   100/%d \n", info->exp);

//     printf("Hunger: [");
//     for(int i=0; i<info->hunger/5; i++) printf("=");
//     printf("]   100/%d \n", info->hunger);

//     // printf("Damagochi name: %s\n",info->name );
//     // printf("Exp: %d\n",info->exp);
//     // printf("Hunger: %d\n",info->hunger );
//     printf("Money: %d\n",info->money );
//     printf("item: %d\n",info->item );
    
//     return 0;
// }

int main(){  
    Info *info;
    // cui_dama_main();
    // cui_dama_start();           //cui main!
    char menu_select;
    mkdir("./data", 00777);
    while(1){
        cui_dama_menuselect();
        printf(">> ");
        scanf(" %s", &menu_select);
        if('1'<=menu_select && menu_select<='3'){
            switch (menu_select){
                case '1':
                    newgame(info);
                    break;
                case '2':
                    loadgame(info);
                    break;
                case '3':
                    help();
                    break;
                default:
                    return -1;
                }
            }
        else{
            printf("unknown input, select 1~3\n");//require cui!!
            sleep(1);   
        }
    }
    return 0;
}   