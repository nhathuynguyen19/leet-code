#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string addKyTu(int a, int b, int &du)
    {
        int sum = a + b + du;
        du = (sum == 2 || sum == 3) ? 1 : 0;
        return (sum == 0 || sum == 2) ? "0" : "1";
    }

    string addPhanDu(int du) { return (du != 1) ? "" : "1"; }

    void daoChuoi(string &st)
    {
        int st_len = st.length();
        for (int i = 0; i < st_len / 2; i++)
        {
            char t = st[i];
            st[i] = st[st_len - 1 - i];
            st[st_len - 1 - i] = t;
        }
    }

    void ganBang(string &st, int len)
    {
        for (int i = 0; i < len; i++)
        {
            st += "0";
        }
    }

    void lamBang(string &a, string &b)
    {
        int a_len = a.length();
        int b_len = b.length();
        int len = abs(b_len - a_len);

        daoChuoi(a);
        daoChuoi(b);

        if (a_len < b_len)
            ganBang(a, len);
        else if (a_len > b_len)
            ganBang(b, len);

        daoChuoi(a);
        daoChuoi(b);
    }

    string addBinary(string a, string b)
    {
        string rs;
        int a_len = a.length();
        int b_len = b.length();
        int Max = max(a.length(), b.length());
        int du = 0;
        lamBang(a, b);

        for (int i = Max - 1; i >= 0; i--)
        {
            int A = a[i] - '0';
            int B = b[i] - '0';
            rs += addKyTu(A, B, du);
        }
        rs += addPhanDu(du);
        daoChuoi(rs);
        return rs;
    }
};

string addKyTu(int a, int b, int &du) {
    int sum = a + b + du;
    du = (sum == 2 || sum == 3)? 1 : 0;
    return (sum == 0 || sum == 2)? "0" : "1";
}



int main() {
    string a = "1010";
    string b = "1011";
    int du = 1;
    Solution s = Solution();
    cout << s.addBinary(a, b) << endl;
    // cout << addKyTu(1, 1, du) << " du: " << du << endl;
    return 0;
}