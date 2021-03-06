#ifndef SENSOR_H
#define SENSOR_H

/*!
 * \file Sensor.h
 * \brief Make the connection beetween CommMqtt and ReceiveData
 * \author Thomas Abgrall
 * \version 0.1
 */

#include "SensorGpioData.h"
#include "MqttHandler.h"

#define TOPICSUBSCRIB "/set/#"
#define TOPICGRAPH "/sensor/graph"

#define GPIO_CHIP_BARAGRAPH "2"

class Sensor : public MqttHandler
{
public:
    Sensor(QString address, quint16 port, QList<QString> topicList);
    ~Sensor();

public slots:
    void onMessage(QMqttMessage message) override;
    void sendData(QString, QJsonObject);

private:
    QString old_value;
    void writeGPIO(int, bool);
    gpiod::chip  *m_chip;
    SensorGpioData *m_sensorGpio;
    MqttHandler *m_MqttHandler;

};

#endif // SENSOR_H
