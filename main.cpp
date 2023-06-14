#include <iostream>
#include <string>
#include <vector>


class Butterfly
{
public:
    std::string stage_name;
    int life_days;

    void change()
    {
        if (stage_name == "гусеница" && life_days >= 7)
        {
            stage_name = "куколка";
        }
        else if (stage_name == "куколка" && life_days >= 15)
        {
            stage_name = "бабочка";
        }
        else if (stage_name == "бабочка" && life_days >= 23)
        {
            stage_name = "гусеница";
            life_days = 0;
        }
        life_days += 1;
    }
};

int main()
{
    std::vector<Butterfly*> butterflies;
    for (int i = 0; i < 10; i++)
    {
        butterflies.push_back(new Butterfly);
    }
    for (int i = 0; i < 10; i++)
    {
        butterflies[i]->stage_name = "гусеница";
        butterflies[i]->life_days = i;
    }
    std::cout << "Исходный вектор:" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << butterflies[i]->stage_name << " " << butterflies[i]->life_days << std::endl;
    }
    for (int i = 0; i < 10; i++)
    {
        butterflies[i]->change();
    }
    std::cout << "\nПолучившийся вектор:" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << butterflies[i]->stage_name << " " << butterflies[i]->life_days << std::endl;
    }
    return 0;
}