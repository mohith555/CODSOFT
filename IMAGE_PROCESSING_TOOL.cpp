#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void displayImage(const Mat& img) {
    imshow("Image", img);
    waitKey(0);
}

void applyGrayscale(Mat& img) {
    cvtColor(img, img, COLOR_BGR2GRAY);
}

void applyBlur(Mat& img) {
    GaussianBlur(img, img, Size(15, 15), 0);
}

void applySharpen(Mat& img) {
    Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(img, img, img.depth(), kernel);
}

void resizeImage(Mat& img, int width, int height) {
    resize(img, img, Size(width, height));
}

void cropImage(Mat& img, Rect region) {
    img = img(region);
}

void saveImage(const Mat& img, const string& filename) {
    imwrite(filename, img);
}

int main() {
    string filename;
    cout << "Enter image filename: ";
    cin >> filename;

    Mat img = imread(filename);
    if (img.empty()) {
        cout << "Could not load image!" << endl;
        return -1;
    }

    displayImage(img);

    int choice;
    do {
        cout << "\nImage Processing Menu:\n";
        cout << "1. Grayscale\n2. Blur\n3. Sharpen\n4. Resize\n5. Crop\n6. Save Image\n7. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                applyGrayscale(img);
                displayImage(img);
                break;
            case 2:
                applyBlur(img);
                displayImage(img);
                break;
            case 3:
                applySharpen(img);
                displayImage(img);
                break;
            case 4: {
                int width, height;
                cout << "Enter new width and height: ";
                cin >> width >> height;
                resizeImage(img, width, height);
                displayImage(img);
                break;
            }
            case 5: {
                int x, y, width, height;
                cout << "Enter crop region (x y width height): ";
                cin >> x >> y >> width >> height;
                cropImage(img, Rect(x, y, width, height));
                displayImage(img);
                break;
            }
            case 6: {
                string saveFilename;
                cout << "Enter filename to save image: ";
                cin >> saveFilename;
                saveImage(img, saveFilename);
                cout << "Image saved as " << saveFilename << endl;
                break;
            }
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
