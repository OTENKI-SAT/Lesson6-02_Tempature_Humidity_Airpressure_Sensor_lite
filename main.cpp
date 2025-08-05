#include "mbed.h"
#include "BME280.h"
#include "LITE_EPS.h"

//I2Cピン定義
#define SCL_PIN PB_6
#define SDA_PIN PB_7
LITE_EPS    eps(PA_0, PA_4);

I2C i2c(SDA_PIN, SCL_PIN);
BME280 sensor(i2c); 

int main() {
    printf("BME280 Sensor Test\r\n");
    eps.turn_on_regulator();
    wait(0.05);
    sensor.initialize();//BME280のイニシャライズ（1回でOK)
    wait(0.05);

    while(1) {
        float temp = sensor.getTemperature();
        float humidity = sensor.getHumidity();
        float pressure = sensor.getPressure();

        printf("Temperature: %.2f C\r\n", temp);
        printf("Humidity: %.2f \r\n", humidity);
        printf("Pressure: %.2f hPa\r\n", pressure); //hPa単位で取得できる

        wait(1.0);
    }
}
