    char* main_nomoney[100];
    char* main_buy[100];
    char buy_temp[10];
    for(int i=0; i<23; i++){
        main_nomoney[i]=itemmain[i];
        main_buy[i]=itemmain[i];
    }
    main_nomoney[21]=     "┃   Not Enough money!                                     <made by team Italy> ┃\n";
    main_buy[21]         ="┃   Purchasing....                                        <made by team Italy> ┃\n";