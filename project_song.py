import RPi.GPIO as GPIO
import time

piezoPin = 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(piezoPin, GPIO.OUT)

sound = GPIO.PWM(piezoPin, 440)

a = [
    262, 294, 330, 349, 392, 440, 494, 523,
    0, 392, 392, 440, 392, 330
]

b = [
    330, 294, 262, 294, 330, 349, 392, 440,
    0, 440, 392, 349, 330, 294
]

def play_song(melody):
    sound.start(50)
    for note in melody:
        if note == 0:
            sound.ChangeFrequency(1)
            time.sleep(0.3)
        else:
            sound.ChangeFrequency(note)
            time.sleep(0.3)
    sound.stop()
    time.sleep(1)

try:
    print("=== 부저 음악 프로그램 시작 ===")
    current_song = 0

    while True:
        if current_song == 0:
            print("\n[1곡] 별자리가 될 수 있다면 재생 중...")
            play_song(a)
        else:
            print("\n[2곡] 기타와 고독과 푸른 행성 재생 중...")
            play_song(b)

        user_input = input("다음 곡을 들으려면 숫자 '1'을 입력하세요 (종료하려[>

        if user_input == '1':
            current_song = (current_song + 1) % 2
        else:
            print("입력값이 '1'이 아니므로 같은 곡을 다시 재생합니다.")

except KeyboardInterrupt:
    print("\n프로그램 종료됨. GPIO 정리 중...")
    sound.stop()
    GPIO.cleanup()
