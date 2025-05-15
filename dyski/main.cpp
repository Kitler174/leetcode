#include <iostream>
#include <cstdint>
#include <typeinfo>
#define SECTOR_SIZE 512

using namespace std;

void outb(uint16_t port, uint8_t value) {
    __asm__ volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
}

static inline uint8_t inb(uint16_t port) {
    uint8_t result;
    asm volatile ("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

void read_block(uint64_t block_number, uint8_t* buffer) {
    cout << "Block number: " << block_number << endl; // Debugowanie
    cout << "Block number shifted: " << (block_number >> 24) << endl; // Debugowanie
    uint8_t highByte = (block_number >> 24) & 0x0F;
    cout << "High byte: " << (int)highByte << endl; // Debugowanie

    outb(0x1F6, (0xE0 | highByte)); // 4 najstarsze bity + LBA bit
    outb(0x1F1, (uint8_t)(block_number & 0xFF));         // LSB
    outb(0x1F1, (uint8_t)((block_number >> 8) & 0xFF)); // następne 8 bitów
    outb(0x1F1, (uint8_t)((block_number >> 16) & 0xFF)); // 8 wyższych bitów

    outb(0x1F7, 0x20); // Komenda READ SECTOR 

    while ((inb(0x1F7) & 0x08) == 0); // Czekaj na gotowość

    for (size_t i = 0; i < SECTOR_SIZE; i += 2) {
        while ((inb(0x1F7) & 0x08) == 0); // Czekaj na gotowość
        uint16_t data = (inb(0x1F0) << 8) | inb(0x1F0); // Odczyt danych
        buffer[i] = data & 0xFF;
        if (i + 1 < SECTOR_SIZE) {
            buffer[i + 1] = (data >> 8) & 0xFF;
        }
        cout << "Read data: " << hex << data << " at index: " << i << endl; // Debugowanie
    }
}

int main() {
    uint8_t buffer[SECTOR_SIZE];

    // Użycie 64-bitowego numeru bloku
    uint64_t block_number = 1048576; // Upewnij się, że to jest 64 bity
    cout << "Setting block number to: " << block_number << endl;
    cout << "Type of block_number: " << typeid(block_number).name() << endl; // Debugowanie typu

    read_block(static_cast<uint64_t>(block_number), buffer); // Użycie wyższej wartości dla block_number
    return 0;
}
