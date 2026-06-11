#pragma once
#include <string>
#include <vector>

class CategoryTree
{
private:
    std::string m_name{};
    int m_totalQuantity = 0;
    int m_uniqueItemsCount = 0;

    std::vector<std::string> m_subcategories{};

public:
    explicit CategoryTree(const std::string &name) : m_name(name) {}
    CategoryTree() = default;

    int getTotalQuantity() const
    {
        return m_totalQuantity;
    }

    void addQuantity(int quantity)
    {
        m_totalQuantity += quantity;
    }

    int getUniqueItemsCount() const
    {
        return m_uniqueItemsCount;
    }

    void incrementUniqueItems()
    {
        m_uniqueItemsCount++;
    }

    const std::vector<std::string>& getSubcategories() const
    {
        return m_subcategories;
    }

    int getSubcategoriesCount() const
    {
        return m_subcategories.size();
    }

    void addSubcategory(const std::string& subcategoryName)
    {
        m_subcategories.push_back(subcategoryName);
    }
};