#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void point(){
    Point_<int> pt1(100, 200);
    Point_<float> pt2(100.1f, 200.2f);
    Point_<double> pt3(100.3, 200.4);

    Point2i pt4(120, 69); // 2차원 integer 포인트
    Point2f pt5(0.3f, 0.f), pt6(0.f, 1.4f); // 2차원 float 포인트
    Point2d pt7(0.25, 0.6);

    Point2i pt8 = pt1 + (Point2i) pt2;
    Point2f pt9 = pt6 * 3.14f;
    Point2d pt10 = (pt3 + (Point2d)pt6) * 10;

    std::cout<<"pt8 = "<< pt8.x << " , " << pt8.y << std::endl;
    std::cout<<"pt9 = "<< pt9 << std::endl;
    std::cout<< (pt2 == pt9) << std::endl;


    std::cout << "pt7과 pt8의 내적 " << pt7.dot(pt8) << std::endl;

    return;
}

void point3() {
    Point3_<int> pt1(100,200,300);
    Point3_<float> pt2(92.3f, 125.23f, 250.f);
    Point3f pt3(0.3f, 0.f, 15.7f);
    Point3d pt4(0.25, 0.6, 33.3);

    Point3i pt5 = pt1 - (Point3i)pt2;
    Point3f pt6 = pt2 * 3.14f;
    Point3d pt7 = ((Point3d)pt3 + pt4) * 10.f;

    cout << "두 벡터(pt4, pt7)의 내적 " << pt4.dot(pt7) <<endl;
    cout << "pt5 = " << pt5.x << ", " << pt5.y <<"," << pt5.z << endl;
    cout << "pt6 = " << pt6 << endl;
    cout << "pt7 = " << pt6 << endl;

    return;

}

void size() {
    Size_<int> sz1(100, 200);
    Size_<float> sz2(192.3f, 25.3f);
    Size_<double> sz3(100.2, 30.9);

    Size2i sz4(120, 69);
    Size2f sz5(0.3f, 0.f);
    Size2d sz6(0.25, 0.6);

    Point2d pt1(0.25, 0.6);
    Size2i sz7 = sz1 + (Size2i)sz2;
    Size2d sz8 = sz3 - (Size2d)sz4;
    Size2d sz9 = (Size2f)sz5 + (Size2f)pt1;

    cout << "sz1.width = " << sz1.width;
    cout << ", sz1.height = " << sz1.height << endl;
    cout << "sz1 넓이 " << sz1.area() << endl;
    cout << "sz7" << sz7 << endl;
    cout << "sz8" << sz8 << endl;
    cout << "sz9" << sz9 << endl;

    return;
}

void rect() {
    Size2d sz(100.5, 60.6);
    Point2f pt1(20.f, 30.f), pt2(100.f, 200.f);

    Rect_<int> rect1(10, 10, 30, 50);
    Rect_<float> rect2(pt1, pt2);
    Rect_<double> rect3(Point2d(20.5, 10), sz);

    Rect rect4 = rect1 + (Point)pt1;
    Rect2f rect5 = rect2 + (Size2f)sz;
    Rect2d rect6 = rect1 & (Rect)rect2;

    cout << "rect3 = " << rect3.x << ", " << rect3.y << ", ";
    cout << rect3.width << " x " <<  rect3.height << endl;
    cout << "rect4 = " << rect4.tl() << " " << rect4.br() << endl;
    cout << "rect5의 크기 = " << rect5.size() << endl;
    cout << "rect6 = " << rect6 << endl;

    return;
}

int main()
{
    rect();
    return 0;
}
