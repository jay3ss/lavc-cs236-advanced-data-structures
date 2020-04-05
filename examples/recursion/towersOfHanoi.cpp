#include <iostream>

void towersOfHanoi(int num, char, char, char);

int main()
{
    towersOfHanoi(3, 'A', 'B', 'C');
}

void towersOfHanoi(int num, char fromTower, char toTower, char auxTower)
{
    if (num == 1)
    {
        std::cout << "Moving disc " << num
                  << " from " << fromTower
                  << " to " << toTower << "\n";
    }
    else
    {
        towersOfHanoi(num - 1, fromTower, auxTower, toTower);
        std::cout << "Moving disc " << num
                  << " from " << fromTower
                  << " to " << toTower << "\n";
        towersOfHanoi(num - 1, auxTower, toTower, fromTower);
    }

}
