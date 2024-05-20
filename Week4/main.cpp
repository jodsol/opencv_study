#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


void matTest() {
    float data[] = {1.2f, 2.3f, 3.2f,
                    4.5f, 5.f, 6.5f};

    Mat m1(2, 3, CV_8U);
    Mat m2(2, 3, CV_8U, Scalar(300)); // 255로 바뀜
    Mat m3(2, 3, CV_16S, Scalar(300)); // 300으로 됨
    Mat m4(2, 3, CV_32F, data);

    cout << "m1" << m1 << endl;
    cout << "m2" << m2 << endl;
    cout << "m3" << m3 << endl;
    cout << "m4" << m4 << endl;
    return;
}

void rectangleTest() {
    // 메모리에 300*500 8bit unsigned charactor chanel1(gray) 이미지 생성
    Mat image(300, 500, CV_8UC1, Scalar(255));


    Point2f center(250, 150), pts[4];
    Size2f size(300, 100);
    int angle = 20;
    RotatedRect rot_rect(center, size, angle);
    rot_rect.points(pts);

    cout << "rotated rect: " << rot_rect.center << "," << rot_rect.size;
    cout << "," << rot_rect.angle << endl;

    for (int i = 0; i < 4; i++){
        circle(image, pts[i], 4, Scalar(0), 1);
        line(image, pts[i], pts[(i + 1) % 4], Scalar(0), 2);
    }
    Rect bound_rect = rot_rect.boundingRect();

    // 사각형 그리기
    rectangle(image, bound_rect, Scalar(0), 1);

    // 원 그리기
    circle (image, rot_rect.center, 1, Scalar(0), 2);

    imshow("Rotated Rect", image);
    waitKey(0);
    return;

}
void scalarTest() {
    Scalar_<uchar> red(0, 0, 255);
    Scalar_<int> blue(255, 0, 0);
    Scalar_<double> color1(500);
    Scalar_<float> color2(100.f, 200.f, 125.9f);

    Vec3d green(0, 0, 300.5);
    Scalar green1 = color1 + (Scalar)green;
    Scalar green2 = color2 + (Scalar_<float>)green;

    cout << "green1" << green1 << endl;
    cout << "green2" << green2 << endl;
    cout << "red" << red << endl;
    cout << "blue" << blue << endl;
    cout << "color1" << color1 << endl;
    cout << "color2" << color2 << endl;

    return;
}

void vectorTest(){
    Vec<int, 2> v1(5, 12);
    Vec<double, 3> v2(40, 130.7, 125.6);
    Vec2b v3(10, 10);
    Vec6f v4(40.f, 230.25f, 525.6f);
    Vec3i v5(200, 230, 250);

    Vec v6 = v2 + (Vec3d)v5;
    Vec2b v7 = (Vec2b)v1 + v3;
    Vec6f v8 = v4 * 20.f;

    Point pt1 = v1 + (Vec2i)v7;
    Point3_<int> pt2 = (Point3_<int>)v2;

    cout << "v3 = " << v3 << endl;
    cout << "v7 = " << v7 << endl;
    cout << "v3 * v7 =" << v3.mul(v7) << endl;
    cout << "v8[0]" <<v8[0] << endl;
    cout << "v8[1]" <<v8[1] << endl;
    cout << "v8[2]" <<v8[2] << endl;
    cout << "v2 = " << v2 << endl;
    cout << "pt2 = " << pt2 << endl;
}

int main()
{

    matTest();
    return 0;
}
