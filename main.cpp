#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stattypes.h"
#include "characters.h"
#include "itemtypes.h"

int main(){
    srand(time(nullptr));

    std::string imie;
    std::cout<<"Podaj imię bohatera: ";
    std::cin>>imie;
    Character player(imie, 100, 20, 10, 15, 5, 100);

    Character enemy("Goblin", 50, 15, 5, 10, 3, 50);

    player.give_item(new Potion(Stat::HEALTH, 20));
    player.give_item(new Sword(10));
    player.give_item(new Shield(30));

    enemy.give_item(new Potion(Stat::HEALTH, 10));
    enemy.give_item(new Sword(5));
    enemy.give_item(new Shield(15));

    while(player.get_health()>0 && enemy.get_health()>0){
        std::cout<<"Twoje zdrowie: "<<player.get_health()<<"/"<<player.get_maxhealth()<<"\n";
        std::cout<<"Zdrowie przeciwnika: "<<enemy.get_health()<<"/"<<enemy.get_maxhealth()<<"\n";
        std::cout<<"Wybierz akcję:\n1. Atak\n2. Użyj przedmiotu\n";
        int choice;
        std::cin>>choice;
        if (choice==1){
            int damage=player.get_attack()-enemy.get_defense();
            if (damage<0) damage=0;
            enemy.take_damage(damage);
            std::cout<<"Zadałeś "<<damage<<" obrażeń przeciwnikowi.\n";
        }else if (choice==2){
            do{
                player.print_items();
                std::cout<<"Wybierz numer przedmiotu do użycia: ";
                int item_choice;
                std::cin>>item_choice;
                if (item_choice>0 && item_choice<=player.get_maxitems()){
                    if(player.use_item(item_choice, &enemy, true)){
                        break;
                    }
                    else{
                        std::cout<<"Nie możesz użyć tego przedmiotu.\n";
                    }
                }
            }while(true);
        }
        if (enemy.get_health()>0){
            int damage=enemy.get_attack()-player.get_defense();
            if (damage<0) damage=0;
            player.take_damage(damage);
            std::cout<<"Przeciwnik zadał Ci "<<damage<<" obrażeń.\n";
        }
    }
    if (player.get_health()<=0){
        std::cout<<"Przegrałeś!\n";
    }else{
        std::cout<<"Wygrałeś!\n";
    }
    return 0;
}