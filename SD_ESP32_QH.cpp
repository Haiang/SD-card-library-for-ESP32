#include "SD_ESP32_QH.h"

// Constructor
SD_ESP32_QH::SD_ESP32_QH() {
    // Constructor code here (if any)
}

// Initialize SD card
bool SD_ESP32_QH::begin() {
    if (!SD.begin(SD_CS_PIN)) {
        Serial.println("Failed to initialize SD card");
        return false;
    }
    return true;
}

// Check if SD card is formatted as FAT32
bool SD_ESP32_QH::isFAT32() {
    return SD.cardType() == CARD_SDHC;
}

// Deinitialize SD card
void SD_ESP32_QH::deinit() {
    SD.end();
}

// Write integer
bool SD_ESP32_QH::writeInt(const char* filename, int value) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    file.println(value);
    file.close();
    return true;
}

// Read integer
bool SD_ESP32_QH::readInt(const char* filename, int& value) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    value = file.parseInt();
    file.close();
    return true;
}

// Write float
bool SD_ESP32_QH::writeFloat(const char* filename, float value) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    file.println(value, 6);
    file.close();
    return true;
}

// Read float
bool SD_ESP32_QH::readFloat(const char* filename, float& value) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    value = file.parseFloat();
    file.close();
    return true;
}

// Write double
bool SD_ESP32_QH::writeDouble(const char* filename, double value) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    file.println(value, 10);
    file.close();
    return true;
}

// Read double
bool SD_ESP32_QH::readDouble(const char* filename, double& value) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    String str = file.readStringUntil('\n');
    value = str.toDouble();
    file.close();
    return true;
}

// Write boolean
bool SD_ESP32_QH::writeBool(const char* filename, bool value) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    file.println(value ? "true" : "false");
    file.close();
    return true;
}

// Read boolean
bool SD_ESP32_QH::readBool(const char* filename, bool& value) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    String str = file.readStringUntil('\n');
    value = (str == "true");
    file.close();
    return true;
}

// Write string
bool SD_ESP32_QH::writeString(const char* filename, const String& value) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    file.println(value);
    file.close();
    return true;
}

// Read string
bool SD_ESP32_QH::readString(const char* filename, String& value) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    value = file.readStringUntil('\n');
    file.close();
    return true;
}

// Write char array
bool SD_ESP32_QH::writeCharArray(const char* filename, const char* value) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    file.println(value);
    file.close();
    return true;
}

// Read char array
bool SD_ESP32_QH::readCharArray(const char* filename, char* value, size_t maxSize) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    String str = file.readStringUntil('\n');
    str.toCharArray(value, maxSize);
    file.close();
    return true;
}

// Write integer array
bool SD_ESP32_QH::writeArray(const char* filename, const int* array, size_t size) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        file.println(array[i]);
    }
    file.close();
    return true;
}

// Read integer array
bool SD_ESP32_QH::readArray(const char* filename, int* array, size_t size) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        if (file.available()) {
            array[i] = file.parseInt();
        } else {
            file.close();
            return false;
        }
    }
    file.close();
    return true;
}

// Write float array
bool SD_ESP32_QH::writeFloatArray(const char* filename, const float* array, size_t size) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        file.println(array[i], 6);
    }
    file.close();
    return true;
}

// Read float array
bool SD_ESP32_QH::readFloatArray(const char* filename, float* array, size_t size) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        if (file.available()) {
            array[i] = file.parseFloat();
        } else {
            file.close();
            return false;
        }
    }
    file.close();
    return true;
}

// Write double array
bool SD_ESP32_QH::writeDoubleArray(const char* filename, const double* array, size_t size) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        file.println(array[i], 10);
    }
    file.close();
    return true;
}

// Read double array
bool SD_ESP32_QH::readDoubleArray(const char* filename, double* array, size_t size) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        if (file.available()) {
            array[i] = file.parseFloat();
        } else {
            file.close();
            return false;
        }
    }
    file.close();
    return true;
}

// Write structure
bool SD_ESP32_QH::writeStruct(const char* filename, const void* structure, size_t size) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    file.write(reinterpret_cast<const uint8_t*>(structure), size);
    file.close();
    return true;
}

// Read structure
bool SD_ESP32_QH::readStruct(const char* filename, void* structure, size_t size) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    file.read(reinterpret_cast<uint8_t*>(structure), size);
    file.close();
    return true;
}

// Write raw data
bool SD_ESP32_QH::writeData(const char* filename, const void* data, size_t size) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    file.write(reinterpret_cast<const uint8_t*>(data), size);
    file.close();
    return true;
}

// Read raw data
bool SD_ESP32_QH::readData(const char* filename, void* data, size_t size) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    file.read(reinterpret_cast<uint8_t*>(data), size);
    file.close();
    return true;
}

// Write long
bool SD_ESP32_QH::writeLong(const char* filename, long value) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    file.println(value);
    file.close();
    return true;
}

// Read long
bool SD_ESP32_QH::readLong(const char* filename, long& value) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    value = file.parseInt();
    file.close();
    return true;
}

// Write uint8_t
bool SD_ESP32_QH::writeUInt8(const char* filename, uint8_t value) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    file.println(value);
    file.close();
    return true;
}

// Read uint8_t
bool SD_ESP32_QH::readUInt8(const char* filename, uint8_t& value) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    value = file.parseInt();
    file.close();
    return true;
}

// Write uint16_t
bool SD_ESP32_QH::writeUInt16(const char* filename, uint16_t value) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    file.println(value);
    file.close();
    return true;
}

// Read uint16_t
bool SD_ESP32_QH::readUInt16(const char* filename, uint16_t& value) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    value = file.parseInt();
    file.close();
    return true;
}

// Write uint32_t
bool SD_ESP32_QH::writeUInt32(const char* filename, uint32_t value) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    file.println(value);
    file.close();
    return true;
}

// Read uint32_t
bool SD_ESP32_QH::readUInt32(const char* filename, uint32_t& value) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    value = file.parseInt();
    file.close();
    return true;
}

// Write unsigned int
bool SD_ESP32_QH::writeUnsignedInt(const char* filename, unsigned int value) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    file.println(value);
    file.close();
    return true;
}

// Read unsigned int
bool SD_ESP32_QH::readUnsignedInt(const char* filename, unsigned int& value) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    value = file.parseInt();
    file.close();
    return true;
}

// Write unsigned long
bool SD_ESP32_QH::writeUnsignedLong(const char* filename, unsigned long value) {
    file = SD.open(filename, FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }
    file.println(value);
    file.close();
    return true;
}

// Read unsigned long
bool SD_ESP32_QH::readUnsignedLong(const char* filename, unsigned long& value) {
    file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }
    value = file.parseInt();
    file.close();
    return true;
}
