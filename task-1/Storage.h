#pragma once


#include <string>
#include <vector>
#include <unordered_map>
#include "CategoryTree.h"

const std::string MAIN_CATEGORY = "All items";

class Storage
{
private:
    std::unordered_map<std::string, CategoryTree> m_categories{};
    std::unordered_map<std::string, int> m_itemToQuantityMap{};

    std::vector<std::string> splitCategories(const std::string &categories);
public:
    Storage();

    void addItem(const std::string &itemName, int quantity, const std::string &categories);

    int getItemQuantity(const std::string& itemName);

    int getCategoryTotalCount(const std::string& categoryName);

    int getCategoryUniqueItemsCount(const std::string& categoryName);

    int getCategorySubcategoriesCount(const std::string& categoryName);
};

