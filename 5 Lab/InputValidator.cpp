

#include "InputValidator.h"
#include <iostream>
#include <limits>
#include <string>
#include <cctype>

using namespace std;

//! \brief Получает корректное целое число от пользователя
//! \param prompt Сообщение для пользователя
//! \return Введенное целое число
int InputValidator::GetInt(const std::string& prompt)
{
    int value;
    bool valid = false;

    while (!valid)
    {
        if (!prompt.empty())
        {
            cout << prompt;
        }

        if (cin >> value)
        {
            char next = cin.peek();
            if (next == '\n' || next == ' ' || next == '\t')
            {
                valid = true;
            }
            else
            {
                cout << "Ошибка! Обнаружены лишние символы. Введите только число: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else
        {
            cout << "Ошибка! Введите корректное целое число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}
