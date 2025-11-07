import os
import tkinter as tk
from tkinter import filedialog
from pygame import mixer

# Initialize mixer
mixer.init()

# Create main window
root = tk.Tk()
root.title("🎵 Simple Music Player")
root.geometry("400x300")
root.config(bg="#222831")

# Global variable
current_song = ""
paused = False

# Functions
def load_music():
    global current_song
    music_dir = filedialog.askdirectory(title="Select Music Folder")
    if music_dir:
        songs = [f for f in os.listdir(music_dir) if f.endswith(".mp3")]
        for song in songs:
            song_list.insert(tk.END, os.path.join(music_dir, song))
        current_song = song_list.get(tk.ACTIVE)

def play_music():
    global current_song, paused
    if paused:
        mixer.music.unpause()
        paused = False
    else:
        selected = song_list.curselection()
        if selected:
            current_song = song_list.get(selected)
            mixer.music.load(current_song)
            mixer.music.play()

def pause_music():
    global paused
    mixer.music.pause()
    paused = True

def stop_music():
    mixer.music.stop()

# UI Elements
title_label = tk.Label(root, text="🎶 Music Player 🎶", bg="#222831", fg="white", font=("Arial", 16, "bold"))
title_label.pack(pady=10)

song_list = tk.Listbox(root, bg="#393E46", fg="white", width=50, selectbackground="#00ADB5")
song_list.pack(pady=10)

btn_frame = tk.Frame(root, bg="#222831")
btn_frame.pack(pady=20)

play_btn = tk.Button(btn_frame, text="▶ Play", width=8, command=play_music, bg="#00ADB5", fg="white")
play_btn.grid(row=0, column=0, padx=5)

pause_btn = tk.Button(btn_frame, text="⏸ Pause", width=8, command=pause_music, bg="#00ADB5", fg="white")
pause_btn.grid(row=0, column=1, padx=5)

stop_btn = tk.Button(btn_frame, text="⏹ Stop", width=8, command=stop_music, bg="#00ADB5", fg="white")
stop_btn.grid(row=0, column=2, padx=5)

load_btn = tk.Button(root, text="📂 Load Folder", command=load_music, bg="#EEEEEE", fg="#222831")
load_btn.pack(pady=5)

root.mainloop()
