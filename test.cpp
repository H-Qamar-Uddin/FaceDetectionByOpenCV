#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////

/*void main() {

    string path = "Resources/lambo.png";
    Mat img = imread(path);
    imshow("Image", img);
    waitKey(0);

}
*/
void main() {

    VideoCapture video(0);
    CascadeClassifier faceDetection;
    Mat img;

    faceDetection.load("haarcascade_frontalface_default.xml");

    while (true)
    {   
        video.read(img);

        vector<Rect> faces;
        faceDetection.detectMultiScale(img, faces, 1.3, 5, 0);

        cout << faces.size() << endl;

        for (int i = 0; i < faces.size(); i++) {
            rectangle(img, faces[i].tl(), faces[i].br(), Scalar(60, 60, 245), 4);
            putText(img, to_string(faces.size()), Point(20, 70), FONT_HERSHEY_DUPLEX,3, Scalar(100, 44, 165), 2);
        }

        imshow("Window", img);
        waitKey(1);
    }
}