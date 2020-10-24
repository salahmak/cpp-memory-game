#include <random>
#include <ctime>
#include <vector>
using namespace std;

default_random_engine e(time(0));

template<typename T>
vector<T> shuffle(vector<T> list){ //takes vector of any type as param

    //looping through the vector (list)
    for(int i = 0; i < list.size(); ++i){

        //getting a random index from the list
        int index = (e() % list.size());


        //getting a random item from the list using the previous index
        T randomItem = list[index];

        //getting the i index's item from the vector
        T indexItem = list[i];

        //just replacing randomItem with indexItem and vice versa
        list[index] = indexItem;
        list[i] = randomItem;
    }

    return list;
};

