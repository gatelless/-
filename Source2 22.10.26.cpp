#include <iostream>
#include <limits>

// Перечисление типов персонажей
enum class CharacterType {
    Warrior = 0,   // Воин
    Mage,          // Маг
    Archer,        // Лучник
    Rogue          // Разбойник
};

// Перечисление качества оружия
enum class WeaponQuality {
    Common = 0,    // Обычное
    Uncommon,      // Необычное
    Rare,          // Редкое
    Epic,          // Эпическое
    Legendary      // Легендарное
};

// Функция очистки потока ввода при ошибке
void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Вывод меню выбора персонажа
void printCharacterMenu() {
    std::cout << "\n=== Выбор персонажа ===\n";
    std::cout << "0 - Воин\n";
    std::cout << "1 - Маг\n";
    std::cout << "2 - Лучник\n";
    std::cout << "3 - Разбойник\n";
    std::cout << "Ваш выбор: ";
}

// Вывод меню выбора качества оружия
void printWeaponMenu() {
    std::cout << "\n=== Качество оружия ===\n";
    std::cout << "0 - Обычное\n";
    std::cout << "1 - Необычное\n";
    std::cout << "2 - Редкое\n";
    std::cout << "3 - Эпическое\n";
    std::cout << "4 - Легендарное\n";
    std::cout << "Ваш выбор: ";
}

// Описание персонажа через switch-case
void describeCharacter(CharacterType type) {
    std::cout << "\n--- Описание персонажа ---\n";
    switch (type) {
    case CharacterType::Warrior:
        std::cout << "Воин: крепкий боец ближнего боя, носит тяжёлую броню "
            "и владеет мечом. Обладает высоким здоровьем и защитой.\n";
        break;
    case CharacterType::Mage:
        std::cout << "Маг: повелитель стихий, использует посох и заклинания. "
            "Наносит огромный магический урон, но имеет мало здоровья.\n";
        break;
    case CharacterType::Archer:
        std::cout << "Лучник: меткий стрелок, атакует на расстоянии из лука. "
            "Быстрый и ловкий, отлично подходит для тактики.\n";
        break;
    case CharacterType::Rogue:
        std::cout << "Разбойник: мастер скрытности и кинжалов. Наносит критический "
            "урон из-за спины и легко уходит от атак.\n";
        break;
    }
}

// Описание качества оружия через switch-case
void describeWeapon(WeaponQuality quality) {
    std::cout << "\n--- Характеристики оружия ---\n";
    switch (quality) {
    case WeaponQuality::Common:
        std::cout << "Обычное оружие: базовая экипировка. Бонусов нет. "
            "Стоимость: 10 золотых.\n";
        break;
    case WeaponQuality::Uncommon:
        std::cout << "Необычное оружие: лёгкое улучшение характеристик. "
            "Бонус +5% к урону. Стоимость: 50 золотых.\n";
        break;
    case WeaponQuality::Rare:
        std::cout << "Редкое оружие: заметный прирост силы. "
            "Бонус +15% к урону, +1 к характеристике. Стоимость: 200 золотых.\n";
        break;
    case WeaponQuality::Epic:
        std::cout << "Эпическое оружие: мощный артефакт. "
            "Бонус +30% к урону, дополнительный эффект. Стоимость: 1000 золотых.\n";
        break;
    case WeaponQuality::Legendary:
        std::cout << "Легендарное оружие: уникальный предмет из легенд. "
            "Бонус +50% к урону, особые эффекты. Стоимость: 5000 золотых.\n";
        break;
    }
}

int main() {
    int characterChoice = -1;
    int weaponChoice = -1;

    // --- Выбор персонажа с обработкой ошибок ---
    while (true) {
        printCharacterMenu();
        if (std::cin >> characterChoice) {
            if (characterChoice >= 0 && characterChoice <= 3) {
                break;
            }
            std::cout << "Ошибка: выберите число от 0 до 3.\n";
        }
        else {
            std::cout << "Ошибка: введено не число. Попробуйте снова.\n";
            clearInput();
        }
    }

    // --- Выбор качества оружия с обработкой ошибок ---
    while (true) {
        printWeaponMenu();
        if (std::cin >> weaponChoice) {
            if (weaponChoice >= 0 && weaponChoice <= 4) {
                break;
            }
            std::cout << "Ошибка: выберите число от 0 до 4.\n";
        }
        else {
            std::cout << "Ошибка: введено не число. Попробуйте снова.\n";
            clearInput();
        }
    }

    // --- Преобразование int в enum class ---
    CharacterType character = static_cast<CharacterType>(characterChoice);
    WeaponQuality quality = static_cast<WeaponQuality>(weaponChoice);

    // --- Вывод результата ---
    std::cout << "\n========================================\n";
    std::cout << "Ваш персонаж: индекс = " << static_cast<int>(character) << "\n";
    describeCharacter(character);

    std::cout << "\nВаше оружие: индекс = " << static_cast<int>(quality) << "\n";
    describeWeapon(quality);
    std::cout << "========================================\n";

    return 0;
}