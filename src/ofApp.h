#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
        void draw() override;
    void keyPressed(int key) override;
    
        void checkNeighbors(int x, int y);
   
        ofImage canvas;
        ofPixels cPix;
        ofPixels cPixCopy;
};
