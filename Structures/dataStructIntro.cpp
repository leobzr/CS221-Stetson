#include <iostream>
#include <assert.h>
using namespace std;

// example of structure creation:
struct product {
    int weight;
    double price; // you can put more than one type inside a struct
};

int main() {
    // creating a new product:
    product apple = {1, 2.5};
    // assign a price to one of the parts of the structures:
    //apple.price = 0.1;

    assert(apple.price > 0); // checks if it meets the expection, and if it doesnt, it returns why.

    cout << apple.price << endl;


    return 0;
}

