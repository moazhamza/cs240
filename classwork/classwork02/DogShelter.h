/* Classwork #2: Dog Shelter Software */

#include "Dog.h"

class DogShelter{
    private:
        int max_dogs;
        Dog *dogs;
        int next_id;
        int current_num;
    public:
        DogShelter(int);
        bool addDog(Dog d);
        bool adopt(int id);

};
