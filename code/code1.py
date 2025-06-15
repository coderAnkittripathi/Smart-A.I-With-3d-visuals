import speech_recognition
import tts_module
import camera_module
import image_recognition

def listen_and_process():
    command = speech_recognition.get_command()
    
    if "hello ankit" in command:
        tts_module.speak("Hi Ankit, how can I help you?")
    elif "what is this" in command:
        image_path = camera_module.capture_image()
        result = image_recognition.analyze_image(image_path)
        tts_module.speak(f"This looks like: {result}")
    elif "how am I looking" in command:
        expression = camera_module.detect_expression()
        tts_module.speak(f"You look {expression} today!")

while True:
    listen_and_process()

