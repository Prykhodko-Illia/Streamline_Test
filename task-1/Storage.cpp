#include "Storage.h"

Storage::Storage()
{
    m_categories[MAIN_CATEGORY] = CategoryTree(MAIN_CATEGORY);
}

std::vector<std::string> Storage::splitCategories(const std::string &categories)
{
    std::vector<std::string> result{};
    std::string temp = "";

    for (char ch : categories) {
        if (ch == ',') {
            result.push_back(temp);
            temp.clear();
        } else {
            temp += ch;
        }
    }

    if (!temp.empty()) {
        result.push_back(temp);
    }

    return result;
}

void Storage::addItem(const std::string &itemName, int quantity, const std::string &categories)
{
    bool isNew = (m_itemToQuantityMap.find(itemName) == m_itemToQuantityMap.end());
    m_itemToQuantityMap[itemName] += quantity;

    std::vector<std::string> parsed = splitCategories(categories);


    std::vector<std::string> path;
    path.push_back(MAIN_CATEGORY);
    for (auto it = parsed.begin(); it != parsed.end(); ++it) {
        path.push_back(*it);
    }

    for (size_t i = 0; i < path.size(); ++i) {
        const std::string& current = path[i];

        if (m_categories.find(current) == m_categories.end()) {
            m_categories[current] = CategoryTree(current);
        }

        m_categories[current].addQuantity(quantity);
        if (isNew) {
            m_categories[current].incrementUniqueItems();
        }

        if (i + 1 < path.size()) {
            const std::string &nextSubcategory = path[i + 1];
            const std::vector<std::string> &subcategories = m_categories[current].getSubcategories();

            bool exists = false;
            for (const std::string &name : subcategories) {
                if (name == nextSubcategory) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                m_categories[current].addSubcategory(nextSubcategory);
            }
        }
    }
}

int Storage::getItemQuantity(const std::string& itemName)
{
    if (m_itemToQuantityMap.find(itemName) != m_itemToQuantityMap.end())
    {
        return m_itemToQuantityMap[itemName];
    }

    return 0;
}

int Storage::getCategoryTotalCount(const std::string& categoryName)
{
    if (m_categories.find(categoryName) != m_categories.end())
    {
        return m_categories[categoryName].getUniqueItemsCount();
    }
    return 0;
}

int Storage::getCategoryUniqueItemsCount(const std::string& categoryName)
{
    if (m_categories.find(categoryName) != m_categories.end())
    {
        return m_categories[categoryName].getUniqueItemsCount();
    }
    return 0;
}

int Storage::getCategorySubcategoriesCount(const std::string& categoryName)
{
    if (m_categories.find(categoryName) != m_categories.end())
    {
        return m_categories[categoryName].getSubcategoriesCount();
    }
    return 0;
}