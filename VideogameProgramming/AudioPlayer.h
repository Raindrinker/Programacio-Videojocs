#pragma once
#include <windows.h>
#include <iostream>

#include "bass.h"
#pragma comment(lib, "bass.lib") 

using namespace std;

class AudioPlayer
{
public:

    static void Init();
    
    static void PlayAudio(string path, bool loop);

};