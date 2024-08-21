#ifndef SD_ESP32_QH_H
#define SD_ESP32_QH_H

#include <Arduino.h>  // Bao gồm thư viện Arduino cơ bản, cung cấp các định nghĩa và hàm cần thiết.
#include <SD.h>       // Bao gồm thư viện SD, cung cấp các hàm và lớp để làm việc với thẻ SD.

// Định nghĩa các chân kết nối với thẻ SD
#define SD_CS_PIN 5    // Chân CS (Chip Select) của thẻ SD, sử dụng chân số 5 trên ESP32.
#define SD_SCK_PIN 18  // Chân SCK (Serial Clock) của thẻ SD, sử dụng chân số 18 trên ESP32.
#define SD_MOSI_PIN 23 // Chân MOSI (Master Out Slave In) của thẻ SD, sử dụng chân số 23 trên ESP32.
#define SD_MISO_PIN 19 // Chân MISO (Master In Slave Out) của thẻ SD, sử dụng chân số 19 trên ESP32.

/**
 * @brief Lớp SD_ESP32_QH
 * 
 * Lớp này cung cấp các phương thức để làm việc với thẻ SD thông qua ESP32 và được lập trình bằng Arduino hoặc Plaform IO trên Vs Code 
 *
 * Bao gồm các chức năng khởi tạo, ghi và đọc các loại dữ liệu khác nhau từ thẻ SD.
 * 
 * Các định dạng dữ liệu mà chương trình hỗ trợ:

 * Số nguyên (int, long, unsigned long, unsigned int): Đọc và ghi các giá trị số nguyên có dấu và không dấu.
 * Số thực (float, double): Đọc và ghi các giá trị số thực đơn và kép.
 * Boolean (bool): Đọc và ghi giá trị đúng/sai.
 * Chuỗi ký tự (String, char[]): Đọc và ghi chuỗi ký tự.
 * Mảng (int[], float[], double[]): Đọc và ghi các mảng số nguyên và số thực.
 * Cấu trúc (struct): Đọc và ghi dữ liệu cấu trúc.
 * Dữ liệu thô (void):* Đọc và ghi dữ liệu thô với kích thước xác định.
 *
 * Tác giả: [Tên tác giả]
 * Ngày tạo: [Ngày]
 */ 
 
class SD_ESP32_QH {
public:
    SD_ESP32_QH();  // Constructor của lớp SD_ESP32_QH, được sử dụng để khởi tạo đối tượng lớp này.

    bool begin();  // Khởi động thẻ SD. Trả về true nếu khởi động thành công, ngược lại false.
    bool isFAT32();  // Kiểm tra xem thẻ SD có định dạng FAT32 không. Trả về true nếu có.
    void deinit();  // Giải phóng tài nguyên và tắt kết nối với thẻ SD.

    // Các phương thức ghi và đọc giá trị kiểu dữ liệu cơ bản
    bool writeInt(const char* filename, int value);  // Ghi một giá trị số nguyên int vào file có tên filename.
    bool readInt(const char* filename, int& value);  // Đọc một giá trị số nguyên int từ file có tên filename và lưu vào biến value.

    bool writeFloat(const char* filename, float value);  // Ghi một giá trị số thực float vào file có tên filename.
    bool readFloat(const char* filename, float& value);  // Đọc một giá trị số thực float từ file có tên filename và lưu vào biến value.

    bool writeDouble(const char* filename, double value);  // Ghi một giá trị số thực double vào file có tên filename.
    bool readDouble(const char* filename, double& value);  // Đọc một giá trị số thực double từ file có tên filename và lưu vào biến value.

    bool writeBool(const char* filename, bool value);  // Ghi một giá trị boolean bool vào file có tên filename.
    bool readBool(const char* filename, bool& value);  // Đọc một giá trị boolean bool từ file có tên filename và lưu vào biến value.

    bool writeString(const char* filename, const String& value);  // Ghi một đối tượng String vào file có tên filename.
    bool readString(const char* filename, String& value);  // Đọc một đối tượng String từ file có tên filename và lưu vào biến value.

    bool writeCharArray(const char* filename, const char* value);  // Ghi một chuỗi ký tự char[] hoặc char* vào file có tên filename.
    bool readCharArray(const char* filename, char* value, size_t maxSize);  // Đọc một chuỗi ký tự char[] từ file có tên filename và lưu vào biến value với kích thước tối đa maxSize.

    bool writeArray(const char* filename, const int* array, size_t size);  // Ghi một mảng số nguyên int vào file có tên filename.
    bool readArray(const char* filename, int* array, size_t size);  // Đọc một mảng số nguyên int từ file có tên filename và lưu vào biến array.

    bool writeFloatArray(const char* filename, const float* array, size_t size);  // Ghi một mảng số thực float vào file có tên filename.
    bool readFloatArray(const char* filename, float* array, size_t size);  // Đọc một mảng số thực float từ file có tên filename và lưu vào biến array.

    bool writeDoubleArray(const char* filename, const double* array, size_t size);  // Ghi một mảng số thực double vào file có tên filename.
    bool readDoubleArray(const char* filename, double* array, size_t size);  // Đọc một mảng số thực double từ file có tên filename và lưu vào biến array.

    bool writeStruct(const char* filename, const void* structure, size_t size);  // Ghi một cấu trúc (struct) vào file có tên filename.
    bool readStruct(const char* filename, void* structure, size_t size);  // Đọc một cấu trúc (struct) từ file có tên filename và lưu vào biến structure.

    bool writeData(const char* filename, const void* data, size_t size);  // Ghi dữ liệu thô (void*) vào file có tên filename.
    bool readData(const char* filename, void* data, size_t size);  // Đọc dữ liệu thô (void*) từ file có tên filename và lưu vào biến data.

    // Thêm các phương thức hỗ trợ kiểu dữ liệu mới
    bool writeLong(const char* filename, long value);  // Ghi một giá trị số nguyên dài long vào file có tên filename.
    bool readLong(const char* filename, long& value);  // Đọc một giá trị số nguyên dài long từ file có tên filename và lưu vào biến value.

    bool writeUnsignedLong(const char* filename, unsigned long value);  // Ghi một giá trị số nguyên không dấu dài unsigned long vào file có tên filename.
    bool readUnsignedLong(const char* filename, unsigned long& value);  // Đọc một giá trị số nguyên không dấu dài unsigned long từ file có tên filename và lưu vào biến value.

    bool writeUInt8(const char* filename, uint8_t value);  // Ghi một giá trị số nguyên không dấu 8-bit uint8_t vào file có tên filename.
    bool readUInt8(const char* filename, uint8_t& value);  // Đọc một giá trị số nguyên không dấu 8-bit uint8_t từ file có tên filename và lưu vào biến value.

    bool writeUInt16(const char* filename, uint16_t value);  // Ghi một giá trị số nguyên không dấu 16-bit uint16_t vào file có tên filename.
    bool readUInt16(const char* filename, uint16_t& value);  // Đọc một giá trị số nguyên không dấu 16-bit uint16_t từ file có tên filename và lưu vào biến value.

    bool writeUInt32(const char* filename, uint32_t value);  // Ghi một giá trị số nguyên không dấu 32-bit uint32_t vào file có tên filename.
    bool readUInt32(const char* filename, uint32_t& value);  // Đọc một giá trị số nguyên không dấu 32-bit uint32_t từ file có tên filename và lưu vào biến value.

    bool writeUnsignedInt(const char* filename, unsigned int value);  // Ghi một giá trị số nguyên không dấu unsigned int vào file có tên filename.
    bool readUnsignedInt(const char* filename, unsigned int& value);  // Đọc một giá trị số nguyên không dấu unsigned int từ file có tên filename và lưu vào biến value.

private:
    File file;  // Đối tượng File để làm việc với các tập tin trên thẻ SD.
};

#endif // SD_ESP32_QH_H
