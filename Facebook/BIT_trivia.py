import network
import time
import ujson as json
import urequests as requests
from Bit import *
from machine import Pin

led = Pin(37, mode=Pin.OUT)

answer = True
waiting = True
score = 0
rounds = 0

def on_A_press():
    global answer
    global led
    global score
    global rounds
    global waiting
    if answer == "True":
        display.rect(0, 120, 130, 10, Display.Color.Green, True)
        led.on()
        piezo.tone(440, 200)
        led.off()
        score += 1
    else:
        display.rect(0, 120, 130, 10, Display.Color.Red, True)
    rounds += 1
    display.commit()
    time.sleep(0.5)
    waiting = False

def on_B_press():
    global answer
    global led
    global score
    global rounds
    global waiting
    if answer == "False":
        display.rect(0, 120, 130, 10, Display.Color.Green, True)
        led.on()
        piezo.tone(440, 200)
        led.off()
        score += 1
    else:
        display.rect(0, 120, 130, 10, Display.Color.Red, True)
    rounds += 1
    display.commit()
    time.sleep(0.5)
    waiting = False

def show_question(question):
    global score
    display.fill(Display.Color.Black)
    y = 0
    row = ""
    words = question.split()
    for word in words:
        new_row = row + " " + word
        if (len(new_row) < 18):
            row = new_row
        else:
            display.text(row[1:], 0, y, Display.Color.White)
            y += 10
            row = " " + word
    display.text(row[1:], 0, y, Display.Color.White)
    display.text("A", 0, 120, Display.Color.Green)
    display.text("   Score: " + str(score) + "/" + str(rounds), 0, 120, Display.Color.White)
    display.text("               B", 0, 120, Display.Color.Red)
    display.commit()

sta_if = network.WLAN(network.STA_IF)
sta_if.active(True)
sta_if.connect('WIFI_NAZIV', 'WIFI_LOZINKA')
while not sta_if.isconnected():
    time.sleep(0.2)
print("Connected!")

begin()
display.fill(Display.Color.Black)
display.line(0, 25, 130, 25, Display.Color.White)
display.text("    COMPUTER", 0, 30, Display.Color.White)
display.text("     TRIVIA", 0, 40, Display.Color.White)
display.text("      GAME", 0, 50, Display.Color.White)
display.line(0, 60, 130, 60, Display.Color.White)
display.commit()
buttons.on_press(Buttons.A, on_A_press)
buttons.on_press(Buttons.B, on_B_press)
response = requests.get(url='https://opentdb.com/api.php?amount=10&category=18&type=boolean')
body = json.loads(response.text)
questions = []
answers = []
for question in body["results"]:
    questions.append(question["question"].replace('&quot;', '"').replace("&#039;", "'"))
    answers.append(question["correct_answer"])
idx = 0
while idx < len(questions):
    show_question(questions[idx])
    answer = answers[idx]
    waiting = True
    while waiting:
        buttons.scan()
        time.sleep(0.1)
    idx += 1
display.fill(Display.Color.Black)
display.line(0, 25, 130, 25, Display.Color.White)
display.text("    COMPUTER", 0, 30, Display.Color.White)
display.text("     TRIVIA", 0, 40, Display.Color.White)
display.text("      GAME", 0, 50, Display.Color.White)
display.line(0, 60, 130, 60, Display.Color.White)
display.text("   Score: " + str(score) + "/" + str(rounds), 0, 120, Display.Color.White)
display.commit()
piezo.tone(440, 200)
time.sleep(0.2)
piezo.tone(440, 200)