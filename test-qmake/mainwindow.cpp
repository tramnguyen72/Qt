#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("hello");
    Mat image = imread("E:/dog.jpg");
    imshow("dog", image);
    waitKey(0); // Wait for any keystroke in the window
    destroyAllWindows();

}

void MainWindow::on_pushButton_2_clicked()
{
    VideoCapture cap(1);
    while(1)
    {
        Mat frame;
        // Capture frame-by-frame
        cap.read(frame);

        cv::imshow("window", frame);

                char key = cv::waitKey();
                if (key == 27) // ESC
                    break;}


}
