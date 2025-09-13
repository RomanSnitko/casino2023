#include <iostream>
#include <cstdlib> //для рандом чисел
#include <ctime>
#include <thread> //для задержки 200мс
#include <chrono> //для интервалов по времени

using namespace std;

int balance;
int slot1, slot2, slot3;

void spinAnimation() {
    const int cols = 3;
    int slots[cols];

    for (int j = 0; j < cols; j++) {
        slots[j] = rand() % 2 + 1; // от 1 до 5 рандом
    }
    cout << "\r[ " << slots[0] << " ] [ " << slots[1] << " ] [ " << slots[2] << " ]" << flush; // очистка экрана
    this_thread::sleep_for(chrono::milliseconds(100));

    slot1 = slots[0];
    slot2 = slots[1];
    slot3 = slots[2];
    cout << "\n";
}

void playSlots() {
    int bet;
    if (balance <= 0) {
        cout << "У вас недостаточно средств для игры." << endl;
        return;
    }

    cout << "\n--- Слот-Машина ---" << endl;
    cout << "Ваш текущий баланс: " << balance << " монет" << endl;
    cout << "Введите вашу ставку: ";
    cin >> bet;

    if (bet > balance) {
        cout << "Недостаточно средств для такой ставки!" << endl;
        return;
    }

    cout << "Вращение барабанов..." << endl;

    spinAnimation();

    cout << "Результаты: [" << slot1 << "] [" << slot2 << "] [" << slot3 << "]" << endl;

    if (slot1 == slot2 && slot2 == slot3) {
        cout << "Поздравляем! Джекпот! Вы выиграли " << bet * 20 << " монет!" << endl;
        balance += bet * 20;
    }
    else {
        cout << "Вы проиграли! Удачи в следующий раз!" << endl;
        balance -= bet;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0));

    cout << "Введите стартовый баланс: ";
    cin >> balance;

    char choice;
    do {
        playSlots();

        if (balance <= 0) {
            cout << "\nВы банкрот! Игра завершена." << endl;
            break;
        }

        cout << "\nВаш текущий баланс: " << balance << " монет" << endl;
        cout << "Хотите сыграть ещё раз? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Спасибо за игру! До встречи!" << endl;
    return 0;
}
