#include <iostream>
#include <iomanip>

using namespace std;

/**
 * 计算等差数列的和
 * 公式: S = n/2 * (2a + (n-1)d)
 * 其中: n = 项数, a = 首项, d = 公差
 * 
 * @param first_term 首项 (a)
 * @param common_diff 公差 (d) 
 * @param num_terms 项数 (n)
 * @return 等差数列的和
 */
double arithmetic_sequence_sum(double first_term, double common_diff, int num_terms) {
    if (num_terms <= 0) {
        return 0;
    }
    
    // 使用等差数列求和公式: S = n/2 * (2a + (n-1)d)
    return (double)num_terms / 2.0 * (2 * first_term + (num_terms - 1) * common_diff);
}

/**
 * 计算等差数列的和 (另一种公式)
 * 公式: S = n/2 * (first_term + last_term)
 * 
 * @param first_term 首项
 * @param last_term 末项
 * @param num_terms 项数
 * @return 等差数列的和
 */
double arithmetic_sequence_sum_alt(double first_term, double last_term, int num_terms) {
    if (num_terms <= 0) {
        return 0;
    }
    
    // 使用首项和末项的公式: S = n/2 * (首项 + 末项)
    return (double)num_terms / 2.0 * (first_term + last_term);
}

int main() {
    cout << "等差数列求和计算器" << endl;
    cout << "==================" << endl << endl;
    
    // 示例1: 计算等差数列 1, 3, 5, 7, 9 的和
    double a1 = 1.0;    // 首项
    double d1 = 2.0;    // 公差
    int n1 = 5;         // 项数
    
    double sum1 = arithmetic_sequence_sum(a1, d1, n1);
    cout << "示例1: 等差数列 1, 3, 5, 7, 9" << endl;
    cout << "首项 a = " << a1 << ", 公差 d = " << d1 << ", 项数 n = " << n1 << endl;
    cout << "和 S = " << sum1 << endl << endl;
    
    // 示例2: 计算等差数列 10, 7, 4, 1, -2, -5 的和
    double a2 = 10.0;   // 首项
    double d2 = -3.0;   // 公差
    int n2 = 6;         // 项数
    
    double sum2 = arithmetic_sequence_sum(a2, d2, n2);
    cout << "示例2: 等差数列 10, 7, 4, 1, -2, -5" << endl;
    cout << "首项 a = " << a2 << ", 公差 d = " << d2 << ", 项数 n = " << n2 << endl;
    cout << "和 S = " << sum2 << endl << endl;
    
    // 示例3: 使用首项和末项计算
    double first = 2.0;
    double last = 20.0;
    int n3 = 10;
    
    double sum3 = arithmetic_sequence_sum_alt(first, last, n3);
    cout << "示例3: 使用首项和末项计算" << endl;
    cout << "首项 = " << first << ", 末项 = " << last << ", 项数 n = " << n3 << endl;
    cout << "和 S = " << sum3 << endl << endl;
    
    // 交互式计算
    cout << "请输入您要计算的等差数列参数:" << endl;
    double user_first, user_diff;
    int user_terms;
    
    cout << "首项 a: ";
    cin >> user_first;
    cout << "公差 d: ";
    cin >> user_diff;
    cout << "项数 n: ";
    cin >> user_terms;
    
    if (user_terms > 0) {
        double user_sum = arithmetic_sequence_sum(user_first, user_diff, user_terms);
        cout << endl << "结果:" << endl;
        cout << "等差数列的和 S = " << fixed << setprecision(2) << user_sum << endl;
        
        // 显示数列的前几项
        cout << "数列的前几项: ";
        for (int i = 0; i < min(user_terms, 10); i++) {
            cout << user_first + i * user_diff;
            if (i < min(user_terms, 10) - 1) cout << ", ";
        }
        if (user_terms > 10) cout << ", ...";
        cout << endl;
    } else {
        cout << "项数必须大于0!" << endl;
    }
    
    return 0;
}