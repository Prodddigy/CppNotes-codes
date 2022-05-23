#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>


        struct point{
            int x;
            int y;

            point(int x, int y)
            : x(x), y(y)
            {

            }
        };


        bool distance_between(point a , point b, point search)
        {
            return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2))
                                     >
                    sqrt(pow(a.x-search.x,2)+pow(a.y-search.y,2));

        }

        point closest(std::vector<point> points, point search)
                {

                    return std::ranges::min(points, [search](point a, point b )
                    {//for each loop would be ok too :'(
                        return(distance_between(a,b,search));
                    });

              }



        enum comparing_by
        {
            name,
            mana_cost,
            power,
            health
        };


        struct card{
            std::string name;
            int mana;
            int power;
            int health;

            card(std::string name, int mana, int power, int health)
            : name(name), mana(mana), power(power),health(health)
            {

            }
        };




        bool compare(card a , card b, comparing_by value)
        {
            switch (value)
            {
                case comparing_by::name : {

                    return a.name < b.name;

                    break;
                }
                case comparing_by::mana_cost : {

                    return a.mana < b.mana;

                    break;
                }
                case comparing_by::power : {

                    return a.power < b.power;

                    break;
                }
                case comparing_by::health : {

                    return a.health < b.health;

                    break;
                }
                default:{

                }
            }

        }


      card static max(std::vector<card> cards, comparing_by value)
        {

         return std::ranges::max(cards,[value](card a, card b){

             return compare(a,b,value);
         });

        }



int main() {

    auto points = std::vector<point> {
            point(7,5),
            point(10,2),
            point(5,1),
            point(0,4),
            point(2,8),
            point(6,11)
    };

    auto search = point(0,0);

   std::cout<< closest(points,search).x <<closest(points,search).y << '\n';

    auto cards = std::vector<card> {
            card("Goblin Snowman",7,5,3),
            card("Hidden Dragon Slayer",10,2,6),
            card("Ice Thing",5,1,0),
            card("Black lotus",0,4,44),
            card("Disciple of the Ring",2,8,1),
            card("Angel of Deliverance",6,11,9)
    };



 std::cout<<  max(cards, mana_cost).name <<" which has the greatest stat of " << max(cards, mana_cost).mana << '\n';

}
