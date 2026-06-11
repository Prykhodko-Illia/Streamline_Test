#include "Storage.h"
#include <iostream>

int main()
{
    Storage storage{};

    storage.addItem("item_23451", 150, "Nike,T-shirts,Clothes");
    storage.addItem("item_23452", 75,  "Adidas,Hoodies,Clothes");
    storage.addItem("item_23453", 200, "H&M,Dresses,Clothes");
    storage.addItem("item_23454", 120, "Zara,Skirts,Clothes");
    storage.addItem("item_23455", 20,  "Timberland,Desert,Boots");

    std::cout << "Item quantity for item_23451: " << storage.getItemQuantity("item_23451") << std::endl;
    std::cout << "Category total for Clothes: " << storage.getCategoryTotalCount("Clothes") << std::endl;
    std::cout << "Category unique items count for Clothes: " << storage.getCategoryUniqueItemsCount("Clothes") << std::endl;
    std::cout << "Category subcategories count for Skirts: " << storage.getCategorySubcategoriesCount("Skirts") << std::endl;
    std::cout << "Category subcategories count for All Items: " << storage.getCategorySubcategoriesCount(MAIN_CATEGORY) << std::endl;

    return 0;
}