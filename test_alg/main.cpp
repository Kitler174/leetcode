using namespace std;
#include <iostream>

int calc(const char* com) {
    double math1[1024];  // Tablica do przechowywania liczb
    char symbols[512];    // Tablica do przechowywania symboli
    double actual_num = 0;  // Bieżąca liczba
    int tleng = 0;          // Indeks do tablicy math1
    int cleng = 0;          // Indeks do tablicy symbols

    while (*com != '\0') {
        if (*com == '+' || *com == '-' || *com == '*' || *com == '/') {
            if (tleng < 1024) {
                math1[tleng++] = actual_num;  // Zapisz aktualną liczbę i zwiększ indeks
            }
            actual_num = 0;  // Resetuj bieżącą liczbę

            if (cleng < 512) {
                symbols[cleng++] = *com;  // Zapisz symbol i zwiększ indeks
            }
        } else if (*com >= '0' && *com <= '9') {
            actual_num = actual_num * 10 + (*com - '0');  // Zbuduj aktualną liczbę
        }
        com++;
    }

    if (tleng < 1024) {
        math1[tleng++] = actual_num;  // Zapisz ostatnią liczbę
    }

    // Przetwarzanie mnożenia i dzielenia
    double math2[1024];
    char symbols2[512];
    int tleng2 = 0;  // Indeks do math2
    int cleng2 = 0;  // Indeks do symbols2

    for (int i = 0; i < cleng; i++) {
        if (symbols[i] == '*') {
            math1[i + 1] = math1[i] * math1[i + 1];  // Mnożenie
            math1[i] = 0;  // Zresetuj wartość
        } else if (symbols[i] == '/') {
            if (math1[i + 1] != 0) {  // Sprawdź dzielenie przez zero
                math1[i + 1] = math1[i] / math1[i + 1];  // Dzielenie
            } else {
                // Obsłuż błąd: dzielenie przez zero
                return 0;  // Lub zwróć inną wartość, aby zasygnalizować błąd
            }
            math1[i] = 0;  // Zresetuj wartość
        } else {
            math2[tleng2++] = math1[i];  // Przenieś liczbę do math2
            if (i < cleng) {
                symbols2[cleng2++] = symbols[i];  // Przenieś symbol do symbols2
            }
        }
    }
    // Dodaj ostatnią liczbę
    math2[tleng2++] = math1[tleng - 1];

    // Oblicz wynik dla dodawania i odejmowania
    double result = math2[0];

    for (int i = 0; i < cleng2; i++) {
        if (symbols2[i] == '+') {
            result += math2[i + 1];
        } else if (symbols2[i] == '-') {
            result -= math2[i + 1];
        }
    }

    return static_cast<int>(result);  // Zwróć wynik jako int
}

int main() {
    char command[1024] = "2-2*2";
    int result = calc(command);
    cout << result;

}
