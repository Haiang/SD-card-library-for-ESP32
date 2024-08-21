#include <Arduino.h>
#include <SD.h>
#include "SD_ESP32_QH.h"

// Khởi tạo đối tượng SD_ESP32_QH
SD_ESP32_QH sd;

void setup() {
    Serial.begin(115200);

    if (!sd.begin()) {
        Serial.println("SD initialization failed!");
        return;
    }

    // Ghi và đọc các kiểu dữ liệu khác nhau
    writeReadInt();
    writeReadFloat();
    writeReadDouble();
    writeReadBool();
    writeReadString();
    writeReadCharArray();
    writeReadArray();
    writeReadFloatArray();
    writeReadDoubleArray();
    writeReadStruct();

    // Kết thúc kết nối với thẻ SD
    sd.deinit();
}

void loop() {
    // Không cần thực hiện gì trong loop() cho chương trình mẫu này
}

void writeReadInt() {
    const char* filename = "/intdata.txt";
    int intValue = 1234;
    sd.writeInt(filename, intValue);
    int readValue;
    sd.readInt(filename, readValue);
    Serial.print("Integer Value: ");
    Serial.println(readValue);
}

void writeReadFloat() {
    const char* filename = "/floatdata.txt";
    float floatValue = 123.456;
    sd.writeFloat(filename, floatValue);
    float readValue;
    sd.readFloat(filename, readValue);
    Serial.print("Float Value: ");
    Serial.println(readValue);
}

void writeReadDouble() {
    const char* filename = "/doubldata.txt";
    double doubleValue = 123.456789;
    sd.writeDouble(filename, doubleValue);
    double readValue;
    sd.readDouble(filename, readValue);
    Serial.print("Double Value: ");
    Serial.println(readValue);
}

void writeReadBool() {
    const char* filename = "/booldata.txt";
    bool boolValue = true;
    sd.writeBool(filename, boolValue);
    bool readValue;
    sd.readBool(filename, readValue);
    Serial.print("Boolean Value: ");
    Serial.println(readValue ? "true" : "false");
}

void writeReadString() {
    const char* filename = "/stringdata.txt";
    String strValue = "Hello, World!";
    sd.writeString(filename, strValue);
    String readValue;
    sd.readString(filename, readValue);
    Serial.print("String Value: ");
    Serial.println(readValue);
}

void writeReadCharArray() {
    const char* filename = "/chararraydata.txt";
    const char* charArrayValue = "Hello, Char Array!";
    sd.writeCharArray(filename, charArrayValue);
    char readValue[50];
    sd.readCharArray(filename, readValue, sizeof(readValue));
    Serial.print("Char Array Value: ");
    Serial.println(readValue);
}

void writeReadArray() {
    const char* filename = "/intarraydata.txt";
    int intArray[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(intArray) / sizeof(intArray[0]);
    sd.writeArray(filename, intArray, size);
    int readArray[5];
    sd.readArray(filename, readArray, size);
    Serial.print("Integer Array Values: ");
    for (size_t i = 0; i < size; ++i) {
        Serial.print(readArray[i]);
        Serial.print(" ");
    }
    Serial.println();
}

void writeReadFloatArray() {
    const char* filename = "/floatarraydata.txt";
    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t size = sizeof(floatArray) / sizeof(floatArray[0]);
    sd.writeFloatArray(filename, floatArray, size);
    float readArray[5];
    sd.readFloatArray(filename, readArray, size);
    Serial.print("Float Array Values: ");
    for (size_t i = 0; i < size; ++i) {
        Serial.print(readArray[i]);
        Serial.print(" ");
    }
    Serial.println();
}

void writeReadDoubleArray() {
    const char* filename = "/doublearraydata.txt";
    double doubleArray[] = {1.11, 2.22, 3.33, 4.44, 5.55};
    size_t size = sizeof(doubleArray) / sizeof(doubleArray[0]);
    sd.writeDoubleArray(filename, doubleArray, size);
    double readArray[5];
    sd.readDoubleArray(filename, readArray, size);
    Serial.print("Double Array Values: ");
    for (size_t i = 0; i < size; ++i) {
        Serial.print(readArray[i]);
        Serial.print(" ");
    }
    Serial.println();
}

void writeReadStruct() {
    const char* filename = "/structdata.bin";
    
    // Define a structure
    struct Data {
        int id;
        float value;
        char name[20];
    };

    // Create and write structure
    Data writeData = {1, 3.14, "StructData"};
    sd.writeStruct(filename, &writeData, sizeof(writeData));

    // Read structure
    Data readData;
    sd.readStruct(filename, &readData, sizeof(readData));
    Serial.print("Struct Data - ID: ");
    Serial.print(readData.id);
    Serial.print(", Value: ");
    Serial.print(readData.value);
    Serial.print(", Name: ");
    Serial.println(readData.name);
}
