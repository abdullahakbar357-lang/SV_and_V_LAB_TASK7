
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const int MAX_MONSTERS = 10;

class Monster {
public:
    int id;
    std::string name;
    int health;
    int attack;

    Monster(int i, std::string n, int h, int a) {
        id = i;
        name = n;
        health = h;
        attack = a;
    }
};

class Game {
private:
    std::vector<Monster> monsters;

public:
    void spawnMonster(int id, std::string name, int health, int attack) {
        if (monsters.size() >= MAX_MONSTERS) {
            std::cout << "Monster limit reached!\n";
            return;
        }

        monsters.emplace_back(id, name, health, attack);
    }

    Monster* findMonster(int id) {
        for (auto& monster : monsters) {
            if (monster.id == id)
                return &monster;
        }
        return nullptr;
    }

    int attackMonster(int id, int damage) {
        Monster* m = findMonster(id);

        if (m == nullptr || damage < 0)
            return -1;

        m->health -= damage;

        if (m->health < 0)
            m->health = 0;

        return m->health;
    }

    int totalMonsterHealth() {
        int total = 0;

        for (const auto& monster : monsters)
            total += monster.health;

        return total;
    }

    std::string getMonsterLabel(int id) {
        Monster* m = findMonster(id);

        if (m == nullptr)
            return "Monster not found";

        return "Monster-" + std::to_string(m->id) + ":" + m->name;
    }

    int averageAttack() {
        if (monsters.empty())
            return 0;

        int sum = 0;

        for (const auto& monster : monsters)
            sum += monster.attack;

        return sum / static_cast<int>(monsters.size());
    }

    void defeatMonster(int id) {
        auto it = std::find_if(
            monsters.begin(), monsters.end(),
            [id](const Monster& m) {
                return m.id == id;
            }
        );

        if (it == monsters.end()) {
            std::cout << "Monster not found!\n";
            return;
        }

        std::cout << "Defeated " << it->name << "\n";
        monsters.erase(it);
    }
};

double calculateDamage(int attack, int armorPercent) {
    return attack * armorPercent / 100.0;
}

int playerRank(int score) {
    if (score > 1000)
        return 1;
    else if (score > 100)
        return 2;
    else
        return 3;
}

void readBoss(Game& game) {
    std::string name;
    int health;

    std::cout << "Enter boss name: ";
    std::cin >> name;

    std::cout << "Enter boss health: ";
    std::cin >> health;

    if (health <= 0) {
        std::cout << "Health must be positive!\n";
        return;
    }

    game.spawnMonster(100, name, health, 50);
}

int main() {
    Game game;

    game.spawnMonster(1, "Goblin", 30, 5);
    game.spawnMonster(2, "Orc", 60, 12);
    game.spawnMonster(3, "Skeleton", 40, 8);
    game.spawnMonster(4, "Troll", 90, 20);
    game.spawnMonster(5, "Dragon", 200, 45);
    game.spawnMonster(6, "Bat", 10, 3);

    std::cout << "Attack: "
              << game.attackMonster(99, 20) << "\n";

    std::cout << "Label: "
              << game.getMonsterLabel(2) << "\n";

    std::cout << "Total health: "
              << game.totalMonsterHealth() << "\n";

    std::cout << "Average attack: "
              << game.averageAttack() << "\n";

    std::cout << "Damage: "
              << calculateDamage(80, 25) << "\n";

    std::cout << "Rank: "
              << playerRank(50) << "\n";

    game.defeatMonster(3);

    readBoss(game);

    Game copy = game;

    std::cout << "Copied game total health: "
              << copy.totalMonsterHealth() << "\n";

    return 0;
}
