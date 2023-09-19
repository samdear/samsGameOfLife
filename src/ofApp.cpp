#include "ofApp.h"

void ofApp::setup(){
    
    canvas.allocate(1000,1000,  OF_IMAGE_GRAYSCALE);
    cPix = canvas.getPixels();
     
    cPix.setColor(canvas.getWidth()/2, canvas.getHeight()/2, 255);
    cPix.setColor((canvas.getWidth()/2) - 1, canvas.getHeight()/2, 255);
    cPix.setColor((canvas.getWidth()/2) - 1, (canvas.getHeight()/2) - 1, 255);
    cPix.setColor((canvas.getWidth()/2) - 1, (canvas.getHeight()/2) + 1, 255);
    cPix.setColor((canvas.getWidth()/2) + 1, (canvas.getHeight()/2) - 1, 255);

//    checkNeighbors(canvas.getWidth() / 2, canvas.getHeight() / 2);
    
    canvas.setFromPixels(cPix);

}

void ofApp::checkNeighbors(int x, int y) {
    
    int count = 0;
    
    if (cPix.getColor(x-1, y-1) == 255) {
        count++;
    }
    if (cPix.getColor(x-1, y) == 255) {
        count++;
    }
    if (cPix.getColor(x-1, y+1) == 255) {
        count++;
    }
    if (cPix.getColor(x, y-1) == 255) {
        count++;
    }
    if (cPix.getColor(x, y+1) == 255) {
        count++;
    }
    if (cPix.getColor(x+1, y-1) == 255) {
        count++;
    }
    if (cPix.getColor(x+1, y) == 255) {
        count++;
    }
    if (cPix.getColor(x+1, y+1) == 255) {
        count++;
    }
    
//    cout << count << endl;
    
    if (count < 2) {
        cPixCopy.setColor(x, y, 0);
//        cout << "is black";
    }
    if (count >= 4) {
        cPixCopy.setColor(x, y, 0);
//        cout << "is black";
    }
    if (count == 3) {
        cPixCopy.setColor(x, y, 255);
//        cout << "is white";
    }
}

void ofApp::update(){
    
    ofImage copyCanvas = canvas;
    cPix = canvas.getPixels();
    cPixCopy = copyCanvas.getPixels();
    
    for (int y = 0; y < canvas.getHeight(); y++)
    {
        for (int x = 0; x < canvas.getWidth(); x++)
        {
            checkNeighbors(x, y);
        }
    }
    canvas.setFromPixels(cPixCopy);
}

void ofApp::keyPressed(int key){
    
    
}

void ofApp::draw(){
    canvas.draw(0,0);
}
