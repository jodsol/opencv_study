#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void print_matInfo(string m_name, Mat m) {
    cout << "[" << m_name << "행렬]"<< endl;
    cout << "채널 수 = " << m.channels() << endl;
    cout << "행x열 = " << m.rows << " x " << m.cols << endl;
}

void matTest7() {
    vector <Point> v1;
    v1.push_back(Point(10, 20));
    v1.push_back(Point(20, 30));
    v1.push_back(Point(50, 60));

    vector<float> v2(3, 9.25);
    Size arr_size[] = {Size(2,2), Size(3,3), Size(4,4)};
    int arr_int[] = {10,20,30,40,50};

    vector <Size> v3(arr_size, arr_size + sizeof(arr_size) / sizeof(Size));
    vector <int> v4(arr_int + 2, arr_int + sizeof(arr_int) / sizeof(int));

    cout << "v1" << (Mat)v1 << endl;
    cout << "v2" << ((Mat)v2).reshape(1,1) << endl;
    cout << "v3" << ((Mat)v3).reshape(1,1) << endl;
    cout << "v4" << ((Mat)v4).reshape(1,1) << endl;

    return;

}

void matTest6() {
    double data[] = {
        1.1, 2.2, 3.3, 4.4,
        5.5, 6.6, 7.7, 8.8,
        9.9, 10, 11, 12};

    Mat m1(3, 4, CV_64F, data);
    Mat m2 = m1.clone(); // 새로운 객체
    Mat m3, m4;
    m1.copyTo(m3); // 새로운객체
    m1.convertTo(m4, CV_8U); // 새로운 객체

    m1 = 33;
    cout << m1 << endl;
    cout << m2 << endl;
    cout << m3 << endl;
    cout << m4 << endl;
}

void matTest5() {
    Mat m1(2, 6, CV_8U);
    Mat m2 = m1.reshape(2);
    Mat m3 = m1.reshape(3, 2);

    print_matInfo("m1(2,6)", m1);
    print_matInfo("m2 = m1.reshape(2)", m2);
    print_matInfo("m3 = m1.reshape(3, 2)", m3);

    m1.create(3, 5, CV_16S);
    print_matInfo("m1.create(3, 5, CV_165", m1);


}

void matTest4() {
    Mat m = (Mat_<uchar>(2, 4) << 1, 2, 3, 4, 5, 6, 7, 8);
    cout << m << endl;

    m.resize(3, Scalar(50));
    cout << m << endl;
    return;

}

void calcMatTest3() {
    Mat m1(2, 3, CV_8U, 2);
    Mat m2(2, 3, CV_8U, Scalar(10));

    Mat m3 = m1 + m2;
    Mat m4 = m2 - 6;
    Mat m5 = m1;

    m5 = 100;

    cout << m1 << endl;
    cout << m2 << endl;
    cout << m3 << endl;
    cout << m4 << endl;
    cout << m5 << endl;

}

void matTest2() {
    Mat m1(4, 3, CV_32FC3);
    cout << "dims = " << m1.dims << endl;
    cout << "size = " << m1.size << endl;
    cout << "total = " << m1.total() << endl;
    cout << "elemSize = " << m1.elemSize() << endl; // CV_32FC3 = float(4byte) * chanel(3)
    cout << "type = " << m1.type() << "," << CV_32FC3 << endl; // CV_32FC3 = 21 (상수정의)
    cout << "depth = " << m1.depth() << "," << CV_32F << endl; // 자료형
    cout << "step = " << m1.step << endl; // 한 행의 byte수
    cout << "step1 = " << m1.step1() << endl; // ?

    return;
}

void matxTest() {
    Matx<int, 3, 3> m1(1,2,3,4,5,6,7,8,9);
    Matx<float, 2, 3> m2(1,2,3,4,5,6);
    Matx<double, 3, 5> m3(3,4,5,7);

    Matx23d m4(3,4,5,6,7,8);
    Matx34d m5(3,4,5,6,7,8,9,10,11,12,13,14);
    cout << m4(0,0) <<", " << m4(0, 1); // 요소 출력
    return;
}

void matInitTest() {
    double a  = 32.12345678, b = 2.7;
    short c = 400;
    float d = 10.f, e = 11.f, f = 13.f;

    Mat_<int> m1(2, 4); // 초기화 안함
    Mat_<uchar> m2(3, 4, 100);
    Mat_<short> m3(2, 4, c);

    m1 << 1, 2, 3, 4, 5, 6; // 초기화 함
    Mat m4 = (Mat_<double>(2,3) << 1,2,3,4,5,6); // 생성과 동시에 초기화
    Mat m5 = (Mat_<float>(2,3) << a,b,c,d,e,f); // 생성과 동시에 초기화
    cout << m5 << endl;

    return;
}
void matTest() {
    Mat m1 = Mat::ones(300, 500, CV_8UC1);
    Mat m2 = Mat::zeros(300, 500, CV_8UC1);
    Mat m3 = 200 * Mat::eye(300, 300, CV_8UC1);

    // cout << "m1" << m1 << endl;
    // cout << "m2" << m2 << endl;
    // cout << "m3" << m3 << endl;

    imshow("Mat", m2);
    waitKey(0);
}

int main()
{
    matTest7();
    return 0;
}
