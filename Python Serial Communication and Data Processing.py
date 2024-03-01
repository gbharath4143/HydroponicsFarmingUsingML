import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression
import serial
import time
import warnings

warnings.filterwarnings("ignore")

data = pd.read_excel("values.xlsx", engine="openpyxl")
feature_1 = data['Turbuidity_value']
feature_2 = data['ph_value']
feature_3 = data['tds_value']
feature_4 = data['temperature']
feature_5 = data['distance']

label_1 = data['label_turbui']
label_2 = data['label_ph']
label_3 = data['label_tds']
label_4 = data['label_temp']
label_5 = data['label_distance']

lr_model_1 = LinearRegression()
lr_model_2 = LinearRegression()
lr_model_3 = LinearRegression()
lr_model_4 = LinearRegression()
lr_model_5 = LinearRegression()

lr_model_1.fit(feature_1.values.reshape(-1, 1), label_1)
lr_model_2.fit(feature_2.values.reshape(-1, 1), label_2)
lr_model_3.fit(feature_3.values.reshape(-1, 1), label_3)
lr_model_4.fit(feature_4.values.reshape(-1, 1), label_4)
lr_model_5.fit(feature_5.values.reshape(-1, 1), label_5)

t, u, v, w, x, y = 0, 0, 0, 0, 0, 0

ser = serial.Serial('COM4', baudrate=9600)
time.sleep(3)
ser.write(bytes('.', 'utf-8'))

def readData():
    global t, u, v, w, x, y
    time.sleep(1)
    serial_data = ser.readline().decode().strip()
    if not serial_data:
        return None
    time.sleep(1)
    a = serial_data.find("a")
    b = serial_data.find("b")
    a = a + 1
    val_1 = float(serial_data[a:b])
    time.sleep(1)
    b = serial_data.find("b")
    c = serial_data.find("c")
    b = b + 1
    val_2 = float(serial_data[b:c])
    time.sleep(1)
    c = serial_data.find("c")
    a = serial_data.find("d")
    c = c + 1
    val_3 = float(serial_data[c:a])
    time.sleep(1)
    a = serial_data.find("d")
    b = serial_data.find("e")
    a = a + 1
    val_4 = float(serial_data[a:b])
    time.sleep(1)
    b = serial_data.find("e")
    c = serial_data.find("f")
    b = b + 1
    val_5 = float(serial_data[b:c])
    time.sleep(1)
    return val_1, val_2, val_3, val_4, val_5

while True:
    serial_data = ser.readline().decode().strip()
    input_data = readData()
    if input_data is None:
        continue
    feature_1_val, feature_2_val, feature_3_val, feature_4_val, feature_5_val = input_data
    lr_prediction_1 = lr_model_1.predict(np.array([[feature_1_val]]))
    lr_prediction_2 = lr_model_2.predict(np.array([[feature_2_val]]))
    lr_prediction_3 = lr_model_3.predict(np.array([[feature_3_val]]))
    lr_prediction_4 = lr_model_4.predict(np.array([[feature_4_val]]))
    lr_prediction_5 = lr_model_5.predict(np.array([[feature_5_val]]))
    values_string = f"t{lr_prediction_1[0]:.2f}u{lr_prediction_2[0]:.2f}v{lr_prediction_3[0]:.2f}w{lr_prediction_4[0]:.2f}x{lr_prediction_5[0]:.2f}y"
    time.sleep(1)
    print(values_string)
    time.sleep(2)
    ser.write(bytes(values_string, 'utf-8'))
    time.sleep(3)
    print("completed")
    time.sleep(10)
