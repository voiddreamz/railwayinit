#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

/**
 * 计算等差数列的和
 * 公式: S = n/2 * (2a + (n-1)d)
 * 其中: n = 项数, a = 首项, d = 公差
 */
double arithmetic_sequence_sum(double first_term, double common_diff, int num_terms) {
    if (num_terms <= 0) {
        return 0;
    }
    return (double)num_terms / 2.0 * (2 * first_term + (num_terms - 1) * common_diff);
}

// 测试函数
void test_arithmetic_sequence_sum() {
    cout << "开始测试等差数列求和函数..." << endl;
    
    // 测试1: 基本等差数列 1, 3, 5, 7, 9 (首项=1, 公差=2, 项数=5)
    // 预期结果: 1+3+5+7+9 = 25
    double result1 = arithmetic_sequence_sum(1.0, 2.0, 5);
    assert(abs(result1 - 25.0) < 0.001);
    cout << "✓ 测试1通过: 1+3+5+7+9 = " << result1 << endl;
    
    // 测试2: 负公差数列 10, 7, 4, 1, -2, -5 (首项=10, 公差=-3, 项数=6)
    // 预期结果: 10+7+4+1+(-2)+(-5) = 15
    double result2 = arithmetic_sequence_sum(10.0, -3.0, 6);
    assert(abs(result2 - 15.0) < 0.001);
    cout << "✓ 测试2通过: 10+7+4+1+(-2)+(-5) = " << result2 << endl;
    
    // 测试3: 单项数列 (项数=1)
    double result3 = arithmetic_sequence_sum(5.0, 3.0, 1);
    assert(abs(result3 - 5.0) < 0.001);
    cout << "✓ 测试3通过: 单项数列和 = " << result3 << endl;
    
    // 测试4: 零项数列 (项数=0)
    double result4 = arithmetic_sequence_sum(5.0, 3.0, 0);
    assert(abs(result4 - 0.0) < 0.001);
    cout << "✓ 测试4通过: 零项数列和 = " << result4 << endl;
    
    // 测试5: 公差为0的数列 (常数列)
    double result5 = arithmetic_sequence_sum(4.0, 0.0, 3);
    assert(abs(result5 - 12.0) < 0.001);  // 4+4+4 = 12
    cout << "✓ 测试5通过: 常数列 4+4+4 = " << result5 << endl;
    
    cout << "所有测试通过! ✓" << endl << endl;
}

int main() {
    cout << "等差数列求和程序测试" << endl;
    cout << "====================" << endl << endl;
    
    // 运行测试
    test_arithmetic_sequence_sum();
    
    // 演示计算
    cout << "演示计算:" << endl;
    
    // 计算1到100的和 (首项=1, 公差=1, 项数=100)
    double sum_1_to_100 = arithmetic_sequence_sum(1.0, 1.0, 100);
    cout << "1到100的和: " << sum_1_to_100 << endl;
    
    // 计算所有偶数从2到20的和 (2, 4, 6, 8, 10, 12, 14, 16, 18, 20)
    double sum_even = arithmetic_sequence_sum(2.0, 2.0, 10);
    cout << "2到20的偶数和: " << sum_even << endl;
    
    return 0;
}
