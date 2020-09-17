/*
 *
   Programmer: Amayrani Luna
   date: 9/7/20
   Squares.h
   MoCapProject1
   
    This class holds the variable n and, uses this variable to divided the screen into n*n
    squares, determines where the white pixels are(indicating movement) in each square, and
    colors those pixels.
 *
 */

#ifndef Squares_h
#define Squares_h
using namespace cinder;

class squares{
private:
    int n;
    
public:
    
    //constructor
    squares(){
        n = 10;
    }
 
    void setN(int n1){
        n = n1;
    }
   
   //divides screen into n*n squares and colors white pixels that indicate movement
   void draw(cv::Mat frameDiff)
   {
       int squareWidth = frameDiff.cols / n;
       int squareHeight = frameDiff.rows / n;
       
       //creating squares
       for(int i = 0 ; i < n ; i++){
           for(int j = 0 ; j < n ; j++){
               int x1 = i * squareWidth;
               int x2 = x1 + squareWidth;
               int y1 = j * squareHeight;
               int y2 = y1 + squareHeight;
               Rectf curSquare = Rectf(x1, y1, x2, y2);
               int sum = 0;
               //counting white pixels
               for(int x = x1 ; x < x2 ; x++){
                   for(int y = y1 ; y < y2 ; y++){
                       int pixel = frameDiff.at<uint8_t>(y,x);
                       sum+=pixel;
                   }
               }
               //coloring white pixels
               gl::color(sum/(float)(n*n*255), 0, 1, 1);
               gl::drawSolidRect(curSquare);
           }
        }
   }
};
#endif // Squares_h
