#pragma once

#include "ofMain.h"
#include "ricochetCube.h"
#include "echo.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int buttona);
		void mouseReleased(int x, int y, int buttona);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void createEcho();
        float * translateSoundFrequency();
    
        float * fftSmoothed;
        int nBandsToGet;
    
        bool mouseDown = false;
        int buttonPressed;
    
        vector<ricochetCube> cubes;
        vector<echo> echoes;
};
