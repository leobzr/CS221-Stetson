#include <iostream>

// example of structure creation:
struct product {
    int weigth;
    double price; // you can put more than one type inside a struct
} 

// assign items to that structure:
product apple;
product banana, melon; //these are completely different, they are products but they
//do not relate to each other

//accessing the elements:
apple.weight;
apple.price;
banana.weight;