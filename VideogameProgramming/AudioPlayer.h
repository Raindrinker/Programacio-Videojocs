#pragma once
#include <windows.h>
#include <iostream>

//these two headers are already included in the <Windows.h> header
#pragma comment(lib, "winmm.lib")

using namespace std;

class AudioPlayer
{
public:

    static void PlayAudio(string path, bool loop);

};