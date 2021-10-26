#include <cstdio>
// Implement these
int getNumberOfItemsOnList(int listNumber);
void insertIntoList(int listNumber, int numberOfItems, //
                    char const *itemDescription, float weight);
/**
 * Note that two items weigh more than one
 */
float getTotalWeightOfItemsOnList(int listNumber);

class Item
{
    char const *itemDescription = nullptr;
    float weight = 0.0f;
    int numberOfItems = 0;

public:
    void setItemDescription(char const *i) { itemDescription = i; }
    void setItemWeight(float w) { weight = w; }
    void setNumberOfItems(int i) { numberOfItems = i; }
    char const *getItemDescription() { return itemDescription; }
    float getWeight() { return weight; }
    int getNumberOfItems() { return numberOfItems; }
};

Item shoppingLists[3][5] = {};

// Maintain shopping lists :

// - implement have a number of shopping lists
// - every item on the list has a number (how many of those are bought), a
//   description and a weight
// - feel free to specialize your program for the application but maintain good
//   object-oriented design
// - hint: memory is cheap :-)

// This is the driver function, do not change!!!
int main(int argc, char *argv[])
{
    insertIntoList(1, 4, "Oranges", .5);
    insertIntoList(1, 2, "Bananas", .2);
    insertIntoList(2, 3, "Plums", .15);
    insertIntoList(2, 1, "Load of Bread", .45);
    insertIntoList(1, 2, "Bottles of Milk", 1.0);

    printf("%d\n", getNumberOfItemsOnList(1));      // expected output: 8
    printf("%f\n", getTotalWeightOfItemsOnList(2)); // expected output: .9
    return 0;
}

int getNumberOfItemsOnList(int listNumber)
{
    auto result = 0;
    for (auto i = 0u; shoppingLists[listNumber][i].getItemDescription() != nullptr; i++)
    {
        result += shoppingLists[listNumber][i].getNumberOfItems();
    }
    return result;
}

float getTotalWeightOfItemsOnList(int listNumber)
{
    float result = 0;
    for (auto i = 0u; shoppingLists[listNumber][i].getItemDescription() != nullptr; i++)
    {
        result += shoppingLists[listNumber][i].getNumberOfItems() * shoppingLists[listNumber][i].getWeight();
    }
    return result;
}

void insertIntoList(int listNumber, int numberOfItems, //
                    char const *itemDescription, float weight)
{
    // Loop through the list to find an empty slot to put an item
    auto i = 0u;
    for (; shoppingLists[listNumber][i].getItemDescription() != nullptr; i++)
        ;
    shoppingLists[listNumber][i].setItemDescription(itemDescription);
    shoppingLists[listNumber][i].setItemWeight(weight);
    shoppingLists[listNumber][i].setNumberOfItems(numberOfItems);
}